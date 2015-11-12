//
//  XMHomeHeaderView.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/9.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

protocol XMHomeHeaderViewDelegate {
    func homeHeaderViewMoveToFirstDidClick(headerView : XMHomeHeaderView, moveToFirstBtn : UIButton)
    func homeHeaderViewMenuDidClick(header : XMHomeHeaderView, menuBtn : UIButton)
}

class XMHomeHeaderView: UIView {
    
    // 返回到第一
    @IBOutlet weak var moveToFirstBtn: UIButton!
    // 日期
    @IBOutlet weak var dateLabel: UILabel!
    // 星期
    @IBOutlet weak var weakLabel: UILabel!

    var delegate : XMHomeHeaderViewDelegate?
    
    var homeModel : XMHomeDataModel! {
        willSet {
            self.homeModel = newValue
        }
        
        didSet {
            if NSDate.isToday(homeModel.publish_date!) {
                self.dateLabel.text = "今天"
                self.hiddenMoveToFirstAnimation()
            } else if NSDate.isLastDay(homeModel.publish_date!) {
                self.dateLabel.text = "昨天"
                self.hiddenMoveToFirstAnimation()
            } else {
                self.dateLabel.text = NSDate.formattDay(homeModel.publish_date!)
                self.showMoveToFirstAnimation()
            }
            self.weakLabel.text = NSDate.weekWithDateString (homeModel.publish_date!)
        }
    }
    
    class func headerView () -> XMHomeHeaderView {
        return NSBundle.mainBundle().loadNibNamed("XMHomeHeaderView", owner: nil, options: nil).first as! XMHomeHeaderView
    }
    //MARK: --- ACTION EVENT
    
    // 点击菜单
    @IBAction func menuImgDidClick(sender: UIButton) {
    }
    // 点击返回第一
    @IBAction func moveToFirstImgDidClick(sender: UIButton) {
        self.delegate?.homeHeaderViewMoveToFirstDidClick(self, moveToFirstBtn: sender)
        self.showMoveToFirstAnimation()
    }
    
    //MARK: --- PRIVATE 
    private func hiddenMoveToFirstAnimation() {
        UIView.animateWithDuration(0.2, delay: 0.0, options: UIViewAnimationOptions.CurveEaseInOut, animations: { () -> Void in
            self.moveToFirstBtn.alpha = 0
            }, completion: nil)
    }
    
    private func showMoveToFirstAnimation() {
        UIView.animateWithDuration(0.2, delay: 0.0, options: UIViewAnimationOptions.CurveEaseInOut, animations: { () -> Void in
            self.moveToFirstBtn.alpha = 1
            }, completion: nil)
    }
}
