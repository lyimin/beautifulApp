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
 *	@brief	分享信息
 */
///#end
///#begin en
/**
 *	@brief	Share information.
 */
///#end
@interface SSQZoneShareInfo : NSObject <ISSPlatformShareInfo,
                                        NSCoding,
                                        ISSCDataObject>
{
@private
    NSDictionary *_sourceData;
    NSString *_sid;
    NSString *_text;
    NSArray *_urls;
    NSArray *_imgs;
    NSDictionary *_extInfo;
}

///#begin zh-cn
/**
 *	@brief	分享ID
 */
///#end
///#begin en
/**
 *	@brief	Share id.
 */
///#end
@property (nonatomic,copy) NSString *sid;

///#begin zh-cn
/**
 *	@brief	分享内容
 */
///#end
///#begin en
/**
 *	@brief	Share content string.
 */
///#end
@property (nonatomic,copy) NSString *text;

///#begin zh-cn
/**
 *	@brief	分享的链接列表
 */
///#end
///#begin en
/**
 *	@brief	a URL list.
 */
///#end
@property (nonatomic,retain) NSArray *urls;

///#begin zh-cn
/**
 *	@brief	分享的图片列表
 */
///#end
///#begin en
/**
 *	@brief	a image list.
 */
///#end
@property (nonatomic,retain) NSArray *imgs;

///#begin zh-cn
/**
 *	@brief	扩展信息
 */
///#end
///#begin en
/**
 *	@brief	Extended information.
 */
///#end
@property (nonatomic,retain) NSDictionary *extInfo;

///#begin zh-cn
/**
 *	@brief	原始数据
 */
///#end
///#begin en
/**
 *	@brief	Raw data.
 */
///#end
@property (nonatomic,retain) NSDictionary *sourceData;

///#begin zh-cn
/**
 *	@brief	创建分享信息
 *
 *	@param 	response 	服务器返回数据
 *
 *	@return	分享信息对象
 */
///#end
///#begin en
/**
 *	@brief	Create a share information.
 *
 *	@param 	response 	Response data.
 *
 *	@return	Response data.
 */
///#end
+ (SSQZoneShareInfo *)shareInfoWithResponse:(NSDictionary *)response;

@end
