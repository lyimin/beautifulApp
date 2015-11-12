//
//  UIColor+XM.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/10.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

extension UIColor {

    class func colorWithHexString (stringToConvert stringToConvert : String) -> UIColor {
        // 默认颜色
        let DEFAULT_VOID_COLOR : UIColor = UIColor.whiteColor()
        
        var cString : String = stringToConvert.stringByTrimmingCharactersInSet(NSCharacterSet.whitespaceAndNewlineCharacterSet()).uppercaseString
        if cString.length < 6 {
            return DEFAULT_VOID_COLOR
        }
        
        if cString.hasPrefix("0x") {
            cString = (cString as NSString).substringFromIndex(2)
        } else if cString.hasPrefix("#") {
            cString = (cString as NSString).substringFromIndex(1)
        }
        
        if cString.length != 6 {
            return DEFAULT_VOID_COLOR
        }
        
        var range : NSRange = NSRange(location: 0, length: 2)
        let rString = (cString as NSString).substringWithRange(range)
        
        range.location = 2
        let gString = (cString as NSString).substringWithRange(range)
        
        range.location = 4
        let bString = (cString as NSString).substringWithRange(range)
        
        var r:CUnsignedInt = 0, g:CUnsignedInt = 0, b:CUnsignedInt = 0;
        NSScanner(string: rString).scanHexInt(&r)
        NSScanner(string: gString).scanHexInt(&g)
        NSScanner(string: bString).scanHexInt(&b)
        
        return UIColor(red: CGFloat(r) / 255.0, green: CGFloat(g) / 255.0, blue: CGFloat(b) / 255.0, alpha: CGFloat(1))
    }

}
