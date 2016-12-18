//
//  XMFindAppDetailTooView.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/12/10.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

protocol FindAppDetailToolViewDelegate {
    func shareBtnClick()
    func downloadBtnClick()
}
class FindAppDetailToolView: UIView {
    @IBOutlet weak var shareBtn: UIButton!
    @IBOutlet weak var shareLabel: UILabel!
    @IBOutlet weak var downloadBtn: UIButton!
    @IBOutlet weak var downloadLabel: UILabel!

    var delegate: FindAppDetailToolViewDelegate?
    class func toolView() -> FindAppDetailToolView {
        return Bundle.main.loadNibNamed("FindAppDetailToolView", owner: nil, options: nil)!.first as! FindAppDetailToolView
    }
    
    
    @IBAction func shareBtnClick(sender: UIButton) {
        self.delegate?.shareBtnClick()
    }
    
    @IBAction func downloadBtnClick(sender: UIButton) {
        self.delegate?.downloadBtnClick()
    }

}
