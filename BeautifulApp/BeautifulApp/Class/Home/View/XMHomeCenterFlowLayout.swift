//
//  XMHomeCenterFlowLayout.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/17.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMHomeCenterFlowLayout: UICollectionViewFlowLayout {
    override func prepareLayout() {
        super.prepareLayout()
        
        self.itemSize = CGSizeMake(310, 420)
        self.scrollDirection = UICollectionViewScrollDirection.Horizontal
        self.sectionInset = UIEdgeInsetsMake(0, 5, 0, 5);
    }
}
