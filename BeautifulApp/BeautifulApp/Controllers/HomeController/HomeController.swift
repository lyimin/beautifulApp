//
//  HomeController.swift
//  beautifulApp-Swift3
//
//  Created by 梁亦明 on 16/10/18.
//  Copyright © 2016年 xiaoming.com. All rights reserved.
//

import UIKit

protocol HomeControllerDelegate {
    /// 点击菜单按钮
    func menuBtnDidClick()
    
    /// index改变时，让main去改变背景颜色
    func indexDidChange(withBackgroundColor: String)
}

class HomeController: UIViewController, ControllerReusable {

    //MARK: --------------------------- Life Cycle --------------------------
    convenience init(apiTarget: APIConstant) {
        self.init()
        self.apiTarget = apiTarget
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = UIConstant.COLOR_APPNORMAL
        
        view.addSubview(headerView)
        view.addSubview(collectionView)
        view.addSubview(bottomCollectionView)
        
        headerView.snp.makeConstraints { (make) in
            make.left.right.equalTo(self.view)
            make.top.equalTo(self.view).offset(UIConstant.MARGIN_20)
            make.height.equalTo(UIConstant.SCREEN_HEIGHT*50/UIConstant.IPHONE5_HEIGHT)
        }
        // 首次加载时显示加载框
        showProgress()
        // 获取默认的10条数据
        getData(target: .daily(page))
        
        // 当滑动结束时就会调用这个block
        bottomCollectionView.touchIndexDidChangeBlock = ({ [unowned self](indexPath) in
            // 滚动中间页面
            self.collectionView.scrollToItem(at: indexPath, at: .centeredHorizontally, animated: false)
            
            self.currentIndex = indexPath
            // 执行底部横向动画
            let cell = self.bottomCollectionView.cellForItem(at: indexPath)
            // 如果当前不够8个item就不让他滚动
            self.bottomHorizontalAnimation(currentCell: cell!, indexPath: indexPath)
            self.lastIndex = indexPath
        })
        
        
        // 下拉刷新时调用
        self.collectionView.headerViewPullToRefresh(direction: .XMRefreshDirectionHorizontal, callback: { [unowned self]() -> Void in
            self.page = 1
            
            self.getData(target: .daily(self.page))
        })
        
        // 上拉加载更多
        self.collectionView.footerViewPullToRefresh(direction: .XMRefreshDirectionHorizontal, callback: {
            [unowned self]() -> Void in
            
            self.page+=1
            self.getData(target: .daily(self.page))
        })
        
        // 网络加载错误按钮点击事件
//        errorBtn.addTarget(self, action: #selector(errorBtnDidClick), for: .touchUpInside)
    }
   
    override var preferredStatusBarStyle: UIStatusBarStyle {
        return .lightContent
    }
    
    //MARK: --------------------------- Getter and Setter --------------------------
//    var errorBtn: UIButton!
    
    var progressView: UIImageView!
    /// 代理
    var delegate: HomeControllerDelegate?
    /// 列表的数据源
    fileprivate var homeModelArray = Array<HomeModel>()
    /// 页数
    fileprivate var page : Int = 1
    /// 上一个index
    fileprivate var lastIndex: IndexPath?
    /// 当前index
    fileprivate var currentIndex: IndexPath! = IndexPath(row: 0, section: 0) {
        didSet {
            guard self.homeModelArray.count > 0 else {
                return
            }
            // 获取模型
            let model: HomeModel = homeModelArray[currentIndex.row]
            // 设置header模型
            self.headerView.homeModel = model
            // 设置背景的动画
            UIView.animate(withDuration: 0.5, animations: { () -> Void in
                self.view.backgroundColor = UIColor.hexString(hexString:  model.recommanded_background_color)
            })
            self.delegate?.indexDidChange(withBackgroundColor: model.recommanded_background_color)
        }
    }
    /// 顶部view
    fileprivate lazy var headerView: HomeHeaderView = {
        var headerView = HomeHeaderView()
        headerView.delegate = self
        return headerView
    }()
    
    /// 中间内容块
    fileprivate lazy var collectionView: UICollectionView = {
        // 初始化布局
        var layout = UICollectionViewFlowLayout()
        layout.itemSize = CGSize(width: UIConstant.SCREEN_WIDTH-2*UIConstant.MARGIN_5, height: UIConstant.SCREEN_HEIGHT*420/UIConstant.IPHONE5_HEIGHT)
        layout.scrollDirection = .horizontal
        layout.sectionInset = UIEdgeInsets(top: 0, left: 5, bottom: 0, right: 5);
        
        // 初始化collectionView
        var collectionView = UICollectionView(frame: CGRect(x: 0, y: UIConstant.MARGIN_20+UIConstant.SCREEN_HEIGHT*50/UIConstant.IPHONE5_HEIGHT, width: UIConstant.SCREEN_WIDTH, height: UIConstant.SCREEN_HEIGHT*420/UIConstant.IPHONE5_HEIGHT), collectionViewLayout: layout)
        collectionView.delegate = self
        collectionView.dataSource = self
        collectionView.showsHorizontalScrollIndicator = false
        collectionView.isPagingEnabled = true
        collectionView.registerClass(HomeCenterItemCell.self)
        collectionView.backgroundColor = UIColor.clear
        collectionView.tag = 100
        return collectionView
    }()
    
    /// 底部音弦collectionview
    fileprivate lazy var bottomCollectionView: HomeBottomCollectionView = {
        var bottomCollectionView = HomeBottomCollectionView(frame: CGRect(x: 0, y: UIConstant.SCREEN_HEIGHT-60, width: UIConstant.SCREEN_WIDTH, height: 60), collectionViewLayout: HomeBottomFlowLayout())
        bottomCollectionView.delegate = self
        bottomCollectionView.dataSource = self

        return bottomCollectionView
    }()
    
    // 类型
    var apiTarget: APIConstant! = .daily(1) {
        didSet {
            self.page = 1
            self.collectionView.isHidden = true
            self.bottomCollectionView.isHidden = true
            self.showProgress()
            getData(target: apiTarget)
        }
    }
    // 当点击cell时获取当前图片和rect, 用于做转场动画
    weak var curImgView : UIImageView?
    fileprivate var rectInView : CGRect?
}

//MARK: --------------------------- UICollectionViewDelegate, UICollectionViewDataSource --------------------------

extension HomeController: UICollectionViewDelegate, UICollectionViewDataSource {
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return homeModelArray.count
    }
    func collectionView(_ collectionView: UICollectionView, willDisplay cell: UICollectionViewCell, forItemAt indexPath: IndexPath) {
        let model = homeModelArray[indexPath.row]
        if collectionView.tag == 100 {
            let cell = cell as! HomeCenterItemCell
            cell.model = model
        } else {
            let cell = cell as! HomeBottomItemCell
            cell.iconURL = model.icon_image
        }
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        if collectionView.tag == 100 {
            let cell = collectionView.dequeueReusableCell(indexPath: indexPath) as HomeCenterItemCell
            return cell
        } else {
            let cell = collectionView.dequeueReusableCell(indexPath: indexPath) as HomeBottomItemCell
            cell.y = 50
            return cell
        }
    }
    
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
//        // 获取cell中的图片 和 rect 用于做转场动画
//        let cell = collectionView.cellForItem(at: indexPath) as! HomeCenterItemCell
//        self.curImgView = cell.coverImageView
//        // 计算collection点击的item在屏幕中的位置
//        let rectInCollectionView = (collectionView.layoutAttributesForItem(at: indexPath)?.frame)!
//        let rectInSuperView = collectionView.convert(rectInCollectionView, to: collectionView.superview)
//        self.rectInView = CGRect(x: rectInSuperView.origin.x+cell.coverImageView.x, y: rectInSuperView.origin.y+cell.coverImageView.y, width: rectInSuperView.width, height: cell.coverImageView.height)
        // 获取模型
        let model = homeModelArray[indexPath.row]
        let detailController = HomeDetailController(model: model)
        self.navigationController?.pushViewController(detailController, animated: true)
    }

}

//MARK: --------------------------- ScrollViewDelegate --------------------------
extension HomeController {
    func scrollViewDidScroll(_ scrollView: UIScrollView) {
        
        if scrollView.tag == 100 {
            let index = Int(round(scrollView.contentOffset.x/scrollView.width))
            guard self.currentIndex.row != index else {
                return
            }
            self.currentIndex = index > homeModelArray.count-1 ?IndexPath(row: self.homeModelArray.count-1, section: 0) :IndexPath(row: index, section: 0)
        }
    }
    
    func scrollViewDidEndDecelerating(_ scrollView: UIScrollView) {
        if scrollView.tag == 100 {
            // 设置底部动画
            self.bottomAnimation(indexPath: currentIndex)
        }
    }
}
//MARK: --------------------------- headerViewDelegate --------------------------
extension HomeController: HeaderViewDelegate {
    func headerViewMoveToFirstBtnDidClick() {
        collectionView.setContentOffset(CGPoint.zero, animated: false)
        bottomCollectionView.setContentOffset(CGPoint.zero, animated: false)
        currentIndex = IndexPath(row: 0, section: 0)
        scrollViewDidEndDecelerating(collectionView)
    }
    
    func headerViewMenuBtnDidClick() {
        delegate?.menuBtnDidClick()
    }
}
//MARK: --------------------------- Event And Action --------------------------
extension HomeController {
    func errorBtnDidClick() {
        
    }
}

//MARK: --------------------------- Private Methods --------------------------

extension HomeController {
    
    /// 获取网络默认的10条数据
    fileprivate func getData(target: APIConstant) {
        NiceServices.shareInstance.getHomeData(target: target) { [unowned self](modelArray) in
            switch target {
            case .article:
                self.collectionView.setHeaderHidden(hidden: true)
                self.collectionView.setFooterHidden(hidden: true)
            default:
                self.collectionView.setHeaderHidden(hidden: false)
                self.collectionView.setFooterHidden(hidden: false)
            }
            if self.page == 1 {
                self.homeModelArray.removeAll()
                self.hiddenProgress()
            }
            for model in modelArray {
                self.homeModelArray.append(model)
            }
            
            // 刷新数据
            self.collectionView.reloadData()
            self.bottomCollectionView.reloadData()
            
           
            if self.page == 1 {
                self.lastIndex = nil
                self.collectionView.isHidden = false
                self.bottomCollectionView.isHidden = false
                self.collectionView.setContentOffset(CGPoint.zero, animated: false)
                self.bottomCollectionView.setContentOffset(CGPoint.zero, animated: false)
                // 下拉刷新
                self.currentIndex = IndexPath(row: 0, section: 0)
                
                // 执行底部第一个item动画
                self.bottomAnimation(indexPath: IndexPath(row: 0, section: 0))
            } else {
                // 上拉加载更多
                self.currentIndex = IndexPath(row: self.homeModelArray.count-10, section: 0)
                self.bottomAnimation(indexPath: self.currentIndex)

            }
            // 停止刷新
            self.collectionView.headerViewStopPullToRefresh()
            self.collectionView.footerEndRefreshing()
        }
    }
    
    /// 底部动画
    fileprivate func bottomAnimation(indexPath: IndexPath) {
        guard lastIndex?.row != indexPath.row else {
            return
        }
        
        // 获取要执行动画的cell
        var currentCell = bottomCollectionView.cellForItem(at: indexPath)
        
        if currentCell == nil {
            self.bottomCollectionView.layoutIfNeeded()
            currentCell = self.bottomCollectionView.cellForItem(at: indexPath)
        }
        
        guard currentCell != nil else {
            return
        }
        
        // 执行横向动画
        bottomHorizontalAnimation(currentCell: currentCell!, indexPath: indexPath)
        
        // 底部纵向动画
        bottomVerticalAnimation(currentCell: currentCell!)
        
        lastIndex = indexPath
    }
    
    
    /// 横向动画
    fileprivate func bottomHorizontalAnimation(currentCell cell: UICollectionViewCell, indexPath: IndexPath) {
        guard homeModelArray.count > 8 && lastIndex != nil else {
            return
        }
        
//
        if cell.x > UIConstant.SCREEN_WIDTH*0.5{
            // 判断下一个还是上一个
            if lastIndex!.row < indexPath.row {
                // 下一个
                let newX = bottomCollectionView.contentOffset.x + cell.width + 2
                bottomCollectionView.setContentOffset(CGPoint(x: newX, y: 0), animated: true)
            } else  {
                // 上一个
                if bottomCollectionView.contentOffset.x > cell.width {
                    let newX = bottomCollectionView.contentOffset.x - cell.width - 2
                    bottomCollectionView.setContentOffset(CGPoint(x: newX, y: 0), animated: true)
                } else {
                    bottomCollectionView.setContentOffset(CGPoint.zero, animated: true)
                }
            }
        } else {
            bottomCollectionView.setContentOffset(CGPoint.zero, animated: true)
        }
    }
    
    // 纵向动画
    fileprivate func bottomVerticalAnimation(currentCell : UICollectionViewCell) {
        
        UIView.animate(withDuration: 0.35, delay: 0, usingSpringWithDamping: 0.3, initialSpringVelocity: 5, options: .allowAnimatedContent, animations: {
            currentCell.y = 15
        }, completion: nil)
        
        if let _ = lastIndex {
            let lastBottomView : UICollectionViewCell? = bottomCollectionView.cellForItem(at: lastIndex!)
            if let view = lastBottomView {

                UIView.animate(withDuration: 0.35, delay: 0, usingSpringWithDamping: 0.3, initialSpringVelocity: 5, options: .allowAnimatedContent, animations: {
                    view.y = 50
                }, completion: nil)
            }
        }
    }
}
