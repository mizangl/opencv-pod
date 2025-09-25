//
//  VisionError.h
//  Metrics
//
//  Created by Dave Fernandes on 2017-10-02.
//  Copyright © 2017 Swift. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString* VisionErrorDomain;

typedef NS_ENUM(NSInteger, VisionErrorCode)
{
    VisionError_OK = 0,                     // No error occurred
    VisionError_CANCELLED = 1,              // Operation was cancelled
    VisionError_INVALID_CALL = 2,           // Methods have not been called in proper sequence

    VisionError_FIDUCIAL_MISSING = 10,      // The reference image fiducial is missing
    VisionError_IMAGE_BLURRED = 11,         // The reference image is blurred
    VisionError_TOO_FEW_IMAGES = 12,        // Too few images were provided to calculate depth
    VisionError_BAD_DEPTH_MAP = 13,         // Too many missing points in the depth map for depth estimation
    VisionError_TOO_FEW_FEATURES = 14,      // Too few features were detected from image
    VisionError_TOO_FEW_CONTOUR_POINTS = 15,// Too few contour points
    VisionError_DEPTH_MAP_FAILED = 16,      // Could not build depth map
    VisionError_NO_SPARSE_POINTS = 17,      // Could not find sparse 3-D points
    VisionError_BUNDLE_ADJUST_FAILED = 18,  // Bundle adjustment failed
    VisionError_TOO_FEW_MATCHES = 19,       // Too few feature matches were detected with reference image
    VisionError_TOO_DEEP = 20,              // Computed depth greater than max depth
    VisionError_TOO_FEW_CONTOUR_SURFELS = 22, // Too few contour surfels
    VisionError_NO_DENSE_POINTS = 23,       // No dense points
    VisionError_NO_DEPTH_POINTS = 24,       // No depth points found. Empty depth map
    VisionError_BAD_FIDUCIAL_ASPECT_RATIO = 25, // Aspect ratio of the fiducial is off range
    VisionError_TOO_SHALLOW = 26,           // Computed depth less than min value
    VisionError_NO_FEATURES_REFERENCE = 27, // The reference image has no features
};
