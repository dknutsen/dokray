/*
	Author: Daniel Knutsen
	Course: Comp 361, Computer Graphics
	Date:   5/3/09
	Desc:	This is the header file for the Sphere class
*/

#ifndef Sphere_h
#define Sphere_h

#include "Primitive.h"
#include "Vector.h"
#include "Point.h"
#include "Ray.h"
#include "HitRecord.h"
#include "RenderContext.h"

class Sphere : public Primitive
{
private:
	RPoint p;
	float rad;
public:
	Sphere();
	Sphere(Material* material, const RPoint& c, float radius);

	RPoint c()const;
	float r()const;
	RPoint& c();
	float& r();
	float r2()const;

	void preprocess();

	Vector normal(const RPoint& point)const;

	void intersect(HitRecord& hit, const RenderContext& rc, const Ray& ray)const;
};

#endif