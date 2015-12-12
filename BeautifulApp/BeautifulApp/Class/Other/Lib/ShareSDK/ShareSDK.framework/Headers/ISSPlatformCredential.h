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
 *	@brief	平台授权凭证协议
 */
///#end
///#begin en
/**
 *	@brief	Authorized credential protocol
 */
///#end
@protocol ISSPlatformCredential <NSObject>

@required

///#begin zh-cn
/**
 *	@brief	获取用户标识
 *
 *	@return	用户标识
 */
///#end
///#begin en
/**
 *	@brief	Get user id.
 *
 *	@return	User id.
 */
///#end
- (NSString *)uid;

///#begin zh-cn
/**
 *	@brief	获取令牌,在OAuth中为oauth_token，在OAuth2中为access_token
 *
 *	@return	令牌
 */
///#end
///#begin en
/**
 *	@brief	Get token, In OAuth is oauth_token property，In OAuth2 is access_token property
 *
 *	@return	Token string.
 */
///#end
- (NSString *)token;

///#begin zh-cn
/**
 *	@brief	获取令牌密钥，仅用于OAuth授权中，为oauth_token_secret。
 *
 *	@return 令牌密钥
 */
///#end
///#begin en
/**
 *	@brief	Get secret，Only for OAuth authorization，is oauth_token_secret property。
 *
 *	@return Secret string.
 */
///#end
- (NSString *)secret;

///#begin zh-cn
/**
 *	@brief	获取令牌过期时间，仅用于OAuth2授权中，需要将返回的秒数转换为时间。
 *
 *	@return	令牌过期时间
 */
///#end
///#begin en
/**
 *	@brief	Get a token expiration time. Only for OAuth2 authorization. Need to return to a time in seconds.
 *
 *	@return	expiration time.
 */
///#end
- (NSDate *)expired;

///#begin zh-cn
/**
 *	@brief	获取其他扩展信息
 *
 *	@return	扩展信息
 */
///#end
///#begin en
/**
 *	@brief	Get extension information
 *
 *	@return	Extension information dicationary.
 */
///#end
- (NSDictionary *)extInfo;

///#begin zh-cn
/**
 *	@brief	获取授权凭证的有效性
 *
 *	@return	授权凭证的有效性
 */
///#end
///#begin en
/**
 *	@brief	Get authorization credential validity
 *
 *	@return	YES is available. otherwise is not available.
 */
///#end
- (BOOL)available;


@end
