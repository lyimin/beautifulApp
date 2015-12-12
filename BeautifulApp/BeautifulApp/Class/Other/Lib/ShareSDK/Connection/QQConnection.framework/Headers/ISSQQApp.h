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
#import "SSQQErrorInfo.h"
#import <ShareSDK/ShareSDKPlugin.h>

///#begin zh-cn
/**
 *	@brief	QQ应用协议
 */
///#end
///#begin en
/**
 *	@brief	QQ App Protocol.
 */
///#end
@protocol ISSQQApp <ISSPlatformApp>

///#begin zh-cn
/**
 *	@brief	获取应用ID
 *
 *	@return	应用ID
 */
///#end
///#begin en
/**
 *	@brief	Get app id.
 *
 *	@return	App id.
 */
///#end
- (NSString *)appId;

///#begin zh-cn
/**
 *	@brief	分享文本信息
 *
 *	@param 	text 	文本信息
 *  @param  result  返回回调
 */
///#end
///#begin en
/**
 *	@brief	Send a text message.
 *
 *	@param 	text 	Content string.
 *  @param  result  Result handler.
 */
///#end
- (void)sendText:(NSString *)text
          result:(SSShareResultEvent)result;

///#begin zh-cn
/**
 *	@brief	分享图片信息
 *
 *	@param 	title 	标题
 *	@param 	description 	描述
 *	@param 	pic 	图片信息
 *  @param  result  返回回调
 */
///#end
///#begin en
/**
 *	@brief	Send a picture message.
 *
 *	@param 	title 	Title string.
 *	@param 	description 	Description.
 *	@param 	pic 	Pictrue attachment object.
 *  @param  result  Result handler.
 */
///#end
- (void)sendPic:(NSString *)title
    description:(NSString *)description
            pic:(id<ISSCAttachment>)pic
         result:(SSShareResultEvent)result;

///#begin zh-cn
/**
 *	@brief	分享新闻信息
 *
 *	@param 	title 	标题
 *	@param 	content 	内容
 *	@param 	url 	链接
 *	@param 	pic 	预览图
 *  @param  result  返回回调
 */
///#end
///#begin en
/**
 *	@brief	Send a news message.
 *
 *	@param 	title 	Title string.
 *	@param 	content 	Content string.
 *	@param 	url 	URL string.
 *	@param 	pic 	Thumbnail.
 *  @param  result  Result handler.
 */
///#end
- (void)sendNews:(NSString *)title
         content:(NSString *)content
             url:(NSString *)url
             pic:(id<ISSCAttachment>)pic
          result:(SSShareResultEvent)result;

///#begin zh-cn
/**
 *	@brief	分享音乐信息
 *
 *	@param 	title 	标题
 *	@param 	content 	内容
 *	@param 	url 	链接
 *	@param 	pic 	预览图
 *  @param  result  返回回调
 */
///#end
///#begin en
/**
 *	@brief	Send a music message.
 *
 *	@param 	title 	Title string.
 *	@param 	content 	Content string.
 *	@param 	url 	URL string.
 *	@param 	pic 	Thumbnail.
 *  @param  result  Result handler.
 */
///#end
- (void)sendMusic:(NSString *)title
          content:(NSString *)content
              url:(NSString *)url
              pic:(id<ISSCAttachment>)pic
           result:(SSShareResultEvent)result;

///#begin zh-cn
/**
 *	@brief	分享视频信息
 *
 *	@param 	title 	标题
 *	@param 	content 	内容
 *	@param 	url 	链接
 *	@param 	pic 	预览图
 *  @param  result  返回回调
 */
///#end
///#begin en
/**
 *	@brief	Send a video message.
 *
 *	@param 	title 	Title string.
 *	@param 	content 	Content string.
 *	@param 	url 	URL string.
 *	@param 	pic 	Thumbnail.
 *  @param  result  Result handler.
 */
///#end
- (void)sendVideo:(NSString *)title
          content:(NSString *)content
              url:(NSString *)url
              pic:(id<ISSCAttachment>)pic
           result:(SSShareResultEvent)result;


@end
