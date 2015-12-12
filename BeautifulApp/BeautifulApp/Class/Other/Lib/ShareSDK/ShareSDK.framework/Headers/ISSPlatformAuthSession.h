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
#import "ISSPlatformCredential.h"

///#begin zh-cn
/**
 *	@brief	授权返回事件
 */
///#end
///#begin en
/**
 *	@brief	Authorized result event.
 */
///#end
typedef void(^SSAuthResultEvent) (SSResponseState state, id<ISSPlatformCredential> credential, CMErrorInfo *error);

///#begin zh-cn
/**
 *	@brief	平台授权会话协议
 */
///#end
///#begin en
/**
 *	@brief	Authorized session protocol.
 */
///#end
@protocol ISSPlatformAuthSession <NSObject>

@required

///#begin zh-cn
/**
 *	@brief	分享类型
 *
 *	@return	分享类型
 */
///#end
///#begin en
/**
 *	@brief	Get platform type.
 *
 *	@return	Platform type. please see ShareType.
 */
///#end
- (ShareType)type;

///#begin zh-cn
/**
 *	@brief	开始授权
 *
 *  @param  allowCallback   是否允许回调到服务器，默认为YES，对于无服务器端应用或者不需要回调授权数据到服务器的应用可以设置为NO。
 *  @param  ssoLogin    SSO授权登录表示，YES 表示优先使用SSO进行授权，否则直接使用Web授权
 *  @param  scopes  权限列表
 *	@param 	result 	返回事件
 */
///#end
///#begin en
/**
 *	@brief	Start Authorized
 *
 *  @param  allowCallback   Whether to allow callbacks to the server，Default YES, the server-side app for free or no callback authorization data to the server app can be set to NO.
 *  @param  ssoLogin    SSO authorized enabled，YES indicate priority SSO authorize. otherwise authorized to use the Web authorized
 *  @param  scopes  Scopes list array.
 *	@param 	result 	Result handler
 */
///#end
- (void)startWithAllowCallback:(BOOL)allowCallback
                      ssoLogin:(BOOL)ssoLogin
                        scopes:(NSArray *)scopes
                        result:(SSAuthResultEvent)result;
///#begin zh-cn
/**
 *	@brief	取消授权
 */
///#end
///#begin en
/**
 *	@brief	Cancel authorized.
 */
///#end
- (void)cancel;

///#begin zh-cn
/**
 *	@brief	获取授权视图,如果返回nil则表示使用SSO方式进行登录。(注：请调用start方法后使用此属性，否则将恒定返回nil。)
 *
 *	@return	授权视图
 */
///#end
///#begin en
/**
 *	@brief	Get authorized view. Returns nil if it means using the SSO login mode。(Note: Please call the start method after using this property, otherwise constant returns nil.)
 *
 *	@return	Authorized view.
 */
///#end
- (UIView *)view;

///#begin zh-cn
/**
 *	@brief	SSO登录标识,目前仅新浪微博、Facebook支持SSO.(注：请调用start方法后使用此属性，否则将恒定返回NO)
 *
 *	@return	YES 表示SSO登录， NO 表示Web登录
 */
///#end
///#begin en
/**
 *	@brief	SSO Login flag.(Note: Please call the start method after using this property, otherwise constant returns nil.)
 *
 *	@return	YES indicate is SSO login. otherwise is Web login.
 */
///#end
- (BOOL)isSSOLogin;


@end
