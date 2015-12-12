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
#import <ShareSDKCoreService/ShareSDKCoreService.h>
#import <ShareSDK/ShareSDKPlugin.h>

///#begin zh-cn
/**
 *	@brief	QQ空间授权凭证
 */
///#end
///#begin en
/**
 *	@brief	QZone Credential.
 */
///#end
@interface SSQZoneCredential : NSObject <ISSPlatformCredential,
                                         NSCoding>
{
@private
    NSString *_uid;
    NSString *_token;
    NSDate *_expired;
    NSDictionary *_extInfo;
}

///#begin zh-cn
/**
 *	@brief	扩展数据
 */
///#end
///#begin en
/**
 *	@brief	Extended data.
 */
///#end
@property (nonatomic,retain) NSDictionary *extInfo;

///#begin zh-cn
/**
 *	@brief	用户ID
 */
///#end
///#begin en
/**
 *	@brief	User id.
 */
///#end
@property (nonatomic,copy) NSString *uid;

///#begin zh-cn
/**
 *	@brief	Access Token
 */
///#end
///#begin en
/**
 *	@brief	Access Token
 */
///#end
@property (nonatomic,copy) NSString *token;

///#begin zh-cn
/**
 *	@brief	过期时间
 */
///#end
///#begin en
/**
 *	@brief	Expires.
 */
///#end
@property (nonatomic,retain) NSDate *expired;

///#begin zh-cn
/**
 *	@brief	判断授权数据是否有效
 */
///#end
///#begin en
/**
 *	@brief	Determine the validity of the authorization data
 */
///#end
@property (nonatomic,readonly) BOOL available;

///#begin zh-cn
/**
 *	@brief	使用原始数据创建授权凭证
 *
 *	@param 	sourceData 	原始数据
 *
 *	@return	授权凭证
 */
///#end
///#begin en
/**
 *	@brief	Create a credential.
 *
 *	@param 	sourceData 	Raw data.
 *
 *	@return	Credential object.
 */
///#end
+ (SSQZoneCredential *)credentialWithSourceData:(NSDictionary *)sourceData;

@end
