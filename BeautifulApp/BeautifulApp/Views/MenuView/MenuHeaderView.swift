//
//  MenuHeaderView.swift
//  beautifulApp-Swift3
//
//  Created by 梁亦明 on 2016/12/2.
//  Copyright © 2016年 xiaoming.com. All rights reserved.
//

import Foundation


class MenuHeaderView: UIView {
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        
        addSubview(loginImageView)
        addSubview(loginLabel)
        
        loginImageView.snp.makeConstraints { (make) in
            make.size.equalTo(CGSize(width: 50, height: 50))
            make.left.equalTo(self).offset(25)
            make.top.equalTo(self).offset(30)
        }
        
        loginLabel.snp.makeConstraints { (make) in
            make.left.equalTo(loginImageView.snp.right).offset(15)
            make.centerY.equalTo(loginImageView.snp.centerY)
            make.right.equalTo(self)
            make.height.equalTo(20)
        }
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    
    //MARK: --------------------------- Getter and Setter --------------------------
    fileprivate lazy var loginImageView: UIImageView = {
        var loginImageView : UIImageView = UIImageView(image: UIImage(named: "detail_portrait_default"))
        loginImageView.addCorner(radius: 50)
        loginImageView.contentMode = .scaleAspectFit
        return loginImageView
    }()
    
    /// 标题
    fileprivate lazy var loginLabel: UILabel = {
        var loginLabel = UILabel()
        loginLabel.text = "微博 @_亦明"
        loginLabel.font = UIConstant.FONT_16
        loginLabel.textColor = UIColor.white
        return loginLabel
    }()
}
