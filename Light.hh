#ifndef Light_hh
#define Light_hh

#include "Color.hh"
#include "Vector.hh"
#include "RenderContext.hh"
#include "Point.hh"

class Light{
private:

public:
   virtual void Preprocess() = 0;

   virtual float GetLight(Color& lcolor, Vector& ldir, const RenderContext& rc, const Point& hp) const=0;
};


class PointLight : public Light{
private:
   Point p;
   Color color;

public:
   PointLight(Point p, Color color);

   void Preprocess();

   float GetLight(Color& lcolor, Vector& ldir, const RenderContext& rc, const Point& hp) const;
};


class DirectionalLight : public Light{
private:
   Vector dir;
   Color color;

public:
   DirectionalLight(Vector dir, Color color);

   void Preprocess();

   float GetLight(Color& lcolor, Vector& ldir, const RenderContext& rc, const Point& hp) const;
};

#endif
