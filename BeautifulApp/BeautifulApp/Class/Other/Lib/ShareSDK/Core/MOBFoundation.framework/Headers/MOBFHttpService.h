//
//  MOBFHttpService.h
//  MOBFoundation
//
//  Created by vimfung on 15-1-20.
//  Copyright (c) 2015年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MOBFHttpService;

/**
 *  GET方式
 */
extern NSString *const kMOBFHttpMethodGet;

/**
 *  POST方式
 */
extern NSString *const kMOBFHttpMethodPost;

/**
 *  DELETE方式
 */
extern NSString *const kMOBFHttpMethodDelete;

/**
 *  HEAD方式
 */
extern NSString *const kMOBFHttpMethodHead;

/**
 *  HTTP返回事件
 *
 *  @param response     回复对象
 *  @param responseData 回复数据
 */
typedef void(^MOBFHttpResultEvent) (NSHTTPURLResponse *response, NSData *responseData);

/**
 *  HTTP错误事件
 *
 *  @param error 错误信息
 */
typedef void(^MOBFHttpFaultEvent) (NSError *error);

/**
 *  HTTP上传数据事件
 *
 *  @param totalBytes  总字节数
 *  @param loadedBytes 上传字节数据
 */
typedef void(^MOBFHttpUploadProgressEvent) (NSInteger totalBytes, NSInteger loadedBytes);

/**
 *  HTTP服务类
 */
@interface MOBFHttpService : NSObject

/**
 *	@brief	提交方式，默认为GET
 */
@property (nonatomic, copy) NSString *method;

/**
 *	@brief	是否缓存回复对象，默认为YES
 */
@property (nonatomic) BOOL isCacheResponse;

/**
 *  自动填充请求表单，默认为YES，如果为NO则表示使用自定义的方式发起请求。
 */
@property (nonatomic) BOOL autoFillRequestForm;

/**
 *  初始化HTTP服务
 *
 *  @param urlString URL地址字符串
 *
 *  @return HTTP服务对象
 */
- (id)initWithURLString:(NSString *)urlString;

/**
 *  初始化HTTP服务
 *
 *  @param URL URL地址对象
 *
 *  @return HTTP服务对象
 */
- (id)initWithURL:(NSURL *)URL;

/**
 *  初始化HTTP服务
 *
 *  @param request 请求对象
 *
 *  @return HTTP服务对象
 */
- (id)initWithRequest:(NSURLRequest *)request;

/**
 *  添加HTTP头
 *
 *  @param header 名称
 *  @param value  值
 */
- (void)addHeader:(NSString *)header value:(NSString *)value;

/**
 *  添加参数
 *
 *  @param value 参数值
 *  @param key   参数名字
 */
- (void)addParameter:(id)value forKey:(NSString *)key;

/**
 *  添加上传文件参数
 *
 *  @param fileData         文件数据
 *  @param fileName         文件名称
 *  @param mimeType         MIME类型
 *  @param transferEncoding 传输编码
 *  @param key              参数名字
 */
- (void)addFileParameter:(NSData *)fileData
                fileName:(NSString *)fileName
                mimeType:(NSString *)mimeType
        transferEncoding:(NSString *)transferEncoding
                  forKey:(NSString *)key;

/**
 *  发送请求
 *
 *  @param resultHandler         返回回调
 *  @param faultHandler          错误回调
 *  @param uploadProgressHandler 上传数据进度回调
 */
- (void)sendRequestOnResult:(MOBFHttpResultEvent)resultHandler
                    onFault:(MOBFHttpFaultEvent)faultHandler
           onUploadProgress:(MOBFHttpUploadProgressEvent)uploadProgressHandler;

/**
 *  取消请求
 */
- (void)cancelRequest;

/**
 *  发送HTTP请求
 *
 *  @param urlString             请求地址
 *  @param method                请求方式
 *  @param parameters            请求参数
 *  @param headers               请求头集合
 *  @param resultHandler         返回回调
 *  @param faultHandler          错误回调
 *  @param uploadProgressHandler 上传数据进度回调
 *
 *  @return HTTP服务对象
 */
+ (MOBFHttpService *)sendHttpRequestByURLString:(NSString *)urlString
                                         method:(NSString *)method
                                     parameters:(NSDictionary *)parameters
                                        headers:(NSDictionary *)headers
                                       onResult:(MOBFHttpResultEvent)resultHandler
                                        onFault:(MOBFHttpFaultEvent)faultHandler
                               onUploadProgress:(MOBFHttpUploadProgressEvent)uploadProgressHandler;


@end
