
#import <Foundation/Foundation.h>

///#begin zh-cn
/**
 *	@brief	设备信息
 */
///#end
///#begin en
/**
 *	@brief	Device information.
 */
///#end
@interface CMDeviceInfo : NSObject

///#begin zh-cn
/**
 *	@brief	取得网卡的物理地址
 *
 *	@return	网卡物理地址
 */
///#end
///#begin en
/**
 *	@brief	Get MAC address.
 *
 *	@return	MAC address.
 */
///#end
+ (NSString *)macAddress;

///#begin zh-cn
/**
 *	@brief	获取设备型号.http://en.wikipedia.org/wiki/List_of_iOS_devices
 *
 *	@return	设备型号：设备型号对照如下：https://github.com/InderKumarRathore/UIDeviceUtil/blob/master/UIDeviceUtil.m
 */
///#end
///#begin en
/**
 *	@brief	Get device model.http://en.wikipedia.org/wiki/List_of_iOS_devices
 *
 *	@return	Device model. Model follows：https://github.com/InderKumarRathore/UIDeviceUtil/blob/master/UIDeviceUtil.m
 */
///#end
+ (NSString *)deviceModel;

@end
