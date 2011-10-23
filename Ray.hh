/*
     Author: dok 
     Desc:   Basic Ray class
 */

#ifndef Ray_hh
#define Ray_hh

#include "Vector.hh"
#include "Point.hh"

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
      dir.Normalize();
   }

   Ray(float x, float y, float z, float u, float v, float w) // parameter constructor
   {
      origin = Point(x,y,z);
      dir = Vector(u,v,w);
   }

   Ray(const Ray &ray){
      origin = Point();
      dir = Vector();
      origin += ray.origin;
      dir += ray.dir; 
   }

   Ray(){                               // default constructor
      origin = Point(0,0,0);
      dir = Vector(0,0,0);
   }


   /*------------------- Accessors ------------*/ 
   Point Origin()const{
      return origin;
   }

   Vector Direction()const{
      return dir;
   }

   Point& Origin(){
      return origin;
   }

   Vector& Direction(){
      return dir;
   }


   /*--------------- Ray Functions -----------*/
   Point PointOn(float t){
      return origin + t*dir;
   }
};

#endif



