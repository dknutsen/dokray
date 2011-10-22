/*
     Author: dok 
     Desc:   Basic Ray class
 */

#ifndef Ray_hh
#define Ray_hh

#include "Vector.h"
#include "Point.h"

/*   todo: use heap allocation?
 *
 */

class Ray
{
private:
   Point origin;
   Vector dir;

public:

   /*----------------------- Constructors ----------------*/
   Ray(const Point& point, const Vector& direction){	// parameter constructor
      origin = point;
      dir = direction;
      dir.normalize();
   }

   Ray(float x, float y, float z, float u, float v, float w) // parameter constructor
   {
      origin = Point(x,y,z);
      dir = Vector(u,v,w);
   }

   Ray(const Ray &r){
      origin = Point();
      dir = Vector();
      origin += Ray.origin;
      dir += ray.dir; 
   }

   Ray(){                               // default constructor
      origin = Point(0,0,0);
      dir = Vector(0,0,0);
   }


   /*------------------- Accessors ------------*/ 
   Point point()const{
      return origin;
   }

   Vector direction()const{
      return dir;
   }

   Point& point(){
      return origin;
   }

   Vector& direction(){
      return dir;
   }


   /*--------------- Ray Functions -----------*/
   Point pointOn(float t){
      return origin + t*dir;
   }
};

#endif



