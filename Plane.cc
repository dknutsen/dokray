
#include "Plane.hh"
#include "Ray.hh"
#include "HitRecord.hh"

Plane::Plane(Material* material, Vector normal, Point point){
   this->material = material;
   this->normal = normal;
   this->point = point;
}

void Plane::Preprocess(){
   normal.Normalize();
   material->Preprocess();
}

Vector Plane::Normal(const Point& point)const{
   return normal;
}

void Plane::Intersect(HitRecord& hit, const RenderContext& rc, const Ray& ray)const{
   //Vector p(ray.p().x(),ray.p().y(),ray.p().z());
   //Vector o(point.x(),point.y(),point.z());
   //float d = dot(o, norm);

   float num = Dot(-normal, ray.Origin()-point);
   float denom = Dot(normal, ray.Direction());
   float t=num/denom;
   if(denom==0 || num==0 || t<0) hit.Hit(std::numeric_limits<float>::infinity(), this, material);
   else hit.Hit(num/denom, this, material);
	
   //float num = -(dot(norm,p)+d);
   //float denom = dot(norm, ray.d());
   //if((denom==0 || num==0)) hit.hit(std::numeric_limits<float>::infinity(), this, material);
   //else hit.hit(num/denom, this, material);
}
