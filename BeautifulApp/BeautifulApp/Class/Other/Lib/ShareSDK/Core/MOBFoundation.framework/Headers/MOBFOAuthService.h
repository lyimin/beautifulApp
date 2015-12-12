//
//  MOBFOAuthService.h
//  MOBFoundation
//
//  Created by fenghj on 15/6/9.
//  Copyright (c) 2015年 MOB. All rights reserved.
//

#import <MOBFoundation/MOBFoundation.h>

/**
 *  OAuth服务
 */
@interface MOBFOAuthService : MOBFHttpService

/**
 *  发送HTTP请求
 *
 *  @param urlString             请求地址
 *  @param method                请求方式
 *  @param parameters            请求参数
 *  @param headers               请求头集合
 *  @param oauthParameters       OAuth请求参数
 *  @param consumerSecret        消费者密钥
 *  @param oauthSecret           OAuth令牌密钥
 *  @param resultHandler         返回回调
 *  @param faultHandler          错误回调
 *  @param uploadProgressHandler 上传数据进度回调
 *
 *  @return HTTP服务对象
 */
+ (MOBFOAuthService *)sendRequestByURLString:(NSString *)urlString
                                      method:(NSString *)method
                                  parameters:(NSDictionary *)parameters
                                     headers:(NSDictionary *)headers
                             oauthParameters:(NSDictionary *)oauthParameters
                              consumerSecret:(NSString *)consumerSecret
                            oauthTokenSecret:(NSString *)oauthTokenSecret
                                    onResult:(MOBFHttpResultEvent)resultHandler
                                     onFault:(MOBFHttpFaultEvent)faultHandler
                            onUploadProgress:(MOBFHttpUploadProgressEvent)uploadProgressHandler;

@end
