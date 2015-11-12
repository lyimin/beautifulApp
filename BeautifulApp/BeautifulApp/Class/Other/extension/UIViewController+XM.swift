//
//  UIViewController+XM.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/9.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

protocol UIViewControllerProtocol {
    var isAnimationProgress : Bool {get set}
    func showProgress()

}

extension UIViewController {
    
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
