//
//  XMHomeViewController.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/8.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMHomeViewController: UIViewController, XMHomeHeaderViewDelegate,UICollectionViewDataSource,XMHomeBottomCollectViewDelegate,UICollectionViewDelegate {
    // 页数
    private var page : Int = 1
    // viewModel对象
    private var viewModel : XMHomeViewModel!
    // 上一个index
    private var lastIndex : NSIndexPath?
    // 当前index
    private var index : Int! {
        willSet {
            self.index = newValue
        }
        
        didSet {
            guard self.viewModel.dataSource.count > 0 else {
                return
            }
            // 获取模型
            let model : XMHomeDataModel = self.viewModel.dataSource[index]
            // 设置header模型
            self.headerView.homeModel = model
            // 设置背景的动画
            UIView.animateWithDuration(0.5, animations: { () -> Void in
                self.view.backgroundColor = UIColor.colorWithHexString(stringToConvert: model.recommanded_background_color!)
            })
        }
    }
    //MARK: - life cycle
    override func viewDidLoad() {
        super.viewDidLoad()
        // 初始化界面
        self.view.backgroundColor = UI_COLOR_APPNORMAL
        
        self.view.addSubview(headerView)
        headerView.delegate = self
        
        self.view.addSubview(centerCollectView)
        centerCollectView.delegate = self
        centerCollectView.dataSource = self
        
        self.view.addSubview(bottomCollectView)
        bottomCollectView.bottomViewDelegate = self
        bottomCollectView.delegate = self
        bottomCollectView.dataSource = self
        
        // 获取viewModel
        viewModel = XMHomeViewModel(regiHeaderView: headerView, centerView: centerCollectView, bottomView: bottomCollectView)
        // 获取数据
        self.centerCollectView.headerViewPullToRefresh(.XMRefreshDirectionHorizontal, callback: { [unowned self]() -> Void in
            self.page = 1
            self.viewModel.getData(self.page, callBack: { (dataSoure) -> Void in
                // 默认选中0
                self.lastIndex = nil
                self.index = 0
                self.scrollViewDidEndDecelerating(self.centerCollectView)
            })
        })
        
        self.centerCollectView.footerViewPullToRefresh (.XMRefreshDirectionHorizontal, callback:{ [unowned self]() -> Void in
            self.page += 1
            self.viewModel.getData(self.page, callBack: { (dataSoure) -> Void in
                // 默认选中0
                self.lastIndex = nil
                self.index = dataSoure.count-10
                self.scrollViewDidEndDecelerating(self.centerCollectView)
            })
        })
        
        self.centerCollectView.headerViewBeginRefreshing()
    }
        //MARK: - scrollerDelegate
    func scrollViewDidScroll(scrollView: UIScrollView) {
        if scrollView.tag == 100 {
            let index : Int = Int((scrollView.contentOffset.x + 0.5*scrollView.width) / scrollView.width)
            if index > self.viewModel.dataSource.count - 1 {
                self.index = self.viewModel.dataSource.count - 1
            } else {
                self.index = index
            }
        } else {
            
        }
    }

    func scrollViewDidEndDecelerating(scrollView: UIScrollView) {
        if scrollView.tag == 100 {
            // 设置底部动画
            self.bottomAnimation(NSIndexPath(forRow: index, inSection: 0))
            // 发送通知改变侧滑菜单的颜色
            let model : XMHomeDataModel = self.viewModel.dataSource[index]
            let noti : NSNotification = NSNotification(name: NOTIFY_SETUPBG, object: model.recommanded_background_color!)
            NSNotificationCenter.defaultCenter().postNotification(noti)
        }
    }
    
    // MARK: - UICollection Delegate 
    
    func collectionView(collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return self.viewModel.dataSource.count
    }
    
    func collectionView(collectionView: UICollectionView, cellForItemAtIndexPath indexPath: NSIndexPath) -> UICollectionViewCell {
        let model : XMHomeDataModel = self.viewModel.dataSource[indexPath.row]
        if collectionView.tag == 100 {
        
            let cell : XMHomeCenterItemView = collectionView.dequeueReusableCellWithReuseIdentifier("XMHomeCenterItemViewID", forIndexPath: indexPath) as! XMHomeCenterItemView
            cell.homeModel = model
            return cell
        } else {
            let cell : XMHomeBottomItemView = collectionView.dequeueReusableCellWithReuseIdentifier("XMHomeBottomItemViewID", forIndexPath: indexPath) as! XMHomeBottomItemView
            cell.y = 50
            cell.iconUrl = model.icon_image

            return cell
        }
    }
    
    func collectionView(collectionView: UICollectionView, didSelectItemAtIndexPath indexPath: NSIndexPath) {
        let model : XMHomeDataModel = self.viewModel.dataSource[indexPath.row]
        self.navigationController?.pushViewController(XMHomeDetailController(model: model), animated: true)
    }
    
    //MARK: -custom Delegate
    func homeHeaderViewMoveToFirstDidClick(headerView: XMHomeHeaderView, moveToFirstBtn: UIButton) {
        centerCollectView.setContentOffset(CGPointZero, animated: false)
        bottomCollectView.setContentOffset(CGPointZero, animated: false)
        self.index = 0
        self.scrollViewDidEndDecelerating(self.centerCollectView)
    }
    func homeHeaderViewMenuDidClick(header: XMHomeHeaderView, menuBtn: UIButton) {
        NSNotificationCenter.defaultCenter().postNotificationName(NOTIFY_SHOWMENU, object: nil)
    }
  
    func homeBottomCollectView(bottomView: UICollectionView, touchIndexDidChangeWithIndexPath indexPath: NSIndexPath?, cellArrayCount: Int) {
        centerCollectView.scrollToItemAtIndexPath(indexPath!, atScrollPosition: UICollectionViewScrollPosition.CenteredHorizontally, animated: false)
        self.index = indexPath?.row
        // 执行底部横向动画
        let cell : UICollectionViewCell? = self.bottomCollectView.cellForItemAtIndexPath(indexPath!)
        // 如果当前不够8个item就不让他滚动
        if cellArrayCount >= 8 {
            self.bottomHorizontalAnimation(cell!, indexPath: indexPath!)
        }
        // 发送通知改变侧滑菜单的颜色
        let model : XMHomeDataModel = self.viewModel.dataSource[index]
        let noti : NSNotification = NSNotification(name: NOTIFY_SETUPBG, object: model.recommanded_background_color!)
        NSNotificationCenter.defaultCenter().postNotification(noti)
        self.lastIndex = indexPath
    }
    
    // MARK: - Event OR Action
    
    
    //MARK: - private methods
    // 底部标签动画
    private func bottomAnimation (indexPath : NSIndexPath) {
        if self.lastIndex?.row == indexPath.row {
            return
        }

        var cell : UICollectionViewCell? = self.bottomCollectView.cellForItemAtIndexPath(indexPath)
        
        if cell == nil {
            self.bottomCollectView.layoutIfNeeded()
            cell = self.bottomCollectView.cellForItemAtIndexPath(indexPath)
        }
        
        if cell != nil {
            // 底部横向动画
            self.bottomHorizontalAnimation(cell!, indexPath: indexPath)
            // 底部纵向动画
            self.bottomVertical(cell!)
            
            self.lastIndex = indexPath
        }
    }
    // 横向动画
    private func bottomHorizontalAnimation(cell : UICollectionViewCell, indexPath:NSIndexPath) {
        if cell.x < SCREEN_WIDTH*0.6 {
            self.bottomCollectView.setContentOffset(CGPointZero, animated: true)
        } else {
            var newX : CGFloat = 0
            // 判断下一个还是上一个
            if self.lastIndex?.row < indexPath.row {
                // 下一个
                newX = self.bottomCollectView.contentOffset.x + cell.width + 2
            } else  {
                // 上一个
                newX = self.bottomCollectView.contentOffset.x - cell.width - 2
            }
            
            self.bottomCollectView.setContentOffset(CGPointMake(newX, 0), animated: true)
        }
    }
    // 纵向动画
    private func bottomVertical(cell : UICollectionViewCell) {
        UIView.animateWithDuration(0.2, animations: { () -> Void in
            cell.y = 10
            }) { (finished) -> Void in
                UIView.animateWithDuration(0.05, animations: { () -> Void in
                    cell.y = 15
                })
        }
        
        if let _ = self.lastIndex {
            let lastBottomView : UICollectionViewCell? = self.bottomCollectView.cellForItemAtIndexPath(self.lastIndex!)
            if lastBottomView != nil {
                UIView.animateWithDuration(0.2, animations: { () -> Void in
                    lastBottomView!.y = 60
                    }) { (finished) -> Void in
                        UIView.animateWithDuration(0.05, animations: { () -> Void in
                            lastBottomView!.y = 50
                        })
                }
            }
        }
    }
    
    //MARK: - getter or setter
    // 头部headerview
    private var headerView : XMHomeHeaderView = {
        let headerView : XMHomeHeaderView = XMHomeHeaderView.headerView()
        headerView.frame = CGRectMake(0, 20, SCREEN_WIDTH, headerView.height)
        return headerView
    }()
    
    // 中间collectionview
    private var centerCollectView : UICollectionView = {
        let collectLayout : XMHomeCenterFlowLayout = XMHomeCenterFlowLayout()
        let collectView : UICollectionView = UICollectionView(frame: CGRectMake(0, 70, SCREEN_WIDTH, 420), collectionViewLayout: collectLayout)
        collectView.showsHorizontalScrollIndicator = false
        collectView.pagingEnabled = true
        
        collectView.registerNib(UINib(nibName: "XMHomeCenterItemView", bundle: nil), forCellWithReuseIdentifier: "XMHomeCenterItemViewID")
        collectView.backgroundColor = UIColor.clearColor()
        collectView.tag = 100
        return collectView
    }()
    
    // 底部collectionView
    private var bottomCollectView : XMHomeBottomCollectView = {
        let collectionLayout : XMHomeBottomFlowLayout = XMHomeBottomFlowLayout()
        let collectView : XMHomeBottomCollectView = XMHomeBottomCollectView(frame: CGRectMake(0, SCREEN_HEIGHT-60, SCREEN_WIDTH, 60), collectionViewLayout: collectionLayout)
        return collectView
    }()
    

}
