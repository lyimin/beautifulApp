//
//  XMFindAppDetailAnimationUtil.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/12/11.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMFindAppDetailAnimationUtil: NSObject {
    class func toolBarToNavAnimation(toolView: FindAppDetailToolView) {
        UIView.animate(withDuration: 0.5, animations: { () -> Void in
            toolView.shareLabel.alpha = 0
            toolView.downloadBtn.transform = CGAffineTransform(translationX: -25, y: 0)
            toolView.downloadLabel.alpha = 0
        })
    }
    
    class func toolBarToScrollAnimation(toolView: FindAppDetailToolView) {
        UIView.animate(withDuration: 0.5, animations: { () -> Void in
            toolView.downloadBtn.transform = CGAffineTransform.identity
            
            toolView.shareLabel.alpha = 1
            toolView.downloadLabel.alpha = 1
            }) { (finish) -> Void in
                
        }
    }

}
