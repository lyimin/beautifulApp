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
#import "ISSViewDelegate.h"

///#begin zh-cn
/**
 *	@brief	授权选项
 */
///#end
///#begin en
/**
 *	@brief	Authorize options
 */
///#end
@protocol ISSAuthOptions <NSObject,
                          NSCopying>

///#begin zh-cn
/**
 *	@brief	获取视图样式
 *
 *  @return 视图样式
 */
///#end
///#begin en
/**
 *	@brief	Get view style
 *
 *  @return View style
 */
///#end
- (SSAuthViewStyle)viewStyle;

///#begin zh-cn
/**
 *	@brief	设置视图样式
 *
 *	@param 	viewStyle 	视图样式
 */
///#end
///#begin en
/**
 *	@brief	Set view style
 *
 *	@param 	viewStyle 	View style
 */
///#end
- (void)setViewStyle:(SSAuthViewStyle)viewStyle;

///#begin zh-cn
/**
 *	@brief	自动授权标志，当分享内容时发现授权过期是否委托SDK处理授权问题，YES：表示委托授权， NO：表示不委托授权，需要自己根据返回值进行判断和处理
 *
 *  @return 自动授权标识
 */
///#end
///#begin en
/**
 *	@brief	Get automatic authorization flag,When authorized expired, Whether SDK has automatic show authorized view let user to completed authorized.
 *
 *  @return Automatic authorization flag. YES indicate enabled. NO indicate disabled.
 */
///#end
- (BOOL)autoAuth;

///#begin zh-cn
/**
 *	@brief	设置自动授权标识,当分享内容时发现授权过期是否委托SDK处理授权问题，YES：表示委托授权， NO：表示不委托授权，需要自己根据返回值进行判断和处理
 *
 *	@param 	autoAuth 	自动授权标识
 */
///#end
///#begin en
/**
 *	@brief	Set automatic authorization flag,When authorized expired, Whether SDK has automatic show authorized view let user to completed authorized.
 *
 *  @param  autoAuth    Automatic authorization flag. YES indicate enabled. NO indicate disabled.
 */
///#end
- (void)setAutoAuth:(BOOL)autoAuth;

///#begin zh-cn
/**
 *	@brief	是否允许授权后回调到服务器，默认为YES，对于没有服务器或者不需要回调服务器的应用可以设置为NO
 *
 *  @return YES表示回调服务器，NO表示不回调服务器
 */
///#end
///#begin en
/**
 *	@brief	Whether to allow authorized after the callback to the server, the default is YES, for there is no server or application server does not require a callback can be set to NO
 *
 *  @return YES indicate enabled callback. NO indicate disabled callback.
 */
///#end
- (BOOL)allowCallback;

///#begin zh-cn
/**
 *	@brief	设置是否允许授权后回调服务器
 *
 *	@param 	allowCallback 	YES表示回调服务器，NO表示不回调服务器
 */
///#end
///#begin en
/**
 *	@brief	Whether to allow authorized after the callback to the server.
 *
 *	@param 	allowCallback 	YES indicate enabled callback. NO indicate disabled callback.
 */
///#end
- (void)setAllowCallback:(BOOL)allowCallback;

///#begin zh-cn
/**
 *	@brief	获取授权视图协议委托
 *  
 *  @return 协议委托
 */
///#end
///#begin en
/**
 *	@brief	Get authorized view delegate.
 *
 *  @return delegate object.
 */
///#end
- (id<ISSViewDelegate>)viewDelegate;

///#begin zh-cn
/**
 *	@brief	设置授权视图协议委托
 *
 *	@param 	viewDelegate 	协议委托
 */
///#end
///#begin en
/**
 *	@brief	Set authorized view delegate.
 *
 *	@param 	viewDelegate 	delegate object.
 */
///#end
- (void)setViewDelegate:(id<ISSViewDelegate>)viewDelegate;

///#begin zh-cn
/**
 *	@brief	授权管理视图协议委托
 *
 *  @return 协议委托
 */
///#end
///#begin en
/**
 *	@brief	Get authroized manager view delegate.
 *
 *  @return delegate object.
 */
///#end
- (id<ISSViewDelegate>)authManagerViewDelegate;

///#begin zh-cn
/**
 *	@brief	设置授权管理视图协议委托
 *
 *	@param 	authManagerViewDelegate 	协议委托
 */
///#end
///#begin en
/**
 *	@brief	Set authroized manager view delegate.
 *
 *	@param 	authManagerViewDelegate 	delegate object.
 */
///#end
- (void)setAuthManagerViewDelegate:(id<ISSViewDelegate>)authManagerViewDelegate;

///#begin zh-cn
/**
 *	@brief	获取授权权限
 *
 *	@return	授权权限
 */
///#end
///#begin en
/**
 *	@brief	Get authorized scopes.
 *
 *	@return	scopes dictionary. key is platform type number. value is contain scope string's array.
 */
///#end
- (NSDictionary *)scopes;

///#begin zh-cn
/**
 *	@brief	设置授权权限
 *
 *	@param 	scopes 	授权权限
 */
///#end
///#begin en
/**
 *	@brief	Set authorized scopes.
 *
 *	@param 	scopes 	scopes dictionary. key is platform type number. value is contain scope string's array.
 */
///#end
- (void)setScopes:(NSDictionary *)scopes;

///#begin zh-cn
/**
 *	@brief	获取版权隐藏标识
 *
 *	@return	YES 表示隐藏， NO 表示不隐藏
 */
///#end
///#begin en
/**
 *	@brief	Get powered by hidden flag.
 *
 *	@return	YES indicate hidden， NO indicate show.
 */
///#end
- (BOOL)powerByHidden;

///#begin zh-cn
/**
 *	@brief	设置版本信息隐藏标识
 *
 *	@param 	powerByHidden 	YES 表示隐藏， NO 表示不隐藏
 */
///#end
///#begin en
/**
 *	@brief	Set powered by hidden flag.
 *
 *	@param 	powerByHidden 	YES indicate hidden， NO indicate show.
 */
///#end
- (void)setPowerByHidden:(BOOL)powerByHidden;

///#begin zh-cn
/**
 *	@brief	获取关注帐号
 *
 *	@return	关注帐号的字典结构
 */
///#end
///#begin en
/**
 *	@brief	Get follower accounts.
 *
 *	@return	follower accounts dicationary. key is platform type number. value is ISSUserField's protocol object.
 */
///#end
- (NSDictionary *)followAccounts;

///#begin zh-cn
/**
 *	@brief	设置关注帐号
 *
 *	@param 	followAccounts 	关注帐号的字典结构
 */
///#end
///#begin en
/**
 *	@brief	Set follower accounts.
 *
 *	@param 	followAccounts 	follower accounts dicationary. key is platform type number. value is ISSUserField's protocol object.
 */
///#end
- (void)setFollowAccounts:(NSDictionary *)followAccounts;

///#begin zh-cn
/**
 *	@brief	拷贝授权选项对象
 *
 *	@return	授权选项对象
 */
///#end
///#begin en
/**
 *	@brief	Clone current authorized options object and return the new object.
 *
 *	@return	The new authorized options object.
 */
///#end
- (id<ISSAuthOptions>)clone;


@end
