
#import <UIKit/UIKit.h>

///#begin zh-cn
/**
 *	@brief	加载视图
 */
///#end
///#begin en
/**
 *	@brief	Loading View.
 */
///#end
@interface CMLoadingView : UIView
{
    UIView *_backgroundView;
    UIActivityIndicatorView *_indicatorView;
    UILabel *_label;
    
    BOOL _needLayout;
    
}

///#begin zh-cn
/**
 *	@brief	提示信息
 */
///#end
///#begin en
/**
 *	@brief	Message content.
 */
///#end
@property (nonatomic,copy) NSString *text;

///#begin zh-cn
/**
 *	@brief	显示
 */
///#end
///#begin en
/**
 *	@brief	Display.
 */
///#end
- (void)show;

///#begin zh-cn
/**
 *	@brief	显示到指定视图中
 *
 *	@param 	view 	视图
 */
///#end
///#begin en
/**
 *	@brief	Display to the specified view
 *
 *	@param 	view 	View object.
 */
///#end
- (void)showInView:(UIView *)view;

///#begin zh-cn
/**
 *	@brief	隐藏
 */
///#end
///#begin en
/**
 *	@brief	hide view.
 */
///#end
- (void)hide;

@end
