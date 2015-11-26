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

class XMHomeDetailCenterView: UIView, UIWebViewDelegate {
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
    // MARK:-DATA
    // 代理
    var delegate : XMHomeDetailCenterViewDelegate?
    var model : XMHomeDataModel! {
        willSet {
            self.model = newValue
        }
        
        didSet {
            self.headerImgView.sd_setImageWithURL(NSURL(string: model.cover_image!), placeholderImage: UIImage(named: "home_logo_pressed"))
            // 图标
            self.appIconView.sd_setImageWithURL(NSURL(string: model.icon_image!), placeholderImage: UIImage(named: "ic_launcher"))
            
            // 添加其他控件
            self.setupOtherData()
        }
    }
    
    class func centerView () -> XMHomeDetailCenterView {
        return NSBundle.mainBundle().loadNibNamed("XMHomeDetailCenterView", owner: nil, options: nil)[0] as! XMHomeDetailCenterView
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
        contentWebView.delegate = self
        contentWebView.frame = CGRectMake(0, CGRectGetMaxY(self.describeLabel.frame)+20, SCREEN_WIDTH, 500)
        contentWebView.loadHTMLString(model.content!, baseURL: nil)
        self.centerScroll.addSubview(contentWebView)
        
    }
    // UIWebview delegate
    func webViewDidFinishLoad(webView: UIWebView) {
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
    private var contentWebView : UIWebView = {
        let contentWebView : UIWebView = UIWebView()
        contentWebView.userInteractionEnabled = false
        return contentWebView
    }()
}
