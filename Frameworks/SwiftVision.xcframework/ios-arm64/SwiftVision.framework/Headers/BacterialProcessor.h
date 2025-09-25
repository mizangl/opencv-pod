#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface BacterialProcessor : NSObject

-(id)init;

-(NSMutableArray *)bacterialOf: (NSMutableArray *)images;
-(bool)isImagesOverlit: (NSMutableArray *)images;
-(bool)isShakingInImages: (NSMutableArray *)images;

@end
