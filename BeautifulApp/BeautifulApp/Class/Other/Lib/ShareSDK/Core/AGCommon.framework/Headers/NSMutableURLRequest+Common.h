
#import <Foundation/Foundation.h>

@interface NSMutableURLRequest (Common)

/**
 *	@brief	设置提交形式为multipart
 *
 *	@return	boundary字符串
 */
- (NSString *)multipartPost;

@end
