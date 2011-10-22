
#include "Plane.h"
#include "Ray.h"
#include "HitRecord.h"

Plane::Plane(Material* material, Vector normal, Point point){
	this->material = material;
	this->norm = normal;
	this->point = point;
}

void Plane::preprocess(){
	norm.normalize();
	material->preprocess();
}

Vector Plane::normal(const Point& point)const{
	return norm;
}

void Plane::intersect(HitRecord& hit, const RenderContext& rc, const Ray& ray)const{
	//Vector p(ray.p().x(),ray.p().y(),ray.p().z());
	//Vector o(point.x(),point.y(),point.z());
	//float d = dot(o, norm);

	float num = dot(-norm, ray.p()-point);
	float denom = dot(norm, ray.d());
	float t=num/denom;
	if(denom==0 || num==0 || t<0) hit.hit(std::numeric_limits<float>::infinity(), this, material);
	else hit.hit(num/denom, this, material);
	
	//float num = -(dot(norm,p)+d);
	//float denom = dot(norm, ray.d());
	//if((denom==0 || num==0)) hit.hit(std::numeric_limits<float>::infinity(), this, material);
	//else hit.hit(num/denom, this, material);
}