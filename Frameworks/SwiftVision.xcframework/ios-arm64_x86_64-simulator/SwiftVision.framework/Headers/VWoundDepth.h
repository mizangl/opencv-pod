//
//  VWoundDepth.h
//  Metrics
//
//  Created by Justin on 2014-12-09.
//  Copyright (c) 2014 Swift. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "VTypes.h"


@interface VDepthPoint : NSObject

@property (nonatomic) CGPoint point;
@property (nonatomic) float depth;
@property (nonatomic, readonly) BOOL isComputed;

- (nonnull instancetype)initWithPoint:(CGPoint)pointVal depth:(float)depthVal;

- (CGPoint)textRenderPoint;

@end

// MARK: -

@interface VWoundDepth : NSObject

@property (nonatomic, nonnull) NSMutableArray<VDepthPoint*>* depthPoints;
@property (nonatomic) CGSize originalImageSize;

- (nonnull instancetype)init;
- (nonnull instancetype)initWithJSON:(nonnull NSString*)jsonStr;

- (void)addDepthPoint:(nonnull VDepthPoint*)depthPoint;
- (void)addDepthPointsFromArray:(nonnull NSArray*)depthPointArray;
- (nullable VDepthPoint*)maxDepthPoint;
- (void)clearDepthPoints;

- (void)scaleToSize:(CGSize)size;

@end
