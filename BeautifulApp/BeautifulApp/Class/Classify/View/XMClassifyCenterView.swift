//
//  XMClassifyCenterView.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/16.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

protocol XMClassifyCenterViewDelegate {
    // 点击登陆
    func classifyCenterViewLoginViewDidClick (centerView : XMClassifyCenterView, loginView : UIView)
    // 每日最美
    func classifyCenterViewEveryDayLoveViewDidClick (centerView : XMClassifyCenterView,  everyDayLoveView: UIView)
    // 推荐
    func classifyCenterViewRecommendViewDidClick (centerView : XMClassifyCenterView, recommendView: UIView)
    // 发现应用
    func classifyCenterViewFindViewDidClick (centerView : XMClassifyCenterView, findView: UIView)
    // 文章专栏
    func classifyCenterViewArticleViewDidClick (centerView : XMClassifyCenterView, articleView: UIView)
    // 美我一下
    func classifyCenterViewSupportViewDidClick (centerView : XMClassifyCenterView, supportView: UIView)
    // 收藏
    func classifyCenterViewCollectViewDidClick (centerView : XMClassifyCenterView, collectView: UIView)
}

class XMClassifyCenterView: UIView {
    
    // 登陆
    @IBOutlet weak var loginView: UIView!
    // 每日最美
    @IBOutlet weak var everyDayLoveView: UIView!
    // 限免推荐
    @IBOutlet weak var recommendView: UIView!
    // 发现应用
    @IBOutlet weak var findView: UIView!
    // 文章专栏
    @IBOutlet weak var articleView: UIView!
    // 美我一下
    @IBOutlet weak var supportView: UIView!
    // 我的收藏
    @IBOutlet weak var collectView: UIView!
    // 当前选中
    @IBOutlet weak var indexView: UIImageView!
    private weak var curView : UIView!
    
    var delegate : XMClassifyCenterViewDelegate?
    
    // 当前选中

    class func centerView () -> XMClassifyCenterView {
        return NSBundle.mainBundle().loadNibNamed("XMClassifyCenterView", owner: nil, options: nil)[0] as! XMClassifyCenterView
    }
    
    override func awakeFromNib() {
        super.awakeFromNib()
        
        // 设置点击事件
        self.loginView.viewAddTarget(self, action: "loginViewDidClick")
        self.everyDayLoveView.viewAddTarget(self, action: "everyDayLoveViewDidClick")
        self.recommendView.viewAddTarget(self, action: "recommendViewDidClick")
        self.findView.viewAddTarget(self, action: "findViewDidClick")
        self.articleView.viewAddTarget(self, action: "articleViewDidClick")
        self.supportView.viewAddTarget(self, action: "supportViewDidClick")
        self.collectView.viewAddTarget(self, action: "collectViewDidClick")
        
        // 默认选中第一
        curView = self.everyDayLoveView
        indexView.center = self.everyDayLoveView.center
    }

    
    // Action Event
    
    // 点击登录
    func loginViewDidClick() {
        self.delegate?.classifyCenterViewLoginViewDidClick(self, loginView: self.loginView)
    }
    
    // 点击每日最美
    func everyDayLoveViewDidClick() {
        if self.curView == self.everyDayLoveView {
            return
        }
        curView = everyDayLoveView
        indexView.y = everyDayLoveView.center.y
        self.delegate?.classifyCenterViewEveryDayLoveViewDidClick(self, everyDayLoveView: self.everyDayLoveView)
    }
    
    // 点击限免推荐
    func recommendViewDidClick() {
        if self.curView == self.recommendView {
            return
        }
        curView = recommendView
        indexView.y = recommendView.center.y
        self.delegate?.classifyCenterViewRecommendViewDidClick(self, recommendView: self.recommendView)
    }
    
    // 点击发现应用
    func findViewDidClick() {
        if self.curView == self.findView {
            return
        }
        curView = findView
        indexView.y = findView.center.y
        self.delegate?.classifyCenterViewFindViewDidClick(self, findView: self.findView)
    }
    
    // 文章专栏
    func articleViewDidClick() {
        if self.curView == self.articleView {
            return
        }
        curView = articleView
        indexView.y = articleView.center.y
        self.delegate?.classifyCenterViewArticleViewDidClick(self, articleView: self.articleView)
    }
    
    // 点击美我一下
    func supportViewDidClick() {
        if self.curView == self.supportView {
            return
        }
        curView = supportView
        indexView.y = supportView.center.y
        self.delegate?.classifyCenterViewSupportViewDidClick(self, supportView: self.supportView)
    }
    // 点击我的收藏
    func collectViewDidClick() {
        if self.curView == self.collectView {
            return
        }
        curView = collectView
        indexView.y = collectView.center.y
        self.delegate?.classifyCenterViewCollectViewDidClick(self, collectView: self.collectView)
    }
    // 点击更多
    @IBAction func moreBtnDidClick(sender: UIButton) {
        
    }
    
    // 点击搜索
    @IBAction func searchBtnDidClick(sender: UIButton) {
        
    }
    
    // 点击招聘
    @IBAction func inviteBtnDidClick(sender: UIButton) {
        
    }

}
