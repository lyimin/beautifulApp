//
//  MOBFImageService.h
//  MOBFoundation
//
//  Created by fenghj on 15/6/8.
//  Copyright (c) 2015年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MOBFImageServiceTypeDef.h"

/**
 *  图片服务
 */
@interface MOBFImageService : NSObject

/**
 *  获取共享图片服务实例
 *
 *  @return 图片服务实例
 */
+ (instancetype)sharedInstance;

/**
 *  获取图片数据
 *
 *  @param url              图片路径
 *  @param observer         观察者
 *  @param loadingHandler   加载中事件
 *  @param resultHandler    图片返回事件
 *  @param failHandler      图片加载失败事件
 */
- (void)getImageWithURL:(NSURL *)url
               observer:(id)observer
              onLoading:(MOBFImageServiceLoadingHandler)loadingHandler
               onResult:(MOBFImageServiceResultHandler)resultHandler
                 onFail:(MOBFImageServiceFailHandler)failHandler;


/**
 *  移除某个图片的观察者监听
 *
 *  @param observer 观察者
 *  @param url      图片路径
 */
- (void)removeObserver:(id)observer forURL:(NSURL *)url;

/**
 *  移除指定观察者的所有监听
 *
 *  @param observer 观察者
 */
- (void)removeObserver:(id)observer;

@end
