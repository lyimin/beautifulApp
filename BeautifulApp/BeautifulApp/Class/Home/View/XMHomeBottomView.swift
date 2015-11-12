//
//  XMHomeBottomView.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/11.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMHomeBottomView: UIView {

    @IBOutlet weak var iconView: UIImageView!
    
    var iconUrl : String? {
        willSet {
            self.iconUrl = newValue
        }
        
        didSet {
            self.iconView.sd_setImageWithURL(NSURL(string: iconUrl!), placeholderImage: UIImage(named: "ic_launcher"))
        }
    }
    
    class func bottomView() -> XMHomeBottomView {
        return NSBundle.mainBundle().loadNibNamed("XMHomeBottomView", owner: nil, options: nil)[0] as! XMHomeBottomView
    }
    
    override func awakeFromNib() {
        super.awakeFromNib()
        
        self.layer.cornerRadius = 8
        self.iconView.layer.cornerRadius = 8
        self.layer.masksToBounds = true
        self.iconView.layer.masksToBounds = true
    }

}
