//
//  XMHomeDetailController.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/19.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMHomeDetailController: UIViewController, XMHomeDetailCenterViewDelegate,UIScrollViewDelegate,XMHomeDetailToolViewDelegate {
    
    // 模型
    private var model : XMHomeDataModel!
    // 评论page
    private var page : Int = 1
    
    convenience init(model : XMHomeDataModel){
        self.init()
        self.model = model
    }
    
    // MARK: - Life Cycle
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.view.backgroundColor = UIColor.whiteColor()
//        self.automaticallyAdjustsScrollViewInsets = false
        
        centerView.model = model
        self.view.addSubview(centerView)
        // 工具条
        self.view.addSubview(toolBar)
        // 返回按钮
        self.view.addSubview(returnBtn)
        // 底部评论view
        self.view.addSubview(bottomView)
        
        self.view.bringSubviewToFront(bottomView)
        // 下拉刷新
        self.centerView.footerViewPullToRefresh(XMRefreashDirection.XMRefreshDirectionVertical) { () -> Void in
            self.getCommentData()
        }
        
        // 屏幕适配
        self.setupLayout()
    }
    
    // MARK: ScrollView Delegate
    func scrollViewDidScroll(scrollView: UIScrollView) {
        self.centerView.updateHeaderView()
        if scrollView.contentOffset.y >= 215 {
            self.toolBar.y = self.returnBtn.y
            // 显示在标题栏动画
            XMHomeDetailAnimationUtil.homeDetailToolBarToNavAnimation(self.toolBar)
            
            
        } else {
            self.toolBar.y = 245 - scrollView.contentOffset.y
            XMHomeDetailAnimationUtil.homeDetailToolBarToScrollAnimation(self.toolBar)
        }
    }
    
    // MARK:1-CenterView Delegate
    func homeDetailCenterView(centerView: XMHomeDetailCenterView, returnButtonDidClick returnButton: UIButton) {
        self.navigationController?.popViewControllerAnimated(true)
    }
    // 点击收藏
    func homeDetailToolViewCollectBtnClick() {
        
    }
    // 点击分享
    func homeDetailToolViewShareBtnClick() {
        let title : String = model.title!+"--"+model.sub_title!
        let shareModel : XMShareModel = XMShareModel(appContent: model.digest!, imgUrl: model.icon_image!, appTitle: title, appDescription: model.digest!, appURL: model.download_url!)
        ShareSDKUtil.shareWithModel(shareModel)
    }
    
    // 点击下载
    func homeDetailToolViewDownloadBtnClick() {
        UIApplication.sharedApplication().openURL(NSURL(string: model.download_url!)!)
    }
    
    // 点击下面的分享
    func homeDetailCenterViewBottomShareDidClick(centerView: XMHomeDetailCenterView) {
        print("分享到qq空间")
    }
    
    // MARK: - Event Aciton
    func returnBtnDidClick() {
        self.navigationController?.popViewControllerAnimated(true)
    }
    // MARK: - Private Methods
    private func getCommentData() {
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
                        self.page = self.page + 1;
                        self.centerView.setCommentData(commentArray)
                    }
                }
            }
            
            self.centerView.footerEndRefreshing()
            }) { (error) -> Void in
                self.centerView.footerEndRefreshing()
        }
    }
    // 适配屏幕
    private func setupLayout() {
        
        returnBtn.snp_makeConstraints { (make) -> Void in
            make.leftMargin.equalTo(self.view.snp_leftMargin).offset(10)
            make.topMargin.equalTo(self.view.snp_topMargin).offset(40)
            make.width.equalTo(30)
            make.height.equalTo(30)
        }
        
        bottomView.snp_makeConstraints { (make) -> Void in
            make.left.right.bottom.equalTo(self.view)
            make.height.equalTo(40)
        }
    }
    
    
    // MARK: - Getter or Setter
    // scrollview
    private lazy var centerView : XMHomeDetailCenterView = {
        let centerView : XMHomeDetailCenterView = XMHomeDetailCenterView()
        centerView.frame = CGRect(x: 0, y: 0, width: SCREEN_WIDTH, height: SCREEN_HEIGHT)
        centerView.delegate = self
        centerView.centerDelegate = self
        return centerView
    }()
    // 返回按钮
    private lazy var returnBtn : UIButton = {
        let returnBtn : UIButton = UIButton()
        returnBtn.addTarget(self, action: #selector(XMHomeDetailController.returnBtnDidClick), forControlEvents: .TouchUpInside)
        returnBtn.setImage(UIImage(named: "detail_icon_back_normal"), forState: .Normal)
        returnBtn.setImage(UIImage(named: "detail_icon_back_pressed"), forState: .Highlighted)
        return returnBtn
    }()
    
    // 工具条
    private lazy var toolBar : XMHomeDetailToolView = {
        let toolBar : XMHomeDetailToolView = XMHomeDetailToolView.toolView()
        toolBar.frame = CGRect(x: 0, y: 245, width: SCREEN_WIDTH, height: 30)
        toolBar.delegate = self
        return toolBar
    }()
    
    // 评论栏
    private lazy var bottomView : XMHomeDetailBottomView = {
        let bottomView : XMHomeDetailBottomView = XMHomeDetailBottomView()
        return bottomView
    }()
    
}
