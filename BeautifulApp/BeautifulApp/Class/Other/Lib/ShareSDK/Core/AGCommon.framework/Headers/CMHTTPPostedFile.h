
#import <Foundation/Foundation.h>

///#begin zh-cn
/**
 *	@brief	HTTP上传文件信息
 */
///#end
///#begin en
/**
 *	@brief	HTTP Posted File.
 */
///#end
@interface CMHTTPPostedFile : NSObject
{
@private
    NSString *_fileName;
    NSString *_contentType;
    NSString *_transferEncoding;
    NSData *_fileData;
}

///#begin zh-cn
/**
 *	@brief	文件名称
 */
///#end
///#begin en
/**
 *	@brief	File name.
 */
///#end
@property (nonatomic,readonly) NSString *fileName;

///#begin zh-cn
/**
 *	@brief	内容类型
 */
///#end
///#begin en
/**
 *	@brief	Content type.
 */
///#end
@property (nonatomic,readonly) NSString *contentType;

///#begin zh-cn
/**
 *	@brief	文件数据
 */
///#end
///#begin en
/**
 *	@brief	File data.
 */
///#end
@property (nonatomic,readonly) NSData *fileData;

///#begin zh-cn
/**
 *	@brief	内容传输编码
 */
///#end
///#begin en
/**
 *	@brief	Transfer encoding.
 */
///#end
@property (nonatomic,readonly) NSString *transferEncoding;

///#begin zh-cn
/**
 *	@brief	初始化上传文件
 *
 *  @param  fileName    文件名称
 *	@param 	data 	文件数据
 *  @param  contentType 内容类型
 *
 *	@return	上传文件信息
 */
///#end
///#begin en
/**
 *	@brief	Initialize posted file.
 *
 *  @param  fileName    File name.
 *	@param 	data 	File data.
 *  @param  contentType Content type.
 *
 *	@return	Posted file object.
 */
///#end
- (id)initWithFileName:(NSString *)fileName data:(NSData *)data contentType:(NSString *)contentType;

///#begin zh-cn
/**
 *	@brief	初始化上传文件
 *
 *  @param  fileName    文件名称
 *	@param 	data 	文件数据
 *  @param  contentType 内容类型
 *  @param  transferEncoding     传输编码
 *
 *	@return	上传文件信息
 */
///#end
///#begin en
/**
 *	@brief	Initialize posted file.
 *
 *  @param  fileName    File name.
 *	@param 	data 	File data.
 *  @param  contentType     Content type.
 *  @param  transferEncoding     Transfer encoding.
 *
 *	@return	Posted file object.
 */
///#end
- (id)initWithFileName:(NSString *)fileName
                  data:(NSData *)data
           contentType:(NSString *)contentType
      transferEncoding:(NSString *)transferEncoding;

///#begin zh-cn
/**
 *	@brief	初始化上传文件
 *
 *	@param 	path 	文件路径
 *  @param  contentType 内容类型
 *
 *	@return	上传文件信息
 */
///#end
///#begin en
/**
 *	@brief	Initialize posted file.
 *
 *	@param 	path 	File path.
 *  @param  contentType Content type.
 *
 *	@return	Posted file object.
 */
///#end
- (id)initWithFilePath:(NSString *)path contentType:(NSString *)contentType;


@end
