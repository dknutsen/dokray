//
//  ServerViewController.h
//  DRay
//
//  Created by dknutsen on 5/1/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
//#import "Room.h"
//#import "RoomDelegate.h"
#import "LocalRoom.h"


@interface ServerViewController : UIViewController <RoomDelegate> {
	LocalRoom* localRoom;
	IBOutlet UITextView* debug;
}

@property(nonatomic,retain) LocalRoom* localRoom;

-(IBAction) btnExit;

// App delegate will call this whenever this view becomes active
- (void)activate;


@end
