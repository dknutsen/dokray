#ifndef SceneCreator_hh
#define SceneCreator_hh

#include "Point.hh"
#include "Vector.hh"
#include "Scene.hh"
#include "Object.hh"
#include "Sphere.hh"
#include "Plane.hh"
#include "Background.hh"
#include "Light.hh"
#include "Camera.hh"

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
          world->AddObject(new Sphere(
                  //new PhongMaterial(Color(0.1f, 0.3f, 1.0f), 0.0f, 1.0f, ka, 2.0f, 10.f),
                  new LambertianMaterial(Color(0.4f, 0.9f, 0.3f), kd, ka),
                  Point(-(float)maxr*0.5f+x,-(float)maxr*0.5f+y,z),
                  0.3f));
  }


  world->AddObject(new Plane(new LambertianMaterial(Color(0.8f, 0.8f, 0.8f),
                                                     kd, ka),
                              Vector(0.f, 0.f, 1.f), Point(0.f, 0.f, -0.1f)));


  scene->SetObject(world);

  scene->SetBackground(new BackgroundConstant(Color(0.0f, 0.0f, 0.0f)));
  scene->SetAmbient(Color(ka, ka, ka));
  scene->AddLight(new PointLight(Point(20.f, -30.f, 100.f),
                                 Color(0.9f, 0.9f, 0.9f)));
  //scene->add_light(new PointLight(Point(40.f, 40.f, 200.f),
  //                               Color(0.6f, 0.6f, 0.6f)));
  //scene->add_light(new DirectionalLight(Vector(1,1,-1), Color(0.9f, 0.9f,0.9f)));

  scene->SetCamera(new PinholeCamera(Point(12.f, -12.f, 7.f),
                                      Point(1.f, 1.f, 2.f),
                                      Vector(0.f, 0.f, 1.f),
                                      60.f));

  return scene;
}


#endif
