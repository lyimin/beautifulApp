//
//  XMClassifyCenterView.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/16.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMClassifyCenterView: UIView {

    class func centerView () -> XMClassifyCenterView {
        return NSBundle.mainBundle().loadNibNamed("XMClassifyCenterView", owner: nil, options: nil)[0] as! XMClassifyCenterView
    }

}
