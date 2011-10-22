//
//  DRayAppDelegate.m
//  DRay
//
//  Created by dknutsen on 5/1/10.
//  Copyright __MyCompanyName__ 2010. All rights reserved.
//

#import "DRayAppDelegate.h"
#import	"HomeViewController.h"
#import "ClientViewController.h"
#import "ServerViewController.h"

static DRayAppDelegate* _instance;

@implementation DRayAppDelegate

@synthesize window;
@synthesize homeViewController;
@synthesize clientViewController;
@synthesize serverViewController;



//- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {    
//    // Override point for customization after application launch
//    [window makeKeyAndVisible];	
//	return YES;
//}
- (void)applicationDidFinishLaunching:(UIApplication *)application {    
    // Allow other classes to use us
    _instance = self;
    
    [window addSubview:clientViewController.view];
    [window addSubview:serverViewController.view];
    [window addSubview:homeViewController.view];
    [window makeKeyAndVisible];
    
    // Greet user
    [window bringSubviewToFront:homeViewController.view];
    [homeViewController activate];
}



- (void)dealloc {
	[homeViewController release];
	[clientViewController release];
	[serverViewController release];
    [window release];
    [super dealloc];
}


+ (DRayAppDelegate*)getInstance {
	return _instance;
}

// Show client view screen
- (void)showHome {
	[homeViewController activate];
	[window bringSubviewToFront:homeViewController.view];
}

// Show client view screen
- (void)showClient {
	[clientViewController activate];
	[window bringSubviewToFront:clientViewController.view];
}

- (void)showServer {
	[serverViewController activate];
	[window bringSubviewToFront:serverViewController.view];
}

@end
