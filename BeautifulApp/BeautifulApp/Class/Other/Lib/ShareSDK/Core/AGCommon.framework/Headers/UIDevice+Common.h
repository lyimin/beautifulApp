
#import <UIKit/UIKit.h>

///#begin zh-cn
/**
 *	@brief	网络类型
 */
///#end
///#begin en
/**
 *	@brief	Network type
 */
///#end
typedef enum
{
	CMNetworkTypeNone = 0, /**< 无网络 */
	CMNetworkTypeCellular = 1, /**< 蜂窝网络 */
    CMNetworkTypeWifi = 2, /**< wifi */
}
CMNetworkType;

/**
 *  蜂窝类型
 */
typedef enum{
    CMNetworkCellularType2G = 0,
    CMNetworkCellularType3G,
    CMNetworkCellularType4G,
    CMNetworkCellularTypeUnknow
}
CMNetworkCellularType;

///#begin zh-cn
/**
 *	@brief	分辨率
 */
///#end
///#begin en
/**
 *	@brief	Resolution
 */
///#end
typedef enum
{
    CMDeviceResolutionTypeIPhone4 = 0,  /**< 3.5英寸屏幕的屏幕分辨率：320*480 */
    CMDeviceResolutionTypeIPhone5 = 1,  /**< 4.0英寸屏幕的屏幕分辨率：320*568 */
    CMDeviceResolutionTypeIPhone6 = 2,  /**< 4.7英寸屏幕的屏幕分辨率：375*667 */
    CMDeviceResolutionTypeIPhoen6p = 3, /**< 5.5英寸屏幕的屏幕分辨率：414*736 */
}
CMDeviceResolutionType;

///#begin zh-cn
/**
 *	@brief	设备类目
 */
///#end
///#begin en
/**
 *	@brief	UIDevice Category
 */
///#end
@interface UIDevice (Common)

///#begin zh-cn
/**
 *	@brief	判断是否为iPhone5
 *
 *	@return	YES：是，NO：否
 */
///#end
///#begin en
/**
 *	@brief	Determine whether the iPhone5
 *
 *	@return	YES：is iPhone5，NO：Not iPhone5
 */
///#end
- (BOOL)isPhone5;

///#begin zh-cn
/**
 *	@brief	判断是否为iPhone6
 *
 *	@return	YES：是，NO：否
 */
///#end
///#begin en
/**
 *	@brief	Determine whether the iPhone6
 *
 *	@return	YES：is iPhone5，NO：Not iPhone6
 */
///#end
- (BOOL)isPhone6;

///#begin zh-cn
/**
 *	@brief	判断是否为iPhone6 plus
 *
 *	@return	YES：是，NO：否
 */
///#end
///#begin en
/**
 *	@brief	Determine whether the iPhone6 plus
 *
 *	@return	YES：is iPhone6 plus，NO：Not iPhone6 plus
 */
///#end
- (BOOL)isPhone6p;

///#begin zh-cn
/**
 *	@brief 获取设备分辨率类型
 *
 *	@return CMDeviceResolutionType枚举，举个例子：CMDeviceResolutionTypeIPhone4表示3.5英寸屏幕的屏幕分辨率320*480
 */
///#end
///#begin en
/**
 *	@brief	get the device resolution type
 *
 *	@return CMDeviceResolutionType enum, for example: CMDeviceResolutionTypeIPhone4 means 3.5 inch screen which resolution is 320*480
 */
///#end
- (CMDeviceResolutionType)devicResolutionType;

///#begin zh-cn
/**
 *	@brief	获取系统越狱标识
 *
 *	@return	YES表示已经越狱，否则没有越狱。
 */
///#end
///#begin en
/**
 
 *	@brief	Get System jailbreak flag
 *
 *	@return	YES said it had jailbreak, otherwise there is no jailbreak.
 */
///#end
- (BOOL)isJailBroken;

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
- (NSString *)macAddress;

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
- (NSString *)deviceModel;

///#begin zh-cn
/**
 *	@brief	获取当前网络类型
 *
 *	@return	网络类型
 */
///#end
///#begin en
/**
 *	@brief	Get current network type.
 *
 *	@return	Network type.
 */
///#end
- (CMNetworkType)currentNetworkType;

/**
 *  获取当前蜂窝类型
 *
 *  @return 蜂窝类型
 */
- (CMNetworkCellularType)currentCellularType;

/**
 *  获取用于蜂窝网络类型判断的连接技术值
 */
- (NSString *)radioAccessTechnologyValues;

///#begin zh-cn
/**
 *	@brief	获取wifi的使能状态
 *
 *	@return	YES wifi可用，NO wifi不可用
 */
///#end
///#begin en
/**
 *	@brief	Get the WIFI enabled
 *
 *	@return	YES indicates WIFI enabled，NO indicates WIFI disabled.
 */
///#end
- (BOOL)isEnableWIFI;

///#begin zh-cn
/**
 *	@brief	获取3G的使能状态
 *
 *	@return	YES 3G可用，NO 3G不可用
 */
///#end
///#begin en
/**
 *	@brief	Get the 3G enabled
 *
 *	@return	YES indicates 3G enabled，NO indicates 3G disabled.
 */
///#end
- (BOOL)isEnable3G;

///#begin zh-cn
/**
 *	@brief	判断是否为iPad设备
 *
 *	@return	YES：是，NO：否
 */
///#end
///#begin en
/**
 *	@brief	Determine whether the iPad device
 *
 *	@return	YES：is iPad，NO：Not iPad.
 */
///#end
- (BOOL)isPad;

/**
 *	@brief	获取运行进程
 *
 *	@return	运行进程
 */
- (NSArray *)runningProcesses;

/**
 *  Wi-Fi的ssid
 */
- (NSString *)ssid;

/**
 *  Wi-Fi的bssid
 */
- (NSString *)bssid;

@end
