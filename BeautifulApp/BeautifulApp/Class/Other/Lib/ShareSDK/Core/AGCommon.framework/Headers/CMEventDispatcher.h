
#import <Foundation/Foundation.h>

///#begin zh-cn
/**
 *	@brief	事件派发器
 */
///#end
///#begin en
/**
 *	@brief	Event Dispatcher.
 */
///#end
@interface CMEventDispatcher : NSObject
{
@private
	NSNotificationCenter *_handle;
}

///#begin zh-cn
/**
 *	@brief	添加通知监听
 *
 *	@param 	name 	通知名称
 *	@param 	target 	监听目标
 *	@param 	action 	监听处理
 */
///#end
///#begin en
/**
 *	@brief	Add notification listener.
 *
 *	@param 	name 	Name.
 *	@param 	target 	Target object.
 *	@param 	action 	Trigger action.
 */
///#end
- (void)addNotificationWithName:(NSString *)name
                         target:(id)target
                         action:(SEL)action;

///#begin zh-cn
/**
 *	@brief	移除通知监听
 *
 *	@param 	name 	通知名称
 *	@param 	target 	监听目标
 */
///#end
///#begin en
/**
 *	@brief	Remove a notification.
 *
 *	@param 	name 	Name.
 *	@param 	target 	Target.
 */
///#end
- (void)removeNotificationWithName:(NSString *)name
                            target:(id)target;

///#begin zh-cn
/**
 *	@brief	移除某个监听目标的所有通知
 *
 *	@param 	target 	监听目标
 */
///#end
///#begin en
/**
 *	@brief	Remove all notification of target
 *
 *	@param 	target 	Target object.
 */
///#end
- (void)removeAllNotificationWithTarget:(id)target;

///#begin zh-cn
/**
 *	@brief	派发通知
 *
 *	@param 	name 	通知名称
 *	@param 	data 	通知数据
 */
///#end
///#begin en
/**
 *	@brief	Post a notification.
 *
 *	@param 	name 	Name.
 *	@param 	data 	Data.
 */
///#end
- (void)postNotificationWithName:(NSString *)name
                            data:(NSDictionary *)data;

@end
