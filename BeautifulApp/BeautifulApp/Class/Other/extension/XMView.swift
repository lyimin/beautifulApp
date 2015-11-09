//
//  XMUIView.swift
//  baiduCourse
//
//  Created by 梁亦明 on 15/9/20.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

@IBDesignable
class XMView : UIView {

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
