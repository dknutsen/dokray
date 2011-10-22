/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

#include "Light.h"

#include <limits>

#include "Color.h"
#include "Point.h"
#include "RenderContext.h"
#include "Vector.h"

namespace RT {

   PointLight::PointLight( Point p, Color color )
      : p( p ), color( color ) { }

   void PointLight::preprocess() { }

   float PointLight::getLight( Color &lcolor, Vector &ldir, const RenderContext &rc, const Point &hp ) const {

      lcolor = this->color;
      ldir = this->p - hp;
      return ldir.normalize();

   }

   DirectionalLight::DirectionalLight( Vector dir, Color color ) 
      : dir( dir ), color( color) {}

   void DirectionalLight::preprocess() { this->dir.normalize(); }

   float DirectionalLight::getLight(Color& lcolor, Vector& ldir, const RenderContext& rc, const Point& hp) const {

      lcolor = this->color;
      ldir = -this->dir;
      return std::numeric_limits<float>::infinity();

   }

} // namespace RT