

#include "Camera.h"



RPoint PinholeCamera::getEye(){
	return eye;
}

PinholeCamera::PinholeCamera(RPoint eye, RPoint lat, Vector up, float fov)
	: eye(eye), lat(lat), up(up), fov(fov) { }

void PinholeCamera::preprocess(float aspect){
	L = (lat - eye).normal();
	Vector Ut = cross(L, up);
	Vector Vt = cross(Ut, L);
			
	//Vector U = (tan(deg2rad*fov*0.5f)) * Ut.normal();
	//Vector V = ((1/aspect)*tan(deg2rad*fov*0.5f)) * Vt.normal();
	U = Ut.normal();
	U = U * tan(deg2rad*fov*0.5f);
	V = Vt.normal();
	V = V * ((1/aspect)*tan(deg2rad*fov*0.5f));
}

void PinholeCamera::generateRay(Ray& ray, const RenderContext& rc, float x, float y)const{
	ray = Ray(eye, (L + x*U + y*V).normal());
}
