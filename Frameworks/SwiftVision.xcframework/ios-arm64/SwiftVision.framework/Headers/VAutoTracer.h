//
//  VAutoTracer.h
//  MedVision
//
//  Created by Narek Adamyan on 2019-06-10.
//  Copyright © 2019 Swift Medical. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class VRegion;

/**
 * Automatically trace the wound in the given image.
 */
@interface VAutoTracer : NSObject

/**
    @abstract Initialize with given NN model.
    @param model Tensor flow lite model data.
*/
- (nonnull instancetype)initWithModel:(nonnull NSData*)model;

/**
    @abstract Trace the given image.
    @param image The image of the wound.
    @param completion Called with the trace region on the main thread.
*/
- (void) regionForImage:(nonnull UIImage*)image completionHandler:(void (^_Nonnull)(VRegion* _Nullable))completion;

/**
    @abstract Return the version string of the loaded model.
    @return Nil if model is not loaded, the version string otherwise.
*/
- (nullable NSString*) modelVersion;

@end
