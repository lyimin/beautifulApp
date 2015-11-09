//
//  UIBarButtonItem+XM.swift
//  baiduCourse
//
//  Created by 梁亦明 on 15/9/17.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

extension UIBarButtonItem {
    class func barButtonItemWithImg(image : UIImage!, selectorImg : UIImage?, target : AnyObject!, action : Selector!) -> UIBarButtonItem {
        let button : UIButton = UIButton()
        button.setBackgroundImage(image, forState: .Normal)
        button.setBackgroundImage(selectorImg, forState: UIControlState.Highlighted)
        button.frame = CGRectMake(0, 0, (button.currentBackgroundImage?.size.width)!, (button.currentBackgroundImage?.size.height)!)
        button.addTarget(target, action: action, forControlEvents: UIControlEvents.TouchUpInside)
        return UIBarButtonItem(customView: button)
    }
}
