//
//  VBaseDepthEstimator.h
//  MedVision
//
//  Created by Narek Adamyan on 2018-11-09.
//  Copyright © 2018 Swift Medical. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreMotion/CoreMotion.h>

@class VRegion;
@class VWoundDepth;

@protocol VBaseDepthEstimator

/// Parameters passed to algorithm
@property (nonatomic, nonnull) NSDictionary<NSString*, id>* parameters;

/// Metadata for upload
@property (nonatomic, nonnull, readonly) id metadata;

/// True if has reconstruction
@property (atomic, readonly) Boolean hasResults;

/**
	@abstract Set the initial reference image and compute.
		Must be called from the main thread. Completion handler will be called on main thread.
	@param image		The initial image downsampled for analysis
	@param attitude		The initial attitude with respect to the reference frame
	@param completion	Called after computation for this image is complete
	@param errorOrNil	An error (VisionErrorCode) or nil
*/
- (void)setReferenceImage:(nonnull UIImage*)image initialAttitude:(nonnull CMAttitude*)attitude completion:(void (^_Nonnull)(NSError* _Nullable errorOrNil))completion;


/**
	@abstract Compute depth map after region and scale have been determined.
		Must be called from the main thread. Completion handler will be called on main thread.
	@param measurementJSON	Measurement JSON string containing the analysis
	@param completion	Called after computation is complete
	@param depth		New autoreleased depth map object or nil
    @param scale        New scale based on 3d model
	@param errorOrNil	An error (VisionErrorCode) or nil
*/
- (void)depthForMeasurement:(nonnull NSString*)measurementJSON completion:(void (^_Nonnull)(VWoundDepth* _Nullable depth, NSNumber* _Nullable scale, NSError* _Nullable errorOrNil))completion;

/**
	@abstract Finalize computations after adding all images.
		Must be called from the main thread. Completion handler will be called on main thread.
	@param completion	Called after computation is complete
	@param errorOrNil	An error (VisionErrorCode) or nil
*/
- (void)finalizeWithCompletion:(void (^_Nonnull)(NSError* _Nullable errorOrNil))completion;

/**
	@abstract Cancel any in-progress operations. Operation completion handlers will be called.
		May be called from any thread.
	@note Deallocating an instance will cancel its operations. However, completion handlers will not be called.
*/
- (void)cancel;

/**
 	@abstract Reports if this instance was previously cancelled
*/
- (BOOL)isCancelled;

/**
	@return Current progress (0-1).
*/
- (Float32)progress;

@end
