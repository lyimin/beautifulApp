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
                    
                    UIView.animate(withDuration: XMRefreshSlowAnimationDuration, animations: {
                        self.arrowImage.transform = CGAffineTransform(rotationAngle: CGFloat(M_PI));
                    })
                    self.scrollView.setContentOffset(CGPoint.zero, animated: true)
                    
                } else {
                    UIView.animate(withDuration: XMRefreshSlowAnimationDuration, animations: {
                        self.arrowImage.transform = CGAffineTransform(rotationAngle: CGFloat(M_PI));
                    })
                }
                self.scrollView.isScrollEnabled = true
                // 释放刷新状态
            case .RefreshStatePulling:
                UIView.animate(withDuration: XMRefreshSlowAnimationDuration, animations: {
                    self.arrowImage.transform = CGAffineTransform.identity
                })
                
                // 正在刷新状态
            case .RefreshStateRefreshing:
                if self.viewDirection == XMRefreashDirection.XMRefreshDirectionHorizontal {
                    self.scrollView.setContentOffset(CGPoint(x: -self.width, y: 0), animated: false)
                } else {
                    self.scrollView.setContentOffset(CGPoint(x: 0, y: -self.height), animated: false)
                }
                
                self.scrollView.isScrollEnabled = false
            default:
                break
                
            }
        }
        
    }
    override func layoutSubviews() {
        super.layoutSubviews()
        
        if self.viewDirection == XMRefreashDirection.XMRefreshDirectionHorizontal {
            self.frame = CGRect(x: -XMRefreshViewHeight, y: 0, width: XMRefreshViewHeight, height: UIConstant.SCREEN_HEIGHT)
        } else {
            self.frame = CGRect(x: 0, y: -XMRefreshViewHeight, width: UIConstant.SCREEN_WIDTH, height: XMRefreshViewHeight)
        }
    }
    // 创建view的静态方法
    class func headerView() -> XMRefreshHeaderView {
        return XMRefreshHeaderView(frame: CGRect(x: -XMRefreshViewHeight, y: 0, width: XMRefreshViewHeight, height: UIConstant.SCREEN_HEIGHT))
    }
    
    /**
    设置headerView的frame
    */
    override func willMove(toSuperview newSuperview: UIView!) {
        super.willMove(toSuperview: newSuperview)
        if self.viewDirection == XMRefreashDirection.XMRefreshDirectionHorizontal {
            self.x = -XMRefreshViewHeight
        } else {
            self.y = -XMRefreshViewHeight
        }
        
    }
    
    
    /**
    这个方法是这个Demo的核心。。监听scrollview的contentoffset属性。 属性变化就会调用。
    */
    
    override func observeValue(forKeyPath keyPath: String?, of object: Any?, change: [NSKeyValueChangeKey : Any]?, context: UnsafeMutableRawPointer?) {
        
        guard !self.isHidden else {
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
        if self.viewDirection == XMRefreashDirection.XMRefreshDirectionHorizontal {
            let currentOffsetY : CGFloat = self.scrollView.contentOffset.x
            let happenOffsetY : CGFloat = -self.scrollViewOriginalInset.left
            
            if (currentOffsetY >= happenOffsetY) {
                return
            }
            // 根据scrollview 滑动的位置设置当前状态
            if self.scrollView.isDragging {
                let normal2pullingOffsetY : CGFloat = happenOffsetY - XMRefreshViewHeight
                if self.State == XMRefreshState.RefreshStateNormal && currentOffsetY < normal2pullingOffsetY {
                    self.State = XMRefreshState.RefreshStatePulling
                } else if self.State == XMRefreshState.RefreshStatePulling && currentOffsetY >= normal2pullingOffsetY{
                    self.State = XMRefreshState.RefreshStateNormal
                }
                
            } else if self.State == XMRefreshState.RefreshStatePulling {
                self.State = XMRefreshState.RefreshStateRefreshing
            }
        } else {
            let currentOffsetY : CGFloat = self.scrollView.contentOffset.y
            let happenOffsetY : CGFloat = -self.scrollViewOriginalInset.top
            
            if (currentOffsetY >= happenOffsetY) {
                return
            }
            // 根据scrollview 滑动的位置设置当前状态
            if self.scrollView.isDragging {
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
        
    }
    
    deinit {
        self.endRefreshing()
    }
    
}
