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
#import <ShareSDK/ShareSDKPlugin.h>

///#begin zh-cn
/**
 *	@brief	分享内容实体
 */
///#end
///#begin en
/**
 *	@brief	Share Content Entity.
 */
///#end
@interface SSSinaWeiboShareContentEntity : NSObject <ISSPlatformShareContentEntity,
                                                     NSCoding>
{
@private
    NSMutableDictionary *_dict;
}

///#begin zh-cn
/**
 *	@brief	分享内容
 */
///#end
///#begin en
/**
 *	@brief	Share content.
 */
///#end
@property (nonatomic,copy) NSString *content;

///#begin zh-cn
/**
 *	@brief	分享图片
 */
///#end
///#begin en
/**
 *	@brief	Image attachment.
 */
///#end
@property (nonatomic,retain) id<ISSCAttachment> image;

///#begin zh-cn
/**
 *	@brief	地理位置信息
 */
///#end
///#begin en
/**
 *	@brief	Location coordinate.
 */
///#end
@property (nonatomic,retain) SSCLocationCoordinate2D *locationCoordinate;

///#begin zh-cn
/**
 *	@brief	通过分享内容解析实体数据
 *
 *	@param 	content 	分享内容
 */
///#end
///#begin en
/**
 *	@brief	Parsed entity data by sharing content
 *
 *	@param 	content 	Content object.
 */
///#end
- (void)parseWithContent:(id<ISSContent>)content;

@end
