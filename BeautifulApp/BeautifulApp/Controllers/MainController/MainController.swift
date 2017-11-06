//
//  MainController.swift
//  beautifulApp-Swift3
//
//  Created by 梁亦明 on 2016/12/2.
//  Copyright © 2016年 xiaoming.com. All rights reserved.
//

import Foundation


class MainController: UIViewController {
    //MARK: --------------------------- Life Cycle --------------------------
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.view.backgroundColor = UIConstant.COLOR_APPNORMAL
        // 初始化控制器
        initRootViewControlelr()
        // 添加覆盖层
        addCoverView()
        
        leftMenuShowAnimate()
    }
    
    override var preferredStatusBarStyle: UIStatusBarStyle {
        return .lightContent
    }
    
    //MARK: --------------------------- Getter and Setter --------------------------
    // 菜单控制器
    fileprivate var menuController: MenuController!
    // 首页控制器
    fileprivate var homeController: HomeController?
    // 发现app控制器
    fileprivate var findAppController: FindAppController?
    // 记录当前中间的控制器
    fileprivate var currentController: UIViewController!
    // 侧滑菜单最大宽度
    fileprivate let menuMaxWidth: CGFloat = 0.8*UIConstant.SCREEN_WIDTH
    // 当侧滑菜单展开时添加一个按钮
    fileprivate weak var cover : UIWindow!
    // 当点击菜单item是就会来这里切换控制器
//    fileprivate var type: MenuItemType! = MenuItemType.dayily {
//        didSet {
//            swit
//        }
//    }
}



//MARK: --------------------------- HomeControllerDelegate, FindAppControllerDelegate--------------------------
extension MainController: HomeControllerDelegate, FindAppControllerDelegate {
    /// 点击菜单操作
    func menuBtnDidClick() {
        leftMenuShowAnimate()
    }
    
    /// 这里主要操作改变背景色
    func indexDidChange(withBackgroundColor: String) {
        view.backgroundColor = UIColor.hexString(hexString: withBackgroundColor)
        self.menuController.view.backgroundColor = UIColor.hexString(hexString: withBackgroundColor);
    }
}

//MARK: --------------------------- MenuControllerDelegate --------------------------
extension MainController: MenuControllerDelegate {
    func menuDidClick(withType: MenuItemType) {
        switch withType {
        case .dayily, .recommend, .article:
            // 每日最美, 限免推荐, 文章专栏
            
            guard currentController != homeController else {
                leftMenuHiddenAnimate()
                homeController?.apiTarget =  withType.typeTarget()
                return
            }
            
            currentController.view.removeFromSuperview()
            currentController.removeFromParentViewController()
            currentController = nil
            
            if homeController == nil {
                homeController = HomeController()
                homeController?.delegate = self
            }
            homeController?.apiTarget =  withType.typeTarget()
            currentController = homeController

        case .findApp:
            // 发现应用
            
            // 如果当前控制器是findAppcontroller就退出
            guard currentController != findAppController else {
                leftMenuHiddenAnimate()
                return
            }
            UIView.animate(withDuration: 0.3, animations: { () -> Void in
                self.view.backgroundColor = UIConstant.COLOR_APPNORMAL
                self.menuController.view.backgroundColor = UIConstant.COLOR_APPNORMAL
            })
            currentController.view.removeFromSuperview()
            currentController.removeFromParentViewController()
            if findAppController == nil {
                findAppController = FindAppController()
                findAppController?.delegate = self
            }
            
            currentController = findAppController
            break;
        default:
            break
        }
        addChildViewController(currentController)
        currentController.view.frame = self.view.bounds
        currentController.view.x = menuMaxWidth
        self.view.addSubview(currentController!.view)
        self.leftMenuHiddenAnimate()
    }
}


//MARK: --------------------------- Private Methods --------------------------

extension MainController {
    // 初始化控制器
    fileprivate func initRootViewControlelr() {
        menuController = MenuController()
        menuController.view.frame = CGRect(x: 0, y: 0, width: menuMaxWidth, height: UIConstant.SCREEN_HEIGHT)
        menuController.view.transform = CGAffineTransform(scaleX: 0.5, y: 0.5)
        homeController = HomeController()
        currentController = homeController
        currentController.view.frame = self.view.bounds
        
        addChildViewController(menuController)
        addChildViewController(currentController)
        
        view.addSubview(menuController.view)
        view.addSubview(currentController.view)
        
        menuController.delegate = self
        homeController?.delegate = self
    }
    
    /// 
    fileprivate func addCoverView() {
        let cover = UIWindow(frame: currentController.view.frame)
        // 拖拽覆盖层事件
        let pan = UIPanGestureRecognizer(target: self, action: #selector(MainController.leftMenuDidDrag(pan:)))
        cover.backgroundColor = UIColor(red: 254/255.0, green: 254/255.0, blue: 254/255.0, alpha: 0.02)
        cover.addGestureRecognizer(pan)
        self.cover = cover
        currentController.view.addSubview(cover)
        // 点击覆盖层事件
        let tap : UITapGestureRecognizer = UITapGestureRecognizer(target: self, action: #selector(MainController.leftMenuHiddenAnimate))
        cover.addGestureRecognizer(tap)
        
        self.view.bringSubview(toFront: cover)
    }
    
    /**
     在中间控制器手势操作是调用
     
     - parameter pan:
     */
    @objc fileprivate func leftMenuDidDrag(pan : UIPanGestureRecognizer) {
        // 拿到手指在屏幕中的位置
        let point = pan.translation(in: pan.view)
        
        // 如果手指取消了或者结束
        if (pan.state == .cancelled || pan.state == .ended) {
            self.leftMenuHiddenAnimate()
        } else {
            // 正在拖拽的状态
            
            // 让左边控制器的x值跟手拖动
            currentController.view.x += point.x
            pan.setTranslation(CGPoint.zero, in: currentController.view)
            // 如果拖动x的值小于0 就不让他拖了
            if currentController.view.x > menuMaxWidth {
                currentController.view.x = menuMaxWidth
                cover.isHidden = false
            } else if currentController.view.x <= 0 {
                currentController.view.x = 0
                cover.isHidden = true
            }
        }
    }
    
    /**
     显示左边菜单动画
     */
    fileprivate func leftMenuShowAnimate() {
        UIView.animate(withDuration: 0.3, animations: { [unowned self]() -> Void in
            self.currentController.view.x = self.menuMaxWidth
            self.menuController.view.transform = CGAffineTransform(scaleX: 1.0, y: 1.0)
            self.cover.isHidden = false
        })
    }
    
    /**
     *  隐藏左边菜单动画
     */
    @objc fileprivate func leftMenuHiddenAnimate () {
        
        UIView.animate(withDuration: 0.3, animations: { [unowned self]() -> Void in
            self.currentController.view.x = 0
            self.cover.isHidden = true
        }) { (finish) -> Void in
            self.menuController.view.transform = CGAffineTransform(scaleX: 0.5, y: 0.5)
        }
    }
}

