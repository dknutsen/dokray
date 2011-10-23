
#include "Camera.hh"
#include "Global.hh"


Point PinholeCamera::GetEye(){
   return eye;
}

PinholeCamera::PinholeCamera(Point eye, Point lat, Vector up, float fov)
   : eye(eye), lat(lat), up(up), fov(fov) { }

void PinholeCamera::Preprocess(float aspect){
   L = (lat - eye).Normal();
   Vector Ut = Cross(L, up);
   Vector Vt = Cross(Ut, L);
			
   //Vector U = (tan(deg2rad*fov*0.5f)) * Ut.normal();
   //Vector V = ((1/aspect)*tan(deg2rad*fov*0.5f)) * Vt.normal();
   U = Ut.Normal();
   U = U * tan(deg2rad*fov*0.5f);
   V = Vt.Normal();
   V = V * ((1/aspect)*tan(deg2rad*fov*0.5f));
}

void PinholeCamera::GenerateRay(Ray& ray, const RenderContext& rc, float x, float y)const{
   ray = Ray(eye, (L + x*U + y*V).Normal());
}

