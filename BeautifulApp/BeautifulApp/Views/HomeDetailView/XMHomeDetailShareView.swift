//
//  XMHomeDetailShareView.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/12/6.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMHomeDetailShareView: UIView {

    @IBOutlet weak var iconView: UIImageView!
    @IBOutlet weak var centerView: UIView!
    
    typealias ShareViewDidClickBlock = () -> Void
    
    var block : ShareViewDidClickBlock?
    var iconURL : String! {
        didSet {
            self.iconView.nice_setImage(imageURL: URL(string: iconURL))
        }
    }
    
    override func awakeFromNib() {
        super.awakeFromNib()
        self.centerView.viewAddTarget(target: self, action: #selector(XMHomeDetailShareView.centerViewDidClick))
    }
    
    class func shareView () -> XMHomeDetailShareView {
        return Bundle.main.loadNibNamed("XMHomeDetailShareView", owner: nil, options: nil)!.first as! XMHomeDetailShareView
    }
    
    func centerViewDidClick() {
        if let _ = self.block {
            self.block!()
        }
    }
    
    func centerViewDidClickWithBlock(block : @escaping ShareViewDidClickBlock) {
        self.block = block
    }
}
