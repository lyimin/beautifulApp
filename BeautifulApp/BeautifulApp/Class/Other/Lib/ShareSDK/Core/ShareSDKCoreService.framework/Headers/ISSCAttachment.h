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
//  Website:http://www.ShareSDK.cn
//  Support E-mail:support@sharesdk.cn
//  WeChat ID:ShareSDK   （If publish a new version, we will be push the updates content of version to you. If you have any questions about the ShareSDK, you can get in touch through the WeChat with us, we will respond within 24 hours）
//  Business QQ:4006852216
//  Copyright (c) 2013年 ShareSDK.cn. All rights reserved.
//
///#end

#import <Foundation/Foundation.h>

///#begin zh-cn
/**
 *	@brief	附件协议
 */
///#end
///#begin en
/**
 *	@brief	Attachment protocol.
 */
///#end
@protocol ISSCAttachment <NSObject>

///#begin zh-cn
/**
 *	@brief	获取文件路径
 *
 *	@return	文件路径
 */
///#end
///#begin en
/**
 *	@brief	Get file path.
 *
 *	@return	Path.
 */
///#end
- (NSString *)path;

///#begin zh-cn
/**
 *	@brief	获取远程文件路径
 *
 *	@return	URL地址
 */
///#end
///#begin en
/**
 *	@brief	Get URL address.
 *
 *	@return	URL address.
 */
///#end
- (NSString *)url;

///#begin zh-cn
/**
 *	@brief	获取附件数据
 *
 *	@return	附件数据
 */
///#end
///#begin en
/**
 *	@brief	Get attachment data.
 *
 *	@return	Attachment data.
 */
///#end
- (NSData *)data;

///#begin zh-cn
/**
 *	@brief	获取附件名称
 *
 *	@return	附件名称
 */
///#end
///#begin en
/**
 *	@brief	Get file name.
 *
 *	@return	File name.
 */
///#end
- (NSString *)fileName;

///#begin zh-cn
/**
 *	@brief	获取附件类型
 *
 *	@return	附件类型
 */
///#end
///#begin en
/**
 *	@brief	Get MIME type.
 *
 *	@return	MIME type.
 */
///#end
- (NSString *)mimeType;

///#begin zh-cn
/**
 *	@brief	判断是否为远程文件
 *
 *	@return	YES 表示为远程文件，NO 表示为本地文件
 */
///#end
///#begin en
/**
 *	@brief	Is remote file flag.
 *
 *	@return	YES means of remote files, NO is a local file
 */
///#end
- (BOOL)isRemoteFile;

///#begin zh-cn
/**
 *	@brief	加载附件信息
 *
 *  @param  completeHandler     加载完成事件处理
 *  @param  faultHandler        加载失败事件处理
 */
///#end
///#begin en
/**
 *	@brief	Load attachment data.
 *
 *  @param  completeHandler     Completed handler.
 *  @param  faultHandler        Fault handler.
 */
///#end
- (void)load:(void(^)())completeHandler
faultHandler:(void(^)(NSError *error))faultHandler;

///#begin zh-cn
/**
 *	@brief	加载附件信息, 进行压缩处理(v2.10.3)
 *
 *  @param  completeHandler     加载完成事件处理
 *  @param  faultHandler        加载失败事件处理
 */
///#end
///#begin en
/**
 *	@brief	Load attachment data. zip the file
 *
 *  @param  completeHandler     Completed handler.
 *  @param  faultHandler        Fault handler.
 */
///#end
- (void)loadCustomImages:(void (^)())completeHandler
            faultHandler:(void (^)(NSError *))faultHandler;


@end