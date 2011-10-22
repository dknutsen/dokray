/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

#include <iostream>

#include "Background.h"
#include "Camera.h"
#include "Core.h"
#include "Image.h"
#include "Light.h"
#include "Material.h"
#include "Object.h"
#include "Plane.h"
#include "Scene.h"
#include "Sphere.h"
#include "Timer.h"

#define XRESOLUTION 200
#define YRESOLUTION 200

RT::Scene* createScene() {

   const float kd = 0.6f;
   const float ka = 0.4f;
   int maxr = 15;

   RT::Scene* scene = new RT::Scene();
   RT::Group* world = new RT::Group();

   for ( int i = 0; i < 60; i++ ) {

      float x = (float)( rand() % ( maxr * 1000 ) )/1000.f;
      float y = (float)( rand() % ( maxr * 1000 ) )/1000.f;
      float z = (float)( rand() % ( maxr * 1000 ) )/3000.f;

      world->addObject( new RT::Sphere(
         new RT::LambertianMaterial( RT::Color( 0.4f, 0.9f, 0.3f ), kd, ka ),
         RT::Point( -(float)maxr * 0.5f + x, -(float)maxr * 0.5f + y, z ), 0.3f ) );
   
   }
   
   world->addObject( new RT::Plane( new RT::LambertianMaterial( 
      RT::Color( 0.8f, 0.8f, 0.8f ), kd, ka ), RT::Vector( 0.f, 0.f, 1.f ), 
      RT::Point( 0.f, 0.f, -0.1f ) ) );

   scene->setObject( world );

   scene->setBackground( new RT::ConstantBackground( 
      RT::Color( 0.0f, 0.0f, 0.0f ) ) );
   
   scene->setAmbient( RT::Color( ka, ka, ka ) );
   
   scene->addLight( new RT::PointLight( RT::Point( 20.f, -30.f, 100.f ), 
      RT::Color( 0.9f, 0.9f, 0.9f ) ) );

   scene->setCamera( new RT::PinholeCamera( RT::Point( 12.f, -12.f, 7.f ),
      RT::Point( 1.f, 1.f, 2.f ), RT::Vector(0.f, 0.f, 1.f), 60.f ) );

   return scene;

}

int main() {

   RT::Scene* scene = createScene();
   scene->setResolution( XRESOLUTION, YRESOLUTION );
   scene->preprocess();

   RT::Core* rtc = new RT::Core( scene );

   RT::Image image( XRESOLUTION, YRESOLUTION );
   RT::Color c;
   RT::Timer timer;
   for ( int x = 0; x < XRESOLUTION; x++ ) {
      for ( int y = 0; y < YRESOLUTION; y++ ) {
         c = rtc->renderPixel( x, y );
         std::cout << "Rendered pixel (" << x << "," << y << ") as (" << c.r() << "," << c.g() << "," << c.b() << ") in " 
            << timer.getElapsed() << " seconds" << std::endl;
         image.set( x, y, c );
      }
   }

   image.writeBMP( "image.bmp" );

   std::cout << std::flush;

   return 0;

}
