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
#import "ISSCParameters.h"

///#begin zh-cn
/**
 *	@brief	OAuth参数
 */
///#end
///#begin en
/**
 *	@brief	OAuth parameters.
 */
///#end
@protocol ISSCOAuthParameters <ISSCParameters>

///#begin zh-cn
/**
 *	@brief	获取消费者Key
 *
 *	@return	消费者Key
 */
///#end
///#begin en
/**
 *	@brief	Get consumer key.
 *
 *	@return	Consumer key.
 */
///#end
- (NSString *)consumerKey;

///#begin zh-cn
/**
 *	@brief	获取消费者密钥
 *
 *	@return	消费者密钥
 */
///#end
///#begin en
/**
 *	@brief	Get consumer secret.
 *
 *	@return	Consumer secret.
 */
///#end
- (NSString *)consumerSecret;

///#begin zh-cn
/**
 *	@brief	获取OAuthToken
 *
 *	@return	OAuthToken
 */
///#end
///#begin en
/**
 *	@brief	Get Oauth token.
 *
 *	@return	OAuth token.
 */
///#end
- (NSString *)oauthToken;

///#begin zh-cn
/**
 *	@brief	获取OAuth密钥
 *
 *	@return	OAuth密钥
 */
///#end
///#begin en
/**
 *	@brief	Get OAuth secret.
 *
 *	@return	OAuth secret.
 */
///#end
- (NSString *)oauthSecret;

///#begin zh-cn
/**
 *	@brief	添加OAuth参数,仅用于OAuth1.0版本
 *
 *	@param 	name 	参数名称
 *	@param 	value 	参数值
 */
///#end
///#begin en
/**
 *	@brief	Add OAuth parameters. Only for OAuth
 *
 *	@param 	name 	Parameter name.
 *	@param 	value 	Parameter value.
 */
///#end
- (void)addOAuthParameter:(NSString *)name value:(id)value;

///#begin zh-cn
/**
 *	@brief	添加多个参数
 *
 *	@param 	parameters 	参数对象
 */
///#end
///#begin en
/**
 *	@brief	Adding multiple parameters
 *
 *	@param 	parameters 	Parameters object.
 */
///#end
- (void)addOAuthParameters:(id<ISSCOAuthParameters>)parameters;

///#begin zh-cn
/**
 *	@brief	添加多个参数
 *
 *	@param 	dictionary 	参数字典
 */
///#end
///#begin en
/**
 *	@brief	Adding multiple parameters
 *
 *	@param 	dictionary 	Parameters dictionary.
 */
///#end
- (void)addOAuthParametersWithDictionary:(NSDictionary *)dictionary;

///#begin zh-cn
/**
 *	@brief	获取OAuth参数值,仅用于OAuth1.0版本
 *
 *	@param 	name 	参数名称
 *
 *	@return	参数值
 */
///#end
///#begin en
/**
 *	@brief	Get OAuth parameter value, Only for OAuth.
 *
 *	@param 	name 	Parameter name.
 *
 *	@return	Parameter value.
 */
///#end
- (id)oauthParameterWithName:(NSString *)name;

///#begin zh-cn
/**
 *	@brief	获取OAuth参数数量,仅用于OAuth1.0版本
 *
 *	@return	参数数量
 */
///#end
///#begin en
/**
 *	@brief	Get parameters count. only for OAuth.
 *
 *	@return	Parameters count.
 */
///#end
- (NSInteger)oauthParameterCount;

///#begin zh-cn
/**
 *	@brief	获取OAuth字典结构数据
 *
 *	@return	字典数据
 */
///#end
///#begin en
/**
 *	@brief	Get OAuth dictionary object.
 *
 *	@return	Dictionary object.
 */
///#end
- (NSDictionary *)oauthDictionaryValue;

@end
