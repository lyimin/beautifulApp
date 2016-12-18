//
//  MenuFooterView.swift
//  beautifulApp-Swift3
//
//  Created by 梁亦明 on 2016/12/18.
//  Copyright © 2016年 xiaoming.com. All rights reserved.
//

import Foundation

protocol MenuFooterViewDelegate {
    func searchBtnDidClick()
    func inviteBtnDidClick()
    func settingBtnDidClick()
}

class MenuFooterView: UIView {
    override init(frame: CGRect) {
        super.init(frame: frame)
        
        addSubview(sepView)
        addSubview(searchBtn)
        addSubview(inviteBtn)
        addSubview(settingBtn)
        
        setupLayout()
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    @objc fileprivate func searchBtnDidClick() {
        delegate.searchBtnDidClick()
    }
    
    @objc fileprivate func inviteBtnDidClick() {
        delegate.inviteBtnDidClick()
    }
    
    @objc fileprivate func settingBtnDidClick() {
        delegate.settingBtnDidClick()
    }
    
    //MARK: --------------------------- Getter and Setter --------------------------
    var delegate: MenuFooterViewDelegate!
    // 分割线
    fileprivate lazy var sepView: UIView = {
        var sepView = UIView()
        sepView.backgroundColor = UIColor.white
        return sepView
    }()
    
    // 搜索按钮
    fileprivate lazy var searchBtn: UIButton = {
        var searchBtn = UIButton()
        searchBtn.addTarget(self, action: #selector(searchBtnDidClick), for: .touchUpInside)
        searchBtn.setImage(UIImage(named: "sidebar_bottomicon_search_normal"), for: .normal)
        return searchBtn
    }()
    
    // 招聘按钮
    fileprivate lazy var inviteBtn: UIButton = {
        var inviteBtn = UIButton()
        inviteBtn.setTitleColor(UIColor.white, for: .normal)
        inviteBtn.titleLabel?.font = UIConstant.FONT_16
        inviteBtn.addTarget(self, action: #selector(inviteBtnDidClick), for: .touchUpInside)
        inviteBtn.setTitle("招聘编辑", for: .normal)
        return inviteBtn
    }()
    
    // 设置按钮
    fileprivate lazy var settingBtn: UIButton = {
        var settingBtn = UIButton()
        settingBtn.addTarget(self, action: #selector(settingBtnDidClick), for: .touchUpInside)
        settingBtn.setImage(UIImage(named: "sidebar_icon_more_normal"), for: .normal)
        return settingBtn
    }()
}

extension MenuFooterView {
    fileprivate func setupLayout() {
        sepView.snp.makeConstraints { (make) in
            make.left.equalTo(self).offset(UIConstant.MARGIN_20)
            make.height.equalTo(1)
            make.right.top.equalTo(self)
        }
        
        searchBtn.snp.makeConstraints { (make) in
            make.left.equalTo(sepView)
            make.width.height.equalTo(25)
            make.bottom.equalTo(self).inset(8)
        }
        
        inviteBtn.snp.makeConstraints { (make) in
            make.centerX.equalTo(self.snp.centerX)
            make.width.equalTo(100)
            make.height.equalTo(20)
            make.bottom.equalTo(self).inset(UIConstant.MARGIN_10)
        }
        
        settingBtn.snp.makeConstraints { (make) in
            make.width.height.bottom.equalTo(searchBtn)
            make.right.equalTo(self).inset(UIConstant.MARGIN_20)
        }
    }
}
