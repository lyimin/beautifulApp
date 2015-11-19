//
//  UIScrollView+XM.swift
//  XMPullToRefreshDemo
//
//  Created by 梁亦明 on 15/10/3.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit


// MARK: - UIScorllview扩展方法
extension UIScrollView {
    
    /**
    下拉刷新
    */
    func headerViewPullToRefresh(callback:(() -> Void)?) {
        // 创建headerview
        let headerView : XMRefreshHeaderView = XMRefreshHeaderView.headerView()
        self.addSubview(headerView)
        headerView.beginRefreshingCallback = callback
        headerView.State = .RefreshStateNormal
    }
    
    /**
    开始下拉刷新
    */
    func headerViewBeginRefreshing() {
        for object : AnyObject in self.subviews {
            if object is XMRefreshHeaderView{
                object.beginRefreshing()
            }
        }
    }
    
    /**
    *  结束下拉刷新
    */
    func headerViewStopPullToRefresh() {
        for object : AnyObject in self.subviews{
            if object is XMRefreshHeaderView{
                object.endRefreshing()
            }
        }
    }
    
    /**
    上拉加载更多
    */
    func footerViewPullToRefresh(callback : (()->Void)?) {
        let footView : XMRefreshFooterView = XMRefreshFooterView.footerView()
        self.addSubview(footView)
        footView.beginRefreshingCallback = callback
        footView.State = .RefreshStateNormal
    }
    
    /**
    开始上拉加载更多
    */
    func footerBeginRefreshing() {
        for object : AnyObject in self.subviews {
            if object is XMRefreshFooterView {
                object.beginRefreshing()
            }
        }
    }
    
    
    /**
    结束上拉加载更多
    */
    func footerEndRefreshing()
    {
        for object : AnyObject in self.subviews{
            if object is XMRefreshFooterView{
                object.endRefreshing()
            }
        }
    }
}
