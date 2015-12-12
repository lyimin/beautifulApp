//
//  SSViewDef.h
//  ShareSDK
//
//  Created by 冯 鸿杰 on 13-11-27.
//  Copyright (c) 2013年 掌淘科技. All rights reserved.
//

#ifndef ShareSDK_SSViewDef_h
#define ShareSDK_SSViewDef_h

/**
 *	@brief	获取视图宽度
 *
 *	@param 	view 	视图对象
 *
 *	@return	宽度
 */
#define SS_WIDTH(view) view.bounds.size.width

/**
 *	@brief	获取视图高度
 *
 *	@param 	view 	视图对象
 *
 *	@return	高度
 */
#define SS_HEIGHT(view) view.bounds.size.height

/**
 *	@brief	获取视图原点横坐标
 *
 *	@param 	view 	视图对象
 *
 *	@return	原点横坐标
 */
#define SS_LEFT(view) view.frame.origin.x

/**
 *	@brief	获取视图原点纵坐标
 *
 *	@param 	view 	视图对象
 *
 *	@return	原点纵坐标
 */
#define SS_TOP(view) view.frame.origin.y

/**
 *	@brief	获取视图右下角横坐标
 *
 *	@param 	view 	视图对象
 *
 *	@return	右下角横坐标
 */
#define SS_RIGHT(view) (SS_LEFT(view) + SS_WIDTH(view))

/**
 *	@brief	获取视图右下角纵坐标
 *
 *	@param 	view 	视图对象
 *
 *	@return	右下角纵坐标
 */
#define SS_BOTTOM(view) (SS_TOP(view) + SS_HEIGHT(view))


#endif
