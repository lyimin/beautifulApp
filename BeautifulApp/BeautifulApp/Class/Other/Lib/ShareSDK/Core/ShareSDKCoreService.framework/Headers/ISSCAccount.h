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
#import <AGCommon/CMErrorInfo.h>
#import "SSCTypeDef.h"

///#begin zh-cn
/**
 *	@brief	ShareSDK帐号协议接口
 */
///#end
///#begin en
/**
 *	@brief	ShareSDK App protocol.
 */
///#end
@protocol ISSCAccount <NSObject>

///#begin zh-cn
/**
 *	@brief	获取应用标识
 *
 *	@return	应用标识
 */
///#end
///#begin en
/**
 *	@brief	Get app key.
 *
 *	@return	App key.
 */
///#end
- (NSString *)appKey;

///#begin zh-cn
/**
 *	@brief	获取所有权限角色
 *
 *	@return	角色列表
 */
///#end
///#begin en
/**
 *	@brief	Get all the permissions roles
 *
 *	@return	Roles list.
 */
///#end
- (NSArray *)roles;

///#begin zh-cn
/**
 *	@brief	检测角色权限
 *
 *	@param 	role 	角色类型
 *
 *	@return	YES 表示拥有此角色， NO 表示没有此角色权限
 */
///#end
///#begin en
/**
 *	@brief	Detection role permissions
 *
 *	@param 	role 	Role object.
 *
 *	@return	YES means to have this role, NO means no permission for this role
 */
///#end
- (BOOL)checkRole:(Class)role;

///#begin zh-cn
/**
 *	@brief	获取缓存路径
 *
 *	@return	缓存路径
 */
///#end
///#begin en
/**
 *	@brief	Get cache path.
 *
 *	@return	Path.
 */
///#end
- (NSString *)cachePath;

///#begin zh-cn
/**
 *	@brief	设置统计策略
 *
 *	@param 	policy 	策略
 */
///#end
///#begin en
/**
 *	@brief	Set statistical policy
 *
 *	@param 	policy 	Policy
 */
///#end
- (void)setStatPolicy:(SSCStatPolicy)policy;

///#begin zh-cn
/**
 *	@brief	统计策略
 *
 *	@return	策略
 */
///#end
///#begin en
/**
 *	@brief	Get statistical policy
 *
 *	@return	Policy
 */
///#end
- (SSCStatPolicy)statPolicy;

///#begin zh-cn
/**
 *	@brief	设置应用信息托管标识
 *
 *  @since  ver1.0.7
 *
 *	@param 	enabled 	YES 表示使用服务器上的托管信息，否则使用本地代码配置信息
 */
///#end
///#begin en
/**
 *	@brief	Set app information hosting flag.
 *
 *  @since  ver1.0.7
 *
 *	@param 	enabled 	YES that the use of the information on the server hosting, otherwise use native code configuration information
 */
///#end
- (void)setUseAppTrusteeship:(BOOL)enabled;

///#begin zh-cn
/**
 *	@brief	获取应用信息托管标识
 *
 *  @since  ver1.0.7
 *
 *	@return	YES 表示使用服务器上的托管信息，否则使用本地代码配置信息
 */
///#end
///#begin en
/**
 *	@brief	Get app information hosting flag.
 *
 *  @since  ver1.0.7
 *
 *	@return	YES that the use of the information on the server hosting, otherwise use native code configuration information
 */
///#end
- (BOOL)useAppTrusteeship;

///#begin zh-cn
/**
 *	@brief	设置SSO使能状态
 *
 *  @since  ver2.1.1
 *
 *	@param 	enabled 	使能状态
 */
///#end
///#begin en
/**
 *	@brief	Set SSO Login enabled.
 *
 *  @since  ver2.1.1
 *
 *	@param 	enabled 	Enabled status.
 */
///#end
- (void)setSsoEnabled:(BOOL)enabled;

///#begin zh-cn
/**
 *	@brief	获取SSO使能状态
 *
 *	@since  ver2.1.1
 *
 *	@return	YES 表示开启， NO 表示关闭
 */
///#end
///#begin en
/**
 *	@brief	Get SSO Login enabled.
 *
 *	@since  ver2.1.1
 *
 *	@return	YES indicates enabled， NO indicates disabled.
 */
///#end
- (BOOL)ssoEnabled;

///#begin zh-cn
/**
 *	@brief	设置是否转换短链
 *
 *  @since  ver2.1.1
 *
 *	@param 	enabled 	使能状态
 */
///#end
///#begin en
/**
 *	@brief	Set convert short-link status
 *
 *  @since  ver2.1.1
 *
 *	@param 	enabled 	Enabled status.
 */
///#end
- (void)setConvertUrlEnabled:(BOOL)enabled;

///#begin zh-cn
/**
 *	@brief	获取是否转换短链状态
 *
 *  @since  ver2.1.1
 *
 *	@return	YES 表示转换，NO 表示不转换
 */
///#end
///#begin en
/**
 *	@brief	Get convert short-link status
 *
 *  @since  ver2.1.1
 *
 *	@return	YES said conversion, NO means no conversion
 */
///#end
- (BOOL)convertUrlEnabled;

///#begin zh-cn
/**
 *	@brief	设置统计数据使能状态
 *
 *  @since  ver2.1.1
 *
 *  @param  enabled     使能状态
 */
///#end
///#begin en
/**
 *	@brief	Set statistical enabled flag.
 *
 *  @since  ver2.1.1
 *
 *  @param  enabled     Enabled.
 */
///#end
- (void)setStatEnabled:(BOOL)enabled;

///#begin zh-cn
/**
 *	@brief	获取统计数据使能状态
 *
 *  @since  ver2.1.1
 *
 *	@return	统计数据使能状态
 */
///#end
///#begin en
/**
 *	@brief	Get statistical enabled flag.
 *
 *  @since  ver2.1.1
 *
 *	@return	Statistical enabled flag
 */
///#end
- (BOOL)statEnabled;

///#begin zh-cn
/**
 *	@brief	获取统计设备信息使能状态
 *
 *  @since  ver2.1.1    设置为只读，状态由开发者后台设置
 *
 *	@return	统计设备信息使能状态
 */
///#end
///#begin en
/**
 *	@brief	Get statistical device information enabled flag.
 *
 *  @since  ver2.1.1    Set readonly，State is set by the server.
 *
 *	@return Statistical device information enabled flag.
 */
///#end
- (BOOL)statDevEnabled;

///#begin zh-cn
/**
 *	@brief	获取统计分享信息使能状态
 *
 *  @since  ver2.1.1    设置为只读，状态由开发者后台设置
 *
 *	@return	统计分享信息使能状态
 */
///#end
///#begin en
/**
 *	@brief	Get statistical share information enabled flag.
 *
 *  @since  ver2.1.1    Set readonly，State is set by the server.
 *
 *	@return	Statistical share information enabled flag.
 */
///#end
- (BOOL)statShareEnabled;

///#begin zh-cn
/**
 *	@brief	获取统计用户信息使能状态
 *
 *  @since  ver2.1.1    设置为只读，状态由开发者后台设置
 *
 *	@return	统计用户信息使能状态
 */
///#end
///#begin en
/**
 *	@brief	Get statistical user information enabled flag.
 *
 *  @since  ver2.1.1    Set readonly，State is set by the server.
 *
 *	@return	Statistical user information enabled flag
 */
///#end
- (BOOL)statUserEnabled;

///#begin zh-cn
/**
 *	@brief	获取当前时间（经过服务器校正）
 *
 *	@return	当前时间（单位：秒）
 */
///#end
///#begin en
/**
 *	@brief	Get current time（After the server corrected）
 *
 *	@return	Current time（unit：second）
 */
///#end
- (NSTimeInterval)currentTimeInterval;

///#begin zh-cn
/**
 *	@brief	将客户端时间转换成服务器时间
 *
 *	@param 	clientTimeInterval 	客户端时间
 *
 *	@return	服务器时间
 */
///#end
///#begin en
/**
 *	@brief	Client time converted into server time
 *
 *	@param 	clientTimeInterval 	Client time.
 *
 *	@return	Server time.
 */
///#end
- (NSTimeInterval)serverTimeIntervalWithClientTimeInterval:(NSTimeInterval)clientTimeInterval;

///#begin zh-cn
/**
 *	@brief	更新平台配置信息
 *
 *  @param  completeHandler     完成事件
 */
///#end
///#begin en
/**
 *	@brief	Upadate paltform setting.
 *
 *  @param  completeHandler     Completed handler.
 */
///#end
- (void)updatePlatSetting:(void(^)(NSArray *settings))completeHandler;

@end
