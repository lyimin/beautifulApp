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
    
    convenience init(model : XMHomeDataModel){
        self.init()
        self.model = model
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.automaticallyAdjustsScrollViewInsets = false
        let centerView : XMHomeDetailCenterView = XMHomeDetailCenterView.centerView()
        centerView.model = model
        centerView.delegate = self
        self.view.addSubview(centerView)
        // 解析html

    }
    
    // MARK:1-Custer Delegate
    func homeDetailCenterView(centerView: XMHomeDetailCenterView, returnButtonDidClick returnButton: UIButton) {
        self.navigationController?.popViewControllerAnimated(true)
    }
    
    override func preferredStatusBarStyle() -> UIStatusBarStyle {
        return UIStatusBarStyle.Default
    }
    
    
}
