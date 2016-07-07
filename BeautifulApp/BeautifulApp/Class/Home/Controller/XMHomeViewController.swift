//
//  XMHomeViewController.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/8.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMHomeViewController: UIViewController, XMHomeHeaderViewDelegate,UICollectionViewDataSource,XMHomeBottomCollectViewDelegate,UICollectionViewDelegate, UINavigationControllerDelegate {

    //MARK: - Life cycle
    override func viewDidLoad() {
        super.viewDidLoad()
//        self.automaticallyAdjustsScrollViewInsets = false
        NSNotificationCenter.defaultCenter().addObserver(self, selector: "errorBtnDidClick", name: NOTIFY_ERRORBTNCLICK, object: nil)
//        self.navigationController?.delegate = self
        // 初始化界面
        self.view.backgroundColor = UI_COLOR_APPNORMAL
        // 添加头部view
        self.view.addSubview(headerView)
        // 添加中间collection
        self.view.addSubview(centerCollectView)
        // 添加底部collection
        self.view.addSubview(bottomCollectView)
        
        // 获取viewModel
        viewModel = XMHomeViewModel(regiHeaderView: headerView, centerView: centerCollectView, bottomView: bottomCollectView)
        // 获取数据
        self.centerCollectView.headerViewPullToRefresh(.XMRefreshDirectionHorizontal, callback: { [unowned self]() -> Void in
            self.page = 1
            self.viewModel.getData(self.page, successCallBack: { (dataSoure) -> Void in
                // 默认选中0
                self.lastIndex = nil
                self.index = 0
                self.bottomCollectView.setContentOffset(CGPointZero, animated: false)
                self.scrollViewDidEndDecelerating(self.centerCollectView)
                
                }, errorCallBack: { (error) -> Void in
                    // 显示网络错误按钮
//                    self.showNetWorkErrorView()
            })
        })
        
        // 加载更多
        self.centerCollectView.footerViewPullToRefresh (.XMRefreshDirectionHorizontal, callback:{ [unowned self]() -> Void in
            self.page += 1

            self.viewModel.getData(self.page, successCallBack: { (dataSoure) -> Void in
                // 默认选中0
                self.lastIndex = nil
                self.index = dataSoure.count-10
                self.scrollViewDidEndDecelerating(self.centerCollectView)
                }, errorCallBack: { (error) -> Void in
                    self.centerCollectView.setContentOffset(CGPointMake(self.centerCollectView.contentSize.width-SCREEN_WIDTH, 0), animated: false)
            })
        })
        
        // 首次加载时中间显示加载框
        self.showProgress()
        self.viewModel.getData(self.page, successCallBack: { (dataSoure) -> Void in
            
            // 默认选中0
            self.lastIndex = nil
            self.index = 0
            self.bottomCollectView.setContentOffset(CGPointZero, animated: false)
            self.scrollViewDidEndDecelerating(self.centerCollectView)
            
            self.hiddenProgress()
            }) { (error) -> Void in
                // 显示网络错误按钮
                self.showNetWorkErrorView()
                self.hiddenProgress()
        }
        // 适配屏幕
        self.setupLayout()
//        self.centerCollectView.headerViewBeginRefreshing()
    }
    
    //MARK: - ScrollerDelegate
    func scrollViewDidScroll(scrollView: UIScrollView) {
        if scrollView.tag == 100 {
            let index : Int = Int((scrollView.contentOffset.x + 0.5*scrollView.width) / scrollView.width)
            if index > self.viewModel.dataSource.count - 1 {
                self.index = self.viewModel.dataSource.count - 1
            } else {
                self.index = index
            }
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
        // 获取cell中的图片 和 rect 用于做转场动画
        let cell : XMHomeCenterItemView = collectionView.cellForItemAtIndexPath(indexPath) as! XMHomeCenterItemView
        self.curImgView = cell.centerImgView
        // 计算collection点击的item在屏幕中的位置
        let rectInCollectionView : CGRect = (collectionView.layoutAttributesForItemAtIndexPath(indexPath)?.frame)!
        let rectInSuperView : CGRect = collectionView.convertRect(rectInCollectionView, toView: collectionView.superview)
        self.rectInView = CGRect(x: rectInSuperView.origin.x+cell.centerImgView.x, y: rectInSuperView.origin.y+cell.centerImgView.y, width: rectInSuperView.width, height: cell.centerImgView.height)
        // 获取模型
        let model : XMHomeDataModel = self.viewModel.dataSource[indexPath.row]
        let detailController = XMHomeDetailController(model: model)
        self.navigationController?.pushViewController(detailController, animated: true)
    }
    
    //MARK: - UINavigationControllerDelegate
    func navigationController(navigationController: UINavigationController, animationControllerForOperation operation: UINavigationControllerOperation, fromViewController fromVC: UIViewController, toViewController toVC: UIViewController) -> UIViewControllerAnimatedTransitioning? {
        if operation == UINavigationControllerOperation.Push {
            return XMHomeAnimationPushUtil(imageViewRect: self.rectInView!)
        } else {
            return nil
        }
    }
    
    //MARK: Custom Delegate
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
        self.bottomHorizontalAnimation(cell!, indexPath: indexPath!)
        // 发送通知改变侧滑菜单的颜色
        let model : XMHomeDataModel = self.viewModel.dataSource[index]
        let noti : NSNotification = NSNotification(name: NOTIFY_SETUPBG, object: model.recommanded_background_color!)
        NSNotificationCenter.defaultCenter().postNotification(noti)
        self.lastIndex = indexPath
    }
    
    // MARK: - Event OR Action
    func errorBtnDidClick() {
        self.centerCollectView.headerViewBeginRefreshing()
    }
    
    //MARK: - Private Methods
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
        guard self.viewModel.dataSource.count > 8 else {
            return
        }
        
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
    
    //MARK: - Getter or Setter
    
    /// 页数
    private var page : Int = 1
    /// viewModel对象
    private var viewModel : XMHomeViewModel!
    /// 上一个index
    private var lastIndex : NSIndexPath?
    /// 当前index
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
    // 当点击cell时获取当前图片和rect, 用于做转场动画
    weak var curImgView : UIImageView?
    private var rectInView : CGRect?
    
    
    // 头部headerview
    private lazy var headerView : XMHomeHeaderView = {
        let headerView : XMHomeHeaderView = XMHomeHeaderView.headerView()
        headerView.delegate = self
//        headerView.frame = CGRectMake(0, 20, SCREEN_WIDTH, headerView.height)
        return headerView
    }()
    
    // 中间collectionview
    private lazy var centerCollectView : UICollectionView = {
        let collectLayout : XMHomeCenterFlowLayout = XMHomeCenterFlowLayout()
        let collectView : UICollectionView = UICollectionView(frame: CGRectMake(0, 70, SCREEN_WIDTH, 420), collectionViewLayout: collectLayout)
        collectView.delegate = self
        collectView.dataSource = self
        collectView.showsHorizontalScrollIndicator = false
        collectView.pagingEnabled = true
        collectView.registerNib(UINib(nibName: "XMHomeCenterItemView", bundle: nil), forCellWithReuseIdentifier: "XMHomeCenterItemViewID")
        collectView.backgroundColor = UIColor.clearColor()
        collectView.tag = 100
        return collectView
    }()
    
    // 底部collectionView
    private lazy var bottomCollectView : XMHomeBottomCollectView = {
        let collectionLayout : XMHomeBottomFlowLayout = XMHomeBottomFlowLayout()
        let collectView : XMHomeBottomCollectView = XMHomeBottomCollectView(frame: CGRectMake(0, SCREEN_HEIGHT-60, SCREEN_WIDTH, 60), collectionViewLayout: collectionLayout)
        collectView.bottomViewDelegate = self
        collectView.delegate = self
        collectView.dataSource = self
        return collectView
    }()
    
    // MARK: - 屏幕适配
    private func setupLayout() {
        headerView.snp_makeConstraints { (make) -> Void in
            make.top.equalTo(self.view.snp_topMargin).offset(20)
            make.height.equalTo(SCREEN_HEIGHT*50/IPHONE5_HEIGHT)
            make.left.right.equalTo(self.view)
        }
        
        bottomCollectView.snp_makeConstraints { (make) -> Void in
            make.left.right.bottom.equalTo(self.view)
            make.height.equalTo(SCREEN_HEIGHT*60/IPHONE5_HEIGHT)
        }
        
        centerCollectView.snp_makeConstraints { (make) -> Void in
            make.left.right.equalTo(self.view)
            make.top.equalTo(headerView).offset(headerView.height)
            make.height.equalTo(SCREEN_HEIGHT*420/IPHONE5_HEIGHT)
        }
    }
}
