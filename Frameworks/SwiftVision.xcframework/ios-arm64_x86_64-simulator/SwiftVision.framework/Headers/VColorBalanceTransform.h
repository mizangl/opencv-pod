//
//  VColorBalanceTransform.h
//  Metrics
//
//  Created by Dave Fernandes on 2017-11-23.
//  Copyright © 2017 Swift. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "VTypes.h"


@interface VColorBalanceTransform : NSObject

// Region mean colour (for RGB or Lab or etc.)
@property (nonatomic, nonnull) UIColor* meanColour;

// RGB-space transform values
@property (nonatomic, nonnull) UIColor* bgrScaleFactors;

// Lab space transform values
@property (nonatomic, nonnull) UIColor* labScaleFactors;
@property (nonatomic, nonnull) UIColor* labOffsets;
@property (nonatomic) VColorBalanceTransformMethod colourBalMethod;

- (nonnull instancetype)initWithJSON:(nonnull NSString*)jsonStr;

@end
