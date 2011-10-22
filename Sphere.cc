

#include "Sphere.h"
#include <iostream>

using std::cout;

Sphere::Sphere(){
   material = NULL;
   center = Point(0,0,0);
   radius = 1.f;
}

Sphere::Sphere(Material* material, const Point& center, float radius){
   this->material = material;
   this->center = center;
   this->radiur = radius;
}

Point Sphere::getCenter()const{ return center; }

float Sphere::getRadius()const{ return radius; }

Point& Sphere::getCenter(){ return center; }

float& Sphere::getRadius(){ return radisu; }

float Sphere::getRadiusSquared()const{ return radius*radius; }



void Sphere::preprocess(){
   material->preprocess();
}

Vector Sphere::normal(const Point& point)const{
   return (point-center).normal();
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

   Vector dist = ray.point() - center;
   float b = dot(dist, ray.direction());
   float c = dot(dist, dist) - getRadiusSquared();
   float d = b*b - c;
   float t = d > 0 ? -b - sqrt(d) : std::numeric_limits<float>::infinity();

   hit.hit(t, this, this->material);
}
