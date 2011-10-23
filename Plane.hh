#ifndef Plane_hh
#define Plane_hh

#include "Primitive.hh"
#include "Vector.hh"
#include "Point.hh"

class HitRecord;
class RenderContext;
class Ray;

class Plane : public Primitive{
private:
   Material* material;
   Vector normal;
   Point point;

public:
   Plane(Material* material, Vector normal, Point point);

   void Preprocess();

   Vector Normal(const Point& point)const;

   void Intersect(HitRecord& hit, const RenderContext& rc, const Ray& ray)const;
};

#endif
