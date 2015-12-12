//
//  MOBFMediaUtils.h
//  MOBFoundation
//
//  Created by vimfung on 15-1-19.
//  Copyright (c) 2015年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  媒体工具类
 */
@interface MOBFMedia : NSObject

/**
 *  压缩视频
 *
 *  @param path            原始视频路径
 *  @param destPath        目标视频路径
 *  @param finishedHandler 完成回调
 */
+ (void)compressVideoWithPath:(NSString *)path
                     destPath:(NSString *)destPath
                     finished:(void(^)())finishedHandler;


/**
 *  裁剪视频
 *
 *  @param path      原始视频路径
 *  @param destPath  目标视频路径
 *  @param startTime 裁剪起始时间
 *  @param endTime   裁剪结束时间
 *  @param handler   返回事件处理
 */
+ (void)trimVideoWithPath:(NSString *)path
                 destPath:(NSString *)destPath
                startTime:(NSTimeInterval)startTime
                  endTime:(NSTimeInterval)endTime
                   result:(void(^)(BOOL successed, NSError *error))handler;

/**
 *  合并视频
 *
 *  @param paths    原始视频路径列表
 *  @param destPath 目标视频路径
 *  @param handler  返回事件处理
 */
+ (void)mergeVideosWithPaths:(NSArray *)paths
                    destPath:(NSString *)destPath
                      result:(void(^)(BOOL successed, NSError *error))handler;

/**
 *  拼接视频
 *
 *  @param paths    原始视频路径列表
 *  @param destPath 目标视频路径
 *  @param handler  返回事件处理
 */
+ (void)concatVideosWithPaths:(NSArray *)paths
                     destPath:(NSString *)destPath
                       result:(void(^)(BOOL successed, NSError *error))handler;

@end
