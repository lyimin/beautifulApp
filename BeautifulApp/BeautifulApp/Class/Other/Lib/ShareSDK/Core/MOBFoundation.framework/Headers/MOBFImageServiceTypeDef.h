//
//  MOBFImageServiceTypeDef.h
//  MOBFoundation
//
//  Created by fenghj on 15/6/8.
//  Copyright (c) 2015年 MOB. All rights reserved.
//

#ifndef MOBFoundation_MOBFImageServiceTypeDef_h
#define MOBFoundation_MOBFImageServiceTypeDef_h

/**
 *  图片加载返回事件
 *
 *  @param imageData 图片数据
 */
typedef void (^MOBFImageServiceResultHandler) (NSData *imageData);

/**
 *  图片加载失败事件
 *
 *  @param error 错误信息
 */
typedef void (^MOBFImageServiceFailHandler) (NSError *error);

/**
 *  图片加载中事件
 */
typedef void (^MOBFImageServiceLoadingHandler) ();

#endif
