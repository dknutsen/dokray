/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

#include "Background.h"

#include "Color.h"

namespace RT {

   ConstantBackground::ConstantBackground( Color color ) 
      : color( color ) { }

   void ConstantBackground::preprocess() { }

   Color ConstantBackground::getColor( const RenderContext& rc, const Ray& ray ) const {
      return this->color;
   }

} // namespace RT