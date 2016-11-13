//
//  HomeHeaderView.swift
//  beautifulApp-Swift3
//
//  Created by 梁亦明 on 16/10/18.
//  Copyright © 2016年 xiaoming.com. All rights reserved.
//

import UIKit
import SnapKit

protocol HeaderViewDelegate {
    /// 点击回到首页按钮
    func headerViewMoveToFirstBtnDidClick(headerView: HomeHeaderView, moveToFirstBtn: UIButton)
    /// 点击菜单按钮
    func headerViewMenuBtnDidClick(headerViewl: HomeHeaderView, menuBtn: UIButton)
}

class HomeHeaderView: UIView {
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        self.backgroundColor = UIColor.red
        
        // 添加控件
        addSubview(menuBtn)
        addSubview(moveToFirstBtn)
        addSubview(dateLabel)
        addSubview(weekLabel)
        addSubview(rightTitleLabel)
    }
    
    
    /// 适配
    override func layoutSubviews() {
        setupLayout()
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    
    //MARK: --------------------------- Getter and Setter --------------------------
    
    /// 菜单按钮
    fileprivate lazy var menuBtn: UIButton = {
        var menuBtn = UIButton()
        menuBtn.setImage(UIImage(named: "home_icon_sidebar_normal"), for: .normal)
        menuBtn.setImage(UIImage(named: "home_icon_sidebar_pressed"), for: .highlighted)
        return menuBtn
    }()
    
    /// 返回到第一
    fileprivate lazy var moveToFirstBtn: UIButton = {
        var moveToFirstBtn = UIButton()
        moveToFirstBtn.setImage(UIImage(named: "backtohome_normal"), for: .normal)
        moveToFirstBtn.setImage(UIImage(named: "backtohome_pressed"), for: .highlighted)
        return moveToFirstBtn
    }()
    /// 日期
    fileprivate lazy var dateLabel: UILabel = {
        var dateLabel = UILabel()
        dateLabel.text = "12月03日"
        dateLabel.textAlignment = .left
        dateLabel.textColor = UIColor.white
        dateLabel.font = UIConstant.FONT_11
        return dateLabel
    }()
    /// 星期
    fileprivate lazy var weekLabel: UILabel = {
        var weekLabel = UILabel()
        weekLabel.text = "星期一"
        weekLabel.textAlignment = .left
        weekLabel.textColor = UIColor.white
        weekLabel.font = UIConstant.FONT_11
        return weekLabel
    }()
    /// 右边标题
    fileprivate lazy var rightTitleLabel: UILabel = {
        var rightTitleLabel = UILabel()
        //        rightTitleLabel.isHidden = true
        rightTitleLabel.text = "文章专栏"
        rightTitleLabel.textColor = UIColor.white
        rightTitleLabel.font = UIConstant.FONT_14
        return rightTitleLabel
    }()
    
    
}

//MARK: --------------------------- private methods --------------------------

extension HomeHeaderView {
    /// 适配屏幕
    fileprivate func setupLayout() {
        menuBtn.snp.makeConstraints { (make) in
            make.width.equalTo(50)
            make.height.equalTo(self)
            make.top.left.equalTo(self)
        }
        
        rightTitleLabel.snp.makeConstraints { (make) in
            make.width.equalTo(60)
            make.right.equalTo(self).inset(UIConstant.MARGIN_10)
            make.top.equalTo(self).offset(UIConstant.MARGIN_10)
            make.bottom.equalTo(self).inset(UIConstant.MARGIN_10)
        }
        
        dateLabel.snp.makeConstraints { (make) in
            make.width.equalTo(50)
            make.height.equalTo(15)
            make.right.equalTo(self).inset(UIConstant.MARGIN_10)
            make.top.equalTo(self).offset((self.height-2*15)*0.5)
        }
        
        weekLabel.snp.makeConstraints { (make) in
            make.width.equalTo(dateLabel)
            make.height.equalTo(dateLabel)
            make.right.equalTo(dateLabel)
            make.top.equalTo(dateLabel.snp.bottom)
        }
        
        moveToFirstBtn.snp.makeConstraints { (make) in
            make.width.equalTo(self.height-2*UIConstant.MARGIN_10)
            make.height.equalTo(self.height-2*UIConstant.MARGIN_10)
            make.right.equalTo(rightTitleLabel.snp.left)
            make.top.equalTo(self).offset(UIConstant.MARGIN_10)
            make.bottom.equalTo(self).inset(UIConstant.MARGIN_10)
        }
    }
    
}
