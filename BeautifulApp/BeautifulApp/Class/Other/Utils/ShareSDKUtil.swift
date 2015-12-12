//
//  ShareSDKUtil.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/12/11.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class ShareSDKUtil: NSObject {
    class func shareToFriend() {
        let img = NSBundle.mainBundle().pathForResource("ic_launcher", ofType: "png")
        let publishContent : ISSContent =
        ShareSDK.content("是好用、好玩、好看应用的根据地，由设计师和发烧友共同参与，每天推荐高品质 #安卓# #iOS# 应用。所用即所思，品位很重要！",
            defaultContent:"默认分享内容，没内容时显示",
            image:ShareSDK.imageWithUrl(img),
            title:"来自_亦明屌炸天的应用",
            url:"https://github.com/lyimin/beautifulApp",
            description:"是好用、好玩、好看应用的根据地，由设计师和发烧友共同参与，每天推荐高品质 #安卓# #iOS# 应用。所用即所思，品位很重要！",
            mediaType:SSPublishContentMediaTypeNews)
        
        ShareSDK.showShareActionSheet(nil, shareList: nil, content: publishContent, statusBarTips: false, authOptions: nil, shareOptions: nil) { (ShareType, state:SSResponseState, statusInfo :ISSPlatformShareInfo!, error:ICMErrorInfo!, end:Bool) -> Void in
            
            if (state == SSResponseStateSuccess){
                PKHUD.sharedHUD.contentView = PKHUDSuccessView()
                PKHUD.sharedHUD.show()
                PKHUD.sharedHUD.hide(afterDelay: 0.5)
            }else if (state == SSResponseStateFail){
                PKHUD.sharedHUD.contentView = PKHUDErrorView()
                PKHUD.sharedHUD.show()
                PKHUD.sharedHUD.hide(afterDelay: 0.5)
            }else if (state == SSResponseStateCancel){
                PKHUD.sharedHUD.contentView = PKHUDErrorView()
                PKHUD.sharedHUD.show()
                PKHUD.sharedHUD.hide(afterDelay: 0.5)
            }
            
        }
    }
    
    class func shareWithModel(model : XMShareModel) {
        let publicContent : ISSContent = ShareSDK.content(model.appContent!, defaultContent: "默认分享内容，没内容时显示", image: ShareSDK.imageWithUrl(model.imgUrl!), title: model.appTitle!, url: model.appURL!, description: model.appDescription!, mediaType: SSPublishContentMediaTypeNews)
        
        ShareSDK.showShareActionSheet(nil, shareList: nil, content: publicContent, statusBarTips: false, authOptions: nil, shareOptions: nil) { (shareType, state, statusInfo, error, end) -> Void in
            if (state == SSResponseStateSuccess){
                PKHUD.sharedHUD.contentView = PKHUDSuccessView()
                PKHUD.sharedHUD.show()
                PKHUD.sharedHUD.hide(afterDelay: 0.5)
            }else if (state == SSResponseStateFail){
                PKHUD.sharedHUD.contentView = PKHUDErrorView()
                PKHUD.sharedHUD.show()
                PKHUD.sharedHUD.hide(afterDelay: 0.5)
            }else if (state == SSResponseStateCancel){
                PKHUD.sharedHUD.contentView = PKHUDErrorView()
                PKHUD.sharedHUD.show()
                PKHUD.sharedHUD.hide(afterDelay: 0.5)
            }
        }
        
//        let aa : ISSContent = ShareSDK.content
    }
}