
#import <UIKit/UIKit.h>
#import "CMImageView.h"

///#begin zh-cn
/**
 *	@brief	带图片头部的表格视图
 */
///#end
///#begin en
/**
 *	@brief	Image Header Table View.
 */
///#end
@interface CMImageHeaderTableView : UIView <UITableViewDelegate, UITableViewDataSource>
{
@private
    UIView *_headerView;
    CMImageView *_imageView;
    UITableView *_tableView;
    UIImageView *_backgroundImageView;
    
    id _delegate;
    id _dataSource;
}

///#begin zh-cn
/**
 *	@brief	表格委托
 */
///#end
///#begin en
/**
 *	@brief	Table view delegate.
 */
///#end
@property (nonatomic,assign) id<UITableViewDelegate> delegate;

///#begin zh-cn
/**
 *	@brief	数据源
 */
///#end
///#begin en
/**
 *	@brief	Table view data source.
 */
///#end
@property (nonatomic,assign) id<UITableViewDataSource> dataSource;

///#begin zh-cn
/**
 *	@brief	表头图片
 */
///#end
///#begin en
/**
 *	@brief	Header image.
 */
///#end
@property (nonatomic,retain) UIImage *headerImage;

///#begin zh-cn
/**
 *	@brief	表头高度
 */
///#end
///#begin en
/**
 *	@brief	Header height.
 */
///#end
@property (nonatomic) CGFloat headerHeight;

///#begin zh-cn
/**
 *	@brief	表格背景颜色
 */
///#end
///#begin en
/**
 *	@brief	Table background color.
 */
///#end
@property (nonatomic,retain) UIColor *tableBackgroundColor;

///#begin zh-cn
/**
 *	@brief	表格背景图片
 */
///#end
///#begin en
/**
 *	@brief	Table background image.
 */
///#end
@property (nonatomic,retain) UIImage *tableBackgroundImage;

///#begin zh-cn
/**
 *	@brief	分隔线颜色
 */
///#end
///#begin en
/**
 *	@brief	Separator color.
 */
///#end
@property (nonatomic,retain) UIColor *separatorColor;

///#begin zh-cn
/**
 *	@brief	分隔线样式
 */
///#end
///#begin en
/**
 *	@brief	Separator style.
 */
///#end
@property (nonatomic) UITableViewCellSeparatorStyle separatorStyle;

///#begin zh-cn
/**
 *	@brief	行高度
 */
///#end
///#begin en
/**
 *	@brief	Row height.
 */
///#end
@property (nonatomic) CGFloat rowHeight;

///#begin zh-cn
/**
 *	@brief	添加表头子视图
 *
 *	@param 	subview 	子视图
 */
///#end
///#begin en
/**
 *	@brief	Add header subview.
 *
 *	@param 	subview 	Subview.
 */
///#end
- (void)addHeaderSubview:(UIView *)subview;



@end

