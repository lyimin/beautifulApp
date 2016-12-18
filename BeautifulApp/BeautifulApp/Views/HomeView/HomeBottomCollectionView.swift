//
//  HomeBottomCollectionView.swift
//  beautifulApp-Swift3
//
//  Created by 梁亦明 on 16/11/29.
//  Copyright © 2016年 xiaoming.com. All rights reserved.
//

import Foundation


class HomeBottomCollectionView: UICollectionView {
    
    //MARK: --------------------------- Life Cycle --------------------------
    override init(frame: CGRect, collectionViewLayout layout: UICollectionViewLayout) {
        super.init(frame: frame, collectionViewLayout: layout)
        
        // 注册item
        self.registerClass(HomeBottomItemCell.self)
        self.isScrollEnabled = false
        self.backgroundColor = UIColor.clear
        self.showsHorizontalScrollIndicator = false
        self.tag = 101
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    //MARK: --------------------------- Private Methods --------------------------
    // 重新设置cell的frame
    fileprivate func resetCellFrame(touches : Set<UITouch>) {
        // 获取点击的位置
        let touch: UITouch = (touches as NSSet).anyObject() as! UITouch
        let clickPoint: CGPoint = touch.location(in: self)
        // 判断点在哪个cell
        for index in 0..<self.cellArray.count {
            let cell = self.cellArray[index]
            if CGRect(x: cell.x, y: 0, width: cell.width, height: cell.height).contains(clickPoint) {
                // 如果点击的点在cell
                guard indexCell != cell else {
                    return
                }
                self.indexCell = cell

                UIView.animate(withDuration: 0.35, delay: 0, usingSpringWithDamping: 0.3, initialSpringVelocity: 5, options: .allowAnimatedContent, animations: {
                    
                    for i in 0..<self.cellArray.count {
                        let cell = self.cellArray[i]
                        let gap = abs(CGFloat(i-index)*5)
                        cell.y = self.minItemY+gap
                    }
                    
                }, completion: nil)
            }
        }
    }
    
    
    //MARK: --------------------------- Getter and Setter --------------------------
    
    fileprivate var cellArray: Array<UICollectionViewCell>! ;
    // cell的最小y值
    fileprivate let minItemY: CGFloat = 10;
    // 保存当前index
    fileprivate var indexCell: UICollectionViewCell?
    // 上一个index
    fileprivate var lastCell: UICollectionViewCell?
    
    typealias TouchIndexDidChangeBlock = (_ indexPath: IndexPath) -> Void
    var touchIndexDidChangeBlock: TouchIndexDidChangeBlock?
}

/// 触摸事件处理
extension HomeBottomCollectionView {
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        // 获取显示的cell,保存cell的rect数组, 排序按cell的x从小到大
        var cellArray : Array<UICollectionViewCell> = Array()
        
        // 遍历当前屏幕显示的cell
        for cell in self.visibleCells {
            cellArray.append(cell)
        }
        // 按cell的x从小到大进行排序
        cellArray.sort { (cell1, cell2) -> Bool in
            return cell1.x < cell2.x
        }
        self.cellArray = cellArray
        
        // 重新设置frame
        resetCellFrame(touches: touches)
    }
    
    override func touchesMoved(_ touches: Set<UITouch>, with event: UIEvent?) {
        resetCellFrame(touches: touches)
    }
    
    override func touchesEnded(_ touches: Set<UITouch>, with event: UIEvent?) {
        UIView.animate(withDuration: 0.35, delay: 0, usingSpringWithDamping: 0.3, initialSpringVelocity: 5, options: .allowAnimatedContent, animations: {
            
            for cell in self.cellArray {
                cell.y = cell != self.indexCell ?50:15
            }
            
        }, completion: nil)
        
        self.lastCell = indexCell
        let indexPath = self.indexPath(for: indexCell!)
        
        // 回调给首页控制器刷新页面
        if let block = touchIndexDidChangeBlock, let indexPath = indexPath {
            block(indexPath)
        }
        
//        self.bottomViewDelegate?.homeBottomCollectView(self, touchIndexDidChangeWithIndexPath: indexPath, cellArrayCount: self.cellArray.count)
    }
}


/// collectionView布局
class HomeBottomFlowLayout: UICollectionViewFlowLayout {
    override func prepare() {
        super.prepare()
        
        self.itemSize = CGSize(width: UIConstant.SCREEN_WIDTH/8-2, height:60)
        self.scrollDirection = UICollectionViewScrollDirection.horizontal
        self.sectionInset = UIEdgeInsetsMake(0, 2, 0, 2)
        self.minimumLineSpacing = 2
    }
}
