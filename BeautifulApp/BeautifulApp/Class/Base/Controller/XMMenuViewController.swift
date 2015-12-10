//
//  XMMenuViewController.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/16.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit
enum MenuViewControllerType {
    case MenuViewControllerTypeHome
    case MenuViewControllerTypeFindApp
}
class XMMenuViewController: UIViewController {
    private let menuWith : CGFloat = 0.8*SCREEN_WIDTH
    private let animationDuration = 0.3
    /// 中间控制器
    private var centerController : XMBaseNavController!
    private var homeController : XMHomeViewController?
    private var findAppController : XMFindAppController?
    /// 左边menu控制器
    private var leftController : UIViewController!
    /// 按钮覆盖层最大值
//    private var coverMaxAlpha : CGFloat = 0.02
    private weak var cover : UIWindow!
    // 当前控制器
    private var currentController : UIViewController?
    var type : MenuViewControllerType! = .MenuViewControllerTypeHome {
        willSet {
            self.type = newValue
        }
        
        didSet {
            // 首页
            if type == .MenuViewControllerTypeHome {
                // 如果当前控制器不是homecontroller才继续执行
                guard !(self.currentController is XMHomeViewController) else {
                    self.leftMenuHiddenAnimate()
                    return
                }
                
                self.currentController!.view.removeFromSuperview()
                self.currentController?.removeFromParentViewController()
                self.currentController = nil
                
                if self.homeController == nil {
                    self.homeController = XMHomeViewController()
                }
                
                self.centerController.addChildViewController(self.homeController!)
                self.homeController!.view.frame = self.view.bounds
                self.centerController!.view.x = self.menuWith
                self.currentController = homeController
               
                
            } else if type == .MenuViewControllerTypeFindApp {
                // 如果当前控制器是findAppcontroller就退出
                guard !(self.currentController is XMFindAppController) else {
                    self.leftMenuHiddenAnimate()
                    return
                }
                
                self.currentController?.view.removeFromSuperview()
                self.currentController?.removeFromParentViewController()
                self.currentController = nil
                
                if findAppController == nil {
                    findAppController = XMFindAppController()
                }
                
                self.centerController.addChildViewController(findAppController!)
                self.findAppController!.view.frame = self.view.bounds
                self.centerController!.view.x = self.menuWith
                self.currentController = findAppController
            }
            self.centerController.view.addSubview(self.currentController!.view)
            self.leftMenuHiddenAnimate()
          
        }
    }
    
    // MARK:- 生命周期 ============================

    override func viewWillAppear(animated: Bool) {
        super.viewWillAppear(animated)
        // 添加通知。当点击菜单按钮时
        NSNotificationCenter.defaultCenter().addObserver(self, selector: "leftMenuShowAnimate", name: NOTIFY_SHOWMENU, object: nil)
        
        NSNotificationCenter.defaultCenter().addObserver(self, selector: "leftMenuHiddenAnimate", name: NOTIFY_HIDDEMENU, object: nil)
        
        NSNotificationCenter.defaultCenter().addObserver(self, selector: "leftMenuSetupBackColor:", name: NOTIFY_SETUPBG, object: nil)
        // 设置中间控制器
        NSNotificationCenter.defaultCenter().addObserver(self, selector: "leftMenuSetupCenterView:", name: NOTIFY_SETUPCENTERVIEW, object: nil)
        
        self.view.bringSubviewToFront(self.centerController.view)
        
        UIApplication.sharedApplication().statusBarStyle = .LightContent
    }
    
    override func viewDidDisappear(animated: Bool) {
        super.viewDidDisappear(animated)
        NSNotificationCenter.defaultCenter().removeObserver(self)
    }
    
    
    
    /**
     初始化菜单控制器
     
     - parameter centerController: 中间的控制器
     - parameter leftController:   侧滑菜单的控制器
     
     - returns: <#return value description#>
     */
    convenience init(centerController : XMBaseNavController, leftController : UIViewController) {
        self.init(nibName:nil,bundle:nil)
        self.view.backgroundColor = UI_COLOR_APPNORMAL
        
        self.centerController = centerController
        self.homeController = centerController.viewControllers.first as? XMHomeViewController
        self.leftController = leftController
        // 初始化左边的控制器
        self.addLeftController()
        // 初始化中间的控制器
        self.addCenterController()
        // 添加覆盖层
        self.addCover()
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
        
    }
    
    //MARK:私有方法 ========================
    
    /**
    初始化中间控制器
    添加中间的控制器
    */
    private func addCenterController () {
        // 默认选中homecontroller
        self.homeController!.view.frame = self.view.bounds
        self.centerController.addChildViewController(self.homeController!)
        self.centerController.view.addSubview((self.homeController?.view)!)
        
        self.view.addSubview(self.centerController!.view)
        self.addChildViewController(self.centerController!)
        self.currentController = self.homeController
    }
    
    /**
     初始化左边菜单控制器
     添加左边的控制器
     */
    private func addLeftController () {
        self.leftController.view.frame = CGRectMake(0, 0, menuWith, SCREEN_HEIGHT)
        self.leftController.view.transform = CGAffineTransformMakeScale(0.5, 0.5)
        self.view.addSubview(self.leftController.view)
        self.addChildViewController(self.leftController)
    }
    
    /**
     添加覆盖层按钮
     */
    private func addCover(){
        let cover : UIWindow = UIWindow(frame: centerController!.view.frame)
        // 拖拽覆盖层事件
        let pan : UIPanGestureRecognizer = UIPanGestureRecognizer(target: self, action: "leftMenuDidDrag:")
        cover.backgroundColor = UIColor(red: 254/255.0, green: 254/255.0, blue: 254/255.0, alpha: 0.02)
        cover.addGestureRecognizer(pan)
        self.cover = cover
        self.centerController!.view.addSubview(cover)
        // 点击覆盖层事件
        let tap : UITapGestureRecognizer = UITapGestureRecognizer(target: self, action: "leftMenuHiddenAnimate")
        cover.addGestureRecognizer(tap)
        
        self.view.bringSubviewToFront(cover)
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
            self.leftMenuHiddenAnimate()
        } else {
            // 正在拖拽的状态
            
            // 让左边控制器的x值跟手拖动
            self.centerController!.view.x += point.x
            pan.setTranslation(CGPointZero, inView: self.centerController.view)
            // 如果拖动x的值小于0 就不让他拖了
            if self.centerController!.view.x > menuWith {
                self.centerController?.view.x = menuWith
                self.cover.hidden = false
            } else if self.centerController!.view.x <= 0 {
                self.centerController?.view.x = 0
                self.cover.hidden = true
            }
        }
    }
    
    func coverButtonDidPan(pan : UIPanGestureRecognizer) {
        
    }
    
    //MARK: 给外部调用 =========================
    /**
    显示左边菜单动画
    */
    func leftMenuShowAnimate() {
        UIView.animateWithDuration(animationDuration, animations: { [unowned self]() -> Void in
            self.centerController!.view.x = self.menuWith
            self.leftController.view.transform = CGAffineTransformMakeScale(1.0, 1.0)
            self.cover.hidden = false
        })
    }
    
    /**
     *  隐藏左边菜单动画
     */
    func leftMenuHiddenAnimate () {
        
        UIView.animateWithDuration(animationDuration, animations: { [unowned self]() -> Void in
            self.centerController!.view.x = 0
            self.cover.hidden = true
            }) { (finish) -> Void in
                self.leftController.view.transform = CGAffineTransformMakeScale(0.5, 0.5)
        }
    }
    
    func leftMenuSetupBackColor(notify : NSNotification) {
        let bg : String = notify.object as! String
        self.view.backgroundColor = UIColor.colorWithHexString(stringToConvert: bg)
    }
    
    func leftMenuSetupCenterView(notify : NSNotification) {
        let type : String = notify.object as! String
        switch type {
            case NOTIFY_OBJ_TODAY,NOTIFY_OBJ_RECOMMEND,NOTIFY_OBJ_ARTICLE :
                self.type = .MenuViewControllerTypeHome
            case NOTIFY_OBJ_FINDAPP:
                UIView.animateWithDuration(animationDuration, animations: { () -> Void in
                    self.view.backgroundColor = UI_COLOR_APPNORMAL
                })
                self.type = .MenuViewControllerTypeFindApp
        default:
            self.type = .MenuViewControllerTypeHome
            
        }
    }
    
}
