//
//  XMFindAppHeaderView.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/24.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

// 代理
protocol XMFindAppHeaderViewDelegate {
    // 点击最热分享
    func findAppHeaderViewHotBtnDidClick(headerView : XMFindAppHeaderView, hotBtn : UIButton)
    // 点击最新分享
    func findAppHeaderViewLastestBtnDidClick(headerView : XMFindAppHeaderView, lastestBtn : UIButton)
    // 点击菜单
    func findAppHeaderViewMenuBtnDidClick(headerView : XMFindAppHeaderView, menuBtn : UIButton)
    // 点击添加APP
    func findAppHeaderViewAddBtnDidClick(headerView : XMFindAppHeaderView, addBtn : UIButton)
}

class XMFindAppHeaderView: UIView {
    // 最热
    @IBOutlet weak var hotButton: UIButton!
    // 最新
    @IBOutlet weak var latestButton: UIButton!
    
    // 当前选中
    private weak var indexButton : UIButton!
    
    var delegate : XMFindAppHeaderViewDelegate?

    class func headerView () -> XMFindAppHeaderView {
        return NSBundle.mainBundle().loadNibNamed("XMFindAppHeaderView", owner: nil, options: nil).first as! XMFindAppHeaderView
    }

    override func awakeFromNib() {
        super.awakeFromNib()
        // 默认选中第一个
        self.indexButton = self.hotButton
    }
    
    //MARK: -Event Action
    
    // 点击最热分享
    @IBAction func hotBtnDidClick(sender: UIButton) {
        guard self.indexButton != sender else {
            return
        }
        delegate?.findAppHeaderViewHotBtnDidClick(self, hotBtn: sender)
        self.selectIndex(sender)
    }
    
    // 点击最新分享
    @IBAction func lastestBtnDidClick(sender: UIButton) {
        guard self.indexButton != sender else {
            return
        }
        delegate?.findAppHeaderViewLastestBtnDidClick(self, lastestBtn: sender)
        self.selectIndex(sender)
    }
    // 添加应用按钮
    @IBAction func addBtnDidClick(sender: UIButton) {
        delegate?.findAppHeaderViewAddBtnDidClick(self, addBtn: sender)
    }
    // 点击菜单按钮
    @IBAction func menuBtnDidClick(sender: AnyObject) {
        delegate?.findAppHeaderViewMenuBtnDidClick(self, menuBtn: sender as! UIButton)
    }
    //MARK : private 
    private func selectIndex(selectBtn : UIButton) {
        self.indexButton.selected = false
        self.indexButton.backgroundColor = UIColor.clearColor()
        selectBtn.backgroundColor = UIColor.whiteColor()
        selectBtn.selected = true
        self.indexButton = selectBtn
    }
    
}
