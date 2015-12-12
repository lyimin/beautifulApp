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
 *	@brief	分享信息协议
 */
///#end
///#begin en
/**
 *	@brief	Share info protocol
 */
///#end
@protocol ISSPlatformShareInfo <NSObject>

@required

///#begin zh-cn
/**
 *	@brief	获取分享信息的原始数据,与各平台定义结构一致
 *
 *	@return	原始数据
 */
///#end
///#begin en
/**
 *	@brief	Get sharing raw data, define the structure consistent with the platform
 *
 *	@return	Raw data dicationary.
 */
///#end
- (NSDictionary *)sourceData;

///#begin zh-cn
/**
 *	@brief	获取分享信息标识
 *
 *	@return	分享信息标识
 */
///#end
///#begin en
/**
 *	@brief	Get share info id.
 *
 *	@return	Share info id.
 */
///#end
- (NSString *)sid;

///#begin zh-cn
/**
 *	@brief	获取分享内容
 *
 *	@return	分享内容
 */
///#end
///#begin en
/**
 *	@brief	Get share content.
 *
 *	@return	Content string.
 */
///#end
- (NSString *)text;

///#begin zh-cn
/**
 *	@brief	获取分享的链接列表
 *
 *	@return	链接列表数组
 */
///#end
///#begin en
/**
 *	@brief	Get a list of url.
 *
 *	@return	urls list array.
 */
///#end
- (NSArray *)urls;

///#begin zh-cn
/**
 *	@brief	获取分享的图片列表
 *
 *	@return	图片列表数组
 */
///#end
///#begin en
/**
 *	@brief	Get a list of image
 *
 *	@return	Images list array.
 */
///#end
- (NSArray *)imgs;

///#begin zh-cn
/**
 *	@brief	获取扩展信息
 *
 *	@return	扩展信息
 */
///#end
///#begin en
/**
 *	@brief	Get extended Information.
 *
 *	@return	Extended Information
 */
///#end
- (NSDictionary *)extInfo;

@end
