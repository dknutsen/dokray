//
//  ClientViewController.m
//  DRay
//
//  Created by dknutsen on 5/1/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import "ClientViewController.h"
#import "DRayAppDelegate.h"
#import "AppConfig.h"
#import "UITextView+Utils.h"


// Private properties
@interface ClientViewController ()
@property(nonatomic,retain) ServerBrowser* serverBrowser;
@property(nonatomic,retain) RemoteConnect* remoteConnect;
@end


@implementation ClientViewController

@synthesize serverBrowser;
@synthesize remoteConnect;


- (void)debugMessage:(NSString*)message{
	[debug appendTextAfterLinebreak:[NSString stringWithFormat:@"- %@", message]];
	[debug scrollToBottom];
}

// View loaded
- (void)viewDidLoad {
	[self debugMessage:@"View Loaded"];
	serverBrowser = [[ServerBrowser alloc] init];
	serverBrowser.delegate = self;
	remoteConnect = nil;
}

- (void)dealloc {
    self.serverBrowser = nil;
    [super dealloc];
}


- (void)activate {
	[self debugMessage:@"Entering Client"];
	[serverBrowser start];
	[self debugMessage:@"Starting ServerBrowser..."];
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



-(IBAction) btnExit {
	// KILL STUFF
	// Go to client
	[[DRayAppDelegate getInstance] showHome];
}

- (IBAction)joinRemoteConnect {
	if (remoteConnect != nil) {
		[self debugMessage:@"Already Connected"];
		return;
	}
	// Figure out which server is selected
	NSIndexPath* currentRow = [serverList indexPathForSelectedRow];
	if ( currentRow == nil ) {
		UIAlertView* alert = [[UIAlertView alloc] initWithTitle:@"Which chat room?" message:@"Please select which chat room you want to join from the list above" delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil];
		[alert show];
		[alert release];
		return;
	}
	int i=currentRow.row;
	NSNetService* selectedServer = [serverBrowser.servers objectAtIndex:currentRow.row];
	
	[self debugMessage:@"Creating remote connect"];
	// Create chat room that will connect to that chat server
	remoteConnect = [[[RemoteConnect alloc] initWithNetService:selectedServer] autorelease];
	
	[self debugMessage:@"Closing server browser"];
	// Stop browsing and switch over to chat room
	[serverBrowser stop];
	
	remoteConnect.delegate = self;
	[remoteConnect start];
	//[[DRayAppDelegate getInstance] showChatRoom:room];
}

-(IBAction) btnSnd {
	if (remoteConnect == nil) {
		[self debugMessage:@"Not sending message, no RC"];
		return;
	}
	[self debugMessage:@"Sending Message"];
	[remoteConnect broadcastChatMessage:@"Message" fromUser:@"dok"];
}


#pragma mark -
#pragma mark ServerBrowserDelegate Method Implementations
- (void)updateServerList {
	[self debugMessage:@"Update Server List..."];
	[serverList reloadData];
}

#pragma mark -
#pragma mark UITableViewDataSource Method Implementations

// Number of rows in each section. One section by default.
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	return [serverBrowser.servers count];
}


// Table view is requesting a cell
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	static NSString* serverListIdentifier = @"serverListIdentifier";
	
	UITableViewCell *cell = (UITableViewCell *)[tableView dequeueReusableCellWithIdentifier:serverListIdentifier];
	if (cell == nil) {
		cell = [[[UITableViewCell alloc] initWithFrame:CGRectZero reuseIdentifier:serverListIdentifier] autorelease];
	}
	
	// Set cell's text to server's name
	NSNetService* server = [serverBrowser.servers objectAtIndex:indexPath.row];
	cell.text = [server name];
	[self debugMessage:[NSString stringWithFormat:@"Adding cell with text: %@", [server name]]];
	
	
	return cell;
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



@end
