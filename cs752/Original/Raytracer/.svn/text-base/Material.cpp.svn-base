

#include "Material.h"
#include "HitRecord.h"
#include "Scene.h"
#include "Primitive.h"
#include "Ray.h"
#include "RenderContext.h"
#include "Light.h"
#include "Camera.h"

#include <math.h>


///////////////////
// Lambertian /////
///////////////////
LambertianMaterial::LambertianMaterial(Color color, float kd, float ka){
	this->color = color; this->kd = kd; this->ka = ka;
}

void LambertianMaterial::preprocess(){

}

Color LambertianMaterial::shade(const RenderContext& rc, const Ray& ray, const HitRecord& hrec, int depth) const{
	Point hp = ((Ray&)ray).pointOn(((HitRecord&)hrec).GetT());
	Vector normal = ((HitRecord&)hrec).GetPrimitive()->normal(hp);

	hp += 0.0001f * normal;
	
	Scene* scene = (Scene*)rc.getScene();
	int numlights = scene->num_lights();
	Color finalc(0.f,0.f,0.f);
	for(int i=0; i<numlights; i++){
		Vector ldir;
		Color lcolor;
		float ldist = scene->get_light(i)->getLight(lcolor, ldir, rc, hp);
		
		HitRecord shadowhr;
		Ray shadowray(hp, ldir);
		scene->get_object()->intersect(shadowhr, rc, shadowray);
		if(shadowhr.GetT()>=ldist || shadowhr.GetT()<0.01){
			float dp = dot(normal, ldir);
			if(dp > 0) 
				finalc += dp*lcolor;
		}
	}
	
	return color*(finalc*kd + scene->get_ambient()*ka);
}



///////////////////
// Phong //////////
///////////////////
PhongMaterial::PhongMaterial(Color color, float ke, float kd, float ka, float ks, float shininess){
	this->color = color; this->ke = ke; this->kd = kd; this->ka = ka; this->ks = ks;
	n = shininess;
}

void PhongMaterial::preprocess(){
	//if(kd+ks > 1.f){
	//	float d = 1/(kd+ks);
	//	kd*=d; ks*=d;
	//}
}

Color PhongMaterial::shade(const RenderContext& rc, const Ray& ray, const HitRecord& hrec, int depth) const{
	Scene* scene = (Scene*)rc.getScene();
	Point hp = ((Ray&)ray).pointOn(((HitRecord&)hrec).GetT());
	Vector normal = ((HitRecord&)hrec).GetPrimitive()->normal(hp);
	Vector v = scene->get_camera()->getEye() - hp;
	v.normalize();

	hp += 0.0001f * normal;
	
	int numlights = scene->num_lights();
	Color finalc(0.f,0.f,0.f);

	for(int i=0; i<numlights; i++){
		Vector ldir;
		Color lcolor;
		float ldist = scene->get_light(i)->getLight(lcolor, ldir, rc, hp);
		
		HitRecord shadowhr;
		Ray shadowray(hp, ldir);
		scene->get_object()->intersect(shadowhr, rc, shadowray);
		if((shadowhr.GetT()>=ldist || shadowhr.GetT()<0.01)){
			float dp = dot(normal, ldir) * kd;
			if(!(dp > 0)) dp = 0;
			Vector r = 2*(dot(ldir, normal))*normal - ldir;
			r.normalize();
			float spec = dot(r, v);
			if(!(spec > 0)) spec = 0;
			else 
				spec = pow(spec,n);
				
			finalc += (dp*kd+spec*ks)*lcolor;
		}
	}
	
	return color*(finalc + scene->get_ambient()*ka);
}