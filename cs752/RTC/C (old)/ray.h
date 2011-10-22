
#ifndef ray_h
#define ray_h

#include <vector.h>

typedef struct tRay{
   Vector p;
   Vector dir;
} Ray;

extern void ray_init(Ray &r);
extern void ray_init(Ray &r, const Vector &p, const Vector &dir);
extern void ray_init(Ray &r, float x, float y, float z, float u, float v, float w);

extern void ray_pointon(Vector &result, const Ray &r, float t);
extern Vector ray_pointon(const Ray &r, float t);


#endif
