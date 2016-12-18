//
//  XMFindAppDetailCenterView.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/12/1.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class FindAppDetailCenterView: UIScrollView, UIScrollViewDelegate {
    
    var dataModel: FindAppModel! {
        didSet {
            setData()
        }
    }
//MARK: -life cycle
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        // 添加内容
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
        userIconView.frame = CGRect(x:UIConstant.SCREEN_WIDTH-userIconSize-UIConstant.MARGIN_20 , y: 40, width: userIconSize, height: userIconSize)
        userIconView.nice_setImage(imageURL: URL(string: dataModel.author_avatar_url), placeholderImage: UIImage(named: "detail_portrait_default")!)
        
        // 2.用户名
        let userNameLabel = self.createTitleView(title: dataModel.author_name)
        userNameLabel.textAlignment = NSTextAlignment.right
        let userNameLabelWidth : CGFloat = 150
        userNameLabel.frame = CGRect(x: userIconView.x-UIConstant.MARGIN_5-userNameLabelWidth, y: userIconView.y, width: userNameLabelWidth, height: 20)
        // 3.详情
        let userDetailLabel = self.createUserSubTitleLabel()
        userDetailLabel.text = dataModel.author_career!
        userDetailLabel.frame = CGRect(x: userNameLabel.x, y: userNameLabel.frame.maxY, width: userNameLabelWidth, height: 15)
        // 4.分割线
        let topLine = self.createTitleSeparatLine()
        topLine.frame = CGRect(x: 0, y: userDetailLabel.frame.maxY+UIConstant.MARGIN_10, width: UIConstant.SCREEN_WIDTH-UIConstant.MARGIN_20, height: 1)
        // 5.appIcon
        appIconView.frame = CGRect(x: UIConstant.MARGIN_20, y: topLine.frame.maxY+UIConstant.MARGIN_15, width: 50, height: 50)
        self.centerView.addSubview(appIconView)
        appIconView.nice_setImage(imageURL: URL(string: dataModel.icon_image), imageCornerRadius: 5)

        // 6.appName
        let appNameLabelX = appIconView.frame.maxX + UIConstant.MARGIN_10;
        appNameLabel.frame = CGRect(x: appNameLabelX, y: appIconView.center.y-UIConstant.MARGIN_10, width: UIConstant.SCREEN_WIDTH-appNameLabelX-UIConstant.MARGIN_10, height: 20)
        self.centerView.addSubview(appNameLabel)
        self.appNameLabel.text = dataModel.title!
        
        // 计算当前高度+toolbar高度
        contentY = appIconView.frame.maxY + UIConstant.MARGIN_5 + 30
// MARK : 设置动态的view ------------ 很多view需要手动创建
        let margin : CGFloat = 10
        self.contentLabel.frame = CGRect(x: margin, y: contentY + UIConstant.MARGIN_10, width: UIConstant.SCREEN_WIDTH-2*margin, height: 20)
    // 详情文字
        // 计算高度
        let contentText = (dataModel.appDescription! as NSString).replacingOccurrences(of: "<br/>", with: "\n")
        // 设置样式
        let attributString : NSMutableAttributedString = NSMutableAttributedString(string: contentText)
        attributString.setAttributes([NSFontAttributeName: UIConstant.FONT_16], range: NSMakeRange(0, contentText.length))
        let paragraphStyle = NSMutableParagraphStyle()
        paragraphStyle.lineSpacing = 5.0
        attributString.addAttribute(NSParagraphStyleAttributeName , value: paragraphStyle, range: NSMakeRange(0, contentText.length))
        let size = (contentText as NSString).boundingRect(with: CGSize(width: UIConstant.SCREEN_WIDTH-2*UIConstant.MARGIN_10, height: CGFloat.greatestFiniteMagnitude), options: .usesLineFragmentOrigin, attributes: [NSFontAttributeName: UIConstant.FONT_16], context: nil).size
        // 设置frame

        self.contentLabel.attributedText = attributString
        self.centerView.addSubview(self.contentLabel)
    
        contentY += size.height + UIConstant.MARGIN_10
    // 添加图片
        contentY = contentLabel.frame.maxY + margin
        for i in 0..<dataModel.all_images.count {
            let url: String = self.dataModel.all_images[i]
            // 根据url 获取图片高度
            let size: CGSize = url.getImageSizeWithURL()
            // 获取 _ 的位置
            let imgView: UIImageView = self.createImgView()
            imgView.frame = CGRect(x: UIConstant.MARGIN_10, y: contentY, width: size.width, height: size.height)
            imgView.center.x = UIConstant.SCREEN_WIDTH*0.5
            imgView.nice_setImage(imageURL: URL(string: url))
            self.centerView.addSubview(imgView)
            contentY += size.height + margin
        }
        
    // 美过的美友
        if dataModel.up_users.count != 0 {
            let loveUserLabel = self.createTitleView(title: "美过的美友")
            loveUserLabel.frame = CGRect(x: margin, y: contentY + margin*2, width: 80, height: 20)
            
            // 分割线
            let sepLine = self.createTitleSeparatLine()
            sepLine.frame = CGRect(x: loveUserLabel.frame.maxX, y: loveUserLabel.center.y, width: 220, height: 0.5)
            contentY = loveUserLabel.frame.maxY+margin;
            // 添加点赞的头像
            // 头像大小
            let imgMargin : CGFloat = (UIConstant.SCREEN_WIDTH-2*margin-8*userIconSize)/7
            for i in 0..<dataModel.up_users.count {
                let userImg : UIImageView = self.createUserImgView()
                // 获取模型
                let upUserDate: UpUserDataModel = dataModel.up_users[i]
                userImg.nice_setImage(imageURL: URL(string: upUserDate.avatar_url), placeholderImage: UIImage(named: "detail_portrait_default")!)
                userImg.frame = CGRect(x: margin+(CGFloat(i).truncatingRemainder(dividingBy: 8))*(userIconSize+imgMargin), y: contentY + (userIconSize+imgMargin) * CGFloat(i/8), width: userIconSize, height: userIconSize)
                if i == dataModel.up_users.count - 1 {
                    contentY = userImg.frame.maxY;
                }
            }
        }
        
    // 评论
        if dataModel.comments.count != 0 {
            let commentLabel = self.createTitleView(title: "评论")
            commentLabel.frame = CGRect(x: margin, y: contentY+2*margin, width: 35, height: 20)
            contentY = commentLabel.frame.maxY+margin;
            commentY = commentLabel.frame.maxY+margin
            // 分割线
            let sepLine = self.createTitleSeparatLine()
            sepLine.frame = CGRect(x: commentLabel.frame.maxX, y: commentLabel.center.y, width: 80, height: 0.5)
            
            // 添加评论
            for i in 0..<dataModel.comments.count {
                let commentView = CommentCell(frame: CGRect(x: 0, y:contentY, width: UIConstant.SCREEN_WIDTH, height: 50))
                commentView.setData(model: self.dataModel.comments[i])
                self.centerView.addSubview(commentView)
                contentY += commentView.height
            }
        } else {
            commentY = self.contentSize.height-UIConstant.MARGIN_10
        }
        
    //设置contentsize
        self.centerView.height = contentY
        self.contentSize = CGSize(width: 0, height: contentY)
    }
    
    /**
     *  设置评论数据
     */
    func setCommentData(comments : Array<CommentModel>) {
        if comments.count != 0 {
            // 添加评论
            for i in 0..<comments.count {
                let commentView = CommentCell(frame: CGRect(x: 0, y: contentY, width: UIConstant.SCREEN_WIDTH, height: 50))
                commentView.setData(model: comments[i])
                self.centerView.addSubview(commentView)
                contentY += commentView.height
            }
        }
        //设置contentsize
        self.centerView.height = contentY
        self.contentSize = CGSize(width: 0, height: contentY)
    }
    
    //MARK: - Private Methods
    // 用户名头像
    private func createUserImgView() -> UIImageView {
        let userImgView : UIImageView = UIImageView()
        userImgView.layer.cornerRadius = 18
        userImgView.layer.borderColor = UIColor.lightGray.cgColor
        userImgView.layer.borderWidth = 1
        userImgView.layer.masksToBounds = true
        self.centerView.addSubview(userImgView)
        return userImgView
    }
    
    // 用户详情
    private func createUserSubTitleLabel() -> UILabel {
        let userDetailLabel : UILabel = UILabel()
        userDetailLabel.textAlignment = .right
        userDetailLabel.font = UIConstant.FONT_10
        userDetailLabel.textColor = UIColor.lightGray
        self.centerView.addSubview(userDetailLabel)
        return userDetailLabel
    }
    private func createImgView() -> UIImageView {
        let imgView : UIImageView = UIImageView()
        imgView.layer.cornerRadius = 3
        imgView.layer.borderColor = UIColor.lightGray.cgColor
        imgView.layer.borderWidth = 0.5
        imgView.contentMode = .scaleAspectFit
        imgView.center.x = self.centerView.center.x
        return imgView
    }
    
    private func createTitleView(title : String) -> UILabel {
        let label : UILabel = UILabel()
        label.font = UIConstant.FONT_16
        label.text = title
        label.textColor = UIColor.black
        self.centerView.addSubview(label)
        return label
    }
    
    private func createTitleSeparatLine() -> UIView {
        let line : UIView = UIView()
        line.backgroundColor = UIColor.lightGray
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
        appNameLabel.font = UIConstant.FONT_18
        appNameLabel.textColor = UIColor.black
        return appNameLabel
    }()
    
    private lazy var contentLabel: UILabel = {
        var contentLabel = UILabel()
        contentLabel.font = UIConstant.FONT_16
        contentLabel.textColor = UIColor.darkGray
        contentLabel.numberOfLines = 0
        return contentLabel
    }()

}
