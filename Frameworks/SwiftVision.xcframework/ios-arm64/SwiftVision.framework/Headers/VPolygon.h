//
//  VPolygon.h
//  Metrics
//
//  Created by Justin on 2014-12-18.
//  Copyright (c) 2014 Swift. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "VTypes.h"

/// Container for region polygon data
@interface VPolygon : NSObject

@property (nonatomic) VPolygonType type;
@property (nonatomic) int lineDiameter;
@property (nonatomic, nullable) UIColor* color;
@property (nonatomic, nonnull, readonly) NSMutableArray<NSValue*>* points;

- (nonnull instancetype)init;
- (nullable instancetype)initWithJSON:(nonnull NSString*)JSON;

- (void)addPoint:(CGPoint)point;
- (CGPoint)pointAtIndex:(int)index;
- (BOOL)isAdditive;

- (double)length:(BOOL)closePath;
- (double)area;
- (double)strokeArea:(int)brushSize;

@end
