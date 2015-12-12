
#import <Foundation/Foundation.h>
#import "CMLoader.h"

///#begin zh-cn
/**
 *	@brief	缓存管理器
 */
///#end
///#begin en
/**
 *	@brief	Cache Manager.
 */
///#end
@interface CMCacheManager : NSObject
{
	//加载队列，尚未从网络获取本地加载完毕的将会进入此队列。
	NSMutableArray *_loaderQueue;
	//缓存路径
	NSString *_cachePath;
}

///#begin zh-cn
/**
 *	@brief	加载文件
 *
 *	@param 	url 	文件路径
 *
 *	@return	文件加载器
 */
///#end
///#begin en
/**
 *	@brief	Load file.
 *
 *	@param 	url 	File URL object.
 *
 *	@return	Loader object.
 */
///#end
- (CMLoader *)load:(NSURL *)url;


@end
