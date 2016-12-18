//
//  String+ifanr.swift
//  ifanr
//
//  Created by 梁亦明 on 16/7/7.
//  Copyright © 2016年 ifanrOrg. All rights reserved.
//

import Foundation

extension String {
    /// 获取字符串长度
    var length : Int {
        return characters.count
    }
    
    /**
     获得符合正则表达式的字符串集合
     - parameter pattern: 正则表达式
     - returns: 字符串集合
     */
    func getSuitableString(pattern: String) -> [String]{
        
        do {
            let pattern = pattern
            let regex   = try NSRegularExpression(pattern: pattern, options: NSRegularExpression.Options.caseInsensitive)
            let res     = regex.matches(in: self, options: NSRegularExpression.MatchingOptions(rawValue: 0), range: NSMakeRange(0, self.characters.count))
            var subStrArray = [String]()
            for checkingRes in res {
                let subStr = (self as NSString).substring(with: checkingRes.range)
                subStrArray.append(subStr)
            }
            return subStrArray
        }
        catch {
            print(error)
        }
        
        return [String]()
    }
    
    /// 获取图片大小
    func getImageSizeWithURL() -> CGSize {
        // 获取 _ 的位置
        let firstIndex : NSRange = (self as NSString).range(of: "_")
        let imgType : [String] = [".JPG",".jpg",".JPEG",".jpeg",".PNG",".png","gif",""]
        
        var currType = imgType.last
        var typeRange : NSRange!
        for type in imgType {
            typeRange = (self as NSString).range(of: type)
            if typeRange.location < 100 {
                currType = type
                break;
            }
        }
        var sizeString = self
        guard currType != "" else {
            print ("图片类型错误:\(self)")
            return CGSize.zero
        }
        
        sizeString = (self as NSString).substring(with: NSMakeRange(firstIndex.location+1, typeRange.location - firstIndex.location-1))
        let size = sizeString.components(separatedBy: "x")
        let widthFormatter = NumberFormatter().number(from: size.first!)
        let heightFormatter = NumberFormatter().number(from: size.last!)
        
        guard let _ = widthFormatter else {
            return CGSize.zero
        }
        guard let _ = heightFormatter else {
            return CGSize.zero
        }
        
        var width = CGFloat(widthFormatter!)
        var height = CGFloat(heightFormatter!)
        if width > UIConstant.SCREEN_WIDTH - 20 {
            width = UIConstant.SCREEN_WIDTH - 20
            height = width * height / CGFloat(widthFormatter!)
        }
        
        return CGSize(width: CGFloat(width), height: CGFloat(height))
        
    }
}
