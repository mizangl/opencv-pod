//
//  VFiducial.h
//  Metrics
//
//  Created by Dave Fernandes on 2017-11-23.
//  Copyright © 2017 Swift. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "VTypes.h"

/// Container for fiducial data
@interface VFiducial : NSObject

@property (nonatomic) VFiducialType type;
@property (nonatomic) CGPoint center;
@property (nonatomic) CGFloat length;
@property (nonatomic) CGFloat width;
@property (nonatomic) CGFloat angleRads;
@property (nonatomic) CGFloat pixelPitch;
@property (nonatomic) CGFloat phaseShift;

@end

