//
//  XMFindAppCell.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/24.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMFindAppCell: UITableViewCell {
    // 用户头像
    @IBOutlet weak var headerIconView: XMImageView!
    // 用户名
    @IBOutlet weak var userNameLabel: UILabel!
    // 用户详情
    @IBOutlet weak var userDetailLabel: UILabel!
    // 中间图片
    @IBOutlet weak var CenterImgView: XMImageView!
    // app图标
    @IBOutlet weak var appIconView: XMImageView!
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
    
    var model : XMFindAppModel? {
        willSet {
            self.model = newValue
        }
        
        didSet {
            if model != nil {
                self.headerIconView.xm_setBlurImageWithURL(NSURL(string: model!.author_avatar_url!), placeholderImage: UIImage(named: "detail_portrait_default"))
                self.userNameLabel.text = model!.author_name
                self.userDetailLabel.text = model!.author_career
                self.CenterImgView.xm_setBlurImageWithURL(NSURL(string: model!.cover_image!), placeholderImage: UIImage(named: "home_logo_pressed"))
                self.appIconView.xm_setBlurImageWithURL(NSURL(string: model!.icon_image!), placeholderImage: UIImage(named: "ic_launcher"))
                self.appNameLabel.text = model!.title!
                self.appDetailLabel.text = model!.appDescription!
                self.lookCountLabel.text = model!.show_times
                self.loveCountLabel.text = model!.author_flowers
                self.commentCountLabel.text = model!.comment_times
            }
        }
    }
    
    class func cellWithTableView(tableView : UITableView) -> XMFindAppCell {
        var cell : XMFindAppCell? = tableView.dequeueReusableCellWithIdentifier(tableviewID) as? XMFindAppCell
        if cell == nil {
            cell = NSBundle.mainBundle().loadNibNamed("XMFindAppCell", owner: nil, options: nil).first as? XMFindAppCell
        }
        cell!.selectionStyle = UITableViewCellSelectionStyle.None
        return cell!
    }

    override func awakeFromNib() {
        super.awakeFromNib()

    }
    private static var tableviewID : String = "XMFindAppCellID"
}
