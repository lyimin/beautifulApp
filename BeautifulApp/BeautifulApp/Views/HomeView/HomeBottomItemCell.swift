//
//  HomeBottomItemCell.swift
//  beautifulApp-Swift3
//
//  Created by 梁亦明 on 16/11/29.
//  Copyright © 2016年 xiaoming.com. All rights reserved.
//

import Foundation


class HomeBottomItemCell: UICollectionViewCell, Reusable {
    override init(frame: CGRect) {
        super.init(frame: frame)
        self.backgroundColor = UIColor.white
        layer.cornerRadius = 8
        
        addSubview(iconView)
    }
    
    override func layoutSubviews() {
        super.layoutSubviews()
        
        iconView.snp.makeConstraints { (make) in
            make.left.top.equalTo(self).offset(2)
            make.right.equalTo(self).inset(2)
            make.width.equalTo(iconView.snp.height).multipliedBy(1)
        }
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    var iconURL: String! {
        didSet {
            self.iconView.nice_setImage(imageURL: URL(string: iconURL), imageCornerRadius: 8)
        }
    }
    
    //MARK: --------------------------- Getter and Setter --------------------------
    /// 图片
    fileprivate lazy var iconView: UIImageView = {
        var iconView = UIImageView()
        return iconView
    }()
}
