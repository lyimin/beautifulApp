//
//  SSQZoneShareContentEntity.h
//  QZoneConnection
//
//  Created by 冯 鸿杰 on 13-10-22.
//  Copyright (c) 2013年 掌淘科技. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ShareSDK/ShareSDKPlugin.h>

/**
 *	@brief	分享内容实体
 */
@interface SSQZoneShareContentEntity : NSObject <ISSPlatformShareContentEntity,
                                                 NSCoding>
{
@private
    NSMutableDictionary *_dict;
}

/**
 *	@brief	标题
 */
@property (nonatomic,copy) NSString *title;

/**
 *	@brief	链接
 */
@property (nonatomic,copy) NSString *url;

/**
 *	@brief	来源网站名称
 */
@property (nonatomic,copy) NSString *site;

/**
 *	@brief	网站地址url
 */
@property (nonatomic,copy) NSString *fromUrl;

/**
 *	@brief	用户评论内容
 */
@property (nonatomic,copy) NSString *comment;

/**
 *	@brief	摘要内容
 */
@property (nonatomic,copy) NSString *summary;

/**
 *	@brief	分享图片
 */
@property (nonatomic,retain) id<ISSCAttachment> image;

/**
 *	@brief	分享内容的类型。4表示网页；5表示视频
 */
@property (nonatomic,retain) NSNumber *type;

/**
 *	@brief	播放地址
 */
@property (nonatomic,copy) NSString *playUrl;

/**
 *	@brief	同步微博标识
 */
@property (nonatomic,retain) NSNumber *nswb;

/**
 *	@brief	通过分享内容解析实体数据
 *
 *	@param 	content 	分享内容
 */
- (void)parseWithContent:(id<ISSContent>)content;

@end
