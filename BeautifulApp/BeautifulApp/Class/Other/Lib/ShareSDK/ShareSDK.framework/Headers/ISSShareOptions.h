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

#import <Foundation/Foundation.h>
#import "ISSViewDelegate.h"
#import "ISSShareViewDelegate.h"

///#begin zh-cn
/**
 *	@brief	分享选项协议
 */
///#end
///#begin en
/**
 *	@brief	Share options protocol
 */
///#end
@protocol ISSShareOptions <NSObject>

///#begin zh-cn
/**
 *	@brief	获取一键分享列表
 *
 *	@return	一键分享列表
 */
///#end
///#begin en
/**
 *	@brief	Get one key share list.
 *
 *	@return	One key share list array.
 */
///#end
- (NSArray *)oneKeyShareList;

///#begin zh-cn
/**
 *	@brief	设置一键分享列表
 *
 *	@param 	oneKeyShareList 	一键分享列表
 */
///#end
///#begin en
/**
 *	@brief	Set one key share list.
 *
 *	@param 	oneKeyShareList 	One key share list.
 */
///#end
- (void)setOneKeyShareList:(NSArray *)oneKeyShareList;

///#begin zh-cn
/**
 *	@brief	获取分享视图标题
 *
 *	@return	分享视图标题
 */
///#end
///#begin en
/**
 *	@brief	Get share view title.
 *
 *	@return	Title string.
 */
///#end
- (NSString *)title;

///#begin zh-cn
/**
 *	@brief	设置分享视图标题
 *
 *	@param 	title 	分享视图标题
 */
///#end
///#begin en
/**
 *	@brief	Set share view title
 *
 *	@param 	title 	Title string.
 */
///#end
- (void)setTitle:(NSString *)title;

///#begin zh-cn
/**
 *	@brief	QQ分享按钮隐藏标识，默认NO, 样式为ShareViewStyleDefault时有效
 *
 *	@return	YES表示隐藏， NO表示显示
 */
///#end
///#begin en
/**
 *	@brief	Get QQ Share button hidden flag，Default NO, Style is effective when ShareViewStyleDefault
 *
 *	@return	YES indicate hidden, NO indicate display.
 */
///#end
- (BOOL)qqButtonHidden;

///#begin zh-cn
/**
 *	@brief	设置QQ分享按钮隐藏标识
 *
 *	@param 	qqButtonHidden 	YES表示隐藏， NO表示显示
 */
///#end
///#begin en
/**
 *	@brief	Set QQ Share button hidden flag.
 *
 *	@param 	qqButtonHidden 	YES indicate hidden, NO indicate display.
 */
///#end
- (void)setQqButtonHidden:(BOOL)qqButtonHidden;

///#begin zh-cn
/**
 *	@brief	微信好友分享按钮隐藏标识，默认NO, 样式为ShareViewStyleDefault时有效
 *
 *	@return	YES表示隐藏， NO表示显示
 */
///#end
///#begin en
/**
 *	@brief	Get WeChat session share button hidden flag，Default NO, Style is effective when ShareViewStyleDefault
 *
 *	@return	YES indicate hidden, NO indicate display.
 */
///#end
- (BOOL)wxSessionButtonHidden;

///#begin zh-cn
/**
 *	@brief	设置微信好友分享按钮隐藏标识
 *
 *	@param 	wxSessionButtonHidden 	YES表示隐藏， NO表示显示
 */
///#end
///#begin en
/**
 *	@brief	Set WeChat session share button flag.
 *
 *	@param 	wxSessionButtonHidden 	YES indicate hidden, NO indicate display.
 */
///#end
- (void)setWxSessionButtonHidden:(BOOL)wxSessionButtonHidden;

///#begin zh-cn
/**
 *	@brief	微信朋友圈分享按钮隐藏标识，默认NO, 样式为ShareViewStyleDefault时有效
 *
 *  @return YES表示隐藏， NO表示显示
 */
///#end
///#begin en
/**
 *	@brief	Get WeChat timeline share button hidden flag，Default NO, Style is effective when ShareViewStyleDefault
 *
 *  @return YES indicate hidden, NO indicate display.
 */
///#end
- (BOOL)wxTimelineButtonHidden;

///#begin zh-cn
/**
 *	@brief	设置微信朋友圈分享按钮隐藏标识
 *
 *	@param 	wxTimelineButtonHidden 	YES表示隐藏， NO表示显示
 */
///#end
///#begin en
/**
 *	@brief	Set WeChat timeline share button hidden flag
 *
 *	@param 	wxTimelineButtonHidden 	YES indicate hidden, NO indicate display.
 */
///#end
- (void)setWxTimelineButtonHidden:(BOOL)wxTimelineButtonHidden;

///#begin zh-cn
/**
 *	@brief	拍照按钮隐藏标识，默认NO, 样式为ShareViewStyleDefault时有效
 *
 *  @since  ver2.2.0
 *
 *	@return	YES表示隐藏， NO表示显示
 */
///#end
///#begin en
/**
 *	@brief	Get camera button hidden flag，Defulat NO, Style is effective when ShareViewStyleDefault
 *
 *  @since  ver2.2.0
 *
 *	@return	YES indicate hidden, NO indicate display.
 */
///#end
- (BOOL)cameraButtonHidden;

///#begin zh-cn
/**
 *	@brief	拍照按钮隐藏标识
 *
 *  @since  ver2.2.0
 *
 *	@param 	cameraButtonHidden 	YES表示隐藏， NO表示显示
 */
///#end
///#begin en
/**
 *	@brief	Set camera button hidden flag.
 *
 *  @since  ver2.2.0
 *
 *	@param 	cameraButtonHidden 	YES indicate hidden, NO indicate display.
 */
///#end
- (void)setCameraButtonHidden:(BOOL)cameraButtonHidden;

///#begin zh-cn
/**
 *	@brief	@按钮隐藏标识，默认NO, 样式为ShareViewStyleDefault时有效
 *
 *  @since  ver2.2.0
 *
 *	@return	YES表示隐藏， NO表示显示
 */
///#end
///#begin en
/**
 *	@brief	Get mention button hidden flag，Default NO, Style is effective when ShareViewStyleDefault
 *
 *  @since  ver2.2.0
 *
 *	@return	YES indicate hidden, NO indicate display.
 */
///#end
- (BOOL)mentionButtonHidden;

///#begin zh-cn
/**
 *	@brief	@按钮隐藏标识
 *
 *  @since  ver2.2.0
 *
 *	@param 	mentionButtonHidden 	YES表示隐藏， NO表示显示
 */
///#end
///#begin en
/**
 *	@brief	Set mention button hidden flag.
 *
 *  @since  ver2.2.0
 *
 *	@param 	mentionButtonHidden 	YES indicate hidden, NO indicate display.
 */
///#end
- (void)setMentionButtonHidden:(BOOL)mentionButtonHidden;

///#begin zh-cn
/**
 *	@brief	话题按钮隐藏标识，默认NO, 样式为ShareViewStyleDefault时有效
 *
 *  @since  ver2.2.0
 *
 *	@return	YES表示隐藏， NO表示显示
 */
///#end
///#begin en
/**
 *	@brief	Get topic button hidden flag，Default NO, Style is effective when ShareViewStyleDefault
 *
 *  @since  ver2.2.0
 *
 *	@return	YES indicate hidden, NO indicate display.
 */
///#end
- (BOOL)topicButtonHidden;

///#begin zh-cn
/**
 *	@brief	话题按钮隐藏标识
 *
 *  @since  ver2.2.0
 *
 *	@param 	topicButtonHidden 	YES表示隐藏， NO表示显示
 */
///#end
///#begin en
/**
 *	@brief	Set topic button hidden flag.
 *
 *  @since  ver2.2.0
 *
 *	@param 	topicButtonHidden 	YES indicate hidden, NO indicate display.
 */
///#end
- (void)setTopicButtonHidden:(BOOL)mentionButtonHidden;

///#begin zh-cn
/**
 *	@brief	是否在视图显示时显示键盘,默认NO。当一键分享列表为nil时，此值无效。
 *
 *  @return YES表示显示，NO表示不显示
 */
///#end
///#begin en
/**
 *	@brief	Whether in view of the display when the keyboard is displayed, the default NO. When on key share list is nil, this value is invalid.
 *
 *  @return YES indicates display. otherwise hidden.
 */
///#end
- (BOOL)showKeyboardOnAppear;

///#begin zh-cn
/**
 *	@brief	设置在视图显示时是否显示键盘
 *
 *	@param 	showKeyboardOnAppear 	YES表示显示，NO表示不显示
 */
///#end
///#begin en
/**
 *	@brief	Set whether to display the keyboard when the view display
 *
 *	@param 	showKeyboardOnAppear 	YES indicates display. otherwise hidden.
 */
///#end
- (void)setShowKeyboardOnAppear:(BOOL)showKeyboardOnAppear;

///#begin zh-cn
/**
 *	@brief	获取分享视图委托
 *
 *  @return 协议委托
 */
///#end
///#begin en
/**
 *	@brief	Get share view delegate.
 *
 *  @return Delegate object.
 */
///#end
- (id<ISSShareViewDelegate>)shareViewDelegate;

///#begin zh-cn
/**
 *	@brief	设置分享视图委托
 *
 *	@param 	shareViewDelegate 	协议委托
 */
///#end
///#begin en
/**
 *	@brief	Set share view delegate.
 *
 *	@param 	shareViewDelegate 	Delegate object.
 */
///#end
- (void)setShareViewDelegate:(id<ISSShareViewDelegate>)shareViewDelegate;

///#begin zh-cn
/**
 *	@brief	获取好友视图委托,此委托仅使用在默认样式视图中弹出的好友列表
 *
 *  @return 协议委托
 */
///#end
///#begin en
/**
 *	@brief	Get friends view delegate,only use the default sylte view friends list pop.
 *
 *  @return Delegate object.
 */
///#end
- (id<ISSViewDelegate>)friendsViewDelegate;

///#begin zh-cn
/**
 *	@brief	设置好友视图委托
 *
 *	@param 	friendsViewDelegate 	协议委托
 */
///#end
///#begin en
/**
 *	@brief	Set friends view delegate.
 *
 *	@param 	friendsViewDelegate 	Delegate object.
 */
///#end
- (void)setFriendsViewDelegate:(id<ISSViewDelegate>)friendsViewDelegate;

///#begin zh-cn
/**
 *	@brief	图片查看器视图委托,此委托仅使用在默认样式视图中图片查看器视图
 *
 *  @return 协议委托
 */
///#end
///#begin en
/**
 *	@brief	Get picture viewer view delegate.This delegate is only used in the default style view's picture viewer view.
 *
 *  @return Delegate object.
 */
///#end
- (id<ISSViewDelegate>)picViewerViewDelegate;

///#begin zh-cn
/**
 *	@brief	设置图片查看器视图委托
 *
 *	@param 	picViewerViewDelegate 	协议委托
 */
///#end
///#begin en
/**
 *	@brief	Set picture viewer view delegate.
 *
 *	@param 	picViewerViewDelegate 	Delegate object.
 */
///#end
- (void)setPicViewerViewDelegate:(id<ISSViewDelegate>)picViewerViewDelegate;

///#begin zh-cn
/**
 *	@brief	获取邮件视图委托
 *
 *	@return	协议委托
 */
///#end
///#begin en
/**
 *	@brief	Get mail view delegate.
 *
 *	@return	Delegate object.
 */
///#end
- (id<ISSViewDelegate>)mailViewDelegate;

///#begin zh-cn
/**
 *	@brief	设置邮件视图委托
 *
 *	@param 	mailViewDelegate 	协议委托
 */
///#end
///#begin en
/**
 *	@brief	Set mail view delegate.
 *
 *	@param 	mailViewDelegate 	Delegate object.
 */
///#end
- (void)setMailViewDelegate:(id<ISSViewDelegate>)mailViewDelegate;

///#begin zh-cn
/**
 *	@brief	获取短信视图委托
 *
 *	@return	协议委托
 */
///#end
///#begin en
/**
 *	@brief	Get SMS view delegate.
 *
 *	@return	Delegate object.
 */
///#end
- (id<ISSViewDelegate>)smsViewDelegate;

///#begin zh-cn
/**
 *	@brief	设置短信视图委托
 *
 *	@param 	smsViewDelegate 	协议委托
 */
///#end
///#begin en
/**
 *	@brief	Set SMS view delegate
 *
 *	@param 	smsViewDelegate 	Delegate object.
 */
///#end
- (void)setSmsViewDelegate:(id<ISSViewDelegate>)smsViewDelegate;


@end
