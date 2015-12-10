//
//  XMBaseNavController.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/21.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMBaseNavController: UINavigationController {

    override func viewDidLoad() {
        super.viewDidLoad()

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
}
