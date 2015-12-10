//
//  XMHomeDetailToolView.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/12/8.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

protocol XMHomeDetailToolViewDelegate {
    func homeDetailToolViewCollectBtnClick()
    func homeDetailToolViewShareBtnClick()
    func homeDetailToolViewDownloadBtnClick()
}

class XMHomeDetailToolView: UIView {
    // 收藏按钮
    @IBOutlet weak var collectButton: UIButton!
    @IBOutlet weak var collectLabel: UILabel!
    // 分享
    @IBOutlet weak var shareButton: UIButton!
    @IBOutlet weak var shareLabel: UILabel!
    // 下载
    @IBOutlet weak var downloadButton: UIButton!
    @IBOutlet weak var downloadLabel: UILabel!
    
    var delegate : XMHomeDetailToolViewDelegate?
  
    class func toolView() -> XMHomeDetailToolView {
        return NSBundle.mainBundle().loadNibNamed("XMHomeDetailToolView", owner: nil, options: nil)[0] as! XMHomeDetailToolView
    }
    
    @IBAction func collectionDidClick(sender: UIButton) {
        self.delegate?.homeDetailToolViewCollectBtnClick()
    }
    @IBAction func shareDidClick(sender: UIButton) {
        self.delegate?.homeDetailToolViewShareBtnClick()
    }
    
    @IBAction func downloadDidClick(sender: UIButton) {
        self.delegate?.homeDetailToolViewDownloadBtnClick()
    }
}
