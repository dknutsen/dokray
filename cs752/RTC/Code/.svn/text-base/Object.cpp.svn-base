/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

#include "Object.h"

#include "HitRecord.h"
#include "Ray.h"
#include "RenderContext.h"

namespace RT {

   void Group::preprocess() {
      for( int i = 0; i < (int)objects.size(); i++ )
         objects[i]->preprocess();
   }

   void Group::intersect( HitRecord& hit, const RenderContext& rc, const Ray& ray ) const {
      for( int i = 0; i < (int)objects.size(); i++ )
         objects[i]->intersect( hit, rc, ray );
   }

   void Group::addObject( Object* object ) {
      objects.push_back( object );
   }

} // namespace RT