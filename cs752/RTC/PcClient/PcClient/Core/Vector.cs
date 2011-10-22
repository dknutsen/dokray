/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

namespace RT {

   public class Vector  {

       public float[] c = new float[3];

       public Vector(float x, float y, float z)
       {

         this.c[0] = x; 
         this.c[1] = y; 
         this.c[2] = z;

      }

       public Vector()
       {

         this.c[0] = 0; 
         this.c[1] = 0; 
         this.c[2] = 0;

      }

       public float x() { return this.c[0]; }
       public float y() { return this.c[1]; }
       public float z() { return this.c[2]; }

       public float get(int i)
       {
          return this.c[i%3];
      }

       public float length2() { return (this.c[0] * this.c[0]) + (this.c[1] * this.c[1]) + (this.c[2] * this.c[2]); }
       public float length() { return (float)System.Math.Sqrt(this.length2()); }

       public Vector normal()
       {

         float length = this.length();
         float div = 1/length;
         return new Vector( this.c[0]*div, this.c[1]*div, this.c[2]*div );

      }

       public float normalize()
       {

         float length = this.length();
         float div = 1/length;
         this.c[0] *= div; 
         this.c[1] *= div; 
         this.c[2] *= div;
         return length;

      }

       public static Vector operator -(Vector v1) { return new Vector(-v1.x(), -v1.y(), -v1.z()); }
       public static Vector operator +(Vector v1, Vector v) { return new Vector(v1.x() + v.x(), v1.y() + v.y(), v1.z() + v.z()); }
       public static Vector operator -(Vector v1, Vector v) { return new Vector(v1.x() - v.x(), v1.y() - v.y(), v1.z() - v.z()); }
       public static Vector operator *(Vector v1, Vector v) { return new Vector(v1.x() * v.x(), v1.y() * v.y(), v1.z() * v.z()); }
       public static Vector operator *(Vector v1, float d) { return new Vector(v1.x() * d, v1.y() * d, v1.z() * d); }
       public static Vector operator *(float x, Vector v) { return new Vector(v.x() * x, v.y() * x, v.z() * x); } 
      public static Vector operator/( float x, Vector v ) { return new Vector( v.x()/x, v.y()/x, v.z()/x ); } 

      public static float dot( Vector v1, Vector v2 ) { return ( v1.x() * v2.x() ) + ( v1.y() * v2.y() ) + ( v1.z() * v2.z() );	} 
      public static Vector cross( Vector v1, Vector v2 ) {

         return new Vector(
            v1.y()*v2.z() - v1.z()*v2.y(),
            v1.z()*v2.x() - v1.x()*v2.z(),
            v1.x()*v2.y() - v1.y()*v2.x() );

      }

   }

} // namespace RT