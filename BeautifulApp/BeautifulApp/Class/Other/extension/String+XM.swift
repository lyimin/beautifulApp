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
    
    func getImageSizeWithURL(url : String) -> CGSize {
        // 获取 _ 的位置
        let firstIndex : NSRange = (url as NSString).rangeOfString("_")
        let secondIndexJPG : NSRange = (url as NSString).rangeOfString(".JPG")
        let secondIndexPNG : NSRange = (url as NSString).rangeOfString(".PNG")
        var sizeString = url
        if secondIndexJPG.location < 100 {
            // 图片时jpg
            sizeString = (url as NSString).substringWithRange(NSMakeRange(firstIndex.location+1, secondIndexJPG.location - firstIndex.location))
        } else {
            // 图片是png
            sizeString = (url as NSString).substringWithRange(NSMakeRange(firstIndex.location+1, secondIndexPNG.location - firstIndex.location))
        }
        
        let size = sizeString.componentsSeparatedByString("x")
        
        if let widthFormatter = NSNumberFormatter().numberFromString(size.first!){
            if let heightFormatter = NSNumberFormatter().numberFromString(size.last!) {
                
                var width = CGFloat(widthFormatter)
                var height = CGFloat(heightFormatter)
                if width > SCREEN_WIDTH - 20 {
                    width = SCREEN_WIDTH - 20
                    height = width * height / CGFloat(widthFormatter)
                }
                
                return CGSize(width: CGFloat(width), height: CGFloat(height))
            }
        }
        
        return CGSizeZero
    }
}
