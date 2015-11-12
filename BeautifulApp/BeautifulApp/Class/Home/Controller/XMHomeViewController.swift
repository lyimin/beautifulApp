//
//  XMHomeViewController.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/8.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMHomeViewController: UIViewController, UIScrollViewDelegate, XMHomeHeaderViewDelegate {
    // 数据源
    private var dataSourse : NSArray?
    // 当前index
    private var index : Int! {
        willSet {
            self.index = newValue
        }
        
        didSet {
            // 获取模型
            let model : XMHomeDataModel = self.dataSourse![index] as! XMHomeDataModel
            // 设置header模型
            self.headerView.homeModel = model
            // 设置背景的动画
            UIView.animateWithDuration(0.3, animations: { () -> Void in
                self.view.backgroundColor = UIColor.colorWithHexString(stringToConvert: model.recommanded_background_color!)
            })
            
            // 设置底部动画
            
        }
    }
    override func viewDidLoad() {
        super.viewDidLoad()
        self.view.backgroundColor = UI_COLOR_APPNORMAL
        self.view.addSubview(headerView)
        self.view.addSubview(centerScroll)
        self.view.addSubview(bottomScroll)
        headerView.delegate = self
        centerScroll.delegate = self
        bottomScroll.delegate = self
        // 获取数据
        getData()
    }
    
    // dataSource 
    private func getData() {
        let params = ["page" : "1"]
        self.showProgress()
        XMNetworkTool.get(APIConfig.API_Today, params: params, success: { [unowned self](json) -> Void in
            if json["data"] is NSDictionary {
                let dataDic : NSDictionary = (json["data"] as? NSDictionary)!
                if dataDic["apps"] is NSArray {
                    let array : NSArray = (dataDic["apps"] as? NSArray)!
                    
                    let dataArray = NSMutableArray()
                    // 字典转模型
                    for dict in array {
                        let homeModel : XMHomeDataModel = XMHomeDataModel(dict: dict as! NSDictionary)
                        dataArray.addObject(homeModel)
                    }
                    
                    self.dataSourse = dataArray
                }
                self.reloadData()
            }
            
            self.hiddenProgress()
            }) { (error) -> Void in
                self.hiddenProgress()
        }
    }
    
    //MARK: - scrollerDelegate
    func scrollViewDidScroll(scrollView: UIScrollView) {
        if scrollView.tag == 100 {
            let index : Int = Int((scrollView.contentOffset.x + 0.5*scrollView.width) / scrollView.width)
            self.index = index
        }
    }

    //MARK: -custom Delegate 
    func homeHeaderViewMoveToFirstDidClick(headerView: XMHomeHeaderView, moveToFirstBtn: UIButton) {
        self.centerScroll.setContentOffset(CGPoint.zero, animated: true)
    }
    func homeHeaderViewMenuDidClick(header: XMHomeHeaderView, menuBtn: UIButton) {
        
    }
    
    //MARK: - private methods
    private func reloadData () {
        // 设置背景色
        let model : XMHomeDataModel = self.dataSourse?.firstObject as! XMHomeDataModel
        self.headerView.homeModel = model
        self.view.backgroundColor = UIColor.colorWithHexString(stringToConvert: model.recommanded_background_color!)
        // 添加view
        for i in 0..<(self.dataSourse?.count)! {
            let model : XMHomeDataModel = self.dataSourse![i] as! XMHomeDataModel
            // 添加中间view
            let centerView : XMHomeCenterView = XMHomeCenterView.centerView()
            centerView.frame = CGRectMake(5+CGFloat(i)*SCREEN_WIDTH, 0, 310, centerScroll.height)
            centerView.homeModel = model
            self.centerScroll.addSubview(centerView)
            
            // 添加dibuview
            let bottomView : XMHomeBottomView = XMHomeBottomView.bottomView()
            bottomView.iconUrl = model.icon_image
            bottomView.frame = CGRectMake(2+CGFloat(i)*40, bottomScroll.height-5, 38, 60)
            self.bottomScroll.addSubview(bottomView)
        }
        
        
        self.centerScroll.contentSize = CGSizeMake(CGFloat((self.dataSourse?.count)!)*SCREEN_WIDTH, 0)
    }
    
    //MARK: - getter or setter 
    private var headerView : XMHomeHeaderView = {
        let headerView : XMHomeHeaderView = XMHomeHeaderView.headerView()
        headerView.frame = CGRectMake(0, 20, SCREEN_WIDTH, headerView.height)
        return headerView
    }()
    
    private var centerScroll : UIScrollView = {
        let centerScroll = UIScrollView(frame: CGRectMake(0, 70, SCREEN_WIDTH, 420))
        centerScroll.tag = 100;
        centerScroll.showsHorizontalScrollIndicator = false
        centerScroll.pagingEnabled = true
        return centerScroll
    }()
    
    private var bottomScroll : UIScrollView = {
        let bottomScroll = UIScrollView(frame: CGRectMake(0, 490, SCREEN_WIDTH, SCREEN_HEIGHT-490))
        bottomScroll.scrollEnabled = false
        bottomScroll.tag = 101
        bottomScroll.showsHorizontalScrollIndicator = false
        return bottomScroll
    }()

}
