//
//  SPObjectMappingBase.h
//  SPTest
//
//  Created by Nathan Wood on 12/02/13.
//  Copyright (c) 2013 Nathan Wood. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SPObjectMapping.h"

@interface SPObjectMappingBase : NSObject <SPObjectMapping, NSCoding>

- (void)mapKeyPath:(NSString *)keyPath toAttribute:(NSString *)attribute;
- (void)removeMappingForKeyPath:(NSString *)keyPath;

@end