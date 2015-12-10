//
//  XMFindAppDetailCenterView.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/12/1.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMFindAppDetailCenterView: UIScrollView, UIScrollViewDelegate {
    
    var dataModel : XMFindAppModel! {
        willSet {
            self.dataModel = newValue
        }
        
        didSet {
            self.setData()
        }
    }
//MARK: -life cycle
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        // 添加内容
        centerView.frame = self.bounds
        self.addSubview(centerView)
    }

    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
//MARK: - dataSource
    
    /**
        设置数据
     */
    private func setData() {
        // 1.头像
        let userIconView : UIImageView = self.createUserImgView()
        let userIconSize : CGFloat = 36
        userIconView.frame = CGRect(x:SCREEN_WIDTH-userIconSize-UI_MARGIN_20 , y: 40, width: userIconSize, height: userIconSize)
        userIconView.xm_setBlurImageWithURL(NSURL(string: dataModel.author_avatar_url!)!, placeholderImage:UIImage(named: "detail_portrait_default"))
        
        // 2.用户名
        let userNameLabel = self.createTitleView(dataModel.author_name!)
        userNameLabel.textAlignment = NSTextAlignment.Right
        let userNameLabelWidth : CGFloat = 150
        userNameLabel.frame = CGRect(x: userIconView.x-UI_MARGIN_5-userNameLabelWidth, y: userIconView.y, width: userNameLabelWidth, height: 20)
        // 3.详情
        let userDetailLabel = self.createUserSubTitleLabel()
        userDetailLabel.text = dataModel.author_career!
        userDetailLabel.frame = CGRect(x: userNameLabel.x, y: CGRectGetMaxY(userNameLabel.frame), width: userNameLabelWidth, height: 15)
        // 4.分割线
        let topLine = self.createTitleSeparatLine()
        topLine.frame = CGRect(x: 0, y: CGRectGetMaxY(userDetailLabel.frame)+UI_MARGIN_10, width: SCREEN_WIDTH-UI_MARGIN_20, height: 1)
        // 5.appIcon
        appIconView.frame = CGRect(x: UI_MARGIN_20, y: CGRectGetMaxY(topLine.frame)+UI_MARGIN_15, width: 50, height: 50)
        self.centerView.addSubview(appIconView)
        appIconView.xm_setBlurImageWithURL(NSURL(string: dataModel.icon_image!)!, placeholderImage: UIImage(named: "ic_launcher"))
        // 6.appName
        let appNameLabelX = CGRectGetMaxX(appIconView.frame) + UI_MARGIN_10;
        appNameLabel.frame = CGRect(x: appNameLabelX, y: appIconView.center.y-UI_MARGIN_10, width: SCREEN_WIDTH-appNameLabelX-UI_MARGIN_10, height: 20)
        self.centerView.addSubview(appNameLabel)
        self.appNameLabel.text = dataModel.title!
        
        // 计算当前高度+toolbar高度
        contentY = CGRectGetMaxY(appIconView.frame) + UI_MARGIN_5 + 30
// MARK : 设置动态的view ------------ 很多view需要手动创建
        let margin : CGFloat = 10
        self.contentLabel.frame = CGRectMake(margin, contentY + UI_MARGIN_10, SCREEN_WIDTH-2*margin, 20)
    // 详情文字
        // 计算高度
        let contentText : String = (dataModel.appDescription! as NSString).stringByReplacingOccurrencesOfString("<br/>", withString: "\n")
        // 设置样式
        let attributString : NSMutableAttributedString = NSMutableAttributedString(string: contentText)
        attributString.setAttributes([NSFontAttributeName : UI_FONT_16], range: NSMakeRange(0, contentText.length))
        let paragraphStyle = NSMutableParagraphStyle()
        paragraphStyle.lineSpacing = 5.0
        attributString.yy_color = UIColor.darkGrayColor()
        attributString.addAttribute(NSParagraphStyleAttributeName , value: paragraphStyle, range: NSMakeRange(0, contentText.length))
        let textLayout = YYTextLayout(containerSize: CGSize(width: SCREEN_WIDTH-2*margin, height: CGFloat.max), text: attributString)
        // 设置frame
        contentLabel.size = textLayout.textBoundingSize
        contentLabel.textLayout = textLayout
        self.centerView.addSubview(self.contentLabel)
    
        contentY += textLayout.textBoundingSize.height + UI_MARGIN_10
    // 添加图片
        contentY = CGRectGetMaxY(contentLabel.frame) + margin
        for i in 0..<dataModel.all_images.count {
            let url : String = self.dataModel.all_images[i]
            // 根据url 获取图片高度
            let size : CGSize = url.getImageSizeWithURL()
            // 获取 _ 的位置
            let imgView : UIImageView = self.createImgView()
            imgView.frame = CGRectMake(10, contentY, size.width, size.height)
            imgView.center.x = SCREEN_WIDTH*0.5
            imgView.xm_setBlurImageWithURL(NSURL(string: url), placeholderImage: UIImage(named: "home_logo_pressed"))
            self.centerView.addSubview(imgView)
            contentY += size.height + margin
        }
        
    // 美过的美友
        if dataModel.up_users.count != 0 {
            let loveUserLabel = self.createTitleView("美过的美友")
            loveUserLabel.frame = CGRectMake(margin, contentY + margin*2, 80, 20)
            
            // 分割线
            let sepLine = self.createTitleSeparatLine()
            sepLine.frame = CGRectMake(CGRectGetMaxX(loveUserLabel.frame), loveUserLabel.center.y, 220, 0.5)
            contentY = CGRectGetMaxY(loveUserLabel.frame)+margin;
            // 添加点赞的头像
            // 头像大小
            let imgMargin : CGFloat = (SCREEN_WIDTH-2*margin-8*userIconSize)/7
            for i in 0..<dataModel.up_users.count {
                let userImg : UIImageView = self.createUserImgView()
                // 获取模型
                let upUserDate : XMUpUserDataModel = dataModel.up_users[i]
                userImg.xm_setBlurImageWithURL(NSURL(string: upUserDate.avatar_url!), placeholderImage: UIImage(named: "detail_portrait_default"))
                userImg.frame = CGRectMake(margin+(CGFloat(i)%8)*(userIconSize+imgMargin), contentY + (userIconSize+imgMargin) * CGFloat(i/8), userIconSize, userIconSize)
                if i == dataModel.up_users.count - 1 {
                    contentY = CGRectGetMaxY(userImg.frame);
                }
            }
        }
        
    // 评论
        if dataModel.comments.count != 0 {
            let commentLabel = self.createTitleView("评论")
            commentLabel.frame = CGRectMake(margin, contentY+2*margin, 35, 20)
            contentY = CGRectGetMaxY(commentLabel.frame)+margin;
            commentY = CGRectGetMaxY(commentLabel.frame)+margin
            // 分割线
            let sepLine = self.createTitleSeparatLine()
            sepLine.frame = CGRectMake(CGRectGetMaxX(commentLabel.frame), commentLabel.center.y, 80, 0.5)
            
            // 添加评论
            for i in 0..<dataModel.comments.count {
                let commentView : XMFindAppDetailCommentCell = XMFindAppDetailCommentCell(frame: CGRectMake(0, contentY, SCREEN_WIDTH, 50))
                commentView.setData(self.dataModel.comments[i])
                self.centerView.addSubview(commentView)
                contentY += commentView.height
            }
        } else {
            commentY = self.contentSize.height-UI_MARGIN_10
        }
        
    //设置contentsize
        self.centerView.height = contentY
        self.contentSize = CGSizeMake(0, contentY)
    }
    
    /**
     *  设置评论数据
     */
    func setCommentData(comments : Array<XMFindAppCommentModel>) {
        if comments.count != 0 {
            // 添加评论
            for i in 0..<comments.count {
                let commentView : XMFindAppDetailCommentCell = XMFindAppDetailCommentCell(frame: CGRectMake(0, contentY, SCREEN_WIDTH, 50))
                commentView.setData(comments[i])
                self.centerView.addSubview(commentView)
                contentY += commentView.height
            }
        }
        //设置contentsize
        self.centerView.height = contentY
        self.contentSize = CGSizeMake(0, contentY)
    }
    
    //MARK: - Private Methods
    // 用户名头像
    private func createUserImgView() -> UIImageView {
        let userImgView : UIImageView = UIImageView()
        userImgView.layer.cornerRadius = 18
        userImgView.layer.borderColor = UIColor.lightGrayColor().CGColor
        userImgView.layer.borderWidth = 1
        userImgView.layer.masksToBounds = true
        self.centerView.addSubview(userImgView)
        return userImgView
    }
    
    // 用户详情
    private func createUserSubTitleLabel() -> UILabel {
        let userDetailLabel : UILabel = UILabel()
        userDetailLabel.textAlignment = .Right
        userDetailLabel.font = UI_FONT_10
        userDetailLabel.textColor = UIColor.lightGrayColor()
        self.centerView.addSubview(userDetailLabel)
        return userDetailLabel
    }
    private func createImgView() -> UIImageView {
        let imgView : UIImageView = UIImageView()
        imgView.layer.cornerRadius = 3
        imgView.layer.borderColor = UIColor.lightGrayColor().CGColor
        imgView.layer.borderWidth = 0.5
        imgView.contentMode = .ScaleAspectFit
        imgView.center.x = self.centerView.center.x
        return imgView
    }
    
    private func createTitleView(title : String) -> UILabel {
        let label : UILabel = UILabel()
        label.font = UI_FONT_16
        label.text = title
        label.textColor = UIColor.blackColor()
        self.centerView.addSubview(label)
        return label
    }
    
    private func createTitleSeparatLine() -> UIView {
        let line : UIView = UIView()
        line.backgroundColor = UIColor.lightGrayColor()
        self.centerView.addSubview(line)
        return line
    }
    
    //MARK：-Getter or Setter
    private var contentY : CGFloat = 0
    private var commentY : CGFloat = 0
    // 内容
    private lazy var centerView : UIView = {
        let centerView = UIView(frame: self.bounds)
        return centerView
    }()
    // appIcon
    private lazy var appIconView : UIImageView = {
        let appIconView : UIImageView = UIImageView()
        appIconView.layer.cornerRadius = 10
        return appIconView
    }()
    // appName
    private lazy var appNameLabel : UILabel = {
        let appNameLabel : UILabel = UILabel()
        appNameLabel.font = UI_FONT_18
        appNameLabel.textColor = UIColor.blackColor()
        return appNameLabel
    }()
    
    private lazy var contentLabel : YYLabel = {
        var contentLabel : YYLabel = YYLabel()
        contentLabel.font = UI_FONT_16
        contentLabel.textColor = UIColor.darkGrayColor()
        contentLabel.numberOfLines = 0
        return contentLabel
    }()

}
