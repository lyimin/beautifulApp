//
//  XMHomeDetailAnimationUtil.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/12/9.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMHomeDetailAnimationUtil: NSObject {
    class func homeDetailToolBarToNavAnimation(toolView : XMHomeDetailToolView) {
        UIView.animate(withDuration: 0.5, animations: { () -> Void in
            toolView.collectLabel.alpha = 0
            toolView.downloadLabel.alpha = 0
            toolView.shareLabel.alpha = 0
            
            toolView.collectButton.transform = CGAffineTransform(translationX: 13, y: 0)
            toolView.shareButton.transform = CGAffineTransform(translationX: -12, y: 0)
            toolView.downloadButton.transform = CGAffineTransform(translationX: -37, y: 0)
        })
    }
 
    class func homeDetailToolBarToScrollAnimation(toolView : XMHomeDetailToolView) {
        UIView.animate(withDuration: 0.5) { () -> Void in
            toolView.collectLabel.alpha = 1
            toolView.downloadLabel.alpha = 1
            toolView.shareLabel.alpha = 1
            
            toolView.collectButton.transform = CGAffineTransform.identity
            toolView.shareButton.transform = CGAffineTransform.identity
            toolView.downloadButton.transform = CGAffineTransform.identity
        }
    }
}
