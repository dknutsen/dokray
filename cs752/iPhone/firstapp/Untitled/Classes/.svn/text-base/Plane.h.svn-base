#ifndef Plane_h
#define Plane_h

#include "Primitive.h"
#include "Vector.h"
#include "Point.h"

class HitRecord;
class RenderContext;
class Ray;

class Plane : public Primitive{
private:
	Material* material;
	Vector norm;
	RPoint point;
public:
	Plane(Material* material, Vector normal, RPoint point);

	void preprocess();
	Vector normal(const RPoint& point)const;
	void intersect(HitRecord& hit, const RenderContext& rc, const Ray& ray)const;
};

#endif