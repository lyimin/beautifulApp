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
#import "SSSinaWeiboUserInfoReader.h"
#import "SSSinaWeiboStatusInfoReader.h"

///#begin zh-cn
/**
 *	@brief	评论信息读取器
 */
///#end
///#begin en
/**
 *	@brief	Comment Reader.
 */
///#end
@interface SSSinaWeiboCommentReader : NSObject
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
 *	@brief	评论创建时间
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
 *	@brief	评论的ID
 */
///#end
///#begin en
/**
 *	@brief	Comment id.
 */
///#end
@property (nonatomic,readonly) long long Id;

///#begin zh-cn
/**
 *	@brief	评论的内容
 */
///#end
///#begin en
/**
 *	@brief	Comment text.
 */
///#end
@property (nonatomic,readonly) NSString *text;

///#begin zh-cn
/**
 *	@brief	评论的来源
 */
///#end
///#begin en
/**
 *	@brief	Comment source
 */
///#end
@property (nonatomic,readonly) NSString *source;

///#begin zh-cn
/**
 *	@brief	评论作者的用户信息
 */
///#end
///#begin en
/**
 *	@brief	Review of user information
 */
///#end
@property (nonatomic,readonly) SSSinaWeiboUserInfoReader *user;

///#begin zh-cn
/**
 *	@brief	评论的MID
 */
///#end
///#begin en
/**
 *	@brief	Comment mid.
 */
///#end
@property (nonatomic,readonly) NSString *mid;

///#begin zh-cn
/**
 *	@brief	字符串型的评论ID
 */
///#end
///#begin en
/**
 *	@brief	Comment id string
 */
///#end
@property (nonatomic,readonly) NSString *idStr;

///#begin zh-cn
/**
 *	@brief	评论的微博信息
 */
///#end
///#begin en
/**
 *	@brief	Comments stuatus information
 */
///#end
@property (nonatomic,readonly) SSSinaWeiboStatusInfoReader *status;

///#begin zh-cn
/**
 *	@brief	评论来源评论，当本评论属于对另一评论的回复时返回此字段
 */
///#end
///#begin en
/**
 *	@brief	Review source comments, return to this field when the comments are a reply to another comment
 */
///#end
@property (nonatomic,readonly) SSSinaWeiboCommentReader *replyComment;

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
 *	@brief	创建评论信息读取器
 *
 *	@param 	sourceData 	原数据
 *
 *	@return	读取器实例对象
 */
///#end
///#begin en
/**
 *	@brief	Create a comment reader.
 *
 *	@param 	sourceData 	Raw data.
 *
 *	@return Reader object.
 */
///#end
+ (SSSinaWeiboCommentReader *)readerWithSourceData:(NSDictionary *)sourceData;

@end
