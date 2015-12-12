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
#import "ISSCAccount.h"
#import "ISSCParameters.h"

///#begin zh-cn
/**
 *	@brief	请求协议
 */
///#end
///#begin en
/**
 *	@brief	Request protocol
 */
///#end
@protocol ISSCRequest <NSObject>

///#begin zh-cn
/**
 *	@brief	获取登录帐号
 *
 *	@return	登录帐号
 */
///#end
///#begin en
/**
 *	@brief	Get account.
 *
 *	@return	Account object.
 */
///#end
- (id<ISSCAccount>)account;

///#begin zh-cn
/**
 *	@brief	添加请求头参数
 *
 *	@param 	header  参数头名称
 *	@param 	value   参数值
 */
///#end
///#begin en
/**
 *	@brief	Add request header
 *
 *	@param 	header  Header name.
 *	@param 	value   Header value.
 */
///#end
- (void)addHeader:(NSString *)header value:(NSString *)value;

///#begin zh-cn
/**
 *	@brief	以GET方式进行数据提交
 *
 *	@param 	path 	提交路径
 *  @param  parameters  参数
 *  @param  timeInterval 请求超时时间
 *  @param  userData    附加数据
 *  @param  result  返回回调方法
 *  @param  fault   错误回调方法
 */
///#end
///#begin en
/**
 *	@brief	Send request by GET mehtod
 *
 *	@param 	path 	Request path.
 *  @param  parameters  Parameters object.
 *  @param  timeInterval time Interval
 *  @param  userData    User data.
 *  @param  result  Result handler.
 *  @param  fault   Fault handler.
 */
///#end
- (void)get:(NSString *)path
 parameters:(id<ISSCParameters>)parameters
   userData:(id)userData
     result:(void(^)(NSHTTPURLResponse *response, NSData *responseData))result
      fault:(void(^)(NSError *error))fault;

- (void)get:(NSString *)path
 parameters:(id<ISSCParameters>)parameters
timeInterval:(NSTimeInterval)timeInterval
   userData:(id)userData
     result:(void(^)(NSHTTPURLResponse *response, NSData *responseData))result
      fault:(void(^)(NSError *error))fault;


///#begin zh-cn
/**
 *	@brief	以POST方式进行数据提交
 *
 *	@param 	path 	提交路径
 *  @param  parameters  参数
 *  @param  timeInterval 请求超时时间
 *  @param  userData    附加数据
 *  @param  result  返回回调方法
 *  @param  fault   错误回调方法
 */
///#end
///#begin en
/**
 *	@brief	Send request by POST mehtod
 *
 *	@param 	path 	Request path.
 *  @param  parameters  Parameters object.
 *  @param  timeInterval time Interval
 *  @param  userData    User data.
 *  @param  result  Result handler.
 *  @param  fault   Fault handler.
 */
///#end
- (void)post:(NSString *)path
  parameters:(id<ISSCParameters>)parameters
    userData:(id)userData
      result:(void(^)(NSHTTPURLResponse *response, NSData *responseData))result
       fault:(void(^)(NSError *error))fault;

- (void)post:(NSString *)path
  parameters:(id<ISSCParameters>)parameters
timeInterval:(NSTimeInterval)timeInterval
    userData:(id)userData
      result:(void(^)(NSHTTPURLResponse *response, NSData *responseData))result
       fault:(void(^)(NSError *error))fault;

///#begin zh-cn
/**
 *	@brief	以POST方式并以multipart形式进行数据提交
 *
 *	@param 	path 	提交路径
 *  @param  parameters  参数
 *  @param  timeInterval 请求超时时间
 *  @param  userData    附加数据
 *  @param  result  返回回调方法
 *  @param  fault   错误回调方法
 */
///#end
///#begin en
/**
 *	@brief	Send request by POST mehtod and multipart form data submitted
 *
 *	@param 	path 	Request path.
 *  @param  parameters  Parameters object.
 *  @param  timeInterval time Interval
 *  @param  userData    User data.
 *  @param  result  Result handler.
 *  @param  fault   Fault handler.
 */
///#end
- (void)multipartPost:(NSString *)path
           parameters:(id<ISSCParameters>)parameters
             userData:(id)userData
               result:(void(^)(NSHTTPURLResponse *response, NSData *responseData))result
                fault:(void(^)(NSError *error))fault;

- (void)multipartPost:(NSString *)path
           parameters:(id<ISSCParameters>)parameters
         timeInterval:(NSTimeInterval)timeInterval
             userData:(id)userData
               result:(void(^)(NSHTTPURLResponse *response, NSData *responseData))result
                fault:(void(^)(NSError *error))fault;

///#begin zh-cn
/**
 *	@brief	以DELETE方式进行数据提交
 *
 *	@param 	path 	提交路径
 *	@param 	parameters 	参数
 *  @param  timeInterval 请求超时时间
 *	@param 	userData 	附加数据
 *  @param  result      返回回调方式
 *  @param  fault       错误回调方法
 */
///#end
///#begin en
/**
 *	@brief	Send request by DELETE method
 *
 *	@param 	path 	Request path.
 *	@param 	parameters 	Parameters object.
 *  @param  timeInterval time Interval
 *	@param 	userData 	User data.
 *  @param  result      Result handler.
 *  @param  fault       Fault handler.
 */
///#end
- (void)del:(NSString *)path
 parameters:(id<ISSCParameters>)parameters
   userData:(id)userData
     result:(void(^)(NSHTTPURLResponse *response, NSData *responseData))result
      fault:(void(^)(NSError *error))fault;

- (void)del:(NSString *)path
 parameters:(id<ISSCParameters>)parameters
timeInterval:(NSTimeInterval)timeInterval
   userData:(id)userData
     result:(void(^)(NSHTTPURLResponse *response, NSData *responseData))result
      fault:(void(^)(NSError *error))fault;

///#begin zh-cn
/**
 *	@brief	发送请求
 *
 *	@param 	request 	请求对象
 *  @param  timeInterval 请求超时时间
 *	@param 	userData 	附加数据
 *  @param  result      返回回调方式
 *  @param  fault       错误回调方法
 */
///#end
///#begin en
/**
 *	@brief	Send request.
 *
 *	@param 	request 	Request object.
 *  @param  timeInterval time Interval
 *	@param 	userData 	User data.
 *  @param  result      Result handler.
 *  @param  fault       Fault handler.
 */
///#end
- (void)sendRequest:(NSMutableURLRequest *)request
           userData:(id)userData
             result:(void(^)(NSHTTPURLResponse *response, NSData *responseData))result
              fault:(void(^)(NSError *error))fault;

- (void)sendRequest:(NSMutableURLRequest *)request
       timeInterval:(NSTimeInterval)timeInterval
           userData:(id)userData
             result:(void(^)(NSHTTPURLResponse *response, NSData *responseData))result
              fault:(void(^)(NSError *error))fault;

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
- (void)cancel;

@end
