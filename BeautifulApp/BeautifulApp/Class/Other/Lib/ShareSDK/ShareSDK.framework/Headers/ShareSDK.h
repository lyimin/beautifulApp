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
#import "NSArray+ShareSDK.h"
#import "ShareSDKTypeDef.h"
#import "ShareSDKEventHandlerDef.h"

#import "ShareSDKDef.h"
#import "ISSAuthOptions.h"
#import "ISSViewDelegate.h"
#import "ISSPage.h"
#import "ISSContent.h"

#import "ISSShareActionSheet.h"
#import "ISSShareOptions.h"
#import "ISSShareViewDelegate.h"
#import "ISSShareActionSheetItem.h"
#import "ISSUserField.h"

///#begin zh-cn
/**
 *	@brief	ShareSDK类，为整个SDK的顶层接口类，所有功能都由此类进行提供（包括分享、授权等等）v2.11.2
 */
///#end
///#begin en
/**
 *	@brief	ShareSDK function interface class, all functions performed by such offers (including sharing, authorization, etc.)
 */
///#end
@interface ShareSDK : NSObject

///#begin zh-cn
/**
 *	@brief	注册应用,此方法在应用启动时调用一次并且只能在主线程中调用。
 *
 *	@param 	appKey 	应用Key,在ShareSDK官网中注册的应用Key
 */
///#end
///#begin en
/**
 *	@brief	Register app.This method is called when the application starts and can be called only once in the main thread.
 *
 *	@param 	appKey 	App key. Registered ShareSDK app in the official website and get an app key.
 */
///#end
+ (void)registerApp:(NSString *)appKey;

///#begin zh-cn
/**
 *	@brief	注册应用。
 *
 *  @since  ver2.2.6
 *  @since  ver2.9.0
 *
 *  @deprecated     已过期，默认会同时使用本地配置和服务器托管配置。其优先级为：服务器托管配置 > 本地配置
 *
 *	@param 	appKey 	应用Key,在ShareSDK官网中注册的应用Key
 *	@param 	useAppTrusteeship 	是否使用平台信息托管，如果为YES则获取在服务器中配置的平台信息，NO表示获取本地配置信息。
 */
///#end
///#begin en
/**
 *	@brief	Register app.
 *
 *  @since  ver2.2.6
 *  @since  ver2.9.0 
 *
 *  @deprecated     Has deprecated, the default configuration will use both local and server hosting configuration. Its priority is: server hosting Configuration > Local Configuration
 *
 *	@param 	appKey 	App Key. Registered ShareSDK app in the official website and get an app key.
 *	@param 	useAppTrusteeship 	Whether to use the platform information hosting. If you get the information in the server platform configured for YES, NO, said access to the local configuration information.
 */
///#end
+ (void)registerApp:(NSString *)appKey useAppTrusteeship:(BOOL)useAppTrusteeship;


#pragma mark 设置

///#begin zh-cn
/**
 *	@brief	SSO登录方式使能
 *
 *	@param 	ssoEnabled 	YES表示使用SSO方式登录，NO表示不使用SSO方式登录，默认为YES
 */
///#end
///#begin en
/**
 *	@brief	SSO Login enabled.
 *
 *	@param 	ssoEnabled 	YES indicates using SSO Login, NO indicates that the SSO Login is not used, the default is YES
 */
///#end
+ (void)ssoEnabled:(BOOL)ssoEnabled;

///#begin zh-cn
/**
 *	@brief	设置统计策略,在3G环境以下可以通过设置该策略来减少网络请求的流量。
 *
 *	@param 	policy 	统计策略
 */
///#end
///#begin en
/**
 *	@brief	Set statistical policy, in 3G environment by setting the following policies to reduce the flow of network requests.
 *
 *	@param 	policy 	Statistical policy.
 */
///#end
+ (void)setStatPolicy:(SSCStatPolicy)policy;

///#begin zh-cn
/**
 *	@brief	设置统计的使能状态
 *
 *  @since  ver2.2.0
 *  @deprecated 已过期，请使用allowExchangeDataEnabled方法代替
 *
 *	@param 	statEnabled 	YES表示使用统计功能，NO表示不使用统计功能
 */
///#end
///#begin en
/**
 *	@brief	Set enabled state statistics.
 *
 *  @since  ver2.2.0
 *  @deprecated Deprecated，Use allowExchangeDataEnabled method instead.
 *
 *	@param 	statEnabled 	YES indicates the use of statistical functions, NO indicates they did not use statistical functions
 */
///#end
+ (void)statEnabled:(BOOL)statEnabled __deprecated;

///#begin zh-cn
/**
 *	@brief	设置是否允许与服务器交换数据。此为一个开关属性，如果设置为NO则包括统计数据、获取在线App配置信息等一切与服务器交互的操作都不允许调用。
 *
 *  @since  ver2.2.6
 *
 *	@param 	enabled 	YES表示允许与服务器进行通讯，NO表示不允许进行通讯
 */
///#end
///#begin en
/**
 *	@brief	Whether it is allowed to exchange data with the server. This is a switch attribute, if set to NO, including statistical data, to obtain operating online App configuration information and all interaction with the server are not allowed to call.
 *
 *  @since  ver2.2.6
 *
 *	@param 	enabled 	YES means allowed to communicate with the server, NO if not allowed to communicate
 */
///#end
+ (void)allowExchangeDataEnabled:(BOOL)enabled;

///#begin zh-cn
/**
 *	@brief	设置应用托管模式，当设置为YES时，将使用服务器中配置的App信息来初始化SDK中的分享平台。
 *          注：当allowExchangeDataEnabled设置为NO时，此项无效。
 *
 *  @since  ver2.2.6
 *
 *	@param 	enabled 	YES表示使用托管应用模式，NO表示不使用托管应用模式。
 */
///#end
///#begin en
/**
 *	@brief	Set application hosting mode, when set to YES, to initialize the sharing platform from server configuration.
 *          Note: When allowExchangeDataEnabled set to NO, this is invalid.
 *
 *  @since  ver2.2.6
 *
 *	@param 	enabled 	YES indicates using managed application mode, NO said they did not use the hosted application model.
 */
///#end
+ (void)useAppTrusteeship:(BOOL)enabled;

#pragma mark 初始化

///#begin zh-cn
/**
 *	@brief	链接平台应用以使用相关功能
 *
 *  @since  ver2.6.0
 *
 *	@param 	type 	平台类型
 *	@param 	appInfo 	应用信息
 */
///#end
///#begin en
/**
 *	@brief	Initialize sharing paltform.
 *
 *  @since  ver2.6.0
 *
 *	@param 	type 	Platform type.
 *	@param 	appInfo 	App information.
 */
///#end
+ (void)connectPlatformWithType:(ShareType)type
                       platform:(id<ISSPlatform>)platform
                        appInfo:(NSDictionary *)appInfo;

///#begin zh-cn
/**
 *	@brief	连接新浪微博开放平台应用以使用相关功能，此应用需要引用SinaWeiboConnection.framework
 *          http://open.weibo.com上注册新浪微博开放平台应用，并将相关信息填写到以下字段
 *
 *	@param 	appKey 	应用Key
 *	@param 	appSecret 	应用密钥
 *	@param 	redirectUri 	回调地址,无回调页面或者不需要返回回调时可以填写新浪默认回调页面：https://api.weibo.com/oauth2/default.html
 *                          但新浪开放平台中应用的回调地址必须填写此值
 */
///#end
///#begin en
/**
 *	@brief	Initialize Sina Weibo platform，This platform need import SinaWeiboConnection.framework
 *          Go to http://open.weibo.com and register Sina Weibo open platform app，Then fill in the relevant information into the field below
 *
 *	@param 	appKey  App key.
 *	@param 	appSecret 	App secret.
 *	@param 	redirectUri 	Redirect url,Sina default callback page https://api.weibo.com/oauth2/default.html can fill when there is no or no callback.
 *                          However, the app of open platform Sina callback address must complete this value
 */
///#end
+ (void)connectSinaWeiboWithAppKey:(NSString *)appKey
                         appSecret:(NSString *)appSecret
                       redirectUri:(NSString *)redirectUri;

///#begin zh-cn
/**
 *	@brief	连接新浪微博开放平台应用以使用相关功能，此应用需要引用SinaWeiboConnection.framework
 *          http://open.weibo.com上注册新浪微博开放平台应用，并将相关信息填写到以下字段
 *
 *  @since  ver 2.4.0
 *
 *	@param 	appKey 	应用Key
 *	@param 	appSecret 	应用密钥
 *	@param 	redirectUri 	回调地址,无回调页面或者不需要返回回调时可以填写新浪默认回调页面：https://api.weibo.com/oauth2/default.html
 *                          但新浪开放平台中应用的回调地址必须填写此值
 *  @param  weiboSDKCls     新浪微博SDK类型，应先导入libWeiboSDK.a,再传入[WeiboSDK class]到此参数.
 */
///#end
///#begin en
/**
 *	@brief	Initialize Sina Weibo platform，This platform need import SinaWeiboConnection.framework
 *          Go to http://open.weibo.com and register Sina Weibo open platform app，Then fill in the relevant information into the field below
 *
 *  @since  ver 2.4.0
 *
 *	@param 	appKey 	App key.
 *	@param 	appSecret 	App secret.
 *	@param 	redirectUri 	Redirect url,Sina default callback page https://api.weibo.com/oauth2/default.html can fill when there is no or no callback.
 *                          However, the app of open platform Sina callback address must complete this value
 *  @param  weiboSDKCls     Sina Weibo SDK class, you should import libWeiboSDK.a, then passed [WeiboSDK class] this parameter.
 */
///#end
+ (void)connectSinaWeiboWithAppKey:(NSString *)appKey
                         appSecret:(NSString *)appSecret
                       redirectUri:(NSString *)redirectUri
                       weiboSDKCls:(Class)weiboSDKCls;

///#begin zh-cn
/**
 *	@brief	连接腾讯微博开放平台应用以使用相关功能，此应用需要引用TencentWeiboConnection.framework
 *          http://dev.t.qq.com上注册腾讯微博开放平台应用，并将相关信息填写到以下字段
 *
 *	@param 	appKey 	应用Key
 *	@param 	appSecret 	应用密钥
 *	@param 	redirectUri 	回调地址，此地址则为应用地址。
 */
///#end
///#begin en
/**
 *	@brief	Initialize Tencent Weibo platform.This platform need import TencentWeiboConnection.framework
 *          Go to http://dev.t.qq.com and register Tencent Weibo open platform app，Then fill in the relevant information into the field below
 *
 *	@param 	appKey 	App key.
 *	@param 	appSecret 	App secret.
 *	@param 	redirectUri 	Redirect url. This address was app address.
 */
///#end
+ (void)connectTencentWeiboWithAppKey:(NSString *)appKey
                            appSecret:(NSString *)appSecret
                          redirectUri:(NSString *)redirectUri;

///#begin zh-cn
/**
 *	@brief	连接腾讯微博开放平台应用以使用相关功能，此应用需要引用TencentWeiboConnection.framework
 *          http://dev.t.qq.com上注册腾讯微博开放平台应用，并将相关信息填写到以下字段
 *
 *  @since  ver2.2.0
 *
 *	@param 	appKey 	应用Key
 *	@param 	appSecret 	应用密钥
 *	@param 	redirectUri 	回调地址，此地址则为应用地址。
 *  @param  wbApiCls    腾讯微博Api类型，引入WeiboApi.h，并将[WBApi class]传入参数，注：不使用SSO时可以传入nil
 */
///#end
///#begin en
/**
 *	@brief	Initialize Tencent Weibo platform.This platform need import TencentWeiboConnection.framework
 *          Go to http://dev.t.qq.com and register Tencent Weibo open platform app，Then fill in the relevant information into the field below
 *
 *  @since  ver2.2.0
 *
 *	@param 	appKey 	App key.
 *	@param 	appSecret 	App secret.
 *	@param 	redirectUri 	Redirect url. This address was app address.
 *  @param  wbApiCls    Tencent Weibo SDK class, you should import WeiboApi.h, then passed [WeiboApi class] this parameter.
 */
///#end
+ (void)connectTencentWeiboWithAppKey:(NSString *)appKey
                            appSecret:(NSString *)appSecret
                          redirectUri:(NSString *)redirectUri
                             wbApiCls:(Class)wbApiCls;


///#begin zh-cn
/**
 *	@brief	连接QQ空间应用以使用相关功能，此应用需要引用QZoneConnection.framework
 *          http://connect.qq.com/intro/login/上申请加入QQ登录，并将相关信息填写到以下字段
 *
 *	@param 	appKey 	应用Key
 *	@param 	appSecret 	应用密钥
 */
///#end
///#begin en
/**
 *	@brief	Initialize QZone platform.This platform need import QZoneConnection.framework
 *          Go to http://connect.qq.com/intro/login/and and register QQ Connect app，Then fill in the relevant information into the field below
 *
 *	@param 	appKey 	App key.
 *	@param 	appSecret 	App secret.
 */
///#end
+ (void)connectQZoneWithAppKey:(NSString *)appKey
                     appSecret:(NSString *)appSecret;

///#begin zh-cn
/**
 *	@brief	连接QQ空间应用以使用相关功能，此应用需要引用QZoneConnection.framework
 *          http://connect.qq.com/intro/login/上申请加入QQ登录，并将相关信息填写到以下字段
 *
 *	@param 	appKey 	应用Key
 *	@param 	appSecret 	应用密钥
 *  @param  qqApiInterfaceCls   QQApi接口类型,如果不需要SSO登录可设置为nil
 *  @param  tencentOAuthCls     腾讯授权接口类型,如果不需要SSO登录可设置为nil
 */
///#end
///#begin en
/**
 *	@brief	Initialize QZone platform.This platform need import QZoneConnection.framework
 *          Go to http://connect.qq.com/intro/login/and and register QQ Connect app，Then fill in the relevant information into the field below
 *
 *	@param 	appKey 	App key.
 *	@param 	appSecret 	App secret.
 *  @param  qqApiInterfaceCls   QQApi class, If no SSO login can be set to nil
 *  @param  tencentOAuthCls     TencentOauth class, If no SSO login can be set to nil
 */
///#end
+ (void)connectQZoneWithAppKey:(NSString *)appKey
                     appSecret:(NSString *)appSecret
             qqApiInterfaceCls:(Class)qqApiInterfaceCls
               tencentOAuthCls:(Class)tencentOAuthCls;

///#begin zh-cn
/**
 *	@brief	连接豆瓣应用以使用相关功能，此应用需要引用DouBanConnection.framework
 *          http://developers.douban.com上注册豆瓣社区应用，并将相关信息填写到以下字段
 *
 *	@param 	appKey 	应用Key
 *	@param 	appSecret 	应用密钥
 *	@param 	redirectUri 	回调地址
 */
///#end
///#begin en
/**
 *	@brief	Initialize DouBan platform，This platform need import DouBanConnection.framework
 *          Go to http://developers.douban.com and register Douban app，Then fill in the relevant information into the field below
 *
 *	@param 	appKey 	App key.
 *	@param 	appSecret 	App secret
 *	@param 	redirectUri 	Redirect Url
 */
///#end
+ (void)connectDoubanWithAppKey:(NSString *)appKey
                      appSecret:(NSString *)appSecret
                    redirectUri:(NSString *)redirectUri;

///#begin zh-cn
/**
 *	@brief	连接人人网应用以使用相关功能，此应用需要引用RenRenConnection.framework
 *          http://dev.renren.com上注册人人网开放平台应用，并将相关信息填写到以下字段
 *
 *	@param 	appKey 	应用Key
 *	@param 	appSecret 	应用密钥
 */
///#end
///#begin en
/**
 *	@brief	Initialize RenRen platform，This platform need import RenRenConnection.framework
 *          Go to http://dev.renren.comand register app，Then fill in the relevant information into the field below
 *
 *	@param 	appKey 	App key.
 *	@param 	appSecret 	App secret.
 */
///#end
+ (void)connectRenRenWithAppKey:(NSString *)appKey
                      appSecret:(NSString *)appSecret;

///#begin zh-cn
/**
 *	@brief	连接人人网应用，此应用需要引用RenRenConnection.framework
 *
 *  @since  ver2.2.6
 *
 *  @param  appId   应用ID
 *	@param 	appKey 	应用Key
 *	@param 	appSecret 	应用密钥
 *  @param  renrenClientClass   人人客户端类型,SSO时需要传入此参数。应该先引入RennSDK.framework，然后在此参数中传入[RennClient class]
 */
///#end
///#begin en
/**
 *	@brief	Initialize RenRen platform，This platform need import RenRenConnection.framework
 *
 *  @since  ver2.2.6
 *
 *  @param  appId   App id
 *	@param 	appKey  App key
 *	@param 	appSecret 	App secret
 *  @param  renrenClientClass   RenrenClient class, When you need to SSO Login pass this parameter。
 *                              You should import RennSDK.framework, then passed [RennClient class] this parameter.
 */
///#end
+ (void)connectRenRenWithAppId:(NSString *)appId
                        appKey:(NSString *)appKey
                     appSecret:(NSString *)appSecret
             renrenClientClass:(Class)renrenClientClass;

///#begin zh-cn
/**
 *	@brief	连接开心网应用以使用相关功能，此应用需要引用KaiXinConnection.framework
 *          http://open.kaixin001.com上注册开心网开放平台应用，并将相关信息填写到以下字段
 *
 *	@param 	appKey 	应用Key
 *	@param 	appSecret 	应用密钥
 *	@param 	redirectUri 	回调地址
 */
///#end
///#begin en
/**
 *	@brief	Initialize KaiXin platform，This platform need import KaiXinConnection.framework
 *          Go to http://open.kaixin001.com register app，Then fill in the relevant information into the field below
 *
 *	@param 	appKey 	App key
 *	@param 	appSecret 	App secret
 *	@param 	redirectUri 	Redirect url.
 */
///#end
+ (void)connectKaiXinWithAppKey:(NSString *)appKey
                      appSecret:(NSString *)appSecret
                    redirectUri:(NSString *)redirectUri;

///#begin zh-cn
/**
 *	@brief	连接Instapaper应用以使用相关功能，此应用需要引用InstapaperConnection.framework
 *          http://www.instapaper.com/main/request_oauth_consumer_token上注册Instapaper应用，并将相关信息填写到以下字段
 *
 *	@param 	appKey 	应用Key
 *	@param 	appSecret 	应用密钥
 */
///#end
///#begin en
/**
 *	@brief	Initialize Instapaper platform. This platform need import InstapaperConnection.framework
 *          Go to http://www.instapaper.com/main/request_oauth_consumer_token register app，Then fill in the relevant information into the field below
 *
 *	@param 	appKey 	App key
 *	@param 	appSecret 	App secret
 */
///#end
+ (void)connectInstapaperWithAppKey:(NSString *)appKey
                          appSecret:(NSString *)appSecret;

///#begin zh-cn
/**
 *	@brief	连接有道云笔记应用以使用相关功能，此应用需要引用YouDaoNoteConnection.framework
 *          http://note.youdao.com/open/developguide.html#app上注册应用，并将相关信息填写到以下字段
 *
 *	@param 	consumerKey 	消费者Key
 *	@param 	consumerSecret 	消费者密钥
 *	@param 	redirectUri 	回调地址
 */
///#end
///#begin en
/**
 *	@brief	Initialize YouDaoNote platform.This platform need import YouDaoNoteConnection.framework
 *          Go to http://note.youdao.com/open/developguide.html#app register app，Then fill in the relevant information into the field below
 *
 *	@param 	consumerKey 	Consumer key.
 *	@param 	consumerSecret 	Consumer secret.
 *	@param 	redirectUri 	Redirect url.
 */
///#end
+ (void)connectYouDaoNoteWithConsumerKey:(NSString *)consumerKey
                          consumerSecret:(NSString *)consumerSecret
                             redirectUri:(NSString *)redirectUri;

///#begin zh-cn
/**
 *	@brief	连接Facebook应用以使用相关功能，此应用需要引用FacebookConnection.framework
 *          https://developers.facebook.com上注册应用，并将相关信息填写到以下字段
 *
 *	@param 	appKey 	应用Key
 *	@param 	appSecret 	应用密钥
 */
///#end
///#begin en
/**
 *	@brief	Initialize Facebook platform.This platform need import FacebookConnection.framework
 *          Go to https://developers.facebook.com register app，Then fill in the relevant information into the field below
 *
 *	@param 	appKey 	App key.
 *	@param 	appSecret 	App secret.
 */
///#end
+ (void)connectFacebookWithAppKey:(NSString *)appKey
                        appSecret:(NSString *)appSecret;

///#begin zh-cn
/**
 *	@brief	连接Twitter应用以使用相关功能，此应用需要引用TwitterConnection.framework
 *          https://dev.twitter.com上注册应用，并将相关信息填写到以下字段
 *
 *	@param 	consumerKey 	消费者Key
 *	@param 	consumerSecret 	消费者密钥
 *	@param 	redirectUri 	回调地址
 */
///#end
///#begin en
/**
 *	@brief	Initialize Twitter platform.This platform need import TwitterConnection.framework
 *          Go to https://dev.twitter.com register app，Then fill in the relevant information into the field below
 *
 *	@param 	consumerKey 	Consumer key.
 *	@param 	consumerSecret 	Consumer secret.
 *	@param 	redirectUri 	Redirect url.
 */
///#end
+ (void)connectTwitterWithConsumerKey:(NSString *)consumerKey
                       consumerSecret:(NSString *)consumerSecret
                          redirectUri:(NSString *)redirectUri;

///#begin zh-cn
/**
 *	@brief	连接QQ应用以使用相关功能，此应用需要引用QQConnection.framework和QQApi.framework库
 *          http://mobile.qq.com/api/上注册应用，并将相关信息填写到以下字段
 *
 *	@param 	appId 	应用ID
 *	@param 	qqApiCls 	QQApi类型,引入QQApi.h后，将[QQApi class]传入此参数
 */
///#end
///#begin en
/**
 *	@brief	Initialize QQ platform.This platform need import QQConnection.framework and QApi.framework
 *          Go to http://mobile.qq.com/api/ register app，Then fill in the relevant information into the field below
 *
 *	@param 	appId 	App id.
 *	@param 	qqApiCls 	QQApi class, You should import QQApi.h，then passed [QQApi class] this parameter.
 */
///#end
+ (void)connectQQWithAppId:(NSString *)appId
                  qqApiCls:(Class)qqApiCls;

///#begin zh-cn
/**
 *	@brief	连接QQ应用以使用相关功能，此应用需要引用QQConnection.framework和TencentOAuthAPI.framework库
 *          http://connect.qq.com上注册应用，并将相关信息填写到以下字段,
 *          可以调用此接口来使QQ空间中申请的AppKey用于QQ好友分享
 *
 *  @since  ver2.2.4
 *
 *	@param 	qzoneAppKey 	QQ空间App标识
 *	@param 	qqApiInterfaceCls 	QQAPI接口类型
 *	@param 	tencentOAuthCls 	腾讯OAuth类型
 */
///#end
///#begin en
/**
 *	@brief	Initialize QQ platform. This platform need import QQConnection.framework and TencentOAuthAPI.framework
 *          Go to http://connect.qq.com register app，Then fill in the relevant information into the field below
 *          You can call this interface passed QZone app key to initialize.
 *
 *  @since  ver2.2.4
 *
 *	@param 	qzoneAppKey 	QZone app key.
 *	@param 	qqApiInterfaceCls 	QQAPIInterface class.
 *	@param 	tencentOAuthCls 	TencentOAuth class.
 */
///#end
+ (void)connectQQWithQZoneAppKey:(NSString *)qzoneAppKey
               qqApiInterfaceCls:(Class)qqApiInterfaceCls
                 tencentOAuthCls:(Class)tencentOAuthCls;

///#begin zh-cn
/**
 *	@brief	连接微信应用以使用相关功能，此应用需要引用WeChatConnection.framework和微信官方SDK
 *          http://open.weixin.qq.com上注册应用，并将相关信息填写以下字段。如果需要使用微信授权获取用户信息等，则可使用下面中带appSecret的方法。
 *
 *	@param 	appId 	应用ID
 *  @param 	appSecret 	应用密钥
 *	@param 	wechatCls 	微信Api类型，引入WXApi.h后，将[WXApi class]传入此参数
 */
///#end
///#begin en
/**
 *	@brief	Initialize WeChat platform. If you want get the user's infomation then you may choose the method that with the appSecret.This platform need import WeChatConnection.framework and libWeChatSDK.a
 *          Go to http://open.weixin.qq.com register app，Then fill in the relevant information into the field below
 *
 *	@param 	appId 	App id.
 *  @param 	appSecret 	App Secret
 *	@param 	wechatCls 	WXApi class，You should import WXApi.h，then passed [WXApi class] this parameter.
 */
///#end
+ (void)connectWeChatWithAppId:(NSString *)appId
                     wechatCls:(Class)wechatCls;

+ (void)connectWeChatWithAppId:(NSString *)appId
                     appSecret:(NSString *)appSecret
                     wechatCls:(Class)wechatCls;

///#begin zh-cn
/**
 *	@brief	链接Pocket以使用相关功能，此应用需要引用PocketConnection.framework
 *          http://getpocket.com/developer/上注册应用，并将相关信息填写以下字段
 *
 *  @since  ver2.2.0
 *
 *	@param 	consumerKey 	消费者Key
 *	@param 	redirectUri 	回调地址
 */
///#end
///#begin en
/**
 *	@brief	Initialize Pocket platform，This platform need import PocketConnection.framework
 *          Go to http://getpocket.com/developer/ register app，Then fill in the relevant information into the field below
 *
 *  @since  ver2.2.0
 *
 *	@param 	consumerKey 	Consumer key
 *	@param 	redirectUri 	Redirect Url.
 */
///#end
+ (void)connectPocketWithConsumerKey:(NSString *)consumerKey
                         redirectUri:(NSString *)redirectUri;

///#begin zh-cn
/**
 *	@brief	连接印象笔记以使用相关功能，此应用需要引用EverNoteConnection.framework
 *          http://dev.yinxiang.com上注册应用，并将相关信息填写以下字段
 *
 *	@param 	type 	应用类型，可以指定是沙箱、印象笔记中国还是Evernote International,注：如果设置了沙箱类型，则需要在发布应用之前把类型改为其他的，否则会导致用户无法正常使用。
 *	@param 	consumerKey 	消费者Key
 *	@param 	consumerSecret 	消费者密钥
 */
///#end
///#begin en
/**
 *	@brief	Initialize EverNote platform，This platform need import EverNoteConnection.framework
 *          Go to http://dev.yinxiang.com register app，Then fill in the relevant information into the field below
 *
 *	@param 	type 	App Type. You can specify a sandbox environment or Evernote China or Evernote International, Note: If you set the sandbox type, you need to apply before the release of the other type, otherwise it will lead to the user not work properly.
 *	@param 	consumerKey 	Consumer key.
 *	@param 	consumerSecret 	Consumer secret.
 */
///#end
+ (void)connectEvernoteWithType:(SSEverNoteType)type
                    consumerKey:(NSString *)consumerKey
                 consumerSecret:(NSString *)consumerSecret;

///#begin zh-cn
/**
 *	@brief	连接LinkedIn以使用相关功能，此平台需要引用LinkedInConnection.framework
 *          https://www.linkedin.com/secure/developer上注册应用，并将相关信息填写以下字段
 *
 *  @since  ver2.4.0
 *
 *	@param 	apiKey 	应用Key
 *	@param 	secretKey 	应用密钥
 *	@param 	redirectUri 	回调地址
 */
///#end
///#begin en
/**
 *	@brief	Initialize LinkedIn platform. This platform need import LinkedInConnection.framework
 *          Go to https://www.linkedin.com/secure/developer register app，Then fill in the relevant information into the field below
 *
 *  @since  ver2.4.0
 *
 *	@param 	apiKey 	Api key
 *	@param 	secretKey 	Secret key.
 *	@param 	redirectUri 	Redirect url.
 */
///#end
+ (void)connectLinkedInWithApiKey:(NSString *)apiKey
                        secretKey:(NSString *)secretKey
                      redirectUri:(NSString *)redirectUri;

///#begin zh-cn
/**
 *	@brief	链接Google+,此平台需要引用GooglePlusConnection.framework、GoogleOpenSource.frramework、GooglePlus.framework框架
 *          https://code.google.com/apis/console上注册应用，并将相关信息填写以下字段
 *
 *  @since  ver2.4.0
 *
 *	@param 	clientId 	应用Key
 *	@param 	clientSecret 	应用密钥
 *	@param 	redirectUri 	回调地址
 *  @param  signInCls       登录授权类型，应先导入GooglePlus.framework,然后在此参数中传入[GPPSignIn class]
 *  @param  shareCls        分享类型，应先导入GooglePlus.framework,然后在此参数中传入[GPPShare class]
 */
///#end
///#begin en
/**
 *	@brief	Initialize Google+ platform, This platform need import GooglePlusConnection.framework、GoogleOpenSource.frramework、GooglePlus.framework
 *          Go to https://code.google.com/apis/console register app，Then fill in the relevant information into the field below
 *
 *  @since  ver2.4.0
 *
 *	@param 	clientId 	Client id.
 *	@param 	clientSecret 	Client secret.
 *	@param 	redirectUri 	Redirect url.
 *  @param  signInCls       GPPSignIn class，You should import GooglePlus.framework,then passed [GPPSignIn class] this parameter.
 *  @param  shareCls        GPPShare class，You should import GooglePlus.framework,then passed [GPPShare class] this parameter.
 */
///#end
+ (void)connectGooglePlusWithClientId:(NSString *)clientId
                         clientSecret:(NSString *)clientSecret
                          redirectUri:(NSString *)redirectUri
                            signInCls:(Class)signInCls
                             shareCls:(Class)shareCls;

///#begin zh-cn
/**
 *	@brief	链接Pinterest,此平台需要引用PinterestConnection.framework、Pinterest.framework框架。
 *          http://developers.pinterest.com/上注册应用，并将相关信息填写以下字段。
 *
 *	@param 	clientId 	应用Key
 *	@param 	pinterestCls 	Pinterest类型，应先导入Pinterest.framework，然后在此参数中传入
 */
///#end
///#begin en
/**
 *	@brief	Initialize Pinterest platform, This platform need import PinterestConnection.framework and Pinterest.framework
 *          Go to http://developers.pinterest.com/ register app，Then fill in the relevant information into the field below
 *
 *	@param 	clientId 	Client id.
 *	@param 	pinterestCls 	Pinterest class，You should import Pinterest.framework，Then passed this parameter.
 */
///#end
+ (void)connectPinterestWithClientId:(NSString *)clientId
                        pinterestCls:(Class)pinterestCls;

///#begin zh-cn
/**
 *	@brief	链接Flickr,此平台需要引用FlickrConnection.framework框架。
 *          http://www.flickr.com/services/apps/create/上注册应用，并将相关信息填写以下字段。
 *
 *	@param 	apiKey 	应用Key
 *	@param 	apiSecret 	应用密钥
 */
///#end
///#begin en
/**
 *	@brief	Initialize Flickr platform, This platform need import FlickrConnection.framework。
 *          Go to http://www.flickr.com/services/apps/create/ register app，Then fill in the relevant information into the field below
 *
 *	@param 	apiKey 	Api key
 *	@param 	apiSecret 	Api secret
 */
///#end
+ (void)connectFlickrWithApiKey:(NSString *)apiKey
                      apiSecret:(NSString *)apiSecret;

///#begin zh-cn
/**
 *	@brief	链接Tumblr,此平台需要引用TumblrConnection.framework框架
 *          http://www.tumblr.com/oauth/apps上注册应用，并将相关信息填写以下字段。
 *
 *	@param 	consumerKey 	应用Key
 *	@param 	consumerSecret 	应用密钥
 *	@param 	callbackUrl 	回调地址
 */
///#end
///#begin en
/**
 *	@brief	Initialize Tumblr platform. This platform need import TumblrConnection.framework
 *          Go to http://www.tumblr.com/oauth/apps register app，Then fill in the relevant information into the field below
 *
 *	@param 	consumerKey 	Consumer key.
 *	@param 	consumerSecret 	Consumer secret.
 *	@param 	callbackUrl 	Callback url.
 */
///#end
+ (void)connectTumblrWithConsumerKey:(NSString *)consumerKey
                      consumerSecret:(NSString *)consumerSecret
                         callbackUrl:(NSString *)callbackUrl;

///#begin zh-cn
/**
 *	@brief	连接Dropbox，此平台需要引用DropboxConnection.framework框架
 *          https://www.dropbox.com/developers/apps上注册应用，并将相关信息填写以下字段。
 *
 *	@param 	appKey 	应用Key
 *	@param 	appSecret 	应用密钥
 */
///#end
///#begin en
/**
 *	@brief	Initialize Dropbox platform，This platform need import DropboxConnection.framework
 *          Go to https://www.dropbox.com/developers/apps register app，Then fill in the relevant information into the field below
 *
 *	@param 	appKey 	App key
 *	@param 	appSecret 	App secret
 */
///#end
+ (void)connectDropboxWithAppKey:(NSString *)appKey
                       appSecret:(NSString *)appSecret
                     callbackUrl:(NSString *)callbackUrl;

///#begin zh-cn
/**
 *	@brief	连接Instagram,此平台需要引用InstagramConnection.framework框架
 *          http://instagram.com/developer/clients/register/上注册应用，并将相关信息填写以下字段
 *
 *	@param 	clientId 	应用Key
 *	@param 	clientSecret 	应用密钥
 *	@param 	redirectUri 	回调地址
 */
///#end
///#begin en
/**
 *	@brief	Initialize Instagram platform. This platform need import InstagramConnection.framework
 *          Go to http://instagram.com/developer/clients/register/ register app，Then fill in the relevant information into the field below
 *
 *	@param 	clientId 	Client id
 *	@param 	clientSecret 	Client secret
 *	@param 	redirectUri 	Redirect url.
 */
///#end
+ (void)connectInstagramWithClientId:(NSString *)clientId
                        clientSecret:(NSString *)clientSecret
                         redirectUri:(NSString *)redirectUri;

///#begin zh-cn
/**
 *	@brief	链接VKontakte，此平台需要引用VKontakteConnection.framework框架
 *          http://vk.com/editapp?act=create上注册应用，并将相关信息填写以下字段
 *
 *	@param 	appKey 	应用Key
 *	@param 	secretKey 	应用密钥
 */
///#end
///#begin en
/**
 *	@brief	Initialize VKontakte platform，This platform need import VKontakteConnection.framework
 *          Go to http://vk.com/editapp?act=create register app，Then fill in the relevant information into the field below
 *
 *	@param 	appKey 	App key
 *	@param 	secretKey 	Secret key
 */
///#end
+ (void)connectVKontakteWithAppKey:(NSString *)appKey
                         secretKey:(NSString *)secretKey;

///#begin zh-cn
/**
 *	@brief	连接邮件分享
 *  
 *  @since  ver2.6.0
 */
///#end
///#begin en
/**
 *	@brief	Initialize mail.
 *
 *  @since  ver2.6.0
 */
///#end
+ (void)connectMail;

///#begin zh-cn
/**
 *	@brief	连接短信分享
 *  
 *  @since  ver2.6.0
 */
///#end
///#begin en
/**
 *	@brief	Initialize SMS
 *
 *  @since  ver2.6.0
 */
///#end
+ (void)connectSMS;

///#begin zh-cn
/**
 *	@brief	连接打印
 *
 *  @since  ver2.6.0
 */
///#end
///#begin en
/**
 *	@brief	Initialize Print.
 *
 *  @since  ver2.6.0
 */
///#end
+ (void)connectAirPrint;

///#begin zh-cn
/**
 *	@brief	连接拷贝
 *
 *  @since  ver2.6.0
 */
///#end
///#begin en
/**
 *	@brief	Initialize Copy
 *
 *  @since  ver2.6.0
 */
///#end
+ (void)connectCopy;

///#begin zh-cn
/**
 *	@brief	连接微信好友。如果需要使用微信授权获取用户信息等，则可使用下面中带appSecret的方法。
 *
 *  @since  ver2.6.0
 *
 *	@param 	appId 	应用ID，必须要和朋友圈传入ID一致
 *  @param 	appSecret 	应用密钥
 *	@param 	wechatCls 	微信Api类型，引入WXApi.h后，将[WXApi class]传入此参数
 */
///#end
///#begin en
/**
 *	@brief	Initialize WeChat Session platform.If you want get the user's infomation then you may choose the method that with the appSecret.
 *
 *  @since  ver2.6.0
 *
 *	@param 	appId 	App id. Must be consistent and WeChat Timeline passed ID
 *  @param 	appSecret 	App Secret
 *	@param 	wechatCls 	WXApi class，You should import WXApi.h，then passed [WXApi class] this parameter.
 */
///#end
+ (void)connectWeChatSessionWithAppId:(NSString *)appId
                            wechatCls:(Class)wechatCls;

+ (void)connectWeChatSessionWithAppId:(NSString *)appId
                            appSecret:(NSString *)appSecret
                            wechatCls:(Class)wechatCls;

///#begin zh-cn
/**
 *	@brief	连接微信朋友圈。如果需要使用微信授权获取用户信息等，则可使用下面中带appSecret的方法。
 *
 *  @since  ver2.6.0
 *
 *	@param 	appId 	应用ID，必须要和好友传入ID一致
 *  @param 	appSecret 	应用密钥
 *	@param 	wechatCls 	微信Api类型，引入WXApi.h后，将[WXApi class]传入此参数
 */
///#end
///#begin en
/**
 *	@brief	Initialize WeChat Timeline platform.If you want get the user's infomation then you may choose the method that with the appSecret.
 *
 *  @since  ver2.6.0
 *
 *	@param 	appId 	App id. Must be consistent and WeChat Session passed ID
 *  @param 	appSecret 	App Secret
 *	@param 	wechatCls 	WXApi class，You should import WXApi.h，then passed [WXApi class] this parameter.
 */
///#end
+ (void)connectWeChatTimelineWithAppId:(NSString *)appId
                             wechatCls:(Class)wechatCls;

+ (void)connectWeChatTimelineWithAppId:(NSString *)appId
                             appSecret:(NSString *)appSecret
                             wechatCls:(Class)wechatCls;

///#begin zh-cn
/**
 *	@brief	连接微信收藏。如果需要使用微信授权获取用户信息等，则可使用下面中带appSecret的方法。
 *
 *	@param 	appId 	应用ID，必须要和好友、朋友圈传入ID一致。
 *  @param 	appSecret 	应用密钥
 *	@param 	wechatCls 	微信Api类型，引入WXApi.h后，将[WXApi class]传入此参数
 */
///#end
///#begin en
/**
 *	@brief	Initialize WeChat Favorite platform.If you want get the user's infomation then you may choose the method that with the appSecret.
 *
 *	@param 	appId 	App id，Must be consistent and WeChat Session、WeChat Timeline passed ID
 *  @param 	appSecret 	App Secret
 *	@param 	wechatCls 	WXApi class，You should import WXApi.h，then passed [WXApi class] this parameter.
 */
///#end
+ (void)connectWeChatFavWithAppId:(NSString *)appId
                        wechatCls:(Class)wechatCls;

+ (void)connectWeChatFavWithAppId:(NSString *)appId
                        appSecret:(NSString *)appSecret
                        wechatCls:(Class)wechatCls;

///#begin zh-cn
/**
 *	@brief	链接易信好友
 *
 *  @since  ver2.7.0
 *
 *	@param 	appId 	应用ID，必须要和朋友圈传入ID一致
 *	@param 	yixinCls 	易信Api类型，引入YXApi.h后，将[YXApi class]传入此参数
 */
///#end
///#begin en
/**
 *	@brief	Initialize YiXin Session platform.
 *
 *  @since  ver2.7.0
 *
 *	@param 	appId 	App id，Must be consistent and YiXin Timeline passed ID
 *	@param 	yixinCls 	YXApi class，You should import YXApi.h，then passed [YXApi class] this parameter.
 */
///#end
+ (void)connectYiXinSessionWithAppId:(NSString *)appId
                            yixinCls:(Class)yixinCls;

///#begin zh-cn
/**
 *	@brief	链接易信朋友圈
 *
 *  @since  ver2.7.0
 *
 *	@param 	appId 	应用ID，必须和易信好友传入ID一致
 *	@param 	yixinCls 	易信Api类型，引入YXApi.h后，将[YXApi class]传入此参数
 */
///#end
///#begin en
/**
 *	@brief	Initialize YiXin Timeline platform.
 *
 *  @since  ver2.7.0
 *
 *	@param 	appId 	App id，Must be consistent and YiXin Session passed ID
 *	@param 	yixinCls 	YXApi class，You should import YXApi.h，then passed [YXApi class] this parameter.
 */
///#end
+ (void)connectYiXinTimelineWithAppId:(NSString *)appId
                             yixinCls:(Class)yixinCls;

///#begin zh-cn
/**
 *	@brief	连接易信应用以使用相关功能，此应用需要引用YiXinConnection.framework和易信官方SDK
 *          http://open.yixin.im/上注册应用，并将相关信息填写以下字段
 *
 *	@param 	appId 	应用ID
 *	@param 	yixinCls 	易信Api类型，引入YXApi.h后，将[YXApi class]传入此参数
 */
///#end
///#begin en
/**
 *	@brief	Initialize YiXin platform，This platform need import YiXinConnection.framework and libYXSDK.a
 *          Go to http://open.yixin.im/ register app，Then fill in the relevant information into the field below
 *
 *	@param 	appId 	App id，
 *	@param 	yixinCls 	YXApi class，You should import YXApi.h，then passed [YXApi class] this parameter.
 */
///#end
+ (void)connectYiXinWithAppId:(NSString *)appId
                     yixinCls:(Class)yixinCls;

///#begin zh-cn
/**
 *	@brief	链接明道应用以使用相关功能，此应用需要引用MingDaoConnection.framework
 *          http://open.mingdao.com/上注册应用，并将相关信息填写以下字段。
 *
 *  @since  ver2.9.0
 *
 *	@param 	appKey 	应用Key
 *	@param 	appSecret 	应用密钥
 *	@param 	redirectUri 	回调地址
 */
///#end
///#begin en
/**
 *	@brief	Initialize MingDao platform，This platform need import MingDaoConnection.framework
 *          Go to http://open.mingdao.com/ register app，Then fill in the relevant information into the field below
 *
 *  @since  ver2.9.0
 *
 *	@param 	appKey 	App key
 *	@param 	appSecret 	App secret
 *	@param 	redirectUri 	Redirect URI
 */
///#end
+ (void)connectMingDaoWithAppKey:(NSString *)appKey
                       appSecret:(NSString *)appSecret
                     redirectUri:(NSString *)redirectUri;

///#begin zh-cn
/**
 *	@brief	链接Line以使用相关功能。
 *
 *  @since  ver2.9.0
 *
 */
///#end
///#begin en
/**
 *	@brief	Initialize Line platform，This platform need import LineConnection.framework
 *
 *	@since  ver2.9.0
 */
///#end
+ (void)connectLine;

///#begin zh-cn
/**
 *	@brief	链接WhatsApp以使用相关功能。
 *
 *  @since  ver2.9.0
 *
 */
///#end
///#begin en
/**
 *	@brief	Initialize WhatsApp platform，This platform need import WhatsAppConnection.framework
 *
 *	@since  ver2.9.0
 */
///#end
+ (void)connectWhatsApp;

///#begin zh-cn
/**
 *	@brief	链接KaKao Talk以使用相关功能。
 *
 *  @since  ver2.10.0
 *
 */
///#end
///#begin en
/**
 *	@brief	Initialize KaKao Talk platform，This platform need import KaKaoTalkConnection.framework
 *
 *	@since  ver2.10.0
 */
///#end
+ (void)connectKaKaoTalk;

///#begin zh-cn
/**
 *	@brief	链接KaKao Story以使用相关功能。
 *
 *  @since  ver2.10.0
 *
 */
///#end
///#begin en
/**
 *	@brief	Initialize KaKao Story platform，This platform need import KaKaoTalkConnection.framework
 *
 *	@since  ver2.10.0
 */
///#end
+ (void)connectKaKaoStory;

///#begin zh-cn
/**
 *	@brief	链接支付宝朋友以使用相关功能
 *
 *  @since  ver2.11.2
 *
 *	@param 	appId               应用ID
 *  @param 	openApiCls          头文件导入文件"APOpenAPI.h",将[APOpenAPI class]传入此参数
 *  @param 	mediaMessageCls     将[APMediaMessage class]传入此参数
 *  @param 	shareTextObjectCls  将[APShareTextObject class]传入此参数
 *  @param 	shareImgObjectCls   将[APShareImageObject class]传入此参数
 *  @param 	webObjectCls        将[APShareWebObject class]传入此参数
 *  @param 	sendMsgToAPReqCls   将[APSendMessageToAPReq class]传入此参数
 */
///#end
///#begin en
/**
 *	@brief	Initialize YiXin Session platform.
 *
 *  @since  ver2.11.2
 *
 *	@param 	appId 	App id
 *  @param 	openApiCls          import "APOpenAPI.h",then passed [APOpenAPI class] this parameter.
 *  @param 	mediaMessageCls     passed [APMediaMessage class] this parameter
 *  @param 	shareTextObjectCls  passed [APShareTextObject class] this parameter
 *  @param 	shareImgObjectCls   passed [APShareImageObject class] this parameter
 *  @param 	webObjectCls        passed [APShareWebObject class] this parameter
 *  @param 	sendMsgToAPReqCls   passed [APSendMessageToAPReq class] this parameter
 */
///#end
+ (void)connectAliPaySocialWithAppID:(NSString*)appId
                          openApiCls:(Class)openApiCls
                     mediaMessageCls:(Class)mediaMessageCls
                  shareTextObjectCls:(Class)shareTextObjectCls
                   shareImgObjectCls:(Class)shareImgObjectCls
                   shareWebObjectCls:(Class)webObjectCls
               sendMessageToAPReqCls:(Class)sendMsgToAPReqCls;

///#begin zh-cn
/**
 *	@brief	处理请求打开链接,如果集成新浪微博(SSO)、Facebook(SSO)、微信、QQ分享功能需要加入此方法
 *
 *	@param 	url 	链接
 *  @param  wxDelegate  微信委托,如果没有集成微信SDK，可以传入nil
 *
 *	@return	YES 表示接受请求 NO 表示不接受
 */
///#end
///#begin en
/**
 *	@brief	Handle open url,If the integrated Sina Weibo (SSO), Facebook (SSO), WeChat, QQ sharing need to add this method
 *
 *	@param 	url 	Url string.
 *  @param  wxDelegate  WeChat delegate,If there is no integrated WeChat platform, you can pass nil
 *
 *	@return	YES indicates to accept the request. NO indicates they did not accept
 */
///#end
+ (BOOL)handleOpenURL:(NSURL *)url wxDelegate:(id)wxDelegate;

///#begin zh-cn
/**
 *	@brief	处理请求打开链接,如果集成新浪微博(SSO)、Facebook(SSO)、微信、QQ分享功能需要加入此方法
 *
 *	@param 	url 	链接
 *	@param 	sourceApplication 	源应用
 *	@param 	annotation 	源应用提供的信息
 *  @param  wxDelegate  微信委托,如果没有集成微信SDK，可以传入nil
 *
 *	@return	YES 表示接受请求，NO 表示不接受请求
 */
///#end
///#begin en
/**
 *	@brief	Handle open url,If the integrated Sina Weibo (SSO), Facebook (SSO), WeChat, QQ sharing need to add this method
 *
 *	@param 	url 	Url string.
 *	@param 	sourceApplication 	Source Application.
 *	@param 	annotation 	Annotation
 *  @param  wxDelegate  WeChat delegate,If there is no integrated WeChat platform, you can pass nil
 *
 *	@return	YES indicates to accept the request. NO indicates they did not accept
 */
///#end
+ (BOOL)handleOpenURL:(NSURL *)url
    sourceApplication:(NSString *)sourceApplication
           annotation:(id)annotation
           wxDelegate:(id)wxDelegate;

///#begin zh-cn
/**
 *	@brief	导入腾讯微博类型，对于使用应用信息托管方式下（即registerApp中的useAppTrusteeship为YES）需要调用此方法。注：不使用SSO时可以不调用
 *
 *	@param 	wbApiCls 	腾讯微博Api类型，引入WBApi.h，并将[WBApi class]传入参数
 */
///#end
///#begin en
/**
 *	@brief	Import Tencent Weibo Classes，For application information hosting (ie registerApp in useAppTrusteeship is YES) need to call this method. Note: You not use the SSO Login when not in call
 *
 *	@param 	wbApiCls 	WeiboApi class，You should import WBApi.h，Then passed [WeiboApi class] this parameter.
 */
///#end
+ (void)importTencentWeiboClass:(Class)wbApiCls;

///#begin zh-cn
/**
 *	@brief	导入QQ好友和QQ空间所需要类型，对于使用应用信息托管方式下（即registerApp中的useAppTrusteeship为YES）需要调用此方法。注：不使用QQ空间SSO或者不调用QQ好友分享时可以不调用
 *
 *	@param 	qqApiInterfaceCls 	QQApi接口类型
 *	@param 	tencentOAuthCls 	腾讯授权接口类型
 */
///#end
///#begin en
/**
 *	@brief	Import QQ and QZone Classes，For application information hosting (ie registerApp in useAppTrusteeship is YES) need to call this method. Note: You not use the QZone SSO Login and QQ Share when not in call
 *
 *	@param 	qqApiInterfaceCls 	QQApiInterface class.
 *	@param 	tencentOAuthCls 	TencentOAuth class.
 */
///#end
+ (void)importQQClass:(Class)qqApiInterfaceCls
      tencentOAuthCls:(Class)tencentOAuthCls;

///#begin zh-cn
/**
 *	@brief	导入人人所需要类型，对于使用应用信息托管方式下（即registerApp中的useAppTrusteeship为YES）需要调用此方法。注：不使用SSO时可以不调用
 *
 *	@param 	renrenClientClass 	人人客户端类型,应该先引入RennSDK.framework，然后在此参数中传入[RennClient class]
 */
///#end
///#begin en
/**
 *	@brief	Import Renren classes，For application information hosting (ie registerApp in useAppTrusteeship is YES) need to call this method. Note: You not use the SSO Login when not in call
 *
 *	@param 	renrenClientClass 	RenrenClient class, You should import RennSDK.framework，Then passed [RennClient class] this parameter.
 */
///#end
+ (void)importRenRenClass:(Class)renrenClientClass;

///#begin zh-cn
/**
 *	@brief	导入微信所需要类型，对于使用应用信息托管方式下（即registerApp中的useAppTrusteeship为YES）需要调用此方法。注：如果不使用微信可以不调用
 *
 *	@param 	wechatCls 	微信Api类型，引入WXApi.h后，将[WXApi class]传入此参数
 */
///#end
///#begin en
/**
 *	@brief	Import WeChat classes，For application information hosting (ie registerApp in useAppTrusteeship is YES) need to call this method. Note：You not use the WeChat share when not in call
 *
 *	@param 	wechatCls 	WXApi class，You should import WXApi.h，Then passed [WXApi class] this parameter.
 */
///#end
+ (void)importWeChatClass:(Class)wechatCls;

///#begin zh-cn
/**
 *	@brief	导入Google+所需要的类型，对于使用应用信息托管方式下（即registerApp中的useAppTrusteeship为YES）需要调用此方法。注：如果不使用Google＋可以不调用
 *
 *  @since  ver2.4.0
 *
 *	@param 	signInClass 	登录类型，引入GooglePlus.framework后，将[GPPSignIn class]传入此参数
 *	@param 	shareClass 	分享类型，引入GooglePlush.framework后，将[GPPShare class]传入此参数
 */
///#end
///#begin en
/**
 *	@brief	Import Google+ classes，For application information hosting (ie registerApp in useAppTrusteeship is YES) need to call this method. Note：You not use the Google+ platform when not in call
 *
 *  @since  ver2.4.0
 *
 *	@param 	signInClass 	GPPSignIn class，You should import GooglePlus.framework，Then passed [GPPSignIn class] this parameter.
 *	@param 	shareClass 	GPPShare class，You should import GooglePlush.framework，Then passed [GPPShare class] this parameter.
 */
///#end
+ (void)importGooglePlusClass:(Class)signInClass
                   shareClass:(Class)shareClass;

///#begin zh-cn
/**
 *	@brief	导入Pinterest所需要的类型，对于使用应用信息托管方式下（即registerApp中的useAppTrusteeship为YES）需要调用此方法，注：如果不使用Pinterest可以不调用
 *
 *  @since  ver2.4.1
 *
 *	@param 	pinterestClass 	Pinterest接口类型。引入Pinterest.framework后，将[Pinterest class]传入此参数
 */
///#end
///#begin en
/**
 *	@brief	Import Pinterest classes，For application information hosting (ie registerApp in useAppTrusteeship is YES) need to call this method. Note：You not use the Pinterest platform when not in call
 *
 *  @since  ver2.4.1
 *
 *	@param 	pinterestClass 	Pinterest classes。You should import Pinterest.framework，Then passed [Pinterest class] this parameter.
 */
///#end
+ (void)importPinterestClass:(Class)pinterestClass;

///#begin zh-cn
/**
 *	@brief	导入易信所需要的类型，对于应用信息托管方式下（即registerApp中的useAppTrusteeship为YES）需要调用此方法，注：如果不使用易信可以不调用
 *
 *	@param 	yixinClass 	易信接口类型。引入libYixinSDK.a后，将[YXApi class]传入此参数
 */
///#end
///#begin en
/**
 *	@brief	Import YiXin classes，For application information hosting (ie registerApp in useAppTrusteeship is YES) need to call this method. Note：You not use the YiXin platform when not in call
 *
 *	@param 	yixinClass 	YXApi class。You should import libYixinSDK.a，Then passed [YXApi class] this parameter.
 */
///#end
+ (void)importYiXinClass:(Class)yixinClass;


///#begin zh-cn
/**
 *	@brief	导入支付宝朋友所需要的类型，如果不使用支付宝朋友可以不调用
 *
 *  @since  ver2.11.2
 *
 *  @param 	openApiCls          头文件导入文件"APOpenAPI.h",将[APOpenAPI class]传入此参数
 *  @param 	mediaMessageCls     将[APMediaMessage class]传入此参数
 *  @param 	shareTextObjectCls  将[APShareTextObject class]传入此参数
 *  @param 	shareImgObjectCls   将[APShareImageObject class]传入此参数
 *  @param 	webObjectCls        将[APShareWebObject class]传入此参数
 *  @param 	sendMsgToAPReqCls   将[APSendMessageToAPReq class]传入此参数
 */
///#end
///#begin en
/**
 *	@brief	Import Alipay classes，If you not use the Alipay platform when not in call
 *
 *  @since  ver2.11.2
 *
 *  @param 	openApiCls          import "APOpenAPI.h",then passed [APOpenAPI class] this parameter.
 *  @param 	mediaMessageCls     passed [APMediaMessage class] this parameter
 *  @param 	shareTextObjectCls  passed [APShareTextObject class] this parameter
 *  @param 	shareImgObjectCls   passed [APShareImageObject class] this parameter
 *  @param 	webObjectCls        passed [APShareWebObject class] this parameter
 *  @param 	sendMsgToAPReqCls   passed [APSendMessageToAPReq class] this parameter
 */
///#end

+ (void)importAlipayOpenApiCls:(Class)openApiCls
               mediaMessageCls:(Class)mediaMessageCls
            shareTextObjectCls:(Class)shareTextObjectCls
             shareImgObjectCls:(Class)shareImgObjectCls
             shareWebObjectCls:(Class)webObjectCls
         sendMessageToAPReqCls:(Class)sendMsgToAPReqCls;

///#begin zh-cn
/**
 *	@brief	如果你需要使用Facebook App（AppInvite）分享的功能,请导入Facebook SDK所需要的类型，
 *  @brief  头文件处请 import <FBSDKCoreKit/FBSDKCoreKit.h> 和 <FBSDKShareKit/FBSDKShareKit.h>
 *  @since  ver2.11.2
 
 *  @param 	applicationDelegateCls  将[FBSDKApplicationDelegate class]传入此参数
 *  @param 	appInviteDialogCls      将[FBSDKAppInviteDialog class]传入此参数
 *  @param 	appInviteContentCls     将[FBSDKAppInviteContent class]传入此参数
 */
///#end
///#begin en
/**
 *	@brief	Import Facebook classes，If you need Share App(AppInvite) to Facebook.
 *  @brief 	You need to import <FBSDKCoreKit/FBSDKCoreKit.h> and <FBSDKShareKit/FBSDKShareKit.h>.
 *  @since  ver2.11.2
 
 *  @param 	applicationDelegateCls  passed [FBSDKApplicationDelegate class] this parameter
 *  @param 	appInviteDialogCls      passed [FBSDKAppInviteDialog class] this parameter
 *  @param 	appInviteContentCls     passed [APShareImageObject class] this parameter
 */
///#end
+ (void)importFacebookShareAppWithApplicationDelegateCls:(Class)applicationDelegateCls
                                      appInviteDialogCls:(Class)appInviteDialogCls
                                     appInviteContentCls:(Class)appInviteContentCls;

#pragma mark 辅助

///#begin zh-cn
/**
 *	@brief	获取平台客户端名称
 *
 *  @since  ver1.2.4
 *
 *	@param 	type 	分享类型
 *
 *	@return	名称
 */
///#end
///#begin en
/**
 *	@brief	Get platform name.
 *
 *  @since  ver1.2.4
 *
 *	@param 	type 	Platform type.
 *
 *	@return	Platform name.
 */
///#end
+ (NSString *)getClientNameWithType:(ShareType)type;

///#begin zh-cn
/**
 *	@brief	获取平台客户端图标
 *
 *  @since  ver1.2.4
 *
 *	@param 	type 	分享类型
 *
 *	@return	图标
 */
///#end
///#begin en
/**
 *	@brief	Get platform icon.
 *
 *  @since  ver1.2.4
 *
 *	@param 	type 	Platform type.
 *
 *	@return	Platform icon.
 */
///#end
+ (UIImage *)getClientIconWithType:(ShareType)type;

///#begin zh-cn
/**
 *	@brief	获取平台客户端
 *
 *	@param 	type 	分享类型
 *
 *	@return	平台客户端
 */
///#end
///#begin en
/**
 *	@brief	Get platform object.
 *
 *	@param 	type 	Platform type.
 *
 *	@return	Platform object.
 */
///#end
+ (id<ISSPlatformApp>)getClientWithType:(ShareType)type;

///#begin zh-cn
/**
 *	@brief	获取分享列表
 *
 *	@param 	shareType 	社会化平台类型
 *
 *	@return	分享列表
 */
///#end
///#begin en
/**
 *	@brief	Create a list of platform type.
 *
 *	@param 	shareType 	Platform type.
 *
 *	@return	Platform type list array.
 */
///#end
+ (NSArray *)getShareListWithType:(ShareType)shareType, ... NS_REQUIRES_NIL_TERMINATION;

///#begin zh-cn
/**
 *	@brief	添加通知监听
 *
 *	@param 	name 	通知名称
 *	@param 	target 	目标对象
 *	@param 	action 	处理方法
 */
///#end
///#begin en
/**
 *	@brief	Add notification listen.
 *
 *	@param 	name 	Notification name.
 *	@param 	target 	Target object.
 *	@param 	action 	Notification handler.
 */
///#end
+ (void)addNotificationWithName:(NSString *)name
                         target:(id)target
                         action:(SEL)action;

///#begin zh-cn
/**
 *	@brief	移除通知监听
 *
 *	@param 	name 	通知名称
 *	@param 	target 	目标对象
 */
///#end
///#begin en
/**
 *	@brief	Remove notification listen.
 *
 *	@param 	name 	Notification name.
 *	@param 	target 	Target object.
 */
///#end
+ (void)removeNotificationWithName:(NSString *)name
                            target:(id)target;

///#begin zh-cn
/**
 *	@brief	移除全部通知监听
 *
 *	@param 	target 	目标对象
 */
///#end
///#begin en
/**
 *	@brief	Remove all notification listen.
 *
 *	@param 	target 	Target object.
 */
///#end
+ (void)removeAllNotificationWithTarget:(id)target;

///#begin zh-cn
/**
 *	@brief	创建分页对象,为提供获取关注用户列表中的page参数提供的构造方法
 *
 *	@param 	cursor 	分页游标，目前此方法仅用于Twitter，获取起始页请传入-1
 *
 *	@return 分页对象
 */
///#end
///#begin en
/**
 *	@brief	Create paging object. Construction method to get the user list page parameters provided.
 *
 *	@param 	cursor 	Cursor. This method only for Twitter,please pass -1 to get the start page
 *
 *	@return Paging object.
 */
///#end
+ (id<ISSPage>)pageWithCursor:(long long)cursor;

///#begin zh-cn
/**
 *	@brief	创建分页对象,为提供获取关注用户列表中的page参数提供的构造方法
 *
 *	@param 	pageNo 	页码
 *	@param 	pageSize 	分页尺寸
 *
 *	@return	分页对象
 */
///#end
///#begin en
/**
 *	@brief	Create paging object. Construction method to get the user list page parameters provided.
 *
 *	@param 	pageNo 	Page No.
 *	@param 	pageSize 	Page size.
 *
 *	@return	Paging object.
 */
///#end
+ (id<ISSPage>)pageWithPageNo:(NSInteger)pageNo pageSize:(NSInteger)pageSize;

///#begin zh-cn
/**
 *	@brief	创建分享内容对象，根据以下每个字段适用平台说明来填充参数值
 *
 *	@param 	content 	分享内容（新浪、腾讯、豆瓣、人人、开心、有道云笔记、facebook、twitter、邮件、打印、短信、微信、QQ、拷贝）
 *	@param 	defaultContent 	默认分享内容（新浪、腾讯、豆瓣、人人、开心、有道云笔记、facebook、twitter、邮件、打印、短信、微信、QQ、拷贝）
 *	@param 	image 	分享图片（新浪、腾讯、豆瓣、人人、开心、facebook、twitter、邮件、打印、微信、QQ、拷贝、短信）
 *	@param 	title 	标题（QQ空间、人人、微信、QQ）
 *	@param 	url 	链接（QQ空间、人人、instapaper、微信、QQ）
 *	@param 	description 	主体内容（人人）
 *	@param 	mediaType 	分享类型（QQ、微信）
 *
 *	@return	分享内容对象
 */
///#end
///#begin en
/**
 *	@brief	Create share content object. based on the following description of each field to fill the parameter values
 *
 *	@param 	content 	Share content string.（Sina Weibo、Tencent Weibo、Douban、RenRen、KaiXin、YouDaoNote、Facebook、Twitter、Mail、Print、SMS、WeChat、QQ、Copy）
 *	@param 	defaultContent 	Default share content string.（Sina Weibo、Tencent Weibo、Douban、RenRen、KaiXin、YouDaoNote、Facebook、Twitter、Mail、Print、SMS、WeChat、QQ、Copy）
 *	@param 	image 	Image attachment object.（Sina Weibo、Tencent Weibo、Douban、RenRen、KaiXin、Facebook、Twitter、Mail、Print、WeChat、QQ、Copy、SMS）
 *	@param 	title 	Title string.（QZone、RenRen、WeChat、QQ）
 *	@param 	url 	Url string.（QZone、RenRen、Instapaper、WeChat、QQ）
 *	@param 	description 	Description string（RenRen）
 *	@param 	mediaType 	MediaType（QQ、WeChat）
 *
 *	@return	Share content object.
 */
///#end
+ (id<ISSContent>)content:(NSString *)content
           defaultContent:(NSString *)defaultContent
                    image:(id<ISSCAttachment>)image
                    title:(NSString *)title
                      url:(NSString *)url
              description:(NSString *)description
                mediaType:(SSPublishContentMediaType)mediaType;

///#begin zh-cn
/**
 *	@brief	创建分享内容对象，根据一下每个字段适用平台说明来填充参数值
 *
 *  @since  ver2.4.1
 *
 *	@param 	content 	分享内容（新浪、腾讯、豆瓣、人人、开心、有道云笔记、facebook、twitter、邮件、打印、短信、微信、QQ、拷贝）
 *	@param 	defaultContent 	默认分享内容（新浪、腾讯、豆瓣、人人、开心、有道云笔记、facebook、twitter、邮件、打印、短信、微信、QQ、拷贝）
 *	@param 	image 	分享图片（新浪、腾讯、豆瓣、人人、开心、facebook、twitter、邮件、打印、微信、QQ、拷贝、短信）
 *	@param 	title 	标题（QQ空间、人人、微信、QQ）
 *	@param 	url 	链接（QQ空间、人人、instapaper、微信、QQ）
 *	@param 	description 	主体内容（人人）
 *	@param 	mediaType 	分享类型（QQ、微信）
 *	@param 	locationCoordinate 	地理位置 (新浪、腾讯、Twitter)
 *
 *	@return	分享内容对象
 */
///#end
///#begin en
/**
 *	@brief	Create share content object. based on the following description of each field to fill the parameter values
 *
 *  @since  ver2.4.1
 *
 *	@param 	content 	Share content string.（Sina Weibo、Tencent Weibo、Douban、RenRen、KaiXin、YouDaoNote、Facebook、Twitter、Mail、Print、SMS、WeChat、QQ、Copy）
 *	@param 	defaultContent 	Default share content string.（Sina Weibo、Tencent Weibo、Douban、RenRen、KaiXin、YouDaoNote、Facebook、Twitter、Mail、Print、SMS、WeChat、QQ、Copy）
 *	@param 	image 	Image attachment object.（Sina Weibo、Tencent Weibo、Douban、RenRen、KaiXin、Facebook、Twitter、Mail、Print、WeChat、QQ、Copy、SMS）
 *	@param 	title 	Title string.（QZone、RenRen、WeChat、QQ）
 *	@param 	url 	Url string.（QZone、RenRen、Instapaper、WeChat、QQ）
 *	@param 	description 	Description string（RenRen）
 *	@param 	mediaType 	MediaType（QQ、WeChat）
 *	@param 	locationCoordinate 	Location information. (Sina Weibo、Tencent Weibo、Twitter)
 *
 *	@return	Share content object.
 */
///#end
+ (id<ISSContent>)content:(NSString *)content
           defaultContent:(NSString *)defaultContent
                    image:(id<ISSCAttachment>)image
                    title:(NSString *)title
                      url:(NSString *)url
              description:(NSString *)description
                mediaType:(SSPublishContentMediaType)mediaType
       locationCoordinate:(SSCLocationCoordinate2D *)locationCoordinate;

///#begin zh-cn
/**
 *	@brief	创建分享内容对象，根据一下每个字段适用平台说明来填充参数值
 *
 *  @since  ver2.6.0
 *
 *	@param 	content 	分享内容（新浪、腾讯、豆瓣、人人、开心、有道云笔记、facebook、twitter、邮件、打印、短信、微信、QQ、拷贝）
 *	@param 	defaultContent 	默认分享内容（新浪、腾讯、豆瓣、人人、开心、有道云笔记、facebook、twitter、邮件、打印、短信、微信、QQ、拷贝）
 *	@param 	image 	分享图片（新浪、腾讯、豆瓣、人人、开心、facebook、twitter、邮件、打印、微信、QQ、拷贝、短信）
 *	@param 	title 	标题（QQ空间、人人、微信、QQ）
 *	@param 	url 	链接（QQ空间、人人、instapaper、微信、QQ）
 *	@param 	description 	主体内容（人人）
 *	@param 	mediaType 	分享类型（QQ、微信）
 *	@param 	locationCoordinate 	地理位置 (新浪、腾讯、Twitter)
 *  @param  groupId     分组标识
 *
 *	@return	分享内容对象
 */
///#end
///#begin en
/**
 *	@brief	Create share content object. based on the following description of each field to fill the parameter values
 *
 *  @since  ver2.6.0
 *
 *	@param 	content 	Share content string.（Sina Weibo、Tencent Weibo、Douban、RenRen、KaiXin、YouDaoNote、Facebook、Twitter、Mail、Print、SMS、WeChat、QQ、Copy）
 *	@param 	defaultContent 	Default share content string.（Sina Weibo、Tencent Weibo、Douban、RenRen、KaiXin、YouDaoNote、Facebook、Twitter、Mail、Print、SMS、WeChat、QQ、Copy）
 *	@param 	image 	Image attachment object.（Sina Weibo、Tencent Weibo、Douban、RenRen、KaiXin、Facebook、Twitter、Mail、Print、WeChat、QQ、Copy、SMS）
 *	@param 	title 	Title string.（QZone、RenRen、WeChat、QQ）
 *	@param 	url 	Url string.（QZone、RenRen、Instapaper、WeChat、QQ）
 *	@param 	description 	Description string（RenRen）
 *	@param 	mediaType 	MediaType（QQ、WeChat）
 *	@param 	locationCoordinate 	Location information. (Sina Weibo、Tencent Weibo、Twitter)
 *  @param  groupId     Group id (VK)
 *
 *	@return	Share content object.
 */
///#end
+ (id<ISSContent>)content:(NSString *)content
           defaultContent:(NSString *)defaultContent
                    image:(id<ISSCAttachment>)image
                    title:(NSString *)title
                      url:(NSString *)url
              description:(NSString *)description
                mediaType:(SSPublishContentMediaType)mediaType
       locationCoordinate:(SSCLocationCoordinate2D *)locationCoordinate
                  groupId:(NSString *)groupId;

///#begin zh-cn
/**
 *	@brief	获取图片信息
 *
 *	@param 	path 	图片路径
 *
 *	@return 图片信息
 */
///#end
///#begin en
/**
 *	@brief	Create image attachment object.
 *
 *	@param 	path 	Image path.
 *
 *	@return Attachment object.
 */
///#end
+ (id<ISSCAttachment>)imageWithPath:(NSString *)path;

///#begin zh-cn
/**
 *	@brief	获取图片信息
 *
 *	@param 	url 	图片网址
 *
 *	@return	图片信息
 */
///#end
///#begin en
/**
 *	@brief	Create image attachment object.
 *
 *	@param 	url 	Image url.
 *
 *	@return	Attachment object.
 */
///#end
+ (id<ISSCAttachment>)imageWithUrl:(NSString *)url;

///#begin zh-cn
/**
 *	@brief	创建JPEG图片信息
 *
 *	@param 	image 	图片对象
 *  @param  quality 图片质量
 *
 *	@return	图片信息
 */
///#end
///#begin en
/**
 *	@brief	Create jpeg image attachment object.
 *
 *	@param 	image 	UIImage object.
 *  @param  quality Image quality(0 ~ 1)
 *
 *	@return	Attachment object.
 */
///#end
+ (id<ISSCAttachment>)jpegImageWithImage:(UIImage *)image quality:(CGFloat)quality;

///#begin zh-cn
/**
 *	@brief	创建PNG图片信息
 *
 *	@param 	image 	图片对象
 *
 *	@return	图片信息
 */
///#end
///#begin en
/**
 *	@brief	Create png image attachment object.
 *
 *	@param 	image 	UIImage object.
 *
 *	@return	Attachment object.
 */
///#end
+ (id<ISSCAttachment>)pngImageWithImage:(UIImage *)image;

///#begin zh-cn
/**
 *	@brief	获取图片信息
 *
 *	@param 	data 	图片数据
 *	@param 	fileName 	文件名称
 *	@param 	mimeType 	MIME类型
 *
 *	@return	图片信息
 */
///#end
///#begin en
/**
 *	@brief	Create image attachment object.
 *
 *	@param 	data 	Image data.
 *	@param 	fileName 	File name.
 *	@param 	mimeType 	MIME type.
 *
 *	@return	Attachment object.
 */
///#end
+ (id<ISSCAttachment>)imageWithData:(NSData *)data
                           fileName:(NSString *)fileName
                           mimeType:(NSString *)mimeType;
///#begin zh-cn
/**
 *	@brief	创建容器对象
 *
 *	@return	容器对象
 */
///#end
///#begin en
/**
 *	@brief	Create container.
 *
 *	@return	Container object.
 */
///#end
+ (id<ISSContainer>)container;

///#begin zh-cn
/**
 *	@brief	创建自定义分享菜单项
 *
 *  @since  ver1.2.3
 *
 *	@param 	title 	标题
 *	@param 	icon 	图标
 *	@param 	clickHandler 	点击事件处理器
 *
 *	@return	分享菜单项
 */
///#end
///#begin en
/**
 *	@brief	Create custom share menu item.
 *
 *  @since  ver1.2.3
 *
 *	@param 	title 	Title string.
 *	@param 	icon 	Icon image.
 *	@param 	clickHandler 	Click event handler.
 *
 *	@return	Share menu item.
 */
///#end
+ (id<ISSShareActionSheetItem>)shareActionSheetItemWithTitle:(NSString *)title
                                                        icon:(UIImage *)icon
                                                clickHandler:(SSShareActionSheetItemClickHandler)clickHandler;

///#begin zh-cn
/**
 *	@brief	创建附件信息,用于设置有道云笔记平台的附件信息。
 *
 *	@param 	data 	附件数据
 *	@param 	mimeType 	附件类型
 *  @param  fileName    附件名称
 *
 *	@return	附件信息
 */
///#end
///#begin en
/**
 *	@brief	Create attachment object.
 *
 *	@param 	data 	Attachment data.
 *	@param 	mimeType 	MIME type.
 *  @param  fileName    File name.
 *
 *	@return	Attachment object.
 */
///#end
+ (id<ISSCAttachment>)attachmentWithData:(NSData *)data mimeType:(NSString *)mimeType fileName:(NSString *)fileName;

///#begin zh-cn
/**
 *	@brief	创建自定义分享列表
 *
 *	@param 	item 分享列表项，可以为包含ShareType的NSNumber类型，也可以为由shareActionSheetItemWithTitle创建的ISSShareActionSheetItem类型对象。
 *
 *	@return	分享列表
 */
///#end
///#begin en
/**
 *	@brief	Create custom share list.
 *
 *	@param 	item Share menu item object，Can contain ShareType of NSNumber type, You can also call shareActionSheetItemWithTitle method create ISSShareActionSheetItem objects.
 *
 *	@return	Share list array.
 */
///#end
+ (NSArray *)customShareListWithType:(id)item, ... NS_REQUIRES_NIL_TERMINATION;

///#begin zh-cn
/**
 *	@brief	设置屏幕方向,默认是所有方向
 *
 *	@param 	interfaceOrientationMask 	屏幕方向掩码
 */
///#end
///#begin en
/**
 *	@brief	Set interface orientation. Default SSInterfaceOrientationMaskAll
 *
 *	@param 	interfaceOrientationMask 	Interface orientation.
 */
///#end
+ (void)setInterfaceOrientationMask:(SSInterfaceOrientationMask)interfaceOrientationMask;

///#begin zh-cn
/**
 *	@brief	将授权凭证进行序列化
 *
 *  @since  ver2.6.0    修复返回的类型
 *
 *	@param 	credential 	序列化凭证
 *
 *	@return	序列化后的数据
 */
///#end
///#begin en
/**
 *	@brief	Serialization authorization credential.
 *
 *  @since  ver2.6.0    Fix return type
 *
 *	@param 	credential 	Credential object.
 *
 *	@return	Serialized data.
 */
///#end
+ (NSData *)dataWithCredential:(id<ISSPlatformCredential>)credential;

///#begin zh-cn
/**
 *	@brief	创建用户信息
 *
 *  @since  ver2.0.1
 *  @since  ver2.6.0    修复返回类型
 *
 *	@param 	localUser 	平台相关用户信息
 *	@param 	type 	平台类型
 *
 *	@return	用户信息
 */
///#end
///#begin en
/**
 *	@brief	Create user object
 *
 *  @since  ver2.0.1
 *  @since  ver2.6.0    Fix return type.
 *
 *	@param 	localUser 	Platform user info.
 *	@param 	type 	Platform type.
 *
 *	@return	User object.
 */
///#end
+ (id<ISSPlatformUser>)userWithLocalUser:(id)localUser type:(ShareType)type;

///#begin zh-cn
/**
 *	@brief	创建状态信息
 *
 *  @since  ver2.0.1
 *  @since  ver2.6.0    修复返回类型
 *
 *	@param 	localStatus 	平台相关的状态信息
 *	@param 	type 	平台类型
 *
 *	@return	状态信息
 */
///#end
///#begin en
/**
 *	@brief	Create share info object.
 *
 *  @since  ver2.0.1
 *  @since  ver2.6.0    Fix return type.
 *
 *	@param 	localStatus 	Platform share information.
 *	@param 	type 	Platform type.
 *
 *	@return	Share information object.
 */
///#end
+ (id<ISSPlatformShareInfo>)statusWithLocalStatus:(id)localStatus type:(ShareType)type;

///#begin zh-cn
/**
 *	@brief	创建用户信息字段
 *
 *  @since  ver2.1.1
 *
 *	@param 	type 	用户字段类型
 *	@param 	value 	用户字段值
 *
 *	@return	用户信息字段
 */
///#end
///#begin en
/**
 *	@brief	Create user field object.
 *
 *  @since  ver2.1.1
 *
 *	@param 	type 	Field type.
 *	@param 	value 	Field value.
 *
 *	@return	Field object.
 */
///#end
+ (id<ISSUserField>)userFieldWithType:(SSUserFieldType)type value:(NSString *)value;

///#begin zh-cn
/**
 *	@brief	显示顶部状态栏显示消息,此消息会一直显示，直到调用hideStatusbarMessage为止
 *
 *  @since  ver2.2.0
 *
 *	@param 	message 	消息内容
 */
///#end
///#begin en
/**
 *	@brief	at the status bar displays the message, this message will be displayed until call hideStatusbarMessage method
 *
 *  @since  ver2.2.0
 *
 *	@param 	message 	Message content.
 */
///#end
+ (void)showStatusbarMessage:(NSString *)message;

///#begin zh-cn
/**
 *	@brief	隐藏顶部状态消息。
 *
 *  @since  ver2.2.0
 *
 */
///#end
///#begin en
/**
 *	@brief	hide status bar message.
 *
 *  @since  ver2.2.0
 *
 */
///#end
+ (void)hideStatusbarMessage;

///#begin zh-cn
/**
 *	@brief	显示临时消息，此消息再一定时间内容消失，此消息内容不受hideStatusbarMessage控制。
 *
 *  @since  ver2.2.0
 *
 *	@param 	message 	消息内容
 */
///#end
///#begin en
/**
 *	@brief	Show temporary message. This message is erased in a certain time. This message content is not hideStatusbarMessage control.
 *
 *  @since  ver2.2.0
 *
 *	@param 	message 	Message content.
 */
///#end
+ (void)showStatusbarImmediMessage:(NSString *)message;

///#begin zh-cn
/**
 *	@brief	等待应用配置信息完成,此方法专门针对使用应用信息托管时使用，由于从服务器下发信息需要时间，
 *          因此在调用平台api之前先调用此方法等待完成后做相应操作。
 *  
 *  @since  ver2.2.6
 *
 *  @param  completeHandler     完成处理事件
 */
///#end
///#begin en
/**
 *	@brief	Wait for get the application configuration information completed. This method is used for the application information Hosting。Because the information issued from the server takes time, So before calling platform api call this method accordingly to wait after the completion of the operation.
 *
 *  @since  ver2.2.6
 *
 *  @param  completeHandler     Completed event handler.
 */
///#end
+ (void)waitAppSettingComplete:(void(^)())completeHandler;

///#begin zh-cn
/**
 *	@brief	获取已连接的平台类型列表
 *
 *  @since  ver2.6.0
 *
 *	@return	已连接平台列表，其元素为包含ShareType的NSNumber对象
 */
///#end
///#begin en
/**
 *	@brief	Get initialize platform type list.
 *
 *  @since  ver2.6.0
 *
 *	@return	Platform type list array. Its elements of NSNumber object containing ShareType
 */
///#end
+ (NSArray *)connectedPlatformTypes;

///#begin zh-cn
/**
 *	@brief	获取当前SDK版本号
 *
 *  @since  ver2.6.0
 *
 *	@return	版本号
 */
///#end
///#begin en
/**
 *	@brief	Get current version.
 *
 *  @since  ver2.6.0
 *
 *	@return	Version string.
 */
///#end
+ (NSString *)version;

/**
 *  获取SDK版本，等同于+ (NSString *)version，接口兼容需要。
 *
 *  @return 版本号
 */
+ (NSString *)sdkVer;

///#begin zh-cn
/**
 *	@brief	设置UI显示风格，默认为iOS7风格
 *
 *  @since  ver2.9.0
 *
 *	@param 	style 	UI显示风格
 */
///#end
///#begin en
/**
 *	@brief	Set UI style, Default is iOS7 Style.
 *
 *  @since  ver2.9.0
 *
 *	@param 	style 	UI style.
 */
///#end
+ (void)setUIStyle:(SSUIStyle)style;


#pragma mark 授权

///#begin zh-cn
/**
 *	@brief	反序列化数据为授权凭证
 *
 *  @since  ver2.6.0    调整返回的类型
 *
 *	@param 	data 	授权凭证序列化后的数据
 *	@param 	type 	类型
 *
 *	@return	授权凭证
 */
///#end
///#begin en
/**
 *	@brief	Deserialize data to credential object
 *
 *  @since  ver2.6.0    Fix return type.
 *
 *	@param 	data 	credential data.
 *	@param 	type 	Platform type.
 *
 *	@return	Credential object.
 */
///#end
+ (id<ISSPlatformCredential>)credentialWithData:(NSData *)data type:(ShareType)type;

///#begin zh-cn
/**
 *	@brief	创建授权凭证,通过其他途径获取到的授权数据通过此接口转换为凭证对象传入SDK
 *
 *  @since  ver2.6.0
 *
 *  @param  type    平台类型
 *	@param 	uid 	授权用户标识
 *	@param 	token 	访问令牌，在OAuth中为oauth_token，在OAuth2中为access_token
 *	@param 	secret 	访问令牌密钥，仅用于OAuth授权中，为oauth_token_secret。
 *	@param 	expired 	过期时间，仅用于OAuth2授权中，需要将返回的秒数转换为时间。
 *	@param 	extInfo 	扩展信息。用于存放除上述信息外的其它信息。
 *
 *	@return	授权凭证
 */
///#end
///#begin en
/**
 *	@brief	Create credentail object. Authorization data obtained by other methods incoming SDK convert credentials through this interface
 *
 *  @since  ver2.6.0
 *
 *  @param  type    Platform type.
 *	@param 	uid 	User id.
 *	@param 	token 	Token string，In OAuth is oauth_token，In OAuth2 is access_token
 *	@param 	secret 	Secret string. Only for OAuth，is oauth_token_secret attribute。
 *	@param 	expired 	Expires，Only for OAuth2，Need to return to a time in seconds.
 *	@param 	extInfo 	Extended information. Used to store other information in addition to the above information away.
 *
 *	@return	Credential object.
 */
///#end
+ (id<ISSPlatformCredential>)credentialWithType:(ShareType)type
                                            uid:(NSString *)uid
                                          token:(NSString *)token
                                         secret:(NSString *)secret
                                        expired:(NSDate *)expired
                                        extInfo:(NSDictionary *)extInfo;

///#begin zh-cn
/**
 *	@brief	获取授权凭证,凭证中包含accessToken或oauthToken、过期时间等信息
 *
 *  @since  ver2.6.0    修改返回类型
 *
 *	@param 	type 	平台类型
 *
 *	@return	授权凭证
 */
///#end
///#begin en
/**
 *	@brief	Get credential object, Certificate contains accessToken or oauthToken, expiration date and other information
 *
 *  @since  ver2.6.0    Fix return type
 *
 *	@param 	type 	Platform type.
 *
 *	@return	Credential object.
 */
///#end
+ (id<ISSPlatformCredential>)getCredentialWithType:(ShareType)type;

///#begin zh-cn
/**
 *	@brief	设置授权凭证
 *
 *  @since  ver2.6.0    修复凭证类型
 *
 *	@param 	credential 	授权凭证
 *	@param 	type 	平台类型
 */
///#end
///#begin en
/**
 *	@brief	Set credential object.
 *
 *  @since  ver2.6.0    Fix return type.
 *
 *	@param 	credential 	Credential object.
 *	@param 	type 	Platform type.
 */
///#end
+ (void)setCredential:(id<ISSPlatformCredential>)credential type:(ShareType)type;

///#begin zh-cn
/**
 *	@brief	创建授权选项
 *
 *	@param 	autoAuth 	自动授权标志，当分享内容时发现授权过期是否委托SDK处理授权问题，YES：表示委托授权， NO：表示不委托授权，需要自己根据返回值进行判断和处理
 *  @param  allowCallback   是否允许授权后回调到服务器，默认为YES，对于没有服务器或者不需要回调服务器的应用可以设置为NO
 *	@param 	authViewStyle 	授权视图样式，参考SSAuthViewStyle枚举类型
 *  @param  viewDelegate    授权视图协议委托，可通过视图委托来实现UI细节调整等。
 *  @param  authManagerViewDelegate     授权管理器视图协议委托。可通过委托实现UI细节调整等。
 *
 *	@return	授权选项
 */
///#end
///#begin en
/**
 *	@brief	Create authorized options.
 *
 *	@param 	autoAuth 	Automatic authorization flag, When authorized expired, Whether SDK has automatic show authorized view let user to completed authorized.
 *  @param  allowCallback   Whether to allow authorized after the callback to the server, the default is YES, for there is no server or application server does not require a callback can be set to NO
 *	@param 	authViewStyle 	Authorized view style，Please see SSAuthViewStyle.
 *  @param  viewDelegate    Authorized view delegate，Can adjustment the view details of the UI.
 *  @param  authManagerViewDelegate     Authorized manager view delegate。Can adjustment the view details of the UI.
 *
 *	@return	Authorized options.
 */
///#end
+ (id<ISSAuthOptions>)authOptionsWithAutoAuth:(BOOL)autoAuth
                                allowCallback:(BOOL)allowCallback
                                authViewStyle:(SSAuthViewStyle)authViewStyle
                                 viewDelegate:(id<ISSViewDelegate>)viewDelegate
                      authManagerViewDelegate:(id<ISSViewDelegate>)authManagerViewDelegate;

///#begin zh-cn
/**
 *	@brief	创建授权选项
 *
 *  @since  ver2.1.1    增加授权权限列表
 *
 *	@param 	autoAuth 	自动授权标志，当分享内容时发现授权过期是否委托SDK处理授权问题，YES：表示委托授权， NO：表示不委托授权，需要自己根据返回值进行判断和处理
 *  @param  allowCallback   是否允许授权后回调到服务器，默认为YES，对于没有服务器或者不需要回调服务器的应用可以设置为NO
 *  @param  scopes      授权权限列表，如果默认请求权限可以设置为nil，否则需要参考各个平台的权限相关内容进行填写, value是权限列表， key为分享平台ID
 *  @param  powerByHidden   版权信息隐藏标识，如果为NO则在导航栏右边显示版权信息字样，YES 表示隐藏。默认为NO。
 *  @param  followAccounts      关注的微博账号信息，为字典结构，key为分享类型，value为ISSUserField对象(此属性仅用于Modal视图样式，并且仅在新浪微博和腾讯微博中有效)。
 *	@param 	authViewStyle 	授权视图样式，参考SSAuthViewStyle枚举类型
 *  @param  viewDelegate    授权视图协议委托，可通过视图委托来实现UI细节调整等。
 *  @param  authManagerViewDelegate     授权管理器视图协议委托。可通过委托实现UI细节调整等。
 *
 *	@return	授权选项
 */
///#end
///#begin en
/**
 *	@brief	Create an authorize options.
 *
 *  @since  ver2.1.1    Add authorize scopes list.
 *
 *	@param 	autoAuth 	Automatic authorization flag,When authorized expired, Whether SDK has automatic show authorized view let user to completed authorized.
 *  @param  allowCallback   Whether to allow authorized after the callback to the server, the default is YES, for there is no server or application server does not require a callback can be set to NO
 *  @param  scopes     Get authorized scopes. If the default request scopes can be set to nil, otherwise the need to refer to the relevant authority content of each platform to fill. key is platform type number. value is contain scope string's array.
 *  @param  powerByHidden   powered by hidden flag. If NO in the navigation bar displays the word copyright information, YES, said hidden. The default is NO.
 *  @param  followAccounts      follower accounts dictionary object，key is platform type number. value is ISSUserField's protocol object.(This property is used only for Modal view style, and is only valid on Sina Weibo and Tencent Weibo)。
 *	@param 	authViewStyle 	View style，Please see SSAuthViewStyle.
 *  @param  viewDelegate    Authorized view delegate. Can adjustment the view details of the UI.
 *  @param  authManagerViewDelegate     Authorized manager view delegate。Can adjustment the view details of the UI.
 *
 *	@return	Authorized options.
 */
///#end
+ (id<ISSAuthOptions>)authOptionsWithAutoAuth:(BOOL)autoAuth
                                allowCallback:(BOOL)allowCallback
                                       scopes:(NSDictionary *)scopes
                                powerByHidden:(BOOL)powerByHidden
                               followAccounts:(NSDictionary *)followAccounts
                                authViewStyle:(SSAuthViewStyle)authViewStyle
                                 viewDelegate:(id<ISSViewDelegate>)viewDelegate
                      authManagerViewDelegate:(id<ISSViewDelegate>)authManagerViewDelegate;

///#begin zh-cn
/**
 *	@brief	创建授权控制器，此方法用于自定义授权页面时使用,可以自由控制授权UI及过程。(注：邮件、短信、打印、拷贝类型不支持授权功能。)
 *
 *  @since  ver2.6.0    修改返回类型
 *
 *	@param 	type 	平台类型
 *
 *	@return	授权会话
 */
///#end
///#begin en
/**
 *	@brief	Create an authorize controller，This method is used when the custom authorization page, you can freely control the authorization UI and process. (Note: Mail, SMS, Print, Copy does not support authorization feature.)
 *
 *  @since  ver2.6.0    Fix return type.
 *
 *	@param 	type 	Platform type.
 *
 *	@return	Authorize session.
 */
///#end
+ (id<ISSPlatformAuthSession>)authorizeController:(ShareType)type;

///#begin zh-cn
/**
 *	@brief	显示授权界面，(注：邮件、短信、打印、拷贝类型不支持授权功能。)
 *
 *	@param 	type    社会化平台类型
 *  @param  options 授权选项，如果为nil则表示使用默认设置
 *  @param  result    授权返回事件处理
 */
///#end
///#begin en
/**
 *	@brief	Show authorize view，(Note: Mail, SMS, Print, Copy does not support authorization feature.)
 *
 *	@param 	type    Platform type.
 *  @param  options Authorized options，Used to authorization for custom configuration（Such as: whether the automatic authorization, authorization view style, etc.）Default nil.
 *  @param  result    Result handler.
 */
///#end
+ (void)authWithType:(ShareType)type
             options:(id<ISSAuthOptions>)options
              result:(SSAuthEventHandler)result;

///#begin zh-cn
/**
 *	@brief	判断是否授权,邮件、短信、打印、拷贝类型不支持授权功能。
 *
 *	@param 	type 	社会化平台类型
 *
 *	@return	YES 已授权； NO 未授权
 */
///#end
///#begin en
/**
 *	@brief	Determine whether to authorize flag. WeChat, QQ, Mail, SMS, Print, Copy does not support authorization feature.
 *
 *	@param 	type 	Platform type.
 *
 *	@return	YES authorized; NO unauthorized
 */
///#end
+ (BOOL)hasAuthorizedWithType:(ShareType)type;

///#begin zh-cn
/**
 *	@brief	取消授权,邮件、短信、打印、拷贝类型不支持授权功能。
 *
 *	@param 	type 	社会化平台类型
 */
///#end
///#begin en
/**
 *	@brief	Cancel authorized.Mail, SMS, Print, Copy dose not support authorized feature.
 *
 *	@param 	type 	Platform type.
 */
///#end
+ (void)cancelAuthWithType:(ShareType)type;

///#begin zh-cn
/**
 *	@brief	获取当前授权用户
 *
 *  @since  ver2.6.0
 *
 *	@param 	type 	平台类型
 *
 *	@return	用户信息
 */
///#end
///#begin en
/**
 *	@brief	Get current authorization user.
 *
 *  @since  ver2.6.0
 *
 *	@param 	type 	Platform type.
 *
 *	@return	User object.
 */
///#end
+ (id<ISSPlatformUser>)currentAuthUserWithType:(ShareType)type;

///#begin zh-cn
/**
 *	@brief	设置当前授权用户，当有多个授权用户的时候可以使用此方法进行切换。
 *
 *  @since  ver2.6.0
 *
 *	@param 	user 	用户信息，注：此用户信息必须已经包含授权凭证，否则设置后无法进行相关功能接口调用，会要求重新进行授权。
 *	@param 	type 	平台类型
 *
 */
///#end
///#begin en
/**
 *	@brief	Set current authorization user. When there are multiple authorized users when you can use this method to switch.
 *
 *  @since  ver2.6.0
 *
 *	@param 	user 	User object，Note: This information must already contain user authorization credential, or can not be related to functional interface called after setting will require re-authorization.
 *	@param 	type 	Platform type.
 *
 */
///#end
+ (void)setCurrentAuthUser:(id<ISSPlatformUser>)user type:(ShareType)type;

///#begin zh-cn
/**
 *	@brief	获取授权用户列表
 *
 *  @since  ver2.6.0
 *
 *	@param 	type 	平台类型
 *
 *	@return	用户信息列表
 */
///#end
///#begin en
/**
 *	@brief	Get a list of authorization user.
 *
 *  @since  ver2.6.0
 *
 *	@param 	type 	Platform type.
 *
 *	@return	Users list array.
 */
///#end
+ (NSArray *)authorizedUsersWithType:(ShareType)type;

#pragma mark 用户信息

///#begin zh-cn
/**
 *	@brief	获取当前授权用户信息
 *
 *	@param 	shareType 	平台类型
 *  @param  authOptions 授权选项，用于指定接口在需要授权时的一些属性（如：是否自动授权，授权视图样式等）,传入nil表示使用默认选项
 *  @param  result  获取用户信息返回事件
 */
///#end
///#begin en
/**
 *	@brief	Get current authorization user information.
 *
 *	@param 	shareType 	Platform type.
 *  @param  authOptions Authorized options，Used to authorization for custom configuration（Such as: whether the automatic authorization, authorization view style, etc.）Default nil.
 *  @param  result  Result handler.
 */
///#end
+ (void)getUserInfoWithType:(ShareType)shareType
                authOptions:(id<ISSAuthOptions>)authOptions
                     result:(SSGetUserInfoEventHandler)result;

///#begin zh-cn
/**
 *	@brief	获取用户信息
 *
 *	@param 	type 	平台类型
 *	@param 	field 	用户信息字段值，用于指定对应用户的标识字段。
 *	@param 	fieldType 	字段类型，标识是用户ID、用户名称
 *  @param  authOptions 授权选项，用于指定接口在需要授权时的一些属性（如：是否自动授权，授权视图样式等）,设置未nil则表示采用默认选项
 *  @param  result  获取用户信息返回事件
 */
///#end
///#begin en
/**
 *	@brief	Get user information.
 *
 *	@param 	type 	Platform type.
 *	@param 	field 	User Information field value. is used to specify the user identification field.
 *	@param 	fieldType 	Field type, identifies a user ID, ​​user name
 *  @param  authOptions Authorized options，Used to authorization for custom configuration（Such as: whether the automatic authorization, authorization view style, etc.）Default nil.
 *  @param  result  Result handler.
 */
///#end
+ (void)getUserInfoWithType:(ShareType)type
                      field:(NSString *)field
                  fieldType:(SSUserFieldType)fieldType
                authOptions:(id<ISSAuthOptions>)authOptions
                     result:(SSGetUserInfoEventHandler)result;

#pragma mark 关系

///#begin zh-cn
/**
 *	@brief	关注用户
 *
 *	@param 	type 	平台类型
 *	@param 	field 	用户信息字段值，用于指定对应用户的标识字段。
 *	@param 	fieldType 	字段类型，标识是用户ID、用户名称
 *	@param 	authOptions 	授权选项，用于指定接口在需要授权时的一些属性（如：是否自动授权，授权视图样式等）,设置未nil则表示采用默认选项
 *  @param  viewDelegate    视图委托对象，对于Facebook的关注用户会弹出视图，该委托则用于派发视图的相关行为通知。非Facebook平台可以传入nil
 *	@param 	result 	关注用户返回事件
 */
///#end
///#begin en
/**
 *	@brief	Concern user.
 *
 *	@param 	type 	Platform type.
 *	@param 	field 	User Information field value. is used to specify the user identification field.
 *	@param 	fieldType 	Field type, identifies a user ID, ​​user name
 *	@param 	authOptions 	Authorized options，Used to authorization for custom configuration（Such as: whether the automatic authorization, authorization view style, etc.）Default nil.
 *  @param  viewDelegate    View delegate object，Concern for Facebook users will pop-up view, the delegate is used to distribute the view related behaviors notification. Non-Facebook platform can pass nil
 *	@param 	result 	Result handler.
 */
///#end
+ (void)followUserWithType:(ShareType)type
                     field:(NSString *)field
                 fieldType:(SSUserFieldType)fieldType
               authOptions:(id<ISSAuthOptions>)authOptions
              viewDelegate:(id<ISSViewDelegate>)viewDelegate
                    result:(SSFollowUserEventHandler)result;

///#begin zh-cn
/**
 *	@brief	获取授权用户的关注用户列表
 *
 *	@param 	type 	社会化平台类型
 *	@param 	page 	分页对象
 *  @param  authOptions 授权选项，用于指定接口在需要授权时的一些属性（如：是否自动授权，授权视图样式等）,设置未nil则表示采用默认选项
 *	@param 	result 	获取好友列表返回事件
 */
///#end
///#begin en
/**
 *	@brief	Get friends list.
 *
 *	@param 	type 	Platform type.
 *	@param 	page 	Paging object.
 *  @param  authOptions Authorized options，Used to authorization for custom configuration（Such as: whether the automatic authorization, authorization view style, etc.）Default nil.
 *	@param 	result 	Result handler.
 */
///#end
+ (void)getFriendsWithType:(ShareType)type
                      page:(id<ISSPage>)page
               authOptions:(id<ISSAuthOptions>)authOptions
                    result:(SSFriendsResultEvent)result;

#pragma mark 分享

///#begin zh-cn
/**
 *	@brief	创建默认分享选项
 *
 *	@param 	title 	分享视图标题
 *	@param 	oneKeyShareList 	一键分享列表，传入[NSArray defaultOneKeyShareList]表示使用默认分享列表，为nil则表示不需要一键分享
 *	@param 	qqButtonHidden 	QQ分享按钮是否隐藏,如果不隐藏则显示在分享视图的工具栏右侧，默认显示
 *	@param 	wxSessionButtonHidden 	微信好友分享按钮是否隐藏，如果不隐藏则显示在分享视图的工具栏右侧，默认显示
 *	@param 	wxTimelineButtonHidden 	微信朋友圈分享按钮是否隐藏，如果不隐藏则显示在分享视图的工具栏右侧，默认显示
 *	@param 	showKeyboardOnAppear 	分享视图显示时是否同时显示键盘，如果不显示键盘则显示一键分享列表，默认不显示
 *	@param 	shareViewDelegate 	分享视图委托，如果不需要控制视图则传入nil
 *	@param 	friendsViewDelegate 	好友视图委托，如果不需要控制视图则传入nil
 *	@param 	picViewerViewDelegate 	图片查看器视图委托，如果不需要控制视图则传入nil
 *
 *	@return	分享选项
 */
///#end
///#begin en
/**
 *	@brief	Create a share opitons for default share view.
 *
 *	@param 	title 	Title string.
 *	@param 	oneKeyShareList 	One key share list，Incoming [NSArray defaultOneKeyShareList] indicates the default sharing list. Is nil, said is not required to one key share
 *	@param 	qqButtonHidden 	QQ share button hidden flag. If you do not hide, Then display on the share view toolbar by the right side, the default display.
 *	@param 	wxSessionButtonHidden 	WeChat Session button hidden flag，If you do not hide, Then display on the share view toolbar by the right side, the default display.
 *	@param 	wxTimelineButtonHidden 	WeChat Timeline button hidden flag，If you do not hide, Then display on the share view toolbar by the right side, the default display.
 *	@param 	showKeyboardOnAppear 	Whether in view of the display when the keyboard is displayed, the default NO. When on key share list is nil, this value is invalid.
 *	@param 	shareViewDelegate 	Share view delegate，If you do not control the view of the incoming nil
 *	@param 	friendsViewDelegate 	Friends view delegate，If you do not control the view of the incoming nil
 *	@param 	picViewerViewDelegate 	Picture viewer delegate，If you do not control the view of the incoming nil
 *
 *	@return	分享选项
 */
///#end
+ (id<ISSShareOptions>)defaultShareOptionsWithTitle:(NSString *)title
                                    oneKeyShareList:(NSArray *)oneKeyShareList
                                     qqButtonHidden:(BOOL)qqButtonHidden
                              wxSessionButtonHidden:(BOOL)wxSessionButtonHidden
                             wxTimelineButtonHidden:(BOOL)wxTimelineButtonHidden
                               showKeyboardOnAppear:(BOOL)showKeyboardOnAppear
                                  shareViewDelegate:(id<ISSShareViewDelegate>)shareViewDelegate
                                friendsViewDelegate:(id<ISSViewDelegate>)friendsViewDelegate
                              picViewerViewDelegate:(id<ISSViewDelegate>)picViewerViewDelegate;

///#begin zh-cn
/**
 *	@brief	创建默认分享选项
 *
 *  @since  ver2.2.0
 *
 *	@param 	title 	分享视图标题
 *	@param 	oneKeyShareList 	一键分享列表，传入[NSArray defaultOneKeyShareList]表示使用默认分享列表，为nil则表示不需要一键分享
 *	@param 	cameraButtonHidden 	拍照按钮是否隐藏,如果不隐藏则显示再分享视图的工具栏左侧，默认显示
 *	@param 	mentionButtonHidden 	@按钮是否隐藏,如果不隐藏则显示再分享视图的工具栏左侧，默认显示
 *	@param 	topicButtonHidden 	话题按钮是否隐藏,如果不隐藏则显示再分享视图的工具栏左侧，默认显示
 *	@param 	qqButtonHidden 	QQ分享按钮是否隐藏,如果不隐藏则显示在分享视图的工具栏右侧，默认显示
 *	@param 	wxSessionButtonHidden 	微信好友分享按钮是否隐藏，如果不隐藏则显示在分享视图的工具栏右侧，默认显示
 *	@param 	wxTimelineButtonHidden 	微信朋友圈分享按钮是否隐藏，如果不隐藏则显示在分享视图的工具栏右侧，默认显示
 *	@param 	showKeyboardOnAppear 	分享视图显示时是否同时显示键盘，如果不显示键盘则显示一键分享列表，默认不显示
 *	@param 	shareViewDelegate 	分享视图委托，如果不需要控制视图则传入nil
 *	@param 	friendsViewDelegate 	好友视图委托，如果不需要控制视图则传入nil
 *	@param 	picViewerViewDelegate 	图片查看器视图委托，如果不需要控制视图则传入nil
 *
 *	@return	分享选项
 */
///#end
///#begin en
/**
 *	@brief	Create a share opitons for default share view.
 *
 *  @since  ver2.2.0
 *
 *	@param 	title 	Title string.
 *	@param 	oneKeyShareList 	One key share list，Incoming [NSArray defaultOneKeyShareList] indicates the default sharing list. Is nil, said is not required to one key share
 *	@param 	cameraButtonHidden 	Camera button hidden flag. If you do not hide, Then display on the share view toolbar by the left side, the default display.
 *	@param 	mentionButtonHidden 	Mention button hidden flag. If you do not hide, Then display on the share view toolbar by the left side, the default display.
 *	@param 	topicButtonHidden 	Topic button hidden flag. If you do not hide, Then display on the share view toolbar by the left side, the default display.
 *	@param 	qqButtonHidden 	QQ share button hidden flag. If you do not hide, Then display on the share view toolbar by the right side, the default display.
 *	@param 	wxSessionButtonHidden 	WeChat Session button hidden flag，If you do not hide, Then display on the share view toolbar by the right side, the default display.
 *	@param 	wxTimelineButtonHidden 	WeChat Timeline button hidden flag，If you do not hide, Then display on the share view toolbar by the right side, the default display.
 *	@param 	showKeyboardOnAppear 	Whether in view of the display when the keyboard is displayed, the default NO. When on key share list is nil, this value is invalid.
 *	@param 	shareViewDelegate 	Share view delegate，If you do not control the view of the incoming nil
 *	@param 	friendsViewDelegate 	Friends view delegate，If you do not control the view of the incoming nil
 *	@param 	picViewerViewDelegate 	Picture viewer delegate，If you do not control the view of the incoming nil
 *
 *	@return	分享选项
 */
///#end
+ (id<ISSShareOptions>)defaultShareOptionsWithTitle:(NSString *)title
                                    oneKeyShareList:(NSArray *)oneKeyShareList
                                 cameraButtonHidden:(BOOL)cameraButtonHidden
                                mentionButtonHidden:(BOOL)mentionButtonHidden
                                  topicButtonHidden:(BOOL)topicButtonHidden
                                     qqButtonHidden:(BOOL)qqButtonHidden
                              wxSessionButtonHidden:(BOOL)wxSessionButtonHidden
                             wxTimelineButtonHidden:(BOOL)wxTimelineButtonHidden
                               showKeyboardOnAppear:(BOOL)showKeyboardOnAppear
                                  shareViewDelegate:(id<ISSShareViewDelegate>)shareViewDelegate
                                friendsViewDelegate:(id<ISSViewDelegate>)friendsViewDelegate
                              picViewerViewDelegate:(id<ISSViewDelegate>)picViewerViewDelegate;


///#begin zh-cn
/**
 *	@brief	创建简单分享选项
 *
 *	@param 	title 	分享视图标题
 *	@param 	shareViewDelegate 	分享视图委托，如果不需要控制视图则传入nil
 *
 *	@return	分享选项
 */
///#end
///#begin en
/**
 *	@brief	Create a share options for simple share view.
 *
 *	@param 	title 	Title string.
 *	@param 	shareViewDelegate 	Share view delegate，If you do not control the view of the incoming nil
 *
 *	@return	Share options object.
 */
///#end
+ (id<ISSShareOptions>)simpleShareOptionsWithTitle:(NSString *)title
                                 shareViewDelegate:(id<ISSShareViewDelegate>)shareViewDelegate;

///#begin zh-cn
/**
 *	@brief	创建应用推荐分享选项
 *
 *	@param 	title 	分享视图标题
 *	@param 	shareViewDelegate 	分享视图委托，如果不需要控制视图则传入nil
 *
 *	@return	分享选项
 */
///#end
///#begin en
/**
 *	@brief	Create a share options for app recommend.
 *
 *	@param 	title 	Title string.
 *	@param 	shareViewDelegate 	Share view delegate，If you do not control the view of the incoming nil
 *
 *	@return	Share options object.
 */
///#end
+ (id<ISSShareOptions>)appRecommendShareOptionsWithTile:(NSString *)title
                                      shareViewDelegate:(id<ISSShareViewDelegate>)shareViewDelegate;

///#begin zh-cn
/**
 *	@brief	分享内容,此接口不需要弹出分享界面直接进行分享（除微信、QQ、Pinterest平台外，这些平台会调用客户端进行分享）。
 *
 *	@param 	content 	内容对象
 *	@param 	type 	平台类型
 *	@param 	authOptions 	授权选项，用于指定接口在需要授权时的一些属性（如：是否自动授权，授权视图样式等）,设置未nil则表示采用默认选项
 *  @param  statusBarTips   状态栏提示
 *	@param 	result 	返回事件
 */
///#end
///#begin en
/**
 *	@brief	hare content to platform, This method does not pop up share view. (except WeChat, QQ, Pinterest platforms that will call the client to share).
 *
 *	@param 	content 	Share content object.
 *	@param 	type 	Platform type.
 *	@param 	authOptions 	Authorized options，Used to authorization for custom configuration（Such as: whether the automatic authorization, authorization view style, etc.）Default nil.
 *  @param  statusBarTips   The status bar Tip flag. YES indicates display. NO indicates hidden.
 *	@param 	result 	Result handler.
 */
///#end
+ (void)shareContent:(id<ISSContent>)content
                type:(ShareType)type
         authOptions:(id<ISSAuthOptions>)authOptions
       statusBarTips:(BOOL)statusBarTips
              result:(SSPublishContentEventHandler)result;

///#begin zh-cn
/**
 *	@brief	分享内容,此接口不需要弹出分享界面直接进行分享（除微信、QQ、Pinterest平台外，这些平台会调用客户端进行分享）。
 *
 *  @since  ver2.2.5
 *
 *	@param 	content 	内容对象
 *	@param 	type 	平台类型
 *	@param 	authOptions 	授权选项，用于指定接口在需要授权时的一些属性（如：是否自动授权，授权视图样式等）,设置未nil则表示采用默认选项
 *  @param  shareOptions    分享选项，用于定义分享视图部分属性（如：标题、一键分享列表、功能按钮等）,默认可传入nil
 *  @param  statusBarTips   状态栏提示
 *	@param 	result 	返回事件
 */
///#end
///#begin en
/**
 *	@brief	Share content to platform, This method does not pop up share view. (except WeChat, QQ, Pinterest platforms that will call the client to share).
 *
 *  @since  ver2.2.5
 *
 *	@param 	content 	Share content object.
 *	@param 	type 	Platform type.
 *	@param 	authOptions 	Authorized options，Used to authorization for custom configuration（Such as: whether the automatic authorization, authorization view style, etc.）Default nil.
 *  @param  shareOptions    Share options，Used to share for custom configuration（Such as: title, one key sharing, function buttons, etc.）Default nil.
 *  @param  statusBarTips   The status bar Tip flag. YES indicates display. NO indicates hidden.
 *	@param 	result 	Result handler.
 */
///#end
+ (void)shareContent:(id<ISSContent>)content
                type:(ShareType)type
         authOptions:(id<ISSAuthOptions>)authOptions
        shareOptions:(id<ISSShareOptions>)shareOptions
       statusBarTips:(BOOL)statusBarTips
              result:(SSPublishContentEventHandler)result;

///#begin zh-cn
/**
 *	@brief	分享内容,此接口不需要弹出分享界面直接进行分享（除微信、QQ、Pinterest平台外，这些平台会调用客户端进行分享）。
 *
 *  @since  ver2.9.1
 *
 *	@param 	content 	内容对象
 *	@param 	type 	平台类型
 *	@param 	authOptions 	授权选项，用于指定接口在需要授权时的一些属性（如：是否自动授权，授权视图样式等）,设置未nil则表示采用默认选项
 *  @param  shareOptions    分享选项，用于定义分享视图部分属性（如：标题、一键分享列表、功能按钮等）,默认可传入nil
 *  @param  statusBarTips   状态栏提示
 *  @param  targets         自定义标识集合，设置自定义标识可以在管理后台查看相关标识的分享统计数据
 *	@param 	result 	返回事件
 */
///#end
///#begin en
/**
 *	@brief	Share content to platform, This method does not pop up share view. (except WeChat, QQ, Pinterest platforms that will call the client to share).
 *
 *  @since  ver2.9.1
 *
 *	@param 	content 	Share content object.
 *	@param 	type 	Platform type.
 *	@param 	authOptions 	Authorized options，Used to authorization for custom configuration（Such as: whether the automatic authorization, authorization view style, etc.）Default nil.
 *  @param  shareOptions    Share options，Used to share for custom configuration（Such as: title, one key sharing, function buttons, etc.）Default nil.
 *  @param  statusBarTips   The status bar Tip flag. YES indicates display. NO indicates hidden.
 *  @param  targets         Custom target collection, set custom target can view statistics related to sharing in the management background.
 *	@param 	result 	Result handler.
 */
///#end
+ (void)shareContent:(id<ISSContent>)content
                type:(ShareType)type
         authOptions:(id<ISSAuthOptions>)authOptions
        shareOptions:(id<ISSShareOptions>)shareOptions
       statusBarTips:(BOOL)statusBarTips
             targets:(NSArray *)targets
              result:(SSPublishContentEventHandler)result;

///#begin zh-cn
/**
 *	@brief	一键分享内容
 *
 *	@param 	content 	内容对象
 *	@param 	shareList 	平台类型列表（邮件、短信、微信、QQ、打印、拷贝除外）
 *	@param 	authOptions 	授权选项，用于指定接口在需要授权时的一些属性（如：是否自动授权，授权视图样式等）,设置未nil则表示采用默认选项
 *  @param  statusBarTips   状态栏提示
 *	@param 	result 	返回事件
 */
///#end
///#begin en
/**
 *	@brief	Share content to multiple platforms
 *
 *	@param 	content 	Share content object.
 *	@param 	shareList 	Platform type list（exclude E-mail, SMS, WeChat, QQ, print, copy）
 *	@param 	authOptions 	Authorized options，Used to authorization for custom configuration（Such as: whether the automatic authorization, authorization view style, etc.）Default nil.
 *  @param  statusBarTips   The status bar Tip flag. YES indicates display. NO indicates hidden.
 *	@param 	result 	Result handler.
 */
///#end
+ (void)oneKeyShareContent:(id<ISSContent>)content
                 shareList:(NSArray *)shareList
               authOptions:(id<ISSAuthOptions>)authOptions
             statusBarTips:(BOOL)statusBarTips
                    result:(SSPublishContentEventHandler)result;

///#begin zh-cn
/**
 *	@brief	一键分享内容
 *
 *  @since  ver2.2.5
 *
 *	@param 	content 	内容对象
 *	@param 	shareList 	平台类型列表（邮件、短信、微信、QQ、打印、拷贝除外）
 *	@param 	authOptions 	授权选项，用于指定接口在需要授权时的一些属性（如：是否自动授权，授权视图样式等）,设置未nil则表示采用默认选项
 *  @param  statusBarTips   状态栏提示
 *	@param 	result 	返回事件
 */
///#end
///#begin en
/**
 *	@brief	Share content to multiple platforms.
 *
 *  @since  ver2.2.5
 *
 *	@param 	content 	Share content object.
 *	@param 	shareList 	Platform type list（exclude E-mail, SMS, WeChat, QQ, print, copy）
 *	@param 	authOptions 	Authorized options，Used to authorization for custom configuration（Such as: whether the automatic authorization, authorization view style, etc.）Default nil.
 *  @param  statusBarTips   The status bar Tip flag. YES indicates display. NO indicates hidden.
 *	@param 	result 	Result handler.
 */
///#end
+ (void)oneKeyShareContent:(id<ISSContent>)content
                 shareList:(NSArray *)shareList
               authOptions:(id<ISSAuthOptions>)authOptions
              shareOptions:(id<ISSShareOptions>)shareOptions
             statusBarTips:(BOOL)statusBarTips
                    result:(SSPublishContentEventHandler)result;

///#begin zh-cn
/**
 *	@brief	一键分享内容
 *
 *  @since  ver2.9.1
 *
 *	@param 	content 	内容对象
 *	@param 	shareList 	平台类型列表（邮件、短信、微信、QQ、打印、拷贝除外）
 *	@param 	authOptions 	授权选项，用于指定接口在需要授权时的一些属性（如：是否自动授权，授权视图样式等）,设置未nil则表示采用默认选项
 *  @param  statusBarTips   状态栏提示
 *  @param  targets         自定义标识集合，设置自定义标识可以在管理后台查看相关标识的分享统计数据
 *	@param 	result 	返回事件
 */
///#end
///#begin en
/**
 *	@brief	Share content to multiple platforms.
 *
 *  @since  ver2.9.1
 *
 *	@param 	content 	Share content object.
 *	@param 	shareList 	Platform type list（exclude E-mail, SMS, WeChat, QQ, print, copy）
 *	@param 	authOptions 	Authorized options，Used to authorization for custom configuration（Such as: whether the automatic authorization, authorization view style, etc.）Default nil.
 *  @param  statusBarTips   The status bar Tip flag. YES indicates display. NO indicates hidden.
 *  @param  targets         Custom target collection, set custom target can view statistics related to sharing in the management background.
 *	@param 	result 	Result handler.
 */
///#end
+ (void)oneKeyShareContent:(id<ISSContent>)content
                 shareList:(NSArray *)shareList
               authOptions:(id<ISSAuthOptions>)authOptions
              shareOptions:(id<ISSShareOptions>)shareOptions
             statusBarTips:(BOOL)statusBarTips
                   targets:(NSArray *)targets
                    result:(SSPublishContentEventHandler)result;

///#begin zh-cn
/**
 *	@brief	显示分享视图
 *
 *	@param 	type 	平台类型
 *  @param  container   用于显示分享界面的容器，如果只显示在iPhone客户端可以传入nil。如果需要在iPad上显示需要指定容器。
 *	@param 	content 	分享内容
 *	@param 	statusBarTips 	状态栏提示标识：YES：显示； NO：隐藏
 *	@param 	authOptions 	授权选项，用于指定接口在需要授权时的一些属性（如：是否自动授权，授权视图样式等），默认可传入nil
 *	@param 	shareOptions 	分享选项，用于定义分享视图部分属性（如：标题、一键分享列表、功能按钮等）,默认可传入nil
 *	@param 	result 	分享返回事件处理
 */
///#end
///#begin en
/**
 *	@brief	Show share view.
 *
 *	@param 	type 	Platform type.
 *  @param  container   A container for the share view, if only displayed in the iPhone can pass nil. If you want to display on the iPad needs to be specified container.
 *	@param 	content 	Share content object.
 *	@param 	statusBarTips 	The status bar Tip flag. YES indicates display. NO indicates hidden.
 *	@param 	authOptions 	Authorized options，Used to authorization for custom configuration（Such as: whether the automatic authorization, authorization view style, etc.）Default nil.
 *	@param 	shareOptions 	Share options，Used to share for custom configuration（Such as: title, one key sharing, function buttons, etc.）Default nil.
 *	@param 	result 	Result handler.
 */
///#end
+ (void)showShareViewWithType:(ShareType)type
                    container:(id<ISSContainer>)container
                      content:(id<ISSContent>)content
                statusBarTips:(BOOL)statusBarTips
                  authOptions:(id<ISSAuthOptions>)authOptions
                 shareOptions:(id<ISSShareOptions>)shareOptions
                       result:(SSPublishContentEventHandler)result;

///#begin zh-cn
/**
 *	@brief	显示分享视图
 *
 *  @since  ver2.9.1
 *
 *	@param 	type 	平台类型
 *  @param  container   用于显示分享界面的容器，如果只显示在iPhone客户端可以传入nil。如果需要在iPad上显示需要指定容器。
 *	@param 	content 	分享内容
 *	@param 	statusBarTips 	状态栏提示标识：YES：显示； NO：隐藏
 *	@param 	authOptions 	授权选项，用于指定接口在需要授权时的一些属性（如：是否自动授权，授权视图样式等），默认可传入nil
 *	@param 	shareOptions 	分享选项，用于定义分享视图部分属性（如：标题、一键分享列表、功能按钮等）,默认可传入nil
 *  @param  targets         自定义标识集合，设置自定义标识可以在管理后台查看相关标识的分享统计数据
 *	@param 	result 	分享返回事件处理
 */
///#end
///#begin en
/**
 *	@brief	Show share view.
 *
 *  @since  ver2.9.1
 *
 *	@param 	type 	Platform type.
 *  @param  container   A container for the share view, if only displayed in the iPhone can pass nil. If you want to display on the iPad needs to be specified container.
 *	@param 	content 	Share content object.
 *	@param 	statusBarTips 	The status bar Tip flag. YES indicates display. NO indicates hidden.
 *	@param 	authOptions 	Authorized options，Used to authorization for custom configuration（Such as: whether the automatic authorization, authorization view style, etc.）Default nil.
 *	@param 	shareOptions 	Share options，Used to share for custom configuration（Such as: title, one key sharing, function buttons, etc.）Default nil.
 *  @param  targets         Custom target collection, set custom target can view statistics related to sharing in the management background.
 *	@param 	result 	Result handler.
 */
///#end
+ (void)showShareViewWithType:(ShareType)type
                    container:(id<ISSContainer>)container
                      content:(id<ISSContent>)content
                statusBarTips:(BOOL)statusBarTips
                  authOptions:(id<ISSAuthOptions>)authOptions
                 shareOptions:(id<ISSShareOptions>)shareOptions
                      targets:(NSArray *)targets
                       result:(SSPublishContentEventHandler)result;

///#begin zh-cn
/**
 *	@brief	显示分享菜单
 *
 *	@param 	container 	用于显示分享界面的容器，如果只显示在iPhone客户端可以传入nil。如果需要在iPad上显示需要指定容器。
 *	@param 	shareList 	平台类型列表
 *	@param 	content 	分享内容
 *  @param  statusBarTips   状态栏提示标识：YES：显示； NO：隐藏
 *  @param  authOptions 授权选项，用于指定接口在需要授权时的一些属性（如：是否自动授权，授权视图样式等），默认可传入nil
 *  @param  shareOptions    分享选项，用于定义分享视图部分属性（如：标题、一键分享列表、功能按钮等）,默认可传入nil
 *  @param  result  分享返回事件处理
 */
///#end
///#begin en
/**
 *	@brief	Show share menu.
 *
 *	@param 	container 	A container for the share view, if only displayed in the iPhone can pass nil. If you want to display on the iPad needs to be specified container.
 *	@param 	shareList 	Platform type list.
 *	@param 	content 	Share content object.
 *  @param  statusBarTips   The status bar Tip flag. YES indicates display. NO indicates hidden.
 *  @param  authOptions Authorized options，Used to authorization for custom configuration（Such as: whether the automatic authorization, authorization view style, etc.）Default nil.
 *  @param  shareOptions    Share options，Used to share for custom configuration（Such as: title, one key sharing, function buttons, etc.）Default nil.
 *  @param  result  Result handler.
 */
///#end
+ (id<ISSShareActionSheet>)showShareActionSheet:(id<ISSContainer>)container
                                      shareList:(NSArray *)shareList
                                        content:(id<ISSContent>)content
                                  statusBarTips:(BOOL)statusBarTips
                                    authOptions:(id<ISSAuthOptions>)authOptions
                                   shareOptions:(id<ISSShareOptions>)shareOptions
                                         result:(SSPublishContentEventHandler)result;

///#begin zh-cn
/**
 *	@brief	显示分享菜单
 *
 *  @since  ver2.9.1
 *
 *	@param 	container 	用于显示分享界面的容器，如果只显示在iPhone客户端可以传入nil。如果需要在iPad上显示需要指定容器。
 *	@param 	shareList 	平台类型列表
 *	@param 	content 	分享内容
 *  @param  statusBarTips   状态栏提示标识：YES：显示； NO：隐藏
 *  @param  authOptions 授权选项，用于指定接口在需要授权时的一些属性（如：是否自动授权，授权视图样式等），默认可传入nil
 *  @param  shareOptions    分享选项，用于定义分享视图部分属性（如：标题、一键分享列表、功能按钮等）,默认可传入nil
 *  @param  targets         自定义标识集合，设置自定义标识可以在管理后台查看相关标识的分享统计数据
 *  @param  result  分享返回事件处理
 */
///#end
///#begin en
/**
 *	@brief	Show share menu.
 *
 *  @since  ver2.9.1
 *
 *	@param 	container 	A container for the share view, if only displayed in the iPhone can pass nil. If you want to display on the iPad needs to be specified container.
 *	@param 	shareList 	Platform type list.
 *	@param 	content 	Share content object.
 *  @param  statusBarTips   The status bar Tip flag. YES indicates display. NO indicates hidden.
 *  @param  authOptions Authorized options，Used to authorization for custom configuration（Such as: whether the automatic authorization, authorization view style, etc.）Default nil.
 *  @param  shareOptions    Share options，Used to share for custom configuration（Such as: title, one key sharing, function buttons, etc.）Default nil.
 *  @param  targets         Custom target collection, set custom target can view statistics related to sharing in the management background.
 *  @param  result  Result handler.
 */
///#end
+ (id<ISSShareActionSheet>)showShareActionSheet:(id<ISSContainer>)container
                                      shareList:(NSArray *)shareList
                                        content:(id<ISSContent>)content
                                  statusBarTips:(BOOL)statusBarTips
                                    authOptions:(id<ISSAuthOptions>)authOptions
                                   shareOptions:(id<ISSShareOptions>)shareOptions
                                        targets:(NSArray *)targets
                                         result:(SSPublishContentEventHandler)result;

///#begin zh-cn
/**
 *	@brief	使用客户端进行内容分享（仅支持新浪微博、微信、QQ、Pinterest、Google+）
 *
 *  @since  ver2.4.1
 *
 *	@param 	content 	内容对象
 *	@param 	type 	平台类型
 *  @param  statusBarTips   状态栏提示
 *	@param 	result 	返回事件
 */
///#end
///#begin en
/**
 *	@brief	Content sharing using a client (only for Sina Weibo, WeChat, QQ, Pinterest, Google+)
 *
 *  @since  ver2.4.1
 *
 *	@param 	content 	Content string.
 *	@param 	type 	Platform type
 *  @param  statusBarTips   The status bar Tip flag
 *	@param 	result 	Result handler.
 */
///#end
+ (void)clientShareContent:(id<ISSContent>)content
                      type:(ShareType)type
             statusBarTips:(BOOL)statusBarTips
                    result:(SSPublishContentEventHandler)result;

///#begin zh-cn
/**
 *	@brief	使用客户端进行内容分享（仅支持新浪微博、微信、QQ、Pinterest、Google+）
 *
 *  @since  ver2.9.0
 *
 *	@param 	content 	内容对象
 *	@param 	type 	平台类型
 *	@param 	authOptions 	授权选项，用于指定接口在需要授权时的一些属性（如：是否自动授权，授权视图样式等）,设置未nil则表示采用默认选项
 *  @param  shareOptions    分享选项，用于定义分享视图部分属性（如：标题、一键分享列表、功能按钮等）,默认可传入nil
 *  @param  statusBarTips   状态栏提示
 *	@param 	result 	返回事件
 */
///#end
///#begin en
/**
 *	@brief	Content sharing using a client (only for Sina Weibo, WeChat, QQ, Pinterest, Google+)
 *
 *  @since  ver2.9.0
 *
 *	@param 	content 	Content string.
 *	@param 	type 	Platform type
 *	@param 	authOptions 	Authorized options，Used to authorization for custom configuration（Such as: whether the automatic authorization, authorization view style, etc.）Default nil.
 *  @param  shareOptions    Share options，Used to share for custom configuration（Such as: title, one key sharing, function buttons, etc.）Default nil.
 *  @param  statusBarTips   The status bar Tip flag
 *	@param 	result 	Result handler.
 */
///#end
+ (void)clientShareContent:(id<ISSContent>)content
                      type:(ShareType)type
               authOptions:(id<ISSAuthOptions>)authOptions
              shareOptions:(id<ISSShareOptions>)shareOptions
             statusBarTips:(BOOL)statusBarTips
                    result:(SSPublishContentEventHandler)result;

///#begin zh-cn
/**
 *	@brief	使用客户端进行内容分享（仅支持新浪微博、微信、QQ、Pinterest、Google+）
 *
 *  @since  ver2.9.1
 *
 *	@param 	content 	内容对象
 *	@param 	type 	平台类型
 *	@param 	authOptions 	授权选项，用于指定接口在需要授权时的一些属性（如：是否自动授权，授权视图样式等）,设置未nil则表示采用默认选项
 *  @param  shareOptions    分享选项，用于定义分享视图部分属性（如：标题、一键分享列表、功能按钮等）,默认可传入nil
 *  @param  statusBarTips   状态栏提示
 *  @param  targets         自定义标识集合，设置自定义标识可以在管理后台查看相关标识的分享统计数据
 *	@param 	result 	返回事件
 */
///#end
///#begin en
/**
 *	@brief	Content sharing using a client (only for Sina Weibo, WeChat, QQ, Pinterest, Google+)
 *
 *  @since  ver2.9.1
 *
 *	@param 	content 	Content string.
 *	@param 	type 	Platform type
 *	@param 	authOptions 	Authorized options，Used to authorization for custom configuration（Such as: whether the automatic authorization, authorization view style, etc.）Default nil.
 *  @param  shareOptions    Share options，Used to share for custom configuration（Such as: title, one key sharing, function buttons, etc.）Default nil.
 *  @param  statusBarTips   The status bar Tip flag
 *  @param  targets         Custom target collection, set custom target can view statistics related to sharing in the management background.
 *	@param 	result 	Result handler.
 */
///#end
+ (void)clientShareContent:(id<ISSContent>)content
                      type:(ShareType)type
               authOptions:(id<ISSAuthOptions>)authOptions
              shareOptions:(id<ISSShareOptions>)shareOptions
             statusBarTips:(BOOL)statusBarTips
                   targets:(NSArray *)targets
                    result:(SSPublishContentEventHandler)result;

#pragma mark - 分享推荐页面

/**
 *  显示自定义cell模块，用法类似如下
 *  
    [ShareSDK onShowWidgets:^NSArray *{
        UIView *view1 = [[UIView alloc] initWithFrame:CGRectZero];
        UIView *view2 = [[UIView alloc] initWithFrame:CGRectZero];
        return @[view1, view2];
    }];
 */
+ (void)onShowWidgets:(NSArray *(^)())block;


@end
