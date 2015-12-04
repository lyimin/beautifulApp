//
//  XMFindAppDetailCommentCell.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/12/3.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMFindAppDetailCommentCell: UIView {
    var commentModel : XMFindAppCommentModel! {
        willSet {
            self.commentModel = newValue
        }
        
        didSet {
            self.setData()
        }
    }
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        
        // 头像
        userImgView.frame = CGRectMake(UI_MARGIN_10, 0, 30, 30)
        self.addSubview(userImgView)
        // 名字
        userNameLabel.frame = CGRectMake(CGRectGetMaxX(userImgView.frame) + UI_MARGIN_10, 0, 150, 15)
        self.addSubview(userNameLabel)
        // 详情
        userDetailLabel.frame = CGRectMake(userNameLabel.x, CGRectGetMaxY(userNameLabel.frame), 120, 15)
        self.addSubview(userDetailLabel)
        // 时间
        timeLabel.frame = CGRectMake(SCREEN_WIDTH-120-UI_MARGIN_10, 0, 120, 15)
        self.addSubview(timeLabel)
        // 评论背景
        commentBg.frame = CGRectMake(UI_MARGIN_10, CGRectGetMaxY(userImgView.frame)+UI_MARGIN_5, SCREEN_WIDTH-2*UI_MARGIN_10, 20)
        self.addSubview(commentBg)
        // 评论
        commentLabel.frame = CGRectMake(UI_MARGIN_10, 15, commentBg.width-2*UI_MARGIN_10, 20)
        commentBg.addSubview(commentLabel)

    }

    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    private func setData() {
        // 1.设置头像
        self.userImgView.xm_setBlurImageWithURL(NSURL(string: commentModel.author_avatar_url!), placeholderImage: UIImage(named: "detail_portrait_default"))
        // 2.设置名字
        self.userNameLabel.text = commentModel.author_name!
        // 3.设置详情
        self.userDetailLabel.text = commentModel.author_career!
        // 4.时间
        self.timeLabel.text = commentModel.updated_at!
        // 5.评论内容
        let attributStr : NSMutableAttributedString = NSMutableAttributedString(string: commentModel.content!)
        attributStr.setAttributes([NSFontAttributeName : UI_FONT_12], range: NSMakeRange(0, commentModel.content!.length))
        attributStr.yy_color = UIColor.darkGrayColor()
        let style = NSMutableParagraphStyle()
        style.lineSpacing = 5.0
        attributStr.addAttribute(NSParagraphStyleAttributeName, value: style, range: NSMakeRange(0, commentModel.content!.length))
        let textLayout = YYTextLayout (containerSize: CGSize(width: commentBg.width-2*UI_MARGIN_10, height: CGFloat.max), text: attributStr)
        commentLabel.size = textLayout.textBoundingSize
        commentLabel.textLayout = textLayout
        // 设置frame
        self.commentBg.height = CGRectGetMaxY(commentLabel.frame)+UI_MARGIN_10
        self.height = CGRectGetMaxY(commentBg.frame)+UI_MARGIN_10
    }
    
    // 头像
    private lazy var userImgView : UIImageView = {
        let userImgView : UIImageView = UIImageView()
        userImgView.layer.cornerRadius = 15
        userImgView.layer.borderColor = UIColor.lightGrayColor().CGColor
        userImgView.layer.borderWidth = 1
        userImgView.layer.masksToBounds = true
        return userImgView
    }()
    
    // 名字
    private lazy var userNameLabel : UILabel = {
        let userNameLabel : UILabel = UILabel()
        userNameLabel.font = UI_FONT_12
        userNameLabel.textColor = UIColor.blackColor()
        return userNameLabel
    }()
    
    // 详情
    private lazy var userDetailLabel : UILabel = {
        let userDetailLabel : UILabel = UILabel()
        userDetailLabel.font = UI_FONT_10
        userDetailLabel.textColor = UIColor.lightGrayColor()
        return userDetailLabel
    }()
    
    // 时间
    private lazy var timeLabel : UILabel = {
        let timeLabel : UILabel = UILabel()
        timeLabel.textColor = UIColor.lightGrayColor()
        timeLabel.font = UI_FONT_10
        timeLabel.textAlignment = NSTextAlignment.Right
        return timeLabel
    }()
    
    // 评论背景
    private lazy var commentBg : UIImageView = {
        var commentBg : UIImageView = UIImageView()
        let bgImg : UIImage = UIImage(named: "detail_comment_bg")!
        let stretchWidth = bgImg.size.width*0.8
        let stretchHeight = bgImg.size.height*0.4
        commentBg.image = bgImg.resizableImageWithCapInsets(UIEdgeInsets(top: stretchHeight, left: stretchWidth, bottom: stretchHeight, right: bgImg.size.width*0.1), resizingMode: UIImageResizingMode.Stretch)
        return commentBg
    }()

    // 评论了内容
    private lazy var commentLabel : YYLabel = {
        var commentLabel : YYLabel = YYLabel()
        commentLabel.font = UI_FONT_10
        commentLabel.textColor = UIColor.darkGrayColor()
        commentLabel.numberOfLines = 0
        return commentLabel
    }()
}
