//
//  SSWeChatShareInfo.h
//  WeChatConnection
//
//  Created by 冯 鸿杰 on 13-11-29.
//  Copyright (c) 2013年 掌淘科技. All rights reserved.
//

#ifndef WeChatConnection_SSWeChatTypeDef_h
#define WeChatConnection_SSWeChatTypeDef_h

///#begin zh-cn
/**
 *	@brief	微信类型
 */
///#end
///#begin en
/**
 *	@brief	WeChat type.
 */
///#end
typedef enum
{
	SSWeChatSceneSession = 0,   /**< 好友 */
	SSWeChatSceneTimeline = 1 , /**< 朋友圈 */
    SSWeChatSceneFav = 2        /**< 收藏 */
}
SSWeChatScene;

#endif
