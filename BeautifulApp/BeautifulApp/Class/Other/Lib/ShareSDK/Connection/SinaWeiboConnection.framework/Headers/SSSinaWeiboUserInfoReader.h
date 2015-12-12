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

@class SSSinaWeiboStatusInfoReader;

///#begin zh-cn
/**
 *	@brief	用户信息读取器
 */
///#end
///#begin en
/**
 *	@brief	User information reader.
 */
///#end
@interface SSSinaWeiboUserInfoReader : NSObject
{
@private
    NSDictionary *_sourceData;
}

///#begin zh-cn
/**
 *	@brief	源数据
 */
///#end
///#begin en
/**
 *	@brief	Raw data.
 */
///#end
@property (nonatomic,readonly) NSDictionary *sourceData;

///#begin zh-cn
/**
 *	@brief	字符串型的用户UID
 */
///#end
///#begin en
/**
 *	@brief	User id string.
 */
///#end
@property (nonatomic,readonly) NSString *idstr;

///#begin zh-cn
/**
 *	@brief	用户昵称
 */
///#end
///#begin en
/**
 *	@brief	Screen name.
 */
///#end
@property (nonatomic,readonly) NSString *screenName;

///#begin zh-cn
/**
 *	@brief	友好显示名称
 */
///#end
///#begin en
/**
 *	@brief	User name.
 */
///#end
@property (nonatomic,readonly) NSString *name;

///#begin zh-cn
/**
 *	@brief	用户所在省级ID
 */
///#end
///#begin en
/**
 *	@brief	Province id.
 */
///#end
@property (nonatomic,readonly) NSInteger province;

///#begin zh-cn
/**
 *	@brief	用户所在城市ID
 */
///#end
///#begin en
/**
 *	@brief	City id.
 */
///#end
@property (nonatomic,readonly) NSInteger city;

///#begin zh-cn
/**
 *	@brief	用户所在地
 */
///#end
///#begin en
/**
 *	@brief	Location information.
 */
///#end
@property (nonatomic,readonly) NSString *location;

///#begin zh-cn
/**
 *	@brief	用户个人描述
 */
///#end
///#begin en
/**
 *	@brief	Description of this person.
 */
///#end
@property (nonatomic,readonly) NSString *description;

///#begin zh-cn
/**
 *	@brief	用户博客地址
 */
///#end
///#begin en
/**
 *	@brief	blog URL of this person.
 */
///#end
@property (nonatomic,readonly) NSString *url;

///#begin zh-cn
/**
 *	@brief	用户头像地址，50×50像素
 */
///#end
///#begin en
/**
 *	@brief	User avatar address, 50 × 50 pixels
 */
///#end
@property (nonatomic,readonly) NSString *profileImageUrl;

///#begin zh-cn
/**
 *	@brief	用户的微博统一URL地址
 */
///#end
///#begin en
/**
 *	@brief	Profile url.
 */
///#end
@property (nonatomic,readonly) NSString *profileUrl;

///#begin zh-cn
/**
 *	@brief	用户的个性化域名
 */
///#end
///#begin en
/**
 *	@brief	User's personalized domain
 */
///#end
@property (nonatomic,readonly) NSString *domain;

///#begin zh-cn
/**
 *	@brief	用户的微号
 */
///#end
///#begin en
/**
 *	@brief	Wei hao.
 */
///#end
@property (nonatomic,readonly) NSString *weihao;

///#begin zh-cn
/**
 *	@brief	性别，m：男、f：女、n：未知
 */
///#end
///#begin en
/**
 *	@brief	Gender，m：Male、f：Female、n：Unknown
 */
///#end
@property (nonatomic,readonly) NSString *gender;

///#begin zh-cn
/**
 *	@brief	粉丝数
 */
///#end
///#begin en
/**
 *	@brief	Followers count.
 */
///#end
@property (nonatomic,readonly) NSInteger followersCount;

///#begin zh-cn
/**
 *	@brief	关注数
 */
///#end
///#begin en
/**
 *	@brief	Friends count.
 */
///#end
@property (nonatomic,readonly) NSInteger friendsCount;

///#begin zh-cn
/**
 *	@brief	微博数
 */
///#end
///#begin en
/**
 *	@brief	Statuses count.
 */
///#end
@property (nonatomic,readonly) NSInteger statusesCount;

///#begin zh-cn
/**
 *	@brief	收藏数
 */
///#end
///#begin en
/**
 *	@brief	Favorites count.
 */
///#end
@property (nonatomic,readonly) NSInteger favouritesCount;

///#begin zh-cn
/**
 *	@brief	用户创建（注册）时间
 */
///#end
///#begin en
/**
 *	@brief	User-created (registered) time
 */
///#end
@property (nonatomic,readonly) NSString *createdAt;

///#begin zh-cn
/**
 *	@brief	暂未支持
 */
///#end
///#begin en
/**
 *	@brief	Not support.
 */
///#end
@property (nonatomic,readonly) BOOL following;

///#begin zh-cn
/**
 *	@brief	是否允许所有人给我发私信，true：是，false：否
 */
///#end
///#begin en
/**
 *	@brief	Whether to allow everyone to send me a private letter, true: YES, false: No
 */
///#end
@property (nonatomic,readonly) BOOL allowAllActMsg;

///#begin zh-cn
/**
 *	@brief	是否允许标识用户的地理位置，true：是，false：否
 */
///#end
///#begin en
/**
 *	@brief	Whether to allow the user to identify the location, true: YES, false: No
 */
///#end
@property (nonatomic,readonly) BOOL geoEnabled;

///#begin zh-cn
/**
 *	@brief	是否是微博认证用户，即加V用户，true：是，false：否
 */
///#end
///#begin en
/**
 *	@brief	Whether Weibo authenticate the user, that user plus V, true: YES, false: No
 */
///#end
@property (nonatomic,readonly) BOOL verified;

///#begin zh-cn
/**
 *	@brief	暂未支持
 */
///#end
///#begin en
/**
 *	@brief	Not support.
 */
///#end
@property (nonatomic,readonly) NSInteger verifiedType;

///#begin zh-cn
/**
 *	@brief	用户备注信息，只有在查询用户关系时才返回此字段
 */
///#end
///#begin en
/**
 *	@brief	Remarks user, the user only when the query relationship returns this field
 */
///#end
@property (nonatomic,readonly) NSString *remark;

///#begin zh-cn
/**
 *	@brief	用户的最近一条微博信息字段
 */
///#end
///#begin en
/**
 *	@brief	Recently a status information.
 */
///#end
@property (nonatomic,readonly) SSSinaWeiboStatusInfoReader *status;

///#begin zh-cn
/**
 *	@brief	是否允许所有人对我的微博进行评论，true：是，false：否
 */
///#end
///#begin en
/**
 *	@brief	Whether to allow everyone on my status comment, true: YES, false: No
 */
///#end
@property (nonatomic,readonly) BOOL allowAllComment;

///#begin zh-cn
/**
 *	@brief	用户大头像地址
 */
///#end
///#begin en
/**
 *	@brief	Large image path of avatar
 */
///#end
@property (nonatomic,readonly) NSString *avatarLarge;

///#begin zh-cn
/**
 *	@brief	认证原因
 */
///#end
///#begin en
/**
 *	@brief	Verified reason.
 */
///#end
@property (nonatomic,readonly) NSString *verifiedReason;

///#begin zh-cn
/**
 *	@brief	该用户是否关注当前登录用户，true：是，false：否
 */
///#end
///#begin en
/**
 *	@brief	Whether the user is follow me, true: YES, false: No
 */
///#end
@property (nonatomic,readonly) BOOL followMe;

///#begin zh-cn
/**
 *	@brief	用户的在线状态，0：不在线、1：在线
 */
///#end
///#begin en
/**
 *	@brief	online status，0：offline、1：online
 */
///#end
@property (nonatomic,readonly) NSInteger onlineStatus;

///#begin zh-cn
/**
 *	@brief	用户的互粉数
 */
///#end
///#begin en
/**
 *	@brief	bi followers count.
 */
///#end
@property (nonatomic,readonly) NSInteger biFollowersCount;

///#begin zh-cn
/**
 *	@brief	用户当前的语言版本，zh-cn：简体中文，zh-tw：繁体中文，en：英语
 */
///#end
///#begin en
/**
 *	@brief	The current language, zh-cn: Simplified Chinese, zh-tw: Traditional Chinese, en: English
 */
///#end
@property (nonatomic,readonly) NSString *lang;

///#begin zh-cn
/**
 *	@brief	初始化读取器
 *
 *	@param 	sourceData 	原数据
 *
 *	@return	读取器实例对象
 */
///#end
///#begin en
/**
 *	@brief	Initialize reader.
 *
 *	@param 	sourceData 	Raw data.
 *
 *	@return	Reader object.
 */
///#end
- (id)initWithSourceData:(NSDictionary *)sourceData;

///#begin zh-cn
/**
 *	@brief	创建用户信息读取器
 *
 *	@param 	sourceData 	原数据
 *
 *	@return	读取器实例对象
 */
///#end
///#begin en
/**
 *	@brief	Create a user information reader.
 *
 *	@param 	sourceData 	Raw data.
 *
 *	@return	Reader object.
 */
///#end
+ (SSSinaWeiboUserInfoReader *)readerWithSourceData:(NSDictionary *)sourceData;


@end
