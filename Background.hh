#ifndef Background_hh
#define Background_hh

#include "RenderContext.h"
#include "Ray.h"
#include "Color.h"

class Background
{
public:
   virtual void preprocess() = 0;

   virtual Color getColor(const RenderContext& rc, const Ray& ray) const = 0;
};

class BackgroundConstant : public Background
{
private:
   Color color;

public:
   BackgroundConstant(Color color);

   void preprocess();

   Color getColor(const RenderContext& rc, const Ray& ray)const;
};


/*
class BackgroundImage(imagestuff){

}
*/
#endif
