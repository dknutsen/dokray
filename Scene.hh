#ifndef Scene_h
#define Scene_h

#include "Color.h"

#include <vector>
using std::vector;

class Background;
class Camera;
class Image;
class Object;
class Light;
class Ray;
class RenderContext;
class HitRecord;


class Scene{
private:
   Color ambient;
   Background* background;
   Camera* camera;
   Image* image;
   Object* object;
   vector<Light*> lights;
   //vector<Object*> objects;

   void traceRay(const Ray& ray, HitRecord& hr, RenderContext& rc)const;

public:
   /*------------------- Set Methods -----------------*/
   void set_ambient(Color ambient);

   void set_background(Background* background);

   void set_camera(Camera* camera);

   void set_image(Image* image);

   void set_object(Object* object);

   void add_light(Light* light);

   /*------------------ Get Methods ------------------*/
   Light* get_light(int index);

   int num_lights();

   Color get_ambient()const;

   Object* get_object();

   Camera* get_camera();

   /*---------------- Other Methods ----------------*/
   void preprocess();

   void render();
};

#endif
