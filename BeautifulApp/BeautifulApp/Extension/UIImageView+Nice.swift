//
//  UIImageView+Nice.swift
//  beautifulApp-Swift3
//
//  Created by 梁亦明 on 16/11/29.
//  Copyright © 2016年 xiaoming.com. All rights reserved.
//

import Foundation


extension UIImageView {
    public func nice_setImage(imageURL: URL!) {
        self.nice_setImage(imageURL: imageURL, placeholderImage: UIImage(named: "home_logo_pressed")!)
    }
    public func nice_setImage(imageURL: URL!, placeholderImage: UIImage) {
        self.yy_setImage(with: imageURL, placeholder: placeholderImage, options: [.setImageWithFadeAnimation, .progressiveBlur], completion: nil)
    }
    public func nice_setImage(imageURL: URL!, imageCornerRadius: CGFloat) {
        self.yy_setImage(with: imageURL, placeholder: UIImage(named: "ic_launcher"), options: [.setImageWithFadeAnimation, .progressiveBlur]) { [unowned self](image, url, type, stage, error) in
            if image != nil {
                self.image = image!.drawRectWithRoundedCorner(radius: imageCornerRadius, self.size)
            }
        }
    }
    
    public func nice_setImage(imageURL: URL!, placeholderImage: UIImage, imageCornerRadius: CGFloat) {
        self.yy_setImage(with: imageURL, placeholder: placeholderImage, options: [.setImageWithFadeAnimation, .progressiveBlur]) { [unowned self](image, url, type, stage, error) in
            if image != nil {
                self.image = image!.drawRectWithRoundedCorner(radius: imageCornerRadius, self.size)
            }
        }
    }
}
