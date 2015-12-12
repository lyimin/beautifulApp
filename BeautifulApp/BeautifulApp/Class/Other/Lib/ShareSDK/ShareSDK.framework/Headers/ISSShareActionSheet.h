///#begin zh-cn
//
//  Created by ShareSDK.cn on 13-1-14.
//  官网地址:http://www.ShareSDK.cn
//  技术支持邮箱:support@sharesdk.cn
//  官方微信:ShareSDK   （如果发布新版本的话，我们将会第一时间通过微信将版本更新内容推送给您。如果使用过程中有任何问题，也可以通过微信与我们取得联系，我们将会在24小时内给予回复）
//  商务QQ:4006852216
//  Copyright (c) 2013年 ShareSDK.cn. All rights reserved.
//
///#end
///#begin en
//
//  Created by ShareSDK.cn on 13-1-14.
//  Website:http://www.ShareSDK.cn
//  Support E-mail:support@sharesdk.cn
//  WeChat ID:ShareSDK   （If publish a new version, we will be push the updates content of version to you. If you have any questions about the ShareSDK, you can get in touch through the WeChat with us, we will respond within 24 hours）
//  Business QQ:4006852216
//  Copyright (c) 2013年 ShareSDK.cn. All rights reserved.
//
///#end

#import <Foundation/Foundation.h>
#import "ISSContainer.h"
#import "ShareSDKTypeDef.h"

///#begin zh-cn
/**
 *	@brief	分享菜单协议
 */
///#end
///#begin en
/**
 *	@brief	Share menu protocol
 */
///#end
@protocol ISSShareActionSheet <NSObject>

///#begin zh-cn
/**
 *	@brief	显示分享菜单
 *
 *	@param 	container 	容器
 *	@param 	items 	分享菜单项列表
 *  @param  itemClickHandler    点击事件处理
 *  @param  cancelHandler   取消事件处理
 */
///#end
///#begin en
/**
 *	@brief	Show share menu.
 *
 *	@param 	container 	Container.
 *	@param 	items 	Share item list.
 *  @param  itemClickHandler    Item click event handler.
 *  @param  cancelHandler   Cancel button click event handler.
 */
///#end
- (void)showWithContainer:(id<ISSContainer>)container
                    items:(NSArray *)items
              onItemClick:(void (^)(ShareType shareType))itemClickHandler
                 onCancel:(void(^)())cancelHandler;


///#begin zh-cn
/**
 *	@brief	关闭菜单
 */
///#end
///#begin en
/**
 *	@brief	Dismiss menu.
 */
///#end
- (void)dismiss;

@end
