/*
    Author: dok
    Desc    Primitive base class 

 */

#ifndef Primitive_hh
#define Primitive_hh

#include "Object.h"
#include "Vector.h"
#include "Point.h"

class Material;
class HitRecord;
class RenderContext;
class Ray;

// Big awesome comment here
class Primitive : public Object{
protected:
   Material* material;

public:
   virtual void preprocess() = 0;

   virtual Vector normal(const Point& point)const=0;

   virtual void intersect(HitRecord& hit, const RenderContext& rc, const Ray& ray)const=0;
};

#endif
