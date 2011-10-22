
/* Decided we should keep as floats, if we need int rgb values, multiply in the OS specific client */

#ifndef color_h
#define color_h




typedef struct tColor{
   float r;
   float g;
   float b;
} Color;




extern void color_init(&Color c);
extern void color_init(&Color c, float x, float y, float z);

extern Color color_add(const Color &c1, const Color &c2);
extern void color_add(Color &result, const Color &c1, const Color &c2);
extern void color_add(Color &c1, const Color &c2);

extern void color_scalar(Color &c, float d);
extern Color color_scalar(const Color &c, float d);


#endif
