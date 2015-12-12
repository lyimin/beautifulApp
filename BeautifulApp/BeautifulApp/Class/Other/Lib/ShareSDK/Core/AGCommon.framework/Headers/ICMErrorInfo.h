
#import <Foundation/Foundation.h>

///#begin zh-cn
/**
 *	@brief	错误级别
 */
///#end
///#begin en
/**
 *	@brief	Error Level
 */
///#end
typedef enum
{
	CMErrorLevelAPI = 1, /**< API错误 */
	CMErrorLevelHTTP = 2, /**< HTTP错误 */
    CMErrorLevelNetwork = 3  /**< 网络错误 */
}
CMErrorLevel;

///#begin zh-cn
/**
 *	@brief	错误信息
 */
///#end
///#begin en
/**
 *	@brief	Error information
 */
///#end
@protocol ICMErrorInfo <NSObject>

///#begin zh-cn
/**
 *	@brief	获取错误代码，如果为调用API出错则应该参考API错误码对照表，如果为HTTP错误，此属性则指示HTTP错误码。
 *
 *	@return	错误代码
 */
///#end
///#begin en
/**
 *	@brief	Get error code，If it is you call the API, you should see the error code table, if it is an HTTP error, this attribute indicates the HTTP error code.
 *
 *	@return	Error code.
 */
///#end
- (NSInteger)errorCode;

///#begin zh-cn
/**
 *	@brief	获取错误描述，对应相应的错误码的描述
 *
 *	@return	错误描述
 */
///#end
///#begin en
/**
 *	@brief	Get error description
 *
 *	@return	Error description
 */
///#end
- (NSString *)errorDescription;

///#begin zh-cn
/**
 *	@brief	获取错误级别
 *
 *	@return	错误级别
 */
///#end
///#begin en
/**
 *	@brief	Get error level
 *
 *	@return	Error level.
 */
///#end
- (CMErrorLevel)errorLevel;

@end
