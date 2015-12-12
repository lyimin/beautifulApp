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
#import "SSSinaWeiboCredential.h"
#import <ShareSDKCoreService/ShareSDKCoreService.h>
#import <ShareSDKCoreService/ISSCUserDescriptor.h>
#import <ShareSDK/ShareSDKPlugin.h>

@class SSSinaWeiboStatus;

///#begin zh-cn
/**
 *	@brief	新浪微博用户信息
 */
///#end
///#begin en
/**
 *	@brief	User.
 */
///#end
@interface SSSinaWeiboUser : NSObject <ISSPlatformUser,
                                       NSCoding,
                                       ISSCDataObject>

///#begin zh-cn
/**
 *	@brief	所属平台
 */
///#end
///#begin en
/**
 *	@brief	The app.
 */
///#end
@property (nonatomic,assign) id<ISSPlatformApp> app;

///#begin zh-cn
/**
 *	@brief	授权信息，如果为nil则表示非当前应用授权用户
 */
///#end
///#begin en
/**
 *	@brief	Authorization information, if it is nil, said non-current authorized user
 */
///#end
@property (nonatomic,retain) id<ISSPlatformCredential> credential;

///#begin zh-cn
/**
 *	@brief	用户的原始数据信息，与各个平台定义的用户信息结构相同
 */
///#end
///#begin en
/**
 *	@brief	Raw data，Information structure with the same user-defined for each platform
 */
///#end
@property (nonatomic,retain) NSDictionary *sourceData;

///#begin zh-cn
/**
 *	@brief	平台类型
 */
///#end
///#begin en
/**
 *	@brief	Platform type.
 */
///#end
@property (nonatomic,readonly) ShareType type;

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
@property (nonatomic,readonly) NSString *uid;

///#begin zh-cn
/**
 *	@brief	用户昵称
 */
///#end
///#begin en
/**
 *	@brief	Nickname.
 */
///#end
@property (nonatomic,readonly) NSString *nickname;

///#begin zh-cn
/**
 *	@brief	个人头像路径
 */
///#end
///#begin en
/**
 *	@brief	Avatar path.
 */
///#end
@property (nonatomic,readonly) NSString *profileImage;

///#begin zh-cn
/**
 *	@brief	性别：0 男； 1 女； 2 未知
 */
///#end
///#begin en
/**
 *	@brief	Gender：0 Male； 1 Female； 2 Unknown.
 */
///#end
@property (nonatomic,readonly) NSInteger gender;

///#begin zh-cn
/**
 *	@brief	个人主页地址
 */
///#end
///#begin en
/**
 *	@brief	Personal homepage.
 */
///#end
@property (nonatomic,readonly) NSString *url;

///#begin zh-cn
/**
 *	@brief	个人简介
 */
///#end
///#begin en
/**
 *	@brief	Profile
 */
///#end
@property (nonatomic,readonly) NSString *aboutMe;

///#begin zh-cn
/**
 *	@brief	认证类型：－1 未知； 0 未认证； 1 认证
 */
///#end
///#begin en
/**
 *	@brief	Verify type：－1 Unknown； 0 Not certified； 1 Certified
 */
///#end
@property (nonatomic,readonly) NSInteger verifyType;

///#begin zh-cn
/**
 *	@brief	认证信息
 */
///#end
///#begin en
/**
 *	@brief	Verify reason.
 */
///#end
@property (nonatomic,readonly) NSString *verifyReason;

///#begin zh-cn
/**
 *	@brief	用户生日（单位：秒）
 */
///#end
///#begin en
/**
 *	@brief	Birthday (unit: seconds)
 */
///#end
@property (nonatomic,readonly) NSString *birthday;

///#begin zh-cn
/**
 *	@brief	用户粉丝数
 */
///#end
///#begin en
/**
 *	@brief	Fans count.
 */
///#end
@property (nonatomic,readonly) NSInteger followerCount;

///#begin zh-cn
/**
 *	@brief	用户关注数
 */
///#end
///#begin en
/**
 *	@brief	Friends count.
 */
///#end
@property (nonatomic,readonly) NSInteger friendCount;

///#begin zh-cn
/**
 *	@brief	用户分享数
 */
///#end
///#begin en
/**
 *	@brief	The number of user to share.
 */
///#end
@property (nonatomic,readonly) NSInteger shareCount;

///#begin zh-cn
/**
 *	@brief	用户的注册时间（单位：秒）
 */
///#end
///#begin en
/**
 *	@brief	User registration time (unit: seconds)
 */
///#end
@property (nonatomic,readonly) NSTimeInterval regAt;

///#begin zh-cn
/**
 *	@brief	用户等级
 */
///#end
///#begin en
/**
 *	@brief	User level.
 */
///#end
@property (nonatomic,readonly) NSInteger level;

///#begin zh-cn
/**
 *	@brief	用户的教育信息列表
 */
///#end
///#begin en
/**
 *	@brief	Education information list of user
 */
///#end
@property (nonatomic,readonly) NSArray *educations;

///#begin zh-cn
/**
 *	@brief	用户的职业信息列表
 */
///#end
///#begin en
/**
 *	@brief	Career information list of user
 */
///#end
@property (nonatomic,readonly) NSArray *works;

///#begin zh-cn
/**
 *	@brief	初始化化用户信息
 *
 *	@param 	app 	应用信息
 *
 *	@return	用户信息对象
 */
///#end
///#begin en
/**
 *	@brief	Initialize user information.
 *
 *	@param 	app 	The app object.
 *
 *	@return	User object.
 */
///#end
- (id)initWithApp:(id<ISSPlatformApp>)app;


@end
