//
//  AboutViewController.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/28.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit
import SafariServices

class AboutViewController: UIViewController, AboutCenterViewDelegate {
    private weak var headerView : SettingHeaderView!
    override func viewDidLoad() {
        super.viewDidLoad()
        self.setupNavView()
        centerView.delegate = self
        self.view.addSubview(centerView)
    }
    
    // MARK: - centerView delegate
    func AboutCenterViewOfficialWebViewDidClick() {
        // 官网地址
        let officialURL = "http://zuimeia.com/apps/?platform=1&utm_source=iosapp&utm_campaign=referral&utm_medium=about"
        UIApplication.sharedApplication().openURL(NSURL(string: officialURL)!)
    }
    func AboutCenterViewWechatViewDidClick() {
        let pasteboard : UIPasteboard = UIPasteboard.generalPasteboard()
        pasteboard.string = "最美应用";
        let alert : UIAlertController = UIAlertController(title: "提示", message: "复制微信公众账号成功^_^\n跳转到微信关注我们", preferredStyle: UIAlertControllerStyle.Alert)
        let cancleAction : UIAlertAction = UIAlertAction(title: "取消", style: UIAlertActionStyle.Cancel, handler: nil)
        let enterAction : UIAlertAction = UIAlertAction(title: "确定", style: UIAlertActionStyle.Default) { (enter) -> Void in
            
        }

        alert.addAction(cancleAction)
        alert.addAction(enterAction)
        self.presentViewController(alert, animated: true, completion: nil)
    }
    func AboutCenterViewExonerateViewDidClick() {
        let exonerateURL = "http://zuimeia.com/article/74/"
        let safaController : SFSafariViewController = SFSafariViewController(URL: NSURL(string: exonerateURL)!)
        self.presentViewController(safaController, animated: true, completion: nil)
    }
    func AboutCenterViewUserAgreementDidClick() {
        let userAgressURL = "http://zuimeia.com/article/69/"
        let safaController : SFSafariViewController = SFSafariViewController(URL: NSURL(string: userAgressURL)!)
        self.presentViewController(safaController, animated: true, completion: nil)
    }
    
    // MARK: - private
    private func setupNavView() {
        let headerView : SettingHeaderView = SettingHeaderView.headerView()
        self.headerView = headerView
        headerView.title.text = "关于我们"
        headerView.y = 0
        headerView.backBtnDidClickWithBlock { [unowned self]() -> Void in
            self.navigationController?.popViewControllerAnimated(true)
        }
        self.view.addSubview(headerView)
    }
    
    // MARK: - getter or setter 
    
    private var centerView : AboutCenterView = {
        let centerView = AboutCenterView.centerView()
        centerView.y = 64
        return centerView
    }()
}
