//
//  MenuTableViewCell.swift
//  beautifulApp-Swift3
//
//  Created by 梁亦明 on 2016/12/2.
//  Copyright © 2016年 xiaoming.com. All rights reserved.
//

import Foundation

class MenuTableViewCell: UITableViewCell, Reusable {
    override init(style: UITableViewCellStyle, reuseIdentifier: String?) {
        super.init(style: style, reuseIdentifier: reuseIdentifier)
        
        self.backgroundColor = UIColor.clear
        
        // 添加控件
        self.contentView.addSubview(iconView)
        self.contentView.addSubview(titleLabel)
        self.contentView.addSubview(dotView)
        // 添加约束
        iconView.snp.makeConstraints { [unowned self](make) in
            make.size.equalTo(CGSize(width: 30, height: 30))
            make.centerY.equalTo(self.contentView.snp.centerY)
            make.left.equalTo(self.contentView).offset(30)
        }
        
        titleLabel.snp.makeConstraints { [unowned self](make) in
            make.left.equalTo(self.iconView.snp.right).offset(15)
            make.top.bottom.right.equalTo(self.contentView)
        }
        
        dotView.snp.makeConstraints { (make) in
            make.left.equalTo(self.contentView).offset(15)
            make.centerY.equalTo(self.contentView.snp.centerY)
            make.size.equalTo(CGSize(width: 5, height: 5))
        }
        
    }
    
    /// 给外部传递模型进来， 然后设置数据
    var model: MenuTabModel! {
        didSet {
            self.iconView.image = model.image
            self.titleLabel.text = model.title
        }
    }
    
    class func cell(withTableView tableView: UITableView) -> MenuTableViewCell {
        var cell = tableView.dequeueReusableCell() as MenuTableViewCell?
        if cell == nil {
            cell = MenuTableViewCell(style: .default, reuseIdentifier: self.reuseIdentifier)
            cell?.selectionStyle = .none
        }
        return cell!
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    //MARK: --------------------------- Getter and Setter --------------------------
    /// 图标
    fileprivate lazy var iconView: UIImageView = {
        var iconView = UIImageView()
        iconView.contentMode = .scaleAspectFit
        return iconView
    }()
    
    /// 标题
    fileprivate lazy var titleLabel: UILabel = {
        var titleLabel = UILabel()
        titleLabel.font = UIConstant.FONT_16
        titleLabel.textColor = UIColor.white
        return titleLabel
    }()
    
    /// 小圆点
    lazy var dotView: UIImageView = {
        var dotImageView = UIImageView(image: UIImage(named: "sidebar_dot"))
        dotImageView.frame = CGRect(x: 15, y: 145, width: 5, height: 5)
        dotImageView.isHidden = true
        return dotImageView
    }()
}
