

#include "Light.h"
#include <limits>

PointLight::PointLight(Point p, Color color):p(p),color(color) {}
void PointLight::preprocess(){}
float PointLight::getLight(Color &lcolor, Vector &ldir, const RenderContext &rc, const Point &hp) const{
	lcolor = color;
	ldir = p-hp;
	return ldir.normalize();
}


DirectionalLight::DirectionalLight(Vector dir, Color color):dir(dir),color(color) {}
void DirectionalLight::preprocess(){dir.normalize();}
float DirectionalLight::getLight(Color& lcolor, Vector& ldir, const RenderContext& rc, const Point& hp) const{
	lcolor = color;
	ldir = -dir;
	return std::numeric_limits<float>::infinity();
}
