//
//  ImageProcessor.h
//  Camera-oxilight
//
//  Created by Abhishek on 2017-05-11.
//  Copyright © 2017 Oxilight. All rights reserved.
//  Will be used to process images

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AppConstants.h"

@interface ImageProcessor : NSObject

-(id)init;
-(NSArray*)findHealXInUIImage:(UIImage*)img;
-(NSArray*)findHealXInCIImage:(CIImage*)img;
+(UIImage*)drawText:(NSString*)text inImage:(UIImage*)image atPoint:(CGPoint)point;
+(NSMutableArray*)getProcessedRectanglesFromCapture:(NSMutableArray*)capture;
+(BOOL)findRectangleInImage:(UIImage*)img;
+(NSArray*)findCirclesInImage:(UIImage*)img;
+(BOOL)shakingInRectangle:(NSMutableArray*)capture;
+(BOOL)shakingInCircle:(NSMutableArray*)capture;
+(NSMutableArray*)bestIntensityFromCapture:(NSMutableArray*)capture imageCountNeeded:(int)count;
//+(double)intensity:(UIImage*)img;
//+(UIImage*)realignCircleWithNoFlashSample:(UIImage*)noFlash FlashSample:(UIImage*)flash;
//+(UIImage*)realignReferenceWithNoFlashSample:(UIImage*)noFlash FlashSample:(UIImage*)flash;
//+(UIImage*)getCombinedImageFromRedImage:(UIImage*)red greenImage:(UIImage*)green blueImage:(UIImage*)blue;
//+(UIImage*)getSubtractedImageFromImage:(UIImage*)image ambientImage:(UIImage*)amb;
//+(UIImage*)getBlurredImageFromImage:(UIImage*)image sigmaX:(int)x sigmaY:(int)y;
+(UIImage*)rotateImage:(UIImage*)oldImage degree:(int)degrees;
+(UIImage*)orientImage:(UIImage*)oldImage orient:(UIImageOrientation)orientation;
+(UIImage*)createCircleMaskWithImage:(UIImage*)image circleXCoord:(int)x circleYCoord:(int)y circleRadius:(int)r;
+(UIImage*)cropImageAtPoint:(UIImage*)image xCoord:(int)x yCoord:(int)y radius:(int)r;
+(UIImage*)averagePixelsInImage:(UIImage*)image;
+(NSArray *)averagePixel:(UIImage *)picture;
+(BOOL)checkLightingForImages:(NSMutableArray *)pictures;
+(BOOL)checkLightFlashes:(NSMutableArray *)pictures;
+(UIImage*)getFluorescence:(UIImage*)img1 with:(UIImage*)img2;

+(double)getHeightOfImageInCm:(UIImage *)img healXRadius:(float)radiusPixels;
+(double)getCameraDistance:(float)fov height:(float)h;
+(NSArray*)getThermalROI:(float)d width:(int)width height:(int)height verticalFOV:(float)vfov circle:(NSArray*)circle;
+(NSArray*)getThermalROI:(float)d width:(int)width height:(int)height verticalFOV:(float)vfov;

+(UIImage*)addColorBar:(UIImage*)image colorBar:(UIImage*)colorBar;

// deleted old methods
//+(UIImage*)getRefImage;
//+(UIImage*)imageFromNSData:(NSData*) data;
//+(NSData*)dataFromUIImage:(UIImage*)img;
//+(UIImage*)createImage:(NSArray*)BGRA : (float)multiplier;

@end
