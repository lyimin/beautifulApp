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
    // 模型
    private var model : XMFindAppModel!
    override func viewDidLoad() {
        super.viewDidLoad()
        self.automaticallyAdjustsScrollViewInsets = false

        let centerView : XMFindAppDetailCenterView = XMFindAppDetailCenterView.AppDetailCenterView()
        self.centerView = centerView
        centerView.delegate = self
        centerView.dataModel = model
        self.view.addSubview(centerView)
    }
    
    convenience init(model : XMFindAppModel) {
        self.init()
        self.model = model
    }
    
    // centerViewDelegate 
    func FindAppDetailCenterViewReturnBtnDidClick() {
        self.navigationController?.popViewControllerAnimated(true)
    }
    
    
}
