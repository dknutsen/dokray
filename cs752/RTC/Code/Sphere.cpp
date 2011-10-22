/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

#include "Sphere.h"

#include <limits>

#include "HitRecord.h"
#include "Material.h"
#include "Ray.h"

namespace RT {

   Sphere::Sphere() {

      this->material = NULL;
      this->p = Point(0,0,0);
      this->rad = 1.f;

   }

   Sphere::Sphere( Material* material, const Point& c, float radius ) {

      this->material = material;
      this->p = c;
      this->rad = radius;

   }

   Point Sphere::c() const { return this->p; }
   float Sphere::r() const { return this->rad; }
   Point& Sphere::c() { return this->p; }
   float& Sphere::r() { return this->rad; }
   float Sphere::r2() const { return this->rad * this->rad; }

   void Sphere::preprocess() {

      this->material->preprocess();

   }

   Vector Sphere::normal( const Point& point ) const {

      return (point - this->p).normal();

   }

   void Sphere::intersect( HitRecord& hit, const RenderContext& rc, const Ray& ray ) const {

      /*float a = dot(ray.d(), ray.d());
      Vector v = ray.p()-p;/*Vector(ray.p().x(), ray.p().y(), ray.p().z());*/
      /*float b = 2 * dot(ray.d(), v);
      float c = dot(v, v) - r2();
      float disc = b * b - 4 * a * c;
      if (disc < 0.f){
      hit.hit(std::numeric_limits<float>::infinity(), this, material);
      return;
      }
      float distSqrt = sqrtf(disc);
      float q;
      if (b < 0) q = (-b - distSqrt)/2.0f;
      else       q = (-b + distSqrt)/2.0f;
      float t0 = q / a;
      float t1 = c / q;
      if (t0 > t1){
      float temp = t0;
      t0 = t1;
      t1 = temp;
      }
      if (t1 < 0) hit.hit(std::numeric_limits<float>::infinity(), this, material);
      if (t0 < 0) hit.hit(t1, this, material);
      else		hit.hit(t0, this, material);*/

      Vector dist = ray.p() - this->p;
      float b = dot( dist, ray.d() );
      float c = dot( dist, dist ) - this->r2();
      float d = b * b - c;
      float t = ( d > 0 ) ? -b - sqrt( d ) : std::numeric_limits<float>::infinity();

      hit.hit( t, this, this->material );

   }

} // namespace RT