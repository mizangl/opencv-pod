//
//  VCameraNavigator.h
//  MedVision
//
//  Created by Narek Adamyan on 2018-11-29.
//  Copyright © 2018 Swift Medical. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <CoreMotion/CoreMotion.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, VCameraNavigatorStatus)
{
    CN_OK,
    CN_POOR_DEPTH_DATA_QUALITY,
    CN_TOO_CLOSE,
    CN_TOO_FAR,
    CN_NOT_IN_FRAME,
    CN_POOR_FOCUS
};

@interface VCameraNavigator : NSObject

/**
	@abstract Construct a new object with given reference image.

	@param referenceImage   The initial image taken with rear camera.
    @param fov              Field of view of the camera.
    @param attitude         Device orientation.
*/
-(nonnull instancetype) initWithReferenceImage:(nonnull UIImage*)referenceImage fov:(double)fov attitude:(nonnull CMAttitude*)attitude;

/**
	@abstract Test the given image and corresponding depth data against the reference image and navigation parameters.
		This is a blocking call. Must be called from the same thread as the constructor.

	@param image		Colour image to test.
	@param depthData	Depth data corresponding to the image.
    @param attitude     Device orientation.
*/
- (VCameraNavigatorStatus) checkImage:(nonnull UIImage*)image depthData:(nonnull AVDepthData*)depthData attitude:(nonnull CMAttitude*)attitude API_AVAILABLE(ios(11.0));

@end
