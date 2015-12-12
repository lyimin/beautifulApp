
#import <Foundation/Foundation.h>

///#begin zh-cn
/**
 *	@brief  调试日志类
 */
///#end
///#begin en
/**
 *	@brief  Debug Log.
 */
///#end
@interface CMDebugLog : NSObject

///#begin zh-cn
/**
 *	@brief	获取日志保存路径
 *
 *	@return	日志路径
 */
///#end
///#begin en
/**
 *	@brief	Get log path.
 *
 *	@return	Log path.
 */
///#end
+ (NSString *)logPath;

///#begin zh-cn
/**
 *	@brief	写入信息
 *
 *	@param 	content 	内容
 */
///#end
///#begin en
/**
 *	@brief	Write info message.
 *
 *	@param 	content 	info message.
 */
///#end
+ (void)writeInfo:(NSString *)content;

///#begin zh-cn
/**
 *	@brief	写入警告
 *
 *	@param 	content 	内容
 */
///#end
///#begin en
/**
 *	@brief	Write warning message.
 *
 *	@param 	content 	Warning string.
 */
///#end
+ (void)writeWarning:(NSString *)content;

///#begin zh-cn
/**
 *	@brief	写入错误
 *
 *	@param 	content 	内容
 */
///#end
///#begin en
/**
 *	@brief	Write error message.
 *
 *	@param 	content 	Error string.
 */
///#end
+ (void)writeError:(NSString *)content;

///#begin zh-cn
/**
 *	@brief	写入内容
 *
 *	@param 	content 	内容字典对象
 */
///#end
///#begin en
/**
 *	@brief	Write log content.
 *
 *	@param 	content 	Content dictionary object.
 */
///#end
+ (void)writeContentWithDictionary:(NSDictionary *)content;


@end
