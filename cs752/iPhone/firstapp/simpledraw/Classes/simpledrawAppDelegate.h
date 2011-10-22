//
//  simpledrawAppDelegate.h
//  simpledraw
//
//  Created by dknutsen on 4/24/10.
//  Copyright __MyCompanyName__ 2010. All rights reserved.
//

#import <UIKit/UIKit.h>

@class simpledrawViewController;

@interface simpledrawAppDelegate : NSObject <UIApplicationDelegate> {
    UIWindow *window;
    simpledrawViewController *viewController;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet simpledrawViewController *viewController;

@end

