

#include "Background.hh"

BackgroundConstant::BackgroundConstant(Color color):color(color) {

}

void BackgroundConstant::Preprocess(){ 

}

Color BackgroundConstant::GetColor(const RenderContext& rc, const Ray& ray)const{
   return color;
}





/*   BackgroundImage
 *
 *
 */
