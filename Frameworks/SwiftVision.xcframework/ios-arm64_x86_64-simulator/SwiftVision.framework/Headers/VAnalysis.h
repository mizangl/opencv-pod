//
//  VAnalysis.h
//  Metrics
//
//  Created by Dave Fernandes on 2017-11-23.
//  Copyright © 2017 Swift. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "VTypes.h"

@class VRegion, VFiducial, VDepthPoint, VWoundTunnel, VWoundUndermine;


/// Container for analysis results
@interface VAnalysis : NSObject

@property (nonatomic, nullable, readonly) VRegion* region;

@property (nonatomic, readonly) float area;
@property (nonatomic, readonly) float diameter;
@property (nonatomic, readonly) float width;
@property (nonatomic, readonly) float diameterAngleRads;
@property (nonatomic, readonly) float imageHeadAngleRads;
@property (nonatomic, readonly) bool diameterAngleIsPreset;
@property (nonatomic, readonly) bool imageHeadAngleIsPreset;
@property (nonatomic, nullable, readonly) NSMutableArray<NSValue*>* diameterPoints;
@property (nonatomic, nullable, readonly) NSMutableArray<NSValue*>* widthPoints;
@property (nonatomic, nullable, readonly) NSMutableArray<NSValue*>* boundingBoxTLBRPoints;
@property (nonatomic, readonly) float asymmetry;
@property (nonatomic, readonly) float symmetryAngleRads;
@property (nonatomic, readonly) CGPoint centroid;
@property (nonatomic, readonly) float borderIrregularity;

@property (nonatomic, readonly) int numColours;
@property (nonatomic, readonly) float fiducialRealSize;
@property (nonatomic, readonly) float fiducialImageSize;
@property (nonatomic, readonly) float imageScaleFactor;
@property (nonatomic, readonly) VUnitsType units;
@property (nonatomic, nonnull, readonly) VFiducial* fiducial;
@property (nonatomic, readonly) CGPoint fiducialFaultLocation;

@property (nonatomic, readonly) CGSize originalImgSize;

@property (nonatomic, nullable, readonly) NSMutableArray<UIColor*>* colours;
@property (nonatomic, readonly) float redArea;
@property (nonatomic, readonly) float redColourness;
@property (nonatomic, readonly) float greenArea;
@property (nonatomic, readonly) float greenColourness;
@property (nonatomic, readonly) float yellowArea;
@property (nonatomic, readonly) float yellowColourness;
@property (nonatomic, readonly) float brownArea;
@property (nonatomic, readonly) float brownColourness;
@property (nonatomic, readonly) float blackArea;
@property (nonatomic, readonly) float blackColourness;

@property (nonatomic, readonly) int pushScore;

@property (nonatomic, nullable, readonly) VDepthPoint* maxDepthPoint;
@property (nonatomic, nullable, readonly) VWoundTunnel* maxLengthTunnel;
@property (nonatomic, nullable, readonly) VWoundUndermine* maxLengthUndermine;

- (nonnull instancetype)initWithJSON:(nonnull NSString*)jsonStr;

- (float)computeErrorOnLength:(float)lengthVal;
- (float)computeErrorOnArea:(float)areaVal;

- (BOOL)hasScale;
- (BOOL)isManuallyScaled;
- (BOOL)isAutomaticallyScaled;
- (BOOL)fiducialDetected;
- (BOOL)scaleCleared;

- (nonnull NSString*)getUnits;
- (CGPoint)diameterStart;
- (CGPoint)diameterEnd;
- (CGPoint)widthStart;
- (CGPoint)widthEnd;
- (CGPoint)boundingBoxTopLeft;
- (CGPoint)boundingBoxBottomRight;
- (CGPoint)boundingBoxCenter;

- (void)translateByX:(float)xOffset Y:(float)yOffset;
- (void)scaleByXScale:(float)xScale YScale:(float)yScale;
- (void)scaleToSize:(CGSize)size;

@end
