/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

#include "Scene.h"

#include "Background.h"
#include "Camera.h"
#include "Color.h"
#include "HitRecord.h"
#include "Image.h"
#include "Light.h"
#include "Ray.h"
#include "RenderContext.h"

namespace RT {

   void Scene::setAmbient( Color ambient ){ this->ambient = ambient; }
   void Scene::setBackground( Background* background ){ this->background = background; }
   void Scene::setCamera( Camera* camera ){ this->camera = camera; }
   void Scene::setImage( Image* image ){ this->image = image; }
   void Scene::setObject( Object* object ){ this->object = object; }
   void Scene::addLight( Light* light ){ this->lights.push_back( light ); }

   Light* Scene::getLight( int index ) { return this->lights[index]; }
   int Scene::numberOfLights() { return (int)this->lights.size(); }
   Color Scene::getAmbient() const { return this->ambient; }
   Object* Scene::getObject() { return this->object; }
   Camera* Scene::getCamera() { return this->camera; }
   Background* Scene::getBackground() { return this->background; }

   void Scene::preprocess(){

      this->background->preprocess();
      this->camera->preprocess( this->getAspect() );
      this->object->preprocess();
      
      for ( int i = 0; i < (int)lights.size(); i++ )
         this->lights[i]->preprocess();

   }

   void Scene::traceRay( const Ray& ray, HitRecord& hr, RenderContext& rc ) const {
      this->object->intersect( hr, rc, ray );
   }

} // namespace RT