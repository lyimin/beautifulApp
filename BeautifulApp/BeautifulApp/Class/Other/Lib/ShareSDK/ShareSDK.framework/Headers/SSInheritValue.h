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
 *	@brief	继承值对象，用于标识取值是否继承父级对象
 */
///#end
///#begin en
/**
 *	@brief	Inherit value，The value used to identify whether an object inherits the parent
 */
///#end
@interface SSInheritValue : NSObject
{
@private
    NSString *_name;
}

///#begin zh-cn
/**
 *	@brief	名称
 */
///#end
///#begin en
/**
 *	@brief	Name
 */
///#end
@property (nonatomic,readonly) NSString *name;

///#begin zh-cn
/**
 *	@brief	初始化继承值对象
 *
 *	@param 	name 	名称，制定继承对象的某个属性名称
 *
 *	@return	继承值对象
 */
///#end
///#begin en
/**
 *	@brief	Initialize Inherit value object.
 *
 *	@param 	name 	Name，Specify the name of a property inherited object.
 *
 *	@return	Inherit value object.
 */
///#end
- (id)initWithName:(NSString *)name;

///#begin zh-cn
/**
 *	@brief	创建继承值对象
 *
 *	@return	继承值对象
 */
///#end
///#begin en
/**
 *	@brief	Create an Inherit value object.
 *
 *	@return	Inherit value object.
 */
///#end
+ (id)inherit;

///#begin zh-cn
/**
 *	@brief	创建继承值对象
 *
 *	@param 	name 	名称，指定继承对象的某个值名称。
 *
 *	@return	继承值对象
 */
///#end
///#begin en
/**
 *	@brief	Create inherit value object.
 *
 *	@param 	name 	Name，Specify the name of a property inherited object.
 *
 *	@return	Inherit value object.
 */
///#end
+ (id)inheritWithName:(NSString *)name;


@end
