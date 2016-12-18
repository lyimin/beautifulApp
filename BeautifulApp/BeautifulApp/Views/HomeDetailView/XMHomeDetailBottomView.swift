//
//  XMHomeDetailBottomView.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/12/10.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMHomeDetailBottomView: UIScrollView {

    override init(frame: CGRect) {
        super.init(frame: frame)
        let centerView = UIView(frame: CGRect(x: 0, y: 0, width: 2*UIConstant.SCREEN_WIDTH, height: 40))
        centerView.backgroundColor = UIColor.clear
        self.addSubview(centerView)
        
        // 模糊背景
        let blurEffect = UIBlurEffect(style: .light)
        let blurView : UIVisualEffectView = UIVisualEffectView(effect: blurEffect)
        blurView.frame = centerView.frame
        centerView.addSubview(blurView)
        
        // 添加控件
        let bottomStateView : UIView = Bundle.main.loadNibNamed("XMHomeDetailStateView", owner: nil, options: nil)!.first as! UIView
        bottomStateView.frame = CGRect(x: 0, y: 0, width: UIConstant.SCREEN_WIDTH, height: 40)
        
        let bottomCommentView : UIView = Bundle.main.loadNibNamed("XMHomeDetailCommentView", owner: nil, options: nil)!.first as! UIView
        bottomCommentView.frame = CGRect(x: UIConstant.SCREEN_WIDTH, y: 0, width: UIConstant.SCREEN_WIDTH, height: 40)
        
        centerView.addSubview(bottomStateView)
        centerView.addSubview(bottomCommentView)
        
        self.addSubview(centerView)
        // 设置属性
        self.backgroundColor = UIColor.clear
        self.showsHorizontalScrollIndicator = false
        self.isPagingEnabled = true
        self.contentSize = CGSize(width: UIConstant.SCREEN_WIDTH*2, height: 0)
    }
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
