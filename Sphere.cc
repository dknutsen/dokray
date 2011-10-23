

#include "Sphere.hh"
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
   this->radius = radius;
}

Point Sphere::GetCenter()const{ return center; }

float Sphere::GetRadius()const{ return radius; }

Point& Sphere::GetCenter(){ return center; }

float& Sphere::GetRadius(){ return radius; }

float Sphere::GetRadiusSquared()const{ return radius*radius; }



void Sphere::Preprocess(){
   material->Preprocess();
}

Vector Sphere::Normal(const Point& point)const{
   return (point-center).Normal();
}

void Sphere::Intersect(HitRecord& hit, const RenderContext& rc, const Ray& ray)const{
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

   Vector dist = ray.Origin() - center;
   float b = Dot(dist, ray.Direction());
   float c = Dot(dist, dist) - GetRadiusSquared();
   float d = b*b - c;
   float t = d > 0 ? -b - sqrt(d) : std::numeric_limits<float>::infinity();

   hit.Hit(t, this, this->material);
}
