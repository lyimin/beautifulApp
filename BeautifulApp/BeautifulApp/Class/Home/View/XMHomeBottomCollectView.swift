//
//  XMHomeBottomCollectView.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/20.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

protocol XMHomeBottomCollectViewDelegate {
    func homeBottomCollectView(bottomView : UICollectionView, touchIndexDidChangeWithIndexPath indexPath: NSIndexPath?,cellArrayCount : Int)
}

class XMHomeBottomCollectView: UICollectionView {
    override init(frame: CGRect, collectionViewLayout layout: UICollectionViewLayout) {
        super.init(frame: frame, collectionViewLayout: layout)
        
        self.registerNib(UINib(nibName: "XMHomeBottomItemView", bundle: nil), forCellWithReuseIdentifier: "XMHomeBottomItemViewID")
        self.scrollEnabled = false
        self.backgroundColor = UIColor.clearColor()
        self.showsHorizontalScrollIndicator = false
        self.tag = 101
    }

    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func touchesBegan(touches: Set<UITouch>, withEvent event: UIEvent?) {
        // 获取显示的cell,保存cell的rect数组, 排序按cell的x从小到大
        var cellArray : Array<UICollectionViewCell> = Array()
        for cell in self.visibleCells() {
            cellArray.append(cell)
        }
        cellArray.sortInPlace { (cell1, cell2) -> Bool in
            return cell1.x < cell2.x
        }
        self.cellArray = cellArray
        
        // 重新设置frame
        self.resetCellFrame(touches)
    }
    
    override func touchesMoved(touches: Set<UITouch>, withEvent event: UIEvent?) {
        // 重新设置frame
        self.resetCellFrame(touches)
    }
    
    override func touchesEnded(touches: Set<UITouch>, withEvent event: UIEvent?) {
        
        UIView.animateWithDuration(0.2, delay: 0.5, options: [], animations: { () -> Void in
            for i in 0..<self.cellArray.count {
                let cell = self.cellArray[i]
                if cell != self.indexCell {
                    cell.y = 50
                } else {
                    cell.y = 15
                }
            }
            }, completion: nil)
        if self.indexCell == nil || self.lastCell == self.indexCell {
            return
        }
        self.lastCell = indexCell
        let indexPath : NSIndexPath? = self.indexPathForCell(self.indexCell!)
        self.bottomViewDelegate?.homeBottomCollectView(self, touchIndexDidChangeWithIndexPath: indexPath, cellArrayCount: self.cellArray.count)
    }
    
    // 重新设置cell的frame
    private func resetCellFrame(touches : Set<UITouch>) {
        // 获取点击的位置
        let touch : UITouch = (touches as NSSet).anyObject() as! UITouch
        let clickPoint : CGPoint = touch.locationInView(self)
        // 判断点在哪个cell
        for index in 0..<self.cellArray.count {
            let cell = self.cellArray[index]
            if CGRectContainsPoint(CGRectMake(cell.x, 0, cell.width, cell.height), clickPoint) {
                if self.indexCell == cell {
                    return
                }
                self.indexCell = cell
                // 重新设置cellframe
                UIView.animateKeyframesWithDuration(0.6, delay: 0, options: [], animations: { () -> Void in
                    UIView.addKeyframeWithRelativeStartTime(0, relativeDuration: 0.2, animations: { () -> Void in
                        for i in 0..<self.cellArray.count {
                            let cell = self.cellArray[i]
                            let gap = abs(CGFloat(i-index)*5)
                            cell.y = self.maxItemY+gap
                        }
                    })
                    
                    UIView.addKeyframeWithRelativeStartTime(0.2, relativeDuration: 0.4, animations: { () -> Void in
                        for i in 0..<self.cellArray.count {
                            let cell = self.cellArray[i]
                            cell.y += 5
                        }
                    })
                    
                    }, completion: nil)
            }
        }
    }
    
    private var cellArray : Array<UICollectionViewCell>! ;
    private var maxItemY : CGFloat = 10;
    // 保存当前index
    private var indexCell : UICollectionViewCell?
    // 上一个index
    private var lastCell : UICollectionViewCell?
    var bottomViewDelegate : XMHomeBottomCollectViewDelegate?
}
