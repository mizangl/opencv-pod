//
//  CVWrapper.h
//  Camera-oxilight
//
//  Created by Abhishek on 2017-07-04.
//  Copyright © 2017 Oxilight. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <opencv2/core/core.hpp>
#import "VRegion.h"

@interface CVWrapper : NSObject

+(UIImage*)drawText:(NSString*)text inImage:(UIImage*)image atPoint:(CGPoint)point;
+(cv::Mat)mult:(cv::Mat)m1 m2:(cv::Mat)m2;
+(UIImage*)resizeImage:(UIImage*)originalImage toSize:(CGSize)size;
+(std::vector<cv::Mat>)produceEpidermisThicknessImage:(cv::Mat)refl dynamicRangeMultiplier:(float)drm;

+(cv::Mat)CVMatFromUIImage:(UIImage *)image;
+(cv::Mat)CVMatFromUIImageForBacterial:(UIImage*)image;
+(UIImage*)UIImageFromCVMat:(cv::Mat)cvMat;
+(double)calculateAverageIntensityOfImage:(UIImage*)image;
+(NSArray*)findSquareInImage:(UIImage*)img;
+(BOOL)foundRectangleInImage:(UIImage*)image;
//+(NSArray*)findCirclesHoughAlgInImage:(UIImage*)image;
+(NSArray*)findCirclesRingedInImage:(UIImage*)image;
+(cv::Mat)combineRedImage:(UIImage*)red GreenImage:(UIImage*)green BlueImage:(UIImage*)blue;
+(cv::Mat)produceReflectanceFromCombined:(cv::Mat)rgbMat ambient:(UIImage*)amb reference:(UIImage*)ref dynamicRangeMultiplier:(float)drm circleXCoord:(int)x circleYCoord:(int)y circleRadius:(int)r;
+(std::vector<cv::Mat>)produceResultImageFromReflectance:(cv::Mat)refl dynamicRangeMultiplier:(float)drm;
+(cv::Mat)produceFluorescence:(UIImage *)fluo ambient:(UIImage*)amb;
+(UIImage*)shiftImage:(UIImage*)img deltaX:(int)x deltaY:(int)y;
+(cv::Mat)detectErythema:(UIImage *)image threshold:(float)z;
+(cv::Mat)detectErythemaManual:(UIImage *)image threshold:(float)z center:(CGPoint)point;
+(cv::Mat)detectMaceration:(UIImage *)image;

+(cv::Mat)subtractFromImage:(UIImage*)image ambientImage:(UIImage*)amb;
+(cv::Mat)blurImage:(UIImage*)img sigmaX:(int)sigX sigmaY:(int)sigY;

+(cv::Mat)registerEpidermisImage:(cv::Mat)originalImage thicknessImage:(cv::Mat)thicknessImage;
+(std::vector<cv::Mat>)registerImages:(cv::Mat)originalImage thermal:(cv::Mat)thermalImage;
+(double)getHeightOfImageInCm:(UIImage *)img healXRadius:(float)radiusPixels;
+(double)getCameraDistance:(float)fov height:(float)h;
+(NSArray*)getThermalROI:(float)d width:(int)width height:(int)height verticalFOV:(float)vfov circle:(NSArray*)circle;
+(NSArray*)getThermalROI:(float)d width:(int)width height:(int)height verticalFOV:(float)vfov;

//+(double)getAngleAboutVertex:(cv::Point)vertex FirstVector:(cv::Point)pt1 SecondVector:(cv::Point)pt2;
//+(cv::Mat)getChannelFromImage:(UIImage*)img channel:(int)ch;
+(cv::Mat)KMTransformMatrix:(cv::Mat)matrix;
+(cv::Mat)affineTransformMatrix:(cv::Mat)mat referenceMatrix:(cv::Mat)rMat vector:(cv::Mat)vec;
+(cv::Mat)getOxygenationFromChromophore:(cv::Mat)chro;
+(cv::Mat)getTotalHemoglobinFromChromophore:(cv::Mat)chro;
+(BOOL)overLit:(UIImage *)image;
+(BOOL)channelNotLit:(NSMutableArray *)images;
+(NSArray *)averagePixel: (UIImage *)image;
+(NSMutableArray *)getSo2Info;
+(NSMutableArray *)getEpidermisInfoB;
+(NSMutableArray *)getEpidermisInfoG;

+ (float)calulateAvgTempAt: (CGPoint)point withRadius:(int)radius pixelTemp: (nonnull NSArray*)pixelTemp;
+ (float)calculateAvgTempOfWoundBed:(nonnull NSArray*)pixelTemp tracePolygons: (VRegion*) trace;
+ (void) rotate90:(nonnull cv::Mat*) img rotateAngle:(int) rotateAngle;

@end
