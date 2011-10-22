using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Drawing;

namespace PcClient
{
    [Serializable()]
    public class Pixel
    {
        public Int16 x;
        public Int16 y;
        public Int16 r;
        public Int16 g;
        public Int16 b;
    }

    public class RayTracer
    {
        public RT.Scene scene = null;
        public RT.Core core = null;
        public List<Pixel> pixels = new List<Pixel>();
        public Bitmap image = null;
        public const int xResolution = 50;
        public const int yResolution = 50;
        public int xSectionStart, ySectionStart, xSectionEnd, ySectionEnd;
        public int pixelCount = 0;

        public RayTracer()
        {
            this.image = new Bitmap(xResolution, yResolution);
            this.scene = createScene();
            this.scene.setResolution(xResolution, yResolution);
            this.scene.preprocess();
            this.core = new RT.Core(scene);
        }

        public byte[] getRenderedPixels(int x, int y)
        {
            byte[] msg = new byte[10 + (this.pixels.Count * 6)];

            byte[] client = BitConverter.GetBytes(true);
            byte[] xStartByte = BitConverter.GetBytes(x);
            byte[] yStartByte = BitConverter.GetBytes(y);
            byte[] xEndByte = BitConverter.GetBytes(x + 5);
            byte[] yEndByte = BitConverter.GetBytes(y+5);

            System.Buffer.BlockCopy(client, 0, msg, 0, 1);
            System.Buffer.BlockCopy(xStartByte, 0, msg, 2, 2);
            System.Buffer.BlockCopy(yStartByte, 0, msg, 4, 2);
            System.Buffer.BlockCopy(xEndByte, 0, msg, 6, 2);
            System.Buffer.BlockCopy(yEndByte, 0, msg, 8, 2);

            int offset = 10;
            for (int i = 0; i < this.pixels.Count; i++)
            {
                byte[] rByte = BitConverter.GetBytes(this.pixels[i].r);
                byte[] gByte = BitConverter.GetBytes(this.pixels[i].g);
                byte[] bByte = BitConverter.GetBytes(this.pixels[i].b);

                System.Buffer.BlockCopy(rByte, 0, msg, offset, 2);
                System.Buffer.BlockCopy(gByte, 0, msg, offset + 2, 2);
                System.Buffer.BlockCopy(bByte, 0, msg, offset + 4, 2);

                offset += 6;
            }

            return msg;
        }

        public RT.Scene createScene()
        {
            float kd = 0.6f;
            float ka = 0.4f;
            int maxr = 15;

            RT.Scene scene = new RT.Scene();
            RT.Group world = new RT.Group();
            System.Random rand = new System.Random();
            for (int i = 0; i < 60; i++)
            {

                float x = (float)((i * 300) % (maxr * 1000)) / 1000;
                float y = (float)((i * 600) % (maxr * 1000)) / 1000;
                float z = (float)((i * 900) % (maxr * 1000)) / 3000;

                world.addObject(new RT.Sphere(
                   new RT.LambertianMaterial(new RT.Color(0.4f, 0.9f, 0.3f), kd, ka),
                   new RT.Point(-(float)maxr * 0.5f + x, -(float)maxr * 0.5f + y, z), 0.3f));

            }

            world.addObject(new RT.Plane(new RT.LambertianMaterial(
               new RT.Color(0.8f, 0.8f, 0.8f), kd, ka), new RT.Vector(0, 0, 1),
               new RT.Point(0, 0, -0.1f)));

            scene.setObject(world);

            scene.setBackground(new RT.ConstantBackground(
               new RT.Color(0.0f, 0.0f, 0.0f)));

            scene.setAmbient(new RT.Color(ka, ka, ka));

            scene.addLight(new RT.PointLight(new RT.Point(20, -30, 100),
               new RT.Color(0.9f, 0.9f, 0.9f)));

            scene.setCamera(new RT.PinholeCamera(new RT.Point(12, -12, 7),
               new RT.Point(1, 1, 2), new RT.Vector(0, 0, 1), 60));

            return scene;

        }

        public void renderPixels(int xStart, int yStart)
        {
            RT.Color color = null;
            this.pixels.Clear();
            for (int x = xStart; x < (xStart + 5); x++)
            {
                for (int y = yStart; y < (yStart + 5); y++)
                {
                    Pixel pixel = new Pixel();
                    pixel.x = (Int16)x;
                    pixel.y = (Int16)y;

                    color = this.core.renderPixel(x, (yResolution - y));
                    
                    pixel.r = color.rInt();
                    pixel.g = color.gInt();
                    pixel.b = color.bInt();
                    System.Console.WriteLine("Rendered pixel (" + pixel.x.ToString() + "," + pixel.y.ToString() + ") as (" + pixel.r.ToString() + "," + pixel.g.ToString() + "," + pixel.b.ToString() + ")");
                    image.SetPixel(x,y,Color.FromArgb(pixel.r, pixel.g, pixel.b));
                    this.pixels.Add(pixel);
                    pixelCount++;
                }
            }

            if (pixelCount >= (xResolution * yResolution))
            {
                System.Console.WriteLine("Rendering complete...");
                image.Save("image.bmp");
                this.pixelCount = 0;
            }
        }
    }
}
