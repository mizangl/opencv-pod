//
//  SwiftVision.h
//  Metrics
//
//  Created by Dave Fernandes on 2017-11-24.
//  Copyright © 2017 Swift. All rights reserved.
//

#ifndef SwiftVision_h
#define SwiftVision_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "VTypes.h"
#import "VAutoDepthRunner.h"
#import "VisionMeasures.h"
#import "VRegion.h"
#import "VWoundDepth.h"
#import "VWoundTunnelling.h"
#import "VWoundUndermining.h"
#import "VAnalysis.h"
#import "VFiducial.h"
#import "VFiducialDetector.h"
#import "VFeatureTracker.h"
#import "VEvolution.h"
#import "VRegistrationTransform.h"
#import "VColorBalanceTransform.h"
#import "VPolygon.h"
#import "VisionError.h"
#import "VDepthEstimator.h"
#import "VTrackPoint.h"
#import "VEdge.h"
#import "VDepthEstimatorCache.h"
#import "VBaseDepthEstimator.h"
#import "VAutoTracer.h"
#import "VAutoTissuer.h"
#import "VFileSystemCache.h"
#import "VAutoDepthScene.h"
#import "VCameraNavigator.h"
#import "VTrueDepthEstimator.h"
#import "VAutoEnhance.h"
#import "VExposureCompensator.h"
#import "ThermalProcessor.h"
#import "BacterialProcessor.h"
#import "VSmartTissue.h"
#import "RayHelperWrapper.h"

// Static functions to retrieve versions
NSString* regisVersion(void);
NSString* analysisVersion(void);
NSComparisonResult compareCurrentVersionWithObject(NSString* objectJSON, VVersionSkipLevel skipLevel);

#endif /* SwiftVision_h */

