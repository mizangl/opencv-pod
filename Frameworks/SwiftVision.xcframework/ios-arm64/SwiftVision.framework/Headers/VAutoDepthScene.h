//
//  VAutoDepthScene.h
//  SwiftVision
//
//  Created by Narek Adamyan on 2020-01-03.
//  Copyright © 2020 Swift Medical Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SceneKit/SceneKit.h>

@class VDepthEstimator;

/// Helper class for visualizing AutoDepth reconstruction.
@interface VAutoDepthScene: NSObject

// MARK: Configuration Options

/// Turn On/Off the lid.
@property (nonatomic, readwrite) Boolean showLid;

/// Turn On/Off filtering
@property (nonatomic, readwrite) Boolean filterModel;

/// Current texture for the main model.
@property (nonatomic, readwrite) NSString* _Nonnull texture;

/// List of channels for the main model.
@property (nonatomic, readonly) NSArray<NSString*>* _Nonnull textures;

// MARK: Constructor

/// Scene objet that can be shown in the viewer.
@property (nonatomic, readonly) SCNScene* _Nonnull scene;

/**
	@abstract Construct scene with depth estimator
	@param estimator         Depth estimator containing the reconstruction results.
*/
-(nonnull instancetype)initWith:(nonnull VDepthEstimator*)estimator;


@end
