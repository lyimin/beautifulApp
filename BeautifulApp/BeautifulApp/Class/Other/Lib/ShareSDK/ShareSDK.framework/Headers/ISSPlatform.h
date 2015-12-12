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
#import <ShareSDKCoreService/ShareSDKCoreService.h>
#import "ShareSDKTypeDef.h"

@protocol ISSPlatformApp;

///#begin zh-cn
/**
 *	@brief	平台协议
 */
///#end
///#begin en
/**
 *	@brief	Platform protocol
 */
///#end
@protocol ISSPlatform <NSObject>

@required

///#begin zh-cn
/**
 *	@brief	初始化平台
 *
 *	@param 	type 	平台类型
 *
 *	@return	平台对象
 */
///#end
///#begin en
/**
 *	@brief	Initialize platform
 *
 *	@param 	type 	Platform type
 *
 *	@return	Platform object
 */
///#end
- (id)initWithType:(ShareType)type;

///#begin zh-cn
/**
 *	@brief	获取平台名称
 *
 *	@return	名称
 */
///#end
///#begin en
/**
 *	@brief	Get platform name
 *
 *	@return	Name
 */
///#end
- (NSString *)name;

///#begin zh-cn
/**
 *	@brief	获取平台类型
 *
 *	@return	平台类型
 */
///#end
///#begin en
/**
 *	@brief	Get platform type
 *
 *	@return	Platform type
 */
///#end
- (ShareType)type;

///#begin zh-cn
/**
 *	@brief	获取当前应用
 *
 *	@return	当前应用
 */
///#end
///#begin en
/**
 *	@brief	Get current app.
 *
 *	@return	Current app object.
 */
///#end
- (id<ISSPlatformApp>)currentApp;

///#begin zh-cn
/**
 *	@brief	设置当前应用
 *
 *	@param 	app 	当前应用
 */
///#end
///#begin en
/**
 *	@brief	Set current app.
 *
 *	@param 	app 	app object.
 */
///#end
- (void)setCurrentApp:(id<ISSPlatformApp>)app;

///#begin zh-cn
/**
 *	@brief	注册应用
 *
 *	@param 	account     ShareSDK注册账户信息
 *	@param 	appInfo 	应用信息，需要到各个平台中进行注册应用得到
 *
 *	@return	应用对象
 */
///#end
///#begin en
/**
 *	@brief	Register app.
 *
 *	@param 	account     ShareSDK registered app information object.
 *	@param 	appInfo 	App information, you need to be registered in each platform app to get
 *
 *	@return	App object
 */
///#end
- (id<ISSPlatformApp>)registerAppWithAccount:(id<ISSCAccount>)account
                                     appInfo:(NSDictionary *)appInfo;

///#begin zh-cn
/**
 *	@brief	注销应用
 *
 *	@param 	app 	应用对象
 *
 */
///#end
///#begin en
/**
 *	@brief	Unregister app
 *
 *	@param 	app 	App object
 *
 */
///#end
- (void)unregisterApp:(id<ISSPlatformApp>)app;

///#begin zh-cn
/**
 *	@brief	判断是否已经注册应用
 *
 *	@param 	appInfo 	应用信息
 *
 *	@return	YES 表示已经注册，NO 表示尚未注册
 */
///#end
///#begin en
/**
 *	@brief	Determine whether the application has been registered
 *
 *	@param 	appInfo 	Application information
 *
 *	@return	YES said it had registered, NO indicates not registered
 */
///#end
- (BOOL)hasRegisteredWithAppInfo:(NSDictionary *)appInfo;

///#begin zh-cn
/**
 *	@brief	获取已注册应用
 *
 *	@param 	key 	应用Key
 *
 *	@return	应用对象，返回nil则表示应用尚未注册
 */
///#end
///#begin en
/**
 *	@brief	Get registered application
 *
 *	@param 	key 	App key.
 *
 *	@return	App object, returns nil indicates the app has not been registered
 */
///#end
- (id<ISSPlatformApp>)appForKey:(NSString *)key;

///#begin zh-cn
/**
 *	@brief	获取已注册的应用列表
 *
 *	@return	应用列表数组，其元素为id<ISSPlatformApp>对象
 */
///#end
///#begin en
/**
 *	@brief	Get a list of registered applications
 *
 *	@return	App list array, whose elements are the object id<ISSPlatformApp>
 */
///#end
- (NSArray *)registeredApps;


@end
