//
//  XMFindAppDetailCenterView.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/12/1.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

protocol FindAppDetailCenterViewDelegate {
    // 点击返回键
    func FindAppDetailCenterViewReturnBtnDidClick()
}

class XMFindAppDetailCenterView: UIView, UIScrollViewDelegate {
    @IBOutlet weak var centerScrollView: UIScrollView!
    @IBOutlet weak var centerView: UIView!
    // 用户名
    @IBOutlet weak var userNameLabel: UILabel!
    // 用户头像
    @IBOutlet weak var userIconView: XMImageView!
    // 用户详情
    @IBOutlet weak var userDetailLabel: UILabel!
    // app图片
    @IBOutlet weak var appIconView: XMImageView!
    // app名
    @IBOutlet weak var appNameLabel: UILabel!
    // 分享
    @IBOutlet weak var shareBtn: UIButton!
    @IBOutlet weak var shareLabel: UILabel!
    // 下载
    @IBOutlet weak var downLoadBtn: UIButton!
    @IBOutlet weak var downLoadLabel: UILabel!
    // 工具条
    @IBOutlet weak var toolBar: UIView!
    // 代理
    var delegate : FindAppDetailCenterViewDelegate?
    
    var dataModel : XMFindAppModel! {
        willSet {
            self.dataModel = newValue
        }
        
        didSet {
            self.setData()
        }
    }
//MARK: -life cycle
    class func AppDetailCenterView () -> XMFindAppDetailCenterView {
        return NSBundle.mainBundle().loadNibNamed("XMFindAppDetailCenterView", owner: nil, options: nil).first as!XMFindAppDetailCenterView
    }
    
    override func awakeFromNib() {
        super.awakeFromNib()
        
        self.centerScrollView.footerViewPullToRefresh(.XMRefreshDirectionVertical) { [unowned self]() -> Void in
            self.getCommentData()
        }
    }
//MARK: - dataSource
    
    /**
        设置数据
     */
    private func setData() {
        // 设置标题
        self.userNameLabel.text = dataModel.author_name!
        // 详情
        self.userDetailLabel.text = dataModel.author_career!
        // 头像
        self.userIconView.xm_setBlurImageWithURL(NSURL(string: dataModel.author_avatar_url!)!, placeholderImage:UIImage(named: "detail_portrait_default"))
        self.appIconView.xm_setBlurImageWithURL(NSURL(string: dataModel.icon_image!)!, placeholderImage: UIImage(named: "ic_launcher"))
        self.appNameLabel.text = dataModel.title!
        
// MARK : 设置动态的view ------------ 很多view需要手动创建
        let margin : CGFloat = 10
        self.contentLabel.frame = CGRectMake(margin, CGRectGetMaxY(self.toolBar.frame) + 10, SCREEN_WIDTH-2*margin, 20)
    // 详情文字
        // 计算高度
        let contentText : String = (dataModel.appDescription! as NSString).stringByReplacingOccurrencesOfString("<br/>", withString: "\n")
        // 设置样式
        let attributString : NSMutableAttributedString = NSMutableAttributedString(string: contentText)
        attributString.setAttributes([NSFontAttributeName : UI_FONT_14], range: NSMakeRange(0, contentText.length))
        let paragraphStyle = NSMutableParagraphStyle()
        paragraphStyle.lineSpacing = 5.0
        attributString.yy_color = UIColor.darkGrayColor()
        attributString.addAttribute(NSParagraphStyleAttributeName , value: paragraphStyle, range: NSMakeRange(0, contentText.length))
        let textLayout = YYTextLayout(containerSize: CGSize(width: SCREEN_WIDTH-2*margin, height: CGFloat.max), text: attributString)
        // 设置frame
        contentLabel.size = textLayout.textBoundingSize
        contentLabel.textLayout = textLayout
        self.centerView.addSubview(self.contentLabel)
    
    // 添加图片
        contentY = CGRectGetMaxY(contentLabel.frame) + margin
        for i in 0..<dataModel.all_images.count {
            let url : String = self.dataModel.all_images[i]
            // 根据url 获取图片高度
            let size : CGSize = url.getImageSizeWithURL(url)
            // 获取 _ 的位置
            let imgView : UIImageView = self.createImgView()
            imgView.frame = CGRectMake(10, contentY, size.width, size.height)
            imgView.center.x = self.centerView.center.x
            imgView.xm_setBlurImageWithURL(NSURL(string: url), placeholderImage: UIImage(named: "home_logo_pressed"))
            self.centerView.addSubview(imgView)
            contentY += size.height + margin
        }
        
    // 美过的美友
        if dataModel.up_users.count != 0 {
            let loveUserLabel = self.createTitleViwe("美过的美友")
            loveUserLabel.frame = CGRectMake(margin, contentY + margin*2, 80, 20)
            
            // 分割线
            let sepLine = self.createTitleSeparatLine()
            sepLine.frame = CGRectMake(CGRectGetMaxX(loveUserLabel.frame), loveUserLabel.center.y, 220, 0.5)
            contentY = CGRectGetMaxY(loveUserLabel.frame)+margin;
            // 添加点赞的头像
            // 头像大小
            let headerSize : CGFloat = 30
            let imgMargin : CGFloat = (SCREEN_WIDTH-2*margin-8*headerSize)/7
            for i in 0..<dataModel.up_users.count {
                let userImg : UIImageView = self.createUserImgView()
                // 获取模型
                let upUserDate : XMUpUserDataModel = dataModel.up_users[i]
                userImg.xm_setBlurImageWithURL(NSURL(string: upUserDate.avatar_url!), placeholderImage: UIImage(named: "detail_portrait_default"))
                userImg.frame = CGRectMake(margin+(CGFloat(i)%8)*(headerSize+imgMargin), contentY + (headerSize+imgMargin) * CGFloat(i/8), headerSize, headerSize)
                if i == dataModel.up_users.count - 1 {
                    contentY = CGRectGetMaxY(userImg.frame);
                }
            }
        }
        
    // 评论
        if dataModel.comments.count != 0 {
            let commentLabel = self.createTitleViwe("评论")
            commentLabel.frame = CGRectMake(margin, contentY+2*margin, 35, 20)
            contentY = CGRectGetMaxY(commentLabel.frame)+margin;
            // 分割线
            let sepLine = self.createTitleSeparatLine()
            sepLine.frame = CGRectMake(CGRectGetMaxX(commentLabel.frame), commentLabel.center.y, 80, 0.5)
            
            // 添加评论
            for i in 0..<dataModel.comments.count {
                let commentView : XMFindAppDetailCommentCell = XMFindAppDetailCommentCell(frame: CGRectMake(0, contentY, SCREEN_WIDTH, 50))
                commentView.commentModel = self.dataModel.comments[i]
                self.centerView.addSubview(commentView)
                contentY += commentView.height
            }
        }
        
    //设置contentsize
        self.centerView.height = contentY
        self.centerScrollView.contentSize = CGSizeMake(0, contentY)
    }
    
    /**
     *  设置评论数据
     */
    func setCommentData(comments : Array<XMFindAppCommentModel>) {
        if comments.count != 0 {
            // 添加评论
            for i in 0..<comments.count {
                let commentView : XMFindAppDetailCommentCell = XMFindAppDetailCommentCell(frame: CGRectMake(0, contentY, SCREEN_WIDTH, 50))
                commentView.commentModel = comments[i]
                self.centerView.addSubview(commentView)
                contentY += commentView.height
            }
        }
        //设置contentsize
        self.centerView.height = contentY
        self.centerScrollView.contentSize = CGSizeMake(0, contentY)
    }
    
    /**
     * 获取评论数据
     */
    func getCommentData() {
        // 获取上一条
        guard self.dataModel.comments.count != 0 else {
            self.centerScrollView.footerEndRefreshing()
            return
        }
        let lastCommentModel : XMFindAppCommentModel = dataModel.comments.last!
        let params : Dictionary = ["app_id" : lastCommentModel.app_id!, "comment_id" : lastCommentModel.id!]
        XMNetworkTool.get(APIConfig.API_FindApp_comments, params: params, success: { [unowned self](json) -> Void in
            
            if json["data"] is NSDictionary {
                let data : NSDictionary = json["data"] as! NSDictionary
                if data["comments"] is NSArray {
                    let comments : NSArray = data["comments"] as! NSArray
                    if comments.count != 0 {
                        // 添加评论到模型
                        var commentArray : Array<XMFindAppCommentModel> = Array()
                        for dict in comments {
                            let model : XMFindAppCommentModel = XMFindAppCommentModel(dict: dict as! NSDictionary)
                            self.dataModel.comments.append(model)
                            commentArray.append(model)
                        }
                        
                        self.setCommentData(commentArray)
                    }
                }
            }
            
            self.centerScrollView.footerEndRefreshing()
            }) { (error) -> Void in
                self.centerScrollView.footerEndRefreshing()
        }
    }
    
    //MARK:- ScrollViewDelegate 
    func scrollViewDidScroll(scrollView: UIScrollView) {
        
        if scrollView.contentOffset.y >= 135 {
            self.toolBar.y = 20
            // 显示在标题栏动画
            self.toolBarToNavAnimation()
        } else {
            self.toolBar.y = 155 - scrollView.contentOffset.y
            self.toolBarToScrollAnimation()
        }
    }
    
    //MARK: - Action or Event
    
    // 点击返回
    @IBAction func returnBtnDidClick(sender: UIButton) {
        self.delegate?.FindAppDetailCenterViewReturnBtnDidClick()
    }
    
    //MARK: - Private Methods
    private func toolBarToNavAnimation() {
        UIView.animateWithDuration(0.5, animations: { () -> Void in
            self.shareBtn.x = 60
            self.shareLabel.alpha = 0
            self.downLoadBtn.x = 110
            self.downLoadLabel.alpha = 0
        })
    }
    
    private func toolBarToScrollAnimation() {
        
        UIView.animateWithDuration(0.5, animations: { () -> Void in
            self.shareBtn.x = 70
            self.downLoadBtn.x = 145
            
            self.shareLabel.alpha = 1
            self.downLoadLabel.alpha = 1
            }) { (finish) -> Void in
                
        }
    }
    // MARK: -Private Methods
    private func createImgView() -> UIImageView {
        let imgView : UIImageView = UIImageView()
        imgView.layer.cornerRadius = 3
        imgView.layer.borderColor = UIColor.lightGrayColor().CGColor
        imgView.layer.borderWidth = 0.5
        imgView.contentMode = .ScaleAspectFit
        imgView.center.x = self.centerView.center.x
        return imgView
    }
    
    private func createUserImgView() -> UIImageView {
        let userImgView : UIImageView = UIImageView()
        userImgView.layer.cornerRadius = 15
        userImgView.layer.borderColor = UIColor.lightGrayColor().CGColor
        userImgView.layer.borderWidth = 1
        userImgView.layer.masksToBounds = true
        self.centerView.addSubview(userImgView)
        return userImgView
    }
    
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
    
    //MARK：-Getter or Setter
    private var contentY : CGFloat = 0
    
    private lazy var contentLabel : YYLabel = {
        var contentLabel : YYLabel = YYLabel()
        contentLabel.font = UI_FONT_14
        contentLabel.textColor = UIColor.darkGrayColor()
        contentLabel.numberOfLines = 0
        return contentLabel
    }()
    
//    private lazy var refreshCommentArray : Array<XMFindAppCommentModel> = Array()
}
