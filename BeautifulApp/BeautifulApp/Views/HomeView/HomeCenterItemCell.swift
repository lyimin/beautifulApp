//
//  HomeCenterItemCell.swift
//  beautifulApp-Swift3
//
//  Created by 梁亦明 on 16/10/21.
//  Copyright © 2016年 xiaoming.com. All rights reserved.
//

import UIKit

class HomeCenterItemCell: UICollectionViewCell, Reusable {
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        self.backgroundColor = UIColor.white
        self.layer.cornerRadius = 5
        
        addSubview(titleLabel)
        addSubview(subTitleLabel)
        addSubview(coverImageView)
        addSubview(detailLabel)
        addSubview(praiseCoverView)
        addSubview(praiseImageView)
        addSubview(praiseLabel)
        addSubview(authorNameLabel)
    }
    
    override func layoutSubviews() {
        setupLayout()
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    /// 设置数据
    var model: HomeModel! {
        didSet {
            self.titleLabel.text = model.title
            self.subTitleLabel.text = model.sub_title
            self.coverImageView.nice_setImage(imageURL: URL(string: model.cover_image))
            self.detailLabel.text = model.digest
            self.praiseLabel.text = "\(model.info.up!)"
            self.authorNameLabel.text = model.author_username
        }
    }
    
    
    //MARK: --------------------------- Getter and Setter --------------------------
    
    /// 标题
    fileprivate lazy var titleLabel: UILabel = {
        var titleLabel = UILabel()
        titleLabel.textColor = UIColor.black
        titleLabel.font = UIConstant.FONT_18
        titleLabel.textAlignment = .left
        return titleLabel
    }()
    
    /// 副标题
    fileprivate lazy var subTitleLabel: UILabel = {
        var subTitleLabel = UILabel()
        subTitleLabel.textColor = .darkGray
        subTitleLabel.textAlignment = .left
        subTitleLabel.font = UIConstant.FONT_14
        return subTitleLabel
    }()
    
    /// 图片
    lazy var coverImageView: UIImageView = {
        var coverImageView = UIImageView(image: UIImage(named: "home_logo_pressed"))
        coverImageView.contentMode = .redraw
        coverImageView.image = UIImage(named: "1")
        return coverImageView
    }()
    
    /// 详情
    fileprivate lazy var detailLabel: UILabel = {
        
        var detailLabel = UILabel()
        detailLabel.textColor = .darkGray
        detailLabel.font = UIConstant.FONT_14
        detailLabel.numberOfLines = 0
        detailLabel.textAlignment = .left
        return detailLabel
    }()
    
    /// 点赞数背景色
    fileprivate lazy var praiseCoverView: UIView = {
        var praiseCoverView = UIView()
        praiseCoverView.backgroundColor = UIColor.lightGray
        praiseCoverView.alpha = 0.5
        praiseCoverView.layer.cornerRadius = 10
       
        return praiseCoverView
    }()
    
    /// 点赞数图片
    fileprivate lazy var praiseImageView: UIImageView = {
        var praiseImageView = UIImageView(image: UIImage(named: "icon_flower_home_like"))
        return praiseImageView
    }()
    
    /// 点赞数
    fileprivate lazy var praiseLabel: UILabel = {
        var praiseLabel = UILabel()
        praiseLabel.textColor = UIColor.white
        praiseLabel.textAlignment = .center
        praiseLabel.font = UIConstant.FONT_12
        return praiseLabel
    }()
    
    /// 作者名字
    fileprivate lazy var authorNameLabel: UILabel = {
        var authorNameLabel = UILabel()
        authorNameLabel.textColor = UIColor.black
        authorNameLabel.font = UIConstant.FONT_14
        authorNameLabel.textAlignment = .right
        return authorNameLabel
    }()
}


extension HomeCenterItemCell {
    fileprivate func setupLayout() {
        // 标题
        titleLabel.snp.makeConstraints { (make) in
            make.left.top.equalTo(self).offset(UIConstant.MARGIN_15)
            make.right.equalTo(self).inset(UIConstant.MARGIN_15)
            make.height.equalTo(20)
        }
        
        // 附表图
        subTitleLabel.snp.makeConstraints { (make) in
            make.left.right.equalTo(titleLabel)
            make.height.equalTo(titleLabel)
            make.top.equalTo(titleLabel.snp.bottom).offset(UIConstant.MARGIN_5)
        }
        
        // 图片
        coverImageView.snp.makeConstraints { (make) in
            make.left.right.equalTo(self)
            make.top.equalTo(subTitleLabel.snp.bottom).offset(30)
            make.height.equalTo(180)
        }
        
        detailLabel.snp.makeConstraints { (make) in
            make.left.right.equalTo(titleLabel)
            make.top.equalTo(coverImageView.snp.bottom).offset(UIConstant.MARGIN_15)
        
        }
        
        praiseCoverView.snp.makeConstraints { (make) in
            make.width.equalTo(60)
            make.height.equalTo(20)
            make.right.equalTo(titleLabel)
            make.top.equalTo(subTitleLabel.snp.bottom).offset(40)
        }
        
        praiseImageView.snp.makeConstraints { (make) in
            make.left.equalTo(praiseCoverView).offset(UIConstant.MARGIN_10)
            make.width.height.equalTo(15)
            make.top.equalTo(praiseCoverView).offset(2)
        }
        
        praiseLabel.snp.makeConstraints { (make) in
            make.left.equalTo(praiseImageView.snp.right)
            make.width.equalTo(27)
            make.height.equalTo(praiseCoverView)
            make.top.equalTo(praiseCoverView)
        }
        
        authorNameLabel.snp.makeConstraints { (make) in
            make.left.equalTo(detailLabel)
            make.right.equalTo(detailLabel)
            make.bottom.equalTo(self).inset(UIConstant.MARGIN_20)
            make.height.equalTo(20)
        }
    }
}

