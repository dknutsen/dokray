#ifndef Material_h
#define Material_h

#include "Color.h"

class RenderContext;
class Ray;
class HitRecord;

class Material{

public:
	virtual void preprocess() = 0;
	virtual Color shade(const RenderContext& rc, const Ray& ray, const HitRecord& hrec,
		int depth) const=0;
};


class LambertianMaterial : public Material{
private:
	float kd, ka;
	Color color;
public:
	LambertianMaterial(Color color, float kd, float ka);
	void preprocess();
	Color shade(const RenderContext& rc, const Ray& ray, const HitRecord& hrec,
		int depth) const;
};

class PhongMaterial : public Material{
private:
	float kd, ka, ks, ke;
	float n;
	Color color;
public:
	PhongMaterial(Color color, float ke, float kd, float ka, float ks, float shininess);
	void preprocess();
	Color shade(const RenderContext& rc, const Ray& ray, const HitRecord& hrec,
		int depth) const;
};

#endif