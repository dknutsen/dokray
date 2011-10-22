
#include <ray.h>

void ray_init(Ray &r){
   r.p.x = r.p.y = r.p.z = 0;
   r.dir.x = r.dir.y = r.dir.z = 0;
}

void ray_init(Ray &r, const Vector &p, const Vector &dir){
   r.p = p;
   r.dir = dir;
}

void ray_init(Ray &r, float x, float y, float z, float u, float v, float w){
   r.p.x = x;  r.p.y = y;  r.p.z = z;
   r.dir.x = u;  r.dir.y = v; r.dir.z = w;
}

void ray_pointon(Vector &result, const Ray &r, float t){
   vector_add(result, vector_scalar(dir, t), p);
}

Vector ray_pointon(const Ray &r, float t){
   vector v;
   ray_pointon(v, r, t);
   return v;
}
