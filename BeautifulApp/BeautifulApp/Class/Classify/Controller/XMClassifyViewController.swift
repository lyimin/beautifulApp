//
//  XMClassifyViewController.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/16.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit
import SafariServices

class XMClassifyViewController: UIViewController, XMClassifyCenterViewDelegate {

    override func viewDidLoad() {
        super.viewDidLoad()
        self.view.backgroundColor = UIColor.clearColor()
        
        self.view.addSubview(centerView)
        centerView.delegate = self
        
    }
    
    //MARK:- Custer delegate
    // 登陆
    func classifyCenterViewLoginViewDidClick(centerView: XMClassifyCenterView, loginView: UIView) {
        NSNotificationCenter.defaultCenter().postNotificationName(NOTIFY_HIDDEMENU, object: nil)
    }
    
    // 每日最美
    func classifyCenterViewEveryDayLoveViewDidClick(centerView: XMClassifyCenterView, everyDayLoveView: UIView) {
        // 隐藏menu
//        NSNotificationCenter.defaultCenter().postNotificationName(NOTIFY_HIDDEMENU, object: nil)
        // 设置api
        let setupAPINotify : NSNotification = NSNotification(name: NOTIFY_SETUPHOMEVIEWTYPE, object: NOTIFY_OBJ_TODAY)
        NSNotificationCenter.defaultCenter().postNotification(setupAPINotify)
        // 是否切换centerView的通知
        let setupViewNotify : NSNotification = NSNotification(name: NOTIFY_SETUPCENTERVIEW, object: NOTIFY_OBJ_TODAY)
        NSNotificationCenter.defaultCenter().postNotification(setupViewNotify)
    }
    
    // 限免推荐
    func classifyCenterViewRecommendViewDidClick(centerView: XMClassifyCenterView, recommendView: UIView) {
//        NSNotificationCenter.defaultCenter().postNotificationName(NOTIFY_HIDDEMENU, object: nil)
        let notify : NSNotification = NSNotification(name: NOTIFY_SETUPHOMEVIEWTYPE, object: NOTIFY_OBJ_RECOMMEND)
        NSNotificationCenter.defaultCenter().postNotification(notify)
        
        // 是否切换centerView的通知
        let setupViewNotify : NSNotification = NSNotification(name: NOTIFY_SETUPCENTERVIEW, object: NOTIFY_OBJ_RECOMMEND)
        NSNotificationCenter.defaultCenter().postNotification(setupViewNotify)
    }
    
    // 发现应用
    func classifyCenterViewFindViewDidClick(centerView: XMClassifyCenterView, findView: UIView) {
//        NSNotificationCenter.defaultCenter().postNotificationName(NOTIFY_HIDDEMENU, object: nil)
        
        // 是否切换centerView的通知
        let setupViewNotify : NSNotification = NSNotification(name: NOTIFY_SETUPCENTERVIEW, object: NOTIFY_OBJ_FINDAPP)
        NSNotificationCenter.defaultCenter().postNotification(setupViewNotify)
    }
    
    // 文章专栏
    func classifyCenterViewArticleViewDidClick(centerView: XMClassifyCenterView, articleView: UIView) {
//        NSNotificationCenter.defaultCenter().postNotificationName(NOTIFY_HIDDEMENU, object: nil)
        let notify : NSNotification = NSNotification(name: NOTIFY_SETUPHOMEVIEWTYPE, object: NOTIFY_OBJ_ARTICLE)
        NSNotificationCenter.defaultCenter().postNotification(notify)
        
        // 是否切换centerView的通知
        let setupViewNotify : NSNotification = NSNotification(name: NOTIFY_SETUPCENTERVIEW, object: NOTIFY_SETUPHOMEVIEWTYPE)
        NSNotificationCenter.defaultCenter().postNotification(setupViewNotify)
    }
    // 美我一下
    func classifyCenterViewSupportViewDidClick(centerView: XMClassifyCenterView, supportView: UIView) {
//        NSNotificationCenter.defaultCenter().postNotificationName(NOTIFY_HIDDEMENU, object: nil)
        UIApplication.sharedApplication().openURL(NSURL(string: APIConfig.API_APPStoreComment)!)
    }
    // 我的收藏
    func classifyCenterViewCollectViewDidClick(centerView: XMClassifyCenterView, collectView: UIView) {
        NSNotificationCenter.defaultCenter().postNotificationName(NOTIFY_HIDDEMENU, object: nil)
    }
    // 搜索
    func classifyCenterViewSearchViewDidClick(centerView: XMClassifyCenterView, searchView: UIView) {
        self.presentViewController(XMSearchController(), animated: true, completion: nil)
    }
    
    // 招聘编辑
    func classifyCenterViewInviteViewDidClick(center: XMClassifyCenterView, inviteView: UIView) {
        let safaController : SFSafariViewController = SFSafariViewController(URL: NSURL(string: APIConfig.API_Invite)!)
        self.presentViewController(safaController, animated: true, completion: nil)
    }
    
    // 更多
    func classifyCenterViewSettingViewDidClick(centerView: XMClassifyCenterView, settingView: UIView) {
        self.presentViewController(XMBaseNavController(rootViewController:SettingViewController()), animated: true, completion: nil)
    }
    

    //MARK:- getter or Setter
    
    private var centerView : XMClassifyCenterView = {
        let centerView : XMClassifyCenterView = XMClassifyCenterView.centerView()
        return centerView
    }()

}
