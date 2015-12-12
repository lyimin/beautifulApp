//
//  MOBFDebug.h
//  MOBFoundation
//
//  Created by 冯 鸿杰 on 15/2/4.
//  Copyright (c) 2015年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, MOBFDebugLevel)
{
    MOBFDebugLevelApp   = 0x0001,
};

/**
 *  调试工具类
 */
@interface MOBFDebug : NSObject

/**
 *  启用调试模式
 *
 *  @param enabled YES 启用调试，NO 禁用调试模式
 */
+ (void)enabledDebug:(BOOL)enabled;

/**
 *  启动调试模式
 *
 *  @param enabled YES 启动调试，NO 禁用调试模式
 *  @param level   调试级别
 */
+ (void)enabledDebug:(BOOL)enabled
               level:(MOBFDebugLevel)level;

/**
 *  输出调试日志
 *
 *  @param format 日志格式
 *  @param ... 日志参数
 */
+ (void)log:(NSString *)format,...NS_FORMAT_FUNCTION(1,2);

/**
 *  输出调试日志
 *
 *  @param format 日志格式
 */
+ (void)sdkLog:(NSString *)format,...NS_FORMAT_FUNCTION(1,2);

@end
