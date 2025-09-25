//
//  VFiducialDetector.h
//  Metrics
//
//  Created by Dave Fernandes on 2017-09-27.
//  Copyright © 2017 Swift. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class VFiducial;


/**
	@abstract This class is used for live fiducial detection. Once created,
	it may be used for multiple fiducial detections. All methods and properties
	should be accessed from the same thread (not the main thread).
*/
@interface VFiducialDetector : NSObject

/// Detected fiducials. Valid after a call to findFiducialsInImage
@property (nonatomic, strong, readonly, nonnull) NSArray<VFiducial*>* fiducials;

/// Is the image valid for acquisition? Flag is set after a call to findFiducialsInImage
@property (readonly) BOOL isValidImage;

/// Used to hold the current processing image width and height
@property (nonatomic, assign) NSInteger imageHeight;
@property (nonatomic, assign) NSInteger imageWidth;
@property (nonatomic, assign) double FOV;

/// Number of fiducials required for a valid image
@property (readonly) NSInteger requiredFiducialCount;

/**
	@abstract Initialize the detector. Fiducials will not be detected in this call.
	@param width	Width of images in pixels
	@param height	Height of images in pixels
    @param fov		camera field of view
	@param count	Number of fiducials required for a valid image
*/
- (nonnull instancetype)initForWidth:(NSInteger)width height:(NSInteger)height FOV:(double)FOV requiredFiducialCount:(NSInteger)count;

/**
	@abstract Detect fiducials in an image and set flags.
	@note This method is NOT re-entrant. All calls must be synchronous from the same thread.
	@param image Image used to find fiducials
*/
- (void)findFiducialsInImage:(nonnull UIImage*)scaledImage;

@end

@interface VFiducialDetector (Vision)

/**
	@abstract Detect fiducials in an image and set flags.
	@note This method is NOT re-entrant. All calls must be synchronous from the same thread.
	@param image Image used to find fiducials
*/
- (void)findFiducialsInCIImage:(nonnull CIImage*)image;

@end
