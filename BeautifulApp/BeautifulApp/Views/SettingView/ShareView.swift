//
//  shareView.swift
//  ifanr
//
//  Created by sys on 16/7/30.
//  Copyright © 2016年 ifanrOrg. All rights reserved.
//

import UIKit

public protocol ShareViewDelegate: class {
    // 微信朋友
    func weixinShareButtonDidClick();
    // 朋友圈
    func friendsCircleShareButtonDidClick();
    // 更多
    func shareMoreButtonDidClick();
}

public class ShareView: UIView {
    
    var delegate: ShareViewDelegate?
    
    //MARK:-----Life Circle-----
    override init(frame: CGRect) {
        super.init(frame: frame)
        self.addSubview(weixinShareButton)
        self.addSubview(friendsCircleShareButton)
        self.addSubview(shareMoreButton)
        self.addSubview(logoShareImageView)
        self.addSubview(titleLabel)
        
        self.addSubview(weixinShareLabel)
        self.addSubview(shareMoreLabel)
        self.addSubview(friendsCircleShareLabel)
        
        self.backgroundColor = UIColor(red: 250/255.0, green: 250/255.0, blue: 250/255.0, alpha: 1.0)
        
        self.setupLayout()
    }
    
    required public init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    //Mark:-----Private Function-----
    func setupLayout() {
        logoShareImageView.snp.makeConstraints { (make) in
            make.top.left.equalTo(self).offset(20)
            make.height.width.equalTo(13)
        }
        titleLabel.snp.makeConstraints { (make) in
            make.left.equalTo(logoShareImageView.snp.right).offset(10)
            make.width.equalTo(150)
            make.height.equalTo(30)
            make.centerY.equalTo(logoShareImageView)
        }
        weixinShareButton.snp.makeConstraints { (make) in
            make.top.equalTo(logoShareImageView.snp.bottom).offset(30)
            make.left.equalTo(self).offset(30)
            make.width.equalTo(50)
            make.height.equalTo(50)
        }
        
        friendsCircleShareButton.snp.makeConstraints { (make) in
            make.top.equalTo(logoShareImageView.snp.bottom).offset(30)
            make.centerX.equalTo(self)
            make.width.height.equalTo(50)
        }
        
        shareMoreButton.snp.makeConstraints { (make) in
            make.top.equalTo(logoShareImageView.snp.bottom).offset(30)
            make.right.equalTo(self).offset(-30)
            make.width.height.equalTo(50)
        }
        
        weixinShareLabel.snp.makeConstraints { (make) in
            make.top.equalTo(weixinShareButton.snp.bottom).offset(10)
            make.centerX.equalTo(weixinShareButton)
            make.width.equalTo(150)
        }
        
        friendsCircleShareLabel.snp.makeConstraints { (make) in
            make.top.equalTo(friendsCircleShareButton.snp.bottom).offset(10)
            make.centerX.equalTo(friendsCircleShareButton)
            make.width.equalTo(150)
        }
        
        shareMoreLabel.snp.makeConstraints { (make) in
            make.top.equalTo(shareMoreButton.snp.bottom).offset(10)
            make.centerX.equalTo(shareMoreButton)
            make.width.equalTo(150)
        }
        
    }
    
    //Mark:-----Action-----
    func weixinShareAction() {
        self.delegate?.weixinShareButtonDidClick()
    }
    
    func friendsCircleShareAction() {
        self.delegate?.friendsCircleShareButtonDidClick()
    }
    
    func shareMoreAction() {
        self.delegate?.shareMoreButtonDidClick()
    }
    
    //MARK:-----Setter Getter-----
    /// 微信朋友
    private lazy var weixinShareButton: UIButton = {
        let weixinShareButton = UIButton()
        weixinShareButton.setImage(UIImage(named: "share_wechat"), for: .normal)
        weixinShareButton.setTitle("微信朋友", for: .normal)
        weixinShareButton.setTitleColor(UIColor.black, for: .normal)
        weixinShareButton.imageView?.contentMode = .scaleAspectFit
        weixinShareButton.addTarget(self, action: #selector(weixinShareAction), for: .touchUpInside)
        
        return weixinShareButton
    }()
    private lazy var weixinShareLabel: UILabel = {
        let weixinShareLabel = UILabel()
        weixinShareLabel.text = "微信朋友"
        weixinShareLabel.textAlignment = .center
        weixinShareLabel.textColor = UIColor(red: 82/255.0, green: 78/255.0, blue: 80/255.0, alpha: 1.0)
        weixinShareLabel.font = UIFont.systemFont(ofSize: 13)
        
        return weixinShareLabel
    }()
    /// 朋友圈
    private lazy var friendsCircleShareButton: UIButton = {
        let friendsCircleShareButton = UIButton()
        friendsCircleShareButton.setImage(UIImage(named: "share_wechat_moment"), for: .normal)
        friendsCircleShareButton.setTitle("朋友圈", for: .normal)
        friendsCircleShareButton.addTarget(self, action: #selector(friendsCircleShareAction), for: .touchUpInside)
        
        return friendsCircleShareButton
    }()
    private lazy var friendsCircleShareLabel: UILabel = {
        let friendsCircleShareLabel = UILabel()
        friendsCircleShareLabel.text = "朋友圈"
        friendsCircleShareLabel.textColor = UIColor(red: 82/255.0, green: 78/255.0, blue: 80/255.0, alpha: 1.0)
        friendsCircleShareLabel.textAlignment = .center
        friendsCircleShareLabel.font = UIFont.systemFont(ofSize: 13)
        
        return friendsCircleShareLabel
    }()
    /// 分享更多
    private lazy var shareMoreButton: UIButton = {
        let shareMoreButton = UIButton()
        shareMoreButton.setImage(UIImage(named: "share_more"), for: .normal)
        shareMoreButton.setTitle("更多", for: .normal)
        shareMoreButton.addTarget(self, action: #selector(shareMoreAction), for: .touchUpInside)
        
        return shareMoreButton
    }()
    private lazy var shareMoreLabel: UILabel = {
        let shareMoreLabel = UILabel()
        shareMoreLabel.text = "更多"
        shareMoreLabel.textAlignment = .center
        shareMoreLabel.textColor = UIColor(red: 82/255.0, green: 78/255.0, blue: 80/255.0, alpha: 1.0)
        shareMoreLabel.font = UIFont.systemFont(ofSize: 13)
        
        return shareMoreLabel
    }()
    /// logo
    private lazy var logoShareImageView: UIImageView = {
        let logoShareImageView = UIImageView()
        logoShareImageView.image = UIImage(named: "ic_dialog_share")
        
        return logoShareImageView
    }()
    /// titleLabel
    private lazy var titleLabel: UILabel = {
        let titleLabel = UILabel()
        titleLabel.text = "分享文章给朋友:"
        titleLabel.font = UIFont.systemFont(ofSize: 14.0)
        titleLabel.textColor = UIColor(red: 124/255.0, green: 129/255.0, blue: 142/255.0, alpha: 1.0)
        
        return titleLabel
    }()
}
