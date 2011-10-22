/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

#ifndef RT_PRIMITIVE_H
#define RT_PRIMITIVE_H

#include "Object.h"
#include "Vector.h"

namespace RT {

   class HitRecord;
   class Material;
   class Point;
   class Ray;
   class RenderContext;

   class Primitive : public Object {
   protected:

      Material* material;

   public:

      virtual void preprocess() = 0;
      virtual Vector normal( const Point& point ) const = 0;
      virtual void intersect( HitRecord& hit, const RenderContext& rc, const Ray& ray ) const = 0;

   };

} // namespace RT

#endif // RT_PRIMITIVE_H