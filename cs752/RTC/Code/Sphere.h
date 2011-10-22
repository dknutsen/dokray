/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

#ifndef RT_SPHERE_H
#define RT_SPHERE_H

#include "Point.h"
#include "Primitive.h"
#include "Vector.h"

namespace RT {

   class HitRecord;
   class Material;
   class Ray;
   class RenderContext;

   class Sphere : public Primitive {
   private:

      Point p;
      float rad;

   public:

      Sphere();
      Sphere( Material* material, const Point& c, float radius );

      Point c() const;
      float r() const;
      Point& c();
      float& r();
      float r2() const;

      void preprocess();

      Vector normal(const Point& point)const;

      void intersect( HitRecord& hit, const RenderContext& rc, const Ray& ray )const;
   };

} // namespace RT

#endif // RT_SPHERE_H