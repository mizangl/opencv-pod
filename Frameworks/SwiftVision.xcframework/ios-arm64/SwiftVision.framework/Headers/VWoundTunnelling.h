//
//  VWoundTunnelling.h
//  Metrics
//
//  Created by Justin on 2014-12-09.
//  Copyright (c) 2014 Swift. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class VRegion;


@interface VWoundTunnel : NSObject

@property (nonatomic, nonnull) NSMutableArray<NSValue*>* points;
@property (nonatomic) float length;
@property (nonatomic) CGVector direction;
@property (nonatomic) float imageScaleFactor;
@property (nonatomic) BOOL renderPointsResolved;
@property (nonatomic, nonnull) NSMutableArray<NSValue*>* renderPoints;

- (nonnull instancetype)initWithPointArray:(nonnull NSMutableArray*)pointsArr length:(float)lengthVal direction:(CGVector)directionVec;
- (nonnull instancetype)initWithPointArray:(nonnull NSMutableArray*)pointsArr length:(float)lengthVal;

- (void)resolveAgainstRegion:(nonnull VRegion*)region withImageScaleFactor:(float)imageScaleFactor;
- (CGPoint)textRenderPoint;

@end

// MARK: -

@interface VWoundTunnelling : NSObject

@property (nonatomic, nonnull) NSMutableArray<VWoundTunnel*>* woundTunnels;
@property (nonatomic) CGSize originalImageSize;
@property (nonatomic, nonnull) NSMutableArray<NSNumber*>* clockOccupancy;

- (nonnull instancetype)init;
- (nonnull instancetype)initWithJSON:(nonnull NSString*)jsonStr;

- (BOOL)addWoundTunnel:(nonnull VWoundTunnel*)woundTunnel;
- (nullable VWoundTunnel*)longestWoundTunnel;
- (void)resolveAgainstRegion:(nonnull VRegion*)region withImageScaleFactor:(float)imageScaleFactor;
- (void)clearTunnels;

- (void)scaleToSize:(CGSize)size;

@end
