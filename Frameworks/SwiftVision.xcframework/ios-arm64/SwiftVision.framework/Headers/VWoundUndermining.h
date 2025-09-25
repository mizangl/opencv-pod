//
//  VWoundUndermining.h
//  Metrics
//
//  Created by Justin on 2014-12-09.
//  Copyright (c) 2014 Swift. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class VRegion;


@interface VWoundUndermine : NSObject

@property (nonatomic, nonnull) NSMutableArray<NSValue*>* points;
@property (nonatomic) float length;
@property (nonatomic) CGVector direction;
@property (nonatomic) float imageScaleFactor;
@property (nonatomic) BOOL renderPointsResolved;
@property (nonatomic, nonnull) NSMutableArray<NSValue*>* renderPoints;
@property (nonatomic, nonnull) NSMutableArray<NSValue*>* regionBorderPoints;

- (nonnull instancetype)initWithPointArray:(nonnull NSMutableArray*)pointsArr length:(float)lengthVal direction:(CGVector)directionVec;
- (nonnull instancetype)initWithPointArray:(nonnull NSMutableArray*)pointsArr length:(float)lengthVal;

- (void)resolveAgainstRegion:(nonnull VRegion*)region;
- (CGPoint)textRenderPoint;

@end

// MARK: -

@interface VWoundUndermining : NSObject

@property (nonatomic, nonnull) NSMutableArray<VWoundUndermine*>* woundUndermines;
@property (nonatomic) CGSize originalImageSize;
@property (nonatomic, nonnull) NSMutableArray<NSNumber*>* clockOccupancy;
@property (nonatomic, nonnull) NSMutableArray<NSMutableArray<NSNumber*>*>* consolidatedClockOccupancy;

- (nonnull instancetype)init;
- (nonnull instancetype)initWithJSON:(nonnull NSString*)jsonStr;

- (BOOL)addWoundUndermine:(nonnull VWoundUndermine*)woundUndermine;
- (nullable VWoundUndermine*)longestWoundUndermine;
- (void)resolveAgainstRegion:(nonnull VRegion*)region;
- (void)clearUndermines;
- (BOOL)resolvedWithScale;

- (void)scaleToSize:(CGSize)size;

@end
