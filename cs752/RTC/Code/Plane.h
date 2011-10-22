/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

#ifndef RT_PLANE_H
#define RT_PLANE_H

#include "Point.h"
#include "Primitive.h"
#include "Vector.h"

namespace RT {

   class HitRecord;
   class Material;
   class Ray;
   class RenderContext;

   class Plane : public Primitive {
   private:

	   Material* material;
	   Vector norm;
	   Point point;

   public:

      Plane(Material* material, Vector normal, Point point);

	   void preprocess();
	   Vector normal( const Point& point )const;
	   void intersect( HitRecord& hit, const RenderContext& rc, const Ray& ray ) const;

   };

} // namespace RT

#endif // RT_PLANE_H