
#import <UIKit/UIKit.h>
#import "ICMQuiltItemView.h"

@class CMQuiltView;

///#begin zh-cn
/**
 *	@brief	瀑布流视图数据源
 */
///#end
///#begin en
/**
 *	@brief	Quilt View Data Source.
 */
///#end
@protocol QuiltViewDataSource <NSObject>

@required

///#begin zh-cn
/**
 *	@brief	返回子项数量
 *
 *	@param 	quiltView 	瀑布流视图
 *
 *	@return	子项数量
 */
///#end
///#begin en
/**
 *	@brief	Return number of item.
 *
 *	@param 	quiltView 	Quilt View object.
 *
 *	@return	Items number.
 */
///#end
- (NSInteger)quiltViewNumberOfItem:(CMQuiltView *)quiltView;

///#begin zh-cn
/**
 *	@brief	返回子项内容
 *
 *	@param 	QuiltView 	瀑布流视图
 *	@param 	indexPath 	索引位置
 *
 *	@return	子项对象
 */
///#end
///#begin en
/**
 *	@brief	Return item view.
 *
 *	@param 	QuiltView 	Quilt View object.
 *	@param 	indexPath 	Index path.
 *
 *	@return	Item view.
 */
///#end
- (UIView<ICMQuiltItemView> *)quiltView:(CMQuiltView *)quiltView itemForIndexPath:(NSIndexPath *)indexPath;

@end

///#begin zh-cn
/**
 *	@brief	瀑布流视图协议
 */
///#end
///#begin en
/**
 *	@brief	Quilt View Delegate.
 */
///#end
@protocol QuiltViewDelegate <NSObject>

@optional

///#begin zh-cn
/**
 *	@brief	子项视图将要显示
 *
 *	@param 	quiltView 	瀑布流视图
 *	@param 	itemView 	子项视图
 *	@param 	indexPath 	索引位置
 */
///#end
///#begin en
/**
 *	@brief	Will display item view.
 *
 *	@param 	quiltView 	Quilt View object.
 *	@param 	itemView 	Item view.
 *	@param 	indexPath 	Index path.
 */
///#end
- (void)quiltView:(CMQuiltView *)quiltView willDisplayItemView:(UIView<ICMQuiltItemView> *)itemView indexPath:(NSIndexPath *)indexPath;

///#begin zh-cn
/**
 *	@brief	瀑布流视图滚动
 *
 *	@param 	quiltView 	瀑布流视图
 */
///#end
///#begin en
/**
 *	@brief	Did scroll.
 *
 *	@param 	quiltView 	Quilt View object.
 */
///#end
- (void)quiltViewDidScroll:(CMQuiltView *)quiltView;

///#begin zh-cn
/**
 *	@brief	瀑布流视图停止拖动
 *
 *	@param 	quiltView 	瀑布流视图
 *	@param 	decelerate 	减速运动标识，YES表示进行减速运动，否则不进行减速运动
 */
///#end
///#begin en
/**
 *	@brief	Did end dragging.
 *
 *	@param 	quiltView 	Quilt View object.
 *	@param 	decelerate 	Deceleration flag, YES indicates deceleration movement, or not decelerating motion
 */
///#end
- (void)quiltViewDidEndDragging:(CMQuiltView *)quiltView willDecelerate:(BOOL)decelerate;


@end

///#begin zh-cn
/**
 *	@brief	瀑布流视图
 */
///#end
///#begin en
/**
 *	@brief	Quilt View
 */
///#end
@interface CMQuiltView : UIView <UIScrollViewDelegate,
                                ICMQuiltItemViewConstructorDelegate>
{
@private
    NSInteger _columnsCount;
    NSInteger _itemCount;
    NSInteger _currentIndex;
    
    CGFloat _verticalGap;
    CGFloat _horizontalGap;
    CGFloat _itemWidth;
    
    BOOL _hasUpdateLayout;
    BOOL _hasLoadingItem;                          //标识是否正在加载子项
    NSMutableDictionary *_reuseItemPool;
    NSMutableDictionary *_measureHeightDict;
    NSMutableArray *_visibleItemArray;
    NSMutableArray *_itemsFrameArray;
    
    id<QuiltViewDelegate> _delegate;
    id<QuiltViewDataSource> _dataSource;
    
    UIScrollView *_contentView;
    UIView *_headerView;
}

///#begin zh-cn
/**
 *	@brief	数据源对象
 */
///#end
///#begin en
/**
 *	@brief	Data source object.
 */
///#end
@property (nonatomic,assign) id<QuiltViewDataSource> dataSource;

///#begin zh-cn
/**
 *	@brief	协议对象
 */
///#end
///#begin en
/**
 *	@brief	Delegate object.
 */
///#end
@property (nonatomic,assign) id<QuiltViewDelegate> delegate;

///#begin zh-cn
/**
 *	@brief	表头视图
 */
///#end
///#begin en
/**
 *	@brief	Header view.
 */
///#end
@property (nonatomic,retain) UIView *headerView;

///#begin zh-cn
/**
 *	@brief	内容视图
 */
///#end
///#begin en
/**
 *	@brief	Content view.
 */
///#end
@property (nonatomic,readonly) UIScrollView *contentView;

///#begin zh-cn
/**
 *	@brief	项宽度
 */
///#end
///#begin en
/**
 *	@brief	Item width.
 */
///#end
@property (nonatomic,readonly) CGFloat itemWidth;

///#begin zh-cn
/**
 *	@brief	初始化瀑布流视图
 *
 *	@param 	frame 	显示区域
 *	@param 	itemWidth 	子项视图宽度
 *
 *	@return	瀑布流视图
 */
///#end
///#begin en
/**
 *	@brief	Initialize quilt view.
 *
 *	@param 	frame 	Display rect.
 *	@param 	itemWidth 	Item width.
 *
 *	@return	Quilt view.
 */
///#end
- (id)initWithFrame:(CGRect)frame itemWidth:(CGFloat)itemWidth;

///#begin zh-cn
/**
 *	@brief	重新加载数据
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
 *	@brief	初始化瀑布流，用于重新计算项目
 */
///#end
///#begin en
/**
 *	@brief	Initialize quilt view，Used to recalculate all items.
 */
///#end
- (void)clean;

///#begin zh-cn
/**
 *	@brief	根据标识值获取可用的瀑布流子项视图
 *
 *	@param 	identifier 	复用标识
 *
 *	@return	子项视图对象
 */
///#end
///#begin en
/**
 *	@brief	Dequeue reusable page.
 *
 *	@param 	identifier 	Item identifier.
 *
 *	@return	Item view object.
 */
///#end
- (UIView<ICMQuiltItemView> *)dequeueReusablePageWithIdentifier:(NSString *)identifier;


@end
