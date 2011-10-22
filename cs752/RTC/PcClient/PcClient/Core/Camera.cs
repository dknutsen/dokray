/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

namespace RT {

    public class Camera {

        public double deg2rad = 0.0174532925f;
        public Point eye;
        public Point lat;
        public Vector up;
        public float fov;

        public Vector U, V, L;

        public Point getEye()
        {
            return this.eye;
        }

        public void preprocess(float aspect)
        {

            this.L = (this.lat - this.eye).normal();
            Vector Ut = Vector.cross( this.L, this.up );
            Vector Vt = Vector.cross( Ut, this.L );

            this.U = Ut.normal();
            this.U = this.U * (float)System.Math.Tan( this.deg2rad * this.fov * 0.5f );
            this.V = Vt.normal();
            this.V = this.V * ( ( 1/aspect ) * (float)System.Math.Tan( this.deg2rad * this.fov * 0.5f ) );

        }

        public Ray generateRay(float x, float y)
        {
            return new Ray( this.eye, (this.L + (x * this.U) + (y * this.V) ).normal() );
        }

    }

    class PinholeCamera : Camera
    {
        public PinholeCamera(Point eye, Point lat, Vector up, float fov)
        {
            this.eye = eye;
            this.lat = lat;
            this.up = up;
            this.fov = fov;  
        }
    }

} // namespace RT