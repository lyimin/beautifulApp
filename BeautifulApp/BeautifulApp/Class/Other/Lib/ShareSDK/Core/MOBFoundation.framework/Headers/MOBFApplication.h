//
//  MOBFApplicationUtils.h
//  MOBFoundation
//
//  Created by vimfung on 15-1-20.
//  Copyright (c) 2015年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  应用工具类
 */
@interface MOBFApplication : NSObject

/**
 *  获取应用包名
 *
 *  @return 包名
 */
+ (NSString *)bundleId;

/**
 *  获取应用版本号
 *
 *  @return 版本号
 */
+ (NSString *)version;

/**
 *  检测是否启用ATS功能
 */
+ (BOOL)enabledATS;

@end
