//
//  XMHomeViewModel.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/17.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMHomeViewModel: NSObject {
    private var headerView : XMHomeHeaderView!
    private var centerView : UICollectionView!
    private var bottonView : UICollectionView!
    var dataSource : Array<XMHomeDataModel> = Array()
    // 回调
    typealias XMHomeViewModelCallBack = (dataSoure : Array<XMHomeDataModel>) -> Void
    var callBack : XMHomeViewModelCallBack?
    
    convenience init(regiHeaderView : XMHomeHeaderView, centerView : UICollectionView, bottomView : UICollectionView) {
        self.init()
        
        self.headerView = regiHeaderView
        self.centerView = centerView
        self.bottonView = bottomView
    }
    
    
    func getData(page : Int, callBack : XMHomeViewModelCallBack?) {
        let params = ["page" : page]
        self.callBack = callBack
        XMNetworkTool.get(APIConfig.API_Today, params: params, success: { [unowned self](json) -> Void in
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
                    if self.callBack != nil {
                        self.callBack!(dataSoure: self.dataSource)
                    }
                    // 默认选中0
//                    self.lastIndex = nil
//                    self.index = 0
//                    self.scrollViewDidEndDecelerating(self.centerCollectView)
                
                    // 停止刷新
                    self.centerView.headerViewStopPullToRefresh()
                    self.centerView.footerEndRefreshing()
                }
            }
            
            }) { (error) -> Void in
                self.centerView.headerViewStopPullToRefresh()
                self.centerView.footerEndRefreshing()
        }

    }
}
