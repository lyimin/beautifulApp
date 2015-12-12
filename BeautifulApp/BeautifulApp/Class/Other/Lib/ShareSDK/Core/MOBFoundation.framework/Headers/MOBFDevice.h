//
//  MOBFDeviceUtils.h
//  MOBFoundation
//
//  Created by vimfung on 15-1-19.
//  Copyright (c) 2015年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 *  网络类型
 */
typedef NS_ENUM(NSUInteger, MOBFNetworkType)
{
    /**
     *  无网咯
     */
    MOBFNetworkTypeNone         = 0,
    /**
     *  蜂窝网络
     */
    MOBFNetworkTypeCellular     = 1,
    /**
     *  WIFI
     */
    MOBFNetworkTypeWifi         = 2,
    /**
     *  2G网络
     */
    MOBFNetworkTypeCellular2G   = 3,
    /**
     *  3G网络
     */
    MOBFNetworkTypeCellular3G   = 4,
    /**
     *  4G网络
     */
    MOBFNetworkTypeCellular4G   = 5,
};

/**
 *  设备工具类
 */
@interface MOBFDevice : NSObject

/**
 *  获取网卡物理地址
 *
 *  @return 网卡物理地址
 */
+ (NSString *)macAddress;

/**
 *  获取设备型号
 *
 *  @return 设备型号
 */
+ (NSString *)deviceModel;

/**
 *  获取当前网络类型
 *
 *  @return 网络类型
 */
+ (MOBFNetworkType)currentNetworkType;

/**
 *  获取手机运营商代码
 *
 *  @return 手机运营商代码
 */
+ (NSString *)carrier;

/**
 *  与当前系统版本比较
 *
 *  @param other 需要对比的版本
 *
 *  @return < 0 低于指定版本； = 0 跟指定版本相同；> 0 高于指定版本
 */
+ (NSInteger)versionCompare:(NSString *)other;

/**
 *  判断是否已经越狱
 *
 *  @return YES 已经越狱，NO 尚未越狱
 */
+ (BOOL)hasJailBroken;

/**
 *  获取运行进程信息
 *
 *  @return 进程信息列表
 */
+ (NSArray *)runningProcesses;

/**
 *  判断当前设备是否为iPad
 *
 *  @return YES 是，NO 否
 */
+ (BOOL)isPad;

/**
 *  获取设备唯一标识
 *
 *  @return 标识码
 */
+ (NSString *)duid;

/**
 *  判断当前设备是否有麦克风
 *
 *  @return YES 有，NO 没有
 */
+ (BOOL)hasMicrophone;

/**
 *  判断是否存在指定音频线路
 *
 *  @param type 类型
 *
 *  @return YES 存在，NO 不存在
 */
+ (BOOL)hasAudioRouteWithType:(NSString *)type;

/**
 *  获取屏幕真实尺寸
 *
 *  @return 屏幕尺寸
 */
+ (CGSize)nativeScreenSize;

/**
 *  获取无线局域网的服务集标识（WIFI名称）
 *
 *  @return 服务集标识
 */
+ (NSString *)ssid;

/**
 *  获取基础服务集标识（站点的MAC地址）
 *
 *  @return 基础服务集标识
 */
+ (NSString *)bssid;

/**
 *  获取广告商ID
 *
 *  @return 广告商ID
 */
+ (NSString *)idfa;

@end
