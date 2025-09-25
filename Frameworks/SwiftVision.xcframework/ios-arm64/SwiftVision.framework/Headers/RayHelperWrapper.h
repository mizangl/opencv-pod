//
//  RayHelperWrapper.h
//  
//
//  Created by Zheng Liu on 2025-05-30.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface RayHelperWrapper : NSObject

+(UIImage*)RayCropImage:(UIImage*)image topLeftCol:(int)topLeftCol topLeftRow:(int)topLeftRow width:(int)width height:(int)height;
+(NSArray*)RayGetThermalROI:(float)d width:(int)width height:(int)height verticalFOV:(float)vfov;
+(double)RayGetHeightOfImageInCm:(float)heightPixels healXRadius:(float)radiusPixels;
+(BOOL)RayOverLit:(UIImage *)image;
+(double)RayGetCameraDistance:(float)fov height:(float)h;

@end
