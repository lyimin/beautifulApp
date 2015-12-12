

#import <UIKit/UIKit.h>
#import "ICMQuiltItemView.h"

///#begin zh-cn
/**
 *	@brief	瀑布流子项视图
 */
///#end
///#begin en
/**
 *	@brief	Quilt item view.
 */
///#end
@interface CMQuiltItemView : UIView <ICMQuiltItemView>
{
@private
    NSString *_reuseIdentifier;
    id<ICMQuiltItemViewConstructorDelegate> _constructorDelegate;
}

///#begin zh-cn
/**
 *	@brief	复用标识
 */
///#end
///#begin en
/**
 *	@brief	Reuse identifier.
 */
///#end
@property (nonatomic,readonly) NSString *reuseIdentifier;

///#begin zh-cn
/**
 *	@brief	构造器协议对象
 */
///#end
///#begin en
/**
 *	@brief	Constructor delegate object.
 */
///#end
@property (nonatomic,assign) id<ICMQuiltItemViewConstructorDelegate> constructorDelegate;



@end
