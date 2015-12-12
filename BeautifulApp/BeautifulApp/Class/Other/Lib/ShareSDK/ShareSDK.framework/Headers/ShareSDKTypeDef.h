///#begin zh-cn
//
//  Created by ShareSDK.cn on 13-1-14.
//  官网地址:http://www.ShareSDK.cn
//  技术支持邮箱:support@sharesdk.cn
//  官方微信:ShareSDK   （如果发布新版本的话，我们将会第一时间通过微信将版本更新内容推送给您。如果使用过程中有任何问题，也可以通过微信与我们取得联系，我们将会在24小时内给予回复）
//  商务QQ:4006852216
//  Copyright (c) 2013年 ShareSDK.cn. All rights reserved.
//
///#end
///#begin en
//
//  Created by ShareSDK.cn on 13-1-14.
//  Website:http://www.ShareSDK.cn
//  Support E-mail:support@sharesdk.cn
//  WeChat ID:ShareSDK   （If publish a new version, we will be push the updates content of version to you. If you have any questions about the ShareSDK, you can get in touch through the WeChat with us, we will respond within 24 hours）
//  Business QQ:4006852216
//  Copyright (c) 2013年 ShareSDK.cn. All rights reserved.
//
///#end

#import <AGCommon/ICMErrorInfo.h>

#ifndef ShareSDKInterface_ShareSDKTypeDef_h
#define ShareSDKInterface_ShareSDKTypeDef_h

///#begin zh-cn
/**
 *	@brief	分享类型
 */
///#end
///#begin en
/**
 *	@brief	Platform type.
 */
///#end
typedef enum
{
	ShareTypeSinaWeibo = 1,         /**< 新浪微博 */
	ShareTypeTencentWeibo = 2,      /**< 腾讯微博 */
	ShareTypeDouBan = 5,            /**< 豆瓣社区 */
	ShareTypeQQSpace = 6,           /**< QQ空间 */
	ShareTypeRenren = 7,            /**< 人人网 */
	ShareTypeKaixin = 8,            /**< 开心网 */
	ShareTypePengyou = 9,           /**< 朋友网 */
	ShareTypeFacebook = 10,         /**< Facebook */
	ShareTypeTwitter = 11,          /**< Twitter */
	ShareTypeEvernote = 12,         /**< 印象笔记 */
	ShareTypeFoursquare = 13,       /**< Foursquare */
	ShareTypeGooglePlus = 14,       /**< Google＋ */
	ShareTypeInstagram = 15,        /**< Instagram */
	ShareTypeLinkedIn = 16,         /**< LinkedIn */
	ShareTypeTumblr = 17,           /**< Tumbir */
    ShareTypeMail = 18,             /**< 邮件分享 */
	ShareTypeSMS = 19,              /**< 短信分享 */
	ShareTypeAirPrint = 20,         /**< 打印 */
	ShareTypeCopy = 21,             /**< 拷贝 */
    ShareTypeWeixiSession = 22,     /**< 微信好友 */
	ShareTypeWeixiTimeline = 23,    /**< 微信朋友圈 */
    ShareTypeQQ = 24,               /**< QQ */
    ShareTypeInstapaper = 25,       /**< Instapaper */
    ShareTypePocket = 26,           /**< Pocket */
    ShareTypeYouDaoNote = 27,       /**< 有道云笔记 */
    ShareTypePinterest = 30,        /**< Pinterest */
    ShareTypeFlickr = 34,           /**< Flickr */
    ShareTypeDropbox = 35,          /**< Dropbox */
    ShareTypeVKontakte = 36,        /**< VKontakte */
    ShareTypeWeixiFav = 37,         /**< 微信收藏 */
    ShareTypeYiXinSession = 38,     /**< 易信好友 */
    ShareTypeYiXinTimeline = 39,    /**< 易信朋友圈 */
    ShareTypeYiXinFav = 40,         /**< 易信收藏 */
    ShareTypeMingDao = 41,          /**< 明道 */
    ShareTypeLine = 42,             /**< Line */
    ShareTypeWhatsApp = 43,         /**< Whats App */
    ShareTypeKaKaoTalk = 44,        /**< KaKao Talk */
    ShareTypeKaKaoStory = 45,       /**< KaKao Story */
    ShareTypeAliPaySocial = 50,     /**< 支付宝 */
    ShareTypeOther = -1,            /**< > */
    ShareTypeAny = 99               /**< 任意平台 */
}
ShareType;

///#begin zh-cn
/**
 *	@brief	请求方式
 */
///#end
///#begin en
/**
 *	@brief	Request method.
 */
///#end
typedef enum
{
	ShareSDKRequestMethodGet = 0,           /**< HTTP Get方式 */
	ShareSDKRequestMethodPost = 1,          /**< HTTP Post方法 */
	ShareSDKRequestMethodMultipartPost = 2  /**< HTTP Multipart POST方式，一般用于上传文件的api接口 */
}
ShareSDKRequestMethod;

///#begin zh-cn
/**
 *	@brief	微信分享场景
 */
///#end
///#begin en
/**
 *	@brief	WeChat scene.
 */
///#end
typedef enum
{
	ShareSDKWeChatSceneSession = 0, /**< 好友 */
	ShareSDKWeChatSceneTimeline = 1 /**< 朋友圈 */
}
ShareSDKWeChatScene;

///#begin zh-cn
/**
 *	@brief	授权状态
 */
///#end
///#begin en
/**
 *	@brief	Authorized state.
 */
///#end
typedef enum
{
    SSAuthStateBegan = 0, /**< 开始 */
	SSAuthStateSuccess = 1, /**< 成功 */
	SSAuthStateFail = 2, /**< 失败 */
    SSAuthStateCancel = 3 /**< 取消 */
}
SSAuthState;

///#begin zh-cn
/**
 *	@brief	发布内容状态
 */
///#end
///#begin en
/**
 *	@brief	Publish content state.
 */
///#end
typedef enum
{
	SSPublishContentStateBegan = 0, /**< 开始 */
	SSPublishContentStateSuccess = 1, /**< 成功 */
	SSPublishContentStateFail = 2, /**< 失败 */
	SSPublishContentStateCancel = 3 /**< 取消 */
}
SSPublishContentState;

///#begin zh-cn
/**
 *	@brief	响应状态
 */
///#end
///#begin en
/**
 *	@brief	Response state.
 */
///#end
typedef enum
{
	SSResponseStateBegan = 0, /**< 开始 */
	SSResponseStateSuccess = 1, /**< 成功 */
	SSResponseStateFail = 2, /**< 失败 */
	SSResponseStateCancel = 3 /**< 取消 */
}
SSResponseState;

///#begin zh-cn
/**
 *	@brief	授权视图样式
 */
///#end
///#begin en
/**
 *	@brief	Authorize view style.
 */
///#end
typedef enum
{
	SSAuthViewStylePopup = 0, /**< 弹出式窗口 */
	SSAuthViewStyleModal = 1, /**< 模态式窗口，iPad默认 */
    SSAuthViewStyleFullScreenPopup = 2 /**< 全屏弹出式窗口，iPhone默认 */
}
SSAuthViewStyle;

///#begin zh-cn
/**
 *	@brief	视图方向
 */
///#end
///#begin en
/**
 *	@brief	Interface orientation.
 */
///#end
typedef enum {
    SSInterfaceOrientationMaskPortrait = (1 << UIInterfaceOrientationPortrait),
    SSInterfaceOrientationMaskLandscapeLeft = (1 << UIInterfaceOrientationLandscapeLeft),
    SSInterfaceOrientationMaskLandscapeRight = (1 << UIInterfaceOrientationLandscapeRight),
    SSInterfaceOrientationMaskPortraitUpsideDown = (1 << UIInterfaceOrientationPortraitUpsideDown),
    SSInterfaceOrientationMaskLandscape = (SSInterfaceOrientationMaskLandscapeLeft | SSInterfaceOrientationMaskLandscapeRight),
    SSInterfaceOrientationMaskAll = (SSInterfaceOrientationMaskPortrait | SSInterfaceOrientationMaskLandscapeLeft | SSInterfaceOrientationMaskLandscapeRight | SSInterfaceOrientationMaskPortraitUpsideDown),
    SSInterfaceOrientationMaskAllButUpsideDown = (SSInterfaceOrientationMaskPortrait | SSInterfaceOrientationMaskLandscapeLeft | SSInterfaceOrientationMaskLandscapeRight),
}SSInterfaceOrientationMask;

typedef enum
{
    SSRectEdgeNone   = 0,
    SSRectEdgeTop    = 1 << 0,
    SSRectEdgeLeft   = 1 << 1,
    SSRectEdgeBottom = 1 << 2,
    SSRectEdgeRight  = 1 << 3,
    SSRectEdgeAll    = SSRectEdgeTop | SSRectEdgeLeft | SSRectEdgeBottom | SSRectEdgeRight
}
SSRectEdge;

///#begin zh-cn
/**
 *	@brief	用户字段类型
 */
///#end
///#begin en
/**
 *	@brief	User field type.
 */
///#end
typedef enum
{
	SSUserFieldTypeUid = 0,     /**< 用户ID */
	SSUserFieldTypeName = 1,    /**< 用户名称 */
    SSUserFieldTypePath = 2     /**< 个人主页路径，仅用于LinkedIn */
}
SSUserFieldType;

///#begin zh-cn
/**
 *	@brief	分享内容的消息类型，仅对微信、QQApi有效
 */
///#end
///#begin en
/**
 *	@brief	Share meida type，Only for WeChat QQ.
 */
///#end
typedef enum
{
	SSPublishContentMediaTypeText = 0, /**< 文本 */
	SSPublishContentMediaTypeImage = 1, /**< 图片 */
	SSPublishContentMediaTypeNews = 2, /**< 新闻 */
	SSPublishContentMediaTypeMusic = 3, /**< 音乐 */
	SSPublishContentMediaTypeVideo = 4, /**< 视频 */
    SSPublishContentMediaTypeApp = 5, /**< 应用,仅供微信使用 */
    SSPublishContentMediaTypeNonGif = 6, /**< 非Gif消息,仅供微信使用 */
    SSPublishContentMediaTypeGif = 7 /**< Gif消息,仅供微信使用 */
}
SSPublishContentMediaType;

///#begin zh-cn
/**
 *	@brief	分享视图样式
 */
///#end
///#begin en
/**
 *	@brief	Share view style.
 */
///#end
typedef enum
{
	SSShareViewStyleDefault = 0, /**< 默认 */
	SSShareViewStyleSimple = 1, /**< 简约，只带有文字和图片显示UI */
	SSShareViewStyleAppRecommend = 2 /**< 应用推荐，专为应用推荐而设的显示样式 */
}
SSShareViewStyle;

///#begin zh-cn
/**
 *	@brief	印象笔记类型
 */
///#end
///#begin en
/**
 *	@brief	Evernote type.
 */
///#end
typedef enum
{
	SSEverNoteTypeSandbox = 0, /**< 沙箱 */
	SSEverNoteTypeCN = 1, /**< 印象笔记 */
	SSEverNoteTypeUS = 2 /**< Evernote International */
}
SSEverNoteType;

///#begin zh-cn
/**
 *	@brief	获得金币行为
 */
///#end
///#begin en
/**
 *	@brief	Obtain coins
 */
///#end
typedef enum
{
	SSObtainCoinsActionInitalActivation = 1, /**< 首次激活 */
	SSObtainCoinsActionDailyActivation = 2, /**< 每日激活 */
	SSObtainCoinsActionShare = 3 /**< 分享 */
}
SSObtainCoinsAction;

///#begin zh-cn
/**
 *	@brief	UI风格
 */
///#end
///#begin en
/**
 *	@brief	UI Style
 */
///#end
typedef enum
{
	SSUIStyleiOS7 = 0, /**< iOS7风格 */
	SSUIStyleiOS7Below = 1 /**< iOS7系统版本以下风格 */
}
SSUIStyle;


#endif
