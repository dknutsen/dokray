using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Net;
using System.Net.Sockets;
using System.Data;
using System.Text;
using System.Threading;
using Bonjour;
using System.IO;

namespace PcClient
{
    public class Connection
    {
        private Bonjour.DNSSDEventManager m_eventManager = null;
        private Bonjour.DNSSDService m_service = null;
        private Bonjour.DNSSDService m_registrar = null;
        private Bonjour.DNSSDService m_browser = null;
        private Bonjour.DNSSDService m_resolver = null;
        private String m_name;
        private Socket m_socket = null;
        private const int BUFFER_SIZE = 1024;
        public byte[] m_buffer = new byte[BUFFER_SIZE];
        public bool m_complete = false;
        public bool hasData = false;
        public StringBuilder m_sb = new StringBuilder();
        delegate void ReadMessageCallback(String data);
        public PeerData selectedPeer = null;
        public RayTracer rayTracer = null;
        public const string regName = "_dray._tcp.";

        // ServiceRegistered
        //
        // Called by DNSServices core as a result of Register()
        public void ServiceRegistered(DNSSDService service, DNSSDFlags flags, String name, String regType, String domain)
        {
            m_name = name;

            try
            {
                m_browser = m_service.Browse(0, 0, regName, null, m_eventManager);
                System.Console.WriteLine("Registered as " + m_name + "...");
                System.Console.WriteLine("Waiting for a connection...");
            }
            catch
            {
                System.Console.WriteLine("Error - Browse Failed");
            }
        }

        // ServiceFound
        //
        // Called by DNSServices core as a result of a Browse call
        public void ServiceFound(DNSSDService sref, DNSSDFlags flags, uint ifIndex, String serviceName, String regType, String domain)
        {
            if (serviceName != m_name)
            {
                PeerData peer = new PeerData();

                peer.InterfaceIndex = ifIndex;
                peer.Name = serviceName;
                peer.Type = regType;
                peer.Domain = domain;
                peer.Address = null;

                this.selectedPeer = peer;

                System.Console.WriteLine("Connected to " + peer + "...");

                this.selectNewPeer();
            }
        }

        // ServiceLost
        //
        // Called by DNSServices core as a result of a Browse call
        public void ServiceLost(DNSSDService sref, DNSSDFlags flags, uint ifIndex, String serviceName, String regType, String domain)
        {
            PeerData peer = new PeerData();

            peer.InterfaceIndex = ifIndex;
            peer.Name = serviceName;
            peer.Type = regType;
            peer.Domain = domain;
            peer.Address = null;

            System.Console.WriteLine("Service Lost - " + peer);
        }

        // ServiceResolved
        //
        // Called by DNSServices core as a result of DNSService.Resolve()
        public void ServiceResolved(DNSSDService sref, DNSSDFlags flags, uint ifIndex, String fullName, String hostName, ushort port, TXTRecord txtRecord)
        {
            m_resolver.Stop();
            m_resolver = null;

            PeerData peer = this.selectedPeer;

            peer.Port = port;

            try
            {
                m_resolver = m_service.QueryRecord(0, ifIndex, hostName, DNSSDRRType.kDNSSDType_A, DNSSDRRClass.kDNSSDClass_IN, m_eventManager);
            }
            catch
            {
                System.Console.WriteLine("Error - QueryRecord Failed");
            }
        }

        // QueryAnswered
        //
        // Called by DNSServices core as a result of DNSService.QueryRecord()
        public void QueryAnswered(DNSSDService service, DNSSDFlags flags, uint ifIndex, String fullName, DNSSDRRType rrtype, DNSSDRRClass rrclass, Object rdata, uint ttl)
        {
            m_resolver.Stop();
            m_resolver = null;

            PeerData peer = this.selectedPeer;

            uint bits = BitConverter.ToUInt32((Byte[])rdata, 0);
            System.Net.IPAddress address = new System.Net.IPAddress(bits);

            peer.Address = address;

            try
            {
                IPEndPoint ipe = new IPEndPoint(address, peer.Port);
                m_socket.Connect(ipe);
                m_socket.BeginReceive(m_buffer, 0, BUFFER_SIZE, 0, new AsyncCallback(this.OnReadSocket), this);
            }
            catch (Exception e)
            {
                System.Console.WriteLine(e.Message);
            }
        }

        public void OperationFailed(DNSSDService service, DNSSDError error)
        {
            System.Console.WriteLine("Error - Operation returned an error code " + error);
        }

        // OnReadSocket
        //
        // Called by the .NET core when there is data to be read on a socket
        //
        // This is called from a worker thread by the .NET core
        private void OnReadSocket(IAsyncResult ar)
        {
            try
            {
                int read = m_socket.EndReceive(ar);

                if (read > 0)
                {
                    byte[] s = m_buffer;
                    this.rayTracer.xSectionStart = BitConverter.ToInt16(s, 2);
                    this.rayTracer.ySectionStart = BitConverter.ToInt16(s, 4);
                    this.rayTracer.xSectionEnd = BitConverter.ToInt16(s, 6);
                    this.rayTracer.ySectionEnd = BitConverter.ToInt16(s, 8);
                }

                System.Console.WriteLine("Received worload...");
                m_socket.BeginReceive(m_buffer, 0, BUFFER_SIZE, 0, new AsyncCallback(OnReadSocket), this);
            }
            catch (Exception e)
            {
                System.Console.WriteLine("Error - OnReadSocket - " + e.Message );
            }

            this.render();
        }

        public void render() 
        {
            for (int x = this.rayTracer.xSectionStart; x < this.rayTracer.xSectionEnd; x += 5)
            {
                for (int y = this.rayTracer.ySectionStart; y < this.rayTracer.ySectionEnd; y += 5)
                {
                    this.rayTracer.renderPixels(x, y);
                    
                    PeerData peer = this.selectedPeer;
                    Byte[] bytes = this.rayTracer.getRenderedPixels(x,y);
                    try {
                        m_socket.Send(bytes);
                    }
                    catch (Exception e)
                    {
                        System.Console.WriteLine(e.Message);
                        this.initialize();
                        break;
                    }
                }
            }
            System.Console.WriteLine("Task complete...");
        }

        public Connection()
        {
            this.initialize();
        }

        private void initialize()
        {
            try
            {
                m_service = new DNSSDService();
            }
            catch
            {
                System.Console.WriteLine("Error - Bonjour Service is not available");
            }

            m_eventManager = new DNSSDEventManager();
            m_eventManager.ServiceRegistered += new _IDNSSDEvents_ServiceRegisteredEventHandler(this.ServiceRegistered);
            m_eventManager.ServiceFound += new _IDNSSDEvents_ServiceFoundEventHandler(this.ServiceFound);
            m_eventManager.ServiceLost += new _IDNSSDEvents_ServiceLostEventHandler(this.ServiceLost);
            m_eventManager.ServiceResolved += new _IDNSSDEvents_ServiceResolvedEventHandler(this.ServiceResolved);
            m_eventManager.QueryRecordAnswered += new _IDNSSDEvents_QueryRecordAnsweredEventHandler(this.QueryAnswered);
            m_eventManager.OperationFailed += new _IDNSSDEvents_OperationFailedEventHandler(this.OperationFailed);

            this.rayTracer = new RayTracer();

            this.load();
        }

        private void load()
        {
            IPEndPoint localEP = new IPEndPoint(System.Net.IPAddress.Any, 0);

            // create the socket and bind to INADDR_ANY
            m_socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            m_socket.Bind(localEP);
            localEP = (IPEndPoint)m_socket.LocalEndPoint;

            // start asynchronous read
            // m_socket.BeginReceive(m_buffer, 0, BUFFER_SIZE, 0, new AsyncCallback(this.OnReadSocket), this);

            try
            {
                // start the register and browse operations
                m_registrar = m_service.Register(0, 0, System.Environment.UserName, regName, null, null, (ushort)localEP.Port, null, m_eventManager);
                //m_socket.Listen(32);
                //m_socket = m_socket.Accept();
                //m_socket.BeginReceive(m_buffer, 0, BUFFER_SIZE, 0, new AsyncCallback(this.OnReadSocket), this);
            }
            catch
            {
                System.Console.WriteLine("Error - Bonjour service is not available");
            }
        }

        // called when peer target changes
        private void selectNewPeer()
        {
            PeerData peer = this.selectedPeer;

            try
            {
                m_resolver = m_service.Resolve(0, peer.InterfaceIndex, peer.Name, peer.Type, peer.Domain, m_eventManager);
            }
            catch
            {
                System.Console.WriteLine("Error - Unable to Resolve service");
            }
        }
    }

    // PeerData
    //
    // Holds onto the information associated with a peer on the network
    public class PeerData
    {
        public uint InterfaceIndex;
        public String Name;
        public String Type;
        public String Domain;
        public IPAddress Address;
        public int Port;

        public override String ToString()
        {
            return Name;
        }

        public override bool Equals(object other)
        {
            bool result = false;

            if (other != null)
            {
                if ((object)this == other)
                {
                    result = true;
                }
                else if (other is PeerData)
                {
                    PeerData otherPeerData = (PeerData)other;

                    result = (this.Name == otherPeerData.Name);
                }
            }

            return result;
        }

        public override int GetHashCode()
        {
            return Name.GetHashCode();
        }
    };
}