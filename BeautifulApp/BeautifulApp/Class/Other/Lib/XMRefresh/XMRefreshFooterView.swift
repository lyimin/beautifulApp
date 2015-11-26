//
//  XMRefreshFooterView.swift
//  XMPullToRefreshDemo
//
//  Created by 梁亦明 on 15/10/3.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMRefreshFooterView: XMRefreshBase {
    /// 保存cell的总个数
    private var lastRefreshCount:Int = 0
    
    /// 状态改变时就调用
    override var State : XMRefreshState {
        willSet {
            oldState = self.State
        }
        
        didSet {
            switch self.State {
                // 普通状态
            case .RefreshStateNormal:
//                if (XMRefreshState.RefreshStateRefreshing == oldState) {
//                    
//                    UIView.animateWithDuration(XMRefreshSlowAnimationDuration, animations: {
//                        self.arrowImage.transform = CGAffineTransformMakeRotation(CGFloat(M_PI))
//                        self.scrollView.setContentOffset(CGPointMake(self.scrollView.contentSize.width-SCREEN_WIDTH, 0), animated: true)
//                    })
//                } else {
//                    UIView.animateWithDuration(XMRefreshSlowAnimationDuration, animations: {
//                        self.arrowImage.transform = CGAffineTransformMakeRotation(CGFloat(M_PI));
//                    })
//                }
                
                
                if (XMRefreshState.RefreshStateRefreshing == oldState) {
                    self.arrowImage.transform = CGAffineTransformMakeRotation(CGFloat(M_PI))
                    UIView.animateWithDuration(XMRefreshSlowAnimationDuration, animations: {
                        self.scrollView.contentInset.bottom = self.scrollViewOriginalInset.bottom
                    })
                } else {
                    UIView.animateWithDuration(XMRefreshSlowAnimationDuration, animations: {
                        self.arrowImage.transform = CGAffineTransformMakeRotation(CGFloat(M_PI));
                    })
                }
                
                let deltaH : CGFloat = self.heightForContentBreakView()
                let currentCount : Int = self.totalDataCountInScrollView()
                
                if (.RefreshStateRefreshing == oldState && deltaH > 0  && currentCount != self.lastRefreshCount) {
                    var offset:CGPoint = self.scrollView.contentOffset;
                    offset.x = self.scrollView.contentOffset.x - self.width + SCREEN_WIDTH
                    self.scrollView.setContentOffset(offset, animated: true)
                }
                // 释放加载更多
            case .RefreshStatePulling:
                UIView.animateWithDuration(XMRefreshSlowAnimationDuration, animations: {
                    self.arrowImage.transform = CGAffineTransformIdentity
                })
                
                // 正在加载更多
            case .RefreshStateRefreshing:
                self.scrollView.setContentOffset(CGPointMake(self.scrollView.contentSize.width-SCREEN_WIDTH+self.width, 0), animated: true)
                
            default:
                break;
            }
        }
    }
    
    
    /**
    创建脚部静态方法
    */
    class func footerView() -> XMRefreshFooterView {
        return XMRefreshFooterView(frame: CGRectMake(0, 0, XMRefreshViewHeight, SCREEN_HEIGHT))
    }
    
    
    override func willMoveToSuperview(newSuperview: UIView!) {
        super.willMoveToSuperview(newSuperview)
        if (self.superview != nil){
            self.superview!.removeObserver(self, forKeyPath: XMRefreshContentSize as String,context:nil)
        }
        if (newSuperview != nil)  {
            // 监听contentsize
            newSuperview.addObserver(self, forKeyPath: XMRefreshContentSize, options: NSKeyValueObservingOptions.New, context: nil)
            // 重新调整frame
            resetFrameWithContentSize()
        }
    }
    
    override func observeValueForKeyPath(keyPath: String?, ofObject object: AnyObject?, change: [String : AnyObject]?, context: UnsafeMutablePointer<Void>) {
        guard !self.hidden else {
            return
        }
        // 这里分两种情况 1.contentSize 2.contentOffset
        
        if XMRefreshContentSize == keyPath {
            self.resetFrameWithContentSize()
        } else if XMRefreshContentOffset == keyPath {
            // 如果不是刷新状态
            guard self.State != XMRefreshState.RefreshStateRefreshing else {
                return
            }
            
            let currentOffsetX : CGFloat  = self.scrollView.contentOffset.x
            let happenOffsetX : CGFloat = self.happenOffsetX()
            
            if currentOffsetX <= happenOffsetX {
                return
            }
            
            if self.scrollView.dragging {
                let normal2pullingOffsetY =  happenOffsetX + self.width
                if self.State == .RefreshStateNormal && currentOffsetX > normal2pullingOffsetY {
                    self.State = .RefreshStatePulling;
                } else if (self.State == .RefreshStatePulling && currentOffsetX <= normal2pullingOffsetY) {
                    self.State = .RefreshStateNormal;
                }
            } else if (self.State == .RefreshStatePulling) {
                self.State = .RefreshStateRefreshing
            }
        }
    }
    
    
    /**
    重新设置frame
    */
    private func resetFrameWithContentSize() {
        let contentHeight:CGFloat = self.scrollView.contentSize.width
        let scrollHeight:CGFloat = self.scrollView.width  - self.scrollViewOriginalInset.left - self.scrollViewOriginalInset.right
        
        var rect:CGRect = self.frame;
        rect.origin.x =  contentHeight > scrollHeight ? contentHeight : scrollHeight
        self.frame = rect;
    }
    
    private func heightForContentBreakView() -> CGFloat {
        let h:CGFloat  = self.scrollView.width - self.scrollViewOriginalInset.right - self.scrollViewOriginalInset.left;
        return self.scrollView.contentSize.width - h;
    }
    
    
    private func happenOffsetX() -> CGFloat {
        let deltaH:CGFloat = self.heightForContentBreakView()
        
        if deltaH > 0 {
            return   deltaH - self.scrollViewOriginalInset.left;
        } else {
            return  -self.scrollViewOriginalInset.left;
        }
    }
    
    /**
    获取cell的总个数
    */
    private  func  totalDataCountInScrollView() -> Int {
        var totalCount:Int = 0
        if self.scrollView is UITableView {
            let tableView:UITableView = self.scrollView as! UITableView
            
            for (var i:Int = 0 ; i <  tableView.numberOfSections ; i++){
                totalCount = totalCount + tableView.numberOfRowsInSection(i)
                
            }
        } else if self.scrollView is UICollectionView{
            let collectionView:UICollectionView = self.scrollView as! UICollectionView
            for (var i:Int = 0 ; i <  collectionView.numberOfSections() ; i++){
                totalCount = totalCount + collectionView.numberOfItemsInSection(i)
                
            }
        }
        return totalCount
    }
    
    deinit {
        self.endRefreshing()
    }
}
