#ifndef RenderContext_h
#define RenderContext_h


class Scene;

class RenderContext
{
private:
   Scene* scene;
public:
   RenderContext(Scene* scene) {this->scene = scene;}
   const Scene* getScene() const{return scene;}
};

#endif
