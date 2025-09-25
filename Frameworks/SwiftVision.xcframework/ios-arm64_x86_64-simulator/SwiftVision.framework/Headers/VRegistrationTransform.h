//
//  VRegistrationTransform.h
//  Metrics
//
//  Created by Dave Fernandes on 2017-11-23.
//  Copyright © 2017 Swift. All rights reserved.
//

#import <Foundation/Foundation.h>


/// Container for registration results
@interface VRegistrationTransform : NSObject

- (nonnull instancetype)initWithJSON:(nonnull NSString*)jsonStr;
- (nonnull instancetype)initWithJSONArray:(nonnull NSString*)jsonStr;

@end
