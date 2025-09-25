//
//  VEvolution.h
//  Metrics
//
//  Created by Dave Fernandes on 2017-11-23.
//  Copyright © 2017 Swift. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "VTypes.h"


/// Container for evolution computation results
@interface VEvolution : NSObject

@property (nonatomic, readonly) float deltaDiameter;
@property (nonatomic, readonly) float deltaDiameterPerc;
@property (nonatomic, readonly) float deltaWidth;
@property (nonatomic, readonly) float deltaWidthPerc;
@property (nonatomic, readonly) float deltaArea;
@property (nonatomic, readonly) float deltaAreaPerc;
@property (nonatomic, readonly) float deltaAsymmetry;
@property (nonatomic, readonly) float deltaAsymmetryPerc;
@property (nonatomic, readonly) float deltaBorderIrregularity;
@property (nonatomic, readonly) float deltaBorderIrregularityPerc;
@property (nonatomic, readonly) float deltaTime;
@property (nonatomic, readonly) float diameterRate;
@property (nonatomic, readonly) float diameterRatePerc;
@property (nonatomic, readonly) float widthRate;
@property (nonatomic, readonly) float widthRatePerc;
@property (nonatomic, readonly) float areaRate;
@property (nonatomic, readonly) float areaRatePerc;
@property (nonatomic, readonly) float asymmetryRate;
@property (nonatomic, readonly) float asymmetryRatePerc;
@property (nonatomic, readonly) float borderIrregularityRate;
@property (nonatomic, readonly) float borderIrregularityRatePerc;
@property (nonatomic, readonly) float deltaRedArea;
@property (nonatomic, readonly) float deltaRedAreaPerc;
@property (nonatomic, readonly) float deltaGreenArea;
@property (nonatomic, readonly) float deltaGreenAreaPerc;
@property (nonatomic, readonly) float deltaYellowArea;
@property (nonatomic, readonly) float deltaYellowAreaPerc;
@property (nonatomic, readonly) float deltaBlackArea;
@property (nonatomic, readonly) float deltaBlackAreaPerc;
@property (nonatomic, readonly) float deltaBrownArea;
@property (nonatomic, readonly) float deltaBrownAreaPerc;
@property (nonatomic, readonly) float redAreaRate;
@property (nonatomic, readonly) float redAreaRatePerc;
@property (nonatomic, readonly) float greenAreaRate;
@property (nonatomic, readonly) float greenAreaRatePerc;
@property (nonatomic, readonly) float yellowAreaRate;
@property (nonatomic, readonly) float yellowAreaRatePerc;
@property (nonatomic, readonly) float blackAreaRate;
@property (nonatomic, readonly) float blackAreaRatePerc;
@property (nonatomic, readonly) float brownAreaRate;
@property (nonatomic, readonly) float brownAreaRatePerc;
@property (nonatomic, readonly) VUnitsType units;

@property (nonatomic, readonly) float deltaMaxWoundDepth;
@property (nonatomic, readonly) float deltaMaxWoundDepthPerc;
@property (nonatomic, readonly) float maxWoundDepthRate;
@property (nonatomic, readonly) float maxWoundDepthRatePerc;

@property (nonatomic, readonly) float deltaMaxWoundTunnellingLength;
@property (nonatomic, readonly) float deltaMaxWoundTunnellingLengthPerc;
@property (nonatomic, readonly) float maxWoundTunnellingLengthRate;
@property (nonatomic, readonly) float maxWoundTunnellingLengthRatePerc;

@property (nonatomic, readonly) float deltaMaxWoundUnderminingLength;
@property (nonatomic, readonly) float deltaMaxWoundUnderminingLengthPerc;
@property (nonatomic, readonly) float maxWoundUnderminingLengthRate;
@property (nonatomic, readonly) float maxWoundUnderminingLengthRatePerc;

@property (nonatomic, nonnull, readonly) NSMutableArray<NSArray<UIColor*>*>* coloursBeforeAfter;

@property (nonatomic, nonnull, readonly) NSMutableArray<NSNumber*>* woundUnderminingClockDelta;
@property (nonatomic, nonnull, readonly) NSMutableArray<NSNumber*>* woundTunnellingClockDelta;

@property (nonatomic, readonly) int deltaPUSHScore;
@property (nonatomic, readonly) float deltaPUSHScorePerc;
@property (nonatomic, readonly) float deltaPUSHScoreRate;
@property (nonatomic, readonly) float deltaPUSHScoreRatePerc;

- (nonnull instancetype)initWithJSON:(nonnull NSString*)jsonStr;

@end
