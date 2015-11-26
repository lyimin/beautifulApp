//
//  XMFindAppController.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/24.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMFindAppController: UIViewController, UITableViewDelegate, UITableViewDataSource, UIScrollViewDelegate, XMFindAppHeaderViewDelegate {

    
    // viewModel
    private var viewModel : XMFindAppViewModel?
    // hotPage
    private var hotPage : Int = 1
    override func viewDidLoad() {
        super.viewDidLoad()
        self.view.backgroundColor = UI_COLOR_APPNORMAL
        
        self.view.addSubview(headerView)
        headerView.delegate = self
        
        // setupView
        self.setupCenterView()
    }
    
    private func setupCenterView() {
        // 添加scrollview
        centerScroll.frame = CGRect(x: 0, y: CGRectGetMaxY(headerView.frame), width: SCREEN_WIDTH, height: SCREEN_HEIGHT - CGRectGetMaxY(headerView.frame))
        centerScroll.delegate = self
        self.view.addSubview(centerScroll)
        
        // 添加最热tableview
        hotTableView.delegate = self
        hotTableView.dataSource = self
        hotTableView.frame = centerScroll.bounds
        centerScroll.addSubview(hotTableView)
        
        // 最新
        lastestTableView.delegate = self
        lastestTableView.dataSource = self
        lastestTableView.frame = CGRect(x: SCREEN_WIDTH, y: 0, width: SCREEN_WIDTH, height: centerScroll.height)
        centerScroll.addSubview(lastestTableView)
        
        viewModel = XMFindAppViewModel(hotShareView: hotTableView, lastestView: lastestTableView)
        // 添加下拉刷新和上拉加载更多
        // 下拉刷新
        hotTableView.headerViewPullToRefresh(.XMRefreshDirectionVertical, callback: { [unowned self]() -> Void in
            self.hotPage = 1
            self.viewModel!.findAppType = .XMFindAppViewTypeHotShare
            self.viewModel!.getData(self.hotPage)
        })
        
        lastestTableView.headerViewPullToRefresh(.XMRefreshDirectionVertical,callback: { [unowned self]() -> Void in
            self.viewModel!.findAppType = .XMFindAppViewTypeLastestShare
            self.viewModel!.getData(-1)
        })
        
        // 上拉加载更多
        hotTableView.footerViewPullToRefresh (.XMRefreshDirectionVertical, callback:{ [unowned self]() -> Void in
            self.hotPage += 1
            self.viewModel!.findAppType = .XMFindAppViewTypeHotShare
            self.viewModel!.getData(self.hotPage)
        })
        
        lastestTableView.footerViewPullToRefresh (.XMRefreshDirectionVertical, callback:{ [unowned self]() -> Void in
            self.viewModel!.findAppType = .XMFindAppViewTypeLastestShare
            self.viewModel!.getData(1)
        })
        self.hotTableView.headerViewBeginRefreshing()
    }

    //MARK: TableView Delegate 
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if self.viewModel != nil {
            if tableView.tag == 202 {
                return (self.viewModel?.hotDataSource.count)!
            } else {
                return (self.viewModel?.lastDataSource.count)!
            }
            
        }
        return 0
    }
    
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        let cell : XMFindAppCell = XMFindAppCell.cellWithTableView(tableView)
        if tableView.tag == 202 {
            cell.model = self.viewModel?.hotDataSource[indexPath.row]
        } else {
            cell.model = self.viewModel?.lastDataSource[indexPath.row]
        }
        return cell
    }
    //MARK: UISrollView Delegate 
    func scrollViewDidScroll(scrollView: UIScrollView) {
        
    }
    
    //MARK: custer Delegate 
    
    // 最热
    func findAppHeaderViewHotBtnDidClick(headerView: XMFindAppHeaderView, hotBtn: UIButton) {
        self.centerScroll.setContentOffset(CGPointMake(0, 0), animated: true)
        if self.viewModel != nil {
            if self.viewModel?.hotDataSource.count == 0 {
                self.hotTableView.headerViewBeginRefreshing()
            }
        }
        
    }
    // 最新
    func findAppHeaderViewLastestBtnDidClick(headerView: XMFindAppHeaderView, lastestBtn: UIButton) {
        self.centerScroll.setContentOffset(CGPointMake(SCREEN_WIDTH, 0), animated: true)
        if self.viewModel != nil {
            if self.viewModel?.lastDataSource.count == 0 {
                self.lastestTableView.headerViewBeginRefreshing()
            }
        }
    }
    // 添加
    func findAppHeaderViewAddBtnDidClick(headerView: XMFindAppHeaderView, addBtn: UIButton) {
        self.navigationController?.pushViewController(XMHomeViewController(), animated: true)
    }
    
    // 菜单
    func findAppHeaderViewMenuBtnDidClick(headerView: XMFindAppHeaderView, menuBtn: UIButton) {
        NSNotificationCenter.defaultCenter().postNotificationName(NOTIFY_SHOWMENU, object: nil)
    }
    
    //MARK: - getter or setter
    // 头部headerview
    private var headerView : XMFindAppHeaderView = {
        let headerView : XMFindAppHeaderView = XMFindAppHeaderView.headerView()
        headerView.frame = CGRectMake(0, 20, SCREEN_WIDTH, headerView.height)
        return headerView
    }()
    
    private var centerScroll : UIScrollView = {
        let centerScroll = UIScrollView()
        centerScroll.scrollEnabled = false
        centerScroll.backgroundColor = UIColor.clearColor()
        centerScroll.tag = 201
        centerScroll.pagingEnabled = true
        centerScroll.bounces = false
        centerScroll.showsHorizontalScrollIndicator = false
        centerScroll.contentSize = CGSize(width: 2 * SCREEN_WIDTH, height: 0)
        return centerScroll
    }()
    
    private var hotTableView : UITableView = {
        let hotTableView = UITableView()
        hotTableView.backgroundColor = UIColor.clearColor()
        hotTableView.rowHeight = 310
        hotTableView.tableFooterView = UIView()
        hotTableView.separatorStyle = .None
        hotTableView.tag = 202
        return hotTableView
    }()
    
    private var lastestTableView : UITableView = {
        let lastestTableView = UITableView()
        lastestTableView.backgroundColor = UIColor.clearColor()
        lastestTableView.rowHeight = 310
        lastestTableView.tableFooterView = UIView()
        lastestTableView.separatorStyle = .None
        lastestTableView.tag = 203
        return lastestTableView
    }()
}
