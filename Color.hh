/*
   Author: Daniel Knutsen
   Desc:   This is the header file for the color class
*/

#ifndef Color_hh
#define Color_hh

#include "Vector.h"

#include <iostream>
using std::ostream;

class Color
{
private:
   float c[3];

public:
   /*--------------------- Constructors --------------------*/
   Color(float r, float g, float b){
      c[0] = r;
      c[1] = g;
      c[2] = b;
   }

   Color(const Color& color){
      c[0] = color.r();
      c[1] = color.g();
      c[2] = color.b();
   }

   Color::Color(){
      c[0] = 0;
      c[1] = 0;
      c[2] = 0;
   }

   /*------------------- Accessors -----------------------*/
   float r()const{return c[0];}
   float g()const{return c[1];}
   float b()const{return c[2];}

   float& r(){return c[0];}
   float& g(){return c[1];}
   float& b(){return c[2];}


   /*----------------- Operators ------------------------------*/
   float operator[](int i) const{
      return c[i%3];
   }

   float operator[](int i){
      return c[i%3];
   }

   Color operator+(const Color& color)const{
      return Color(c[0] + color.r(), c[1] + color.g(), c[2] + color.b());
   }

   Color operator-(const Color& color)const{
      return Color(c[0] - color.r(), c[1] - color.g(), c[2] - color.b());
   }

   Color operator*(const Color& color)const{
      return Color(color.r()*c[0], color.g()*c[1], color.b()*c[2]);
   }

   Color operator*(const Vector& v)const{
      return Color(v.x()*c[0], v.y()*c[1], v.z()*c[2]);
   }

   Color operator*(float d)const{
      return Color(c[0]*d, c[1]*d, c[2]*d);
   }

   Color& operator+=(const Color& color){
      c[0] = c[0] + color.r();
      c[1] = c[1] + color.g();
      c[2] = c[2] + color.b();
      return *this;
   }

   Color& operator-=(const Color& color){
      c[0] = c[0] - color.r();
      c[1] = c[1] - color.g();
      c[2] = c[2] - color.b();
      return *this;
   }

   friend Color operator*(float x, const Color& color){
      return Color(x*color.r(), x*color.g(), x*color.b());
   }

   /*friend operator<<(ostream& o, const Color& color){
      o << color.r() << "," << color.g() << "," << color.b();
      return o;
   }*/


   /*-------------------------------- Color Functions -----------------*/
   // rename this something better
   void crustualize(){
      float max=0.f;
      for(int i=0; i<3; i++)
         if(c[i]>max) max = c[i];
      float dmax = 1.f/max;
      for(int i=0; i<3; i++)
         c[i] *= dmax;
   }
};

#endif
