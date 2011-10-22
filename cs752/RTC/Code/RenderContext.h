/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

#ifndef RT_RENDERCONTEXT_H
#define RT_RENDERCONTEXT_H

namespace RT {

   class Scene;

   class RenderContext {
   private:

      Scene* scene;

   public:

      RenderContext( Scene* scene ) { this->scene = scene; }
      const Scene* getScene() const { return this->scene; }

   };

} // namespace RT

#endif // RENDERCONTEXT_H