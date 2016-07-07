//
//  XMHomeAnimationUtil.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/12/25.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMHomeAnimationPushUtil: NSObject, UIViewControllerAnimatedTransitioning {
    private var imageViewRect : CGRect!
    
    convenience init(imageViewRect : CGRect) {
        self.init()
        self.imageViewRect = imageViewRect
    }
    
    /**
    转场动画时间
    - returns: 
    */
    func transitionDuration(transitionContext: UIViewControllerContextTransitioning?) -> NSTimeInterval {
        return 1
    }
    
    /**
     转场动画操作
     
     - parameter transitionContext: <#transitionContext description#>
     */
    func animateTransition(transitionContext: UIViewControllerContextTransitioning) {
        let container = transitionContext.containerView()
        //1.获取动画的源控制器和目标控制器
        let fromVC : XMHomeViewController = transitionContext.viewControllerForKey(UITransitionContextFromViewControllerKey) as! XMHomeViewController
        let toVC : XMHomeDetailController = transitionContext.viewControllerForKey(UITransitionContextToViewControllerKey) as! XMHomeDetailController
        
        //2.创建一个 Cell 中 imageView 的截图，并把 imageView 隐藏，造成使用户以为移动的就是 imageView 的假象
        let snapshotView = fromVC.curImgView!.snapshotViewAfterScreenUpdates(false)
        snapshotView.frame = imageViewRect
        fromVC.curImgView!.hidden = true
        toVC.topImageView.hidden = true
        
        //3.设置目标控制器的位置，并把透明度设为0，在后面的动画中慢慢显示出来变为1
        toVC.view.frame = transitionContext.finalFrameForViewController(toVC)
        toVC.view.alpha = 0
        
        //4.都添加到 container 中。注意顺序不能错了
        container!.addSubview(toVC.view)
        container!.addSubview(snapshotView)
        
        let rect = toVC.view.convertRect(toVC.topImageView.frame, toView: toVC.topImageView.superview)
        //5.执行动画
        toVC.topImageView.layoutIfNeeded()
        UIView.animateWithDuration(transitionDuration(transitionContext), delay: 0, options: UIViewAnimationOptions.CurveEaseInOut, animations: { () -> Void in
            snapshotView.frame = CGRect(x: 0, y: 20, width: rect.width, height: 170)
            toVC.view.alpha = 1
            }) { (finish: Bool) -> Void in
                fromVC.curImgView!.hidden = false
                toVC.topImageView.hidden = false;
                snapshotView.removeFromSuperview()
                //一定要记得动画完成后执行此方法，让系统管理 navigation
                transitionContext.completeTransition(true)
        }

    }
    
}
