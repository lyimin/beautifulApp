//
//  XMHomeViewModel.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/17.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit


class XMHomeViewModel: NSObject {
    
    var type : String = "homeViewTodayType"
    private weak var headerView : XMHomeHeaderView!
    private weak var centerView : UICollectionView!
    private weak var bottonView : UICollectionView!
    var dataSource : Array<XMHomeDataModel> = Array()
    // 回调
    typealias XMHomeViewModelSuccessCallBack = (dataSoure : Array<XMHomeDataModel>) -> Void
    typealias XMHomeVieModelErrorCallBack = (error : NSError) -> Void
    var successCallBack : XMHomeViewModelSuccessCallBack?
    var errorCallBack : XMHomeVieModelErrorCallBack?
    override init() {
        super.init()
        
        NSNotificationCenter.defaultCenter().addObserver(self, selector: #selector(XMHomeViewModel.sendNotify_success(_:)), name: NOTIFY_SETUPHOMEVIEWTYPE, object: nil)
    }
    
    deinit {
        NSNotificationCenter.defaultCenter().removeObserver(self, name: NOTIFY_SETUPHOMEVIEWTYPE, object: nil)
    }
    convenience init(regiHeaderView : XMHomeHeaderView, centerView : UICollectionView, bottomView : UICollectionView) {
        self.init()
        
        self.headerView = regiHeaderView
        self.centerView = centerView
        self.bottonView = bottomView
    }
    
    func getData(page : Int, successCallBack : XMHomeViewModelSuccessCallBack?, errorCallBack : XMHomeVieModelErrorCallBack?) {
       
        self.successCallBack = successCallBack
        self.errorCallBack = errorCallBack
        
         var params : NSDictionary? = ["page" : page]
        var httpString : String = ""
        switch type {
            case NOTIFY_OBJ_TODAY:
                httpString = APIConfig.API_Today
                self.centerView.setHeaderHidden(false)
                self.centerView.setFooterHidden(false)
                // 隐藏右标题
                self.headerView.setRightTitleHidden(true)
            case NOTIFY_OBJ_RECOMMEND:
                httpString = APIConfig.API_Recommend
                self.centerView.setHeaderHidden(false)
                self.centerView.setFooterHidden(false)
                self.headerView.setRightTitleHidden(true)
            case NOTIFY_OBJ_ARTICLE :
                httpString = APIConfig.API_Article
                params = nil
                self.headerView.rightTitle = "文章专栏"
                self.headerView.setRightTitleHidden(false)
        default :
                httpString = APIConfig.API_Today
        }
        
        XMNetworkTool.get(httpString, params: params, success: { [unowned self](json) -> Void in
            if json["data"] is NSDictionary {
                let dataDic : NSDictionary = (json["data"] as? NSDictionary)!
                if dataDic["apps"] is NSArray {
                    let array : NSArray = (dataDic["apps"] as? NSArray)!
                    
                    if page == 1 {
                        self.dataSource.removeAll()
                    }
                    
                    // 字典转模型
                    for dict in array {
                        let homeModel : XMHomeDataModel = XMHomeDataModel(dict: dict as! NSDictionary)
                        self.dataSource.append(homeModel)
                    }
                   
                    // 刷新界面
                    self.centerView.reloadData()
                    self.bottonView.reloadData()
                    // 回调给controller
                    if self.successCallBack != nil {
                        self.successCallBack!(dataSoure: self.dataSource)
                    }
                    // 停止刷新
                    self.centerView.headerViewStopPullToRefresh()
                    self.centerView.footerEndRefreshing()
                }
            }
            
            if self.type == NOTIFY_OBJ_ARTICLE {
                // 隐藏下拉刷新
                self.centerView.setHeaderHidden(true)
                self.centerView.setFooterHidden(true)
            }
            
            }) { (error) -> Void in
                self.centerView.headerViewStopPullToRefresh()
                self.centerView.footerEndRefreshing()
                // 错误回调
                if let _ = self.errorCallBack {
                    self.errorCallBack!(error: error as! NSError)
                }
        }
    }
    // 接受到切换界面的通知
    func sendNotify_success (notify : NSNotification) {
        // 拿到type
        self.type = notify.object as! String
        self.centerView.headerViewBeginRefreshing()
    }
   
}
