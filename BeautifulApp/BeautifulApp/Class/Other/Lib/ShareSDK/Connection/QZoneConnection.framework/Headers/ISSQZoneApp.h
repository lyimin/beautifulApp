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
#import "SSQZoneUser.h"
#import "SSQZoneErrorInfo.h"
#import "SSQZoneShareInfo.h"
#import <ShareSDK/ShareSDKPlugin.h>

///#begin zh-cn
/**
 *	@brief	QQ空间应用
 */
///#end
///#begin en
/**
 *	@brief	QZone App.
 */
///#end
@protocol ISSQZoneApp <ISSPlatformApp>

///#begin zh-cn
/**
 *	@brief	获取应用Key
 *
 *	@return	应用Key
 */
///#end
///#begin en
/**
 *	@brief	Get app key.
 *
 *	@return	App key.
 */
///#end
- (NSString *)appKey;

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
 *	@brief	获取SSO回调地址
 *
 *	@return	SSO回调地址
 */
///#end
///#begin en
/**
 *	@brief	Get SSO callback URL address.
 *
 *	@return	SSO callback url address.
 */
///#end
- (NSString *)ssoCallbackUrl;

///#begin zh-cn
/**
 *	@brief	设置是否打开网页授权，默认值为NO。旧时申请QQ空间应用是可以进行网页授权的，新申请的应用目前不允许网页授权
 *
 *	@return	YES为打开网页授权开关，NO为关闭
 */
///#end
///#begin en
/**
 *	@brief  whether to allow QZone to authorize through Web（the default value is NO）,the new QZone App is allow SSO only.
 *
 *	@return YES means allow to authorize through Web,NO means no allow
 */
///#end
- (void)setIsAllowWebAuthorize:(BOOL)isAllowWebAuthorize;

///#begin zh-cn
/**
 *	@brief	获取是否打开网页授权开关的值
 *
 *	@return	YES为打开网页授权开关，NO为关闭
 */
///#end
///#begin en
/**
 *	@brief	Get the value of isAllowWebAuthorize
 *
 *	@return YES means allow to authorize through Web,NO means no allow
 */
///#end
- (BOOL)isAllowWebAuthorize;

///#begin zh-cn
/**
 *	@brief	上传照片
 *
 *	@param 	pic 	照片
 *	@param 	desc 	描述
 *	@param 	title 	标题
 *	@param 	albumid 	相册ID，为nil则表示默认相册
 */
///#end
///#begin en
/**
 *	@brief	Upload picture.
 *
 *	@param 	pic 	Picture attachment object.
 *	@param 	desc 	Description.
 *	@param 	title 	Title string.
 *	@param 	albumid 	Album ID，The default is nil indicates album
 */
///#end
- (void)uploadPic:(id<ISSCAttachment>)pic
             desc:(NSString *)desc
            title:(NSString *)title
          albumid:(NSString *)albumid
           result:(void(^)(BOOL result, id image, CMErrorInfo *error))result;

///#begin zh-cn
/**
 *	@brief	添加分享
 *
 *	@param 	title 	标题，最长36个中文字，超出部分会被截断。
 *	@param 	url 	分享所在网页资源的链接，点击后跳转至第三方网页
 *	@param 	site 	分享的来源网站名称，请填写网站申请接入时注册的网站名称
 *	@param 	fromUrl 	分享的来源网站对应的网站地址url
 *	@param 	comment 	用户评论内容，最长40个中文字，超出部分会被截断。
 *	@param 	summary 	所分享的网页资源的摘要内容，或者是网页的概要描述，最长80个中文字，超出部分会被截断。
 *	@param 	images 	所分享的网页资源的代表性图片链接
 *	@param 	type 	分享内容的类型。4表示网页；5表示视频（type=5时，必须传入playurl）。
 *	@param 	playUrl 	长度限制为256字节。仅在type=5的时候有效，表示视频的swf播放地址。
 *	@param 	nswb 	值为1时，表示分享不默认同步到微博，其他值或者不传此参数表示默认同步到微博。
 *  @param  result  返回回调
 */
///#end
///#begin en
/**
 *	@brief	Add share information.
 *
 *	@param 	title 	Title, the longest 36 characters, the excess will be truncated.
 *	@param 	url 	Sharing website where links to resources, click after the jump to a third party website
 *	@param 	site 	Site name when sharing the source site, please fill out the application access to registration site name.
 *	@param 	fromUrl 	Shared source site corresponding website address url
 *	@param 	comment 	User Content, the longest 40 characters, the excess will be truncated.
 *	@param 	summary 	Summary of content sharing web resources, or a summary description of the page, the longest 80 characters, the excess will be truncated.
 *	@param 	images 	Representative image links shared web resources.
 *	@param 	type 	Share types of content. 4 indicate that the page; 5 shows a video (type = 5, you must pass playurl).
 *	@param 	playUrl 	Length is limited to 256 bytes. Type = 5 only when effective, which means that the video playback swf address.
 *	@param 	nswb 	A value of 1, which means that the default is not synchronized to Tencent Weibo, other values ​​or do not pass this parameter indicates the default synchronized to Tencent Weibo.
 *  @param  result  Result handler.
 */
///#end
- (void)addShareWithTitle:(NSString *)title
                      url:(NSString *)url
                     site:(NSString *)site
                  fromUrl:(NSString *)fromUrl
                  comment:(NSString *)comment
                  summary:(NSString *)summary
                   images:(NSArray *)images
                     type:(NSNumber *)type
                  playUrl:(NSString *)playUrl
                     nswb:(NSNumber *)nswb
                   result:(SSShareResultEvent)result;

///#begin zh-cn
/**
 *	@brief	定向分享
 *
 *	@param 	title 	标题
 *	@param 	description 	分享的内容描述
 *	@param 	shareUrl 	分享连接
 *	@param 	pics 	分享图片
 *	@param 	summary 	分享的摘要内容
 *	@param 	url 	分享的来源网站对应的网站地址url
 *	@param 	act 	默认为“进入应用”
 *	@param 	result 	返回回调
 */
///#end
///#begin en
/**
 *	@brief	Send story.
 *
 *	@param 	title 	Title string.
 *	@param 	description 	Description.
 *	@param 	shareUrl 	Share url.
 *	@param 	pics 	a image list.
 *	@param 	summary 	Summary string.
 *	@param 	url 	URL string.
 *	@param 	act 	Default is “进入应用”
 *	@param 	result 	Result handler.
 */
///#end
- (void)sendStoryWithTitle:(NSString *)title
               description:(NSString *)description
                  shareUrl:(NSString *)shareUrl
                      pics:(NSArray *)pics
                   summary:(NSString *)summary
                       url:(NSString *)url
                       act:(NSString *)act
                    result:(SSShareResultEvent)result;



@end
