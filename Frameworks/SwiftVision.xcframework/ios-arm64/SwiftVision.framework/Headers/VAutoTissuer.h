//
//  VAutoTissuer.h
//  MedVision
//
//  Created by Justin Allport on 2020-12-29.
//  Copyright © 2020 Swift Medical. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "VSmartTissue.h"

@class VRegion;

/**
 * Automatically trace the wound in the given image.
 */
@interface VAutoTissuer : NSObject

/**
	@abstract Initialize with given NN model.
	@param model Tensor flow lite model data.
*/
- (nonnull instancetype)initWithModel:(nonnull NSData*)model;

/**
	@abstract Infer tissues and proportions for the given image.
	@param image The image of the wound.
	@param region The traced area or ROI of the wound
	@param completion Called with the semantic segmentation output and tissue percentage breakdowns on the main thread.
*/
- (void) tissuesForImage:(nonnull UIImage*)image withRegion:(nonnull VRegion*)region completionHandler:(void (^_Nonnull)(UIImage* _Nullable, NSArray* _Nullable, VSmartTissue* _Nullable))completion;

/**
	@abstract Return the version string of the loaded model.
	@return Nil if model is not loaded, the version string otherwise.
*/
- (nullable NSString*) modelVersion;

@end
