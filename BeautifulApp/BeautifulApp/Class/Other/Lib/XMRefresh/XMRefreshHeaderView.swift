//
//  XMRefreshHeaderView.swift
//  XMPullToRefreshDemo
//
//  Created by 梁亦明 on 15/10/3.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMRefreshHeaderView: XMRefreshBase {
    
    override var State : XMRefreshState {
        willSet {
            oldState = State
        }
        
        didSet {
            switch self.State{
                // 普通状态
            case .RefreshStateNormal:
                if XMRefreshState.RefreshStateRefreshing == oldState {
                    
                    UIView.animateWithDuration(XMRefreshSlowAnimationDuration, animations: {
                        self.arrowImage.transform = CGAffineTransformMakeRotation(CGFloat(M_PI));
                    })
                    self.scrollView.setContentOffset(CGPointZero, animated: true)
                    
                } else {
                    UIView.animateWithDuration(XMRefreshSlowAnimationDuration, animations: {
                        self.arrowImage.transform = CGAffineTransformMakeRotation(CGFloat(M_PI));
                    })
                }
                self.scrollView.scrollEnabled = true
                // 释放刷新状态
            case .RefreshStatePulling:
                UIView.animateWithDuration(XMRefreshSlowAnimationDuration, animations: {
                    self.arrowImage.transform = CGAffineTransformIdentity
                })
                
                // 正在刷新状态
            case .RefreshStateRefreshing:
                self.scrollView.setContentOffset(CGPointMake(-self.width, 0), animated: true)
                self.scrollView.scrollEnabled = false
            default:
                break
                
            }
        }
        
    }
    // 创建view的静态方法
    class func headerView() -> XMRefreshHeaderView {
        return XMRefreshHeaderView(frame: CGRectMake(-XMRefreshViewHeight, 0, XMRefreshViewHeight, SCREEN_HEIGHT))
    }
    
    /**
    设置headerView的frame
    */
    override func willMoveToSuperview(newSuperview: UIView!) {
        super.willMoveToSuperview(newSuperview)
        
        self.x = -XMRefreshViewHeight
    }
    
    
    /**
    这个方法是这个Demo的核心。。监听scrollview的contentoffset属性。 属性变化就会调用。
    */
    override func observeValueForKeyPath(keyPath: String?, ofObject object: AnyObject?, change: [String : AnyObject]?, context: UnsafeMutablePointer<Void>) {
        guard !self.hidden else {
            return
        }
        
        // 如果当前状态不是刷新状态
        guard self.State != XMRefreshState.RefreshStateRefreshing else {
            return
        }
        
        // 监听到的是contentoffset
        guard XMRefreshContentOffset == keyPath else {
            return
        }
        
        // 拿到当前contentoffset的y值
        let currentOffsetY : CGFloat = self.scrollView.contentOffset.x
        let happenOffsetY : CGFloat = -self.scrollViewOriginalInset.left
        
        if (currentOffsetY >= happenOffsetY) {
            return
        }
        // 根据scrollview 滑动的位置设置当前状态
        if self.scrollView.dragging {
            let normal2pullingOffsetY : CGFloat = happenOffsetY - XMRefreshViewHeight
            if self.State == XMRefreshState.RefreshStateNormal && currentOffsetY < normal2pullingOffsetY {
                self.State = XMRefreshState.RefreshStatePulling
            } else if self.State == XMRefreshState.RefreshStatePulling && currentOffsetY >= normal2pullingOffsetY{
                self.State = XMRefreshState.RefreshStateNormal
            }
            
        } else if self.State == XMRefreshState.RefreshStatePulling {
            self.State = XMRefreshState.RefreshStateRefreshing
        }
    }
    
    deinit {
        self.endRefreshing()
    }
    
}
