//
//  XMMenuViewController.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/16.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMMenuViewController: UIViewController {
    private let menuWith : CGFloat = 250
    private let animationDuration = 0.3
    /// 中间控制器
    private var centerController : UIViewController!
    /// 左边menu控制器
    private var leftController : UIViewController!
    /// 按钮覆盖层最大值
    private var coverMaxAlpha : CGFloat = 0.02
    
    private weak var cover : UIButton?
    
    // MARK:- 生命周期 ============================

    override func viewWillAppear(animated: Bool) {
        super.viewWillAppear(animated)
        // 添加通知。当点击菜单按钮时
        NSNotificationCenter.defaultCenter().addObserver(self, selector: "leftMenuShowAnimate", name: NOTIFY_SHOWMENU, object: nil)
        
        NSNotificationCenter.defaultCenter().addObserver(self, selector: "leftMenuHiddenAnimate", name: NOTIFY_HIDDEMENU, object: nil)
        
        NSNotificationCenter.defaultCenter().addObserver(self, selector: "leftMenuSetupBackColor:", name: NOTIFY_SETUPBG, object: nil)
    }
    
    
    
    /**
     初始化菜单控制器
     
     - parameter centerController: 中间的控制器
     - parameter leftController:   侧滑菜单的控制器
     
     - returns: <#return value description#>
     */
    convenience init(centerController : UIViewController, leftController : UIViewController) {
        self.init(nibName:nil,bundle:nil)
        
        self.centerController = centerController
        self.leftController = leftController
        
        // 初始化中间的控制器
        self.addCenterController()
        // 添加覆盖层
        self.addCover()
        // 初始化左边的控制器
        self.addLeftController()
        
        // 添加手势
        let leftPan : UIPanGestureRecognizer = UIPanGestureRecognizer(target: self, action: "leftMenuDidDrag:")
        self.leftController.view.addGestureRecognizer(leftPan)
    }
    
    override init(nibName nibNameOrNil: String?, bundle nibBundleOrNil: NSBundle?) {
        super.init(nibName: nibNameOrNil, bundle: nibBundleOrNil)
    }
    
    required init(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    deinit {
        NSNotificationCenter.defaultCenter().removeObserver(self)
    }
    
    //MARK:私有方法 ========================
    
    /**
    初始化中间控制器
    添加中间的控制器
    */
    private func addCenterController () {
        self.centerController.view.frame = self.view.bounds
        self.view.addSubview(self.centerController.view)
        self.addChildViewController(self.centerController)
        
    }
    
    /**
     初始化左边菜单控制器
     添加左边的控制器
     */
    private func addLeftController () {
        self.leftController.view.frame = CGRectMake(-menuWith, 0, menuWith, SCREEN_HEIGHT)
        self.view.addSubview(self.leftController.view)
        self.addChildViewController(self.leftController)
    }
    
    /**
     添加覆盖层按钮
     */
    private func addCover(){
        let cover : UIButton = UIButton(frame: self.view.frame)
        cover.alpha = 0.0
        cover.backgroundColor = UIColor.lightGrayColor()
        cover.addTarget(self, action: "coverButtonDidClick:", forControlEvents: UIControlEvents.TouchUpInside)
        self.cover = cover
        self.view.addSubview(cover)
    }
    
    /**
     点击覆盖层按钮就隐藏左边菜单
     
     - parameter cover: 覆盖层按钮
     */
    func coverButtonDidClick(cover : UIButton) {
        self.leftMenuHiddenAnimate()
    }
    /**
     在中间控制器手势操作是调用
     
     - parameter pan:
     */
    func leftMenuDidDrag(pan : UIPanGestureRecognizer) {
        // 拿到手指在屏幕中的位置
        let point = pan.translationInView(pan.view)
        
        // 如果手指取消了或者结束
        if (pan.state == .Cancelled || pan.state == .Ended) {
            // 如果用户拖了menu宽度的一半，就显示整个menu
            if self.leftController.view.x > -menuWith*0.5 {
                self.leftMenuShowAnimate()
            } else {
                self.leftMenuHiddenAnimate()
            }
            
        } else {
            // 正在拖拽的状态
            
            // 让左边控制器的x值跟手拖动
            self.leftController.view.transform = CGAffineTransformTranslate(self.leftController.view.transform, point.x, 0)
            self.centerController.view.transform = CGAffineTransformTranslate(self.centerController.view.transform, point.x, 0)
            pan.setTranslation(CGPointZero, inView: self.leftController.view)
            // 如果拖动x的值小于0 就不让他拖了
            if self.leftController.view.x > 0 {
                self.leftController.view.transform = CGAffineTransformMakeTranslation(menuWith, 0)
                self.cover?.alpha = coverMaxAlpha
            } else if self.leftController.view.x <= -menuWith {
                self.leftController.view.transform = CGAffineTransformIdentity
            }
        }
    }
    
    //MARK: 给外部调用 =========================
    /**
    显示左边菜单动画
    */
    func leftMenuShowAnimate() {
        UIView.animateWithDuration(animationDuration, animations: { [unowned self]() -> Void in
            self.leftController.view.transform = CGAffineTransformMakeTranslation(self.menuWith, 0)
            self.centerController.view.transform = CGAffineTransformMakeTranslation(self.menuWith, 0)
            self.cover!.alpha = self.coverMaxAlpha;
        })
    }
    
    /**
     *  隐藏左边菜单动画
     */
    func leftMenuHiddenAnimate () {
        UIView.animateWithDuration(animationDuration, animations: { [unowned self]() -> Void in
            self.leftController.view.transform = CGAffineTransformIdentity
            self.centerController.view.transform = CGAffineTransformIdentity
            self.cover!.alpha = 0;
        })
    }
    
    func leftMenuSetupBackColor(notify : NSNotification) {
        let bg : String = notify.object as! String
        self.leftController.view.backgroundColor = UIColor.colorWithHexString(stringToConvert: bg)
    }
    
}
