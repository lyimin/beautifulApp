//
//  XMFindAppDetailController.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/12/1.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMFindAppDetailController: UIViewController, FindAppDetailCenterViewDelegate {
    // 界面
    private weak var centerView : XMFindAppDetailCenterView!
    private weak var bottomView : XMFindAppDetailBottomView!
    // 模型
    private var model : XMFindAppModel!
    override func viewDidLoad() {
        super.viewDidLoad()
        self.view.backgroundColor = UIColor.whiteColor()
        self.automaticallyAdjustsScrollViewInsets = false

        let centerView : XMFindAppDetailCenterView = XMFindAppDetailCenterView.AppDetailCenterView()
        self.centerView = centerView
        centerView.delegate = self
        centerView.dataModel = model
        self.view.addSubview(centerView)
        
        let bottomView : XMFindAppDetailBottomView = XMFindAppDetailBottomView.bottomView()
        bottomView.praiseCount = model.up_times!
        bottomView.contentSize = CGSize(width: SCREEN_WIDTH*2, height: 0)
        bottomView.y = self.view.height - bottomView.height
        self.bottomView = bottomView
        self.view.addSubview(bottomView)
        
        self.view.bringSubviewToFront(bottomView)
    }
    
    convenience init(model : XMFindAppModel) {
        self.init()
        self.model = model
    }
    
    //MARK:- CenterViewDelegate
    func FindAppDetailCenterViewReturnBtnDidClick() {
        self.navigationController?.popViewControllerAnimated(true)
    }
    
    func FindAppDetailShareBtnDidClick() {
        
    }
    
    func FindAppDetailDownLoadBtnDidClick() {
        
        let downModel : XMFindAppDownloadModel = model.download_urls.first!
        UIApplication.sharedApplication().openURL(NSURL(string: downModel.url!)!)
    }
    
    
}
