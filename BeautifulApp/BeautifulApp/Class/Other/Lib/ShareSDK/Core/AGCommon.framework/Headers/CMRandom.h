
#import <Foundation/Foundation.h>

///#begin zh-cn
/**
 *	@brief	随机类
 */
///#end
///#begin en
/**
 *	@brief	Random
 */
///#end
@interface CMRandom : NSObject

///#begin zh-cn
/**
 *	@brief	获取随机整型值
 *
 *	@param 	maxValue 	随机最大值
 *
 *	@return	随机整数
 */
///#end
///#begin en
/**
 *	@brief	Get random integer value.
 *
 *	@param 	maxValue 	Max integer value.
 *
 *	@return	Random integer value.
 */
///#end
- (NSInteger)getIntegerValue:(NSInteger)maxValue;


@end
