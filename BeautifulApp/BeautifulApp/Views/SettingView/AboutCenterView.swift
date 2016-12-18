//
//  AboutCenterView.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/28.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit
protocol AboutCenterViewDelegate {
    func AboutCenterViewOfficialWebViewDidClick()
    func AboutCenterViewWechatViewDidClick()
    func AboutCenterViewExonerateViewDidClick()
    func AboutCenterViewUserAgreementDidClick()
}

class AboutCenterView: UIView {

    @IBOutlet weak var officialWebView: UIView!
    @IBOutlet weak var wechatView: UIView!
    @IBOutlet weak var exonerateView: UIView!
    @IBOutlet weak var userAgreement: UIView!
    var delegate : AboutCenterViewDelegate?
    
    class func centerView () -> AboutCenterView {
        return Bundle.main.loadNibNamed("AboutCenterView", owner: nil, options: nil)!.first as! AboutCenterView
    }
    
    override func awakeFromNib() {
        super.awakeFromNib()
        self.officialWebView.viewAddTarget(target: self, action: #selector(AboutCenterView.officialWebViewDidClick))
        self.wechatView.viewAddTarget(target: self, action: #selector(AboutCenterView.wechatViewDidClick))
        self.exonerateView.viewAddTarget(target: self, action: #selector(AboutCenterView.exonerateViewDidClick))
        self.userAgreement.viewAddTarget(target: self, action: #selector(AboutCenterView.userAgreementDidClick))
    }
    
    func officialWebViewDidClick() {
        self.delegate?.AboutCenterViewOfficialWebViewDidClick()
    }
    func wechatViewDidClick() {
        self.delegate?.AboutCenterViewWechatViewDidClick()
    }
    func exonerateViewDidClick() {
        self.delegate?.AboutCenterViewExonerateViewDidClick()
    }
    func userAgreementDidClick() {
        self.delegate?.AboutCenterViewUserAgreementDidClick()
    }

}
