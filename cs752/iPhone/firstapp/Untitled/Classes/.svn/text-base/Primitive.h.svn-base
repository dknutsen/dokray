#ifndef Primitive_h
#define Primitive_h

#include "Object.h"
#include "Vector.h"
#include "Point.h"

class Material;
class HitRecord;
class RenderContext;
class Ray;

class Primitive : public Object{
protected:
	Material* material;
public:
	virtual void preprocess() = 0;
	virtual Vector normal(const RPoint& point)const=0;
	virtual void intersect(HitRecord& hit, const RenderContext& rc, const Ray& ray)const=0;
};

#endif