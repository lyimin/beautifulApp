//
//  XMFindAppDetailController.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/12/1.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMFindAppDetailController: UIViewController,UIScrollViewDelegate, XMFindAppDetailToolViewDelegate {
    // 模型
    private var model : XMFindAppModel!
    override func viewDidLoad() {
        super.viewDidLoad()
        self.view.backgroundColor = UIColor.whiteColor()
        self.automaticallyAdjustsScrollViewInsets = false
        
        centerView.dataModel = model
        self.view.addSubview(centerView)
        
        toolBarView.frame = CGRect(x: 0, y: 155, width: SCREEN_WIDTH, height: toolBarView.height)
        self.view.addSubview(toolBarView)
        
        self.view.addSubview(bottomView)
        
        returnBtn.frame = CGRect(x: UI_MARGIN_20, y: 30, width: 30, height: 30)
        self.view.addSubview(returnBtn)
        self.setLayout()
        
        self.centerView.footerViewPullToRefresh(.XMRefreshDirectionVertical) { [unowned self]() -> Void in
            self.getCommentData()
        }
    }
    
    convenience init(model : XMFindAppModel) {
        self.init()
        self.model = model
    }
    //MARK: - UIScrollViewDelegate
    func scrollViewDidScroll(scrollView: UIScrollView) {
        if scrollView.contentOffset.y >= 125 {
            self.toolBarView.y = 30
            // 显示在标题栏动画
            XMFindAppDetailAnimationUtil.toolBarToNavAnimation(toolBarView)
            
        } else {
            self.toolBarView.y = 155 - scrollView.contentOffset.y
            XMFindAppDetailAnimationUtil.toolBarToScrollAnimation(toolBarView)
        }
    }
    
    //MARK:- CenterViewDelegate
    func FindAppDetailCenterViewReturnBtnDidClick() {
        self.navigationController?.popViewControllerAnimated(true)
    }
    
    func XMFindAppDetailToolViewDownloadBtnClick() {
        let downModel : XMFindAppDownloadModel = model.download_urls.first!
        UIApplication.sharedApplication().openURL(NSURL(string: downModel.url!)!)
    }
    
    func XMFindAppDetailToolViewShareBtnClick() {
        
        let shareModel : XMShareModel = XMShareModel(appContent: model.appDescription!, imgUrl: model.icon_image!, appTitle: model.title!, appDescription: model.appDescription!, appURL: (model.download_urls.first?.url)!)
        
        ShareSDKUtil.shareWithModel(shareModel)
    }
    
    // MARK: - Event Aciton
    func returnBtnDidClick() {
        self.navigationController?.popViewControllerAnimated(true)
    }
    
    //MARK: -Private Methods
    private func setLayout () {
        bottomView.snp_makeConstraints { (make) -> Void in
            make.left.right.bottom.equalTo(self.view)
            make.height.equalTo(40)
        }
    }
    
    /**
     * 获取评论数据
     */
    private func getCommentData() {
        // 获取上一条
        guard model.comments.count != 0 else {
            self.centerView.footerEndRefreshing()
            return
        }
        let lastCommentModel : XMFindAppCommentModel = model.comments.last!
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
                            self.model.comments.append(model)
                            commentArray.append(model)
                        }
                        
                        self.centerView.setCommentData(commentArray)
                    }
                }
            }
            
            self.centerView.footerEndRefreshing()
            }) { (error) -> Void in
                self.centerView.footerEndRefreshing()
        }
    }

    
    //MARK: - Getter or Setter
    private lazy var centerView : XMFindAppDetailCenterView = {
        let centerView : XMFindAppDetailCenterView = XMFindAppDetailCenterView(frame: self.view.bounds)
        centerView.delegate = self
        return centerView
    }()
    
    private lazy var bottomView : XMHomeDetailBottomView = {
        let bottomView : XMHomeDetailBottomView = XMHomeDetailBottomView()
        return bottomView
    }()
    
    private lazy var toolBarView : XMFindAppDetailToolView = {
        let toolBarView : XMFindAppDetailToolView = XMFindAppDetailToolView.toolView()
        toolBarView.delegate = self
        return toolBarView
    }()
    
    // 返回按钮
    private lazy var returnBtn : UIButton = {
        let returnBtn : UIButton = UIButton()
        returnBtn.addTarget(self, action: "returnBtnDidClick", forControlEvents: .TouchUpInside)
        returnBtn.setImage(UIImage(named: "detail_icon_back_normal"), forState: .Normal)
        returnBtn.setImage(UIImage(named: "detail_icon_back_pressed"), forState: .Highlighted)
        return returnBtn
    }()
}
