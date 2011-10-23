#ifndef Camera_hh
#define Camera_hh

#include "Vector.hh"
#include "Point.hh"
#include "Ray.hh"

class RenderContext;


class Camera
{
public:
   virtual void Preprocess(float aspect) = 0;

   virtual void GenerateRay(Ray& ray, const RenderContext& rc, float x, float y)const = 0;

   virtual Point GetEye()=0;
};


class PinholeCamera : public Camera
{
private:
   Point eye;
   Point lat;
   Vector up;
   float fov;

   Vector U, V, L;

public:
   PinholeCamera(Point eye, Point lat, Vector up, float fov);

   virtual Point GetEye();

   virtual void Preprocess(float aspect);
	
   virtual void GenerateRay(Ray& ray, const RenderContext& rc, float x, float y)const;

   // wtf is this?
   /*Ray rays[xres*yres];
      float step = 2.f/(float)resx;
      float xstart = -1.f + 0.5*step;
      float ystart = -(float)resy*0.5 + 0.5*step;
      for(int i=0; i<resx; i++){
         for(int j=0; j<resy; j++){
            rays[i+j*resx] = Ray(Point(eye), 
               (L + (xstart+i*step)*U + (ystart*j+step)*V).normal());
         }
      }*/
};

// Fisheye camera?
#endif
