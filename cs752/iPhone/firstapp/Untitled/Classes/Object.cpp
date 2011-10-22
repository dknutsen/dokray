

#include "Object.h"


void Group::preprocess(){
	for(int i=0; i<objects.size(); i++)
		objects[i]->preprocess();
}

void Group::intersect(HitRecord& hit, const RenderContext& rc, const Ray& ray)const{
	for(int i=0; i<objects.size(); i++)
		objects[i]->intersect(hit, rc, ray);
}

void Group::add_object(Object* object){
	objects.push_back(object);
}