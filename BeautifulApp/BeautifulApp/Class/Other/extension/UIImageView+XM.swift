//
//  UIImageView+XM.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/12/3.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

extension UIImageView {
    // 普通效果
    func xm_setImageWithURL(url : NSURL!, placeholderImage: UIImage!) {
        return self.yy_setImageWithURL(url, placeholder: placeholderImage)
    }
    
    // 模糊和渐变效果
//    func xm_setBlurImageWithURL(url : NSURL!) {
//        return self.yy_setImageWithURL(url, options: [YYWebImageOptions.ProgressiveBlur,YYWebImageOptions.SetImageWithFadeAnimation])
//    }
    
//    func xm_setBlurImageWithURL(URL : NSURL!,placeholderImage : UIImage!, block : YYWebImageCompletionBlock?) {
//        return self.yy_setImageWithURL(URL, placeholder: placeholderImage, options: [YYWebImageOptions.ProgressiveBlur,YYWebImageOptions.SetImageWithFadeAnimation], completion: block)
//    }
    
    func xm_setBlurImageWithURL(URL : NSURL!, placeholderImage: UIImage!) {
        return self.yy_setImageWithURL(URL, placeholder: placeholderImage, options: [YYWebImageOptions.ProgressiveBlur,YYWebImageOptions.SetImageWithFadeAnimation], completion: { (image, url, type, stage, error) -> Void in
            if type == YYWebImageFromType.DiskCache {
                self.image = image
            }
        })
        
//        return self.sd_setImageWithURL(URL, placeholderImage: placeholderImage)
    }
}