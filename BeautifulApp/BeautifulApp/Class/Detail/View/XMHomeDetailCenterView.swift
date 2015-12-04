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
}

class XMHomeDetailCenterView: UIView, WKNavigationDelegate, UIScrollViewDelegate {
    // MARK:- VIEW
    
    // scrollview
    @IBOutlet weak var centerScroll: UIScrollView!
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
    
    private var photoisZoom : Bool = false
    
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
    
    class func centerView () -> XMHomeDetailCenterView {
        return NSBundle.mainBundle().loadNibNamed("XMHomeDetailCenterView", owner: nil, options: nil)[0] as! XMHomeDetailCenterView
    }
    
    override func awakeFromNib() {
        super.awakeFromNib()
        self.centerScroll.delegate = self
    }
    // private 
    private func setupOtherData() {
        // 计算文字高度，添加app描述文段
        describeLabel.frame = CGRect(x: 10, y: CGRectGetMaxY(self.toolBarView.frame), width: 300, height: 100)
        self.centerScroll.addSubview(describeLabel)
        
        let describeLabelRect = (model.digest! as NSString).boundingRectWithSize(CGSize(width: 300, height: CGFloat.max), options: [.UsesLineFragmentOrigin , .UsesFontLeading], attributes: [NSFontAttributeName : describeLabel.font], context: nil)
        self.describeLabel.size = describeLabelRect.size
        // 设置文字样式
        let attributString : NSMutableAttributedString = NSMutableAttributedString(string: model.digest!)
        let paragraphStyle = NSMutableParagraphStyle()
        paragraphStyle.lineSpacing = 5.0
        attributString.addAttribute(NSParagraphStyleAttributeName , value: paragraphStyle, range: NSMakeRange(0, model.digest!.length))
        self.describeLabel.attributedText = attributString
        self.describeLabel.sizeToFit()
        
        // 添加http文段
        contentWebView.navigationDelegate = self
        contentWebView.frame = CGRectMake(0, CGRectGetMaxY(self.describeLabel.frame)+20, SCREEN_WIDTH, 500)
        contentWebView.loadHTMLString(model.content!, baseURL: nil)
        self.centerScroll.addSubview(contentWebView)
        
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
    // UIScrollview Delegate
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

    // WKWebview delegate
    
    func webView(webView: WKWebView, didFinishNavigation navigation: WKNavigation!) {
        let tempView : UIScrollView = contentWebView.subviews.first as! UIScrollView
        tempView.scrollEnabled = false
        contentWebView.height = tempView.contentSize.height
        // 设置contentsize
        self.centerScroll.contentSize = CGSize(width: 0, height: contentWebView.y+tempView.contentSize.height)
    }
    
    // Action Event
    
    @IBAction func returnButtonDidClick(sender: UIButton) {
        self.delegate?.homeDetailCenterView(self, returnButtonDidClick: sender)
    }

    //getter or setter
    private var describeLabel : UILabel = {
        let describeLabel : UILabel = UILabel()
        describeLabel.numberOfLines = 0
        describeLabel.font = UIFont.systemFontOfSize(14)
        describeLabel.textColor = UIColor.darkGrayColor()
        return describeLabel
    }()
    
    // 内容
    private var contentWebView : WKWebView = {
        let contentWebView : WKWebView = WKWebView()
        return contentWebView
    }()
    
   
}
