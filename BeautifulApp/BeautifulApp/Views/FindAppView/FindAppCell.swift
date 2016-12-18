//
//  FindAppCell.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/24.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class FindAppCell: UITableViewCell, Reusable {
    // 用户头像
    @IBOutlet weak var headerIconView: UIImageView!
    // 用户名
    @IBOutlet weak var userNameLabel: UILabel!
    // 用户详情
    @IBOutlet weak var userDetailLabel: UILabel!
    // 中间图片
    @IBOutlet weak var CenterImgView: UIImageView!
    // app图标
    @IBOutlet weak var appIconView: UIImageView!
    // app名
    @IBOutlet weak var appNameLabel: UILabel!
    // app详情
    @IBOutlet weak var appDetailLabel: UILabel!
    // 观察数
    @IBOutlet weak var lookCountLabel: UILabel!
    // 喜欢数
    @IBOutlet weak var loveCountLabel: UILabel!
    // 评论数
    @IBOutlet weak var commentCountLabel: UILabel!
    
    var model: FindAppModel! {
        didSet {
            
            self.headerIconView.nice_setImage(imageURL: URL(string: model.author_avatar_url), placeholderImage: UIImage(named: "detail_portrait_default")!, imageCornerRadius: 15)
            self.userNameLabel.text = model.author_name
            self.userDetailLabel.text = model.author_career
            self.CenterImgView.nice_setImage(imageURL: URL(string: model.cover_image))
            self.appIconView.nice_setImage(imageURL: URL(string: model.icon_image), imageCornerRadius: 5)
            self.appNameLabel.text = model.title
            self.appDetailLabel.text = model.appDescription
            self.lookCountLabel.text = "\(model.show_times!)"
            self.loveCountLabel.text = "\(model.author_flowers!)"
            self.commentCountLabel.text = "\(model.comment_times!)"
        
        }
    }
    
    class func cellWithTableView(tableView : UITableView) -> FindAppCell {
        var cell: FindAppCell? = tableView.dequeueReusableCell()
        if cell == nil {
            cell = Bundle.main.loadNibNamed("FindAppCell", owner: nil, options: nil)?.first as? FindAppCell
        }
        cell!.selectionStyle = UITableViewCellSelectionStyle.none
        return cell!
    }
}
