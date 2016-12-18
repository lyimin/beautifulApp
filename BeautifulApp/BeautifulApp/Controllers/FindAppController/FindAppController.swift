//
//  FindAppController.swift
//  beautifulApp-Swift3
//
//  Created by 梁亦明 on 2016/12/17.
//  Copyright © 2016年 xiaoming.com. All rights reserved.
//

import Foundation
protocol FindAppControllerDelegate {
    /// 点击菜单按钮
    func menuBtnDidClick()
}



class FindAppController: UIViewController, ControllerReusable {
    /// 加载进度条
    internal var progressView: UIImageView!

    enum RequestType {
        case hot
        case lastest
    }
    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = UIConstant.COLOR_APPNORMAL
        // 添加headerView
        view.addSubview(headerView)
        view.addSubview(centerScroll)
        centerScroll.addSubview(hotTableView)
        centerScroll.addSubview(lastestTableView)
        
        // 下拉刷新
        hotTableView.headerViewPullToRefresh(direction: .XMRefreshDirectionVertical, callback: { [unowned self]() -> Void in
            self.hotPage = 1
            self.getData(target: APIConstant.popular(self.hotPage))
        })
        
        lastestTableView.headerViewPullToRefresh(direction: .XMRefreshDirectionVertical,callback: { [unowned self]() -> Void in
            self.lastestPage = -1
            self.getData(target: APIConstant.latest(self.lastestPage), requestType: .lastest)
        })
        
        // 上拉加载更多
        hotTableView.footerViewPullToRefresh (direction: .XMRefreshDirectionVertical, callback:{ [unowned self]() -> Void in
            self.hotPage += 1
            self.getData(target: APIConstant.popular(self.hotPage))
        })
        
        lastestTableView.footerViewPullToRefresh (direction: .XMRefreshDirectionVertical, callback:{ [unowned self]() -> Void in
            
            self.getData(target: APIConstant.latest((self.lastestDataSource.last?.pos)!), requestType: .lastest);
        })
        showProgress()
        getData(target: APIConstant.popular(self.hotPage))
    }
    
    
    //MARK: --------------------------- Getter and Setter --------------------------
    var delegate: FindAppControllerDelegate!
    // 数据
    fileprivate var hotPage: Int = 1
    fileprivate var lastestPage: Int = -1
    fileprivate var hotDataSource = Array<FindAppModel>()
    fileprivate var lastestDataSource = Array<FindAppModel>()
    fileprivate var type: RequestType! = .hot
    // 头部headerview
    fileprivate lazy var headerView: FindAppHeaderView = {
        let headerView = FindAppHeaderView()
        headerView.frame = CGRect(x: 0, y: UIConstant.MARGIN_20, width: UIConstant.SCREEN_WIDTH, height: 50)
        headerView.delegate = self
        return headerView
    }()
    
    // 横向scroller
    fileprivate lazy var centerScroll : UIScrollView = {
        let centerScroll = UIScrollView()
        centerScroll.frame = CGRect(x: 0, y: 70, width: UIConstant.SCREEN_WIDTH, height: UIConstant.SCREEN_HEIGHT - 70)
        centerScroll.isScrollEnabled = false
        centerScroll.backgroundColor = UIColor.clear
        centerScroll.tag = 201
        centerScroll.isPagingEnabled = true
        centerScroll.bounces = false
        centerScroll.showsHorizontalScrollIndicator = false
        centerScroll.contentSize = CGSize(width: 2 * UIConstant.SCREEN_WIDTH, height: 0)
        centerScroll.delegate = self
        return centerScroll
    }()
    
    // 最热tableview
    fileprivate lazy var hotTableView : UITableView = {
        let hotTableView = UITableView()
        hotTableView.frame = self.centerScroll.bounds
        hotTableView.delegate = self
        hotTableView.dataSource = self
        hotTableView.backgroundColor = UIColor.clear
        hotTableView.rowHeight = 320
        hotTableView.tableFooterView = UIView()
        hotTableView.separatorStyle = .none
        hotTableView.tag = 202
        return hotTableView
    }()
    
    // 最新tableview
    fileprivate lazy var lastestTableView : UITableView = {
        let lastestTableView = UITableView()
        lastestTableView.frame = CGRect(x: UIConstant.SCREEN_WIDTH, y: 0, width: UIConstant.SCREEN_WIDTH, height: self.centerScroll.height)
        lastestTableView.delegate = self
        lastestTableView.dataSource = self
        lastestTableView.backgroundColor = UIColor.clear
        lastestTableView.rowHeight = 320
        lastestTableView.tableFooterView = UIView()
        lastestTableView.separatorStyle = .none
        lastestTableView.tag = 203
        return lastestTableView
    }()
    
}

//MARK: --------------------------- UITableViewDelegate, UITableViewDataSource --------------------------
extension FindAppController: UITableViewDelegate, UITableViewDataSource {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if tableView.tag == 202 {
            return hotDataSource.count
        } else {
            return lastestDataSource.count
        }
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = FindAppCell.cellWithTableView(tableView: tableView)
        if tableView.tag == 202 {
            cell.model = hotDataSource[indexPath.row]
        } else {
            cell.model = lastestDataSource[indexPath.row]
        }
        return cell
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        var model: FindAppModel!
        if tableView.tag == 202 {
            model = hotDataSource[indexPath.row];
        } else {
            model = lastestDataSource[indexPath.row];
        }
        self.navigationController?.pushViewController(FindAppDetailController(model: model), animated: true)
    }
}

//MARK: --------------------------- FindAppHeaderViewDelegate --------------------------
extension FindAppController: FindAppHeaderViewDelegate {
    func menuBtnDidClick() {
        self.delegate.menuBtnDidClick()
    }
    
    func hotBtnDidClick() {
        self.centerScroll.setContentOffset(CGPoint.zero, animated: true)
        if self.hotDataSource.count == 0 {
            showProgress()
            getData(target: APIConstant.popular(self.hotPage))
        }
    }
    
    func lastestBtnDidClick() {
        self.centerScroll.setContentOffset(CGPoint(x: UIConstant.SCREEN_WIDTH, y: 0), animated: true)
        if self.lastestDataSource.count == 0 {
            showProgress()
            getData(target: APIConstant.latest(self.lastestPage), requestType: .lastest)
        }
    }
}

//MARK: --------------------------- Private Methods --------------------------
extension FindAppController {
    fileprivate func setupLayout() {
        headerView.snp.makeConstraints { (make) in
            make.left.right.equalTo(self.view)
            make.height.equalTo(50)
            make.top.equalTo(self.view).offset(UIConstant.MARGIN_20)
        }
        
        centerScroll.snp.makeConstraints { (make) in
            make.left.right.bottom.equalTo(self.view)
            make.top.equalTo(headerView.snp.bottom)
        }
        
        hotTableView.snp.makeConstraints { (make) in
            make.left.right.top.bottom.equalTo(centerScroll)
        }
        
        lastestTableView.snp.makeConstraints { (make) in
            make.left.equalTo(hotTableView.snp.right)
            make.top.bottom.equalTo(hotTableView)
            make.width.equalTo(hotTableView)
        }
    }
    
    fileprivate func getData(target: APIConstant, requestType: RequestType = .hot) {
        NiceServices.shareInstance.getFindAppData(target: target, successHandle: { [unowned self] modelArray in
            if requestType == .hot {
                // 请求的是热门
                if self.hotPage == 1 {
                    self.hotDataSource.removeAll()
                    self.hiddenProgress()
                }
                
                for model in modelArray {
                    self.hotDataSource.append(model)
                }
                self.hotTableView.footerEndRefreshing()
                self.hotTableView.headerViewStopPullToRefresh()
                self.hotTableView.reloadData()
            } else {
                // 请求的是最新
                if self.lastestPage == -1 {
                    self.lastestDataSource.removeAll()
                    self.hiddenProgress()
                }
                
                for model in modelArray {
                    self.lastestDataSource.append(model)
                }
                self.lastestPage = (self.lastestDataSource.last?.pos)!
                self.lastestTableView.headerViewStopPullToRefresh()
                self.lastestTableView.footerEndRefreshing()
                self.lastestTableView.reloadData()
            }
        })
    }
}


