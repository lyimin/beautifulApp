
#import <UIKit/UIKit.h>
#import "ICMHTableViewItem.h"

///#begin zh-cn
/**
 *	@brief	水平排版表格列表项视图
 */
///#end
///#begin en
/**
 *	@brief	Horizontal table item view.
 */
///#end
@interface CMHTableViewItem : UIView <ICMHTableViewItem>
{
@private
    NSString *_reuseIdentifier;
    NSIndexPath *_indexPath;
}

///#begin zh-cn
/**
 *	@brief	复用标识
 */
///#end
///#begin en
/**
 *	@brief	Reuse indentifier.
 */
///#end
@property (nonatomic,readonly) NSString *reuseIdentifier;

///#begin zh-cn
/**
 *	@brief	位置索引
 */
///#end
///#begin en
/**
 *	@brief	Index path.
 */
///#end
@property (nonatomic,retain) NSIndexPath *indexPath;

@end
