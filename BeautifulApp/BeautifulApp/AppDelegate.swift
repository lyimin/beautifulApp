//
//  AppDelegate.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/5.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?


    func application(application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject: AnyObject]?) -> Bool {
        window = UIWindow(frame: UIScreen.mainScreen().bounds)
        window?.makeKeyAndVisible()

        // 在homecontroller里套一层navcontroller
        window?.rootViewController = XMMenuViewController(centerController: XMBaseNavController(rootViewController:XMHomeViewController()), leftController: XMClassifyViewController())
        
        self.setupShareSDK()
        return true
    }
    private func setupShareSDK() {
        
        ShareSDK.registerApp("d3eb48e7c2d9")
        //2.初始化新浪微博
        ShareSDK.connectSinaWeiboWithAppKey("3251853898", appSecret: "816acc6102b92c8aa862431fdc7142a7", redirectUri: "https://github.com/lyimin", weiboSDKCls: WeiboSDK.classForCoder())
        //初始化微信，微信开放平台上注册应用
        ShareSDK.connectWeChatWithAppId("wx5e0a9f56decb72ba",appSecret:"d5f0dacaf2c5b20401c1569645605221",wechatCls:WXApi.classForCoder());
        //初始化QQ,QQ空间
        ShareSDK.connectQQWithQZoneAppKey("1104940507", qqApiInterfaceCls: QQApiInterface.classForCoder(), tencentOAuthCls: TencentOAuth.classForCoder())
        //连接QQ空间应用
        ShareSDK.connectQZoneWithAppKey("1104940507", appSecret: "x4fpQbKWfydGNRyD", qqApiInterfaceCls: QQApiInterface.classForCoder(), tencentOAuthCls: TencentOAuth.classForCoder())
    }
    //添加两个回调方法,return的必须要ShareSDK的方法
    func application(application: UIApplication, handleOpenURL url: NSURL) -> Bool {
        
        return ShareSDK.handleOpenURL(url, wxDelegate: self)
    }
    
    func application(application: UIApplication, openURL url: NSURL, sourceApplication: String?, annotation: AnyObject ) -> Bool{
        
        return ShareSDK.handleOpenURL(url, sourceApplication: sourceApplication, annotation: annotation, wxDelegate: self)
    }
    
    func applicationWillResignActive(application: UIApplication) {
        // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
        // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
    }

    func applicationDidEnterBackground(application: UIApplication) {
        // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
        // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    }

    func applicationWillEnterForeground(application: UIApplication) {
        // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
    }

    func applicationDidBecomeActive(application: UIApplication) {
        // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    }

    func applicationWillTerminate(application: UIApplication) {
        // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
    }


}

