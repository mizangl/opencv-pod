//
//  VEdge.h
//  MedVision
//
//  Created by justin on 2018-05-31.
//  Copyright © 2018 Swift Medical. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <SwiftVision/VTypes.h>
#import <SwiftVision/VTrackPoint.h>

/// Container for fiducial data
@interface VEdge : NSObject

@property (nonatomic) VTrackPoint* tp0;
@property (nonatomic) VTrackPoint* tp1;

@end
