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

#import <UIKit/UIKit.h>
#import "ISSCAccount.h"
#import "ISSCRequest.h"
#import "ISSCToken.h"
#import "ISSCOpenApp.h"
#import "ISSCOAuthParameters.h"
#import "ISSCAuthSession.h"
#import "ISSCAttachment.h"
#import "SSCNotificationDef.h"
#import "SSCKeyDef.h"
#import "SSCTypeDef.h"
#import "ISSCDataObject.h"
#import "SSCLocationCoordinate2D.h"

///#begin zh-cn
/**
 *	@brief	ShareSDK核心服务层
 */
///#end
///#begin en
/**
 *	@brief	ShareSDK core service.
 */
///#end
@interface ShareSDKCoreService : NSObject

///#begin zh-cn
/**
 *	@brief	使用AppKey进行登录
 *
 *	@param 	appKey 	应用标志
 *
 *	@return	登录帐户对象
 */
///#end
///#begin en
/**
 *	@brief	Use app key login
 *
 *	@param 	appKey 	App key.
 *
 *	@return	Account information.
 */
///#end
+ (id<ISSCAccount>)loginWithAppKey:(NSString *)appKey;

///#begin zh-cn
/**
 *	@brief	是否和服务器通讯的开关请求
 *
 *	@param 	appKey 	应用标志
 *
 *	@return	void
 */
///#end
///#begin en
/**
 *	@brief  whether connect with Server data
 *
 *	@param 	appKey 	App key.
 *
 *	@return	void
 */
///#end
+ (void)requestWhetherConnectServerUrlWithAppKey:(NSString *)appKey result:(void (^)(id<ISSCAccount> sender))aResult;

///#begin zh-cn
/**
 *	@brief	检查帐号是否已经登录
 *
 *	@param 	account 	登录帐号
 *
 *	@return	YES表示登录，NO表示尚未登录
 */
///#end
///#begin en
/**
 *	@brief	Check whether the account has logged
 *
 *	@param 	account 	Account information.
 *
 *	@return	YES means the login, NO indicates not logged in
 */
///#end
+ (BOOL)hasLogined:(id<ISSCAccount>)account;

///#begin zh-cn
/**
 *	@brief	创建请求参数
 *
 *	@return	请求参数对象
 */
///#end
///#begin en
/**
 *	@brief	Create a parameters.
 *
 *	@return	Parameters object.
 */
///#end
+ (id<ISSCParameters>)parameters;

///#begin zh-cn
/**
 *	@brief	创建请求参数
 *
 *	@param 	query 	URL中的query字符串
 *
 *	@return	请求参数对象
 */
///#end
///#begin en
/**
 *	@brief	Create a parameters.
 *
 *	@param 	query 	The URL query string.
 *
 *	@return	Parameters
 */
///#end
+ (id<ISSCParameters>)parametersWithQuery:(NSString *)query;

///#begin zh-cn
/**
 *	@brief	创建OAuth请求参数
 *
 *	@param 	consumerKey 	消费者Key
 *	@param 	consumerSecret 	消费者密钥
 *  @param  oauthToken  OAuth令牌
 *  @param  oauthSecret OAuth密钥
 *
 *	@return	OAuth请求参数
 */
///#end
///#begin en
/**
 *	@brief	Create OAuth request parameters.
 *
 *	@param 	consumerKey 	Consumer key.
 *	@param 	consumerSecret 	Consumer secret.
 *  @param  oauthToken  OAuth token.
 *  @param  oauthSecret OAuth secret.
 *
 *	@return	OAuth parameters.
 */
///#end
+ (id<ISSCOAuthParameters>)oauthParameters:(NSString *)consumerKey
                            consumerSecret:(NSString *)consumerSecret
                                oauthToken:(NSString *)oauthToken
                               oauthSecret:(NSString *)oauthSecret;

///#begin zh-cn
/**
 *	@brief	创建OAuth请求参数
 *
 *	@param 	consumerKey 	消费者Key
 *	@param 	consumerSecret 	消费者密钥
 *  @param  oauthToken  OAuth令牌
 *  @param  oauthSecret OAuth密钥
 *  @param  query   URL中的query字符串
 *
 *	@return	OAuth请求参数
 */
///#end
///#begin en
/**
 *	@brief	Create OAuth request parameters.
 *
 *	@param 	consumerKey 	Consumer key.
 *	@param 	consumerSecret 	Consumer secret
 *  @param  oauthToken  OAuth token.
 *  @param  oauthSecret OAuth secret.
 *  @param  query   The URL query string
 *
 *	@return	OAuth parameters.
 */
///#end
+ (id<ISSCOAuthParameters>)oauthParameters:(NSString *)consumerKey
                            consumerSecret:(NSString *)consumerSecret
                                oauthToken:(NSString *)oauthToken
                               oauthSecret:(NSString *)oauthSecret
                                     query:(NSString *)query;

///#begin zh-cn
/**
 *	@brief	获取请求
 *
 *	@param 	account 	授权帐号
 *
 *	@return	请求对象,如果返回nil则表示帐户尚未通过授权
 */
///#end
///#begin en
/**
 *	@brief	Send request.
 *
 *	@param 	account 	Account information.
 *
 *	@return	Request object, return nil if it means that the account has not been authorized by
 */
///#end
+ (id<ISSCRequest>)requestWithAccount:(id<ISSCAccount>)account;

///#begin zh-cn
/**
 *	@brief	创建附件
 *
 *	@param 	path 	文件路径
 *
 *	@return	附件对象
 */
///#end
///#begin en
/**
 *	@brief	Create attachment object.
 *
 *	@param 	path 	File path.
 *
 *	@return	Attachment object.
 */
///#end
+ (id<ISSCAttachment>)attachmentWithPath:(NSString *)path;

///#begin zh-cn
/**
 *	@brief	创建附件
 *
 *	@param 	url 	文件网络地址
 *
 *	@return	附件对象
 */
///#end
///#begin en
/**
 *	@brief	Create attachment object.
 *
 *	@param 	url 	URL string.
 *
 *	@return	Attachment object.
 */
///#end
+ (id<ISSCAttachment>)attachmentWithUrl:(NSString *)url;

///#begin zh-cn
/**
 *	@brief	创建附件
 *
 *	@param 	data 	文件数据
 *	@param 	fileName 	文件名称
 *	@param 	mimeType 	MIME类型
 *
 *	@return	附件对象
 */
///#end
///#begin en
/**
 *	@brief	Create attachment data.
 *
 *	@param 	data 	File data.
 *	@param 	fileName 	File name.
 *	@param 	mimeType 	MIME type
 *
 *	@return	Attachment data.
 */
///#end
+ (id<ISSCAttachment>)attachmentWithData:(NSData *)data fileName:(NSString *)fileName mimeType:(NSString *)mimeType;

///#begin zh-cn
/**
 *	@brief	OAuth签名
 *
 *	@param 	url 	URL
 *	@param 	method 	请求方法GET或POST
 *	@param 	parameters 	参数
 *	@param 	consumerSecret 	消费者密钥
 *	@param 	oauthTokenSecret 	OAuth令牌密钥
 *  
 *	@return	签名值
 */
///#end
///#begin en
/**
 *	@brief	OAuth signatures
 *
 *	@param 	url 	URL string.
 *	@param 	method 	Request method.
 *	@param 	parameters 	Parameters.
 *	@param 	consumerSecret 	Consumer secret.
 *	@param 	oauthTokenSecret 	OAuth token secret.
 *
 *	@return	Sinature string
 */
///#end
+ (NSString *)oauthSignatureWithURL:(NSURL *)url
                             method:(NSString *)method
                         parameters:(id<ISSCParameters>)parameters
                     consumerSecret:(NSString *)consumerSecret
                   oauthTokenSecret:(NSString *)oauthTokenSecret;

///#begin zh-cn
/**
 *	@brief	获取SDK本地化字符串资源
 *
 *	@param 	name 	名称
 *	@param 	comment 	描述
 *
 *	@return	字符串资源
 */
///#end
///#begin en
/**
 *	@brief	Get localizable string
 *
 *	@param 	name 	Name
 *	@param 	comment 	Comment
 *
 *	@return	String object.
 */
///#end
+ (NSString *)localizableString:(NSString *)name comment:(NSString *)comment;

///#begin zh-cn
/**
 *	@brief	获取SDK的图片资源
 *
 *	@param 	name 	名称
 *
 *	@return	图片资源
 */
///#end
///#begin en
/**
 *	@brief	Get Image object
 *
 *	@param 	name 	Bundle name.
 *
 *	@return	Image object.
 */
///#end
+ (UIImage *)imageNamed:(NSString *)name;



@end
