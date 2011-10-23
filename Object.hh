/*
    Author: dok
    Desc:   Base object class
 
 */

#ifndef Object_hh
#define Object_hh

#include <vector>
using std::vector;

class HitRecord;
class RenderContext;
class Ray;

class Object{
private:

public:
   virtual void Preprocess() = 0;

   virtual void Intersect(HitRecord& hit, const RenderContext& rc, const Ray& ray) const=0;
};


class Group : public Object{
private:
   vector<Object*> objects;
public:
   void Preprocess();

   void Intersect(HitRecord& hit, const RenderContext& rc, const Ray& ray) const;

   void AddObject(Object* object);
};

#endif
