//
//  XMHomeDetailCenterView.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/19.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

protocol XMHomeDetailCenterViewDelegate  {
    func homeDetailCenterView(centerView : XMHomeDetailCenterView ,returnButtonDidClick returnButton : UIButton)
    func homeDetailCenterViewBottomShareDidClick(centerView : XMHomeDetailCenterView)
    
}

class XMHomeDetailCenterView: UIScrollView {
    // 记录当前高度
    private var contentY : CGFloat = 0
    // MARK:-DATA
    // 代理
    var centerDelegate : XMHomeDetailCenterViewDelegate?
    var model : XMHomeDataModel! {
        willSet {
            self.model = newValue
        }
        
        didSet {
            self.headerImgView.xm_setBlurImageWithURL(NSURL(string: model.cover_image!), placeholderImage: UIImage(named: "home_logo_pressed"))
            // 图标
            self.appIconView.xm_setBlurImageWithURL(NSURL(string: model.icon_image!), placeholderImage: UIImage(named: "ic_launcher"))
            self.appTitleLabel.text = model.title!
            self.appDetailLabel.text = model.sub_title!
            // 添加其他控件
            
            self.setupOtherData()
        }
    }
    override init(frame: CGRect) {
        super.init(frame: frame)
        // 添加centerView
        centerView.frame = self.bounds;
        self.addSubview(centerView)
        // 顶部图片
        headerImgView.frame = CGRectMake(0, 0, SCREEN_WIDTH, 170);
        self.centerView.addSubview(headerImgView)
        // appIcon
        appIconView.frame = CGRect(x: UI_MARGIN_20, y: CGRectGetMaxY(headerImgView.frame) + UI_MARGIN_20, width: 50, height: 50)
        self.centerView.addSubview(appIconView)
        // app大标题
        let appTitleLabelX : CGFloat = CGRectGetMaxX(appIconView.frame)+UI_MARGIN_20;
        let appTitleLabelW : CGFloat = SCREEN_WIDTH-UI_MARGIN_20-appTitleLabelX;
        appTitleLabel.frame = CGRect(x: appTitleLabelX, y: CGRectGetMaxY(headerImgView.frame)+25, width: appTitleLabelW, height: 20)
        self.centerView.addSubview(appTitleLabel)
        // app详情
        appDetailLabel.frame = CGRect(x: appTitleLabelX, y: CGRectGetMaxY(appTitleLabel.frame), width: appTitleLabelW, height: 20)
        self.centerView.addSubview(appDetailLabel)
        // appicon + toolbar高度
        contentY = headerImgView.height+UI_MARGIN_20+100
    }

    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    //MARK : -DataSource
    /**
    *  设置评论数据
    */
    func setCommentData(comments : Array<XMCommentsDataModel>) {
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
    
    //MARK:- private Methods
    private func setupOtherData() {
        // 计算文字高度，添加app描述文段
        let describeLabel = self.createPTitleLabel()
        self.centerView.addSubview(describeLabel)
        let descriSize = self.calculateTextHeight(model.digest!, label: describeLabel)
        describeLabel.frame = CGRect(x: UI_MARGIN_10, y: contentY + UI_MARGIN_10, width: SCREEN_WIDTH-2*UI_MARGIN_10, height: descriSize.height)
        contentY = CGRectGetMaxY(describeLabel.frame) + UI_MARGIN_20
        // 添加http文段
        let _ = XMLParserUtil(content: model.content!) { [unowned self](array) -> Void in
            // 拿到解析完的数组后添加控件
            for contentModel in array {
                
                if contentModel.contentType == XMLContentType.XMLContentTypeH2 {
                    // 标题
                    self.contentY += UI_MARGIN_10
                    let h2TitlLabel = self.createH2TitleLabel()
                    h2TitlLabel.text = contentModel.content
                    h2TitlLabel.frame = CGRect(x: UI_MARGIN_10, y: self.contentY, width: SCREEN_WIDTH-2*UI_MARGIN_10, height: 20)
                    self.centerView.addSubview(h2TitlLabel)
                    self.contentY += h2TitlLabel.height + UI_MARGIN_10
                } else if contentModel.contentType == XMLContentType.XMLContentTypeP {
                    // 描述
                    let pTitleLabel = self.createPTitleLabel()
                    pTitleLabel.frame = CGRect(x: UI_MARGIN_10, y: self.contentY, width: SCREEN_WIDTH-2*UI_MARGIN_10, height: 20)
                    let pTitleSize = self.calculateTextHeight(contentModel.content, label: pTitleLabel)
                    self.centerView.addSubview(pTitleLabel)
                    self.contentY += pTitleSize.height + UI_MARGIN_10
                } else if contentModel.contentType == XMLContentType.XMLContentTypeA {
                    // 点击下载
                    let aTitleBtn = self.createATitleButton()
                    aTitleBtn.frame = CGRect(x: UI_MARGIN_10, y: self.contentY, width: 60, height: 20)
                    self.centerView.addSubview(aTitleBtn)
                    self.contentY += aTitleBtn.height + UI_MARGIN_10
                } else if contentModel.contentType == XMLContentType.XMLContentTypeImg {
                    
                    // 根据url 获取图片高度
                    let size : CGSize = contentModel.content.getImageSizeWithURL()
                    // 获取 _ 的位置
                    let imgView : UIImageView = self.createImgView()
                    imgView.frame = CGRectMake(UI_MARGIN_10, self.contentY, size.width, size.height)
                    imgView.center.x = SCREEN_WIDTH*0.5
                    imgView.xm_setBlurImageWithURL(NSURL(string: contentModel.content), placeholderImage: UIImage(named: "home_logo_pressed"))
                    self.centerView.addSubview(imgView)
                    self.contentY += size.height + UI_MARGIN_10
                }
            }
        }

        
        // 分享view
        let shareView : XMHomeDetailShareView = XMHomeDetailShareView.shareView()
        shareView.frame = CGRect(x: UI_MARGIN_10, y: contentY, width: SCREEN_WIDTH-2*UI_MARGIN_10, height: shareView.height)
        shareView.centerViewDidClickWithBlock { [unowned self]() -> Void in
            self.centerDelegate?.homeDetailCenterViewBottomShareDidClick(self)
        }
        self.centerView.addSubview(shareView)
        contentY += shareView.height

        // 评论view
        if model.comments.count != 0 {
            let commentLabel = self.createTitleViwe("评论")
            commentLabel.frame = CGRectMake(UI_MARGIN_10, contentY+2*UI_MARGIN_10, 35, 20)
            contentY = CGRectGetMaxY(commentLabel.frame)+UI_MARGIN_10;
            // 分割线
            let sepLine = self.createTitleSeparatLine()
            sepLine.frame = CGRectMake(CGRectGetMaxX(commentLabel.frame), commentLabel.center.y, 80, 0.5)
//
//            // 添加评论
//            for i in 0..<model.comments.count {
//                let commentView : XMFindAppDetailCommentCell = XMFindAppDetailCommentCell(frame: CGRectMake(0, contentY, SCREEN_WIDTH, 50))
//                commentView.setData(self.model.comments[i])
//                self.centerView.addSubview(commentView)
//                contentY += commentView.height
//            }
        }
        
        // 设置contentsize
        self.centerView.height = contentY
        self.contentSize = CGSize(width: 0, height: contentY)
    }
    // 根据文字计算高度
    private func calculateTextHeight (text : String, label : YYLabel) -> CGSize {
        // 设置文字样式
        let attributString : NSMutableAttributedString = NSMutableAttributedString(string: text)
        let paragraphStyle = NSMutableParagraphStyle()
        paragraphStyle.lineSpacing = 5.0
        attributString.yy_font = UI_FONT_16
        attributString.yy_color = UIColor.darkGrayColor()
        attributString.addAttribute(NSParagraphStyleAttributeName , value: paragraphStyle, range: NSMakeRange(0, text.length))
        let textLayout = YYTextLayout(containerSize: CGSize(width: SCREEN_WIDTH-2*UI_MARGIN_10, height: CGFloat.max), text: attributString)
        label.attributedText = attributString
        // 设置样式
        label.size = textLayout.textBoundingSize
        label.textLayout = textLayout
        
        return textLayout.textBoundingSize
    }
    
    //MARK: - Public Method
    func updateHeaderView() {
        let HeaderHeight : CGFloat = headerImgView.height
        let HeaderCutAway: CGFloat = 170
        
        var headerRect = CGRect(x: 0, y: 0, width: SCREEN_WIDTH, height: HeaderHeight)
        if self.contentOffset.y < 0 {
            headerRect.origin.y = self.contentOffset.y
            headerRect.size.height = -self.contentOffset.y + HeaderCutAway
            headerImgView.frame = headerRect
        }
    }
    
    //MARK: - Action Event

    //MARK: - getter or setter
    // 内容
    private lazy var centerView : UIView = {
        let centerView : UIView = UIView()
        return centerView
    }()
    
    // 顶部图片
    private lazy var headerImgView : UIImageView = {
        let headerImgView : UIImageView = UIImageView(image: UIImage(named: "home_logo_pressed"))
        headerImgView.contentMode = .ScaleAspectFill
        return headerImgView
    }()
    
    // appIcon
    private lazy var appIconView : UIImageView = {
        let appIconView : UIImageView = UIImageView(image: UIImage(named: "ic_launcher"))
//        appIconView.contentMode = .ScaleAspectFit
        appIconView.layer.cornerRadius = UI_MARGIN_10
        appIconView.layer.masksToBounds = true
        return appIconView
    }()
    
    // app大标题
    private lazy var appTitleLabel : UILabel = {
        let appTitleLabel : UILabel = UILabel()
        appTitleLabel.font = UI_FONT_20
        appTitleLabel.textColor = UIColor.blackColor()
        return appTitleLabel
    }()
    
    // app 详情
    private lazy var appDetailLabel : UILabel = {
        let appDetailLabel : UILabel = UILabel()
        appDetailLabel.font = UI_FONT_14
        appDetailLabel.textColor = UIColor.darkGrayColor()
        return appDetailLabel
    }()
    
    private func createTitleViwe(title : String) -> UILabel {
        let label : UILabel = UILabel()
        label.font = UIFont.systemFontOfSize(15)
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
    // 标题(h2)
    private func createH2TitleLabel() -> UILabel {
        let h2TitleLabel = UILabel()
        h2TitleLabel.textColor = UIColor.blackColor()
        h2TitleLabel.font = UI_FONT_16
        return h2TitleLabel
    }
    
    // 描述(p)
    private func createPTitleLabel() -> YYLabel {
        let contentLabel : YYLabel = YYLabel()
        contentLabel.displaysAsynchronously = true
        contentLabel.font = UI_FONT_16
        contentLabel.textColor = UIColor.darkGrayColor()
        contentLabel.numberOfLines = 0
        return contentLabel
    }
    
    
    // 图片(Img)
    private func createImgView() -> UIImageView {
        let imgView : UIImageView = UIImageView()
        imgView.layer.cornerRadius = 3
        imgView.layer.borderColor = UIColor.lightGrayColor().CGColor
        imgView.layer.borderWidth = 0.5
        imgView.contentMode = .ScaleAspectFit
        return imgView
    }
    
    // 下载(a) 
    private func createATitleButton() -> UIButton {
        let btn : UIButton = UIButton()
        btn.titleLabel?.textAlignment = NSTextAlignment.Left
        btn.titleLabel?.font = UI_FONT_14
        btn.setTitle("点击下载", forState: .Normal)
        btn.setTitleColor(UI_COLOR_APPNORMAL, forState: .Normal)
        return btn
    }
}
