
#import <UIKit/UIKit.h>
#import "ICMPageContentView.h"

///#begin zh-cn
/**
 *	@brief	分页内容视图
 */
///#end
///#begin en
/**
 *	@brief	Page content view.
 */
///#end
@interface CMPageContentView : UIView <ICMPageContentView>
{
@private
    NSString *_reuseIdentifier;
}

///#begin zh-cn
/**
 *	@brief	引用标识.
 */
///#end
///#begin en
/**
 *	@brief	Reuse identifier.
 */
///#end
@property (nonatomic,readonly) NSString *reuseIdentifier;


@end
