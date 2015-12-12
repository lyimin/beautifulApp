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

#import "SSInheritValue.h"

#ifndef ShareSDKInterface_ShareSDKDef_h
#define ShareSDKInterface_ShareSDKDef_h

///#begin zh-cn
/**
 *	@brief	将ShareType转换为NSNumber类型
 *
 *	@param 	type 	分享平台类型
 */
///#end
///#begin en
/**
 *	@brief	The ShareType convert NSNumber type
 *
 *	@param 	type 	Platform type.
 */
///#end
#define SHARE_TYPE_NUMBER(type) [NSNumber numberWithInteger:type]

///#begin zh-cn
/**
 *	@brief	继承值
 */
///#end
///#begin en
/**
 *	@brief	Inherit value object.
 */
///#end
#define INHERIT_VALUE [SSInheritValue inherit]

///#begin zh-cn
/**
 *	@brief	映射分享内容对象的某个属性值
 *
 *	@param 	name 	属性名称
 */
///#end
///#begin en
/**
 *	@brief	Mapping a share content object Property values
 *
 *	@param 	name 	Property name.
 */
///#end
#define MAPPING_VALUE(name) [SSInheritValue inheritWithName:name]

///#begin zh-cn
/**
 *	@brief	获取金币通知
 */
///#end
///#begin en
/**
 *	@brief	Get Coins Notification.
 */
///#end
#define SS_AWARD_NOTIF_GET_COINS @"get_coins"

///#begin zh-cn
/**
 *	@brief	购买物品通知
 */
///#end
///#begin en
/**
 *	@brief	Buy item notification
 */
///#end
#define SS_AWARD_NOTIF_BUY_ITEM @"buy_item"

///#begin zh-cn
/**
 *	@brief	金币键名
 */
///#end
///#begin en
/**
 *	@brief	Coins Key
 */
///#end
#define SS_AWARD_KEY_COINS @"coins"

///#begin zh-cn
/**
 *	@brief	行为键名
 */
///#end
///#begin en
/**
 *	@brief	Action Key
 */
///#end
#define SS_AWARD_KEY_ACTION @"action"


#endif
