//
//  VExposureCompensator.h
//  MedVision
//
//  Created by justin on 2018-12-31.
//  Copyright © 2018 Swift Medical. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface VExposureCompensator : NSObject

///**
// @abstract Initialize the detector. Features will not be detected in this call.
// @param width    Width of images in pixels
// @param height    Height of images in pixels
// @param count    Number of features deisired to track
// @param minCount   Minimum number of features required to be tracked to indicate success
// */
- (nonnull instancetype)initForExposureCompensation;


/**
 @abstract adjust exposure of the input image.
 @note This method is NOT re-entrant. All calls must be synchronous from the same thread.
 @param image Image to be adjusted
 */
- (UIImage*_Nullable)adjustExposureOfImage:(nonnull UIImage*)image;

/**
 @absrtact get the raw image illumination
 @note This method SHOULD be called after adjustExpsoureOfImage as the value relates to that image
 */
- (float)getRawImgIllumination;

@end

@interface VExposureCompensator (Vision)

/**
 @abstract Track features in an image and set flags
 @note This method is NOT re-entrant. All calls must be synchronous from the same thread.
 @param image Image used to find fiducials
 */
- (UIImage*_Nullable)adjustExposureOfCIImage:(nonnull CIImage*)image;

@end
