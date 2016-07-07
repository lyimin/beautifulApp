//
//  UIImage+XM.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 16/2/27.
//  Copyright © 2016年 xiaoming. All rights reserved.
//

import UIKit

extension UIImage {
    /**
     设置圆角
     
     - parameter radius: 圆角半径
     */
    func imageWithCornerRadius(radius : CGFloat) -> UIImage {
        let rect : CGRect = CGRect(x: 0, y: 0, width: self.size.width, height: self.size.height)
        
        UIGraphicsBeginImageContextWithOptions(self.size, false, UIScreen.mainScreen().scale)
        CGContextAddPath(UIGraphicsGetCurrentContext(), UIBezierPath(roundedRect: rect, cornerRadius: radius).CGPath)
        self.drawInRect(rect)
        
        let image = UIGraphicsGetImageFromCurrentImageContext()
        
        UIGraphicsEndImageContext()
        return image
    }
}

