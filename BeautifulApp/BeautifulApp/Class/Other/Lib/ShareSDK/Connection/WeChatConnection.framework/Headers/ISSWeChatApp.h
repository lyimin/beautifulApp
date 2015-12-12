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
#import "SSWeChatErrorInfo.h"
#import "SSWeChatTypeDef.h"
#import <ShareSDK/ShareSDKPlugin.h>

///#begin zh-cn
/**
 *	@brief	微信应用协议
 */
///#end
///#begin en
/**
 *	@brief	WeChat App.
 */
///#end
@protocol ISSWeChatApp <ISSPlatformApp>

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
 *	@brief	获取应用密钥
 *
 *	@return	应用密钥
 */
///#end
///#begin en
/**
 *	@brief	Get app secret.
 *
 *	@return	App secret.
 */
///#end
- (NSString *)appSecret;

///#begin zh-cn
/**
 *	@brief	获取分享场景
 *
 *	@return	分享场景
 */
///#end
///#begin en
/**
 *	@brief	Get a share scene.
 *
 *	@return	Share scene.
 */
///#end
- (SSWeChatScene)scene;

///#begin zh-cn
/**
 *	@brief	设置委托
 *
 *	@param 	delegate 	委托对象
 */
///#end
///#begin en
/**
 *	@brief	Set a delegate.
 *
 *	@param 	delegate 	Delegate object.
 */
///#end
- (void)setDelegate:(id)delegate;

///#begin zh-cn
/**
 *	@brief	发送文本消息
 *
 *	@param 	content 	内容
 *	@param 	scene 	类型
 *  @param  result  返回回调
 */
///#end
///#begin en
/**
 *	@brief	Send a text message.
 *
 *	@param 	content 	Content string.
 *	@param 	scene 	Scene
 *  @param  result  Result handler.
 */
///#end
- (void)sendText:(NSString *)content
          result:(SSShareResultEvent)result;

///#begin zh-cn
/**
 *	@brief	发送图片消息
 *
 *  @param  title   标题
 *  @param  description 描述
 *  @param  thumbPic    缩略图
 *	@param 	pic 	图片
 *	@param 	scene 	类型
 *  @param  result  返回回调
 */
///#end
///#begin en
/**
 *	@brief	Send a picture message.
 *
 *  @param  title   Title string.
 *  @param  description     Picture description.
 *  @param  thumbPic    Thumbnail.
 *	@param 	pic 	Picture attachment.
 *	@param 	scene 	Scene.
 *  @param  result  Result handler.
 */
///#end
- (void)sendPic:(NSString *)title
    description:(NSString *)description
       thumbPic:(id<ISSCAttachment>)thumbPic
            pic:(id<ISSCAttachment>)pic
         result:(SSShareResultEvent)result;

///#begin zh-cn
/**
 *	@brief	发送新闻消息
 *
 *	@param 	title 	标题
 *	@param 	content 	内容
 *	@param 	pic 	预览图
 *	@param 	url 	链接
 *	@param 	scene 	类型
 *  @param  result  返回回调
 */
///#end
///#begin en
/**
 *	@brief	Send a new message.
 *
 *	@param 	title 	Title string.
 *	@param 	content 	Content string.
 *	@param 	pic 	Thumbnail.
 *	@param 	url 	URL string.
 *	@param 	scene 	Scene.
 *  @param  result  Result handler.
 */
///#end
- (void)sendNews:(NSString *)title
         content:(NSString *)content
             pic:(id<ISSCAttachment>)pic
             url:(NSString *)url
          result:(SSShareResultEvent)result;

///#begin zh-cn
/**
 *	@brief	发送音乐消息
 *
 *	@param 	title 	标题
 *	@param 	content 	内容
 *	@param 	pic 	预览图
 *	@param 	url 	链接
 *  @param  musicFileUrl    音乐文件路径
 *	@param 	scene 	类型
 *  @param  result  返回回调
 */
///#end
///#begin en
/**
 *	@brief	Send a music message.
 *
 *	@param 	title 	Title string.
 *	@param 	content 	Content string.
 *	@param 	pic 	Thumbnail.
 *	@param 	url 	URL string.
 *  @param  musicFileUrl    Music file URL.
 *	@param 	scene 	Scene.
 *  @param  result  Result handler.
 */
///#end
- (void)sendMusic:(NSString *)title
          content:(NSString *)content
              pic:(id<ISSCAttachment>)pic
              url:(NSString *)url
     musicFileUrl:(NSString *)musicFileUrl
           result:(SSShareResultEvent)result;

///#begin zh-cn
/**
 *	@brief	发送视频消息
 *
 *	@param 	title 	标题
 *	@param 	content 	内容
 *	@param 	pic 	预览图
 *	@param 	url 	链接
 *	@param 	scene 	类型
 *  @param  result  返回回调
 */
///#end
///#begin en
/**
 *	@brief	Send a video message.
 *
 *	@param 	title 	Title string.
 *	@param 	content 	Content string.
 *	@param 	pic 	Thumbnail.
 *	@param 	url 	URL string.
 *	@param 	scene 	Scene.
 *  @param  result  Result handler.
 */
///#end
- (void)sendVideo:(NSString *)title
          content:(NSString *)content
              pic:(id<ISSCAttachment>)pic
              url:(NSString *)url
           result:(SSShareResultEvent)result;

///#begin zh-cn
/**
 *	@brief	发送App信息
 *
 *	@param 	title 	标题
 *	@param 	content 	内容
 *	@param 	pic 	预览图
 *	@param 	url 	链接
 *	@param 	extInfo 	扩展信息
 *	@param 	fileData 	文件数据
 *	@param 	scene 	类型
 *  @param  result  返回回调
 */
///#end
///#begin en
/**
 *	@brief	Send app information.
 *
 *	@param 	title 	Title string.
 *	@param 	content 	Content string.
 *	@param 	pic 	Thumbnail
 *	@param 	url 	URL string.
 *	@param 	extInfo 	Extended information.
 *	@param 	fileData 	File data.
 *	@param 	scene 	Scene
 *  @param  result  Result handler.
 */
///#end
- (void)sendApp:(NSString *)title
        content:(NSString *)content
            pic:(id<ISSCAttachment>)pic
            url:(NSString *)url
        extInfo:(NSString *)extInfo
       fileData:(NSData *)fileData
         result:(SSShareResultEvent)result;

///#begin zh-cn
/**
 *	@brief	发送非Gif图
 *
 *	@param 	pic 	预览图
 *	@param 	emoticonData 	图片数据
 *  @param  result  返回回调
 */
///#end
///#begin en
/**
 *	@brief	Send a Non-GIF image.
 *
 *	@param 	pic 	Thumbnail
 *	@param 	emoticonData 	Image data
 *  @param  result  Result handler.
 */
///#end
- (void)sendNonGif:(id<ISSCAttachment>)pic
      emoticonData:(NSData *)emoticonData
            result:(SSShareResultEvent)result;

///#begin zh-cn
/**
 *	@brief	发送Gif图
 *
 *	@param 	pic 	预览图
 *	@param 	emoticonData 	图片数据
 *  @param  result  返回回调
 */
///#end
///#begin en
/**
 *	@brief	Send a GIF image.
 *
 *	@param 	pic 	Thumbnail
 *	@param 	emoticonData 	Image data.
 *  @param  result  Result handler.
 */
///#end
- (void)sendGif:(id<ISSCAttachment>)pic
   emoticonData:(NSData *)emoticonData
         result:(SSShareResultEvent)result;


@end
