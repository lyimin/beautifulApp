//
//  ShareResuable.swift
//  ifanr
//
//  Created by sys on 16/7/31.
//  Copyright © 2016年 ifanrOrg. All rights reserved.
//

import Foundation
import MonkeyKing

public protocol shareResuable: ShareViewDelegate {
    var shareView: ShareView? {get set}
    var shadowView: UIView? {get set}
}

extension shareResuable where Self: UIViewController {
    
    // 隐藏分享的View
    func hiddenShareView() {
        UIView.animate(withDuration: 0.3, animations: {
            self.shadowView!.alpha = 0
            self.shareView!.center.y += 170
        }) { (true) in
            self.shadowView!.removeFromSuperview()
            self.shareView!.removeFromSuperview()
        }
    }
    
    // 展现分享的View
    func showShareView() {
        
        let window: UIWindow = UIApplication.shared.keyWindow!
        
        self.shareView = ShareView(frame: CGRect(x: 0, y: UIConstant.SCREEN_HEIGHT, width: UIConstant.SCREEN_WIDTH, height: UIConstant.SCREEN_HEIGHT))
        self.shareView!.delegate = self
        
        self.shadowView = UIView(frame: self.view.frame)
        self.shadowView!.alpha = 0
        self.shadowView!.backgroundColor = UIColor.black
//        let tapGesture = UITapGestureRecognizer(target: self, action: #selector(self.hiddenShareView))
//        self.shadowView!.addGestureRecognizer(tapGesture)
        
        window.addSubview(self.shadowView!)
        window.addSubview(self.shareView!)
        
        UIView.animate(withDuration: 0.3, animations: {
            self.shadowView!.alpha = 0.5
            self.shareView!.center.y -= 170
        })
    }
    
    func shareToFriend(shareContent: String, shareImage: UIImage, shareUrl: String, shareTitle: String)  {
        
        let message = MonkeyKing.Message.weChat(.session(info: (
            title: shareTitle,
            description: shareContent,

            thumbnail:  shareImage,
            media: .url(URL(string: shareUrl)!)
        )))
        
        MonkeyKing.deliver(message) { success in
            print("shareURLToWeChatSession success: \(success)")
        }
    }
    
    func shareToFriendsCircle(shareContent: String, shareTitle: String, shareUrl: String, shareImage: UIImage) {
        
        
        let message = MonkeyKing.Message.weChat(.timeline(info: (title: shareTitle,
                                                   description: shareContent,
                                                     thumbnail: shareImage,
                                                         media: .url(URL(string: shareUrl)!))))
 
        MonkeyKing.deliver(message) { (result) in
            print("share to TimeLine Success:\(result)...")
        }
    }

    
//    // 分享到微信好友
//    func shareToFriend(shareContent: String, shareImageUrl: String, shareURL: String, shareTitle: String)  {
//        let shareParames = NSMutableDictionary()
//        shareParames.SSDKSetupShareParamsByText(shareContent,
//                                                images: UIImage(data: NSData(contentsOfURL: NSURL(string: shareImageUrl)!)!),
//                                                url   : NSURL(string:shareURL),
//                                                title : shareTitle,
//                                                type  : SSDKContentType.Auto)
//        
//        //2.进行分享
//        ShareSDK.share(SSDKPlatformType.TypeWechat, parameters: shareParames) { (state : SSDKResponseState, userData : [NSObject : AnyObject]!, contentEntity :SSDKContentEntity!, error : NSError!) -> Void in
//            
//            switch state{
//                
//            case SSDKResponseState.Success:
//                print("分享成功")
//            case SSDKResponseState.Fail:
//                print("分享失败,错误描述:\(error)")
//            case SSDKResponseState.Cancel:
//                print("分享取消")
//                
//            default:
//                break
//            }
//        }
//    }
//    
//    //分享到朋友圈
//    func shareToFriendsCircle(shareContent: String, shareTitle: String, shareUrl: String, shareImageUrl: String) {
//        
//        let shareParams = NSMutableDictionary()
//        shareParams.SSDKSetupWeChatParamsByText(shareContent,
//                                                title: shareTitle,
//                                                url: NSURL(string:shareUrl),
//                                                thumbImage: nil,
//                                                image: UIImage(data: NSData(contentsOfURL: NSURL(string: shareImageUrl)!)!),
//                                                musicFileURL: nil,
//                                                extInfo: nil,
//                                                fileData: nil,
//                                                emoticonData: nil,
//                                                type: .Auto,
//                                                forPlatformSubType: .SubTypeWechatTimeline)
//        
//        ShareSDK.share(.SubTypeWechatTimeline, parameters: shareParams) { (state:SSDKResponseState, userData: [NSObject : AnyObject]!, contentEntity: SSDKContentEntity!, error: NSError!) in
//            switch state {
//            case .Success:
//                print("分享成功")
//            case .Fail:
//                print("分享失败,错误描述:\(error)")
//            case.Cancel:
//                print("分享取消")
//            default:
//                break
//            }
//        }
//    }
    
}
