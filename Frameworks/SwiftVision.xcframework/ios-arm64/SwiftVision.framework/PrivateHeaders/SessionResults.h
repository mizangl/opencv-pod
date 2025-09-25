//
//  SessionResults.h
//  Camera-oxilight
//
//  Created by tian on 2017-10-18.
//  Copyright © 2017 Oxilight. All rights reserved.
//

#import "AppConstants.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <opencv2/core/core.hpp>

@interface SessionResults : NSObject <NSCopying>

-(id)init;

-(UIImage*)traceThermalGradientImage:(BOOL)showErythema showHighTemp:(BOOL)showHighTemp showLowTemp:(BOOL)showLowTemp;

-(void)setTappedPoint:(CGPoint) point;
-(CGPoint)tappedPoint;

-(float)dynamicRangeMultiplier;
-(void)setDynamicRangeMultiplier:(float)d;

-(void)setErythemaImage:(UIImage*)image;

-(enum testType)currTest;
-(void)setCurrTest: (enum testType)type;
-(void)setPixelTemp: (NSMutableArray*) data;

-(void)setDistance:(float)d;
-(void)setVerticalFOV:(float)fov;

-(BOOL)samplesExist;
-(NSMutableArray*)samples;
-(void)setSamples:(NSMutableArray*)capture;
-(void)setCroppedImage:(UIImage*)cropped;
-(void)setOriginalImageFullResWithUIImage:(UIImage*)fullRes;
-(UIImage*)originalImage;
-(UIImage*)originalImageFullRes;
-(UIImage*)redFlashImage;
-(UIImage*)greenFlashImage;
-(UIImage*)blueFlashImage;
-(UIImage*)reflectanceImage;
-(UIImage*)so2Image;
-(UIImage*)tHBImage;
-(UIImage*)fluorescenceImage;
-(UIImage*)bacteriaImage;
-(UIImage*)erythemaImage;
-(NSMutableArray*)so2Info;
-(NSMutableArray*)pixelTemp;
-(NSMutableArray*)epidermisInfoB;
-(NSMutableArray*)epidermisInfoG;
-(UIImage*)thermalImage;
-(UIImage*)thermalGradientImage;

-(UIImage*)epidermisImageB;
-(UIImage*)epidermisImageG;
-(void)processEpidermisThickness;


-(void)setExpectedX:(int)x Y:(int)y R:(int)r;

-(void)obtainBestIntensityImages: (int)count;
-(void)processReflectance: (UIImage*) ref;
-(void)processResultsFromReflectance;
-(void)processFluorescence;
-(void)processThermography;
-(void)traceErythema;
-(UIImage*)traceErythemaManual:(CGPoint)center;
-(void)processThermoDifferential: (float)avgTemp;
-(bool)detectInfection: (float)refTemp;
-(void)detectMaceration;

-(float)processThermoDifferentialAt: (CGPoint)point withRadius:(int)radius;
-(void) rotate90:(cv::Mat) img rotateAngle:(int) rotateAngle;

@end
