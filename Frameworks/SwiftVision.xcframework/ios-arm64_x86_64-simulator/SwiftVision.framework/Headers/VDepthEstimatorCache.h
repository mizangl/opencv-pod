//
//  VDepthEstimatorCache.h
//  MedVision
//
//  Created by Narek Adamyan on 2019-04-17.
//  Copyright © 2019 Swift Medical. All rights reserved.
//

#import <Foundation/Foundation.h>

@class VDepthEstimator;

/// Cache for storing and restoring auto-depth calculations allowing to recalculate with updated region.
@interface VDepthEstimatorCache : NSObject

/**
 * @brief Create auto-depth cache with given configuration parameters.
 *
 * @param rootLocation File system location of the cache.
 * @param params Configuration parameters.
 *
 * @todo List supported parameters here.
 */
- (nonnull instancetype) initWithRootLocation:(nonnull NSString*)rootLocation parameters:(nonnull NSDictionary*)params;

/**
 * @brief Add depth estimator to the cache.
 *
 * @param revisionId Unique ID of the associated revision.
 * @param estimator Capture the state of this depth estimator object.
 * @param completion Optional completion block called on the main thread.
 */
- (void) add:(nonnull NSString*)revisionId estimator:(nonnull VDepthEstimator*)estimator completion:(void (^_Nullable) (void))completion;

/**
 * @brief Remove any cached data for the given revision.
 *
 * @param revisionId Unique ID of the associated revision.
 * @param completion Optional completion block called on the main thread.
 */
- (void) remove:(nonnull NSString*)revisionId completion:(void (^_Nullable) (void))completion;

/**
 * @brief Restore depth estimator from the cache.
 *
 * @param revisionId Unique ID of the associated revision.
 * @param completion Completion block called on the main thread with restored depth estimator object or null if it's not persisted in the cache.
 */
- (void) restore:(nonnull NSString*)revisionId completion:(void (^_Nonnull) (VDepthEstimator* _Nullable))completion;

@end
