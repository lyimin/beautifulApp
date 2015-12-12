
#import <UIKit/UIKit.h>
#import "ICMGridItemView.h"

@class CMGridView;

///#begin zh-cn
/**
 *	@brief	表格视图委托
 */
///#end
///#begin en
/**
 *	@brief	Grid view delegate.
 */
///#end
@protocol CMGridViewDelegate <NSObject>


@required

///#begin zh-cn
/**
 *	@brief	表格项渲染
 *
 *	@param 	gridView 	表格视图
 *	@param 	itemRenderer 	表格项渲染器
 *	@param 	itemData 	表格项数据
 *	@param 	index 	位置索引
 */
///#end
///#begin en
/**
 *	@brief	Grid item renderer.
 *
 *	@param 	gridView 	Grid view.
 *	@param 	itemRenderer 	Item renderer.
 *	@param 	itemData 	Item data.
 *	@param 	index 	Index.
 */
///#end
- (void)gridView:(CMGridView *)gridView
    itemRenderer:(UIView<ICMGridItemView> *)itemRenderer
        itemData:(id)itemData
           index:(NSInteger)index;

@optional

///#begin zh-cn
/**
 *	@brief	表格视图滚动
 *
 *	@param 	gridView 	表格视图
 */
///#end
///#begin en
/**
 *	@brief	View did scroll
 *
 *	@param 	gridView 	Grid view.
 */
///#end
- (void)gridViewDidScroll:(CMGridView *)gridView;

///#begin zh-cn
/**
 *	@brief	表格视图停止拖动
 *
 *	@param 	gridView 	表格视图
 *	@param 	decelerate 	减速运动标识，YES表示进行减速运动，否则不进行减速运动
 */
///#end
///#begin en
/**
 *	@brief	View did end dragging.
 *
 *	@param 	gridView 	Grid view object.
 *	@param 	decelerate 	Deceleration flag, YES indicates deceleration movement, or not decelerating motion
 */
///#end
- (void)gridViewDidEndDragging:(CMGridView *)gridView willDecelerate:(BOOL)decelerate;

///#begin zh-cn
/**
 *	@brief	表格视图页脚将要显示
 *
 *	@param 	gridView 	表格视图
 *	@param 	cell 	页脚项
 */
///#end
///#begin en
/**
 *	@brief	Footer will display.
 *
 *	@param 	gridView 	Grid view object.
 *	@param 	cell 	Footer cell.
 */
///#end
- (void)gridView:(CMGridView *)gridView footerWillDisplay:(UITableViewCell *)cell;

///#begin zh-cn
/**
 *	@brief	表格视图页脚被选中
 *
 *	@param 	gridView 	表格视图
 *	@param 	cell 	页脚项
 */
///#end
///#begin en
/**
 *	@brief	Footer did selected.
 *
 *	@param 	gridView 	Grid view object.
 *	@param 	cell 	Footer cell.
 */
///#end
- (void)gridView:(CMGridView *)gridView footerDidSelected:(UITableViewCell *)cell;


@end

///#begin zh-cn
/**
 *	@brief	表格视图
 */
///#end
///#begin en
/**
 *	@brief	Grid View.
 */
///#end
@interface CMGridView : UIView <UITableViewDataSource,
                                UITableViewDelegate,
                                UIScrollViewDelegate>
{
@private
    UITableView *_tableView;
    Class _itemType;
    Class _footerType;
    NSArray *_dataArray;
    
    NSInteger _iColumnCount;
    NSInteger _iRowCount;
    CGFloat _fLeftPadding;
    CGFloat _fRightPadding;
    CGFloat _fTopPadding;
    CGFloat _fBottomPadding;
    CGFloat _fHorizontalGap;
    CGFloat _fVerticalGap;
    
    CGSize _itemSize;
    
    id _delegate;
}

///#begin zh-cn
/**
 *	@brief	列表数据.
 */
///#end
///#begin en
/**
 *	@brief	Data array.
 */
///#end
@property (nonatomic,retain) NSArray *dataArray;

///#begin zh-cn
/**
 *	@brief	列表项类型
 */
///#end
///#begin en
/**
 *	@brief	Item class
 */
///#end
@property (nonatomic,assign) Class itemType;


///#begin zh-cn
/**
 *	@brief	列表项大小
 */
///#end
///#begin en
/**
 *	@brief	Item size.
 */
///#end
@property (nonatomic,assign) CGSize itemSize;


///#begin zh-cn
/**
 *	@brief	滚动标识
 */
///#end
///#begin en
/**
 *	@brief	Scroll enable.
 */
///#end
@property (nonatomic) BOOL scrollEnable;


///#begin zh-cn
/**
 *	@brief	左边距
 */
///#end
///#begin en
/**
 *	@brief	Left padding.
 */
///#end
@property (nonatomic,readonly) CGFloat fLeftPadding;


///#begin zh-cn
/**
 *	@brief	右边距
 */
///#end
///#begin en
/**
 *	@brief	Right padding.
 */
///#end
@property (nonatomic,readonly) CGFloat fRightPadding;

///#begin zh-cn
/**
 *	@brief	顶部边距
 */
///#end
///#begin en
/**
 *	@brief	Top padding.
 */
///#end
@property (nonatomic,readonly) CGFloat fTopPadding;


///#begin zh-cn
/**
 *	@brief	底部边距
 */
///#end
///#begin en
/**
 *	@brief	Bottom padding
 */
///#end
@property (nonatomic,readonly) CGFloat fBottomPadding;


///#begin zh-cn
/**
 *	@brief	水平间距
 */
///#end
///#begin en
/**
 *	@brief	Horizontal gap
 */
///#end
@property (nonatomic,readonly) CGFloat fHorizontalGap;


///#begin zh-cn
/**
 *	@brief	垂直间距
 */
///#end
///#begin en
/**
 *	@brief	Vertical gap.
 */
///#end
@property (nonatomic,readonly) CGFloat fVerticalGap;


///#begin zh-cn
/**
 *	@brief	内容偏移量
 */
///#end
///#begin en
/**
 *	@brief	Content inset.
 */
///#end
@property (nonatomic) UIEdgeInsets contentInset;

///#begin zh-cn
/**
 *	@brief	委托对象
 */
///#end
///#begin en
/**
 *	@brief	Delegate object.
 */
///#end
@property (nonatomic,assign) id<CMGridViewDelegate> delegate;


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
@property (nonatomic,readonly) UITableView *contentView;

///#begin zh-cn
/**
 *	@brief	页脚类型，如果为nil则不显示页脚
 */
///#end
///#begin en
/**
 *	@brief	Footer class，If nil is not displayed footer
 */
///#end
@property (nonatomic,assign) Class footerType;

///#begin zh-cn
/**
 *	@brief	设置表格边距及间距
 *
 *	@param 	topPadding 	顶部边距
 *	@param 	rightPadding 	右边距
 *	@param 	bottomPadding 	底部边距
 *	@param 	leftPadding 	左边距
 *	@param 	hGap 	水平间距
 *	@param 	vGap 	垂直间距
 */
///#end
///#begin en
/**
 *	@brief	Set grid padding and spacing
 *
 *	@param 	topPadding 	Top padding
 *	@param 	rightPadding 	Right padding
 *	@param 	bottomPadding 	Bottom padding
 *	@param 	leftPadding 	Left padding
 *	@param 	hGap 	Horizontal gap
 *	@param 	vGap 	Vertical gap
 */
///#end
- (void)setGridTopPadding:(CGFloat)topPadding
             rightPadding:(CGFloat)rightPadding
            bottomPadding:(CGFloat)bottomPadding
              leftPadding:(CGFloat)leftPadding
                     hGap:(CGFloat)hGap
                     vGap:(CGFloat)vGap;


///#begin zh-cn
/**
 *	@brief	出队一个尚未使用的单元格
 *
 *	@param 	identifier 	引用标识
 *
 *	@return	单元格对象，如果没有尚未使用的则返回nil
 */
///#end
///#begin en
/**
 *	@brief	Dequeue a reusable cell.
 *
 *	@param 	identifier 	Cell identifier.
 *
 *	@return	Cell object. If you has not reusable cell return nil
 */
///#end
- (UITableViewCell *)dequeueReusableCellWithIdentifier:(NSString *)identifier;



@end
