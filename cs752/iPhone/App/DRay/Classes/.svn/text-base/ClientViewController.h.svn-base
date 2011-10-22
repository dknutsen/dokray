//
//  ClientViewController.h
//  DRay
//
//  Created by dknutsen on 5/1/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ServerBrowser.h"
#import "ServerBrowserDelegate.h"
#import "RemoteConnect.h"


@interface ClientViewController : UIViewController <RoomDelegate, UITableViewDataSource, ServerBrowserDelegate>  {
	ServerBrowser* serverBrowser;
	RemoteConnect* remoteConnect;
	IBOutlet UITextView* debug;
	IBOutlet UITableView* serverList;
}

-(IBAction) joinRemoteConnect;
-(IBAction) btnExit;
-(IBAction) btnSnd;

// App delegate will call this whenever this view becomes active
- (void)activate;

@end
