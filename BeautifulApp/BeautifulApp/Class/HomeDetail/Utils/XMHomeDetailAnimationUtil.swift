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
        UIView.animateWithDuration(0.5, animations: { () -> Void in
            toolView.collectLabel.alpha = 0
            toolView.downloadLabel.alpha = 0
            toolView.shareLabel.alpha = 0
            
            toolView.collectButton.transform = CGAffineTransformMakeTranslation(13, 0)
            toolView.shareButton.transform = CGAffineTransformMakeTranslation(-12, 0)
            toolView.downloadButton.transform = CGAffineTransformMakeTranslation(-37, 0)
        })
    }
 
    class func homeDetailToolBarToScrollAnimation(toolView : XMHomeDetailToolView) {
        UIView.animateWithDuration(0.5) { () -> Void in
            toolView.collectLabel.alpha = 1
            toolView.downloadLabel.alpha = 1
            toolView.shareLabel.alpha = 1
            
            toolView.collectButton.transform = CGAffineTransformIdentity
            toolView.shareButton.transform = CGAffineTransformIdentity
            toolView.downloadButton.transform = CGAffineTransformIdentity
        }
    }
}
