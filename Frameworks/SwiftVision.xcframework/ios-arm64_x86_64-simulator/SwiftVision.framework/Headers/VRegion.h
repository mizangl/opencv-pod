//
//  VRegion.h
//  Metrics
//
//  Created by Justin on 2014-12-18.
//  Copyright (c) 2014 Swift. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class VPolygon;

/// Container for region data
@interface VRegion : NSObject

@property (nonatomic, nonnull) NSMutableArray<VPolygon*>* polygons;
@property (nonatomic) CGSize surfaceSize;
@property (nonatomic) BOOL refined;
@property (nonatomic) int initialPolyCount;
@property (nonatomic) int autoTraceInferenceTime;
@property (nonatomic) BOOL isAutoTraceResult;
@property (nonatomic) BOOL regionHasBeenUpdated;

- (nonnull instancetype)init;
- (nonnull instancetype)initForSurfaceSize:(CGSize)surfaceSize;
- (nullable instancetype)initWithJSON:(nonnull NSString*)JSON;
- (nullable instancetype)initWithReferenceImage:(nonnull UIImage*)referenceImage region:(nonnull VRegion*)region image:(nonnull UIImage*)image;

- (BOOL)addPolygon:(nonnull VPolygon*)poly;
- (BOOL)hasPolygons;
- (nonnull NSString*)toJSON;

- (double)area;

@end
