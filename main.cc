
#include <iostream>
using std::cout;
using std::endl;

#include "Timer.hh"
using simdrt::Timer;

#include "Image.hh"
#include "Scene.hh"
#include "SceneCreator.hh"

int main()
{
  const unsigned int xres = 200;
  const unsigned int yres = 200;
  Image image(xres, yres);

  Scene* scene = make_scene();
  scene->SetImage(&image);
  scene->Preprocess();

  Timer timer;
  scene->Render();

  cout << "Rendered " << xres << 'x' << yres << " pixel image in "
       << timer.getElapsed() << " seconds" << endl;

  image.WriteBMP("output.bmp");

  cout << std::flush;

  return 0;
}
