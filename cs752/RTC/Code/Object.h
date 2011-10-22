/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

#ifndef RT_OBJECT_H
#define RT_OBJECT_H

#include <vector>

namespace RT {

   class HitRecord;
   class Ray;
   class RenderContext;

   class Object {
   public:

      virtual void preprocess() = 0;
      virtual void intersect( HitRecord& hit, const RenderContext& rc, const Ray& ray ) const = 0;

   };

   class Group : public Object {
   private:

      std::vector<Object*> objects;

   public:

      void preprocess();
      void intersect( HitRecord& hit, const RenderContext& rc, const Ray& ray ) const;
      void addObject( Object* object );

   };

} // namespace RT

#endif // RT_OBJECT_H