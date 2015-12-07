//
//  XMHomeDetailController.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/19.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMHomeDetailController: UIViewController, XMHomeDetailCenterViewDelegate {
    private var model : XMHomeDataModel!
    private weak var bottomView : XMFindAppDetailBottomView!
    convenience init(model : XMHomeDataModel){
        self.init()
        self.model = model
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.automaticallyAdjustsScrollViewInsets = false
        let centerView : XMHomeDetailCenterView = XMHomeDetailCenterView.detailCenterView()
        centerView.model = model
        centerView.delegate = self
        self.view.addSubview(centerView)

        
        let bottomView : XMFindAppDetailBottomView = XMFindAppDetailBottomView.bottomView()
        bottomView.praiseCount = model.info?.fav!
        bottomView.contentSize = CGSize(width: SCREEN_WIDTH*2, height: 0)
        bottomView.y = self.view.height - bottomView.height
        self.bottomView = bottomView
        self.view.addSubview(bottomView)
        
        self.view.bringSubviewToFront(bottomView)
    }
    
    // MARK:1-Custer Delegate
    func homeDetailCenterView(centerView: XMHomeDetailCenterView, returnButtonDidClick returnButton: UIButton) {
        self.navigationController?.popViewControllerAnimated(true)
    }
    // 点击收藏
    func homeDetailCenterViewCollectDidClick(centerView: XMHomeDetailCenterView) {
        
    }
    // 点击分享
    func homeDetailCenterViewShareDidClick(centerView: XMHomeDetailCenterView) {
        
    }
    
    // 点击下载
    func homeDetailCenterViewDownloadDidClick(centerView: XMHomeDetailCenterView) {
        UIApplication.sharedApplication().openURL(NSURL(string: model.download_url!)!)
    }
    
    // 点击下面的分享
    func homeDetailCenterViewBottomShareDidClick(centerView: XMHomeDetailCenterView) {
        print("分享到qq空间")
    }
    
    
    
    override func preferredStatusBarStyle() -> UIStatusBarStyle {
        return UIStatusBarStyle.Default
    }
    
    
}
