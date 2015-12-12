
#import <UIKit/UIKit.h>

///#begin zh-cn
/**
 *	@brief	图片视图
 */
///#end
///#begin en
/**
 *	@brief	Image View.
 */
///#end
@interface CMImageView : UIControl
{
@private
    UIImageView *_imageView;
    UIImage *_image;
    UIImage *_defaultImage;
    
    BOOL _bNeedLayout;
}

///#begin zh-cn
/**
 *	@brief	图片对象
 */
///#end
///#begin en
/**
 *	@brief	Image object.
 */
///#end
@property (nonatomic,retain) UIImage *image;

///#begin zh-cn
/**
 *	@brief	默认图片对象，在没有设置图片时显示
 */
///#end
///#begin en
/**
 *	@brief	Default image object，When the display image is not set image property.
 */
///#end
@property (nonatomic,retain) UIImage *defaultImage;



@end
