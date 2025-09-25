//
//  VTrackPoint.h
//  Vision
//
//  Created by justin on 2018-05-31.
//  Copyright © 2018 Swift Medical. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "VTypes.h"

/// Container for fiducial data
@interface VTrackPoint : NSObject

@property (nonatomic) CGPoint pt;
@property (nonatomic) CGPoint toCenter;

@property (nonatomic) int age;
@property (nonatomic) CGFloat quality;

@end
