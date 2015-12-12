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
#import "ShareSDKTypeDef.h"

///#begin zh-cn
/**
 *	@brief	视图委托协议
 */
///#end
///#begin en
/**
 *	@brief  View delegate protocol.
 */
///#end
@protocol ISSViewDelegate <NSObject>

@optional

///#begin zh-cn
/**
 *	@brief	视图将要显示
 *
 *	@param 	viewController 	视图控制器
 *  @param  shareType   分享类型
 */
///#end
///#begin en
/**
 *	@brief	View will display.
 *
 *	@param 	viewController 	View controller.
 *  @param  shareType   Platform type.
 */
///#end
- (void)viewOnWillDisplay:(UIViewController *)viewController shareType:(ShareType)shareType;

///#begin zh-cn
/**
 *	@brief	视图将要关闭
 *
 *	@param 	viewController 	视图控制器
 *  @param  shareType   分享类型
 */
///#end
///#begin en
/**
 *	@brief	View will dismiss.
 *
 *	@param 	viewController 	View controller.
 *  @param  shareType   Platform type.
 */
///#end
- (void)viewOnWillDismiss:(UIViewController *)viewController shareType:(ShareType)shareType;

///#begin zh-cn
/**
 *	@brief	视图旋转到某个方向
 *
 *  @param  viewController    视图控制器
 *	@param 	toInterfaceOrientation 	设备方向
 *  @param  shareType   分享类型
 */
///#end
///#begin en
/**
 *	@brief	Rotate the view to a certain direction
 *
 *  @param  viewController    View controller.
 *	@param 	toInterfaceOrientation 	Interface orientation.
 *  @param  shareType   Platform type.
 */
///#end
- (void)view:(UIViewController *)viewController autorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation shareType:(ShareType)shareType;

@optional

/**
 *  获取发送邮件响应码
 */
//- (void)getShareResponseState;

@end
