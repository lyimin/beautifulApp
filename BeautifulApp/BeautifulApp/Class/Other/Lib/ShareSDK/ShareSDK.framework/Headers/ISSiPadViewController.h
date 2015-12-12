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

///#begin zh-cn
/**
 *	@brief	iPad视图控制器协议，用于描述iPad中显示容器
 */
///#end
///#begin en
/**
 *	@brief	iPad view controller protocol，Used to describe the iPad display containers
 */
///#end
@protocol ISSiPadViewController <NSObject>

///#begin zh-cn
/**
 *	@brief	获取视图,表示弹出菜单显示在哪一个视图上
 *
 *  @return 视图对象
 */
///#end
///#begin en
/**
 *	@brief	Get view, Said the pop-up menu which is displayed on a view.
 *
 *  @return View object
 */
///#end
- (UIView *)view;

///#begin zh-cn
/**
 *	@brief	设置视图
 *
 *	@param 	view 	视图对象
 */
///#end
///#begin en
/**
 *	@brief	Set view
 *
 *	@param 	view 	View object
 */
///#end
- (void)setView:(UIView *)view;

///#begin zh-cn
/**
 *	@brief	获取按钮项，表示弹出菜单用于显示在哪一个导航按钮上
 *
 *  @return 按钮项对象
 */
///#end
///#begin en
/**
 *	@brief	Get button item, which means that the pop-up menu, which is used to display on the navigation buttons
 *
 *  @return Button item object
 */
///#end
- (UIBarButtonItem *)buttonItem;

///#begin zh-cn
/**
 *	@brief	设置按钮项
 *
 *	@param 	buttonItem 	按钮项对象
 */
///#end
///#begin en
/**
 *	@brief	Set button item
 *
 *	@param 	buttonItem 	Button item object.
 */
///#end
- (void)setButtonItem:(UIBarButtonItem *)buttonItem;

///#begin zh-cn
/**
 *	@brief	获取菜单方向
 *
 *	@return	菜单方向
 */
///#end
///#begin en
/**
 *	@brief	Get the menu direction
 *
 *	@return	Menu direction
 */
///#end
- (UIPopoverArrowDirection)arrowDirection;

///#begin zh-cn
/**
 *	@brief	设置菜单方向
 *
 *	@param 	arrowDirection 	菜单方向
 */
///#end
///#begin en
/**
 *	@brief	Set the menu direction
 *
 *	@param 	arrowDirection 	Menu direction
 */
///#end
- (void)setArrowDirection:(UIPopoverArrowDirection)arrowDirection;

///#begin zh-cn
/**
 *	@brief	获取容器显示区域
 *
 *	@return	区域对象
 */
///#end
///#begin en
/**
 *	@brief	Get container display area
 *
 *	@return	Rect object.
 */
///#end
- (CGRect)rect;

///#begin zh-cn
/**
 *	@brief	设置容器显示区域
 *
 *	@param 	rect 	区域对象
 */
///#end
///#begin en
/**
 *	@brief	Set container display area
 *
 *	@param 	rect 	Rect object.
 */
///#end
- (void)setRect:(CGRect)rect;

@end
