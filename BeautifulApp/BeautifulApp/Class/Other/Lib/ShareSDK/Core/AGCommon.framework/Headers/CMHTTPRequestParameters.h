
#import <Foundation/Foundation.h>

///#begin zh-cn
/**
 *	@brief	HTTP请求参数列表类,用于快捷填充HTTP请求数据的工具类
 */
///#end
///#begin en
/**
 *	@brief	HTTP Request Parameters
 */
///#end
@interface CMHTTPRequestParameters : NSObject
{
@private
    NSMutableDictionary *_parameterDict;
}

///#begin zh-cn
/**
 *	@brief	参数字典
 */
///#end
///#begin en
/**
 *	@brief	Parameter dicationary.
 */
///#end
@property (nonatomic,readonly) NSDictionary *parameterDictionary;

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
 *	@brief	Initialize parameter.
 *
 *	@param 	url 	The URL object.
 *
 *	@return	Request parameter object.
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
 *	@brief	Initialize parameter.
 *
 *	@param 	queryString 	The URL query string.
 *
 *	@return	Request Parameter object.
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
 *	@param 	name 	Name
 *	@param 	value 	Value
 */
///#end
- (void)addParameterWithName:(NSString *)name value:(id)value;

///#begin zh-cn
/**
 *	@brief	添加多个参数
 *
 *  @since  ver1.0.8
 *
 *	@param 	parameters 	请求参数列表对象
 */
///#end
///#begin en
/**
 *	@brief	Adding multiple parameters
 *
 *  @since  ver1.0.8
 *
 *	@param 	parameters 	Parameters object.
 */
///#end
- (void)addParameters:(CMHTTPRequestParameters *)parameters;

///#begin zh-cn
/**
 *	@brief	添加多个参数
 *
 *  @since  ver1.0.8
 *
 *	@param 	dictionary 	请求参数字典
 */
///#end
///#begin en
/**
 *	@brief	Adding multiple parameters
 *
 *  @since  ver1.0.8
 *
 *	@param 	dictionary 	Parameters dicationary object.
 */
///#end
- (void)addParametersWithDictionary:(NSDictionary *)dictionary;

///#begin zh-cn
/**
 *	@brief	删除参数
 *
 *	@param 	name 	参数名称
 */
///#end
///#begin en
/**
 *	@brief	Remove a parameter.
 *
 *	@param 	name 	Name.
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
 *	@param 	name 	Name.
 *
 *	@return	Value.
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
 *	@brief	Get request parameters binary data.
 *
 *	@param 	encoding 	Encoding.
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
 *	@brief	Get binary data of multipart form.
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
 *	@brief	Get request parameters string.
 *
 *  @param  encoding    Encoding
 *
 *	@return	String object.
 */
///#end
- (NSString *)stringUsingEncoding:(NSStringEncoding)encoding;

@end
