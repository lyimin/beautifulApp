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
#import "SSCTypeDef.h"

///#begin zh-cn
/**
 *	@brief	开放应用用户信息
 */
///#end
///#begin en
/**
 *	@brief	User descriptor.
 */
///#end
@protocol ISSCUserDescriptor <NSObject>

///#begin zh-cn
/**
 *	@brief	获取用户的原始数据信息，与各个平台定义的用户信息结构相同
 *
 *	@return	原始数据信息
 */
///#end
///#begin en
/**
 *	@brief	Get user's raw data, define the structure consistent with the platform
 *
 *	@return	Raw data dicationary.
 */
///#end
- (NSDictionary *)sourceData;

///#begin zh-cn
/**
 *	@brief	获取用户所属平台类型
 *
 *	@return	平台类型
 */
///#end
///#begin en
/**
 *	@brief	Get platform type.
 *
 *	@return	Platform type. please see ShareType.
 */
///#end
- (SSCShareType)type;

///#begin zh-cn
/**
 *	@brief	获取用户ID
 *
 *	@return	用户ID
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
 *	@brief	获取用户昵称
 *
 *	@return	用户昵称
 */
///#end
///#begin en
/**
 *	@brief	Get user nickname.
 *
 *	@return	User nickname
 */
///#end
- (NSString *)nickname;

///#begin zh-cn
/**
 *	@brief	获取用户个人头像
 *
 *	@return	个人头像路径
 */
///#end
///#begin en
/**
 *	@brief	Get User profile image.
 *
 *	@return	User profile image url.
 */
///#end
- (NSString *)profileImage;

///#begin zh-cn
/**
 *	@brief	获取用户性别
 *
 *	@return	性别：0 男； 1 女； 2 未知
 */
///#end
///#begin en
/**
 *	@brief	Get gender
 *
 *	@return	Gender：0 Male； 1 Female； 2 Unknown
 */
///#end
- (NSInteger)gender;

///#begin zh-cn
/**
 *	@brief	获取用户个人主页
 *
 *	@return	个人主页地址
 */
///#end
///#begin en
/**
 *	@brief	Get user's personal homepage
 *
 *	@return	Personal homepage
 */
///#end
- (NSString *)url;

///#begin zh-cn
/**
 *	@brief	获取用户个人简介
 *
 *	@return	个人简介
 */
///#end
///#begin en
/**
 *	@brief	Get User Profile
 *
 *	@return	User Profile
 */
///#end
- (NSString *)aboutMe;

///#begin zh-cn
/**
 *	@brief	获取用户认证类型
 *
 *	@return	认证类型：－1 未知； 0 未认证； 1 认证。
 */
///#end
///#begin en
/**
 *	@brief	Get user verify type.
 *
 *	@return	Verfify type：－1 Unknown； 0 Not Authenticate； 1 Authenticate。
 */
///#end
- (NSInteger)verifyType;

///#begin zh-cn
/**
 *	@brief	获取用户认证信息
 *
 *	@return	认证信息
 */
///#end
///#begin en
/**
 *	@brief	Get user verify reason.
 *
 *	@return	Verify reason.
 */
///#end
- (NSString *)verifyReason;

///#begin zh-cn
/**
 *	@brief	获取用户生日（单位：秒）
 *
 *	@return	生日
 */
///#end
///#begin en
/**
 *	@brief	Get users birthday (unit: seconds)
 *
 *	@return	Birthday.
 */
///#end
- (NSString *)birthday;

///#begin zh-cn
/**
 *	@brief	获取用户粉丝数
 *
 *	@return	粉丝数量
 */
///#end
///#begin en
/**
 *	@brief	Get fans count.
 *
 *	@return	Fans count.
 */
///#end
- (NSInteger)followerCount;

///#begin zh-cn
/**
 *	@brief	获取用户关注数
 *
 *	@return	关注数量
 */
///#end
///#begin en
/**
 *	@brief	Get friends count.
 *
 *	@return	Friends count.
 */
///#end
- (NSInteger)friendCount;

///#begin zh-cn
/**
 *	@brief	获取用户分享数
 *
 *	@return	分享数量
 */
///#end
///#begin en
/**
 *	@brief	Get share count.
 *
 *	@return	Share count.
 */
///#end
- (NSInteger)shareCount;

///#begin zh-cn
/**
 *	@brief	获取用户的注册时间（单位：秒）
 *
 *	@return	注册时间
 */
///#end
///#begin en
/**
 *	@brief	Get the user's registration time (unit: seconds)
 *
 *	@return	Registration time
 */
///#end
- (NSTimeInterval)regAt;

///#begin zh-cn
/**
 *	@brief	获取用户等级
 *
 *	@return	等级
 */
///#end
///#begin en
/**
 *	@brief	Get user level
 *
 *	@return	Level
 */
///#end
- (NSInteger)level;

///#begin zh-cn
/**
 *	@brief	获取用户的教育信息列表
 *
 *	@return	教育信息列表
 */
///#end
///#begin en
/**
 *	@brief	Get a list of user education information
 *
 *	@return	Education List
 */
///#end
- (NSArray *)educations;

///#begin zh-cn
/**
 *	@brief	获取用户的职业信息列表
 *
 *	@return	职业信息列表
 */
///#end
///#begin en
/**
 *	@brief	Get a list of the user's occupation information
 *
 *	@return	Occupation List
 */
///#end
- (NSArray *)works;

@end
