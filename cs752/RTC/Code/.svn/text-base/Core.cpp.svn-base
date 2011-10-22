/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

#include "Core.h"

#include "Background.h"
#include "Camera.h"
#include "Color.h"
#include "HitRecord.h"
#include "Image.h"
#include "Ray.h"
#include "RenderContext.h"
#include "Scene.h"

namespace RT {

   void Core::setScene( Scene* scene ) {
      this->scene = scene;
   }

   Color Core::renderPixel( int x, int y ) {

      Color color;
      HitRecord hitRecord;
      Ray ray;
      RenderContext renderContext( this->scene );

      float step = 2.f / (float)this->scene->getXResolution();
      float xStart = -1.f + ( 0.5f * step );
      float yStart = (-(float)this->scene->getYResolution() * (0.5f * step)) + (0.5f * step);

      ray = this->scene->getCamera()->generateRay( xStart + (x * step), yStart + (y * step) );
      this->scene->traceRay( ray, hitRecord, renderContext );

      if ( hitRecord.getT() == std::numeric_limits<float>::infinity() || hitRecord.getMaterial() == NULL || hitRecord.getPrimitive() == NULL ) {

         color = this->scene->getBackground()->getColor( renderContext, ray );

      } else {

         color = hitRecord.getMaterial()->shade( renderContext, ray, hitRecord, 1 );

      }

      return color;

   }

}