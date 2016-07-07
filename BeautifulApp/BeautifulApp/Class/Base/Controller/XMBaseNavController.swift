//
//  XMBaseNavController.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/21.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMBaseNavController: UINavigationController, UINavigationControllerDelegate, UIGestureRecognizerDelegate {

    override func viewDidLoad() {
        super.viewDidLoad()
        if respondsToSelector(Selector("interactivePopGestureRecognizer")) {
            interactivePopGestureRecognizer?.delegate = self
            interactivePopGestureRecognizer?.delegate = self
            delegate = self
        }
        self.navigationBarHidden = true
    }
    
    override func pushViewController(viewController: UIViewController, animated: Bool) {
        if self.viewControllers.count > 0 {
            UIApplication.sharedApplication().statusBarStyle = .Default
        }
        
        super.pushViewController(viewController, animated: animated)
    }
    
    override func popViewControllerAnimated(animated: Bool) -> UIViewController? {
        if self.viewControllers.count == 2 {
            UIApplication.sharedApplication().statusBarStyle = .LightContent
        }
        return super.popViewControllerAnimated(animated)
    }
    
    override func popToRootViewControllerAnimated(animated: Bool) -> [UIViewController]? {
        if respondsToSelector(Selector("interactivePopGestureRecognizer")) && animated {
            interactivePopGestureRecognizer?.enabled = false
        }
        
        return super.popToRootViewControllerAnimated(animated)
    }
    
    override func popToViewController(viewController: UIViewController, animated: Bool) -> [UIViewController]? {
        if respondsToSelector(Selector("interactivePopGestureRecognizer")) && animated {
            interactivePopGestureRecognizer?.enabled = false
        }
        
        return super.popToViewController(viewController, animated: false)
    }
    
    //MARK: - UINavigationControllerDelegate
    func navigationController(navigationController: UINavigationController, didShowViewController viewController: UIViewController, animated: Bool) {
        if respondsToSelector(Selector("interactivePopGestureRecognizer")) {
            interactivePopGestureRecognizer?.enabled = true
        }
    }
}
