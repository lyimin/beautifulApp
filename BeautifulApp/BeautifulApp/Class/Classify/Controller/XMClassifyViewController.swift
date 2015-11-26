//
//  XMClassifyViewController.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/16.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMClassifyViewController: UIViewController, XMClassifyCenterViewDelegate {

    override func viewDidLoad() {
        super.viewDidLoad()
        self.view.backgroundColor = UI_COLOR_APPNORMAL
        
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
        NSNotificationCenter.defaultCenter().postNotificationName(NOTIFY_HIDDEMENU, object: nil)
        let notify : NSNotification = NSNotification(name: NOTIFY_SETUPHOMEVIEWTYPE, object: NOTIFY_OBJ_TODAY)
        NSNotificationCenter.defaultCenter().postNotification(notify)
    }
    
    // 限免推荐
    func classifyCenterViewRecommendViewDidClick(centerView: XMClassifyCenterView, recommendView: UIView) {
        NSNotificationCenter.defaultCenter().postNotificationName(NOTIFY_HIDDEMENU, object: nil)
        let notify : NSNotification = NSNotification(name: NOTIFY_SETUPHOMEVIEWTYPE, object: NOTIFY_OBJ_RECOMMEND)
        NSNotificationCenter.defaultCenter().postNotification(notify)
    }
    
    // 发现应用
    func classifyCenterViewFindViewDidClick(centerView: XMClassifyCenterView, findView: UIView) {
        NSNotificationCenter.defaultCenter().postNotificationName(NOTIFY_HIDDEMENU, object: nil)
    }
    
    // 文章专栏
    func classifyCenterViewArticleViewDidClick(centerView: XMClassifyCenterView, articleView: UIView) {
        NSNotificationCenter.defaultCenter().postNotificationName(NOTIFY_HIDDEMENU, object: nil)
        let notify : NSNotification = NSNotification(name: NOTIFY_SETUPHOMEVIEWTYPE, object: NOTIFY_OBJ_ARTICLE)
        NSNotificationCenter.defaultCenter().postNotification(notify)
    }
    // 美我一下
    func classifyCenterViewSupportViewDidClick(centerView: XMClassifyCenterView, supportView: UIView) {
        NSNotificationCenter.defaultCenter().postNotificationName(NOTIFY_HIDDEMENU, object: nil)
    }
    // 我的收藏
    func classifyCenterViewCollectViewDidClick(centerView: XMClassifyCenterView, collectView: UIView) {
        NSNotificationCenter.defaultCenter().postNotificationName(NOTIFY_HIDDEMENU, object: nil)
    }
    
    //MARK:- getter or Setter
    
    private var centerView : XMClassifyCenterView = {
        let centerView : XMClassifyCenterView = XMClassifyCenterView.centerView()
        return centerView
    }()

}
