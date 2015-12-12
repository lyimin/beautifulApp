
#import "CMImageLoader.h"

///#begin zh-cn
/**
 *	@brief 图片缓存管理器，主要负责图片缓存管理
 */
///#end
///#begin en
/**
 *	@brief Image Cache Manager，Primarily responsible for the image cache management
 */
///#end
@interface CMImageCacheManager : NSObject
{
	//加载图片队列，尚未从网络获取本地加载完毕的图片将会进入此队列。
	NSMutableArray *_loaderQueue;
	//缓存路径
	NSString *_cachePath;
}

///#begin zh-cn
/**
 *	@brief	获取图片
 *
 *	@param 	url 	图片路径，可以为本地或者网路路径
 *
 *	@return	图片加载器
 */
///#end
///#begin en
/**
 *	@brief	Get image object.
 *
 *	@param 	url 	Image URL string，Can be local or network path
 *
 *	@return	Image Loader object.
 */
///#end
- (CMImageLoader *)getImage:(NSString *)url;

///#begin zh-cn
/**
 *	@brief	获取图片
 *
 *	@param 	url 	图片路径，可以为本地或者网络路径
 *	@param 	size 	裁剪区域
 *	@param 	clipType 	图片裁剪类型
 *
 *	@return	图片加载器
 */
///#end
///#begin en
/**
 *	@brief	Get image object.
 *
 *	@param 	url 	Image URL string，Can be local or network path
 *	@param 	size 	Clip size.
 *	@param 	clipType 	Clip type.
 *
 *	@return	Image Loader object.
 */
///#end
- (CMImageLoader *)getImage:(NSString *)url
                       size:(CGSize)size
                   clipType:(CMImageClipType)clipType;

///#begin zh-cn
/**
 *	@brief	获取图片
 *
 *	@param 	url 	图片路径，可以为本地或者网络路径
 *	@param 	cornerRadius 	圆角
 *
 *	@return	图片加载器
 */
///#end
///#begin en
/**
 *	@brief	Get image object.
 *
 *	@param 	url 	Image URL string，Can be local or network path
 *	@param 	cornerRadius 	Corner radius.
 *
 *	@return	Image Loader object.
 */
///#end
- (CMImageLoader *)getImage:(NSString *)url
             cornerRadius:(CGFloat)cornerRadius;

///#begin zh-cn
/**
 *	@brief	获取图片
 *
 *	@param 	url 	图片路径，可以为本地或者网络路径
 *	@param 	cornerRadius 	圆角值，此值对应实际显示尺寸的圆角值
 *	@param 	size 	实际显示尺寸
 *
 *	@return	图片加载器
 */
///#end
///#begin en
/**
 *	@brief	Get image object.
 *
 *	@param 	url 	URL string.Can be local or network path
 *	@param 	cornerRadius 	Corner radius
 *	@param 	size 	The actual display size
 *
 *	@return	Image Loader object.
 */
///#end
- (CMImageLoader *)getImage:(NSString *)url
               cornerRadius:(CGFloat)cornerRadius
                       size:(CGSize)size;

///#begin zh-cn
/**
 *	@brief	获取图片
 *
 *	@param 	url 	图片路径，可以为本地或者网络路径
 *	@param 	cornerRadius 	圆角
 *	@param 	size 	裁减区域
 *	@param 	clipType 	图片裁剪类型
 *
 *	@return	图片加载器
 */
///#end
///#begin en
/**
 *	@brief	Get image object.
 *
 *	@param 	url 	Image URL string.
 *	@param 	cornerRadius 	Corner radius.
 *	@param 	size 	Clip size.
 *	@param 	clipType 	Clip type.
 *
 *	@return	Image Loader object.
 */
///#end
- (CMImageLoader *)getImage:(NSString *)url
               cornerRadius:(CGFloat)cornerRadius
                       size:(CGSize)size
                   clipType:(CMImageClipType)clipType;

///#begin zh-cn
/**
 *	@brief	判断图片缓存是否存在,使用getImage:得到的图片用此方法
 *
 *	@param 	url 	图片路径
 *
 *	@return	YES表示存在，NO表示不存在
 */
///#end
///#begin en
/**
 *	@brief	Image cache to determine whether there is,call getImage: this method to get image.
 *
 *	@param 	url 	URL string.
 *
 *	@return	YES exists，NO not exists.
 */
///#end
- (BOOL)existsImageCache:(NSString *)url;

///#begin zh-cn
/**
 *	@brief	判断图片缓存是否存在,使用getImage:size:clipType:得到的图片用此方法
 *
 *	@param 	url 	图片路径
 *	@param 	size 	裁剪区域
 *	@param 	clipType 	图片裁剪类型
 *
 *	@return	YES表示存在，NO表示不存在
 */
///#end
///#begin en
/**
 *	@brief	Image cache to determine whether there is,call getImage:size:clipType: this method to get image.
 *
 *	@param 	url 	Image URL string.
 *	@param 	size 	Clip size.
 *	@param 	clipType 	Clip type.
 *
 *	@return	YES exists，NO not exists.
 */
///#end
- (BOOL)existsImageCache:(NSString *)url
                    size:(CGSize)size
                clipType:(CMImageClipType)clipType;

///#begin zh-cn
/**
 *	@brief	判断图片缓存是否存在,使用getImage:cornerRadius:得到的图片用此方法
 *
 *	@param 	url 	图片路径
 *	@param 	cornerRadius 	圆角
 *
 *	@return	YES表示存在，NO表示不存在
 */
///#end
///#begin en
/**
 *	@brief	Image cache to determine whether there is,call getImage:cornerRadius: this method to get image.
 *
 *	@param 	url 	URL string.
 *	@param 	cornerRadius 	corner radius.
 *
 *	@return	YES exists，NO not exists.
 */
///#end
- (BOOL)existsImageCache:(NSString *)url
            cornerRadius:(CGFloat)cornerRadius;

///#begin zh-cn
/**
 *	@brief	判断图片缓存是否存在,使用getImage:cornerRadius:size:clipType:得到的图片用此方法
 *
 *	@param 	url 	图片路径
 *	@param 	size 	裁剪尺寸
 *	@param 	clipType 	裁剪类型
 *	@param 	cornerRadius 	圆角
 *
 *	@return	YES：存在，NO：不存在
 */
///#end
///#begin en
/**
 *	@brief	Image cache to determine whether there is,call getImage:cornerRadius:size:clipType: this method to get image.
 *
 *	@param 	url 	URL string.
 *	@param 	size 	Clip size.
 *	@param 	clipType 	Clip type.
 *	@param 	cornerRadius 	Corner radius.
 *
 *	@return	YES：exists，NO：not exists.
 */
///#end
- (BOOL)existsImageCache:(NSString *)url
                    size:(CGSize)size
                clipType:(CMImageClipType)clipType
            cornerRadius:(CGFloat)cornerRadius;



@end
