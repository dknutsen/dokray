//
//  simpleview.m
//  simpledraw
//
//  Created by dknutsen on 4/24/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import "simpleview.hh"

#import "Core.h"
#import "Scene.h"
#import "samplescene.h"
#import "Color.h"


@implementation simpleview


- (id)initWithFrame:(CGRect)frame {
    if ((self = [super initWithFrame:frame])) {
        // Initialization code
    }
    return self;
}


// Only override drawRect: if you perform custom drawing.
// An empty implementation adve- (void)drawRect:(CGRect)rect;
- (void)drawRect:(CGRect)rect;
{
	int xres,yres; 
	xres = 100;
	yres = 200;
	RT::Scene* scene = RT::createScene();
	scene->setResolution( xres, yres );
	scene->preprocess();
	RT::Core* rtc = new RT::Core( scene );
	
	
	CGContextRef context = UIGraphicsGetCurrentContext(); 
	CGContextClearRect(context, rect);
	
	for(int i=0; i<xres; i++)
	{
		for (int j=0; j<yres; j++) 
		{
			RT::Color	c = rtc->renderPixel(i,yres-j);
			//float r = (float)i/256.0;
			//float g = (float)j/256.0;
			CGContextSetRGBStrokeColor(context, c.r(), c.g(), c.b(), 1.0); // yellow line
			CGContextSetRGBFillColor(context, c.r(), c.g(), c.b(), 1.0); // green color, half transparent
			CGContextFillRect(context, CGRectMake(i+1, j+1, 1, 1));
		}
		
	}
	CGContextSetRGBStrokeColor(context, 1.0, 1.0, 1.0, 1.0); // yellow line
	CGContextSetRGBFillColor(context, 1.0, 1.0, 1.0, 1.0); // green color, half transparent
	CGContextFillRect(context, CGRectMake(2, 350, 30, 10));
	
	//CGContextBeginPath(context);
	//CGContextMoveToPoint(context, 50.0, 50.0); //start point
	//CGContextAddLineToPoint(context, 250.0, 100.0);
	//CGContextAddLineToPoint(context, 250.0, 350.0);
	//CGContextAddLineToPoint(context, 50.0, 350.0); // end path
	//CGContextClosePath(context); // close path
	//CGContextSetLineWidth(context, 8.0); // this is set from now on until you explicitly change it
	//CGContextStrokePath(context); // do actual stroking
	
	 // a square at the bottom left-hand corner
}

- (void)dealloc {
    [super dealloc];
}


@end
