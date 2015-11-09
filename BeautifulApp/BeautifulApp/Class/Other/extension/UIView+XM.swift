//
//  UIImageView+XM.swift
//  baiduCourse
//
//  Created by 梁亦明 on 15/9/12.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import Foundation
import UIKit

public extension UIView {
    /**
    添加点击事件
    
    - parameter target: 对象
    - parameter action: 动作
    */
    public func viewAddTarget(target : AnyObject,action : Selector) {
        
        let tap = UITapGestureRecognizer(target: target, action: action)
        self.userInteractionEnabled = true
        self.addGestureRecognizer(tap)
    }
    
    public var x : CGFloat {
        get {
            return self.frame.origin.x
        }
        set {
            var frame = self.frame
            frame.origin.x = newValue
            self.frame = frame
        }
    }
    
    public var y : CGFloat {
        get {
            return self.frame.origin.y
        }
        
        set {
            var frame = self.frame
            frame.origin.y = newValue
            self.frame = frame
        }
    }
    
    public var width : CGFloat {
        get {
            return self.frame.size.width
        }
        
        set {
            var frame = self.frame
            frame.size.width = newValue
            self.frame = frame
        }
    }
    
    public var height : CGFloat {
        get {
            return self.frame.size.height
        }
        
        set {
            var frame = self.frame
            frame.size.height = newValue
            self.frame = frame
        }
    }
    
    public var size : CGSize {
        get {
            return self.frame.size
        }
        
        set {
            var frame = self.frame
            frame.size = newValue
            self.frame = frame
        }
    }
    
    public var origin : CGPoint {
        get {
            return self.frame.origin
        }
        
        set {
            var frame = self.frame
            frame.origin = newValue
            self.frame = frame
        }
    }
    
}