
#import <Foundation/Foundation.h>

///#begin zh-cn
/**
 *	@brief	页面内容视图接口，实现此接口则可作为PageView的内容页
 */
///#end
///#begin en
/**
 *	@brief	Page content view protocol，Implement this protocol can be used as page content view.
 */
///#end
@protocol ICMPageContentView <NSObject>

@required

///#begin zh-cn
/**
 *	@brief	获取复用标识
 *
 *	@return	复用标识
 */
///#end
///#begin en
/**
 *	@brief	Get reuse identifier.
 *
 *	@return	Reuse identifier.
 */
///#end
- (NSString *)reuseIdentifier;

///#begin zh-cn
/**
 *	@brief	根据引用标识初始化
 *
 *	@param 	reuseIdentifier 	复用标识
 *  @param  frame   显示区域
 *
 *	@return	对象
 */
///#end
///#begin en
/**
 *	@brief	Initialize page content view.
 *
 *	@param 	reuseIdentifier 	Reuse identifier
 *  @param  frame   Display rect.
 *
 *	@return	Page content view object.
 */
///#end
- (id)initWithReuseIdentifier:(NSString *)reuseIdentifier frame:(CGRect)frame;

@end

