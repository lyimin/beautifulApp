
#import <UIKit/UIKit.h>
#import "ICMHTableViewItem.h"

@class CMHTableView;

///#begin zh-cn
/**
 *	@brief	水平排版表格数据源
 */
///#end
///#begin en
/**
 *	@brief	Horizontal table view data source.
 */
///#end
@protocol CMHTableViewDataSource <NSObject>

@required

///#begin zh-cn
/**
 *	@brief	返回表格的列表项数量
 *
 *	@param 	tableView 	表格视图
 *
 *	@return	列表项数量
 */
///#end
///#begin en
/**
 *	@brief	Return items count.
 *
 *	@param 	tableView 	Table view object.
 *
 *	@return	item number of table view.
 */
///#end
- (NSInteger)itemNumberOfTableView:(CMHTableView *)tableView;

///#begin zh-cn
/**
 *	@brief	返回列表项视图
 *
 *	@param 	tableView 	表格视图
 *	@param 	indexPath 	索引位置
 *
 *	@return	列表项视图
 */
///#end
///#begin en
/**
 *	@brief	Return a table view item.
 *
 *	@param 	tableView 	Table view object.
 *	@param 	indexPath 	Index path.
 *
 *	@return	Item object.
 */
///#end
- (UIView<ICMHTableViewItem> *)tableView:(CMHTableView *)tableView itemForIndexPath:(NSIndexPath *)indexPath;

@end

///#begin zh-cn
/**
 *	@brief	水平排版表格委托
 */
///#end
///#begin en
/**
 *	@brief	Horizontal table view delegate.
 */
///#end
@protocol CMHTableViewDelegate <NSObject>

@optional

///#begin zh-cn
/**
 *	@brief	返回列表项宽度
 *
 *	@param 	tableView 	表格视图
 *	@param 	indexPath 	索引位置
 *
 *	@return	列表项宽度
 */
///#end
///#begin en
/**
 *	@brief	Get item width.
 *
 *	@param 	tableView 	Table view object.
 *	@param 	indexPath 	Index path.
 *
 *	@return	Item width.
 */
///#end
- (CGFloat)tableView:(CMHTableView *)tableView itemWidthForIndexPath:(NSIndexPath *)indexPath;

///#begin zh-cn
/**
 *	@brief	子项将要显示
 *
 *	@param 	tableView 	表格视图
 *  @param  item    子项视图
 *	@param 	indexPath 	索引位置
 */
///#end
///#begin en
/**
 *	@brief	item will display
 *
 *	@param 	tableView 	Table view object.
 *  @param  item    Item view.
 *	@param 	indexPath 	Index path.
 */
///#end
- (void)tableView:(CMHTableView *)tableView willDisplayItem:(UIView<ICMHTableViewItem> *)item indexPath:(NSIndexPath *)indexPath;


@end

///#begin zh-cn
/**
 *	@brief	水平排版表格
 */
///#end
///#begin en
/**
 *	@brief	Horizontal Table View
 */
///#end
@interface CMHTableView : UIView <UIScrollViewDelegate>
{
@private
    NSMutableDictionary *_reuseItemDictionary;
    NSMutableArray *_visibleItemArray;
    id<CMHTableViewDataSource> _dataSource;
    id<CMHTableViewDelegate> _delegate;
    NSMutableArray *_itemsMeasureArray;
    BOOL _needLayout;
    NSInteger _itemCount;
    CGFloat _itemWidth;
    CGFloat _currX;
    
    UIScrollView *_contentView;
}

///#begin zh-cn
/**
 *	@brief	数据源
 */
///#end
///#begin en
/**
 *	@brief	Data source.
 */
///#end
@property (nonatomic,assign) id<CMHTableViewDataSource> dataSource;

///#begin zh-cn
/**
 *	@brief	委托
 */
///#end
///#begin en
/**
 *	@brief	Delegate object.
 */
///#end
@property (nonatomic,assign) id<CMHTableViewDelegate> delegate;

///#begin zh-cn
/**
 *	@brief	列表项宽度
 */
///#end
///#begin en
/**
 *	@brief	Item width.
 */
///#end
@property (nonatomic) CGFloat itemWidth;

///#begin zh-cn
/**
 *	@brief	显示水平方向滚动条
 */
///#end
///#begin en
/**
 *	@brief	Show horizontal scroll indicator.
 */
///#end
@property (nonatomic) BOOL showsHorizontalScrollIndicator;

///#begin zh-cn
/**
 *	@brief	重新刷新数据
 */
///#end
///#begin en
/**
 *	@brief	Reload data.
 */
///#end
- (void)reloadData;

///#begin zh-cn
/**
 *	@brief	根据标识值获取可用的子项视图
 *
 *	@param 	identifier 	复用标识
 *
 *	@return	子项视图对象
 */
///#end
///#begin en
/**
 *	@brief	Dequeue a reusable item.
 *
 *	@param 	identifier 	Item identifier.
 *
 *	@return	Item object.
 */
///#end
- (UIView<ICMHTableViewItem> *)dequeueReusableItemWithIdentifier:(NSString *)identifier;



@end
