
#import <UIKit/UIKit.h>
#import "CMEventDispatcher.h"

///#begin zh-cn
/**
 *	@brief	图片加载成功
 */
///#end
///#begin en
/**
 *	@brief	Image load complete notification.
 */
///#end
#define NOTIF_IMAGE_LOAD_COMPLETE @"imageLoadComplete"

///#begin zh-cn
/**
 *	@brief	图片加载异常
 */
///#end
///#begin en
/**
 *	@brief	Image load error notification.
 */
///#end
#define NOTIF_IMAGE_LOAD_ERROR @"imageLoadError"

///#begin zh-cn
/**
 *	@brief	图片加载进度
 */
///#end
///#begin en
/**
 *	@brief	Image load progress notification.
 */
///#end
#define NOTIF_IMAGE_LOAD_PROGRESS @"imageLoadProgress"

///#begin zh-cn
/**
 *	@brief	图片数据
 */
///#end
///#begin en
/**
 *	@brief	Image data key.
 */
///#end
#define NOTIF_KEY_IMAGE_DATA @"imageData"

///#begin zh-cn
/**
 *	@brief	异常
 */
///#end
///#begin en
/**
 *	@brief	Error key.
 */
///#end
#define NOTIF_KEY_IMAGE_ERROR @"error"

///#begin zh-cn
/**
 *	@brief	图片回复
 */
///#end
///#begin en
/**
 *	@brief	Image response key.
 */
///#end
#define NOTIF_KEY_IMAGE_RESPONSE @"response"

///#begin zh-cn
/**
 *	@brief	总字节数
 */
///#end
///#begin en
/**
 *	@brief	Total bytes key.
 */
///#end
#define NOTIF_KEY_TOTAL_BYTES @"totalBytes"

///#begin zh-cn
/**
 *	@brief	加载字节数
 */
///#end
///#begin en
/**
 *	@brief	Loaded bytes key.
 */
///#end
#define NOTIF_KEY_LOADED_BYTES @"loadedBytes"

///#begin zh-cn
/**
 *	@brief	加载器状态
 */
///#end
///#begin en
/**
 *	@brief	Image loader state.
 */
///#end
typedef enum
{
	ImageLoaderStateUnset,  /**< 未设置状态 */
    ImageLoaderStateLoading, /**< 加载图片中 */
    ImageLoaderStateReady   /**< 图片加载完毕，准备就绪 */
}CMImageLoaderState;

///#begin zh-cn
/**
 *	@brief	图片来源
 */
///#end
///#begin en
/**
 *	@brief	Image source type.
 */
///#end
typedef enum
{
	ImageLoaderSourceTypeCache, /**< 缓存 */
    ImageLoaderSourceTypeUrl, /**< 网络 */
    ImageLoaderSourceTypeFile		/**< 文件 */
}CMImageLoaderSourceType;

///#begin zh-cn
/**
 *	@brief	图片裁剪类型
 */
///#end
///#begin en
/**
 *	@brief	Image clip type.
 */
///#end
typedef enum
{
	ImageClipTypeNone = 0, /**< 无裁剪 */
	ImageClipTypeTop, /**< 从顶部开始裁剪 */
	ImageClipTypeCenter, /**< 从中间开始裁剪 */
	ImageClipTypeBottom /**< 从底部开始裁剪 */
}CMImageClipType;

///#begin zh-cn
/**
 *	@brief	图片加载器，带有图片加载状态，由ImageCacheManager管理分发。
 */
///#end
///#begin en
/**
 *	@brief	Image Loader，With pictures loaded state, the ImageCacheManager manage distribution.
 */
///#end
@interface CMImageLoader : CMEventDispatcher
{
@private
	UIImage *_content;
	CMImageLoaderState _state;
	CMImageLoaderSourceType _sourceType;
	NSString *_tag;
	
	NSURLConnection *_conn;
	//接收数据对象
	NSMutableData *_receiveData;
	//请求回复
	NSURLResponse *_response;
	
    NSInteger _iDealType;           //处理类型：0 不处理，1 裁剪，2 圆角 3 裁剪圆角 4 显示区域圆角
	CGSize _clipSize;
	CMImageClipType _imageClipType;
    CGFloat _fCornerRadius;          //圆角半径，用于指定图片的圆角值，仅在_iDealType为2时有效
    
    NSInteger _imageContentLength;  //图片大小(单位：字节)
    
}

///#begin zh-cn
/**
 *	@brief	照片数据
 */
///#end
///#begin en
/**
 *	@brief	Image object.
 */
///#end
@property (nonatomic,retain,readonly) UIImage *content;

///#begin zh-cn
/**
 *	@brief	照片状态
 */
///#end
///#begin en
/**
 *	@brief	Loader state.
 */
///#end
@property (nonatomic,readonly) CMImageLoaderState state;

///#begin zh-cn
/**
 *	@brief	来源类型
 */
///#end
///#begin en
/**
 *	@brief	Source type.
 */
///#end
@property (nonatomic,readonly) CMImageLoaderSourceType sourceType;

///#begin zh-cn
/**
 *	@brief	标志
 */
///#end
///#begin en
/**
 *	@brief	Tag
 */
///#end
@property (nonatomic,retain) NSString *tag;

///#begin zh-cn
/**
 *	@brief	初始化图片加载器
 *
 *	@param 	clipSize 	裁剪尺寸
 *	@param 	clipType 	裁剪类型
 *
 *	@return	加载器
 */
///#end
///#begin en
/**
 *	@brief	Initialize Image Loader.
 *
 *	@param 	clipSize 	Clip size.
 *	@param 	clipType 	Clip type.
 *
 *	@return	Image Loader.
 */
///#end
- (id)initWithClipSize:(CGSize)clipSize clipType:(CMImageClipType)clipType;

///#begin zh-cn
/**
 *	@brief	初始化图片加载器
 *
 *	@param 	cornerRadius 	圆角
 *
 *	@return	加载器
 */
///#end
///#begin en
/**
 *	@brief	Initialize Image Loader.
 *
 *	@param 	cornerRadius 	Corner radius.
 *
 *	@return	Image Loader object.
 */
///#end
- (id)initWithCornerRadius:(CGFloat)cornerRadius;

///#begin zh-cn
/**
 *	@brief	初始化图片加载器
 *
 *	@param 	cornerRadius 	圆角
 *	@param 	size 	实际显示尺寸
 *
 *	@return	加载器
 */
///#end
///#begin en
///#end
- (id)initWithCornerRadius:(CGFloat)cornerRadius
                      size:(CGSize)size;

///#begin zh-cn
/**
 *	@brief	初始化图片加载器
 *
 *	@param 	clipSize 	裁剪尺寸
 *	@param 	clipType 	裁剪类型
 *	@param 	cornerRadius 	圆角
 *
 *	@return	加载器
 */
///#end
///#begin en
/**
 *	@brief	Initialize Image Loader.
 *
 *	@param 	clipSize 	Clip size.
 *	@param 	clipType 	Clip type.
 *	@param 	cornerRadius 	Corner radius.
 *
 *	@return	Image Loader object.
 */
///#end
- (id)initWithClipSize:(CGSize)clipSize
              clipType:(CMImageClipType)clipType
          cornerRadius:(CGFloat)cornerRadius;

///#begin zh-cn
/**
 *	@brief	加载网络图片对象
 *
 *	@param 	url 	图片URL
 */
///#end
///#begin en
/**
 *	@brief	Load image by URL
 *
 *	@param 	url 	Image URL string.
 */
///#end
- (void)loadImageByUrl:(NSString *)url;

///#begin zh-cn
/**
 *	@brief	加载本地图片对象
 *
 *	@param 	filePath 	图片路径
 */
///#end
///#begin en
/**
 *	@brief	Load image by file path
 *
 *	@param 	filePath 	Image file path.
 */
///#end
- (void)loadImageByFilePath:(NSString *)filePath;

///#begin zh-cn
/**
 *	@brief	加载缓存图片对象
 *
 *	@param 	image 	图片对象
 */
///#end
///#begin en
/**
 *	@brief	Load image by cache
 *
 *	@param 	image 	Image object.
 */
///#end
- (void)loadImageByCache:(UIImage *)image;


@end
