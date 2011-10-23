#ifndef Background_hh
#define Background_hh

#include "RenderContext.hh"
#include "Ray.hh"
#include "Color.hh"

class Background
{
public:
   virtual void Preprocess() = 0;

   virtual Color GetColor(const RenderContext& rc, const Ray& ray) const = 0;
};

class BackgroundConstant : public Background
{
private:
   Color color;

public:
   BackgroundConstant(Color color);

   void Preprocess();

   Color GetColor(const RenderContext& rc, const Ray& ray)const;
};


/*
class BackgroundImage(imagestuff){

}
*/
#endif
