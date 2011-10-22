//
//  HomeViewController.m
//  DRay
//
//  Created by dknutsen on 5/1/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import "HomeViewController.h"
#import	"DRayAppDelegate.h"
#import "AppConfig.h"


@implementation HomeViewController

// App delegate will call this whenever this view becomes active
- (void)activate {
	// Display keyboard
	//[input becomeFirstResponder];
}

//---hide the keyboard---
-(IBAction) btnClient {

	// Go to client
	[[DRayAppDelegate getInstance] showClient];
}

-(IBAction) btnServer {

	// Go to client
	[[DRayAppDelegate getInstance] showServer];
}


/*
 // The designated initializer.  Override if you create the controller programmatically and want to perform customization that is not appropriate for viewDidLoad.
- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    if ((self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil])) {
        // Custom initialization
    }
    return self;
}
*/

/*
// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
- (void)viewDidLoad {
    [super viewDidLoad];
}
*/

/*
// Override to allow orientations other than the default portrait orientation.
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
    // Return YES for supported orientations
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}
*/
/*
- (void)didReceiveMemoryWarning {
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
}

- (void)viewDidUnload {
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}


- (void)dealloc {
    [super dealloc];
}*/


@end
