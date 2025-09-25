#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "VRegion.h"

@interface ThermalProcessor : NSObject
-(nonnull NSArray *)processThermography:(nonnull UIImage*)image pixelTemp: (nonnull NSArray*)pixelTemp avgTemp: (float) avgTemp;
-(float) calulateAvgTempAt: (CGPoint)point withRadius:(int)radius pixelTemp: (nonnull NSArray*)pixelTemp;
-(float) calculateAvgTempOfWoundBed:(nonnull NSArray*)pixelTemp tracePolygons: (VRegion*) trace;
-(UIImage *)rotateImage:(UIImage *)image radians:(CGFloat)radians;
@end
