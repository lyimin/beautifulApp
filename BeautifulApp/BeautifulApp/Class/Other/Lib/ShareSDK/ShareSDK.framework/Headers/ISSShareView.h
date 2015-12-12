//
//  ISSShareView.h
//  ShareSDK
//
//  Created by 冯 鸿杰 on 13-4-8.
//  Copyright (c) 2013年 掌淘科技. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ISSContainer.h"
#import "ShareSDKTypeDef.h"
#import "ISSContent.h"
#import "ISSAuthOptions.h"
#import "ISSShareOptions.h"

/**
 *	@brief	分享视图协议
 */
@protocol ISSShareView <NSObject>

/**
 *	@brief	显示分享视图
 *
 *	@param 	container 	容器
 *	@param 	content 	分享内容
 *	@param 	shareType 	平台类型
 *  @param  statusBarTips   状态栏提示
 *	@param 	authOptions     授权选项
 *	@param 	shareOptions    分享选项
 *  @param  result      返回回调
 */
- (void)showInContainer:(id<ISSContainer>)container
                content:(id<ISSContent>)content
              shareType:(ShareType)shareType
          statusBarTips:(BOOL)statusBarTips
            authOptions:(id<ISSAuthOptions>)authOptions
           shareOptions:(id<ISSShareOptions>)shareOptions
                 result:(void(^)(SSResponseState state, id<ISSContent> content, NSArray *shareApps, id<ICMErrorInfo> error))result;

/**
 *	@brief	关闭视图
 */
- (void)dismiss;

@end
