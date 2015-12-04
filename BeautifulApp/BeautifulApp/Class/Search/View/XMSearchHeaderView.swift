//
//  XMSearchCenterView.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/29.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMSearchHeaderView: UIView {
    typealias cancleBtnDidClickBlock = () -> Void
    // 监听textfiled文字变化
    typealias textFieldDidChangeBlock = (text : String) -> Void
    @IBOutlet weak var cancleBtn: UIButton!
    var block : cancleBtnDidClickBlock?
    var textFieldBlock : textFieldDidChangeBlock?
    class func headerView() -> XMSearchHeaderView {
        return NSBundle.mainBundle().loadNibNamed("XMSearchHeaderView", owner: nil, options: nil).first as! XMSearchHeaderView
    }
    
    override func awakeFromNib() {
        super.awakeFromNib()
        self.cancleBtn.layer.cornerRadius = 2
        self.cancleBtn.layer.masksToBounds = true
    }
    
    @IBAction func textFieldDidChange(sender: UITextField) {
        if let _ = self.textFieldBlock {
            self.textFieldBlock!(text: sender.text!)
        }
    }
    @IBAction func cancleBtnDidClick(sender: UIButton) {
        if let _ = self.block {
            self.block!()
        }
    }
    
    func textfieldDidChangeWithBlock (block : textFieldDidChangeBlock?) {
        self.textFieldBlock = block
    }

    func cancleBtnDidClickWithBlock (block : cancleBtnDidClickBlock?) {
        self.block = block
    }
}
