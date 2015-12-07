//
//  XMHomeBottomFlowLayout.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/17.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMHomeBottomFlowLayout: UICollectionViewFlowLayout {
    override func prepareLayout() {
        super.prepareLayout()
        
        self.itemSize = CGSizeMake(SCREEN_WIDTH/8-2, 60)
        self.scrollDirection = UICollectionViewScrollDirection.Horizontal
        self.sectionInset = UIEdgeInsetsMake(0, 2, 0, 2)
        self.minimumLineSpacing = 2
    }
}
