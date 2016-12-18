//
//  FindAppHeaderView.swift
//  beautifulApp-Swift3
//
//  Created by 梁亦明 on 2016/12/17.
//  Copyright © 2016年 xiaoming.com. All rights reserved.
//

import Foundation
// 代理
protocol FindAppHeaderViewDelegate {
    // 点击最热分享
    func hotBtnDidClick()
    // 点击最新分享
    func lastestBtnDidClick()
    // 点击菜单
    func menuBtnDidClick()
}

class FindAppHeaderView: UIView {
    override init(frame: CGRect) {
        super.init(frame: frame)
        addSubview(menuBtn)
        addSubview(centerView)
        centerView.addSubview(hotButton)
        centerView.addSubview(latestButton)
        setuplayout()
        
        selectorBtn = hotButton
        
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    
    @objc private func menuBtnDidClick() {
        delegate?.menuBtnDidClick()
    }
    
    @objc private func hotBtnDidClick() {
        guard selectorBtn != hotButton else {
            return
        }
        delegate?.hotBtnDidClick()
        
        selectorBtn.isSelected = false
        hotButton.isSelected = true
        selectorBtn = hotButton
    }
    
    @objc private func latestBtnDidClick() {
        guard selectorBtn != latestButton else {
            return
        }
        delegate?.lastestBtnDidClick()
        
        selectorBtn.isSelected = false
        latestButton.isSelected = true
        selectorBtn = latestButton
    }
    
    private func setuplayout() {
        menuBtn.snp.makeConstraints { (make) in
            make.width.equalTo(50)
            make.height.equalTo(self)
            make.top.left.equalTo(self)
        }
        
        centerView.snp.makeConstraints { (make) in
            make.width.equalTo(150)
            make.height.equalTo(25)
            make.center.equalTo(self.snp.center)
        }
        
        hotButton.snp.makeConstraints { (make) in
            make.width.equalTo(75)
            make.height.equalTo(centerView)
            make.left.top.equalTo(centerView)
        }
        
        latestButton.snp.makeConstraints { (make) in
            make.left.equalTo(hotButton.snp.right)
            make.width.height.equalTo(hotButton)
            make.top.equalTo(centerView)
        }
    }
    //MARK: --------------------------- Getter and Setter --------------------------
    var delegate: FindAppHeaderViewDelegate?
    
    /// 当前选中的btn
    var selectorBtn: UIButton!
    /// 菜单按钮
    fileprivate lazy var menuBtn: UIButton = {
        var menuBtn = UIButton()
        menuBtn.setImage(UIImage(named: "home_icon_sidebar_normal"), for: .normal)
        menuBtn.setImage(UIImage(named: "home_icon_sidebar_pressed"), for: .highlighted)
        menuBtn.addTarget(self, action: #selector(menuBtnDidClick), for: .touchUpInside)
        return menuBtn
    }()
    
    fileprivate lazy var centerView: UIView = {
        var centerView = UIView()
        centerView.backgroundColor = UIColor.clear
        return centerView
    }()
    
    fileprivate lazy var hotButton: UIButton = {
        var hotButton = UIButton()
        hotButton.isHighlighted = false
        hotButton.isSelected = true
        hotButton.titleLabel?.font = UIConstant.FONT_12
        hotButton.setBackgroundImage(UIImage.yy_image(with: UIColor.white), for: .selected)
        hotButton.setBackgroundImage(UIImage.yy_image(with: UIConstant.COLOR_APPNORMAL), for: .normal)
        hotButton.setTitle("最热分享", for: .normal)
        hotButton.setTitleColor(UIColor.white, for: .normal)
        hotButton.addTarget(self, action: #selector(hotBtnDidClick), for: .touchUpInside)
        hotButton.setTitleColor(UIConstant.COLOR_APPNORMAL, for: .selected)
        return hotButton
    }()
    
    fileprivate lazy var latestButton: UIButton = {
        var latestButton = UIButton()
        latestButton.titleLabel?.font = UIConstant.FONT_12
        latestButton.setBackgroundImage(UIImage.yy_image(with: UIColor.white), for: .selected)
        latestButton.setBackgroundImage(UIImage.yy_image(with: UIConstant.COLOR_APPNORMAL), for: .normal)
        latestButton.setTitle("最新分享", for: .normal)
        latestButton.setTitleColor(UIColor.white, for: .normal)
        latestButton.addTarget(self, action: #selector(latestBtnDidClick), for: .touchUpInside)
        latestButton.setTitleColor(UIColor(red: 55/255.0, green: 140/255.0, blue: 200/255.0, alpha: 1), for: .selected)
        return latestButton
    }()
}
