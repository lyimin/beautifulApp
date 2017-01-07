//
//  AppDelegate.swift
//  beautifulApp-Swift3
//
//  Created by 梁亦明 on 16/10/17.
//  Copyright © 2016年 xiaoming.com. All rights reserved.
//

import UIKit
import MonkeyKing

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?


    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        
        window = UIWindow(frame: UIScreen.main.bounds)
        window?.makeKeyAndVisible()
        let navigationController = IFBaseNavController(rootViewController: MainController())
        window?.rootViewController = navigationController;
        
        // 注册分享账号
        MonkeyKing.registerAccount(.weChat(appID: "wx5e0a9f56decb72ba", appKey: "932a03ea7c85123ce25117fcf493fcf6"))
        return true
    }

}

