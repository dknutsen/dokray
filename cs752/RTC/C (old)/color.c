

void color_init(&Color c){
   c.r = c.g = c.b = 0.f;
}

void color_init(&Color c, float r, float g, float b){
   c.r = r;  c.g = g;  c.b = b;
}

Color color_add(const Color &c1, const Color &c2){
   Color c;
   color_add(c,c1,c2);
   return c;
}

void color_add(Color &result, const Color &c1, const Color &c2){
   result.r = c1.r+c2.r;  result.g = c1.g+c2.g;  result.b = c1.b+c2.b;
}

void color_add(Color &c1, const Color &c2){
   c1.r = c1.r+c2.r;  c1.g = c1.g+c2.g;  c1.b = c1.b+c2.b;
}

void color_scalar(Color &c, float d){
   c.r = c.r*d;  c.g = c.g*d;  c.b = c.b*d;
}

Color color_scalar(const Color &c, float d){
   Color result;
   color_scalar(result, d);
   return result;
}







