//
//  ServerViewController.m
//  DRay
//
//  Created by dknutsen on 5/1/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import "ServerViewController.h"
#import "DRayAppDelegate.h"
#import "AppConfig.h"
#import "UITextView+Utils.h"


@implementation ServerViewController

@synthesize localRoom;

- (void)debugMessage:(NSString*)message{
	[debug appendTextAfterLinebreak:[NSString stringWithFormat:@"- %@", message]];
	[debug scrollToBottom];
}

- (void)activate {
	[self debugMessage:@"Entering server mode"];
	[self debugMessage:@"Creating and starting LocalRoom"];
	localRoom = [[[LocalRoom alloc] init] autorelease];
	localRoom.delegate = self;
	[localRoom start];
//	[[DRayAppDelegate getInstance] showChatRoom:room];
}

-(IBAction) btnExit {
	// KILL STUFF
	// Go to client
	[localRoom stop];
	localRoom = nil;
	[[DRayAppDelegate getInstance] showHome];
}


// We are being asked to display a chat message
- (void)displayChatMessage:(NSString*)message fromUser:(NSString*)userName {
	[self debugMessage:@"Displaying Message"];
	[debug appendTextAfterLinebreak:[NSString stringWithFormat:@"%@: %@", userName, message]];
	[debug scrollToBottom];
}

// Room closed from outside
- (void)roomTerminated:(id)room reason:(NSString*)reason {
	// Explain what happened
	UIAlertView* alert = [[UIAlertView alloc] initWithTitle:@"Room terminated" message:reason delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil];
	[alert show];
	[alert release];
	//	[self exit];
	[[DRayAppDelegate getInstance] showHome];
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
}



@end
