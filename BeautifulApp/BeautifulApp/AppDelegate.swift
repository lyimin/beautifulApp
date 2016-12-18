//
//  AppDelegate.swift
//  beautifulApp-Swift3
//
//  Created by 梁亦明 on 16/10/17.
//  Copyright © 2016年 xiaoming.com. All rights reserved.
//

import UIKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?


    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        
        window = UIWindow(frame: UIScreen.main.bounds)
        window?.makeKeyAndVisible()
        let navigationController = IFBaseNavController(rootViewController: MainController())
        window?.rootViewController = navigationController;
        
        return true
    }

}

