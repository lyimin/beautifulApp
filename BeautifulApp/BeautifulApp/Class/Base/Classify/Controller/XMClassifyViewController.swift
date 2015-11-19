//
//  XMClassifyViewController.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/16.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMClassifyViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        self.view.backgroundColor = UI_COLOR_APPNORMAL
        self.view.addSubview(centerView)
    }
    
    //MARK:- getter or Setter
    
    private var centerView : XMClassifyCenterView = {
        let centerView : XMClassifyCenterView = XMClassifyCenterView.centerView()
        return centerView
    }()

}
