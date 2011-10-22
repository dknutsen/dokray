/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

#ifndef RT_LIGHT_H
#define RT_LIGHT_H

#include "Color.h"
#include "Point.h"
#include "Vector.h"

namespace RT {

   class RenderContext;

   class Light {
   private:

   public:

      virtual void preprocess() = 0;
      virtual float getLight( Color& lcolor, Vector& ldir, const RenderContext& rc, const Point& hp ) const = 0;
   
   };

   class PointLight : public Light {
   private:

      Point p;
      Color color;
   
   public:

      PointLight( Point p, Color color );
      void preprocess();
      float getLight( Color& lcolor, Vector& ldir, const RenderContext& rc, const Point& hp ) const;
   
   };

   class DirectionalLight : public Light {
   private:

      Vector dir;
      Color color;
   
   public:
   
      DirectionalLight( Vector dir, Color color );
      void preprocess();
      float getLight( Color& lcolor, Vector& ldir, const RenderContext& rc, const Point& hp ) const;

   };

} // namespace RT

#endif // RT_LIGHT_H