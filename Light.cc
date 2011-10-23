

#include "Light.hh"
#include <limits>

/*------------------- Point Light ----------------*/
PointLight::PointLight(Point p, Color color):p(p),color(color) {}

void PointLight::Preprocess(){}

float PointLight::GetLight(Color &lcolor, Vector &ldir, const RenderContext &rc, const Point &hp) const{
   lcolor = color;
   ldir = p-hp;
   return ldir.Normalize();
}


/*------------------ Directional Light -------------*/
DirectionalLight::DirectionalLight(Vector dir, Color color):dir(dir),color(color) {}

void DirectionalLight::Preprocess(){ dir.Normalize(); }

float DirectionalLight::GetLight(Color& lcolor, Vector& ldir, const RenderContext& rc, const Point& hp) const{
   lcolor = color;
   ldir = -dir;
   return std::numeric_limits<float>::infinity();
}
