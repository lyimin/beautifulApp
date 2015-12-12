
#import <Foundation/Foundation.h>

///#begin zh-cn
/**
 *	@brief	水平排版表格列表项
 */
///#end
///#begin en
/**
 *	@brief	Horizontal Table View Item
 */
///#end
@protocol ICMHTableViewItem <NSObject>

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
 *	@brief	获取位置索引
 *
 *	@return	位置索引
 */
///#end
///#begin en
/**
 *	@brief	Get index path.
 *
 *	@return	Index path.
 */
///#end
- (NSIndexPath *)indexPath;

///#begin zh-cn
/**
 *	@brief	设置位置索引
 *
 *	@param 	indexPath 	位置索引
 */
///#end
///#begin en
/**
 *	@brief	Set index path
 *
 *	@param 	indexPath 	Index path.
 */
///#end
- (void)setIndexPath:(NSIndexPath *)indexPath;

///#begin zh-cn
/**
 *	@brief	根据引用标识初始化
 *
 *	@param 	reuseIdentifier 	复用标识
 *
 *	@return	对象
 */
///#end
///#begin en
/**
 *	@brief	Initialize table view item.
 *
 *	@param 	reuseIdentifier 	Reuse identifier.
 *
 *	@return	Item view.
 */
///#end
- (id)initWithReuseIdentifier:(NSString *)reuseIdentifier;



@end
