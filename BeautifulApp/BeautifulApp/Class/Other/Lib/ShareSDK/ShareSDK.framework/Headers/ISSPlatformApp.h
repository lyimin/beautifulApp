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
#import "ISSContent.h"

@protocol ISSPlatform;
@protocol ISSPlatformUser;
@protocol ISSPlatformCredential;
@protocol ISSPlatformShareInfo;
@protocol ISSPlatformShareContentEntity;
@protocol ISSPlatformAuthSession;

///#begin zh-cn
/**
 *	@brief	获取用户信息返回事件
 */
///#end
///#begin en
/**
 *	@brief	Get user info result event.
 */
///#end
typedef void(^SSGetUserInfoResultEvent) (SSResponseState state, id<ISSPlatformUser> user, CMErrorInfo *error);

///#begin zh-cn
/**
 *	@brief	添加好友返回事件
 */
///#end
///#begin en
/**
 *	@brief	Add friend result event.
 */
///#end
typedef void(^SSAddFriendResultEvent) (SSResponseState state, id<ISSPlatformUser> user, CMErrorInfo *error);

///#begin zh-cn
/**
 *	@brief	获取好友列表返回事件
 */
///#end
///#begin en
/**
 *	@brief	Get friends list result event
 */
///#end
typedef void(^SSFriendsResultEvent) (SSResponseState state, NSArray *users, long long curr, long long prev, long long next, BOOL hasNext, NSDictionary *extInfo, id<ICMErrorInfo> error);

///#begin zh-cn
/**
 *	@brief	分享返回事件
 */
///#end
///#begin en
/**
 *	@brief	Share result event
 */
///#end
typedef void(^SSShareResultEvent) (SSResponseState state, id<ISSPlatformShareInfo> status, CMErrorInfo *error);

///#begin zh-cn
/**
 *	@brief	请求方式
 */
///#end
///#begin en
/**
 *	@brief	Request method
 */
///#end
typedef enum
{
    SSCallAPIRequestMethodGet = 0, /**< GET方式 */
    SSCallAPIRequestMethodPost = 1, /**< POST方式 */
    SSCallAPIRequestMethodMultipartPost = 2, /**< Multipart POST方式，用于上传文件的api接口 */
    SSCallAPIRequestMethodDelete = 3/**< DELETE方式 */
}
SSCallAPIRequestMethod;

///#begin zh-cn
/**
 *	@brief	平台应用信息协议
 */
///#end
///#begin en
/**
 *	@brief	App protocol
 */
///#end
@protocol ISSPlatformApp <NSObject>

@required

///#begin zh-cn
/**
 *	@brief	获取ShareSDK注册账户信息
 *
 *	@return	ShareSDK注册账户信息
 */
///#end
///#begin en
/**
 *	@brief	Get ShareSDK registered app information
 *
 *	@return	App information
 */
///#end
- (id<ISSCAccount>)account;

///#begin zh-cn
/**
 *	@brief	获取应用所属平台
 *
 *	@return	平台信息对象
 */
///#end
///#begin en
/**
 *	@brief	Get an app platform
 *
 *	@return	Platform object.
 */
///#end
- (id<ISSPlatform>)platform;

///#begin zh-cn
/**
 *	@brief	获取应用标识
 *
 *	@return	应用标识
 */
///#end
///#begin en
/**
 *	@brief	Get app key
 *
 *	@return	App key.
 */
///#end
- (NSString *)key;

///#begin zh-cn
/**
 *	@brief	获取应用密钥
 *
 *	@return	应用密钥
 */
///#end
///#begin en
/**
 *	@brief	Get app secret
 *
 *	@return	App secret.
 */
///#end
- (NSString *)secret;

///#begin zh-cn
/**
 *	@brief	获取应用所属平台类型
 *
 *	@return	平台类型
 */
///#end
///#begin en
/**
 *	@brief	Get an app platform type
 *
 *	@return	Platform type
 */
///#end
- (ShareType)type;

///#begin zh-cn
/**
 *	@brief	判断是否安装客户端
 *
 *	@return	YES 表示已安装，NO 表示尚未安装
 */
///#end
///#begin en
/**
 *	@brief	Determine whether to install the client
 *
 *	@return	YES means is installed, NO represents yet installed
 */
///#end
- (BOOL)isClientInstalled;

///#begin zh-cn
/**
 *	@brief	获取是否支持一键分享功能标识,如果为YES则表示可以打开内容编辑界面并与其他平台一起进行分享。
 *
 *	@return	YES 表示支持，NO 表示不支持
 */
///#end
///#begin en
/**
 *	@brief	Get whether to support a key sharing identity. If YES indicates the content editing interface can be opened and share it with other platforms.
 *
 *	@return	YES indicate support，NO indicate not support
 */
///#end
- (BOOL)isSupportOneKeyShare;

/**
 *  更新应用信息
 *
 *  @param appInfo 应用数据
 *  @param isServerConfig 是否使用服务器配置信息
 */
///#begin zh-cn
/**
 *	@brief	更新应用信息
 *
 *	@param appInfo 应用数据
 */
///#end
///#begin en
/**
 *	@brief	update the app infomation of social platform
 *
 *	@param appInfo the app infomation
 *  @param isServerConfig  YES means use the server configuration
 */
///#end
- (void)updateInfo:(NSDictionary *)appInfo isServerConfig:(BOOL)isServerConfig;

///#begin zh-cn
/**
 *	@brief	获取分享时是否需要进行授权，如果为YES则在分享时需要检测用户是否已经授权，尚未授权则需要进行授权。
 *          对于使用客户端进行分享的平台此属性一般返回NO
 *
 *  @param  clientShare 客户端分享标识，为YES表示优先使用客户端进行分享。
 *
 *	@return	YES 表示需要， NO 表示不需要
 */
///#end
///#begin en
/**
 *	@brief	The need for obtaining authorization to share.If YES then you need to detect whether sharing user has authorized.Not yet authorized the need for authorization. For client platforms to share this property generally returns NO
 *
 *  @param  clientShare Sharing client identity，YES indicates priority for the client to share.
 *
 *	@return	YES indicates need, NO indicates that no
 */
///#end
- (BOOL)isSharingNeedAuthWithClientShare:(BOOL)clientShare;

///#begin zh-cn
/**
 *	@brief	获取当前用户
 *
 *	@return	用户信息
 */
///#end
///#begin en
/**
 *	@brief	Get current user
 *
 *	@return	User info
 */
///#end
- (id<ISSPlatformUser>)currentUser;

///#begin zh-cn
/**
 *	@brief	设置当前用户
 *
 *	@param 	currentUser 	用户信息
 */
///#end
///#begin en
/**
 *	@brief	Set current user
 *
 *	@param 	currentUser 	User info
 */
///#end
- (void)setCurrentUser:(id<ISSPlatformUser>)currentUser;

///#begin zh-cn
/**
 *	@brief	获取是否转换链接使能状态
 *
 *	@return	使能状态，YES 表示在分享前需要转换链接，NO 表示不转换链接
 */
///#end
///#begin en
/**
 *	@brief	Get whether to convert the link enabled
 *
 *	@return	YES indicates need convert link before sharing, NO indicates no conversion link
 */
///#end
- (BOOL)convertUrlEnabled;

///#begin zh-cn
/**
 *	@brief	获取SSO授权使能状态
 *
 *	@return	YES 表示允许优先使用SSO进行授权，NO 表示不允许SSO授权
 */
///#end
///#begin en
/**
 *	@brief	Get SSO authorized enabled.
 *
 *	@return	YES indicates allowing SSO priority for authorization, NO indicates disable use SSO authorization
 */
///#end
- (BOOL)ssoEnabled;

///#begin zh-cn
/**
 *	@brief	设置SSO授权使能状态
 *
 *	@param 	enabled 	YES 表示允许优先使用SSO进行授权，NO 表示不允许SSO授权
 */
///#end
///#begin en
/**
 *	@brief	Set SSO authorized enabled
 *
 *	@param 	enabled 	YES indicates allowing SSO priority for authorization, NO indicates disable use SSO authorization
 */
///#end
- (void)setSsoEnabled:(BOOL)enabled;

///#begin zh-cn
/**
 *	@brief	创建授权凭证
 *
 *	@param 	uid 	授权用户标识
 *	@param 	token 	访问令牌，在OAuth中为oauth_token，在OAuth2中为access_token
 *	@param 	secret 	访问令牌密钥，仅用于OAuth授权中，为oauth_token_secret。
 *	@param 	expired 	过期时间，仅用于OAuth2授权中，需要将返回的秒数转换为时间。
 *	@param 	extInfo 	扩展信息。用于存放除上述信息外的其它信息。
 *
 *	@return	授权凭证
 */
///#end
///#begin en
/**
 *	@brief	Create an authorized credential object
 *
 *	@param 	uid 	User id
 *	@param 	token 	In OAuth, is oauth_token. In OAuth2, is access_token.
 *	@param 	secret 	Token secret，Only for OAuth authorization is oauth_token_secret.
 *	@param 	expired 	Expiration time, only for OAuth2 authorization, you need to return to a time in seconds.
 *	@param 	extInfo 	Extended information. Used to store other information in addition to the above information away.
 *
 *	@return	Credential object.
 */
///#end
- (id<ISSPlatformCredential>)credentialWithUid:(NSString *)uid
                                         token:(NSString *)token
                                        secret:(NSString *)secret
                                       expired:(NSDate *)expired
                                       extInfo:(NSDictionary *)extInfo;

///#begin zh-cn
/**
 *	@brief	通过授权凭证来创建用户
 *
 *	@param 	credential 	授权凭证
 *
 *	@return	用户信息对象
 */
///#end
///#begin en
/**
 *	@brief	To create a user through authorized credential
 *
 *	@param 	credential 	Credential
 *
 *	@return	User object.
 */
///#end
- (id<ISSPlatformUser>)userWithCredential:(id<ISSPlatformCredential>)credential;

///#begin zh-cn
/**
 *	@brief	通过用户的原始数据来创建用户
 *
 *	@param 	data 	原始数据，与各个平台中的用户结构定义相同
 *
 *	@return	用户信息对象
 */
///#end
///#begin en
/**
 *	@brief	To create a user through the user's raw data
 *
 *	@param 	data 	Raw data. Platform users the same structure definition
 *
 *	@return	User object.
 */
///#end
- (id<ISSPlatformUser>)userWithData:(NSDictionary *)data;

///#begin zh-cn
/**
 *	@brief	通过原始数据来创建分享信息
 *
 *	@param 	data 	原始数据，与各个平台中的分享信息结构一致
 *
 *	@return	分享信息对象
 */
///#end
///#begin en
/**
 *	@brief	To create a share info through the raw data
 *
 *	@param 	data 	Raw data. Platform share info the same structure definition
 *
 *	@return	Share info.
 */
///#end
- (id<ISSPlatformShareInfo>)shareInfoWithData:(NSDictionary *)data;

///#begin zh-cn
/**
 *	@brief	对用户进行授权。
 *
 *	@return	授权会话，返回nil则表示该平台不支持授权功能
 */
///#end
///#begin en
/**
 *	@brief	To authorize.
 *
 *	@return	Authorized session，Returns nil indicates that the platform does not support the authorization
 */
///#end
- (id<ISSPlatformAuthSession>)authorize;

///#begin zh-cn
/**
 *	@brief	注册用户
 *
 *	@param 	user 	用户信息
 *
 *	@return	YES 表示注册成功， NO 表示注册失败
 */
///#end
///#begin en
/**
 *	@brief	Register user.
 *
 *	@param 	user 	User object.
 *
 *	@return	YES indicates the registration is successful, NO indicates registration failure
 */
///#end
- (BOOL)registerUser:(id<ISSPlatformUser>)user;

///#begin zh-cn
/**
 *	@brief	注销用户
 *
 *	@param 	user 	用户信息
 *
 *	@return	YES 表示注销成功， NO 表示注销失败
 */
///#end
///#begin en
/**
 *	@brief	Unregister user.
 *
 *	@param 	user 	User object.
 *
 *	@return	YES indicates the unregistration is successful, NO indicates unregistration failure
 */
///#end
- (BOOL)unregisterUser:(id<ISSPlatformUser>)user;

///#begin zh-cn
/**
 *	@brief	获取已注册的用户列表
 *
 *	@return	用户列表数组，其元素为id<ISSPlatformUser>对象
 */
///#end
///#begin en
/**
 *	@brief	Get a list of registered users.
 *
 *	@return	Users list array，whose elements are the object id<ISSPlatformUser>
 */
///#end
- (NSArray *)registeredUsers;

///#begin zh-cn
/**
 *	@brief	获取注册用户
 *
 *	@param 	uid 	用户标识
 *
 *	@return	用户信息
 */
///#end
///#begin en
/**
 *	@brief	Get a registered user.
 *
 *	@param 	uid 	User id.
 *
 *	@return	User object.
 */
///#end
- (id<ISSPlatformUser>)registeredUserForUid:(NSString *)uid;

///#begin zh-cn
/**
 *	@brief	检测用户是否需要重新授权
 *
 *	@param 	error 	错误信息
 *
 *	@return	YES 表示需要重新授权，NO 表示不需要重新授权
 */
///#end
///#begin en
/**
 *	@brief	Detecting whether the user needs to re-authorize.
 *
 *	@param 	error 	Error info.
 *
 *	@return	YES indicates need for re-authorization, NO indicates that no re-authorization
 */
///#end
- (BOOL)checkNeedReAuth:(id<ICMErrorInfo>)error;

///#begin zh-cn
/**
 *	@brief	判断是否为用户级别错误，此级别错误可以显示给操作用户查看
 *
 *	@param 	error 	错误信息
 *
 *	@return	YES 表示是用户级别错误，NO 表示不是。
 */
///#end
///#begin en
/**
 *	@brief	Determine whether the user-level error, this error can be displayed to the users
 *
 *	@param 	error 	Error info.
 *
 *	@return	YES indicates a user-level error, NO if not.
 */
///#end
- (BOOL)isUserError:(id<ICMErrorInfo>)error;

///#begin zh-cn
/**
 *	@brief	获取授权用户信息
 *
 *  @param  resultHandler   返回回调处理
 */
///#end
///#begin en
/**
 *	@brief	Get authorized user object.
 *
 *  @param  resultHandler   Result handler
 */
///#end
- (void)getAuthUserInfo:(SSGetUserInfoResultEvent)resultHandler;

///#begin zh-cn
/**
 *	@brief	获取授权用户信息
 *
 *	@param 	uid 	用户标识, 根据用户标识来查找用户信息，参数优先级别最高
 *	@param 	name 	用户名称，根据用户名称来查找用户信息，参数优先级别仅次于用户标识
 *	@param 	url 	用户主页路径，根据用户主页路径查找用户信息，参数优先级别最低
 *  @param  resultHandler   返回回调处理
 */
///#end
///#begin en
/**
 *	@brief	Get user info.
 *
 *	@param 	uid 	User ID. Based on user identity to find user information. Parameters highest priority
 *	@param 	name 	User name. Based on the user name to find the user information. Parameters priority second only to the user identity
 *	@param 	url 	User home path. Based on the user home path to find the user information. Parameters lowest priority
 *  @param  resultHandler   Result handler
 */
///#end
- (void)getUserInfoWithUid:(NSString *)uid
                    orName:(NSString *)name
                     orUrl:(NSString *)url
             resultHandler:(SSGetUserInfoResultEvent)resultHandler;

///#begin zh-cn
/**
 *	@brief	添加好友/关注用户
 *
 *	@param 	uid 	用户标识
 *	@param 	name 	用户名称
 *  @param  url     用户路径(仅用于微信关注)
 *  @param  resultHandler   返回回调处理
 */
///#end
///#begin en
/**
 *	@brief	Add Friend / concerns Users
 *
 *	@param 	uid 	User Id.
 *	@param 	name 	User name.
 *  @param  url     User path (only for WeChat concerned)
 *  @param  resultHandler   Result handler
 */
///#end
- (void)addFriendWithUid:(NSString *)uid
                  orName:(NSString *)name
                   orUrl:(NSString *)url
           resultHandler:(SSAddFriendResultEvent)resultHandler;

///#begin zh-cn
/**
 *	@brief	获取好友列表
 *
 *	@param 	cursor 	游标位置
 *	@param 	count 	数量
 *	@param 	resultHandler 	返回回调处理
 */
///#end
///#begin en
/**
 *	@brief	Get friends list
 *
 *	@param 	cursor 	Cursor
 *	@param 	count 	Friends quantity
 *	@param 	resultHandler 	Result handler
 */
///#end
- (void)friendsWithCursor:(long long)cursor
                  count:(NSInteger)count
          resultHandler:(SSFriendsResultEvent)resultHandler;

///#begin zh-cn
/**
 *	@brief	分享内容
 *
 *	@param 	contentEntity 	分享内容实体
 *  @param  clientShare     客户端分享标识，YES 表示使用客户端进行内容分享。否则直接应用内分享。
 *	@param 	resultHandler 	返回回调处理
 */
///#end
///#begin en
/**
 *	@brief	Share content
 *
 *	@param 	contentEntity 	Share content entity
 *  @param  clientShare     Sharing client flag, YES indicates share content by client. Otherwise, the sharing in app.
 *	@param 	resultHandler 	Result handler
 */
///#end
- (void)shareContent:(id<ISSPlatformShareContentEntity>)contentEntity
         clientShare:(BOOL)clientShare
       resultHandler:(SSShareResultEvent)resultHandler;

///#begin zh-cn
/**
 *	@brief	通过一个字典类型来构造一个分享内容实体对象
 *
 *	@param 	dictonary 	字典结构数据
 *
 *	@return	分享内容实体对象
 */
///#end
///#begin en
/**
 *	@brief	Through a dictionary type to construct a share content entity.
 *
 *	@param 	dictonary 	Dicationary data.
 *
 *	@return	Share content entity.
 */
///#end
- (id<ISSPlatformShareContentEntity>)shareContentEntityWithDictonary:(NSDictionary *)dictonary;

///#begin zh-cn
/**
 *	@brief	将分享内容转换为平台的分享内容实体，在此方法中需要对分享实体中的描述值对象进行转换。
 *
 *	@param 	content 	分享内容
 *
 *	@return	分享内容实体对象
 */
///#end
///#begin en
/**
 *	@brief	Convert share content to share entity。In this method, Attributes of the entity needs to be converted.
 *
 *	@param 	content 	Share content object
 *
 *	@return	Share content entity object
 */
///#end
- (id<ISSPlatformShareContentEntity>)convertShareContentEntityByContent:(id<ISSContent>)content;

///#begin zh-cn
/**
 *	@brief	处理请求打开链接
 *
 *	@param 	url 	链接
 *	@param 	sourceApplication 	源应用
 *	@param 	annotation 	源应用提供的信息
 *
 *	@return	YES 表示接受请求，NO 表示不接受请求
 */
///#end
///#begin en
/**
 *	@brief	Handle open url.
 *
 *	@param 	url 	url object
 *	@param 	sourceApplication 	source application
 *	@param 	annotation 	annotation
 *
 *	@return	YES indicates to accept the request, NO indicates did not accept the request
 */
///#end
- (BOOL)handleOpenURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;
/**
 *	@brief	调用开放平台API
 *
 *	@param 	path 	路径
 *  @param  method  请求方式
 *	@param 	params 	请求参数
 *  @param  user    授权用户,如果传入nil则表示默认的授权用户
 *  @param  result  返回回调
 *  @param  fault   失败回调
 */
///#end
///#begin en
/**
 *	@brief	Call API
 *
 *	@param 	path 	API path.
 *  @param  method  Request method.
 *	@param 	params 	Request parameters.
 *  @param  user    Authorized users, it means that if the incoming nil default authorized users
 *  @param  result  Result handler.
 *  @param  fault   Fault handler.
 */
///#end
- (void)api:(NSString *)path
     method:(SSCallAPIRequestMethod)method
     params:(id<ISSCParameters>)params
       user:(id<ISSPlatformUser>)user
     result:(void(^)(id responder))result
      fault:(void(^)(CMErrorInfo *error))fault;

@end
