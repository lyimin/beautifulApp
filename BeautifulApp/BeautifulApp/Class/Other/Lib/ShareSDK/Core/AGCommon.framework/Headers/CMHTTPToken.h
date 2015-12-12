
#import <Foundation/Foundation.h>
#import "CMEventDispatcher.h"

///#begin zh-cn
/**
 *	@brief	HTTP返回通知
 */
///#end
///#begin en
/**
 *	@brief	HTTP result notification.
 */
///#end
#define NOTIF_HTTP_RESULT @"httpResult"

///#begin zh-cn
/**
 *	@brief	HTTP错误通知
 */
///#end
///#begin en
/**
 *	@brief	HTTP error notification.
 */
///#end
#define NOTIF_HTTP_ERROR @"httpError"

///#begin zh-cn
/**
 *	@brief	缓存数据
 */
///#end
///#begin en
/**
 *	@brief	Cache data notification.
 */
///#end
#define NOTIF_HTTP_CACHE_DATA @"httpCacheData"

///#begin zh-cn
/**
 *	@brief	回复对象
 */
///#end
///#begin en
/**
 *	@brief	Response key.
 */
///#end
#define NOTIF_HTTP_KEY_RESPONSE @"nhkResponse"

///#begin zh-cn
/**
 *	@brief	回复数据
 */
///#end
///#begin en
/**
 *	@brief	Response data key.
 */
///#end
#define NOTIF_HTTP_KEY_RESPONSE_DATA @"nhkResponseData"

///#begin zh-cn
/**
 *	@brief	请求异常
 */
///#end
///#begin en
/**
 *	@brief	Error key.
 */
///#end
#define NOTIF_HTTP_KEY_ERROR @"nhkError"

///#begin zh-cn
/**
 *	@brief	附加数据标识
 */
///#end
///#begin en
/**
 *	@brief	User data key.
 */
///#end
#define NOTIF_HTTP_KEY_USER_DATA @"nhkUserData"

///#begin zh-cn
/**
 *	@brief	缓存数据标识
 */
///#end
///#begin en
/**
 *	@brief	Cache data key.
 */
///#end
#define NOTIF_HTTP_KEY_CACHE_DATA @"nhkCacheData"


@class CMHTTPToken;

///#begin zh-cn
/**
 *	@brief	Http处理器
 */
///#end
///#begin en
/**
 *	@brief	HTTP Worker.
 */
///#end
@protocol ICMHTTPWorker <NSObject>

@required

///#begin zh-cn
/**
 *	@brief	http返回
 *
 *	@param 	token 令牌
 */
///#end
///#begin en
/**
 *	@brief	HTTP result
 *
 *	@param 	token Token object.
 */
///#end
- (void)httpResult:(CMHTTPToken *)token;

///#begin zh-cn
/**
 *	@brief	http缓存返回
 *
 *	@param 	token 	令牌
 *  @param  cacheData   缓存数据
 */
///#end
///#begin en
/**
 *	@brief	HTTP cache data result.
 *
 *	@param 	token 	Token object.
 *  @param  cacheData   Cache data
 */
///#end
- (void)httpCacheResult:(CMHTTPToken *)token cacheData:(NSString *)cacheData;

///#begin zh-cn
/**
 *	@brief	http错误
 *
 *	@param 	token 令牌
 */
///#end
///#begin en
/**
 *	@brief	HTTP fault
 *
 *	@param 	token Token object.
 */
///#end
- (void)httpFault:(CMHTTPToken *)token;

///#begin zh-cn
/**
 *	@brief	是否允许获取缓存数据
 *
 *	@param 	token 	令牌
 *
 *	@return	YES 表示允许获取，NO 表示从指定URL中获取数据
 */
///#end
///#begin en
/**
 *	@brief	Whether to allow access to cache data
 *
 *	@param 	token 	Token object.
 *
 *	@return	YES means allowing access to, NO indicates get data from the specified URL
 */
///#end
- (BOOL)httpShouldGetCacheData:(CMHTTPToken *)token;

///#begin zh-cn
/**
 *	@brief	获取缓存数据
 *
 *	@param 	token 	令牌
 *
 *	@return	缓存数据
 */
///#end
///#begin en
/**
 *	@brief	Get cache data.
 *
 *	@param 	token 	Token.
 *
 *	@return	Cache data string.
 */
///#end
- (NSString *)httpCacheData:(CMHTTPToken *)token;


@end

///#begin zh-cn
/**
 *	@brief	HTTP令牌
 */
///#end
///#begin en
/**
 *	@brief	HTTP Token.
 */
///#end
@interface CMHTTPToken : CMEventDispatcher <NSURLConnectionDelegate,
                                            NSURLConnectionDataDelegate>
{
@private
    NSMutableURLRequest *_request;
    NSURLConnection *_connection;
    NSHTTPURLResponse *_response;
    
    NSMutableData *_responseData;
    NSError *_error;
    
    id _userData;
    id<ICMHTTPWorker> _worker;
    BOOL _useCacheResponse;
}

///#begin zh-cn
/**
 *	@brief	使用缓存回复, YES 表示使用， NO 表示不使用
 */
///#end
///#begin en
/**
 *	@brief	Use cache response, YES indicates used， NO indicates no used.
 */
///#end
@property (nonatomic) BOOL useCacheResponse;

///#begin zh-cn
/**
 *	@brief	请求对象
 */
///#end
///#begin en
/**
 *	@brief	Request object.
 */
///#end
@property (nonatomic,readonly) NSMutableURLRequest *request;

///#begin zh-cn
/**
 *	@brief	请求回复对象
 */
///#end
///#begin en
/**
 *	@brief	Response object.
 */
///#end
@property (nonatomic,readonly) NSHTTPURLResponse *response;

///#begin zh-cn
/**
 *	@brief	回复数据
 */
///#end
///#begin en
/**
 *	@brief	Response data.
 */
///#end
@property (nonatomic,readonly) NSData *responseData;

///#begin zh-cn
/**
 *	@brief	请求错误对象
 */
///#end
///#begin en
/**
 *	@brief	Error information.
 */
///#end
@property (nonatomic,readonly) NSError *error;

///#begin zh-cn
/**
 *	@brief	附加数据
 */
///#end
///#begin en
/**
 *	@brief	User data.
 */
///#end
@property (nonatomic,readonly) id userData;

///#begin zh-cn
/**
 *	@brief	获取HTTP令牌
 *
 *	@param 	urlString 	请求地址字符串
 *	@param 	userData 	附加数据
 *	@param 	worker 	处理器，如果传入该参数则不进行默认处理。注意，此参数会在内部引用，切勿传入该Token对象的父级对象。
 *
 *	@return	HTTP令牌
 */
///#end
///#begin en
/**
 *	@brief	Create a HTTP token.
 *
 *	@param 	urlString 	URL String.
 *	@param 	userData 	User data.
 *	@param 	worker 	Worker, if the parameter is not passed for default handling. Note: that this parameter will be internal references, do not pass the parent object of the Token object.
 *
 *	@return	HTTP Token object.
 */
///#end
+ (CMHTTPToken *)tokenWithUrlString:(NSString *)urlString
                         userData:(id)userData
                           worker:(id<ICMHTTPWorker>)worker;

///#begin zh-cn
/**
 *	@brief	获取HTTP令牌
 *
 *	@param 	url 	请求地址
 *	@param 	userData 	附加数据
 *	@param 	worker 	处理器，如果传入该参数则不进行默认处理。注意，此参数会在内部引用，切勿传入该Token对象的父级对象。
 *
 *	@return	HTTP令牌
 */
///#end
///#begin en
/**
 *	@brief	Greate a HTTP token.
 *
 *	@param 	url 	URL object.
 *	@param 	userData 	User data.
 *	@param 	worker 	Worker, if the parameter is not passed for default handling. Note: that this parameter will be internal references, do not pass the parent object of the Token object.
 *
 *	@return	HTTP Token object.
 */
///#end
+ (CMHTTPToken *)tokenWithUrl:(NSURL *)url
                   userData:(id)userData
                     worker:(id<ICMHTTPWorker>)worker;

///#begin zh-cn
/**
 *	@brief	获取HTTP令牌
 *
 *	@param 	request 	请求对象
 *	@param 	userData 	附加数据
 *	@param 	worker 	处理器，如果传入该参数则不进行默认处理。注意，此参数会在内部引用，切勿传入该Token对象的父级对象。
 *
 *	@return	HTTP令牌
 */
///#end
///#begin en
/**
 *	@brief	Create a HTTP Token.
 *
 *	@param 	request 	Request object.
 *	@param 	userData 	User data.
 *	@param 	worker 	Worker, if the parameter is not passed for default handling. Note: that this parameter will be internal references, do not pass the parent object of the Token object.
 *
 *	@return	HTTP Token object.
 */
///#end
+ (CMHTTPToken *)tokenWithRequest:(NSMutableURLRequest *)request
                       userData:(id)userData
                         worker:(id<ICMHTTPWorker>)worker;


///#begin zh-cn
/**
 *	@brief	初始化令牌
 *
 *	@param 	url 	请求地址
 *	@param 	userData 	附加数据
 *	@param 	worker 	处理器，如果传入该参数则不进行默认处理。注意，此参数会在内部引用，切勿传入该Token对象的父级对象。
 *
 *	@return	令牌对象
 */
///#end
///#begin en
/**
 *	@brief	Initialize token.
 *
 *	@param 	url 	URL object.
 *	@param 	userData 	User data.
 *	@param 	worker 	Worker, if the parameter is not passed for default handling. Note: that this parameter will be internal references, do not pass the parent object of the Token object.
 *
 *	@return	Token object.
 */
///#end
- (id)initWithURL:(NSURL *)url
         userData:(id)userData
           worker:(id<ICMHTTPWorker>)worker;

///#begin zh-cn
/**
 *	@brief	初始化令牌
 *
 *	@param 	urlString 	请求地址字符串
 *	@param 	userData 	附加数据
 *	@param 	worker 	处理器，如果传入该参数则不进行默认处理。注意，此参数会在内部引用，切勿传入该Token对象的父级对象。
 *
 *	@return	令牌对象
 */
///#end
///#begin en
/**
 *	@brief	Initialize token.
 *
 *	@param 	urlString 	URL string.
 *	@param 	userData 	User data.
 *	@param 	worker 	Worker, if the parameter is not passed for default handling. Note: that this parameter will be internal references, do not pass the parent object of the Token object.
 *
 *	@return	Token object.
 */
///#end
- (id)initWithURLString:(NSString *)urlString
               userData:(id)userData
                 worker:(id<ICMHTTPWorker>)worker;

///#begin zh-cn
/**
 *	@brief	初始化令牌
 *
 *	@param 	request 	请求对象
 *	@param 	userData 	附加数据
 *  @param  worker      处理器，如果传入该参数则不进行默认处理。注意，此参数会在内部引用，切勿传入该Token对象的父级对象。
 *
 *	@return	令牌对象
 */
///#end
///#begin en
/**
 *	@brief	Initialize token.
 *
 *	@param 	request 	Request object.
 *	@param 	userData 	User data.
 *  @param  worker      Worker, if the parameter is not passed for default handling. Note: that this parameter will be internal references, do not pass the parent object of the Token object.
 *
 *	@return	Token object.
 */
///#end
- (id)initWithRequest:(NSMutableURLRequest *)request
             userData:(id)userData
               worker:(id<ICMHTTPWorker>)worker;

///#begin zh-cn
/**
 *	@brief	开始请求
 */
///#end
///#begin en
/**
 *	@brief	Start request.
 */
///#end
- (void)start;

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
 *	@param 	encoding 	Encoding
 *
 *	@return	Response string.
 */
///#end
- (NSString *)responseString:(NSStringEncoding)encoding;


@end

