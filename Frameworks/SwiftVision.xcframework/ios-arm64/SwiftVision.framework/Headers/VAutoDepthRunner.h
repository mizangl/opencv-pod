//
//  VAutoDepthRunner.h
//  MedVision
//
//  Created by Narek Adamyan on 2019-02-02.
//  Copyright © 2019 Swift Medical. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "VisionError.h"

NS_ASSUME_NONNULL_BEGIN

@protocol VAutoDepthDelegate<NSObject>

- (void) log: (NSString*)message;
- (void) completed: (VisionErrorCode)code;

@end

@interface VAutoDepthRunner : NSObject

- (instancetype)initWithOutput: (NSURL*)output delegate: (id<VAutoDepthDelegate>)delegate;

- (void)runWithPath: (NSURL*)path;
- (void)cancel;
- (float)getProgress;

@end

NS_ASSUME_NONNULL_END
