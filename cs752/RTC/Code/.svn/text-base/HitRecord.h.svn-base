/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

#ifndef RT_HITRECORD_H
#define RT_HITRECORD_H

#include <limits>

#include "Material.h"
#include "Primitive.h"

namespace RT {

   class HitRecord {
   private:

      float t;
      Primitive* primitive;
      Material* material;

   public:

      HitRecord() {
         this->t = std::numeric_limits<float>::infinity();
         this->primitive = NULL;
         this->material = NULL;
      }

      float getT() { return this->t; }
      Primitive* getPrimitive() { return this->primitive; }
      Material* getMaterial() { return this->material; }

      bool hit( float t, const Primitive* hitPrimitive, const Material* hitMaterial ) {
         
         if ( this->t > t ) {
         
            this->t = t;
            this->primitive = (Primitive*)hitPrimitive;
            this->material = (Material*)hitMaterial;
            return true;
         
         }
         
         return false;
      
      }

   };

} // namespace RT

#endif // RT_HITRECORD_H