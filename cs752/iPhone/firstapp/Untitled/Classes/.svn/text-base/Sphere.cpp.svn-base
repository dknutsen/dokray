

#include "Sphere.h"
#include <iostream>

using std::cout;

Sphere::Sphere(){
	material = NULL;
	p = RPoint(0,0,0);
	rad = 1.f;
}

Sphere::Sphere(Material* material, const RPoint& c, float radius){
	this->material = material;
	p = c;
	rad = radius;
}

RPoint Sphere::c()const{ return p; }
float Sphere::r()const{ return rad; }
RPoint& Sphere::c(){ return p; }
float& Sphere::r(){ return rad; }
float Sphere::r2()const{ return rad*rad; }

void Sphere::preprocess(){
	material->preprocess();
}

Vector Sphere::normal(const RPoint& point)const{
	return (point-p).normal();
}

void Sphere::intersect(HitRecord& hit, const RenderContext& rc, const Ray& ray)const{
	/*float a = dot(ray.d(), ray.d());
	Vector v = ray.p()-p;/*Vector(ray.p().x(), ray.p().y(), ray.p().z());*/
    /*float b = 2 * dot(ray.d(), v);
    float c = dot(v, v) - r2();
    float disc = b * b - 4 * a * c;
	if (disc < 0.f){
		hit.hit(std::numeric_limits<float>::infinity(), this, material);
		return;
	}
    float distSqrt = sqrtf(disc);
    float q;
    if (b < 0) q = (-b - distSqrt)/2.0f;
    else       q = (-b + distSqrt)/2.0f;
    float t0 = q / a;
    float t1 = c / q;
    if (t0 > t1){
        float temp = t0;
        t0 = t1;
        t1 = temp;
    }
    if (t1 < 0) hit.hit(std::numeric_limits<float>::infinity(), this, material);
	if (t0 < 0) hit.hit(t1, this, material);
    else		hit.hit(t0, this, material);*/

	Vector dist = ray.p() - p;
	float b = dot(dist, ray.d());
	float c = dot(dist, dist) - r2();
	float d = b*b - c;
	float t = d > 0 ? -b - sqrt(d) : std::numeric_limits<float>::infinity();

	hit.hit(t, this, this->material);
}