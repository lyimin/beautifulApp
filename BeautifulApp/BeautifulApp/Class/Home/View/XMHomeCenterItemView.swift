//
//  XMHomeCenterView.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/8.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMHomeCenterItemView: UICollectionViewCell {
    // 大标题
    @IBOutlet weak var titleLabel: UILabel!
    // 子标题
    @IBOutlet weak var subTitleLabel: UILabel!
    // 图片
    @IBOutlet weak var centerImgView: UIImageView!
    // 详情
    @IBOutlet weak var detailLabel: UILabel!
    // 喜欢数
    @IBOutlet weak var fovView: XMView!
    @IBOutlet weak var fovCountLabel: UILabel!
    // 作者
    @IBOutlet weak var authorLabel: UILabel!

    var homeModel : XMHomeDataModel! {
        willSet {
            self.homeModel = newValue
        }
        
        didSet {
            self.titleLabel.text = homeModel.title
            self.subTitleLabel.text = homeModel.sub_title
            self.centerImgView.xm_setBlurImageWithURL(NSURL(string: homeModel.cover_image!), placeholderImage: UIImage(named: "home_logo_pressed"))
            self.detailLabel.text = homeModel.digest
//            self.detailLabel.sizeToFit()
            
            
            if  homeModel.info?.fav == nil {
                self.fovCountLabel.text = "0"
            } else {
                self.fovCountLabel.text = homeModel.info?.fav
            }
            self.authorLabel.text = homeModel.author_username
        }
    }
    
    override func awakeFromNib() {
        super.awakeFromNib()
        
        self.backgroundColor = UIColor.whiteColor()
        self.layer.cornerRadius = 5
    }
    
    override func layoutSubviews() {
        super.layoutSubviews()
//        self.detailLabel.sizeToFit()
    }
    
    class func itemView () -> XMHomeCenterItemView {
        let centerView : XMHomeCenterItemView = NSBundle.mainBundle().loadNibNamed("XMHomeCenterItemView", owner: nil, options: nil)[0] as! XMHomeCenterItemView
        return centerView
    }

    class func itemWithCollectionView(collection : UICollectionView, indexPath : NSIndexPath) -> XMHomeCenterItemView {
        var cell : XMHomeCenterItemView? = collection.dequeueReusableCellWithReuseIdentifier("XMHomeCenterItemViewID", forIndexPath: indexPath) as? XMHomeCenterItemView
        
        if cell == nil {
            cell = NSBundle.mainBundle().loadNibNamed("XMHomeCenterItemView", owner: nil, options: nil)[0] as? XMHomeCenterItemView
        }
        return cell!
    }
}
