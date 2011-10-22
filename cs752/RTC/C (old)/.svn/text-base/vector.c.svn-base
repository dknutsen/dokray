/*

*/

#include <vector.h>


void vector_init(Vector &v){
   v.x = v.y = v.z = 0.0f;
}

void vector_init(Vector &v, float x, float y, float z){
   v.x = x;
   v.y = y;
   v.z = z;
}

float vector_length(const Vector &v){
   return sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
}

float vector_length2(const Vector &v){
   return v.x*v.x+v.y*v.y+v.z*v.z;
}

Vector vector_add(const Vector &v1, const Vector &v2){
   Vector v;
   vector_init(v, v1.x+v2.x, v1.y+v2.y, v1.z+v2.z);
   return v;
}

void vector_add(Vector &result, const Vector &v1, const Vector &v2){
   vector_init(result, v1.x+v2.x, v1.y+v2.y, v1.z+v2.z);
}

void vector_add(Vector &v1, const Vector &v2){
   v1.x = v1.x+v2.x;
   v1.y = v1.y+v2.y;
   v1.z = v1.z+v2.z;
}

void vector_scalar(Vector &v, float d){
   v.x = v.x * d;
   v.y = v.y * d;
   v.z = v.z * d;
}

Vector vector_scalar(const Vector &v, float d){
   Vector result;
   vector_scalar(v,d);
   return result;
}

Vector vector_normal(const Vector &v){
   float div = 1 / vector_length(v);
   Vector result;
   vector_init(result, v.x*div, v.y*div, v.z*div);
   return result;   
}

float vector_normalize(Vector &v){
   float div = 1.f / vector_length(v);
   vector_init(v, v.x*div, v.y*div, v.z*div);
}

Vector vector_add(const Vector &v1, const Vector &v2){
   Vector v;
   vector_add(v,v1,v2);
   return v;
}

void vector_add(Vector &result, const Vector &v1, const Vector &v2){
   result.x = v1.x+v2.x;  result.y = v1.y+v2.y;  result.z = v1.z+v2.z;
}

void vector_add(Vector &v1, const Vector &v2){
   v1.x = v1.x+v2.x;  v1.y = v1.y+v2.y;  v1.z = v1.z+v2.z;
}

float vector_dot(const Vector &v1, const Vector &v2){
   return v1.x*v2.x+v1.y*v2.y+v1.z*v2.z;
}

void vector_cross(Vector &result, const Vector &v1, const Vector &v2){
   result.x = v1.y*v2.z - v1.z*v2.y;
   result.y = v1.z*v2.x - v1.x*v2.z;
   result.z = v1.x*v2.y - v1.y*v2.x;
}

Vector vector_cross(const Vector &v1, const Vector &v2){
   vector v;
   vector_cross(v,v1,v2);
   return v;
}
