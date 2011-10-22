

#include "Scene.h"
#include "Background.h"
#include "Camera.h"
#include "Object.h"
#include "Image.h"
#include "Light.h"
#include "Material.h"
#include "HitRecord.h"
#include "RenderContext.h"

/*------------------------- Set Methods -----------------------------*/
void Scene::set_ambient(Color ambient){ this->ambient = ambient; }

void Scene::set_background(Background* background){ this->background = background; }

void Scene::set_camera(Camera* camera){ this->camera = camera; }

void Scene::set_image(Image* image){ this->image = image; }

void Scene::set_object(Object* object){ this->object = object; }

void Scene::add_light(Light* light){ lights.push_back(light); }

/*------------------------- Get Methods ---------------------------*/
Light* Scene::get_light(int index){ return lights[index]; }

int Scene::num_lights(){ return lights.size(); }

Color Scene::get_ambient()const{ return ambient; }

Object* Scene::get_object(){ return object; }

Camera* Scene::get_camera(){ return camera; }


/*------------------------- Other Methods -----------------------*/
void Scene::preprocess(){
   background->preprocess();
   camera->preprocess(image->aspect());
   object->preprocess();
   for(int i=0; i<lights.size(); i++)
      lights[i]->preprocess();
}

void Scene::render(){
   int resx = image->get_xres();
   int resy = image->get_yres();
   float step = 2.f/(float)resx;
   float xstart = -1.f + 0.5f*step;
   float ystart = -(float)resy*0.5f*step + 0.5f*step;
   for(int i=0; i<resx; i++){
      for(int j=0; j<resy; j++){
         Ray r;
         RenderContext rc(this);
         HitRecord hr;
         camera->generateRay(r, rc, xstart+i*step, ystart+j*step);
         traceRay(r, hr, rc);
         Color c;
         if(hr.GetT()==std::numeric_limits<float>::infinity() || hr.GetMaterial()==NULL || hr.GetPrimitive() == NULL){
            c = background->getColor(rc, r);
         }
         else{
            c = hr.GetMaterial()->shade(rc, r, hr, 1);
         }		
         image->set(i,j,c);
      }
   }
}

void Scene::traceRay(const Ray& ray, HitRecord& hr, RenderContext& rc)const{
   object->intersect(hr, rc, ray);
}
