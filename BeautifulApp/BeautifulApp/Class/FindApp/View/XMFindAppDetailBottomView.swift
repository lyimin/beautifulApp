//
//  XMFindAppDetailBottomView.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/12/7.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMFindAppDetailBottomView: UIScrollView {
    // 点赞回调
    typealias praiseViewDidClickBlock = () -> Void
    var priaiseblock : praiseViewDidClickBlock?
    // 不喜欢回调
    typealias unlikeViewDidClickBlock = () -> Void
    var unlikeblock : unlikeViewDidClickBlock?
    // 赞view
    @IBOutlet weak var praiseView: UIView!
    @IBOutlet weak var praiseViewNumberLabel: UILabel!
    @IBOutlet weak var praiseViewIcon: UIImageView!
    @IBOutlet weak var praiseLabel: UILabel!
    
    // 不喜欢view
    @IBOutlet weak var unLikeView: UIView!
    @IBOutlet weak var unLikeIconView: UIImageView!
    @IBOutlet weak var unLikeLabel: UILabel!
    
    @IBOutlet weak var centerView: UIView!
    
    var praiseCount : String? {
        willSet {
            self.praiseCount = newValue
        }
        
        didSet {
            self.praiseViewNumberLabel.text = praiseCount!
        }
    }
    
    override func awakeFromNib() {
        super.awakeFromNib()
        
        // 添加模糊背景
        let blurEffect : UIBlurEffect = UIBlurEffect(style: .Light)
        let blurView : UIVisualEffectView = UIVisualEffectView(effect: blurEffect)
        blurView.frame = self.centerView.frame
        self.addSubview(blurView)
        self.bringSubviewToFront(centerView)
        
        // 添加点击事件
        self.praiseView.viewAddTarget(self, action: "praiseViewDidClick")
        self.unLikeView.viewAddTarget(self, action: "unLikeViewDidClick")
    }
    
    func praiseViewDidClick() {
        if let _ = self.priaiseblock {
            self.priaiseblock!()
        }
    }
    
    func praiseViewDidClickWithBlock(priaiseblock : praiseViewDidClickBlock?) {
        self.priaiseblock = priaiseblock
    }
    
    func unLikeViewDidClick() {
        if let _ = self.unlikeblock {
            self.unlikeblock!()
        }
    }
    
    func unLikeViewDidClickWithBlock (unlikeblock : unlikeViewDidClickBlock?) {
        self.unlikeblock = unlikeblock
    }
    
    
    class func bottomView () -> XMFindAppDetailBottomView {
        return NSBundle.mainBundle().loadNibNamed("XMFindAppDetailBottomView", owner: nil, options: nil).first as! XMFindAppDetailBottomView
    }
}
