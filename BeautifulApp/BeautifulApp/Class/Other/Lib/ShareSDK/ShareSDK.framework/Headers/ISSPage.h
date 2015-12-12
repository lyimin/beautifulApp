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
 *	@brief	分页对象协议，用于获取分页数据时标识分页信息
 */
///#end
///#begin en
/**
 *	@brief	Paging info protocol，Data is used to specify which pages to get
 */
///#end
@protocol ISSPage <NSObject>

///#begin zh-cn
/**
 *	@brief	获取页码
 *
 *	@return	页码
 */
///#end
///#begin en
/**
 *	@brief	Get page No.
 *
 *	@return	Page No
 */
///#end
- (NSInteger)pageNo;

///#begin zh-cn
/**
 *	@brief	设置页码
 *
 *	@param 	pageNo 	页码
 */
///#end
///#begin en
/**
 *	@brief	Set page No.
 *
 *	@param 	pageNo 	Page No.
 */
///#end
- (void)setPageNo:(NSInteger)pageNo;

///#begin zh-cn
/**
 *	@brief	获取分页大小
 *
 *	@return	分页大小
 */
///#end
///#begin en
/**
 *	@brief	Get page size
 *
 *	@return	Page size
 */
///#end
- (NSInteger)pageSize;

///#begin zh-cn
/**
 *	@brief	设置分页大小
 *
 *	@param 	pageSize 	分页大小
 */
///#end
///#begin en
/**
 *	@brief	Set page size
 *
 *	@param 	pageSize 	Page size
 */
///#end
- (void)setPageSize:(NSInteger)pageSize;

///#begin zh-cn
/**
 *	@brief	获取分页游标
 *
 *	@return	分页游标
 */
///#end
///#begin en
/**
 *	@brief	Get cursor
 *
 *	@return	Cursor
 */
///#end
- (long long)cursor;

///#begin zh-cn
/**
 *	@brief	设置分页游标
 *
 *	@param 	cursor 	分页游标
 */
///#end
///#begin en
/**
 *	@brief	Set cursor
 *
 *	@param 	cursor 	Cursor
 */
///#end
- (void)setCursor:(long long)cursor;

@end
