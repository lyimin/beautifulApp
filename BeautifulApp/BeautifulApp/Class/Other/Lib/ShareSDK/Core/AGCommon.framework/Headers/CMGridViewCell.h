
#import <UIKit/UIKit.h>
#import "ICMGridItemView.h"

///#begin zh-cn
/**
 *	@brief	表格视图单元格
 */
///#end
///#begin en
/**
 *	@brief	Grid view cell.
 */
///#end
@interface CMGridViewCell : UITableViewCell
{
@private
    NSMutableArray *_itemArray;
    Class _itemType;
    
    CGSize _itemSize;
    CGFloat _fTopPadding;
    CGFloat _fBottomPadding;
    CGFloat _fLeftPadding;
    CGFloat _fRightPadding;
    CGFloat _fHGap;
    
    BOOL _bHasUpdateLayout;
}

///#begin zh-cn
/**
 *	@brief	更新列表项类型以及列数量
 *
 *	@param 	itemType 	列表项类型
 *	@param 	itemSize 	列表项大小
 *	@param 	topPadding 	顶部边距
 *	@param 	rightPadding 	右边距
 *	@param 	bottomPadding 	底部边距
 *	@param 	leftPadding 	左边距
 *	@param 	hGap 	水平间距
 */
///#end
///#begin en
/**
 *	@brief	Update item data.
 *
 *	@param 	itemType 	Item class.
 *	@param 	itemSize 	Item size.
 *	@param 	topPadding 	Top padding.
 *	@param 	rightPadding 	Right padding.
 *	@param 	bottomPadding 	Bottom padding.
 *	@param 	leftPadding 	Left padding.
 *	@param 	hGap 	Horizontal gap.
 */
///#end
- (void)updateItemType:(Class)itemType
              itemSize:(CGSize)itemSize
            topPadding:(CGFloat)topPadding
          rightPadding:(CGFloat)rightPadding
         bottomPadding:(CGFloat)bottomPadding
           leftPadding:(CGFloat)leftPadding
                  hGap:(CGFloat)hGap;


///#begin zh-cn
/**
 *	@brief	获取表格项视图
 *
 *	@param 	index 	索引位置
 *
 *	@return	表格项视图对象
 */
///#end
///#begin en
/**
 *	@brief	Get grid item.
 *
 *	@param 	index 	Item index.
 *
 *	@return	Item object.
 */
///#end
- (UIView<ICMGridItemView> *)getItemAtIndex:(NSInteger)index;


///#begin zh-cn
/**
 *	@brief	从指定位置开始隐藏不必要的列表项
 *
 *	@param 	index 	索引位置
 */
///#end
///#begin en
/**
 *	@brief	Began to hide unused list items from the specified location
 *
 *	@param 	index 	Item index.
 */
///#end
- (void)hideItemFromIndex:(NSInteger)index;


@end
