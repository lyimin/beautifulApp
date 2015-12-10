//
//  XMFindAppDetailTooView.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/12/10.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

protocol XMFindAppDetailToolViewDelegate {
    func XMFindAppDetailToolViewShareBtnClick()
    func XMFindAppDetailToolViewDownloadBtnClick()
}
class XMFindAppDetailToolView: UIView {
    @IBOutlet weak var shareBtn: UIButton!
    @IBOutlet weak var shareLabel: UILabel!
    @IBOutlet weak var downloadBtn: UIButton!
    @IBOutlet weak var downloadLabel: UILabel!

    var delegate : XMFindAppDetailToolViewDelegate?
    class func toolView() -> XMFindAppDetailToolView {
        return NSBundle.mainBundle().loadNibNamed("XMFindAppDetailToolView", owner: nil, options: nil).first as! XMFindAppDetailToolView
    }
    
    
    @IBAction func shareBtnClick(sender: UIButton) {
        self.delegate?.XMFindAppDetailToolViewShareBtnClick()
    }
    
    @IBAction func downloadBtnClick(sender: UIButton) {
        self.delegate?.XMFindAppDetailToolViewDownloadBtnClick()
    }

}
