#ifndef Scene_hh
#define Scene_hh

#include "Color.hh"

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

   void TraceRay(const Ray& ray, HitRecord& hr, RenderContext& rc)const;

public:
   /*------------------- Set Methods -----------------*/
   void SetAmbient(Color ambient);

   void SetBackground(Background* background);

   void SetCamera(Camera* camera);

   void SetImage(Image* image);

   void SetObject(Object* object);

   void AddLight(Light* light);

   /*------------------ Get Methods ------------------*/
   Light* GetLight(int index);

   int NumLights();

   Color GetAmbient()const;

   Object* GetObject();

   Camera* GetCamera();

   /*---------------- Other Methods ----------------*/
   void Preprocess();

   void Render();
};

#endif
