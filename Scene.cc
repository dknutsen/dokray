

#include "Scene.hh"
#include "Background.hh"
#include "Camera.hh"
#include "Object.hh"
#include "Image.hh"
#include "Light.hh"
#include "Material.hh"
#include "HitRecord.hh"
#include "RenderContext.hh"

/*------------------------- Set Methods -----------------------------*/
void Scene::SetAmbient(Color ambient){ this->ambient = ambient; }

void Scene::SetBackground(Background* background){ this->background = background; }

void Scene::SetCamera(Camera* camera){ this->camera = camera; }

void Scene::SetImage(Image* image){ this->image = image; }

void Scene::SetObject(Object* object){ this->object = object; }

void Scene::AddLight(Light* light){ lights.push_back(light); }

/*------------------------- Get Methods ---------------------------*/
Light* Scene::GetLight(int index){ return lights[index]; }

int Scene::NumLights(){ return lights.size(); }

Color Scene::GetAmbient()const{ return ambient; }

Object* Scene::GetObject(){ return object; }

Camera* Scene::GetCamera(){ return camera; }


/*------------------------- Other Methods -----------------------*/
void Scene::Preprocess(){
   background->Preprocess();
   camera->Preprocess(image->Aspect());
   object->Preprocess();
   for(int i=0; i<lights.size(); i++)
      lights[i]->Preprocess();
}

void Scene::Render(){
   int resx = image->GetXRes();
   int resy = image->GetYRes();
   float step = 2.f/(float)resx;
   float xstart = -1.f + 0.5f*step;
   float ystart = -(float)resy*0.5f*step + 0.5f*step;
   for(int i=0; i<resx; i++){
      for(int j=0; j<resy; j++){
         Ray r;
         RenderContext rc(this);
         HitRecord hr;
         camera->GenerateRay(r, rc, xstart+i*step, ystart+j*step);
         TraceRay(r, hr, rc);
         Color c;
         if(hr.GetT()==std::numeric_limits<float>::infinity() || hr.GetMaterial()==NULL || hr.GetPrimitive() == NULL){
            c = background->GetColor(rc, r);
         }
         else{
            c = hr.GetMaterial()->Shade(rc, r, hr, 1);
         }		
         image->Set(i,j,c);
      }
   }
}

void Scene::TraceRay(const Ray& ray, HitRecord& hr, RenderContext& rc)const{
   object->Intersect(hr, rc, ray);
}
