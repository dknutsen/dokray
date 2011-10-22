/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

#ifndef RT_SCENE_H
#define RT_SCENE_H

#include <vector>

#include "Color.h"

namespace RT {

   class Background;
   class Camera;
   class HitRecord;
   class Image;
   class Light;
   class Object;
   class Ray;
   class RenderContext;

   class Scene {
   private:

      int xResolution;
      int yResolution;

      Camera* camera;
      Image* image;
      Color ambient;
      Background* background;
      Object* object;
      std::vector<Light*> lights;

   public:

      //vector<Object*> objects;

      void traceRay( const Ray& ray, HitRecord& hr, RenderContext& rc ) const;

      void setAmbient( Color ambient );
      void setBackground( Background* background );
      void setCamera( Camera* camera );
      void setImage( Image* image );
      void setObject( Object* object );
      void addLight( Light* light );
      void setResolution( int x, int y ) { this->xResolution = x; this->yResolution = y; }

      Light* getLight( int index );
      Background* getBackground();
      int numberOfLights();
      Color getAmbient() const;
      Object* getObject();
      Camera* getCamera();
      float getAspect() const { return static_cast<float>( this->xResolution / this->yResolution ); }
      int getXResolution() { return xResolution; }
      int getYResolution() { return yResolution; }

      void preprocess();

   };

} // namespace RT

#endif // SCENE_H