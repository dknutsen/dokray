/*
    Author: dok
    Desc    Primitive base class 

 */

#ifndef Primitive_hh
#define Primitive_hh

#include "Object.hh"
#include "Vector.hh"
#include "Point.hh"

class Material;
class HitRecord;
class RenderContext;
class Ray;

// Big awesome comment here
class Primitive : public Object{
protected:
   Material* material;

public:
   virtual void Preprocess() = 0;

   virtual Vector Normal(const Point& point)const=0;

   virtual void Intersect(HitRecord& hit, const RenderContext& rc, const Ray& ray)const=0;
};

#endif
