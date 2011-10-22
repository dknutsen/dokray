

#include "Background.h"

BackgroundConstant::BackgroundConstant(Color color):color(color) {

}

void BackgroundConstant::preprocess(){ 

}

Color BackgroundConstant::getColor(const RenderContext& rc, const Ray& ray)const{
   return color;
}





/*   BackgroundImage
 *
 *
 * /
