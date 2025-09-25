//
//  VSmartTissue.h
//  SwiftVision
//
//  Created by Marius Gutoi on 11/11/22.
//  Copyright © 2022 Swift Medical Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface VSmartTissue : NSObject

@property (nonatomic) NSString *modelVersion;
@property (nonatomic) BOOL woundTissueDetected;
@property (nonatomic) CGSize outputDimensions;
// output color coding
@property (nonatomic) NSString* outputColorBackground;
@property (nonatomic) NSString* outputColorHealx;
@property (nonatomic) NSString* outputColorEpithelial;
@property (nonatomic) NSString* outputColorGranulation;
@property (nonatomic) NSString* outputColorEschar;
@property (nonatomic) NSString* outputColorSlough;
// output raw
@property (nonatomic) float outputRawBackground;
@property (nonatomic) float outputRawHealx;
@property (nonatomic) float outputRawEpithelial;
@property (nonatomic) float outputRawGranulation;
@property (nonatomic) float outputRawEschar;
@property (nonatomic) float outputRawSlough;
// output normalized
//@property (nonatomic) float outputNormalizedBackground;
//@property (nonatomic) float outputNormalizedHealx;
//@property (nonatomic) float outputNormalizedEpithelial;
//@property (nonatomic) float outputNormalizedGranulation;
//@property (nonatomic) float outputNormalizedEschar;
//@property (nonatomic) float outputNormalizedSlough;
@property (nonatomic) NSString *outputNormalizedBackground;
@property (nonatomic) NSString *outputNormalizedHealx;
@property (nonatomic) NSString *outputNormalizedEpithelial;
@property (nonatomic) NSString *outputNormalizedGranulation;
@property (nonatomic) NSString *outputNormalizedEschar;
@property (nonatomic) NSString *outputNormalizedSlough;
 
@end

NS_ASSUME_NONNULL_END
