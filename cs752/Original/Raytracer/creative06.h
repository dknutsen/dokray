
// NOTE(cpg) - you may need to modify this code if your interfaces
//             differ from those discussed in class

#ifndef rt361_creative06_h
#define rt361_creative06_h

#include "Point.h"
#include "Vector.h"
#include "Scene.h"
#include "Object.h"
#include "Sphere.h"
#include "Plane.h"
#include "Background.h"
#include "Light.h"
#include "Camera.h"

Scene* make_scene()
{
  const float kd = 0.6f;
  const float ka = 0.4f;

  Scene* scene = new Scene();

  Group* world = new Group();

  int maxr = 15;

  for(int i=0; i<600; i++){
	  float x = (float)(rand()%(maxr*1000))/1000.f;
	  float y = (float)(rand()%(maxr*1000))/1000.f;
	  float z = (float)(rand()%(maxr*1000))/3000.f;
	  world->add_object(new Sphere(
		  //new PhongMaterial(Color(0.1f, 0.3f, 1.0f), 0.0f, 1.0f, ka, 2.0f, 10.f),
		  new LambertianMaterial(Color(0.4f, 0.9f, 0.3f), kd, ka),
		  Point(-(float)maxr*0.5f+x,-(float)maxr*0.5f+y,z), 
		  0.3f));
  }
  /*world->add_object(new Sphere(
	  new LambertianMaterial(Color(0.1f, 0.6f, 0.9f), .9f, ka),
	  Point(-2.f, -2.f, 2.5f),
	  1.3f));	  
  world->add_object(new Sphere(
	  new PhongMaterial(Color(0.1f, 0.6f, 0.9f), 0.0f, 0.5f, ka, 0.5f, 20.f),
	  Point(0.f, 0.f, 2.5f),
	  1.3f));
  world->add_object(new Sphere(
	  new PhongMaterial(Color(0.1f, 0.6f, 0.9f), 0.0f, 2.f, ka, 2.f, 20.f),
	  Point(2.f, 2.f, 2.5f),
	  1.3f));
  world->add_object(new Sphere(
	  new PhongMaterial(Color(0.1f, 0.3f, 1.0f), 0.0f, 1.0f, ka, 2.0f, 70.f),
	  Point(0.f, 0.f, 5.5f),
	  1.3f));*/
  world->add_object(new Plane(new LambertianMaterial(Color(0.8f, 0.8f, 0.8f),
                                                     kd, ka),
                              Vector(0.f, 0.f, 1.f), Point(0.f, 0.f, -0.1f)));
						

  scene->set_object(world);

  scene->set_background(new ConstantBackground(Color(0.0f, 0.0f, 0.0f)));
  scene->set_ambient(Color(ka, ka, ka));
  scene->add_light(new PointLight(Point(20.f, -30.f, 100.f),
                                 Color(0.9f, 0.9f, 0.9f)));
  //scene->add_light(new PointLight(Point(40.f, 40.f, 200.f),
  //                               Color(0.6f, 0.6f, 0.6f)));
  //scene->add_light(new DirectionalLight(Vector(1,1,-1), Color(0.9f, 0.9f,0.9f)));

  scene->set_camera(new PinholeCamera(Point(12.f, -12.f, 7.f),
                                      Point(1.f, 1.f, 2.f),
                                      Vector(0.f, 0.f, 1.f),
                                      60.f));

  return scene;
}

#endif // rt361_req06_h
