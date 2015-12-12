
#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonCrypto.h>

@interface NSData (Common)

/**
 *	@brief	使用Key进行HMAC-SHA1加密
 *
 *	@param 	key 	密钥
 */
- (NSData *)dataByUsingHMacSHA1WithKey:(NSData *)key;

/**
 *	@brief	使用BASE64编码数据
 *
 *	@return	编码后字符串
 */
- (NSString *)stringWithBase64Encode;

/**
 *	@brief	获取16进制字符串
 */
- (NSString *)hexString;

/**
 *	@brief	AES128位加密
 *
 *  @since  ver1.0.6
 *
 *	@param 	key 	密钥
 *	@param 	iv 	初始向量,允许为nil
 *  @param  encoding    字符编码
 */
- (NSData *)dataUsingAES128EncryptWithKey:(NSString *)key
                                       iv:(NSString *)iv
                                 encoding:(NSStringEncoding)encoding;

/**
 *	@brief	AES128位解密
 *
 *  @since  ver1.0.6
 *
 *	@param 	key 	密钥
 *	@param 	iv 	初始向量,允许为nil
 *  @param  encoding    字符编码
 */
- (NSData *)dataUsingAES128DecryptWithKey:(NSString *)key
                                       iv:(NSString *)iv
                                 encoding:(NSStringEncoding)encoding;

/**
 *	@brief	AES128位加密
 *
 *  @since  ver1.0.11
 *
 *	@param 	key 	密钥
 *	@param 	iv 	初始向量,允许为nil
 *  @param  options     选项
 */
- (NSData *)dataUsingAES128EncryptWithKey:(NSData *)key
                                       iv:(NSData *)iv
                                  options:(CCOptions)options;

/**
 *	@brief	AES128位解密
 *
 *  @since  ver1.0.11
 *
 *	@param 	key 	密钥
 *	@param 	iv 	初始向量,允许为nil
 *  @param  options     选项
 */
- (NSData *)dataUsingAES128DecryptWithKey:(NSData *)key
                                       iv:(NSData *)iv
                                  options:(CCOptions)options;

/**
 *	@brief	AES256位加密
 *
 *  @since  ver1.0.6
 *
 *	@param 	key 	密钥
 *	@param 	iv 	初始向量,允许为nil
 *  @param  encoding    字符编码
 */
- (NSData *)dataUsingAES256EncryptWithKey:(NSString *)key
                                       iv:(NSString *)iv
                                 encoding:(NSStringEncoding)encoding;

/**
 *	@brief	AES256位解密
 *
 *  @since  ver1.0.6
 *
 *	@param 	key 	密钥
 *	@param 	iv 	初始向量,允许为nil
 *  @param  encoding    字符编码
 *
 */
- (NSData *)dataUsingAES256DecryptWithKey:(NSString *)key
                                       iv:(NSString *)iv
                                 encoding:(NSStringEncoding)encoding;

/**
 *	@brief	AES256位加密
 *
 *  @since  ver1.0.11
 *
 *	@param 	key 	密钥
 *	@param 	iv 	初始向量,允许为nil
 *  @param  options     选项
 */
- (NSData *)dataUsingAES256EncryptWithKey:(NSData *)key
                                       iv:(NSData *)iv
                                  options:(CCOptions)options;

/**
 *	@brief	AES256位解密
 *
 *  @since  ver1.0.11
 *
 *	@param 	key 	密钥
 *	@param 	iv 	初始向量,允许为nil
 *  @param  options     选项
 */
- (NSData *)dataUsingAES256DecryptWithKey:(NSData *)key
                                       iv:(NSData *)iv
                                  options:(CCOptions)options;

/**
 *	@brief	GZip方式压缩数据
 *
 *	@return	压缩后数据
 */
- (NSData *)gzipData;

/**
 *	@brief	解压GZip数据
 *
 *	@return	解压后GZip数据
 */
- (NSData *)uncompressGZipData;

/**
 *	@brief	对数据进行MD5散列
 *
 *  @since  ver1.0.10
 *
 *	@return	MD5后的数据
 */
- (NSData *)dataByUsingMD5;


@end
