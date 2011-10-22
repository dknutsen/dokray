/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

#include "Camera.h"

#include "Point.h"
#include "Ray.h"
#include "Vector.h"

namespace RT {

   Point PinholeCamera::getEye() {
      return this->eye;
   }

   PinholeCamera::PinholeCamera( Point eye, Point lat, Vector up, float fov )
      : eye( eye ), lat( lat ), up( up ), fov( fov ) { }

   void PinholeCamera::preprocess( float aspect ) {

      this->L = (this->lat - this->eye).normal();
      Vector Ut = cross( this->L, this->up );
      Vector Vt = cross( Ut, this->L );

      //Vector U = (tan(deg2rad*fov*0.5f)) * Ut.normal();
      //Vector V = ((1/aspect)*tan(deg2rad*fov*0.5f)) * Vt.normal();
      this->U = Ut.normal();
      this->U = this->U * tan( deg2rad * this->fov * 0.5f );
      this->V = Vt.normal();
      this->V = this->V * ( ( 1/aspect ) * tan( deg2rad * this->fov * 0.5f ) );

   }

   Ray PinholeCamera::generateRay( float x, float y ) const {
      return Ray( this->eye, (this->L + (x * this->U) + (y * this->V) ).normal() );
   }

} // namespace RT