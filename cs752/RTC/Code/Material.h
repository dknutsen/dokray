/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

#ifndef RT_MATERIAL_H
#define RT_MATERIAL_H

#include "Color.h"

namespace RT {

   class HitRecord;
   class Ray;
   class RenderContext;

   class Material {
   public:

      virtual void preprocess() = 0;
      virtual Color shade( const RenderContext& rc, const Ray& ray, const HitRecord& hrec, int depth ) const = 0;
   
   };

   class LambertianMaterial : public Material {
   private:

      float kd, ka;
      Color color;
   
   public:

      LambertianMaterial( Color color, float kd, float ka );
      void preprocess();
      Color shade( const RenderContext& rc, const Ray& ray, const HitRecord& hrec, int depth ) const;

   };

   class PhongMaterial : public Material {
   private:
   
      float kd, ka, ks, ke;
      float n;
      Color color;
   
   public:
   
      PhongMaterial( Color color, float ke, float kd, float ka, float ks, float shininess );
      void preprocess();
      Color shade( const RenderContext& rc, const Ray& ray, const HitRecord& hrec, int depth ) const;
   
   };

} // namespace RT

#endif // RT_MATERIAL_H