//
//  DRayAppDelegate.h
//  DRay
//
//  Created by dknutsen on 5/1/10.
//  Copyright __MyCompanyName__ 2010. All rights reserved.
//

#import <UIKit/UIKit.h>

@class HomeViewController, ClientViewController, ServerViewController;

@interface DRayAppDelegate : NSObject <UIApplicationDelegate> {
    UIWindow *window;
	HomeViewController *homeViewController;
	ClientViewController *clientViewController;
	ServerViewController *serverViewController;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property(nonatomic, retain) IBOutlet HomeViewController *homeViewController;
@property(nonatomic, retain) IBOutlet ClientViewController *clientViewController;
@property(nonatomic, retain) IBOutlet ServerViewController *serverViewController;


// Main instance of the app delegate
+ (DRayAppDelegate*)getInstance;

// Go to server view
- (void)showHome;

// Go to client view
- (void)showClient;

// Go to server view
- (void)showServer;

@end

