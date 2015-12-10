//
//  XMFindAppDetailAnimationUtil.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/12/11.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMFindAppDetailAnimationUtil: NSObject {
    class func toolBarToNavAnimation(toolView : XMFindAppDetailToolView) {
        UIView.animateWithDuration(0.5, animations: { () -> Void in
            toolView.shareLabel.alpha = 0
            toolView.downloadBtn.transform = CGAffineTransformMakeTranslation(-25, 0)
            toolView.downloadLabel.alpha = 0
        })
    }
    
    class func toolBarToScrollAnimation(toolView : XMFindAppDetailToolView) {
        UIView.animateWithDuration(0.5, animations: { () -> Void in
            toolView.downloadBtn.transform = CGAffineTransformIdentity
            
            toolView.shareLabel.alpha = 1
            toolView.downloadLabel.alpha = 1
            }) { (finish) -> Void in
                
        }
    }

}
