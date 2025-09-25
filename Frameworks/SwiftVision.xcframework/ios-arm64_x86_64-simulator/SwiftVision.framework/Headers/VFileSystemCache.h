//
//  VFileSystemCache.h
//  MedVision
//
//  Created by Narek Adamyan on 2019-07-09.
//  Copyright © 2019 Swift Medical. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VFileSystemCache : NSObject

typedef NSDictionary<NSString*, NSString*> MetadataDictionary;

/**
 * @brief Create file system cache with given configuration parameters.
 *
 * @param rootLocation File system directory of the cache.
 * @param params Configuration parameters.
 *
 * @todo List supported parameters here.
 */
- (nonnull instancetype) initWithRootLocation:(nonnull NSString*)rootLocation
                                   parameters:(nonnull NSDictionary*)params;

/**
 * @brief Add an object to the cache.
 *
 * @param data Data to be stored.
 * @param key Unique ID of the object.
 * @param keep Do not expire this object and do not remove when making room for other objects.
 * @param metadata Optional string to string dictionary stored with the object.
 * @param completion Optional completion block (called from a background thread).
 *
 * @note Metadata is stored on file system in unencrypted form.
 */
- (void) add:(nonnull NSData*)data
     withKey:(nonnull NSString*)key
        keep:(BOOL)keep
    metadata:(nullable MetadataDictionary*)metadata
  completion:(void (^_Nullable) (void))completion;

/**
 * @brief Remove object with the given key if exists.
 *
 * @param key Unique ID of the object.
 * @param completion Optional completion block (called from a background thread).
 */
- (void) remove:(nonnull NSString*)key
     completion:(void (^_Nullable) (void))completion;

/**
 * @brief Load object from the cache.
 *
 * @param key Unique ID of the object.
 * @param completion Completion block (called from a background thread) with object or null if it's not persisted in the cache.
 */
- (void) restore:(nonnull NSString*)key
      completion:(void (^_Nonnull) (NSData* _Nullable data , MetadataDictionary* _Nullable metadata))completion;

/**
 * @brief Get the current size of the cache.
 *
 * @param completion Completion block (called from a background thread) with the size of the cache in bytes.
 */
- (void) size:(void (^_Nonnull) (NSUInteger))completion;

@end
