//
//  HomeDetailCenterView.swift
//  beautifulApp-Swift3
//
//  Created by 梁亦明 on 2016/12/5.
//  Copyright © 2016年 xiaoming.com. All rights reserved.
//

import Foundation
import UIKit

protocol HomeDetailCenterViewDelegate  {
    func backBtnDidClick()
    func shareBtnDidClick()
    
}

class HomeDetailCenterView: UIScrollView {
    
    //MARK: --------------------------- Life Cycle --------------------------
    override init(frame: CGRect) {
        super.init(frame: frame)
        // 添加centerView
        centerView.frame = self.bounds;
        self.addSubview(centerView)
        // 顶部图片
        headerImgView.frame = CGRect(x: 0, y: 0, width: UIConstant.SCREEN_WIDTH, height: 170);
        self.centerView.addSubview(headerImgView)
        // appIcon
        
        appIconView.frame = CGRect(x: UIConstant.MARGIN_20, y: headerImgView.frame.maxY + UIConstant.MARGIN_20, width: 50, height: 50)
        self.centerView.addSubview(appIconView)
        // app大标题
        let appTitleLabelX = appIconView.frame.maxX+UIConstant.MARGIN_20;
        let appTitleLabelW = UIConstant.SCREEN_WIDTH-UIConstant.MARGIN_20-appTitleLabelX;
        appTitleLabel.frame = CGRect(x: appTitleLabelX, y: headerImgView.frame.maxY+25, width: appTitleLabelW, height: 20)
        self.centerView.addSubview(appTitleLabel)
        // app详情
        appDetailLabel.frame = CGRect(x: appTitleLabelX, y: appTitleLabel.frame.maxY, width: appTitleLabelW, height: 20)
        self.centerView.addSubview(appDetailLabel)
        // appicon + toolbar高度
        contentY = headerImgView.height+UIConstant.MARGIN_20+100
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    //MARK : -DataSource
    /**
     *  设置评论数据
     */
    func setCommentData(comments: Array<CommentModel>) {
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
    
    //MARK:- private Methods
    private func setupOtherData() {
        // 计算文字高度，添加app描述文段
        let describeLabel = self.createPTitleLabel()
        self.centerView.addSubview(describeLabel)
        let descriSize = self.calculateTextHeight(text: model.digest!, label: describeLabel)
        describeLabel.frame = CGRect(x: UIConstant.MARGIN_10, y: contentY + UIConstant.MARGIN_10, width: UIConstant.SCREEN_WIDTH-2*UIConstant.MARGIN_10, height: descriSize.height)
        contentY = describeLabel.frame.maxY + UIConstant.MARGIN_20
        // 添加http文段
        let _ = XMLParserUtil(content: model.content!) { [unowned self](array) -> Void in
            // 拿到解析完的数组后添加控件
            for contentModel in array {
                
                if contentModel.contentType == XMLContentType.XMLContentTypeH2 {
                    // 标题
                    self.contentY += UIConstant.MARGIN_10
                    let h2TitlLabel = self.createH2TitleLabel()
                    h2TitlLabel.text = contentModel.content
                    h2TitlLabel.frame = CGRect(x: UIConstant.MARGIN_10, y: self.contentY, width: UIConstant.SCREEN_WIDTH-2*UIConstant.MARGIN_10, height: 20)
                    self.centerView.addSubview(h2TitlLabel)
                    self.contentY += h2TitlLabel.height + UIConstant.MARGIN_10
                } else if contentModel.contentType == XMLContentType.XMLContentTypeP {
                    // 描述
                    let pTitleLabel = self.createPTitleLabel()
                    pTitleLabel.frame = CGRect(x: UIConstant.MARGIN_10, y: self.contentY, width: UIConstant.SCREEN_WIDTH-2*UIConstant.MARGIN_10, height: 20)
                    let pTitleSize = self.calculateTextHeight(text: contentModel.content, label: pTitleLabel)
                    self.centerView.addSubview(pTitleLabel)
                    self.contentY += pTitleSize.height + UIConstant.MARGIN_10
                } else if contentModel.contentType == XMLContentType.XMLContentTypeA {
                    // 点击下载
                    let aTitleBtn = self.createATitleButton()
                    aTitleBtn.frame = CGRect(x: UIConstant.MARGIN_10, y: self.contentY, width: 60, height: 20)
                    self.centerView.addSubview(aTitleBtn)
                    self.contentY += aTitleBtn.height + UIConstant.MARGIN_10
                } else if contentModel.contentType == XMLContentType.XMLContentTypeImg {
                    
                    // 根据url 获取图片高度
                    let size : CGSize = contentModel.content.getImageSizeWithURL()
                    // 获取 _ 的位置
                    let imgView : UIImageView = self.createImgView()
                    imgView.frame = CGRect(x: UIConstant.MARGIN_10, y: self.contentY, width: size.width, height: size.height)
                    imgView.center.x = UIConstant.SCREEN_WIDTH*0.5
                    imgView.nice_setImage(imageURL: URL(string: contentModel.content))
                    self.centerView.addSubview(imgView)
                    self.contentY += size.height + UIConstant.MARGIN_10
                }
            }
        }
        
        
        // 分享view
        let shareView : XMHomeDetailShareView = XMHomeDetailShareView.shareView()
        shareView.frame = CGRect(x: UIConstant.MARGIN_10, y: contentY, width: UIConstant.SCREEN_WIDTH-2*UIConstant.MARGIN_10, height: shareView.height)
        shareView.centerViewDidClickWithBlock { [unowned self]() -> Void in
            self.centerDelegate?.shareBtnDidClick()
        }
        self.centerView.addSubview(shareView)
        contentY += shareView.height
        
        // 评论view
        if model.comments.count != 0 {
            let commentLabel = self.createTitleViwe(title: "评论")
            commentLabel.frame = CGRect(x: UIConstant.MARGIN_10, y: contentY+2*UIConstant.MARGIN_10, width: 35, height: 20)
            contentY = commentLabel.frame.maxY+UIConstant.MARGIN_10;
            // 分割线
            let sepLine = self.createTitleSeparatLine()
            sepLine.frame = CGRect(x: commentLabel.frame.maxX, y: commentLabel.center.y, width:80, height: 0.5)

            // 添加评论
            for i in 0..<model.comments.count {
                let commentView = CommentCell(frame: CGRect(x: 0, y: contentY, width: UIConstant.SCREEN_WIDTH, height: 50))
                commentView.setData(model: self.model.comments[i])
                self.centerView.addSubview(commentView)
                contentY += commentView.height
            }
        }
        
        // 设置contentsize
        self.centerView.height = contentY
        self.contentSize = CGSize(width: 0, height: contentY)
    }
    // 根据文字计算高度
    private func calculateTextHeight (text: String, label: UILabel) -> CGSize {
        // 设置文字样式
        let attributString : NSMutableAttributedString = NSMutableAttributedString(string: text)
        let paragraphStyle = NSMutableParagraphStyle()
        paragraphStyle.lineSpacing = 5.0
        attributString.addAttribute(NSAttributedStringKey.paragraphStyle , value: paragraphStyle, range: NSMakeRange(0, text.length))
        
        let size = (text as NSString).boundingRect(with: CGSize(width: UIConstant.SCREEN_WIDTH-2*UIConstant.MARGIN_10, height: CGFloat.greatestFiniteMagnitude), options: .usesLineFragmentOrigin, attributes: [NSAttributedStringKey.font: UIConstant.FONT_16], context: nil).size
        label.attributedText = attributString
        return size
    }
    
    //MARK: - Public Method
    func updateHeaderView() {
        let HeaderHeight : CGFloat = headerImgView.height
        let HeaderCutAway: CGFloat = 170
        
        var headerRect = CGRect(x: 0, y: 0, width: UIConstant.SCREEN_WIDTH, height: HeaderHeight)
        if self.contentOffset.y < 0 {
            headerRect.origin.y = self.contentOffset.y
            headerRect.size.height = -self.contentOffset.y + HeaderCutAway
            headerImgView.frame = headerRect
        }
    }
    
    //MARK: - Action Event
    
    //MARK: - getter or setter
    // 记录当前高度
    private var contentY: CGFloat = 0
    // MARK:-DATA
    // 代理
    var centerDelegate: HomeDetailCenterViewDelegate?
    var model: HomeModel! {
        didSet {
            self.headerImgView.nice_setImage(imageURL: URL(string: model.cover_image!))
            // 图标
            self.appIconView.nice_setImage(imageURL: URL(string: model.icon_image!), placeholderImage: UIImage(named: "ic_launcher")!)
            self.appTitleLabel.text = model.title!
            self.appDetailLabel.text = model.sub_title!
            // 添加其他控件
            
            self.setupOtherData()
        }
    }
    // 内容
    private lazy var centerView : UIView = {
        let centerView : UIView = UIView()
        return centerView
    }()
    
    // 顶部图片
    lazy var headerImgView : UIImageView = {
        let headerImgView : UIImageView = UIImageView(image: UIImage(named: "home_logo_pressed"))
        headerImgView.contentMode = .scaleAspectFill
        return headerImgView
    }()
    
    // appIcon
    private lazy var appIconView : UIImageView = {
        let appIconView : UIImageView = UIImageView(image: UIImage(named: "ic_launcher"))
        //        appIconView.contentMode = .ScaleAspectFit
        appIconView.layer.cornerRadius = UIConstant.MARGIN_10
        appIconView.layer.masksToBounds = true
        return appIconView
    }()
    
    // app大标题
    private lazy var appTitleLabel : UILabel = {
        let appTitleLabel : UILabel = UILabel()
        appTitleLabel.font = UIConstant.FONT_20
        appTitleLabel.textColor = UIColor.black
        return appTitleLabel
    }()
    
    // app 详情
    private lazy var appDetailLabel : UILabel = {
        let appDetailLabel : UILabel = UILabel()
        appDetailLabel.font = UIConstant.FONT_14
        appDetailLabel.textColor = UIColor.darkGray
        return appDetailLabel
    }()
    
    private func createTitleViwe(title : String) -> UILabel {
        let label : UILabel = UILabel()
        label.font = UIFont.systemFont(ofSize: 15)
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
    // 标题(h2)
    private func createH2TitleLabel() -> UILabel {
        let h2TitleLabel = UILabel()
        h2TitleLabel.textColor = UIColor.black
        h2TitleLabel.font = UIConstant.FONT_16
        return h2TitleLabel
    }
    
    // 描述(p)
    private func createPTitleLabel() -> UILabel {
        let contentLabel = UILabel()
        contentLabel.font = UIConstant.FONT_16
        contentLabel.textColor = UIColor.darkGray
        contentLabel.numberOfLines = 0
        return contentLabel
    }
    
    // 图片(Img)
    private func createImgView() -> UIImageView {
        let imgView : UIImageView = UIImageView()
        imgView.layer.cornerRadius = 3
        imgView.layer.borderColor = UIColor.lightGray.cgColor
        imgView.layer.borderWidth = 0.5
        imgView.contentMode = .scaleAspectFit
        return imgView
    }
    
    // 下载(a)
    private func createATitleButton() -> UIButton {
        let btn : UIButton = UIButton()
        btn.titleLabel?.textAlignment = NSTextAlignment.left
        btn.titleLabel?.font = UIConstant.FONT_14
        btn.setTitle("点击下载", for: .normal)
        btn.setTitleColor(UIConstant.COLOR_APPNORMAL, for: .normal)
        return btn
    }
    
    
}
//MARK: ---------------------------HomeDetailShareView 分享view --------------------------
//class HomeDetailShareView: UIView {
//    override init(frame: CGRect) {
//        super.init(frame: frame)
//    }
//    
//    required init?(coder aDecoder: NSCoder) {
//        fatalError("init(coder:) has not been implemented")
//    }
//    
//    fileprivate lazy var lineView: UIView = {
//        var lineView = UIView()
//        lineView.backgroundColor = UIColor(red: 240/255.0, green: 240/255.0, blue: 240/255.0, alpha: 1)
//        lineView.frame = CGRect(x: 8, y: 0, width: self.width-16, height: 1)
//        return lineView
//    }()
//    
//    fileprivate lazy var iconView: UIImageView = {
//        var iconView = UIImageView(image: UIImage(named: "ic_launcher"))
//        iconView.frame = CGRect(x: 0, y: 0, width: 50, height: 50)
//        iconView.center = CGPoint(x: self.center.x, y: 8+25)
//        return iconView
//    }()
//    
//    fileprivate lazy var centerView: UIView = {
//        var centerView = UIView()
//        centerView.backgroundColor = UIColor(red: 54/255.0, green: 152/255.0, blue: 250/255.0, alpha: 1)
//        centerView.layer.cornerRadius = 5
//        centerView.frame = CGRect(x: 8, y: self.iconView.frame.maxY+UIConstant.MARGIN_10, width: self.width-16, height: 100)
//        return centerView
//    }()
//    
//    fileprivate lazy var tipLabel: UILabel = {
//        var tipLabel = UILabel()
//        tipLabel.text = "喜欢就分享给朋友吧"
//        tipLabel.textColor = UIColor.white
//        tipLabel.font = UIConstant.FONT_12
//        tipLabel.textAlignment = .center
//        tipLabel.frame = CGRect(x: 0, y: 0, width: s)
//        return tipLabel
//    }()
//}
