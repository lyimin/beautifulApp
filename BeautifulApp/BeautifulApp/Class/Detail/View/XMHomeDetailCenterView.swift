//
//  XMHomeDetailCenterView.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/19.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

protocol XMHomeDetailCenterViewDelegate {
    func homeDetailCenterView(centerView : XMHomeDetailCenterView ,returnButtonDidClick returnButton : UIButton)
    func homeDetailCenterViewCollectDidClick(centerView : XMHomeDetailCenterView)
    func homeDetailCenterViewShareDidClick (centerView : XMHomeDetailCenterView)
    func homeDetailCenterViewDownloadDidClick(centerView : XMHomeDetailCenterView)
    func homeDetailCenterViewBottomShareDidClick(centerView : XMHomeDetailCenterView)
    
}

class XMHomeDetailCenterView: UIView, UIScrollViewDelegate {
    // MARK:- VIEW
    
    // scrollview
    @IBOutlet weak var centerScroll: UIScrollView!
    @IBOutlet weak var centerView: UIView!
    // 返回
    @IBOutlet weak var returnButton: UIButton!
    // 顶部图片
    @IBOutlet weak var headerImgView: UIImageView!
    // 图标
    @IBOutlet weak var appIconView: UIImageView!
    // 大标题
    @IBOutlet weak var titleLabel: UILabel!
    // 详情标题
    @IBOutlet weak var detailLabel: UILabel!
    // 收藏按钮
    @IBOutlet weak var collectButton: UIButton!
    @IBOutlet weak var collectLabel: UILabel!
    // 分享
    @IBOutlet weak var shareButton: UIButton!
    @IBOutlet weak var shareLabel: UILabel!
    // 下载
    @IBOutlet weak var downloadButton: UIButton!
    @IBOutlet weak var downloadLabel: UILabel!
    // 工具条
    @IBOutlet weak var toolBarView: UIView!
    // 评论page
    private var page : Int = 1
    // 记录当前高度
    private var contentY : CGFloat = 0
    // MARK:-DATA
    // 代理
    var delegate : XMHomeDetailCenterViewDelegate?
    var model : XMHomeDataModel! {
        willSet {
            self.model = newValue
        }
        
        didSet {
            self.headerImgView.xm_setBlurImageWithURL(NSURL(string: model.cover_image!), placeholderImage: UIImage(named: "home_logo_pressed"))
            // 图标
            self.appIconView.xm_setBlurImageWithURL(NSURL(string: model.icon_image!), placeholderImage: UIImage(named: "ic_launcher"))
            
            // 添加其他控件
            self.setupOtherData()
        }
    }
    
    class func detailCenterView () -> XMHomeDetailCenterView {
        return NSBundle.mainBundle().loadNibNamed("XMHomeDetailCenterView", owner: nil, options: nil)[0] as! XMHomeDetailCenterView
    }
    
    override func awakeFromNib() {
        super.awakeFromNib()
        self.centerScroll.delegate = self
        contentY = CGRectGetMaxY(toolBarView.frame) + UI_MARGIN_10
        
        self.centerScroll.footerViewPullToRefresh(.XMRefreshDirectionVertical) { [unowned self]() -> Void in
            self.getCommentData()
        }
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
        self.centerScroll.contentSize = CGSizeMake(0, contentY)
    }
    
    /**
     * 获取评论数据
     */
    func getCommentData() {
        let params : NSDictionary = ["app" : self.model.id!, "page" : self.page]
        XMNetworkTool.get(APIConfig.API_Home_Comment, params: params, success: { [unowned self](json) -> Void in
            
            if json["data"] is NSDictionary {
                let data : NSDictionary = json["data"] as! NSDictionary
                if data["comments"] is NSArray {
                    let comments : NSArray = data["comments"] as! NSArray
                    if comments.count != 0 {
                        // 添加评论到模型
                        var commentArray : Array<XMCommentsDataModel> = Array()
                        for dict in comments {
                            let model : XMCommentsDataModel = XMCommentsDataModel(dict: dict as! NSDictionary)
                            self.model.comments.append(model)
                            commentArray.append(model)
                        }
                        self.page++;
                        self.setCommentData(commentArray)
                    }
                }
            }
            
            self.centerScroll.footerEndRefreshing()
            }) { (error) -> Void in
                self.centerScroll.footerEndRefreshing()
        }
    }

    //MARK:- private Methods
    private func setupOtherData() {
        // 计算文字高度，添加app描述文段
        let describeLabel = self.createPTitleLabel()
        describeLabel.frame = CGRect(x: UI_MARGIN_10, y: CGRectGetMaxY(self.toolBarView.frame) + UI_MARGIN_10, width: SCREEN_WIDTH-2*UI_MARGIN_10, height: 20)
        self.centerView.addSubview(describeLabel)
        
        let descriSize = self.calculateTextHeight(model.digest!, label: describeLabel)
        describeLabel.size = descriSize
        
        contentY += descriSize.height + UI_MARGIN_10
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
                    imgView.center.x = self.centerView.center.x
                    imgView.xm_setBlurImageWithURL(NSURL(string: contentModel.content), placeholderImage: UIImage(named: "home_logo_pressed"))
                    self.centerView.addSubview(imgView)
                    self.contentY += size.height + UI_MARGIN_10
                }
            }
        }
        
        // 分享view
        let shareView : XMHomeDetailShareView = XMHomeDetailShareView.shareView()
        shareView.y = contentY
        shareView.height = 180
        shareView.centerViewDidClickWithBlock { [unowned self]() -> Void in
            self.delegate?.homeDetailCenterViewBottomShareDidClick(self)
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
            
            // 添加评论
//            for i in 0..<model.comments.count {
//                let commentView : XMFindAppDetailCommentCell = XMFindAppDetailCommentCell(frame: CGRectMake(0, contentY, SCREEN_WIDTH, 50))
//                commentView.commentModel = self.model.comments[i]
//                self.centerView.addSubview(commentView)
//                contentY += commentView.height
//            }
        }
        
        // 设置contentsize
        self.centerView.height = contentY
        self.centerScroll.contentSize = CGSize(width: 0, height: contentY)
    }
    // MARK: -更新headerView的frame 。 实现zoom效果
    private func updateHeaderView() {
        let HeaderHeight : CGFloat = headerImgView.height
        let HeaderCutAway: CGFloat = 170
        
        var headerRect = CGRect(x: 0, y: 0, width: SCREEN_WIDTH, height: HeaderHeight)
        if self.centerScroll.contentOffset.y < 0 {
            headerRect.origin.y = self.centerScroll.contentOffset.y
            headerRect.size.height = -self.centerScroll.contentOffset.y + HeaderCutAway
            headerImgView.frame = headerRect
        }
    }
    
    private func toolBarToNavAnimation() {
        UIView.animateWithDuration(0.5, animations: { () -> Void in
            self.collectButton.x = 60
            self.collectLabel.alpha = 0
            self.shareButton.x = 110
            self.shareLabel.alpha = 0
            self.downloadButton.x = 160
            self.downloadLabel.alpha = 0
        })
    }
    
    private func toolBarToScrollAnimation() {
        UIView.animateWithDuration(0.5, animations: { () -> Void in
            self.collectButton.x = 55
            self.shareButton.x = 130
            self.downloadButton.x = 205
            
            self.collectLabel.alpha = 1
            self.shareLabel.alpha = 1
            self.downloadLabel.alpha = 1
            }) { (finish) -> Void in
                
        }
    }

    // 根据文字计算高度
    private func calculateTextHeight (text : String, label : YYLabel) -> CGSize {
        // 设置文字样式
        let attributString : NSMutableAttributedString = NSMutableAttributedString(string: text)
        let paragraphStyle = NSMutableParagraphStyle()
        paragraphStyle.lineSpacing = 5.0
        attributString.yy_font = UI_FONT_14
        attributString.yy_color = UIColor.darkGrayColor()
        attributString.addAttribute(NSParagraphStyleAttributeName , value: paragraphStyle, range: NSMakeRange(0, text.length))
        let textLayout = YYTextLayout(containerSize: CGSize(width: SCREEN_WIDTH-2*UI_MARGIN_10, height: CGFloat.max), text: attributString)
        label.attributedText = attributString
        // 设置样式
        label.size = textLayout.textBoundingSize
        label.textLayout = textLayout
        
        return textLayout.textBoundingSize
    }
    
    //MARK: - UIScrollview Delegate
    func scrollViewDidScroll(scrollView: UIScrollView) {
        self.updateHeaderView()
        if scrollView.contentOffset.y >= 215 {
            self.toolBarView.y = 20
            // 显示在标题栏动画
            self.toolBarToNavAnimation()
            
        } else {
            self.toolBarView.y = 235 - scrollView.contentOffset.y
            self.toolBarToScrollAnimation()
        }
    }
    
    //MARK: - Action Event
    
    @IBAction func returnButtonDidClick(sender: UIButton) {
        self.delegate?.homeDetailCenterView(self, returnButtonDidClick: sender)
    }
    @IBAction func collectBtnDidClick(sender: UIButton) {
        self.delegate?.homeDetailCenterViewCollectDidClick(self)
    }
    @IBAction func shareBtnDidClick(sender: UIButton) {
        self.delegate?.homeDetailCenterViewShareDidClick(self)
    }
    @IBAction func downLoadBtnDidClick(sender: UIButton) {
        self.delegate?.homeDetailCenterViewDownloadDidClick(self)
    }

    //MARK: - getter or setter
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
        contentLabel.font = UI_FONT_14
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
        imgView.center.x = self.centerView.center.x
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
