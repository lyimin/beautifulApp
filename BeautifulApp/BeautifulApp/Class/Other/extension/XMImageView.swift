//
//  XMImageView.swift
//  baiduCourse
//
//  Created by 梁亦明 on 15/10/4.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

@IBDesignable
class XMImageView : UIImageView {
    
    @IBInspectable var cornerRadius : CGFloat = 0 {
        didSet{
            layer.cornerRadius = cornerRadius
            layer.masksToBounds = cornerRadius > 0
        }
    }
    
    @IBInspectable var borderWidth : CGFloat = 0 {
        didSet {
            layer.borderWidth = borderWidth
        }
    }
    
    @IBInspectable var borderColor : UIColor? {
        didSet {
            layer.borderColor = borderColor?.CGColor
        }
    }

}