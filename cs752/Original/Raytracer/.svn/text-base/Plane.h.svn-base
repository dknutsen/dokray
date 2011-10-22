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
	Point point;
public:
	Plane(Material* material, Vector normal, Point point);

	void preprocess();
	Vector normal(const Point& point)const;
	void intersect(HitRecord& hit, const RenderContext& rc, const Ray& ray)const;
};

#endif