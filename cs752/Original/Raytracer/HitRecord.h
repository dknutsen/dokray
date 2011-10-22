#ifndef HitRecord_h
#define HitRecord_h

#include "Primitive.h"
#include "Material.h"
#include <limits>

class HitRecord{
private:
	float t;
	Primitive* primitive;
	Material* material;
public:
	HitRecord(){
		t = std::numeric_limits<float>::infinity();
		primitive = NULL;
		material = NULL;
	}

	float GetT(){ return t; }
	Primitive* GetPrimitive(){ return primitive; }
	Material* GetMaterial(){ return material; }
	bool hit(float t, const Primitive* hit_primitive, const Material* hit_material){
		if(this->t > t){
			this->t = t;
			this->primitive = (Primitive*)hit_primitive;
			this->material = (Material*)hit_material;
			return true;
		}
		return false;
	}
};


#endif