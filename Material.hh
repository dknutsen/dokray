/*
    Author: dok
    Desc:   Contains definitions for a few basic materials
 */


#ifndef Material_hh
#define Material_hh

#include "Color.h"

class RenderContext;
class Ray;
class HitRecord;

// Big awesome comment here
class Material{
private:

public:
   virtual void preprocess() = 0;

   virtual Color shade(const RenderContext& rc, const Ray& ray, const HitRecord& hrec, int depth) const=0;
};


// Big awesome comment here
class LambertianMaterial : public Material{
private:
   float kd, ka;
   Color color;

public:
   LambertianMaterial(Color color, float kd, float ka);

   void preprocess();

   Color shade(const RenderContext& rc, const Ray& ray, const HitRecord& hrec, int depth) const;
};


// big awesome comment here
class PhongMaterial : public Material{
private:
   float kd, ka, ks, ke;
   float n;
   Color color;

public:
   PhongMaterial(Color color, float ke, float kd, float ka, float ks, float shininess);

   void preprocess();

   Color shade(const RenderContext& rc, const Ray& ray, const HitRecord& hrec, int depth) const;
};

#endif
