

#include "Object.hh"


void Group::Preprocess(){
   for(int i=0; i<objects.size(); i++)
      objects[i]->Preprocess();
}

void Group::Intersect(HitRecord& hit, const RenderContext& rc, const Ray& ray)const{
   for(int i=0; i<objects.size(); i++)
      objects[i]->Intersect(hit, rc, ray);
}

void Group::AddObject(Object* object){
   objects.push_back(object);
}
