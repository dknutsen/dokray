#ifndef Camera_h
#define Camera_h

#include "Vector.h"
#include "Point.h"
#include "Ray.h"

class RenderContext;
#define deg2rad 0.0174532925f


class Camera
{
public:
	virtual void preprocess(float aspect) = 0;
	virtual void generateRay(Ray& ray, const RenderContext& rc, float x, float y)const = 0;
	virtual RPoint getEye()=0;
};


class PinholeCamera : public Camera
{
private:
	RPoint eye;
	RPoint lat;
	Vector up;
	float fov;

	Vector U, V, L;

public:
	PinholeCamera(RPoint eye, RPoint lat, Vector up, float fov);
	
	virtual RPoint getEye();

	virtual void preprocess(float aspect);
	
	virtual void generateRay(Ray& ray, const RenderContext& rc, float x, float y)const;

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
#endif