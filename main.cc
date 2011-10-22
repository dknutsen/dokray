
#include <iostream>
using std::cout;
using std::endl;

#include "Timer.h"
using simdrt::Timer;

#include "Image.h"

int main()
{
  const unsigned int xres = 1024;
  const unsigned int yres = 1024;
  Image image(xres, yres);

  Scene* scene = make_scene();
  scene->set_image(&image);
  scene->preprocess();

  Timer timer;
  scene->render();

  cout << "Rendered " << xres << 'x' << yres << " pixel image in "
       << timer.getElapsed() << " seconds" << endl;

  image.writeBMP("output.bmp");

  cout << std::flush;

  return 0;
}
