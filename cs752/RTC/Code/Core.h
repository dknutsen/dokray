/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

#ifndef RT_CORE_H
#define RT_CORE_H

#include "Scene.h"

namespace RT {

   class Color;

   class Core {
   protected:

      Scene* scene;

   public:

      Core() { }
      Core( Scene* scene ) : scene( scene ) { }

      ~Core() { }

      void setScene( Scene* scene );

      Color renderPixel( int x, int y );

   };

} // namepsace RT

#endif // CORE_H