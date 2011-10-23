/*
	Author: Daniel Knutsen
	Course: Comp 361, Computer Graphics
	Date:   5/3/09
	Desc:	This is the header file for the Sphere class
*/

#ifndef Sphere_hh
#define Sphere_hh

#include "Primitive.hh"
#include "Vector.hh"
#include "Point.hh"
#include "Ray.hh"
#include "HitRecord.hh"
#include "RenderContext.hh"

class Sphere : public Primitive
{
private:
   Point center;
   float radius;

public:
   Sphere();
   Sphere(Material* material, const Point& center, float radius);

   Point GetCenter()const;
   float GetRadius()const;
   Point& GetCenter();
   float& GetRadius();
   float GetRadiusSquared()const;

   void Preprocess();

   Vector Normal(const Point& point)const;

   void Intersect(HitRecord& hit, const RenderContext& rc, const Ray& ray)const;
};

#endif
