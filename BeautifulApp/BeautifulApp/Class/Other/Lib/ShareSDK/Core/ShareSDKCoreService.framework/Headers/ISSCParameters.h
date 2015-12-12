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
 *	@brief	请求参数协议
 */
///#end
///#begin en
/**
 *	@brief	Parameters.
 */
///#end
@protocol ISSCParameters <NSObject>

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
- (void)addParameter:(NSString *)name value:(id)value;

///#begin zh-cn
/**
 *	@brief	添加文件参数
 *
 *	@param 	name 	参数名称
 *	@param 	filePath 	参数值
 *  @param  mimeType    MIME类型
 */
///#end
///#begin en
/**
 *	@brief	Add file parameter.
 *
 *	@param 	name 	Parameter name.
 *	@param 	filePath 	File path.
 *  @param  mimeType    MIME type.
 */
///#end
- (void)addParameter:(NSString *)name
            filePath:(id)filePath
            mimeType:(NSString *)mimeType;

///#begin zh-cn
/**
 *	@brief	添加文件参数
 *
 *	@param 	name 	参数名称
 *	@param 	fileName 	文件名称
 *	@param 	data 	文件数据
 *	@param 	mimeType 	MIME类型
 *	@param 	transferEncoding 	传输编码，不指定可以设置为nil
 */
///#end
///#begin en
/**
 *	@brief	Add file parameter.
 *
 *	@param 	name 	Parameter name.
 *	@param 	fileName 	File name.
 *	@param 	data 	File data.
 *	@param 	mimeType 	MIME type.
 *	@param 	transferEncoding 	Transfer encoding, can be set to nil
 */
///#end
- (void)addParameter:(NSString *)name
            fileName:(NSString *)fileName
                data:(NSData *)data
            mimeType:(NSString *)mimeType
    transferEncoding:(NSString *)transferEncoding;

///#begin zh-cn
/**
 *	@brief	添加多个参数
 *
 *	@param 	parameters 	参数对象
 */
///#end
///#begin en
/**
 *	@brief	Adding multiple parameters
 *
 *	@param 	parameters 	Parameters object.
 */
///#end
- (void)addParameters:(id<ISSCParameters>)parameters;

///#begin zh-cn
/**
 *	@brief	添加多个参数
 *
 *	@param 	dictionary 	参数字典
 */
///#end
///#begin en
/**
 *	@brief	Adding multiple parameters
 *
 *	@param 	dictionary 	Dicationary value.
 */
///#end
- (void)addParametersWithDictionary:(NSDictionary *)dictionary;

///#begin zh-cn
/**
 *	@brief	清除参数
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
 *	@brief	获取参数值
 *
 *	@param 	name 	参数名称
 *
 *	@return	参数值
 */
///#end
///#begin en
/**
 *	@brief	Get parameter value
 *
 *	@param 	name 	Parameter name.
 *
 *	@return	Paremeter value
 */
///#end
- (id)parameterWithName:(NSString *)name;

///#begin zh-cn
/**
 *	@brief	获取参数数量
 *
 *	@return	参数数量
 */
///#end
///#begin en
/**
 *	@brief	Get parameters number.
 *
 *	@return	Number of parameters
 */
///#end
- (NSInteger)parameterCount;

///#begin zh-cn
/**
 *	@brief	获取字典结构数据
 *
 *	@return	字典数据
 */
///#end
///#begin en
/**
 *	@brief	Get parameters dictionary.
 *
 *	@return	Dication object.
 */
///#end
- (NSDictionary *)dictionaryValue;

///#begin zh-cn
/**
 *	@brief	获取参数组织的字符串
 *
 *	@param 	encoding 	编码
 *
 *	@return	字符串
 */
///#end
///#begin en
/**
 *	@brief	Get parameters string.
 *
 *	@param 	encoding 	Encoding.
 *
 *	@return	String object.
 */
///#end
- (NSString *)stringValue:(NSStringEncoding)encoding;

///#begin zh-cn
/**
 *	@brief	获取参数组织的二进制数据
 *
 *	@param 	encoding 	编码
 *
 *	@return	二进制数据
 */
///#end
///#begin en
/**
 *	@brief	Get parameters binary data.
 *
 *	@param 	encoding 	Encoding.
 *
 *	@return	Binary data.
 */
///#end
- (NSData *)dataValue:(NSStringEncoding)encoding;

///#begin zh-cn
/**
 *	@brief	获取参数组织的二进制数据
 *
 *	@param 	encoding 	编码
 *	@param 	boundary 	分隔字符串，用于multipart形式
 *
 *	@return	 二进制数据
 */
///#end
///#begin en
/**
 *	@brief	Get parameters binary data.
 *
 *	@param 	encoding 	Encoding
 *	@param 	boundary 	Boundary string for multipart forms
 *
 *	@return	 Binary data.
 */
///#end
- (NSData *)dataValue:(NSStringEncoding)encoding boundary:(NSString *)boundary;


@end
