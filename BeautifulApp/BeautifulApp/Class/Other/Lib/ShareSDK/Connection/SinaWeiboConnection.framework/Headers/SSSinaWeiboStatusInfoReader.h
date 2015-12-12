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
#import "SSSinaWeiboGeoReader.h"
#import "SSSinaWeiboVisibleReader.h"

@class SSSinaWeiboUserInfoReader;

///#begin zh-cn
/**
 *	@brief	微博信息读取器
 */
///#end
///#begin en
/**
 *	@brief	Status Information Reader.
 */
///#end
@interface SSSinaWeiboStatusInfoReader : NSObject
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
 *	@brief	微博创建时间
 */
///#end
///#begin en
/**
 *	@brief	Created time.
 */
///#end
@property (nonatomic,readonly) NSString *createdAt;

///#begin zh-cn
/**
 *	@brief	字符串型的微博ID
 */
///#end
///#begin en
/**
 *	@brief	status id string.
 */
///#end
@property (nonatomic,readonly) NSString *idstr;

///#begin zh-cn
/**
 *	@brief	微博ID
 */
///#end
///#begin en
/**
 *	@brief	Status id.
 */
///#end
@property (nonatomic,readonly) long long Id;

///#begin zh-cn
/**
 *	@brief	微博MID
 */
///#end
///#begin en
/**
 *	@brief	Status mid.
 */
///#end
@property (nonatomic,readonly) long long mid;

///#begin zh-cn
/**
 *	@brief	微博信息内容
 */
///#end
///#begin en
/**
 *	@brief	Content string.
 */
///#end
@property (nonatomic,readonly) NSString *text;

///#begin zh-cn
/**
 *	@brief	微博来源
 */
///#end
///#begin en
/**
 *	@brief	Source.
 */
///#end
@property (nonatomic,readonly) NSString *source;

///#begin zh-cn
/**
 *	@brief	是否已收藏，true：是，false：否
 */
///#end
///#begin en
/**
 *	@brief	Whether favorited, true: YES, false: No
 */
///#end
@property (nonatomic,readonly) BOOL favorited;

///#begin zh-cn
/**
 *	@brief	是否被截断，true：是，false：否
 */
///#end
///#begin en
/**
 *	@brief	Whether truncated, true: YES, false: No
 */
///#end
@property (nonatomic,readonly) BOOL truncated;

///#begin zh-cn
/**
 *	@brief	回复ID
 */
///#end
///#begin en
/**
 *	@brief	Reply status id.
 */
///#end
@property (nonatomic,readonly) NSString *inReplyToStatusId;

///#begin zh-cn
/**
 *	@brief	回复人UID
 */
///#end
///#begin en
/**
 *	@brief	Reply user id.
 */
///#end
@property (nonatomic,readonly) NSString *inReplyToUserId;

///#begin zh-cn
/**
 *	@brief	回复人昵称
 */
///#end
///#begin en
/**
 *	@brief	Reply Nickname
 */
///#end
@property (nonatomic,readonly) NSString *inReplyToScreenName;

///#begin zh-cn
/**
 *	@brief	缩略图片地址，没有时不返回此字段
 */
///#end
///#begin en
/**
 *	@brief	Address of the thumbnail, this field is not returned when no
 */
///#end
@property (nonatomic,readonly) NSString *thumbnailPic;

///#begin zh-cn
/**
 *	@brief	中等尺寸图片地址，没有时不返回此字段
 */
///#end
///#begin en
/**
 *	@brief	Address of the middle picture, this field is not returned when no
 */
///#end
@property (nonatomic,readonly) NSString *bmiddlePic;

///#begin zh-cn
/**
 *	@brief	原始图片地址，没有时不返回此字段
 */
///#end
///#begin en
/**
 *	@brief	Address of the original picture, this field is not returned when no
 */
///#end
@property (nonatomic,readonly) NSString *originalPic;

///#begin zh-cn
/**
 *	@brief	地理信息字段
 */
///#end
///#begin en
/**
 *	@brief	Geo information
 */
///#end
@property (nonatomic,readonly) SSSinaWeiboGeoReader *geo;

///#begin zh-cn
/**
 *	@brief	微博作者的用户信息字段
 */
///#end
///#begin en
/**
 *	@brief	user information
 */
///#end
@property (nonatomic,readonly) SSSinaWeiboUserInfoReader *user;

///#begin zh-cn
/**
 *	@brief	转发数
 */
///#end
///#begin en
/**
 *	@brief	Reposts count.
 */
///#end
@property (nonatomic,readonly) NSInteger repostsCount;

///#begin zh-cn
/**
 *	@brief	评论数
 */
///#end
///#begin en
/**
 *	@brief	Comments count.
 */
///#end
@property (nonatomic,readonly) NSInteger commentsCount;

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
@property (nonatomic,readonly) NSInteger attitudesCount;

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
@property (nonatomic,readonly) NSInteger mlevel;

///#begin zh-cn
/**
 *	@brief	微博的可见性及指定可见分组信息
 */
///#end
///#begin en
/**
 *	@brief	Status visibility and visibility group information
 */
///#end
@property (nonatomic,readonly) SSSinaWeiboVisibleReader *visible;

///#begin zh-cn
/**
 *	@brief	被转发微博信息
 */
///#end
///#begin en
/**
 *	@brief	Retweeted status.
 */
///#end
@property (nonatomic,readonly) SSSinaWeiboStatusInfoReader *retweetedStatus;

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
 *	@brief	创建微博信息读取器
 *
 *	@param 	sourceData 	原数据
 *
 *	@return	读取器实例对象
 */
///#end
///#begin en
/**
 *	@brief	Create a status reader
 *
 *	@param 	sourceData 	Raw data.
 *
 *	@return	Status reader.
 */
///#end
+ (SSSinaWeiboStatusInfoReader *)readerWithSourceData:(NSDictionary *)sourceData;

@end
