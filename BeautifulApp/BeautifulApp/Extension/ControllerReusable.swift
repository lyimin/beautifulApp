//
//  ControllerReusable.swift
//  beautifulApp-Swift3
//
//  Created by 梁亦明 on 2016/12/3.
//  Copyright © 2016年 xiaoming.com. All rights reserved.
//

import Foundation


protocol ControllerReusable: class {
    /// 网络加载错误时的图形
    var errorBtn: UIButton! { get }
    /// 加载进度条
    var progressView: UIImageView! { get set }
}


extension ControllerReusable where Self: UIViewController {
    
    var errorBtn: UIButton! {
        let errorBtn = UIButton(frame: CGRect(x: 0, y: 0, width: 150, height: 145))
        errorBtn.isHidden = true
        errorBtn.center = self.view.center
        errorBtn.setImage(UIImage(named: "not_network_icon_unpre"), for: .normal)
        errorBtn.setImage(UIImage(named: "not_network_icon_pre"), for: .highlighted)
        self.view.addSubview(errorBtn)
        // 让他处在view的最上层
        self.view.bringSubview(toFront: errorBtn)
        return errorBtn
    }
    
    /// 显示进度条
    func showProgress() {
        if progressView == nil {
            progressView = UIImageView(frame: CGRect(x: 0, y: 0, width: 40, height: 40))
            progressView.center = self.view.center
            self.view.addSubview(progressView)
        }
        
        var imgArray : Array<UIImage> = Array()
        // 添加图片
        for i in 0..<8 {
            let image = UIImage(named: "loading_\(i+1)")!
            imgArray.append(image)
        }
        progressView.animationImages = imgArray
        progressView.animationDuration = 0.5
        progressView.animationRepeatCount = 999
        self.view.bringSubview(toFront:progressView)
        progressView.startAnimating()
    }
    
    /// 隐藏进度条
    func hiddenProgress() {
        if progressView != nil {
            progressView.stopAnimating()
            progressView.perform(#selector(setter: UIImageView.animationImages), with: nil)
        }
    }
}
