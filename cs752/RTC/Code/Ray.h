/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

#ifndef RT_RAY_H
#define RT_RAY_H

#include "Point.h"
#include "Vector.h"

namespace RT {

   class Ray {
   private:

      Point o;
      Vector dir;

   public:

      Ray() {

         this->o = Point(0,0,0);
         this->dir = Vector(0,0,0);

      }

      Ray( const Point& point, const Vector& direction )	{

         this->o = point;
         this->dir = direction;
         this->dir.normalize();

      }

      Ray( float x, float y, float z, float u, float v, float w ) {

         this->o = Point(x,y,z);
         this->dir = Vector(u,v,w);

      }

      Point p() const { return this->o; }
      Point& p() { return this->o; }

      Vector d()const { return this->dir; }
      Vector& d() { return this->dir; }

      Point pointOn( float t ) { return this->o + ( t * this->dir ); }

   };

} // namespace RT

#endif // RT_RAY_H
