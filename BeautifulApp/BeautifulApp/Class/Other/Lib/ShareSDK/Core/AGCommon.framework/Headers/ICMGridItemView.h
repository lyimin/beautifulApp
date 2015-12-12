
#import <Foundation/Foundation.h>

///#begin zh-cn
/**
	表格项接口，所有在ZGGridView中显示的项目都需要实现此接口.
 */
///#end
///#begin en
/**
 *	@brief	Grid Item View protocol. All display item in Gridview must be implement this protocol 
 */
///#end
@protocol ICMGridItemView <NSObject>

@required

///#begin zh-cn
/**
 *	@brief	获取数据.
 *
 *	@return	数据对象.
 */
///#end
///#begin en
/**
 *	@brief	Get data.
 *
 *	@return	Data object.
 */
///#end
- (id)data;


///#begin zh-cn
/**
 *	@brief	设置数据.
 *
 *	@param 	data 	数据对象.
 */
///#end
///#begin en
/**
 *	@brief	Set data.
 *
 *	@param 	data 	Data object.
 */
///#end
- (void)setData:(id)data;


///#begin zh-cn
/**
 *	@brief	获取索引
 *
 *	@return	索引值
 */
///#end
///#begin en
/**
 *	@brief	Get index.
 *
 *	@return	Index.
 */
///#end
- (NSInteger)index;

///#begin zh-cn
/**
 *	@brief	设置索引
 *
 *	@param 	index 	索引值
 */
///#end
///#begin en
/**
 *	@brief	Set index
 *
 *	@param 	index 	Index
 */
///#end
- (void)setIndex:(NSInteger)index;

@end
