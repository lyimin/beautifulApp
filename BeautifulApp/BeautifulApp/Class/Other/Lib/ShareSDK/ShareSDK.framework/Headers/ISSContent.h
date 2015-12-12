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
#import "ShareSDKTypeDef.h"
#import <ShareSDKCoreService/ShareSDKCoreService.h>
#import "ISSPlatformShareContentEntity.h"

///#begin zh-cn
/**
 *	@brief	分享内容协议
 */
///#end
///#begin en
/**
 *	@brief	Share content protocol
 */
///#end
@protocol ISSContent <NSObject>

///#begin zh-cn
/**
 *	@brief	获取元数据
 *
 *	@param 	name 	名称
 *
 *	@return	数据值
 */
///#end
///#begin en
/**
 *	@brief	Get metadata
 *
 *	@param 	name 	Metadata name
 *
 *	@return	Metadata value
 */
///#end
- (id)getMetadata:(NSString *)name;

///#begin zh-cn
/**
 *	@brief	设置元数据
 *
 *	@param 	name 	名称
 *	@param 	value 	数据值
 */
///#end
///#begin en
/**
 *	@brief	Set metadata
 *
 *	@param 	name 	Metadata name
 *	@param 	value 	Metadata value
 */
///#end
- (void)setMetadata:(NSString *)name value:(id)value;

///#begin zh-cn
/**
 *	@brief	删除元数据
 *
 *	@param 	name 	名称
 */
///#end
///#begin en
/**
 *	@brief	Remove metadata.
 *
 *	@param 	name 	Metadata name
 */
///#end
- (void)removeMetadata:(NSString *)name;

///#begin zh-cn
/**
 *	@brief	获取标题(适用平台：QQ空间、人人、微信、QQ)
 *
 *	@return	标题
 */
///#end
///#begin en
/**
 *	@brief	Get title(suitable platform：QZone、Renren、WeChat、QQ)
 *
 *	@return	title string
 */
///#end
- (NSString *)title;

///#begin zh-cn
/**
 *	@brief	设置标题
 *
 *	@param 	title 	标题
 */
///#end
///#begin en
/**
 *	@brief	Set title.
 *
 *	@param 	title 	Title string.
 */
///#end
- (void)setTitle:(NSString *)title;

///#begin zh-cn
/**
 *	@brief	获取URL(适用平台：QQ空间、人人、Instapaper、微信、QQ)
 *
 *	@return	URL
 */
///#end
///#begin en
/**
 *	@brief	Get URL(suitable platform：QZone、Renren、Instapaper、WeChat、QQ)
 *
 *	@return	URL string
 */
///#end
- (NSString *)url;

///#begin zh-cn
/**
 *	@brief	设置URL
 *
 *	@param 	url 	URL
 */
///#end
///#begin en
/**
 *	@brief	Set URL.
 *
 *	@param 	url 	URL string
 */
///#end
- (void)setUrl:(NSString *)url;

///#begin zh-cn
/**
 *	@brief	获取分享内容主体(适用平台：人人)
 *
 *	@return	分享内容主体
 */
///#end
///#begin en
/**
 *	@brief	Get share description(suitable platform：Renren)
 *
 *	@return	Share description string.
 */
///#end
- (NSString *)desc;

///#begin zh-cn
/**
 *	@brief	设置分享内容主体
 *
 *	@param 	desc 	分享内容主体
 */
///#end
///#begin en
/**
 *	@brief	Set share description.
 *
 *	@param 	desc 	Share description string.
 */
///#end
- (void)setDesc:(NSString *)desc;

///#begin zh-cn
/**
 *	@brief	获取分享类型（适用平台：微信、QQ）
 *
 *	@return	分享类型
 */
///#end
///#begin en
/**
 *	@brief	Get media type（suitable platform：WeChat、QQ）
 *
 *	@return	Media type
 */
///#end
- (SSPublishContentMediaType)mediaType;

///#begin zh-cn
/**
 *	@brief	设置分享类型
 *
 *	@param 	mediaType 	分享类型
 */
///#end
///#begin en
/**
 *	@brief	Set media type.
 *
 *	@param 	mediaType 	Media type.
 */
///#end
- (void)setMediaType:(SSPublishContentMediaType)mediaType;

///#begin zh-cn
/**
 *	@brief	获取分享内容(适用平台：新浪、腾讯、豆瓣、人人、开心、有道云笔记、facebook、twitter、邮件、打印、短信、微信、QQ、拷贝)
 *
 *	@return	分享内容
 */
///#end
///#begin en
/**
 *	@brief	Get share content(suitable platform：Sina Weibo、Tencent Weibo、DouBan、Renren、KaiXin、YouDaoNote、Facebook、Twitter、Mail、Print、SMS、WeChat、QQ、Copy)
 *
 *	@return	share content string.
 */
///#end
- (NSString *)content;

///#begin zh-cn
/**
 *	@brief	设置分享内容
 *
 *	@param 	content 	分享内容
 */
///#end
///#begin en
/**
 *	@brief	Set share content
 *
 *	@param 	content     Share content string.
 */
///#end
- (void)setContent:(NSString *)content;

///#begin zh-cn
/**
 *	@brief	获取默认分享内容，在没有设置content时使用。
 *          (适用平台：新浪、腾讯、豆瓣、人人、开心、有道云笔记、facebook、twitter、邮件、打印、短信、微信、QQ、拷贝)
 *
 *	@return	默认分享内容
 */
///#end
///#begin en
/**
 *	@brief	Get default share content，Used when there is no set content。
 *          (suitable platform：Sina Weibo、Tencent Weibo、DouBan、Renren、KaiXin、YouDaoNote、Facebook、Twitter、Mail、Print、SMS、WeChat、QQ、Copy)
 *
 *	@return	Default share content string.
 */
///#end
- (NSString *)defaultContent;

///#begin zh-cn
/**
 *	@brief	设置默认分享内容
 *
 *	@param 	defaultContent 	默认分享内容
 */
///#end
///#begin en
/**
 *	@brief	Set default share content.
 *
 *	@param 	defaultContent 	Default share content string.
 */
///#end
- (void)setDefaultContent:(NSString *)defaultContent;

///#begin zh-cn
/**
 *	@brief	获取分享图片（适用平台：新浪、腾讯、豆瓣、人人、开心、facebook、twitter、邮件、打印、微信、QQ、短信）
 *
 *	@return	分享图片
 */
///#end
///#begin en
/**
 *	@brief	Get share image.（uitable platform：Sina Weibo、Tencent Weibo、DouBan、Renren、KaiXin、Facebook、Twitter、Mai、Print、WeChat、QQ、SMS）
 *
 *	@return	image attachment object.
 */
///#end
- (id<ISSCAttachment>)image;

///#begin zh-cn
/**
 *	@brief	设置分享图片
 *
 *	@param 	image 	分享图片
 */
///#end
///#begin en
/**
 *	@brief	Set share image.
 *
 *	@param 	image 	image attachment object.
 */
///#end
- (void)setImage:(id<ISSCAttachment>)image;

///#begin zh-cn
/**
 *	@brief	获取分享图片数组（适用平台：腾讯微博、Twitter）
 *
 *	@return	分享图片
 */
///#end
///#begin en
/**
 *	@brief	Get share image array.（suitable platform：Tencent Weibo）
 *
 *	@return	image attachment object array.
 */
///#end
- (NSArray *)imageArray;

///#begin zh-cn
/**
 *	@brief	设置分享图片数组（适用平台：腾讯微博、Twitter）
 *
 *	@param 	image 	分享图片
 */
///#end
///#begin en
/**
 *	@brief	Set share image array.
 *
 *	@param 	image 	image attachment object array.
 */
///#end
- (void)setImageArray:(NSArray *)imageArray;

///#begin zh-cn
/**
 *	@brief	获取地理位置
 *
 *	@return	地理位置
 */
///#end
///#begin en
/**
 *	@brief	Get location
 *
 *	@return	Location object.
 */
///#end
- (SSCLocationCoordinate2D *)locationCoordinate;

///#begin zh-cn
/**
 *	@brief	设置地理位置
 *
 *	@param 	locationCoordinate 	地理位置
 */
///#end
///#begin en
/**
 *	@brief	Set location.
 *
 *	@param 	locationCoordinate 	Location object
 */
///#end
- (void)setLocationCoordinate:(SSCLocationCoordinate2D *)locationCoordinate;

///#begin zh-cn
/**
 *	@brief	获取分组标识
 *
 *	@return	分组标识
 */
///#end
///#begin en
/**
 *	@brief	Get group id.(uitable platform：VK)
 *
 *	@return	Group id string.
 */
///#end
- (NSString *)groupId;

///#begin zh-cn
/**
 *	@brief	设置分组标识
 *
 *	@param 	groupId 	分组标识
 */
///#end
///#begin en
/**
 *	@brief	Set group id.
 *
 *	@return	Group id string.
 */
///#end
- (void)setGroupId:(NSString *)groupId;

///#begin zh-cn
/**
 *	@brief	获取分享内容实体
 *
 *	@param 	type 	平台类型
 *
 *	@return	分享内容实体
 */
///#end
///#begin en
/**
 *	@brief	Get share content entity.
 *
 *	@param 	type 	Platform type.
 *
 *	@return	share content entity.
 */
///#end
- (id<ISSPlatformShareContentEntity>)shareContentEntityWithType:(ShareType)type;

///#begin zh-cn
/**
 *	@brief	设置分享内容实体
 *
 *	@param 	shareContentEntity 	分享内容实体
 *	@param 	type 	平台类型
 */
///#end
///#begin en
/**
 *	@brief	Set share content entity.
 *
 *	@param 	shareContentEntity 	Share content entity.
 *	@param 	type 	Platform type.
 */
///#end
- (void)setShareContentEntity:(id<ISSPlatformShareContentEntity>)shareContentEntity
                         type:(ShareType)type;


#pragma mark ContentUnti

///#begin zh-cn
/**
 *	@brief	添加微信好友内容单元，制定微信分享时的内容使用此参数，如果参数设置为INHERIT_VALUE则默认使用父级类型相关参数
 *
 *	@param 	type 	分享类型,请参考SSPublishContentMediaType
 *	@param 	content 	分享内容
 *	@param 	title 	标题
 *	@param 	url 	URL地址
 *	@param 	image 	分享图片
 *  @param  musicFileUrl    音乐文件路径
 *  @param  extInfo     扩展信息
 *  @param  fileData    文件数据
 *  @param  emoticonData    表情数据，用于存放Gif和非Gif图片数据
 */
///#end
///#begin en
/**
 *	@brief	add WeChat session content unit，When custom WeChat share content use this method，If the parameter is set to INHERIT_VALUE. will using the parent parameter value.
 *
 *	@param 	type 	Media type. Please see SSPublishContentMediaType
 *	@param 	content 	Share content string.
 *	@param 	title 	Title string
 *	@param 	url 	URL string
 *	@param 	image 	Image attachment object
 *  @param  musicFileUrl    Music file URL
 *  @param  extInfo     Extension information
 *  @param  fileData    File data
 *  @param  emoticonData    Emoticon Data，Used to store Gif picture data
 */
///#end
- (void)addWeixinSessionUnitWithType:(NSNumber *)type
                             content:(NSString *)content
                               title:(NSString *)title
                                 url:(NSString *)url
                               image:(id<ISSCAttachment>)image
                        musicFileUrl:(NSString *)musicFileUrl
                             extInfo:(NSString *)extInfo
                            fileData:(NSData *)fileData
                        emoticonData:(NSData *)emoticonData;

///#begin zh-cn
/**
 *	@brief	添加微信朋友圈内容单元，制定微信分享时的内容使用此参数，如果参数设置为INHERIT_VALUE则默认使用父级类型相关参数
 *
 *	@param 	type 	分享类型,请参考SSPublishContentMediaType
 *	@param 	content 	分享内容
 *	@param 	title 	标题
 *	@param 	url 	URL地址
 *	@param 	image 	分享图片
 *  @param  musicFileUrl    音乐文件路径
 *  @param  extInfo     扩展信息
 *  @param  fileData    文件数据
 *  @param  emoticonData    表情数据，用于存放Gif和非Gif图片数据
 */
///#end
///#begin en
/**
 *	@brief	add WeChat Timeline content unit，When custom WeChat share content use this method，If the parameter is set to INHERIT_VALUE. will using the parent parameter value.
 *
 *	@param 	type 	Media type. Please see SSPublishContentMediaType
 *	@param 	content 	Share content string.
 *	@param 	title 	Title string
 *	@param 	url 	URL string
 *	@param 	image 	Image attachment object
 *  @param  musicFileUrl    Music file URL
 *  @param  extInfo     Extension information
 *  @param  fileData    File data
 *  @param  emoticonData    Emoticon Data，Used to store Gif picture data
 */
///#end
- (void)addWeixinTimelineUnitWithType:(NSNumber *)type
                              content:(NSString *)content
                                title:(NSString *)title
                                  url:(NSString *)url
                                image:(id<ISSCAttachment>)image
                         musicFileUrl:(NSString *)musicFileUrl
                              extInfo:(NSString *)extInfo
                             fileData:(NSData *)fileData
                         emoticonData:(NSData *)emoticonData;

///#begin zh-cn
/**
 *	@brief	添加QQ内容单元，制定QQ分享时的内容使用此参数，如果参数设置为INHERIT_VALUE则默认使用父级类型相关参数
 *
 *	@param 	type 	分享类型,请参考SSPublishContentMediaType
 *	@param 	content 	分享内容
 *	@param 	title 	标题
 *	@param 	url 	URL地址
 *	@param 	image 	分享图片
 */
///#end
///#begin en
/**
 *	@brief	add QQ content unit，When custom QQ share content use this method，If the parameter is set to INHERIT_VALUE. will using the parent parameter value.
 *
 *	@param 	type 	Media type. Please see SSPublishContentMediaType
 *	@param 	content 	Share content string.
 *	@param 	title 	Title string
 *	@param 	url 	URL string
 *	@param 	image 	Image attachment object
 */
///#end
- (void)addQQUnitWithType:(NSNumber *)type
                  content:(NSString *)content
                    title:(NSString *)title
                      url:(NSString *)url
                    image:(id<ISSCAttachment>)image;


///#begin zh-cn
/**
 *	@brief	添加短信内容单元，制定短信分享时的内容使用此参数，如果参数设置为INHERIT_VALUE则默认使用父级类型相关参数
 *
 *	@param 	content 	分享内容
 *	@param 	subject 	分享主题 iOS (7.0 and later)
 *	@param 	attachments 	分享附件（id<ISSActtachment>类型组成的数组）iOS (7.0 and later)
 *	@param 	recipients 	收信人 iOS (7.0 and later)
 */
///#end
///#begin en
/**
 *	@brief	add SMS content unit. When custom SMS share content use this method，If the parameter is set to INHERIT_VALUE. will using the parent parameter value.
 *
 *	@param 	content 	Share content string
 *	@param 	subject 	subject iOS (7.0 and later)
 *	@param 	attachments attachments（the type of array element is id<ISSActtachment>）iOS (7.0 and later)
 *	@param 	recipients 	recipients iOS (7.0 and later)
 */
///#end
- (void)addSMSUnitWithContent:(NSString *)content;

- (void)addSMSUnitWithContent:(NSString *)content
                      subject:(NSString *)subject
                  attachments:(NSArray *)attachments
                           to:(NSArray*)recipients;

///#begin zh-cn
/**
 *	@brief	添加QQ空间内容单元，制定QQ空间分享时的内容使用此参数，如果参数设置为INHERIT_VALUE则默认使用父级类型相关参数
 *
 *	@param 	title 	标题
 *	@param 	url 	链接地址
 *	@param 	site 	分享的来源网站名称，请填写网站申请接入时注册的网站名称。
 *	@param 	fromUrl 	分享的来源网站对应的网站地址url
 *	@param 	comment 	评论内容
 *	@param 	summary 	分享分享内容概述
 *	@param 	image 	分享图片
 *	@param 	type 	内容类型，4表示网页；5表示视频
 *	@param 	playUrl 	视频的swf播放地址，在type为5时必须填写
 *	@param 	nswb 	是否同步到微博，等于1表示不同步，非1表示同步
 */
///#end
///#begin en
/**
 *	@brief	add QZone content unit， When custom QZone share content use this method，If the parameter is set to INHERIT_VALUE. will using the parent parameter value.
 *
 *	@param 	title 	Title string
 *	@param 	url 	URL string
 *	@param 	site 	Shared Source website name.Please fill in the website domain name when applying for registration.
 *	@param 	fromUrl 	Shared source site corresponding website url.
 *	@param 	comment 	Comment content string.
 *	@param 	summary 	Share content summary
 *	@param 	image 	Image attachment object
 *	@param 	type 	Content type:，4 indicate web page；5 indicate video
 *	@param 	playUrl 	SWF play url.，In the type of 5 must be filled
 *	@param 	nswb 	Synchronized to Tencent Weibo, equal to 1 are not synchronized, non-1 represents a synchronization
 */
///#end
- (void)addQQSpaceUnitWithTitle:(NSString *)title
                            url:(NSString *)url
                           site:(NSString *)site
                        fromUrl:(NSString *)fromUrl
                        comment:(NSString *)comment
                        summary:(NSString *)summary
                          image:(id<ISSCAttachment>)image
                           type:(NSNumber *)type
                        playUrl:(NSString *)playUrl
                           nswb:(NSNumber *)nswb;

///#begin zh-cn
/**
 *	@brief	添加有道云笔记内容单元。
 *
 *	@param 	content 	内容
 *	@param 	title 	标题
 *	@param 	author 	作者
 *	@param 	source 	来源
 *	@param 	attachments 	附件列表
 */
///#end
///#begin en
/**
 *	@brief	Add YouDaoNote content unit.
 *
 *	@param 	content 	Content string
 *	@param 	title   Title string
 *	@param 	author 	Author
 *	@param 	source 	Source
 *	@param 	attachments 	Attachments array
 */
///#end
- (void)addYouDaoNoteUnitWithContent:(NSString *)content
                               title:(NSString *)title
                              author:(NSString *)author
                              source:(NSString *)source
                         attachments:(NSArray *)attachments;

///#begin zh-cn
/**
 *	@brief	添加Instapaper分享内容
 *
 *	@param 	url 	URL路径
 *	@param 	title 	标题，无标题时传入nil
 *	@param 	description 	描述，无描述时传入nil
 */
///#end
///#begin en
/**
 *	@brief	Add Instapaper content unit
 *
 *	@param 	url 	URL string
 *	@param 	title 	Title string，passing nil when there is no title
 *	@param 	description 	Description, passing nil when there is no description
 */
///#end
- (void)addInstapaperContentWithUrl:(NSString *)url
                              title:(NSString *)title
                        description:(NSString *)description;

///#begin zh-cn
/**
 *	@brief	添加邮件内容单元，制定邮件分享时的内容使用此参数，如果参数设置为INHERIT_VALUE则默认使用父级类型相关参数
 *
 *  @since  ver1.2.4
 *
 *	@param 	subject 	邮件主题
 *	@param 	content 	邮件内容
 *	@param 	isHTML      邮件内容格式：YES：HTML格式。NO：普通文本格式
 *  @param  attachments     附件列表
 *  @param  to      收件人邮箱地址列表
 *  @param  cc      抄送邮箱地址列表
 *  @param  bcc     密送邮箱地址列表
 */
///#end
///#begin en
/**
 *	@brief	Add Mail content unit，When custom Mail share content use this method，If the parameter is set to INHERIT_VALUE. will using the parent parameter value.
 *
 *  @since  ver1.2.4
 *
 *	@param 	subject 	Subject string
 *	@param 	content 	Content string
 *	@param 	isHTML      Content format:YES indicate body is HTML format。NO indicate body is Normal text
 *  @param  attachments     Attachments Array
 *  @param  to      Recipient e-mail address list
 *  @param  cc      Cc-mail address list
 *  @param  bcc     Bcc e-mail address list
 */
///#end
- (void)addMailUnitWithSubject:(NSString *)subject
                       content:(NSString *)content
                        isHTML:(NSNumber *)isHTML
                   attachments:(NSArray *)attachments
                            to:(NSArray *)to
                            cc:(NSArray *)cc
                           bcc:(NSArray *)bcc;

///#begin zh-cn
/**
 *	@brief	添加人人网
 *
 *	@param 	name 	标题 注意：最多30个字符
 *	@param 	description 	主体内容 注意：最多200个字符。
 *	@param 	url 	指向的链接
 *	@param 	message 	用户输入的自定义内容。注意：最多200个字符。
 *	@param 	image 	分享图片对象
 *	@param 	captions 	副标题 注意：最多20个字符
 */
///#end
///#begin en
/**
 *	@brief	Add Renren content unit
 *
 *	@param 	name 	Title. Note: Up to 30 characters.
 *	@param 	description 	Body content. Note: Up to 200 characters.
 *	@param 	url 	Link
 *	@param 	message 	User input custom content. Note: Up to 200 characters.
 *	@param 	image 	Image attachment object
 *	@param 	captions 	Subtitle. Note: Up to 20 characters
 */
///#end
- (void)addRenRenUnitWithName:(NSString *)name
                  description:(NSString *)description
                          url:(NSString *)url
                      message:(NSString *)message
                        image:(id<ISSCAttachment>)image
                      caption:(NSString *)captions;

///#begin zh-cn
/**
 *	@brief	添加Pocket内容单元
 *
 *  @since  ver2.2.0
 *
 *	@param 	url 	链接
 *	@param 	title 	标题，如果链接内容无标题时使用
 *	@param 	tags 	带逗号分隔的标签列表
 *	@param 	tweetId 	推文ID
 */
///#end
///#begin en
/**
 *	@brief	Add Pocket content unit.
 *
 *  @since  ver2.2.0
 *
 *	@param 	url 	Share link.
 *	@param 	title 	Title, if the linked content Untitled used.
 *	@param 	tags 	With a comma-separated list of tags
 *	@param 	tweetId 	Tweet ID
 */
///#end
- (void)addPocketUnitWithUrl:(NSString *)url
                       title:(NSString *)title
                        tags:(NSString *)tags
                     tweetId:(NSString *)tweetId;

///#begin zh-cn
/**
 *	@brief	添加印象笔记内容单元
 *
 *	@param 	content 	内容
 *	@param 	title 	标题
 *	@param 	resources 	图片资源列表，元素为ISSAttachment协议对象。如果设置为INHERIT_VALUE则继承父级内容的image。
 */
///#end
///#begin en
/**
 *	@brief	Add EverNote content unit
 *
 *	@param 	content 	Content string
 *	@param 	title 	Title string
 *	@param 	resources 	Image resource list，Element is ISSAttachment protocol object。If the parameter is set to INHERIT_VALUE. will using the parent's image parameter value.
 */
///#end
- (void)addEvernoteUnitWithContent:(NSString *)content
                             title:(NSString *)title
                         resources:(NSArray *)resources;

///#begin zh-cn
/**
 *	@brief	添加印象笔记内容单元
 *
 *  @since  ver2.9.0
 *
 *	@param 	content 	内容
 *	@param 	title 	标题
 *	@param 	resources 	图片资源列表，元素为ISSAttachment协议对象。如果设置为INHERIT_VALUE则继承父级内容的image。
 *  @param  notebookGuid    笔记本ID
 *  @param  tagsGuid    标签ID列表
 */
///#end
///#begin en
/**
 *	@brief	Add EverNote content unit
 *
 *  @since  ver2.9.0
 *
 *	@param 	content 	Content string
 *	@param 	title 	Title string
 *	@param 	resources 	Image resource list，Element is ISSAttachment protocol object。If the parameter is set to INHERIT_VALUE. will using the parent's image parameter value.
 *  @param  notebookGuid    Notebook guid
 *  @param  tagsGuid        Tag guid list.
 */
///#end
- (void)addEvernoteUnitWithContent:(NSString *)content
                             title:(NSString *)title
                         resources:(NSArray *)resources
                      notebookGuid:(NSString *)notebookGuid
                          tagsGuid:(NSArray *)tagsGuid;

///#begin zh-cn
/**
 *	@brief	添加新浪微博内容单元
 *
 *  @since  ver2.2.0
 *
 *	@param 	content 	内容
 *	@param 	image 	图片
 */
///#end
///#begin en
/**
 *	@brief	Add Sina Weibo content unit.
 *
 *  @since  ver2.2.0
 *
 *	@param 	content 	Content string.
 *	@param 	image 	Image attachment object.
 */
///#end
- (void)addSinaWeiboUnitWithContent:(NSString *)content
                              image:(id<ISSCAttachment>)image;

///#begin zh-cn
/**
 *	@brief	添加新浪微博内容单元
 *
 *  @since  ver2.4.1
 *
 *	@param 	content 	内容
 *	@param 	image 	图片
 *  @param  locationCoordinate 	地理位置
 */
///#end
///#begin en
/**
 *	@brief	Add Sina Weibo content unit
 *
 *  @since  ver2.4.1
 *
 *	@param 	content 	Content string.
 *	@param 	image 	Image attachment object.
 *  @param  locationCoordinate 	Location info.
 */
///#end
- (void)addSinaWeiboUnitWithContent:(NSString *)content
                              image:(id<ISSCAttachment>)image
                          locationCoordinate:(SSCLocationCoordinate2D *)locationCoordinate;

///#begin zh-cn
/**
 *	@brief	添加腾讯微博内容单元
 *
 *  @since  ver2.2.0
 *
 *	@param 	content 	内容
 *	@param 	image 	图片
 */
///#end
///#begin en
/**
 *	@brief	Add Tencent Weibo content unit
 *
 *  @since  ver2.2.0
 *
 *	@param 	content 	Content string.
 *	@param 	image 	Image attachment object.
 */
///#end
- (void)addTencentWeiboUnitWithContent:(NSString *)content
                                 image:(id<ISSCAttachment>)image;

///#begin zh-cn
/**
 *	@brief	添加腾讯微博内容单元
 *
 *  @since  ver2.4.1
 *
 *	@param 	aContent 	内容
 *	@param 	aImage 	图片
 *	@param 	locationCoordinate 	地理位置
 */
///#end
///#begin en
/**
 *	@brief	Add Tencent Weibo content unit
 *
 *  @since  ver2.4.1
 *
 *	@param 	aContent 	Content string
 *	@param 	aImage 	Image attachment object.
 *	@param 	locationCoordinate 	Location info.
 */
///#end
- (void)addTencentWeiboUnitWithContent:(NSString *)content
                                 image:(id<ISSCAttachment>)image
                    locationCoordinate:(SSCLocationCoordinate2D *)locationCoordinate;

///#begin zh-cn
/**
 *	@brief	添加腾讯微博多图内容单元
 *
 *  @since  ver2.10.0
 *
 *	@param 	aContent 	内容
 *	@param 	imageArray 	图片数组，类型是id<ISSCAttachment>类型
 *	@param 	locationCoordinate 	地理位置
 */
///#end
///#begin en
/**
 *	@brief	Add Tencent Weibo content unit
 *
 *  @since  ver2.10.0
 *
 *	@param 	aContent 	Content string
 *	@param 	imageArray 	Image attachment array.
 *	@param 	locationCoordinate 	Location info.
 */
///#end
- (void)addTencentWeiboUnitWithContent:(NSString *)content
                            imageArray:(NSArray *)imageArray
                    locationCoordinate:(SSCLocationCoordinate2D *)locationCoordinate;

///#begin zh-cn
/**
 *	@brief	添加拷贝内容单元
 *
 *  @since  ver2.2.0
 *
 *	@param 	content 	内容
 *	@param 	image 	图片
 */
///#end
///#begin en
/**
 *	@brief	Add Copy content unit
 *
 *  @since  ver2.2.0
 *
 *	@param 	content 	Content string.
 *	@param 	image 	Image attachment object.
 */
///#end
- (void)addCopyUnitWithContent:(NSString *)content
                         image:(id<ISSCAttachment>)image;

///#begin zh-cn
/**
 *	@brief	添加打印内容单元
 *
 *  @since  ver2.2.0
 *
 *	@param 	content 	内容
 *	@param 	image 	图片
 */
///#end
///#begin en
/**
 *	@brief	Add Print content unit
 *
 *  @since  ver2.2.0
 *
 *	@param 	content 	Content string.
 *	@param 	image 	Image attachment object.
 */
///#end
- (void)addAirPrintWithContent:(NSString *)content
                         image:(id<ISSCAttachment>)image;

///#begin zh-cn
/**
 *	@brief	添加豆瓣内容单元
 *
 *  @since  ver2.2.0
 *
 *	@param 	content 	内容
 *	@param 	image 	图片
 */
///#end
///#begin en
/**
 *	@brief	Add Douban content unit
 *
 *  @since  ver2.2.0
 *
 *	@param 	content 	Content string.
 *	@param 	image   Image attachment object.
 */
///#end
- (void)addDouBanWithContent:(NSString *)content
                       image:(id<ISSCAttachment>)image;

///#begin zh-cn
/**
 *	@brief	添加Facebook内容单元
 *
 *  @since  ver2.2.0
 *
 *	@param 	content 	内容
 *	@param 	image 	图片
 */
///#end
///#begin en
/**
 *	@brief	Add Facebook content unit
 *
 *  @since  ver2.2.0
 *
 *	@param 	content 	Content string
 *	@param 	image 	Image attachment object.
 */
///#end
- (void)addFacebookWithContent:(NSString *)content
                         image:(id<ISSCAttachment>)image;

///#begin zh-cn
/**
 *	@brief	添加Twitter内容单元
 *
 *  @since  ver2.2.0
 *
 *	@param 	content 	内容
 *	@param 	image 	图片
 */
///#end
///#begin en
/**
 *	@brief	Add Twitter content unit
 *
 *  @since  ver2.2.0
 *
 *	@param 	content 	Content string.
 *	@param 	image 	Image attachment object.
 */
///#end
- (void)addTwitterWithContent:(NSString *)content
                        image:(id<ISSCAttachment>)image;

///#begin zh-cn
/**
 *	@brief	添加Twitter内容单元
 *
 *  @since  ver2.4.1
 *
 *	@param 	content 	内容
 *	@param 	image 	图片
 *	@param 	locationCoordinate 	地理位置
 */
///#end
///#begin en
/**
 *	@brief	Add Twitter content unit
 *
 *  @since  ver2.4.1
 *
 *	@param 	content 	Content string.
 *	@param 	image 	Image attachment object.
 *	@param 	locationCoordinate 	Location info.
 */
///#end
- (void)addTwitterWithContent:(NSString *)content
                        image:(id<ISSCAttachment>)image
           locationCoordinate:(SSCLocationCoordinate2D *)locationCoordinate;


///#begin zh-cn
/**
 *	@brief	添加推特多图内容单元
 *
 *  @since  ver2.10.1
 *
 *	@param 	aContent 	内容
 *	@param 	imageArray 	图片数组，类型是id<ISSCAttachment>类型
 *	@param 	locationCoordinate 	地理位置
 */
///#end
///#begin en
/**
 *	@brief	Add twitter content unit
 *
 *  @since  ver2.10.1
 *
 *	@param 	aContent 	Content string
 *	@param 	imageArray 	Image attachment array.
 *	@param 	locationCoordinate 	Location info.
 */
///#end
- (void)addTwitterUnitWithContent:(NSString *)content
                       imageArray:(NSArray *)imageArray
               locationCoordinate:(SSCLocationCoordinate2D *)locationCoordinate;


///#begin zh-cn
/**
 *	@brief	添加开心网内容单元
 *
 *  @since  ver2.2.0
 *
 *	@param 	content 	内容
 *	@param 	image 	图片
 */
///#end
///#begin en
/**
 *	@brief	Add KaiXin content unit
 *
 *  @since  ver2.2.0
 *
 *	@param 	content 	Content string.
 *	@param 	image 	Image attachment object.
 */
///#end
- (void)addKaiXinUnitWithContent:(NSString *)content
                           image:(id<ISSCAttachment>)image;

///#begin zh-cn
/**
 *	@brief	添加LinkedIn内容单元
 *
 *  @since  ver2.4.0
 *
 *	@param 	comment 	对分享内容的评论
 *	@param 	title 	标题
 *	@param 	description 	内容描述
 *	@param 	url 	内容链接地址
 *	@param 	image   内容相关图片（只允许分享网络图片）
 *	@param 	visibility  可见，默认为anyone
 */
///#end
///#begin en
/**
 *	@brief	Add LinkedIn content unit
 *
 *  @since  ver2.4.0
 *
 *	@param 	comment 	Comments for sharing content
 *	@param 	title 	Title string
 *	@param 	description 	Content description
 *	@param 	url 	Url string
 *	@param 	image   Image attachment object（Pictures only allows sharing network）
 *	@param 	visibility  Visible, the default is anyone
 */
///#end
- (void)addLinkedInUnitWithComment:(NSString *)comment
                             title:(NSString *)title
                       description:(NSString *)description
                               url:(NSString *)url
                             image:(id<ISSCAttachment>)image
                        visibility:(NSString *)visibility;
///#begin zh-cn
/**
 *	@brief	添加Google+内容单元
 *
 *  @since  ver2.4.0
 *
 *	@param 	text 	分享内容
 *  @param  image   分享图片，如果设置此参数，则跟链接相关参数将无效（包括：url、deepLinkId、title、description、thumbnail）。
 *	@param 	url 	链接
 *	@param 	deepLinkId 	深链接ID
 *	@param 	title 	深链接标题
 *	@param 	description 	深链接描述
 *	@param 	thumbnail   缩略图
 */
///#end
///#begin en
/**
 *	@brief	Add Google+ content unit
 *
 *  @since  ver2.4.0
 *
 *	@param 	text 	Content string.
 *  @param  image   Share pictures, if you set this parameter, with links to related parameters will be invalid（contains：url、deepLinkId、title、description、thumbnail）。
 *	@param 	url 	Url string
 *	@param 	deepLinkId 	Deep link
 *	@param 	title 	Deep link title string
 *	@param 	description 	Deep link description
 *	@param 	thumbnail   Thumbnails
 */
///#end
- (void)addGooglePlusUnitWithText:(NSString *)text
                            image:(id<ISSCAttachment>)image
                              url:(NSString *)url
                       deepLinkId:(NSString *)deepLinkId
                            title:(NSString *)title
                      description:(NSString *)description
                        thumbnail:(NSString *)thumbnail;
///#begin zh-cn
/**
 *	@brief	添加Pinterest内容单元
 *
 *  @since  ver2.4.1
 *
 *	@param 	image 	图片
 *	@param 	url 	链接
 *	@param 	description 	描述
 */
///#end
///#begin en
/**
 *	@brief	Add Pinterest content unit
 *
 *  @since  ver2.4.1
 *
 *	@param 	image 	Image attachment object.
 *	@param 	url 	Url string.
 *	@param 	description 	Description.
 */
///#end
- (void)addPinterestUnitWithImage:(id<ISSCAttachment>)image
                              url:(NSString *)url
                      description:(NSString *)description;

///#begin zh-cn
/**
 *	@brief	添加Flickr内容单元
 *
 *	@param 	photo 	图片对象
 *	@param 	title 	标题
 *	@param 	description 	相片描述。可能包含某受限的 HTML。
 *	@param 	tags 	適用於相片的以空格分隔的標籤清單。
 *	@param 	isPublic 	設定為 0 表示否，1 表示是。指定誰可以檢視相片。
 *	@param 	isFriend 	設定為 0 表示否，1 表示是。指定誰可以檢視相片。
 *	@param 	isFamily 	設定為 0 表示否，1 表示是。指定誰可以檢視相片。
 *	@param 	safetyLevel 	設置 1 為「安全級」、2 為「輔導級」、3 為「限制級」。
 *	@param 	contentType 	設置 1 為「相片」、2 為「螢幕截圖」、3 為「其他」。
 *	@param 	hidden 	設置 1 為「相片」、2 為「螢幕截圖」、3 為「其他」。
 */
///#end
///#begin en
/**
 *	@brief	Add Flickr content unit
 *
 *	@param 	photo 	Image attachment object.
 *	@param 	title 	Title string.
 *	@param 	description 	Image description。HTML may contain a limited。
 *	@param 	tags 	Suitable for space-separated list of labels photo.
 *	@param 	isPublic 	Set to 0 for no, 1 indicate yes. Specify who can view photos.
 *	@param 	isFriend 	Set to 0 for no, 1 indicate yes. Specify who can view photos.
 *	@param 	isFamily 	Set to 0 for no, 1 indicate yes. Specify who can view photos.
 *	@param 	safetyLevel 	Set to 1 is "safe level", 2 is "PG", 3 is "X-rated."
 *	@param 	contentType 	Set to 1 is the "Photo", 2 is "screen shots", 3 is "Other."
 *	@param 	hidden 	Set to 1 is the "Photo", 2 is "screen shots", 3 is "Other."
 */
///#end
- (void)addFlickrUnitWithPhoto:(id<ISSCAttachment>)photo
                         title:(NSString *)title
                   description:(NSString *)description
                          tags:(NSString *)tags
                      isPublic:(NSNumber *)isPublic
                      isFriend:(NSNumber *)isFriend
                      isFamily:(NSNumber *)isFamily
                   safetyLevel:(NSNumber *)safetyLevel
                   contentType:(NSNumber *)contentType
                        hidden:(NSNumber *)hidden;

///#begin zh-cn
/**
 *	@brief	添加Tumblr内容单元
 *
 *	@param 	text 	内容，可以带有HTML标签
 *	@param 	title 	标题
 *	@param 	image 	图片
 *	@param 	url 	点击后跳转的链接
 *	@param 	blogName 	博客名称，为nil时表示发去主博客
 */
///#end
///#begin en
/**
 *	@brief	Add Tumblr content unit
 *
 *	@param 	text 	Content string, Can with HTML tags.
 *	@param 	title 	Title string.
 *	@param 	image 	Image attachment object
 *	@param 	url 	Jump Links
 *	@param 	blogName 	Blog name, or nil when sent to the main blog
 */
///#end
- (void)addTumblrUnitWithText:(NSString *)text
                        title:(NSString *)title
                        image:(id<ISSCAttachment>)image
                          url:(NSString *)url
                     blogName:(NSString *)blogName;

///#begin zh-cn
/**
 *	@brief	添加Dropbox内容单元
 *
 *	@param 	file 	文件
 */
///#end
///#begin en
/**
 *	@brief	Add Dropbox content unit.
 *
 *	@param 	file 	File attachment object.
 */
///#end
- (void)addDropboxUnitWithFile:(id<ISSCAttachment>)file;

///#begin zh-cn
/**
 *	@brief	添加VKontakte内容单元
 *
 *	@param 	message 	消息
 *	@param 	attachments 	附件列表
 *	@param 	url 	链接地址
 *	@param 	groupId 	分组标识
 *	@param 	friendsOnly 	是否仅允许好友查看
 *	@param 	locationCoordinate 	地理位置信息
 */
///#end
///#begin en
/**
 *	@brief	Add VKontakte content unit
 *
 *	@param 	message 	Message string.
 *	@param 	attachments 	Attachment list
 *	@param 	url 	Url string.
 *	@param 	groupId 	Group Id
 *	@param 	friendsOnly 	Whether to allow only friends to view
 *	@param 	locationCoordinate 	Location info
 */
///#end
- (void)addVKontakteUnitWithMessage:(NSString *)message
                        attachments:(NSArray *)attachments
                                url:(NSString *)url
                            groupId:(NSString *)groupId
                        friendsOnly:(NSNumber *)friendsOnly
                 locationCoordinate:(SSCLocationCoordinate2D *)locationCoordinate;

///#begin zh-cn
/**
 *	@brief	添加Instagram内容单元
 *
 *	@param 	title 	标题
 *	@param 	image 	图片
 */
///#end
///#begin en
/**
 *	@brief	Add Instagram content unit
 *
 *	@param 	title 	Title string
 *	@param 	image 	Image attachment object
 */
///#end
- (void)addInstagramUnitWithTitle:(NSString *)title
                            image:(id<ISSCAttachment>)image;

///#begin zh-cn
/**
 *	@brief	添加易信好友内容单元，制定微信分享时的内容使用此参数，如果参数设置为INHERIT_VALUE则默认使用父级类型相关参数
 *
 *  @since ver2.7.0
 *
 *	@param 	type 	分享类型,请参考SSPublishContentMediaType
 *	@param 	content 	分享内容
 *	@param 	title 	标题
 *	@param 	url 	URL地址
 *  @param  thumbImage  缩略图
 *	@param 	image 	分享图片
 *  @param  musicFileUrl    音乐文件路径
 *  @param  extInfo     扩展信息
 *  @param  fileData    文件数据
 */
///#end
///#begin en
/**
 *	@brief	Add YiXin session content unit，When custom YiXin session share content use this method，If the parameter is set to INHERIT_VALUE. will using the parent parameter value.
 *
 *  @since ver2.7.0
 *
 *	@param 	type 	Media type,Please see SSPublishContentMediaType
 *	@param 	content 	Content string
 *	@param 	title 	Title string
 *	@param 	url 	URL string
 *  @param  thumbImage  Thumbnails
 *	@param 	image 	Image attachment object
 *  @param  musicFileUrl    Music file url string.
 *  @param  extInfo     Extended Information
 *  @param  fileData    File data
 */
///#end
- (void)addYiXinSessionUnitWithType:(NSNumber *)type
                            content:(NSString *)content
                              title:(NSString *)title
                                url:(NSString *)url
                         thumbImage:(id<ISSCAttachment>)thumbImage
                              image:(id<ISSCAttachment>)image
                       musicFileUrl:(NSString *)musicFileUrl
                            extInfo:(NSString *)extInfo
                           fileData:(NSData *)fileData;

///#begin zh-cn
/**
 *	@brief	添加易信朋友圈内容单元，制定微信分享时的内容使用此参数，如果参数设置为INHERIT_VALUE则默认使用父级类型相关参数
 *
 *  @since ver2.7.0
 *
 *	@param 	type 	分享类型,请参考SSPublishContentMediaType
 *	@param 	content 	分享内容
 *	@param 	title 	标题
 *	@param 	url 	URL地址
 *  @param  thumbImage  缩略图
 *	@param 	image 	分享图片
 *  @param  musicFileUrl    音乐文件路径
 *  @param  extInfo     扩展信息
 *  @param  fileData    文件数据
 */
///#end
///#begin en
/**
 *	@brief	Add YiXin timeline content unit，When custom YiXin timeline share content use this method，If the parameter is set to INHERIT_VALUE. will using the parent parameter value.
 *
 *  @since ver2.7.0
 *
 *	@param 	type 	Media type,Please see SSPublishContentMediaType
 *	@param 	content 	Content string
 *	@param 	title 	Title string
 *	@param 	url 	URL string
 *  @param  thumbImage  Thumbnails
 *	@param 	image 	Image attachment object
 *  @param  musicFileUrl    Music file url string.
 *  @param  extInfo     Extended Information
 *  @param  fileData    File data
 */
///#end
- (void)addYiXinTimelineUnitWithType:(NSNumber *)type
                             content:(NSString *)content
                               title:(NSString *)title
                                 url:(NSString *)url
                          thumbImage:(id<ISSCAttachment>)thumbImage
                               image:(id<ISSCAttachment>)image
                        musicFileUrl:(NSString *)musicFileUrl
                             extInfo:(NSString *)extInfo
                            fileData:(NSData *)fileData;

///#begin zh-cn
/**
 *	@brief	添加微信好友内容单元，制定微信分享时的内容使用此参数，如果参数设置为INHERIT_VALUE则默认使用父级类型相关参数
 *
 *  @since  ver2.7.0    增加缩略图参数
 *
 *	@param 	type 	分享类型,请参考SSPublishContentMediaType
 *	@param 	content 	分享内容
 *	@param 	title 	标题
 *	@param 	url 	URL地址
 *  @param  thumbImage  缩略图
 *	@param 	image 	分享图片
 *  @param  musicFileUrl    音乐文件路径
 *  @param  extInfo     扩展信息
 *  @param  fileData    文件数据
 *  @param  emoticonData    表情数据，用于存放Gif和非Gif图片数据
 */
///#end
///#begin en
/**
 *	@brief	Add WeChat session content unit，When custom WeChat session share content use this method，If the parameter is set to INHERIT_VALUE. will using the parent parameter value.
 *
 *  @since  ver2.7.0    增加缩略图参数
 *
 *	@param 	type 	Media type,Please see SSPublishContentMediaType
 *	@param 	content 	Content string
 *	@param 	title 	Title string
 *	@param 	url 	URL string
 *  @param  thumbImage  Thumbnails
 *	@param 	image 	Image attachment object
 *  @param  musicFileUrl    Music file url string.
 *  @param  extInfo     Extended Information
 *  @param  fileData    File data
 *  @param  emoticonData    Emoticon Data，Used to store Gif picture data
 */
///#end
- (void)addWeixinSessionUnitWithType:(NSNumber *)type
                             content:(NSString *)content
                               title:(NSString *)title
                                 url:(NSString *)url
                          thumbImage:(id<ISSCAttachment>)thumbImage
                               image:(id<ISSCAttachment>)image
                        musicFileUrl:(NSString *)musicFileUrl
                             extInfo:(NSString *)extInfo
                            fileData:(NSData *)fileData
                        emoticonData:(NSData *)emoticonData;

///#begin zh-cn
/**
 *	@brief	添加微信朋友圈内容单元，制定微信分享时的内容使用此参数，如果参数设置为INHERIT_VALUE则默认使用父级类型相关参数
 *
 *  @since  ver2.7.0    增加缩略图参数
 *
 *	@param 	type 	分享类型,请参考SSPublishContentMediaType
 *	@param 	content 	分享内容
 *	@param 	title 	标题
 *	@param 	url 	URL地址
 *  @param  thumbImage  缩略图
 *	@param 	image 	分享图片
 *  @param  musicFileUrl    音乐文件路径
 *  @param  extInfo     扩展信息
 *  @param  fileData    文件数据
 *  @param  emoticonData    表情数据，用于存放Gif和非Gif图片数据
 */
///#end
///#begin en
/**
 *	@brief	Add WeChat timeline content unit，When custom WeChat timeline share content use this method，If the parameter is set to INHERIT_VALUE. will using the parent parameter value.
 *
 *  @since  ver2.7.0    增加缩略图参数
 *
 *	@param 	type 	Media type,Please see SSPublishContentMediaType
 *	@param 	content 	Content string
 *	@param 	title 	Title string
 *	@param 	url 	URL string
 *  @param  thumbImage  Thumbnails
 *	@param 	image 	Image attachment object
 *  @param  musicFileUrl    Music file url string.
 *  @param  extInfo     Extended Information
 *  @param  fileData    File data
 *  @param  emoticonData    Emoticon Data，Used to store Gif picture data
 */
///#end
- (void)addWeixinTimelineUnitWithType:(NSNumber *)type
                              content:(NSString *)content
                                title:(NSString *)title
                                  url:(NSString *)url
                           thumbImage:(id<ISSCAttachment>)thumbImage
                                image:(id<ISSCAttachment>)image
                         musicFileUrl:(NSString *)musicFileUrl
                              extInfo:(NSString *)extInfo
                             fileData:(NSData *)fileData
                         emoticonData:(NSData *)emoticonData;

///#begin zh-cn
/**
 *	@brief	添加微信收藏内容单元，制定微信分享时的内容使用此参数，如果参数设置为INHERIT_VALUE则默认使用父级类型相关参数
 *
 *	@param 	type 	分享类型,请参考SSPublishContentMediaType
 *	@param 	content 	分享内容
 *	@param 	title 	标题
 *	@param 	url 	URL地址
 *  @param  thumbImage  缩略图
 *	@param 	image 	分享图片
 *  @param  musicFileUrl    音乐文件路径
 *  @param  extInfo     扩展信息
 *  @param  fileData    文件数据
 *  @param  emoticonData    表情数据，用于存放Gif和非Gif图片数据
 */
///#end
///#begin en
/**
 *	@brief	Add WeChat Favorite content unit，When custom WeChat Favorite share content use this method，If the parameter is set to INHERIT_VALUE. will using the parent parameter value.
 *
 *	@param 	type 	Media type,Please see SSPublishContentMediaType
 *	@param 	content 	Content string
 *	@param 	title 	Title string
 *	@param 	url 	URL string
 *  @param  thumbImage  Thumbnails
 *	@param 	image 	Image attachment object
 *  @param  musicFileUrl    Music file url string.
 *  @param  extInfo     Extended Information
 *  @param  fileData    File data
 *  @param  emoticonData    Emoticon Data，Used to store Gif picture data
 */
///#end
- (void)addWeixinFavUnitWithType:(NSNumber *)type
                         content:(NSString *)content
                           title:(NSString *)title
                             url:(NSString *)url
                      thumbImage:(id<ISSCAttachment>)thumbImage
                           image:(id<ISSCAttachment>)image
                    musicFileUrl:(NSString *)musicFileUrl
                         extInfo:(NSString *)extInfo
                        fileData:(NSData *)fileData
                    emoticonData:(NSData *)emoticonData;

///#begin zh-cn
/**
 *	@brief	添加明道内容单元。定制明道分享时地内容使用此方法。如果参数设置为INHERIT_VALUE则默认使用父级类型相关参数
 *
 *	@param 	content 	内容
 *	@param 	image 	图片
 *	@param 	title 	标题
 *	@param 	url 	链接
 */
///#end
///#begin en
/**
 *	@brief	Add MingDao content unit，When custom MingDao share content use this method，If the parameter is set to INHERIT_VALUE. will using the parent parameter value.
 *
 *	@param 	content 	Content string
 *	@param 	image 	Image attachment object
 *	@param 	title 	Title string.
 *	@param 	url 	URL string.
 */
///#end
- (void)addMingDaoUnitWithContent:(NSString *)content
                            image:(id<ISSCAttachment>)image
                            title:(NSString *)title
                              url:(NSString *)url;
///#begin zh-cn
/**
 *	@brief	添加Line内容单元。定制Line分享时内容使用此方法。如果参数设置为INHERIT_VALUE则默认使用父级类型相关参数
 *
 *	@param 	content 	内容
 *	@param 	image 	图片
 */
///#end
///#begin en
/**
 *	@brief	Add Line content unit，When custom Line share content use this method，If the parameter is set to INHERIT_VALUE. will using the parent parameter value.
 *
 *	@param 	content 	Content string.
 *	@param 	image 	Image attachment object.
 */
///#end
- (void)addLineUnitWithContent:(NSString *)content
                         image:(id<ISSCAttachment>)image;

///#begin zh-cn
/**
 *	@brief  添加WhatsApp内容单元。定制WhatsApp分享时内容使用此方法。如果参数设置为INHERIT_VALUE则默认使用父级类型相关参数
 *
 *	@param 	content 	内容
 *	@param 	image 	图片
 *	@param 	music 	音乐
 *	@param 	video 	视频
 *
 */
///#end
///#begin en
/**
 *	@brief  Add WhatsApp content unit，When custom WhatsApp share content use this method，If the parameter is set to INHERIT_VALUE. will using the parent parameter value.
 *
 *	@param 	content 	content string
 *	@param 	image 	image attachment
 *	@param 	music 	music attachment
 *	@param 	video   video attachment
 *
 */
///#end
- (void)addWhatsAppUnitWithContent:(NSString *)content
                             image:(id<ISSCAttachment>)image
                             music:(id<ISSCAttachment>)music
                             video:(id<ISSCAttachment>)video;


///#begin zh-cn
/**
 *  添加KaKaoTalk内容单元。定制KaKaoTalk分享时内容使用此方法。如果参数设置为INHERIT_VALUE则默认使用父级类型相关参数
 *
 *  @param type               分享内容类型，支持SSPublishContentMediaTypeText,SSPublishContentMediaTypeNews,SSPublishContentMediaTypeApp
 *  @param content            分享内容
 *  @param title              标题
 *  @param url                链接地址
 *  @param appName            应用名
 *  @param appVersion         应用版本
 *  @param appBundleId        应用的Bundle ID
 *  @param iosDownloadUrl     iOS的应用下载地址
 *  @param androidDownloadUrl Android的应用下载地址
 *  @param executeUrl         运行应用的URL
 */
///#end
///#begin en
/**
 *  Add KaKaoTalk content unit，When custom KaKaoTalk share content use this method，If the parameter is set to INHERIT_VALUE. will using the parent parameter value.
 *
 *  @param type               Share type，Only support SSPublishContentMediaTypeText,SSPublishContentMediaTypeNews,SSPublishContentMediaTypeApp
 *  @param content            Content string
 *  @param title              Title
 *  @param url                URL string
 *  @param appName            Application name
 *  @param appVersion         Application version
 *  @param appBundleId        Bundle ID of Application
 *  @param iosDownloadUrl     Application download URL for iOS
 *  @param androidDownloadUrl Application download URL for Android
 *  @param executeUrl         Execute URL
 */
///#end
- (void)addKaKaoTalkUnitWithType:(NSNumber *)type
                         content:(NSString *)content
                           title:(NSString *)title
                             url:(NSString *)url
                         appName:(NSString *)appName
                      appVersion:(NSString *)appVersion
                     appBundleId:(NSString *)appBundleId
                  iosDownloadUrl:(NSString *)iosDownloadUrl
              androidDownloadUrl:(NSString *)androidDownloadUrl
                      executeUrl:(NSString *)executeUrl;

///#begin zh-cn
/**
 *  添加KaKaoStory内容单元。定制KaKaoStory分享时内容使用此方法。如果参数设置为INHERIT_VALUE则默认使用父级类型相关参数
 *
 *  @param type        分享内容类型，支持SSPublishContentMediaTypeText,SSPublishContentMediaTypeNews,SSPublishContentMediaTypeMusic,SSPublishContentMediaTypeVideo
 *  @param content     分享内容
 *  @param title       标题
 *  @param fileUrl     文件地址
 *  @param description 描述
 *  @param image       配图
 *  @param appName     应用名
 *  @param appVersion  应用版本
 *  @param appBundleId appBundleID
 */
///#end
///#begin en
/**
 *  Add KaKaoStory content unit，When custom KaKaoStory share content use this method，If the parameter is set to INHERIT_VALUE. will using the parent parameter value.
 *
 *  @param type        Share type，Only Support SSPublishContentMediaTypeText,SSPublishContentMediaTypeNews,SSPublishContentMediaTypeMusic,SSPublishContentMediaTypeVideo
 *  @param content     Content string
 *  @param title       Title
 *  @param fileUrl     File's URL
 *  @param description Description string
 *  @param image       Image object
 *  @param appName     Application name
 *  @param appVersion  Application version
 *  @param appBundleId Bundle ID of Application
 */
///#end
- (void)addKaKaoStoryUnitWithType:(NSNumber *)type
                          content:(NSString *)content
                            title:(NSString *)title
                          fileUrl:(NSString *)fileUrl
                      description:(NSString *)description
                            image:(id<ISSCAttachment>)image
                          appName:(NSString *)appName
                       appVersion:(NSString *)appVersion
                      appBundleId:(NSString *)appBundleId;



@end
