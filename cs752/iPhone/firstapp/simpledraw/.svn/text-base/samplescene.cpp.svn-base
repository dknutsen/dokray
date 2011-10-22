/*
 *  samplescene.cpp
 *  simpledraw
 *
 *  Created by dknutsen on 4/29/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "samplescene.h"
#import "Light.h"
#import "Material.h"
#import "Object.h"
#import "Plane.h"
#import "Sphere.h"
#import "Background.h"
#import "Camera.h"
#import "Scene.h"

namespace RT
{
	Scene* createScene() {
		
		const float kd = 0.6f;
		const float ka = 0.4f;
		int maxr = 15;
		
		Scene* scene = new Scene();
		Group* world = new Group();
		
		for ( int i = 0; i < 60; i++ ) {
			
			float x = (float)( rand() % ( maxr * 1000 ) )/1000.f;
			float y = (float)( rand() % ( maxr * 1000 ) )/1000.f;
			float z = (float)( rand() % ( maxr * 1000 ) )/3000.f;
			
			world->addObject( new Sphere(
										 new LambertianMaterial( Color( 0.4f, 0.9f, 0.3f ), kd, ka ),
										 Point( -(float)maxr * 0.5f + x, -(float)maxr * 0.5f + y, z ), 0.3f ) );
			
		}
		
		world->addObject( new Plane( new LambertianMaterial( 
															Color( 0.8f, 0.8f, 0.8f ), kd, ka ), Vector( 0.f, 0.f, 1.f ), 
									Point( 0.f, 0.f, -0.1f ) ) );
		
		scene->setObject( world );
		
		scene->setBackground( new ConstantBackground( 
													 Color( 0.0f, 0.0f, 0.0f ) ) );
		
		scene->setAmbient( Color( ka, ka, ka ) );
		
		scene->addLight( new PointLight( Point( 20.f, -30.f, 100.f ), 
										Color( 0.9f, 0.9f, 0.9f ) ) );
		
		scene->setCamera( new PinholeCamera( Point( 12.f, -12.f, 7.f ),
											Point( 1.f, 1.f, 2.f ), Vector(0.f, 0.f, 1.f), 60.f ) );
		
		return scene;
		
	}
}