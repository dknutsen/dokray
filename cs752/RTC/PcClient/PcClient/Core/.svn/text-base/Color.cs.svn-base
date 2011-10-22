/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

namespace RT {

   public class Color {

       public float[] c = new float[3];

       public Color(float r, float g, float b)
       {
         this.c[0] = r;
         this.c[1] = g;
         this.c[2] = b;
      }

       public Color(Color color)
       {
         this.c[0] = color.r();
         this.c[1] = color.g();
         this.c[2] = color.b();
      }

       public Color()
       {
         this.c[0] = 0;
         this.c[1] = 0;
         this.c[2] = 0;
      }

       public System.Int16 rInt() { return (System.Int16)(this.c[0] * 255); }
       public System.Int16 gInt() { return (System.Int16)(this.c[1] * 255); }
       public System.Int16 bInt() { return (System.Int16)(this.c[2] * 255); }

       public float r() { return this.c[0]; }
       public float g() { return this.c[1]; }
       public float b() { return this.c[2]; }

       public System.Drawing.Color getRGBColor()
       {
           return System.Drawing.Color.FromArgb((int)(this.c[0] * 255), (int)(this.c[1] * 255), (int)(this.c[2] * 255));
       }

       public float get(int i)
       {
          return this.c[i%3];
      }

      public static Color operator +(Color c1, Color c2){
         return new Color(c1.r() + c2.r(), c1.g() + c2.g(), c1.b() + c2.b());
      }

      public static Color operator -(Color c1, Color c2){
         return new Color(c1.r() - c2.r(), c1.g() - c2.g(), c1.b() - c2.b());
      }

       public static Color operator *(Color c1, Color c2)
       {
         return new Color(c1.r() * c2.r(), c2.g()*c1.g(), c2.b()*c1.b());
      }

       public static Color operator *(Color c1, Vector v)
       {
         return new Color(v.x()*c1.r(), v.y()*c1.g(), v.z()*c1.b());
      }
      
        public static Color operator *(Color c1, float d){
         return new Color(c1.r()*d, c1.g()*d, c1.b()*d);
      }

      public static Color operator *(float x, Color c2){
         return new Color(x*c2.r(), x*c2.g(), x*c2.b());
      }

      void crustualize() {

         float max = 0;
         for ( int i = 0; i < 3; i++ )
            if ( this.c[i] > max ) max = this.c[i];
      
         float dmax = 1/max;
         for ( int i = 0; i < 3; i++ )
            this.c[i] *= dmax;
      
      }

   }

} // namespace RT
