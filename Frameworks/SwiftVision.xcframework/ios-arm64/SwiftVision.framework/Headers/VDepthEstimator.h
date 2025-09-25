//
//  VDepthEstimator.h
//  Metrics
//
//  Created by Dave Fernandes on 2017-09-27.
//  Copyright © 2017 Swift. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreMotion/CoreMotion.h>

#import "VBaseDepthEstimator.h"

@class VRegion;
@class VWoundDepth;


@interface VDepthEstimator : NSObject <VBaseDepthEstimator>

/// The reference frame used for the initial image attitude
@property (nonatomic, readonly) CMAttitudeReferenceFrame referenceFrame;

/// Camera focal length in cm
@property (nonatomic, readonly) Float32 focalLength;

/// Camera field of view
@property (nonatomic, readonly) Float32 fieldOfView;

/// Camera zoom factor (digital)
@property (nonatomic, readonly) Float32 digitalZoomFactor;

/// Metadata for upload
@property (nonatomic, nonnull, readonly) id metadata;

/// Parameters passed to algorithm
@property (nonatomic, nonnull) NSDictionary<NSString*, id>* parameters;

/// True if has reconstruction
@property (atomic, readonly) Boolean hasResults;

/**
	@abstract Construct instance with camera constants.
	@param frame		The reference frame used for the initial image attitude
	@param focalLength	Camera focal length in cm
	@param fieldOfView	Camera field of view
	@param zoom			Camera zoom factor (digital)
*/
- (nonnull instancetype)initWithReferenceFrame:(CMAttitudeReferenceFrame)frame focalLength:(Float32)focalLength fieldOfView:(Float32)fieldOfView digitalZoomFactor:(Float32)zoom;

/**
	@abstract Construct by restoring from serialized state.
	@param state		Binary serialization of the object.
*/
+ (nullable instancetype)estimatorWithState:(nonnull NSData*)state;

/**
	@abstract Serialize the state of the object.
	@param completion	Callback to receive the data.
*/
- (void)saveStateWithCompletion:(void (^_Nonnull)(NSData* _Nullable))completion;

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
	@abstract Add an additional image and compute.
		Must be called from the main thread. Completion handler will be called on main thread.
	@param image		The additional image downsampled for analysis
	@param attitude		The attitude relative to the reference image's attitude
	@param prompt		Identifier for prompt displayed to the user when image was captured
	@param captureMethod	Either @"auto" or @"manual"
 	@param otherParameters some other parameters that we want to track for the image.
	@param completion	Called after computation for this image is complete
	@param errorOrNil	An error (VisionErrorCode) or nil
*/
- (void)addImage:(nonnull UIImage*)inputImage relativeAttitude:(nonnull CMAttitude*)attitude prompt:(nonnull NSString*)prompt captureMethod:(nonnull NSString*)captureMethod otherParameters:(nonnull NSDictionary *)otherParameters completion:(void (^_Nonnull)(NSError* _Nullable error))completion;

/**
	@abstract Finalize computations after adding all images.
		Must be called from the main thread. Completion handler will be called on main thread.
	@param completion	Called after computation is complete
	@param errorOrNil	An error (VisionErrorCode) or nil
*/
- (void)finalizeWithCompletion:(void (^_Nonnull)(NSError* _Nullable errorOrNil))completion;

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



// Add this public method to expose the runner
//- (std::shared_ptr<AutoDepthRunner>)getRunner;

- (void*) getRunner;

@end
