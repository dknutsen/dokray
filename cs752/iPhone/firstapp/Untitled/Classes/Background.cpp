

#include "Background.h"

ConstantBackground::ConstantBackground(Color color):color(color) {}

void ConstantBackground::preprocess(){ }

Color ConstantBackground::getColor(const RenderContext& rc, const Ray& ray)const{
	return color;
}