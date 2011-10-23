#ifndef RenderContext_hh
#define RenderContext_hh


class Scene;

class RenderContext
{
private:
   Scene* scene;
public:
   RenderContext(Scene* scene) {this->scene = scene;}
   const Scene* GetScene() const{return scene;}
};

#endif
