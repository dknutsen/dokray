/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

namespace RT {

   public class Point {

      float[] c = new float[3];

       public Point(float x, float y, float z)
       {
         this.c[0] = x; this.c[1] = y; this.c[2] = z;
      }

       public Point(Vector v)
       {
         this.c[0] = v.get(0); this.c[1] = v.get(1); this.c[2] = v.get(2);
      }

       public Point(Point p)
       {
         this.c[0] = p.x(); this.c[1] = p.y(); this.c[2] = p.z();
      }

       public Point()
       {
         this.c[0] = 0; this.c[1] = 0; this.c[2] = 0;
      }

       public float x() { return this.c[0]; }
       public float y() { return this.c[1]; }
       public float z() { return this.c[2]; }

       public float get(int i)
       {
          return this.c[i%3];
      }

      public static Point operator +( Point p, Vector v ) {
         return new Point( p.x()+v.x(), p.y()+v.y(), p.z()+v.z() );
      }

      public static Point operator *( Point p, Vector v ) {
         return new Point( p.x() * v.x(), p.y() * v.y(), p.z() * v.z() );
      }

      public static Vector operator -(Point p1, Point p2) {
         return new Vector( p1.x() - p2.x(), p1.y() - p2.y(), p1.z() - p2.z() );
      }

   }

} // namespace RT