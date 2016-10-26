//
//  UIConstant.swift
//  beautifulApp-Swift3
//
//  Created by 梁亦明 on 16/10/17.
//  Copyright © 2016年 xiaoming.com. All rights reserved.
//

import UIKit

struct UIConstant {
    // 屏幕宽高
    static let SCREEN_WIDTH : CGFloat = UIScreen.main.bounds.width
    static let SCREEN_HEIGHT : CGFloat = UIScreen.main.bounds.height
    static let IPHONE6_WIDTH : CGFloat = 375
    static let IPHONE6_HEIGHT : CGFloat = 667
    static let IPHONE5_WIDTH : CGFloat = 320
    static let IPHONE5_HEIGHT : CGFloat = 568

    // 字体
    static let UI_FONT_10 : UIFont = UIFont.systemFont(ofSize: 10)
    static let UI_FONT_11 : UIFont = UIFont.systemFont(ofSize: 11)
    static let UI_FONT_12 : UIFont = UIFont.systemFont(ofSize: 12)
    static let UI_FONT_14 : UIFont = UIFont.systemFont(ofSize: 14)
    static let UI_FONT_16 : UIFont = UIFont.systemFont(ofSize: 16)
    static let UI_FONT_20 : UIFont = UIFont.systemFont(ofSize: 20)
    static let UI_FONT_22 : UIFont = UIFont.systemFont(ofSize: 22)
    
    // 默认背景色
    static let UI_COLOR_APPNORMAL : UIColor = UIColor(red: 54/255.0, green: 142/255.0, blue: 198/155.0, alpha: 1)
    static let UI_COLOR_BORDER : UIColor = UIColor(red: 240/255.0, green: 240/255.0, blue: 240/255.0, alpha: 1)
    
    // 间距
    static let UI_MARGIN_5 : CGFloat = 5
    static let UI_MARGIN_10 : CGFloat = 10
    static let UI_MARGIN_15 : CGFloat = 15
    static let UI_MARGIN_20 : CGFloat = 20
}
