//
//  HomeController.swift
//  beautifulApp-Swift3
//
//  Created by 梁亦明 on 16/10/18.
//  Copyright © 2016年 xiaoming.com. All rights reserved.
//

import UIKit

class HomeController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        self.view.backgroundColor = UIColor.white
        
        
        view.addSubview(headerView)
        
        headerView.snp.makeConstraints { (make) in
            make.left.top.right.equalTo(self.view)
            make.height.equalTo(UIConstant.SCREEN_HEIGHT*50/UIConstant.IPHONE5_HEIGHT)
        }
    }
    
    private lazy var headerView: HomeHeaderView = {
        var headerView = HomeHeaderView()
        return headerView
    }()
}
