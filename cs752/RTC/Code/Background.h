/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

#ifndef RT_BACKGROUND_H
#define RT_BACKGROUND_H

#include "Color.h"

namespace RT {

   class Ray;
   class RenderContext;

   class Background {
   public:

	   virtual void preprocess() = 0;
	   virtual Color getColor( const RenderContext& rc, const Ray& ray ) const = 0;

   };

   class ConstantBackground : public Background {
   private:

	   Color color;

   public:

	   ConstantBackground( Color color );
	   void preprocess();
	   Color getColor( const RenderContext& rc, const Ray& ray ) const;

   };

} // namespace RT

#endif // RT_BACKGROUND_H