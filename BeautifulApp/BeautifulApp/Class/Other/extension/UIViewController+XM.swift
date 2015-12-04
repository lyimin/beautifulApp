//
//  UIViewController+XM.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/9.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

extension UIViewController {
    
//    func showNetWorkErrorView () {
//        let errorView : UIButton = UIButton(frame: CGRectMake(85, 170, 150, 145))
//        errorView.setImage(UIImage(named: "not_network_icon_unpre"), forState: .Normal)
//        errorView.setImage(UIImage(named: "not_network_icon_pre"), forState: .Highlighted)
//        errorView.addTarget(self, action: "errorViewDidClick:", forControlEvents: .TouchUpInside)
//        self.view.addSubview(errorView)
//        // 让他处在view的最上层
//        self.view.bringSubviewToFront(errorView)
//    }
//    
//    func errorViewDidClick(errorView : UIButton) {
//        errorView.removeFromSuperview()
//        NSNotificationCenter.defaultCenter().postNotificationName(NOTIFY_ERRORBTNCLICK, object: nil)
//    }
    
    func showProgress () {
        let progressView : UIImageView = UIImageView(frame: CGRectMake(0, 0, 40, 40))
        progressView.tag = 500
        progressView.center = self.view.center
        self.view.addSubview(progressView)
        
        var imgArray : Array<UIImage> = Array()
        // 添加图片
        for i in 0..<8 {
            let image : UIImage = UIImage(named: "loading_\(i+1)")!
            imgArray.append(image)
        }
        progressView.animationImages = imgArray
        progressView.animationDuration = 0.5
        progressView.animationRepeatCount = 999
        progressView.startAnimating()
    }
    
    func hiddenProgress() {
        for view in self.view.subviews {
            if view.tag == 500 {
                let imgView : UIImageView = view as! UIImageView
                imgView.stopAnimating()
                imgView.performSelector("setAnimationImages:" , withObject: nil)
            }
        }
    }
    
}
