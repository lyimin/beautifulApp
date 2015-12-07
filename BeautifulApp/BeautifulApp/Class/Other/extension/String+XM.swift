//
//  String+XM.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/10.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import Foundation

extension String {
    var length : Int {
        return self.characters.count
    }
    
    func getImageSizeWithURL() -> CGSize {
        // 获取 _ 的位置
        let firstIndex : NSRange = (self as NSString).rangeOfString("_")
        let imgType : [String] = [".JPG",".jpg",".JPEG",".jpeg",".PNG",".png",""]
        
        var currType = imgType.last
        var typeRange : NSRange!
        for type in imgType {
            typeRange = (self as NSString).rangeOfString(type)
            if typeRange.location < 100 {
                currType = type
                break;
            }
        }
        var sizeString = self
        guard currType != "" else {
            print ("图片类型错误:\(self)")
            return CGSizeZero
        }
        
        sizeString = (self as NSString).substringWithRange(NSMakeRange(firstIndex.location+1, typeRange.location - firstIndex.location-1))
        
        let size = sizeString.componentsSeparatedByString("x")
        let widthFormatter = NSNumberFormatter().numberFromString(size.first!)
        let heightFormatter = NSNumberFormatter().numberFromString(size.last!)
        
        guard let _ = widthFormatter else {
            return CGSizeZero
        }
        guard let _ = heightFormatter else {
            return CGSizeZero
        }
        
        var width = CGFloat(widthFormatter!)
        var height = CGFloat(heightFormatter!)
        if width > SCREEN_WIDTH - 20 {
            width = SCREEN_WIDTH - 20
            height = width * height / CGFloat(widthFormatter!)
        }
        
        return CGSize(width: CGFloat(width), height: CGFloat(height))
        
    }
}
