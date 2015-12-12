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
#import "ISSViewDelegate.h"
#import "ISSContent.h"

///#begin zh-cn
/**
 *	@brief	分享视图委托
 */
///#end
///#begin en
/**
 *	@brief	Share view delegate protocol
 */
///#end
@protocol ISSShareViewDelegate <ISSViewDelegate>

@optional

///#begin zh-cn
/**
 *	@brief	将要分享内容
 *
 *  @since  ver2.2.0    已过时
 *
 *  @deprecated     已过时，推荐使用- (id<ISSContent>)view:willPublishContent:shareList:;方法代替
 *
 *	@param 	viewController 	视图控制器
 *	@param 	content 	内容
 *  @param  shareList   将要分享的平台列表
 *
 *	@return	实际发送的内容
 */
///#end
///#begin en
/**
 *	@brief	Will publish content
 *
 *  @since  ver2.2.0    deprecated
 *
 *  @deprecated     Deprecated.Recommended use - (id <ISSContent>) view: willPublishContent: shareList:; method instead.
 *
 *	@param 	viewController 	View controller.
 *	@param 	content 	Share content object.
 *  @param  shareList   Platform list.
 *
 *	@return	The actual transmission of the content object.
 */
///#end
- (id<ISSContent>)view:(UIViewController *)viewController
    willPublishContent:(id<ISSContent>)content;

///#begin zh-cn
/**
 *	@brief	将要分享内容
 *
 *  @since  ver2.2.0
 *
 *	@param 	viewController 	视图控制器
 *	@param 	content 	内容
 *  @param  shareList   将要分享的平台列表
 *
 *	@return	实际发送的内容
 */
///#end
///#begin en
/**
 *	@brief	Will publish content
 *
 *  @since  ver2.2.0
 *
 *	@param 	viewController 	View controller
 *	@param 	content 	Share content object.
 *  @param  shareList   Platform list.
 *
 *	@return	The actual transmission of the content object.
 */
///#end
- (id<ISSContent>)view:(UIViewController *)viewController
    willPublishContent:(id<ISSContent>)content
             shareList:(NSArray *)shareList;

///#begin zh-cn
/**
 *	@brief	视图取消发布
 *
 *	@param 	viewController 	视图控制器
 */
///#end
///#begin en
/**
 *	@brief	Cancel publish
 *
 *	@param 	viewController 	View controller.
 */
///#end
- (void)viewOnCancelPublish:(UIViewController *)viewController;

@end
