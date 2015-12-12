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
#import "SSHTTPParameters.h"

///#begin zh-cn
/**
 *	@brief	HTTP返回事件
 */
///#end
///#begin en
/**
 *	@brief	HTTP result event.
 */
///#end
typedef void(^SSHTTPResultEvent) (NSHTTPURLResponse *response, NSData *responseData);

///#begin zh-cn
/**
 *	@brief	HTTP错误事件
 */
///#end
///#begin en
/**
 *	@brief	HTTP fault event.
 */
///#end
typedef void(^SSHTTPFaultEvent) (NSError *error);

///#begin zh-cn
/**
 *	@brief	HTTP客户端
 */
///#end
///#begin en
/**
 *	@brief	HTTP Client
 */
///#end
@interface SSHTTPClient : NSObject

///#begin zh-cn
/**
 *	@brief	初始化HTTP客户端对象
 *
 *	@param 	url 	请求地址
 *
 *	@return	客户端对象
 */
///#end
///#begin en
/**
 *	@brief	Initialize HTTP Client.
 *
 *	@param 	url 	Request URL object.
 *
 *	@return	HTTP Client object.
 */
///#end
- (id)initWithURL:(NSURL *)url;

///#begin zh-cn
/**
 *	@brief	初始化HTTP客户端对象
 *
 *	@param 	urlString 	请求地址字符串
 *
 *	@return	客户端对象
 */
///#end
///#begin en
/**
 *	@brief	Initialize HTTP Client.
 *
 *	@param 	urlString 	Request URL string.
 *
 *	@return	HTTP Client object.
 */
///#end
- (id)initWithURLString:(NSString *)urlString;

///#begin zh-cn
/**
 *	@brief	初始化HTTP客户端对象
 *
 *	@param 	request 	请求对象
 *
 *	@return	客户端对象
 */
///#end
///#begin en
/**
 *	@brief	Initialize HTTP Client.
 *
 *	@param 	request 	Request object.
 *
 *	@return	HTTP client object.
 */
///#end
- (id)initWithRequest:(NSMutableURLRequest *)request;

///#begin zh-cn
/**
 *	@brief	开始请求
 *
 *  @param  resultHandler   返回事件处理
 *  @param  faultHandler    失败事件处理
 */
///#end
///#begin en
/**
 *	@brief	Start request.
 *
 *  @param  resultHandler   Result handler.
 *  @param  faultHandler    Fault handler.
 */
///#end
- (void)startWithResult:(SSHTTPResultEvent)resultHandler
                  fault:(SSHTTPFaultEvent)faultHandler;

///#begin zh-cn
/**
 *	@brief	取消请求
 */
///#end
///#begin en
/**
 *	@brief	Cancel request.
 */
///#end
- (void)cancelRequest;

///#begin zh-cn
/**
 *	@brief	设置请求方式
 *
 *	@param 	method 	请求方式
 */
///#end
///#begin en
/**
 *	@brief	Set request method.
 *
 *	@param 	method 	Request method.
 */
///#end
- (void)setMethod:(NSString *)method;

///#begin zh-cn
/**
 *	@brief	启用Multipart形式提交
 *
 *	@return	分隔字符串
 */
///#end
///#begin en
/**
 *	@brief	Enable Multipart forms submitted
 *
 *	@return	Boundary string.
 */
///#end
- (NSString *)enableMultipart;

///#begin zh-cn
/**
 *	@brief	添加参数
 *
 *	@param 	name 	参数名称
 *	@param 	value 	参数值
 */
///#end
///#begin en
/**
 *	@brief	Add parameter.
 *
 *	@param 	name 	Parameter name.
 *	@param 	value 	Parameter value.
 */
///#end
- (void)addParameterWithName:(NSString *)name value:(id)value;

///#begin zh-cn
/**
 *	@brief	添加文件参数
 *
 *	@param 	name 	参数名称
 *	@param 	fileName 	文件名称
 *	@param 	data 	文件数据
 *	@param 	contentType 	MIME类型
 *	@param 	transferEncoding 	传输编码
 */
///#end
///#begin en
/**
 *	@brief	Add file parameter.
 *
 *	@param 	name 	Parameter name.
 *	@param 	fileName 	File name.
 *	@param 	data 	File data.
 *	@param 	contentType 	MIME Type.
 *	@param 	transferEncoding 	Transfer Encoding.
 */
///#end
- (void)addPostedFileWithName:(NSString *)name
                     fileName:(NSString *)fileName
                         data:(NSData *)data
                  contentType:(NSString *)contentType
             transferEncoding:(NSString *)transferEncoding;

///#begin zh-cn
/**
 *	@brief	获取回复数据字符串
 *
 *	@param 	encoding 	编码
 *
 *	@return	数据字符串
 */
///#end
///#begin en
/**
 *	@brief	Get response string.
 *
 *	@param 	encoding 	Encoding.
 *
 *	@return	Response string.
 */
///#end
- (NSString *)responseString:(NSStringEncoding)encoding;

@end
