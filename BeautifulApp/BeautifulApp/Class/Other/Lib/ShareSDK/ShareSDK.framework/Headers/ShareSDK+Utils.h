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

#import <ShareSDK/ShareSDK.h>
#import <CommonCrypto/CommonCrypto.h>
#import "SSHTTPClient.h"

///#begin zh-cn
/**
 *	@brief	网络类型
 */
///#end
///#begin en
/**
 *	@brief	Network type
 */
///#end
typedef enum
{
	SSNetworkTypeNone = 0, /**< 无网络 */
	SSNetworkTypeCellular = 1, /**< 蜂窝网络 */
    SSNetworkTypeWifi = 2, /**< wifi */
}
SSNetworkType;

///#begin zh-cn
/**
 *	@brief	ShareSDK工具类提供
 */
///#end
///#begin en
/**
 *	@brief	ShareSDK Utils
 */
///#end
@interface ShareSDK (Utils)

#pragma mark - ViewController

///#begin zh-cn
/**
 *	@brief	获取当前视图控制器
 *
 *	@return	视图控制器
 */
///#end
///#begin en
/**
 *	@brief	Get current view controller.
 *
 *	@return	View controller.
 */
///#end
+ (UIViewController *)currentViewController;

#pragma mark - Date

///#begin zh-cn
/**
 *	@brief	获取NSDate的年份部分
 *
 *	@param 	date 	日期对象
 *
 *	@return	年份
 */
///#end
///#begin en
/**
 *	@brief	Get the year part of the NSDate
 *
 *	@param 	date 	Date object
 *
 *	@return	Year
 */
///#end
+ (NSInteger)getFullYearWithDate:(NSDate *)date;

///#begin zh-cn
/**
 *	@brief	获取NSDate的月份部分
 *
 *	@param 	date 	日期对象
 *
 *	@return	月份
 */
///#end
///#begin en
/**
 *	@brief	Get the month part of the NSDate
 *
 *	@param 	date 	Date object
 *
 *	@return	Month
 */
///#end
+ (NSInteger)getMonthWithDate:(NSDate *)date;

///#begin zh-cn
/**
 *	@brief	获取NSDate的日期部分
 *
 *	@param 	date 	日期对象
 *
 *	@return	日期
 */
///#end
///#begin en
/**
 *	@brief	Get the date part of the NSDate
 *
 *	@param 	date 	Date object.
 *
 *	@return	Date
 */
///#end
+ (NSInteger)getDayWithDate:(NSDate *)date;

///#begin zh-cn
/**
 *	@brief	获取NSDate的小时部分
 *
 *	@param 	date 	日期对象
 *
 *	@return	小时
 */
///#end
///#begin en
/**
 *	@brief	Get the hour part of the NSDate
 *
 *	@param 	date 	Date object
 *
 *	@return	Hour
 */
///#end
+ (NSInteger)getHourWithDate:(NSDate *)date;

///#begin zh-cn
/**
 *	@brief	获取NSDate的分钟部分
 *
 *	@param 	date 	日期对象
 *
 *	@return	分钟
 */
///#end
///#begin en
/**
 *	@brief	Get the minute part of the NSDate
 *
 *	@param 	date 	Date object.
 *
 *	@return Minute
 */
///#end
+ (NSInteger)getMinuteWithDate:(NSDate *)date;

///#begin zh-cn
/**
 *	@brief	获取NSDate的秒部分
 *
 *	@param 	date 	日期对象
 *
 *	@return	秒
 */
///#end
///#begin en
/**
 *	@brief	Get the second part of the NSDate
 *
 *	@param 	date 	Date object.
 *
 *	@return	Seconds
 */
///#end
+ (NSInteger)getSecondWithDate:(NSDate *)date;

///#begin zh-cn
/**
 *	@brief	根据字符串格式转换字符串为日期
 *
 *	@param 	format 	日期格式字符串
 *	@param 	dateString 	日期字符串
 *
 *	@return	日期对象
 */
///#end
///#begin en
/**
 *	@brief	According to format string convert the string to a date
 *
 *	@param 	format 	Date format string.
 *	@param 	dateString 	Date string.
 *
 *	@return	Date object.
 */
///#end
+ (NSDate *)dateWithFormat:(NSString *)format dateString:(NSString *)dateString;

///#begin zh-cn
/**
 *	@brief	根据字符串格式转换字符串为日期
 *
 *	@param 	format 	日期格式字符串
 *	@param 	dateString 	日期字符串
 *	@param 	locale 	本地化参数
 *
 *	@return	日期对象
 */
///#end
///#begin en
/**
 *	@brief	According to format string convert the string to a date
 *
 *	@param 	format 	Date format string.
 *	@param 	dateString 	Date string.
 *	@param 	locale 	Localization parameters
 *
 *	@return	Date object.
 */
///#end
+ (NSDate *)dateWithFormat:(NSString *)format dateString:(NSString *)dateString locale:(NSLocale *)locale;

///#begin zh-cn
/**
 *	@brief	根据字符串格式转换日期为字符串
 *
 *	@param 	format 	日期格式字符串
 *	@param 	date 	日期对象
 *
 *	@return	日期字符串
 */
///#end
///#begin en
/**
 *	@brief	According to string format conversion date to a string
 *
 *	@param 	format 	date format string.
 *	@param 	date 	Date object
 *
 *	@return	date string.
 */
///#end
+ (NSString *)stringWithFormat:(NSString *)format data:(NSDate *)date;

///#begin zh-cn
/**
 *	@brief	根据年月日返回日期
 *
 *	@param 	year 	年份
 *	@param 	month 	月份
 *	@param 	date 	日期
 *	@param 	hour 	小时
 *	@param 	minute 	分钟
 *	@param 	second 	秒
 *
 *	@return	日期对象
 */
///#end
///#begin en
/**
 *	@brief	According to Year，month, date return date object.
 *
 *	@param 	year 	Year
 *	@param 	month 	Month
 *	@param 	date 	Date
 *	@param 	hour 	Hour
 *	@param 	minute 	Minute
 *	@param 	second 	seconds
 *
 *	@return	Date object.
 */
///#end
+ (NSDate *)dateWithYear:(NSInteger)year
                   month:(NSInteger)month
                    date:(NSInteger)date
                    hour:(NSInteger)hour
                  minute:(NSInteger)minute
                  second:(NSInteger)second;

#pragma mark - Color

///#begin zh-cn
/**
 *	@brief	获取颜色对象
 *
 *	@param 	rgb 	RGB颜色值
 *
 *	@return	颜色对象
 */
///#end
///#begin en
/**
 *	@brief	Get color object.
 *
 *	@param 	rgb 	RGB color value.
 *
 *	@return	Color object.
 */
///#end
+ (UIColor *)colorWithRGB:(NSUInteger)rgb;

///#begin zh-cn
/**
 *	@brief	获取颜色对象
 *
 *	@param 	argb 	ARGB颜色值
 *
 *	@return	颜色对象
 */
///#end
///#begin en
/**
 *	@brief	Get color object.
 *
 *	@param 	rgb 	ARGB color value.
 *
 *	@return	Color object.
 */
///#end
+ (UIColor *)colorWithARGB:(NSUInteger)argb;


#pragma mark - Image

///#begin zh-cn
/**
 *	@brief	获取图片对象
 *
 *	@param 	name 	图片名称
 *	@param 	bundleName 	Bundle名称
 *
 *	@return	图片对象
 */
///#end
///#begin en
/**
 *	@brief	Get image object.
 *
 *	@param 	name 	Image name.
 *	@param 	bundleName 	Bundle name.
 *
 *	@return	Image object.
 */
///#end
+ (UIImage *)imageNamed:(NSString *)name bundleName:(NSString *)bundleName;

///#begin zh-cn
/**
 *	@brief	裁剪图片
 *
 *  @param  image   图片对象
 *	@param 	rect 	裁剪范围
 *
 *	@return	裁剪后的图片对象
 */
///#end
///#begin en
/**
 *	@brief	Clip Image
 *
 *  @param  image   Image object.
 *	@param 	rect 	Clip rect.
 *
 *	@return	Image object.
 */
///#end
+ (UIImage *)clipImageWithImage:(UIImage *)image rect:(CGRect)rect;

///#begin zh-cn
/**
 *	@brief	创建圆角图片
 *
 *  @param  image   图片对象
 *	@param 	size 	圆角图像的图片尺寸
 *	@param 	ovalWidth 	圆角宽度
 *	@param 	ovalHeight 	圆角高度
 *
 *	@return	圆角图片对象引用
 */
///#end
///#begin en
/**
 *	@brief	Create a rounded image
 *
 *  @param  image   Image object.
 *	@param 	size 	Image size.
 *	@param 	ovalWidth 	oval width
 *	@param 	ovalHeight 	oval height
 *
 *	@return	Image object.
 */
///#end
+ (UIImage *)roundedRectImageWithImage:(UIImage *)image
                                  size:(CGSize)size
                             ovalWidth:(CGFloat)ovalWidth
                            ovalHeight:(CGFloat)ovalHeight;

#pragma mark - Device

///#begin zh-cn
/**
 *	@brief	比较版本字符串
 *
 *	@param 	other 	需要对比的版本号
 *
 *	@return	NSOrderedAscending 表示大于指定版本 NSOrderedSame 表示两个版本相同  NSOrderedDescending 表示小于指定版本
 */
///#end
///#begin en
/**
 *	@brief	Compare the version string
 *
 *	@param 	other 	Version string.
 *
 *	@return	NSOrderedAscending means greater than the specified version. NSOrderedSame represent two versions of the same. NSOrderedDescending represents less than the specified version
 */
///#end
+ (NSComparisonResult)versionStringCompare:(NSString *)other;

///#begin zh-cn
/**
 *	@brief	获取应用的Bundle标识
 *
 *	@return	Bundle标识
 */
///#end
///#begin en
/**
 *	@brief	Get bundle identifier.
 *
 *	@return	Bundle identifier.
 */
///#end
+ (NSString *)bundleId;

///#begin zh-cn
/**
 *	@brief	获取应用版本号
 *
 *	@return	版本号
 */
///#end
///#begin en
/**
 *	@brief	Get app version.
 *
 *	@return	Version string.
 */
///#end
+ (NSString *)appVersion;

///#begin zh-cn
/**
 *	@brief	获取当前网络类型
 *
 *	@return	网络类型
 */
///#end
///#begin en
/**
 *	@brief	Get current network type.
 *
 *	@return	Network type.
 */
///#end
+ (SSNetworkType)currentNetworkType;

///#begin zh-cn
/**
 *	@brief	获取设备型号
 *
 *	@return	设备型号
 */
///#end
///#begin en
/**
 *	@brief	Get device model.
 *
 *	@return	Device model.
 */
///#end
+ (NSString *)deviceModel;

///#begin zh-cn
/**
 *	@brief	获取手机运营商代码
 *
 *	@return	手机运营商代码
 */
///#end
///#begin en
/**
 *	@brief	Get mobile carrier code
 *
 *	@return	Mobile carrier code
 */
///#end
+ (NSString *)carrier;

#pragma mark - Http

///#begin zh-cn
/**
 *	@brief	创建HTTP客户端
 *
 *	@param 	request 	请求对象
 *
 *	@return	HTTP客户端对象
 */
///#end
///#begin en
/**
 *	@brief	Create a HTTP client.
 *
 *	@param 	request 	Request object.
 *
 *	@return	HTTP client object.
 */
///#end
+ (SSHTTPClient *)httpClientWithRequest:(NSMutableURLRequest *)request;

///#begin zh-cn
/**
 *	@brief	创建HTTP客户端
 *
 *	@param 	url 	请求URL
 *
 *	@return	HTTP客户端对象
 */
///#end
///#begin en
/**
 *	@brief	Create a HTTP client.
 *
 *	@param 	url 	Request URL object.
 *
 *	@return	HTTP client object.
 */
///#end
+ (SSHTTPClient *)httpClientWithURL:(NSURL *)url;

///#begin zh-cn
/**
 *	@brief	创建HTTP客户端
 *
 *	@param 	urlString 	请求地址字符串
 *
 *	@return	HTTP客户端对象
 */
///#end
///#begin en
/**
 *	@brief	Create a HTTP client.
 *
 *	@param 	urlString 	Request url address.
 *
 *	@return	HTTP client object.
 */
///#end
+ (SSHTTPClient *)httpClientWithURLString:(NSString *)urlString;

#pragma mark - JSON

///#begin zh-cn
/**
 *	@brief	将Data转换为JSON对象
 *
 *	@param 	data 	数据
 *
 *	@return	JSON对象
 */
///#end
///#begin en
/**
 *	@brief	Converts a data to JSON object
 *
 *	@param 	data 	Data
 *
 *	@return	JSON object.
 */
///#end
+ (id)jsonObjectWithData:(NSData *)data;

///#begin zh-cn
/**
 *	@brief	将字符串转换为JSON对象
 *
 *	@param 	string 	字符串
 *
 *	@return	JSON对象
 */
///#end
///#begin en
/**
 *	@brief	Converts a string to JSON object
 *
 *	@param 	string 	String
 *
 *	@return	JSON object.
 */
///#end
+ (id)jsonObjectWithString:(NSString *)string;

///#begin zh-cn
/**
 *	@brief	将对象转换为JSON字符串
 *
 *	@param 	object 	对象
 *
 *	@return	JSON字符串
 */
///#end
///#begin en
/**
 *	@brief	Convert an object to JSON string.
 *
 *	@param 	object 	Object
 *
 *	@return	JSON string.
 */
///#end
+ (NSString *)jsonStringWithObject:(id)object;

///#begin zh-cn
/**
 *	@brief	将对象转换为JSON数据
 *
 *	@param 	object 	对象
 *
 *	@return	JSON数据
 */
///#end
///#begin en
/**
 *	@brief	Convert an object to JSON data
 *
 *	@param 	object 	Object
 *
 *	@return	JSON data.
 */
///#end
+ (NSData *)jsonDataWithObject:(id)object;


#pragma mark - Data

///#begin zh-cn
/**
 *	@brief	GZip方式压缩数据
 *
 *	@return	压缩后数据
 */
///#end
///#begin en
/**
 *	@brief	Compress data By GZip
 *
 *	@return	After compress data.
 */
///#end
+ (NSData *)gzipWithData:(NSData *)data;

///#begin zh-cn
/**
 *	@brief	解压GZip数据
 *
 *	@return	解压后GZip数据
 */
///#end
///#begin en
/**
 *	@brief	Extracting GZip data
 *
 *	@return	After extracting data.
 */
///#end
+ (NSData *)uncompressGZipWithData:(NSData *)data;

///#begin zh-cn
/**
 *	@brief	AES128位加密
 *
 *  @param  data    需要加密数据
 *	@param 	key 	密钥
 *	@param 	iv 	初始向量,允许为nil
 *  @param  encoding    字符编码
 *
 *	@return	加密后数据
 */
///#end
///#begin en
/**
 *	@brief	AES 128-bit encryption
 *
 *  @param  data    Data
 *	@param 	key 	Key
 *	@param 	iv 	Initial vector, which allows to nil
 *  @param  encoding    Encoding
 *
 *	@return	After the encrypt data.
 */
///#end
+ (NSData *)dataUsingAES128EncryptWithData:(NSData *)data
                                       key:(NSString *)key
                                        iv:(NSString *)iv
                                  encoding:(NSStringEncoding)encoding;

///#begin zh-cn
/**
 *	@brief	AES128位解密
 *
 *  @param  data    需要解密数据
 *	@param 	key 	密钥
 *	@param 	iv 	初始向量,允许为nil
 *  @param  encoding    字符编码
 *
 *	@return	解密后数据
 */
///#end
///#begin en
/**
 *	@brief	AES 128-bit dencryption
 *
 *  @param  data    Data
 *	@param 	key 	Key
 *	@param 	iv 	Initial vector, which allows to nil
 *  @param  encoding    Encoding
 *
 *	@return	After the decrypt data.
 */
///#end
+ (NSData *)dataUsingAES128DecryptWithData:(NSData *)data
                                       key:(NSString *)key
                                        iv:(NSString *)iv
                                  encoding:(NSStringEncoding)encoding;

///#begin zh-cn
/**
 *	@brief	AES128位加密
 *
 *  @param  data    需要加密数据
 *	@param 	key 	密钥
 *	@param 	iv 	初始向量,允许为nil
 *  @param  options     选项
 *
 *	@return	加密后数据
 */
///#end
///#begin en
/**
 *	@brief	AES 128-bit encryption
 *
 *  @param  data    Data
 *	@param 	key 	Key
 *	@param 	iv 	Initial vector, which allows to nil
 *  @param  options     Options
 *
 *	@return	After the encrypt data.
 */
///#end
+ (NSData *)dataUsingAES128EncryptWithData:(NSData *)data
                                       key:(NSData *)key
                                        iv:(NSData *)iv
                                   options:(CCOptions)options;

///#begin zh-cn
/**
 *	@brief	AES128位解密
 *
 *  @param  data    需要解密数据
 *	@param 	key 	密钥
 *	@param 	iv 	初始向量,允许为nil
 *  @param  options     选项
 *
 *	@return	解密后数据
 */
///#end
///#begin en
/**
 *	@brief	AES 128-bit decryption
 *
 *  @param  data    Data
 *	@param 	key 	Key
 *	@param 	iv 	Initial vector, which allows to nil
 *  @param  options     Options
 *
 *	@return	After the decrypt data.
 */
///#end
+ (NSData *)dataUsingAES128DecryptWithData:(NSData *)data
                                       key:(NSData *)key
                                        iv:(NSData *)iv
                                   options:(CCOptions)options;

///#begin zh-cn
/**
 *	@brief	使用BASE64编码数据
 *
 *  @param  data    数据
 *
 *	@return	编码后字符串
 */
///#end
///#begin en
/**
 *	@brief	Using BASE64 encoding data
 *
 *  @param  data    Data
 *
 *	@return	After the encoded string.
 */
///#end
+ (NSString *)stringUsingBase64EncodeWithData:(NSData *)data;


#pragma mark - String

///#begin zh-cn
/**
 *	@brief	URL编码
 *
 *  @param  string      需要进行URL编码字符串
 *	@param 	encoding 	编码标准
 *
 *	@return	编码后字符串
 */
///#end
///#begin en
/**
 *	@brief	URL encode.
 *
 *  @param  string      Needs to be URL encoded string
 *	@param 	encoding 	Encoding
 *
 *	@return	After the encoded string.
 */
///#end
+ (NSString *)urlEncodeWithString:(NSString *)string encoding:(NSStringEncoding)encoding;

///#begin zh-cn
/**
 *	@brief	URL解码
 *
 *  @param  string      需要进行URL解码字符串
 *	@param 	encoding 	编码标准
 *
 *	@return	解码后字符串
 */
///#end
///#begin en
/**
 *	@brief	URL decode.
 *
 *  @param  string      Needs to be URL decoded string
 *	@param 	encoding 	Encoding
 *
 *	@return	After the decoded string.
 */
///#end
+ (NSString *)urlDecodeWithString:(NSString *)string encoding:(NSStringEncoding)encoding;

///#begin zh-cn
/**
 *	@brief	使用MD5算法进行签名（16位）
 *
 *  @param  string  原字符串
 *
 *	@return	签名后字符串
 */
///#end
///#begin en
/**
 *	@brief	Use MD5 signature algorithm (16-bit)
 *
 *  @param  string  Raw string.
 *
 *	@return	After the signature string
 */
///#end
+ (NSString *)hexDigestStringUsingMD5WithString:(NSString *)string;

#pragma mark - Regex

///#begin zh-cn
/**
 *	@brief	字符串是否匹配
 *
 *	@param 	string 	字符串
 *	@param 	regex 	正则表达式
 *
 *	@return	YES 表示匹配， NO 表示不匹配
 */
///#end
///#begin en
/**
 *	@brief	Whether the string matches
 *
 *	@param 	string 	String object.
 *	@param 	regex 	Regex string.
 *
 *	@return	YES means to match, NO means no match
 */
///#end
+ (BOOL)isMatchWithString:(NSString *)string regex:(NSString *)regex;


@end
