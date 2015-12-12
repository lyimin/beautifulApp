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
//  website:http://www.ShareSDK.cn
//  Support E-mail:support@sharesdk.cn
//  WeChat ID:ShareSDK   （If publish a new version, we will be push the updates content of version to you. If you have any questions about the ShareSDK, you can get in touch through the WeChat with us, we will respond within 24 hours）
//  Business QQ:4006852216
//  Copyright (c) 2013年 ShareSDK.cn. All rights reserved.
//
///#end

#import <Foundation/Foundation.h>
#import "ISSiPadViewController.h"

///#begin zh-cn
/**
 *	@brief	容器对象
 */
///#end
///#begin en
/**
 *	@brief	Container object procotol.
 */
///#end
@protocol ISSContainer <NSObject>

@required

///#begin zh-cn
/**
 *	@brief	获取iPhone视图容器控制器
 *
 *	@return	视图控制器
 */
///#end
///#begin en
/**
 *	@brief	Get iPhone container controller.
 *
 *	@return	View controller.
 */
///#end
- (UIViewController *)iPhoneViewController;

///#begin zh-cn
/**
 *	@brief	获取iPad视图容器控制器
 *
 *	@return	视图控制器
 */
///#end
///#begin en
/**
 *	@brief	Get iPad container controller.
 *
 *	@return	View controller.
 */
///#end
- (id<ISSiPadViewController>)iPadViewController;

///#begin zh-cn
/**
 *	@brief	设置iPhone显示容器
 *
 *	@param 	viewController 	视图控制器
 */
///#end
///#begin en
/**
 *	@brief	Set iPhone container controller.
 *
 *	@param 	viewController 	View controller.
 */
///#end
- (void)setIPhoneContainerWithViewController:(UIViewController *)viewController;

///#begin zh-cn
/**
 *	@brief	设置iPad显示容器
 *
 *	@param 	view 	视图
 *	@param 	arrowDirect 	显示分享列表方向
 */
///#end
///#begin en
/**
 *	@brief	Set iPad container
 *
 *	@param 	view 	Container view
 *	@param 	arrowDirect     Share menu's arrow direction
 */
///#end
- (void)setIPadContainerWithView:(UIView *)view
                     arrowDirect:(UIPopoverArrowDirection)arrowDirect;

///#begin zh-cn
/**
 *	@brief	设置iPad显示容器
 *
 *	@param 	view 	视图
 *	@param 	rect 	显示范围
 *	@param 	arrowDirect 	显示分享列表方向
 */
///#end
///#begin en
/**
 *	@brief	Set iPad container
 *
 *	@param 	view 	Container view
 *	@param 	rect 	display rectangle
 *	@param 	arrowDirect 	Share menu's arrow direction
 */
///#end
- (void)setIPadContainerWithView:(UIView *)view
                            rect:(CGRect)rect
                     arrowDirect:(UIPopoverArrowDirection)arrowDirect;

///#begin zh-cn
/**
 *	@brief	设置iPad显示容器
 *
 *	@param 	buttonItem 	导航按钮
 *	@param 	arrowDirect 	显示分享列表方向
 */
///#end
///#begin en
/**
 *	@brief	Set iPad container
 *
 *	@param 	buttonItem 	Navigation item or toolbar item.
 *	@param 	arrowDirect 	Share menu's arrow direction
 */
///#end
- (void)setIPadContainerWithBarButtonItem:(UIBarButtonItem *)buttonItem
                              arrowDirect:(UIPopoverArrowDirection)arrowDirect;

@end
