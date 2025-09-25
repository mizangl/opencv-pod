//
//  VAutoEnhance.h
//  SwiftVision
//
//  Created by Zheng Liu on 2020-12-16.
//  Copyright © 2020 Swift Medical Inc. All rights reserved.
//

#ifndef VAutoEnhance_h
#define VAutoEnhance_h



#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "VTypes.h"


@interface VAutoEnhance : NSObject

//// Region mean colour (for RGB or Lab or etc.)
//@property (nonatomic, nonnull) UIColor* meanColour;
//
//// RGB-space transform values
//@property (nonatomic, nonnull) UIColor* bgrScaleFactors;
//
//// Lab space transform values
//@property (nonatomic, nonnull) UIColor* labScaleFactors;
//@property (nonatomic, nonnull) UIColor* labOffsets;
@property (nonatomic) VAutoEnhanceMethod autoEnhanceMethod;
@property (nonatomic) float vIlluminationIndex;

- (nonnull instancetype)initWithJSON:(nonnull NSString*)jsonStr;

@end

#endif /* VAutoEnhance_h */
