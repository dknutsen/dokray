//
//  main.m
//  Untitled
//
//  Created by dknutsen on 2/28/10.
//  Copyright __MyCompanyName__ 2010. All rights reserved.
//

#import <UIKit/UIKit.h>

#include "Image.h"
#include "creative06.h"


int main(int argc, char *argv[]) {
    
    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
    int retVal = UIApplicationMain(argc, argv, nil, nil);
	
	const unsigned int xres = 1024;
	const unsigned int yres = 1024;
	Image image(xres, yres);
	
	Scene* scene = make_scene();
	scene->set_image(&image);
	scene->preprocess();
	
	scene->render();

	
	image.writeBMP("output.bmp");
	
	CGRect myImageRect = CGRectMake(0.0f, 0.0f, 320.0f, 109.0f); 
	UIImageView *myImage = [[UIImageView alloc] initWithFrame:myImageRect]; 
	[myImage setImage:[UIImage imageNamed:@"output.bmp"]]; 
	myImage.opaque = YES;
	// explicitly opaque for performance 
	[self.view addSubview:myImage]; [myImage release]; 


	
    [pool release];
    return retVal;
}
