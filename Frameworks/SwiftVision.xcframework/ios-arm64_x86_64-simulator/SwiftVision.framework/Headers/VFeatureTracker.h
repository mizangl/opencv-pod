//
//  VFeatureTracker.h
//  MedVision
//
//  Created by justin on 2018-06-01.
//  Copyright © 2018 Swift Medical. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "VTrackPoint.h"
#import "VEdge.h"

@interface VFeatureTracker : NSObject

/// Tracked points. Valid after a call to trackPointsInImage
@property (nonatomic, strong, readonly, nonnull) NSArray<VTrackPoint*>* trackedPoints;

/// Percentage of detectedfeatures required for a valid track
@property (readonly) VTrackPoint* _Nullable trackCenter;

/// Edges tesselating tracked points. Valid after a call to trackPointsInImage
@property (nonatomic, strong, readonly, nonnull) NSArray<VEdge*>* trackedEdges;

/// Percentage of detectedfeatures required for a valid track
@property (readonly) float requiredFeatureFraction;

/// Percentage of detectedfeatures required for a valid track
@property (readonly) NSInteger desiredFeatureCount;

@property (nonatomic, assign) NSInteger imageHeight;
@property (nonatomic, assign) NSInteger imageWidth;

/**
 @abstract Initialize the detector. Features will not be detected in this call.
 @param width    Width of images in pixels
 @param height    Height of images in pixels
 @param count    Number of features deisired to track
 @param minCount   Minimum number of features required to be tracked to indicate success
 */
- (nonnull instancetype)initForWidth:(NSInteger)width height:(NSInteger)height desiredFeatureCount:(NSInteger)count minFeatureCount:(NSInteger)minCount;

/**
 @abstract Track features in an image and set flags.
 @note This method is NOT re-entrant. All calls must be synchronous from the same thread.
 @param image Image used to find fiducials
 */
- (void)trackFeaturesInImage:(nonnull UIImage*)scaledImage;

/**
 @abstract Reset tracker states to allow restart of tracking
 @note This method is NOT re-entrant. All calls must be synchronous from the same thread.
 */
- (void)resetTracker;
@end

@interface VFeatureTracker (Vision)

/**
 @abstract Track features in an image and set flags
 @note This method is NOT re-entrant. All calls must be synchronous from the same thread.
 @param image Image used to find fiducials
 */
- (void)trackFeaturesInCIImage:(nonnull CIImage*)image;
@end
