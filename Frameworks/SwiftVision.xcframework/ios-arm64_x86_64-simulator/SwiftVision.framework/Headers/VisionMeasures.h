//
//  VisionMeasures.h
//  Metrics
//
//  Created by Dave Fernandes on 2017-11-24.
//  Copyright © 2017 Swift. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "VTypes.h"

@class VRegion, VPolygon, VFiducial, VDepthPoint, VWoundDepth, VWoundTunnel, VWoundTunnelling, VWoundUndermine, VWoundUndermining, VAnalysis, VFiducial, VEvolution, VRegistrationTransform, VColorBalanceTransform, VAutoEnhance, VSmartTissue, VDepthEstimator;

@interface VisionMeasures : NSObject

// MARK: - JSON conversion
@property (nonatomic, nonnull) NSString* analysisJSON;
@property (nonatomic, nonnull) NSString* depthMapJSON;
@property (nonatomic, nonnull) NSString* woundTunnellingJSON;
@property (nonatomic, nonnull) NSString* woundUnderminingJSON;
@property (nonatomic, nonnull) NSString* analysisProtobuf;

@property (nonatomic, nullable, readonly) NSString* colourBalanceJSON;
@property (nonatomic, nullable, readonly) NSString* registrationJSON;
@property (nonatomic, nullable, readonly) NSString* evolutionJSON;

- (void)setRegionJSON:(nonnull NSString*)jsonString;

// MARK: - Images
- (void)setImage:(nonnull UIImage*)img toBGR:(BOOL)convert;
- (void)resetImage;

// MARK: - Regions
@property (nonatomic, nonnull) VRegion* region;

- (void)clearRegion;
- (void)reduceRegion;
- (void)clipRegionAgainst:(nonnull VRegion*)clipRegion withOperation:(VClipMethod)clipMethod;
- (VStatus)refineRegionWithIterationCount:(unsigned int)iterations inward:(BOOL)refineInward forcedOffsetPx:(int)offsetPx avoidingFiducial:(nonnull VFiducial*)fiducial;
- (void)setAutoTraceRegion:(nonnull VRegion*)autoTraceRegion withModelVersion:(nonnull NSString*)modelVersion;
- (void)setSmartTissueData:(nonnull VSmartTissue*)smartTissueData;
- (nullable VSmartTissue*)smartTissue;

// MARK: - Depth points
@property (nonatomic, nonnull, readonly) VWoundDepth* depthMap;

- (void)addDepthPoint:(nonnull VDepthPoint*)depthPoint;
- (void)clearAllDepthPoints;

// MARK: - Tunneling
@property (nonatomic, nonnull, readonly) VWoundTunnelling* woundTunnelling;

- (void)addWoundTunneling:(nonnull VWoundTunnelling*)woundTunneling;
- (void)addWoundTunnel:(nonnull VWoundTunnel*)woundTunnel;
- (void)clearAllWoundTunneling;

// MARK: - Undermining
@property (nonatomic, nonnull, readonly) VWoundUndermining* woundUndermining;

- (void)addWoundUndermining:(nonnull VWoundUndermining*)woundUndermining;
- (void)addWoundUndermine:(nonnull VWoundUndermine*)woundUndermine;
- (void)clearAllWoundUndermining;

// MARK: - Analysis
@property (nonatomic, readonly) VFiducialType fiducialType;
@property (nonatomic, nonnull, readonly) VAnalysis* analysis;
@property (nonatomic, nonnull, readonly) VAnalysis* basicAnalysis;

- (void)analyseRegionForType:(VAnalysisType)analysisType;
- (void)analyseRegionGeometryForType:(VAnalysisType)analysisType;

// MARK: - Scale
- (nullable VFiducial*)findFiducialType:(VFiducialType)fidType fieldOfView:(double)FOV fastDetect:(BOOL)fast status:(nonnull VStatus*)status;
- (VStatus)setScaleFactor:(double)scaleFactor units:(VUnitsType)units;
- (VStatus)setScaleWithRulerUnits:(VUnitsType)units fieldOfView:(double)FOV atPoint:(CGPoint)pt preferredDirection:(CGVector)dir;
- (VStatus)setScaleWithExistingRuler:(nonnull VFiducial*)fid;

- (nullable NSString*)convertVStatusToString:(nonnull VStatus*)status;

- (void)setDiameterAngle:(CGFloat)angleInRads preset:(BOOL)isPreset;
- (void)setHeadAngle:(CGFloat)angleInRads preset:(BOOL)isPreset tiedToDiameter:(BOOL)tiedToDiameter;

// MARK: - Registration
- (nullable UIImage*)registeredImageForReference:(nonnull VisionMeasures*)reference status:(nonnull VStatus*)status;
- (nullable VRegistrationTransform*)registrationTransformForReference:(nonnull VisionMeasures*)reference status:(nonnull VStatus*)status;
- (nonnull UIImage*)warpImageWithTransform:(nonnull VRegistrationTransform*)transform;

// MARK: - Transforms
- (BOOL)transformRegionWithCATransform3D:(CATransform3D)transform invalidateAnalysis:(BOOL)invalidate;
- (BOOL)transformRegionWithTransform:(nonnull VRegistrationTransform*)transform invalidateAnalysis:(BOOL)invalidate;
- (BOOL)translateRegionByX:(float)xOffset Y:(float)yOffset invalidateAnalysis:(BOOL)invalidate;
- (BOOL)scaleRegionWithXScale:(float)xScale YScale:(float)yScale invalidateAnalysis:(BOOL)invalidate;
- (BOOL)rotateRegionByAngle:(float)angleInRads invalidateAnalysis:(BOOL)invalidate;

// MARK: - Color
- (nullable UIImage*)enhanceImageWithAutoEnhance:(VAutoEnhanceMethod)aEMethod;
- (nullable UIImage*)colourBitmapForBucket:(VColourBucket)colourBucket status:(nonnull VStatus*)status;
- (nullable UIImage*)colourBalanceImageUsingPoint:(CGPoint)pt tolerance:(int)tol status:(nonnull VStatus*)status;
- (nullable VColorBalanceTransform*)colourBalanceUsingPoint:(CGPoint)pt tolerance:(int)tol status:(nonnull VStatus*)status;
- (nullable VColorBalanceTransform*)colourBalanceUsingFiducialWithTolerance:(int)tol status:(nonnull VStatus*)status;
- (nullable VColorBalanceTransform*)colourBalanceUsingSwiftFiducialWithTolerance:(int)tol backupPoint:(CGPoint)pt status:(nonnull VStatus*)status;
- (nonnull UIImage*)colourBalanceImageWithColourBalance:(nonnull VColorBalanceTransform*)balance;

// MARK: - Evolution
- (nullable VEvolution*)evolutionAt:(nonnull NSDate*)currentDate fromReference:(nonnull VisionMeasures*)reference at:(nonnull NSDate*)oldDate status:(nonnull VStatus*)status;

// MARK: - Nudge
- (int)nudgeBrushRadiusAtPoint:(CGPoint)pt withMin:(int)minRadius withMax:(int)maxRadius;
- (void)setRegionFromBitmap:(nonnull UIImage*)bitmap withPolygon:(nonnull VPolygon*)polygonType;
- (void)nudgeRegionWithBrushSize:(int)brushSize path:(nonnull NSArray<NSValue*>*)nudgePathPoints;

// MARK: - Legacy
- (void)setPUSHScore:(int)score;

// MARK: - Annotations
- (nullable UIImage*)getAnnotatedImage;
- (nullable UIImage*)getTraceImageFromAnnotation:(nonnull UIImage*)image;
// MARK: - Proprietary Data
- (NSData *)getProprietaryDataWithMetadata:(nonnull NSString*)metadata Runner:(nullable VDepthEstimator*)depthEstimator;

@end
