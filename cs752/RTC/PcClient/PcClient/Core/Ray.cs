/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

namespace RT {

   public class Ray {

       public Point o;
       public Vector dir;

       public Ray()
       {

         this.o = new Point(0,0,0);
         this.dir = new Vector(0,0,0);

      }

       public Ray(Point point, Vector direction)
       {

         this.o = point;
         this.dir = direction;
         this.dir.normalize();

      }

       public Ray(float x, float y, float z, float u, float v, float w)
       {

         this.o = new Point(x,y,z);
         this.dir = new Vector(u,v,w);

      }

       public Point p() { return this.o; }
       public Vector d() { return this.dir; }

       public Point pointOn(float t) { return this.o + (t * this.dir); }

   }

} // namespace RT