//
//  SimpleAppAppDelegate.m
//  SimpleApp
//
//  Created by dknutsen on 3/2/10.
//  Copyright __MyCompanyName__ 2010. All rights reserved.
//

#import "SimpleAppAppDelegate.h"
#import "whatupvc.h"

@implementation SimpleAppAppDelegate

@synthesize window, wvc;


- (void)applicationDidFinishLaunching:(UIApplication *)application {    
	whatupvc *local_wvc = [whatupvc alloc];
	
	[local_wvc initWithNibName:@"whatup" bundle:[NSBundle mainBundle]];
	
	self.wvc = local_wvc;
	[local_wvc release];
	
	[window addSubview:[self.wvc view]];
	
	
    [window makeKeyAndVisible];
}


- (void)dealloc {
	[wvc release];
    [window release];
    [super dealloc];
}


@end
