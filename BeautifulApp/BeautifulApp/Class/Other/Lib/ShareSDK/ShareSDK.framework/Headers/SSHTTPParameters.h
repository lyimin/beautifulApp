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
 *	@brief	HTTP参数集合
 */
///#end
///#begin en
/**
 *	@brief	HTTP Parameters.
 */
///#end
@interface SSHTTPParameters : NSObject

///#begin zh-cn
/**
 *	@brief	初始化HTTP请求参数列表
 *
 *	@param 	url 	请求的URL对象
 *
 *	@return	请求参数列表对象
 */
///#end
///#begin en
/**
 *	@brief	Initialize HTTP Parameters.
 *
 *	@param 	url 	URL object.
 *
 *	@return	HTTP Parameters object.
 */
///#end
- (id)initWithURL:(NSURL *)url;

///#begin zh-cn
/**
 *	@brief	初始化HTTP请求参数列表
 *
 *	@param 	queryString 	请求的URL参数部分字符串
 *
 *	@return	请求参数列表对象
 */
///#end
///#begin en
/**
 *	@brief	Initialize HTTP parameters.
 *
 *	@param 	queryString 	URL's query part string.
 *
 *	@return	HTTP Paremeters object.
 */
///#end
- (id)initWithQueryString:(NSString *)queryString;

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
 *	@param 	value 	Paremeter value.
 */
///#end
- (void)addParameterWithName:(NSString *)name value:(id)value;

///#begin zh-cn
/**
 *	@brief	添加多个参数
 *
 *	@param 	dictionary 	请求参数字典
 */
///#end
///#begin en
/**
 *	@brief	Adding multiple parameters
 *
 *	@param 	dictionary 	Request parameters dicationary object.
 */
///#end
- (void)addParametersWithDictionary:(NSDictionary *)dictionary;

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
 *	@param 	contentType 	MIME type.
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
 *	@brief	删除参数
 *
 *	@param 	name 	参数名称
 */
///#end
///#begin en
/**
 *	@brief	Remove parameter.
 *
 *	@param 	name 	Parameter name.
 */
///#end
- (void)removeParameterWithName:(NSString *)name;

///#begin zh-cn
/**
 *	@brief	获取参数值
 *
 *	@param 	name 	参数名称
 *
 *	@return	参数值
 */
///#end
///#begin en
/**
 *	@brief	Get parameter value.
 *
 *	@param 	name 	Parameter name.
 *
 *	@return	Parameter value.
 */
///#end
- (id)getValueForName:(NSString *)name;

///#begin zh-cn
/**
 *	@brief	清除所有参数
 */
///#end
///#begin en
/**
 *	@brief	Remove all parameters.
 */
///#end
- (void)clear;

///#begin zh-cn
/**
 *	@brief	获取请求参数的二进制数据
 *
 *	@param 	encoding 	编码
 *
 *	@return	二进制数据对象
 */
///#end
///#begin en
/**
 *	@brief	Get parameters binary data.
 *
 *	@param 	encoding 	Encoding
 *
 *	@return	Binary data object.
 */
///#end
- (NSData *)dataUsingEncoding:(NSStringEncoding)encoding;

///#begin zh-cn
/**
 *	@brief	获取Multipart格式的二进制数据
 *
 *	@param 	encoding 	编码
 *  @param  boundary    分隔符号
 *
 *	@return	二进制数据对象
 */
///#end
///#begin en
/**
 *	@brief	Get multipart format binary data
 *
 *	@param 	encoding 	Encoding
 *  @param  boundary    Boundary string.
 *
 *	@return	Binary data object.
 */
///#end
- (NSData *)multipartDataUsingEncoding:(NSStringEncoding)encoding boundary:(NSString *)boundary;

///#begin zh-cn
/**
 *	@brief	获取请求参数字符串
 *
 *  @param  encoding    编码
 *
 *	@return	字符串对象
 */
///#end
///#begin en
/**
 *	@brief	Get parameters string.
 *
 *  @param  encoding    Encoding.
 *
 *	@return	String object.
 */
///#end
- (NSString *)stringUsingEncoding:(NSStringEncoding)encoding;

///#begin zh-cn
/**
 *	@brief	获取参数集合字典
 *
 *	@return	字典对象
 */
///#end
///#begin en
/**
 *	@brief	Get parameters dictionary.
 *
 *	@return	Dictionary object.
 */
///#end
- (NSDictionary *)dictionaryValue;

@end
