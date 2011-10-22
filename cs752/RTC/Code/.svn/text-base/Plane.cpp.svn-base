/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

#include "Plane.h"

#include <limits>

#include "HitRecord.h"
#include "Material.h"
#include "Point.h"
#include "Ray.h"
#include "Vector.h"

namespace RT {

   Plane::Plane( Material* material, Vector normal, Point point ) {
      this->material = material;
      this->norm = normal;
      this->point = point;
   }

   void Plane::preprocess() {
      this->norm.normalize();
      this->material->preprocess();
   }

   Vector Plane::normal( const Point& point ) const {
      return this->norm;
   }

   void Plane::intersect( HitRecord& hit, const RenderContext& rc, const Ray& ray ) const {
      //Vector p(ray.p().x(),ray.p().y(),ray.p().z());
      //Vector o(point.x(),point.y(),point.z());
      //float d = dot(o, norm);

      float num = dot( -this->norm, ray.p() - this->point );
      float denom = dot( this->norm, ray.d() );
      float t = num/denom;
      if ( denom==0 || num==0 || t < 0 ) hit.hit( std::numeric_limits<float>::infinity(), this, this->material );
      else hit.hit( num/denom, this, this->material );

      //float num = -(dot(norm,p)+d);
      //float denom = dot(norm, ray.d());
      //if((denom==0 || num==0)) hit.hit(std::numeric_limits<float>::infinity(), this, material);
      //else hit.hit(num/denom, this, material);
   }

} // namespace RT