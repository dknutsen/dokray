/*
    Author: dok
    Desc:   Hit Record, contains information about ray/object intersections
 */


#ifndef HitRecord_hh
#define HitRecord_hh

#include "Primitive.hh"
#include "Material.hh"
#include <limits>


// big awesome comment here
class HitRecord{
private:
   float t;
   Primitive* primitive;
   Material* material;

public:
   /*----------------- Constructors ------------*/
   HitRecord(){
      t = std::numeric_limits<float>::infinity();
      primitive = NULL;
      material = NULL;
   }

   /*------------------- Accessors -------------*/
   float GetT(){ return t; }

   Primitive* GetPrimitive(){ return primitive; }

   Material* GetMaterial(){ return material; }

   /*------------------- Hit Record Functions ---------*/
   bool Hit(float t, const Primitive* hit_primitive, const Material* hit_material){
      if(this->t > t){
         this->t = t;
         this->primitive = (Primitive*)hit_primitive;
         this->material = (Material*)hit_material;
         return true;
      }
      return false;
   }
};


#endif
