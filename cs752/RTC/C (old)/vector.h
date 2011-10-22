


#ifndef vector_h
#define vector_h



typedef struct tVector{
   float x;
   float y;
   float z;
} Vector;

extern void vector_init(&Vector);
extern void vector_init(&Vector v, float x, float y, float z);

extern float vector_length(const Vector &v);
extern float vector_length2(const Vector &v);

extern Vector vector_add(const Vector &v1, const Vector &v2);
extern void vector_add(Vector &result, const Vector &v1, const Vector &v2);
extern void vector_add(Vector &v1, const Vector &v2);

extern void vector_scalar(Vector &v, float d);
extern Vector vector_scalar(const Vector &v, float d);

extern Vector vector_normal(const Vector &v);
extern float vector_normalize(Vector &v);

extern float vector_dot(const Vector &v1, const Vector &v2);

extern void vector_cross(Vector &result, const Vector &v1, const Vector &v2);
extern Vector vector_cross(const Vector &v1, const Vector &v2);


#endif
