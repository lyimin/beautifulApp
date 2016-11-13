//
//  Reusable.swift
//  EyepetizerApp
//
//  Created by 梁亦明 on 16/3/16.
//  Copyright © 2016年 xiaoming. All rights reserved.
//

import UIKit

public protocol Reusable: class {
    static var reuseIdentifier: String { get }
}

extension Reusable {
    static var reuseIdentifier : String {
        return String(describing: self)
    }
}

// MARK: - 扩展UITableView, 不用传入identifier参数  identifier参数为类名
public extension UICollectionView {
    
    public func dequeueReusableCell<T: Reusable>(indexPath: IndexPath) -> T {
        return self.dequeueReusableCell(withReuseIdentifier: T.reuseIdentifier, for: indexPath) as! T
    }
    
    func registerClass<T: UICollectionViewCell>(_: T.Type) where T: Reusable {
        self.register(T.self, forCellWithReuseIdentifier: T.reuseIdentifier)
    }
    
    func registerClass<T: UICollectionReusableView>(_: T.Type, forSupplementaryViewOfKind: String) where T: Reusable {
        return self.register(T.self, forSupplementaryViewOfKind: forSupplementaryViewOfKind, withReuseIdentifier: T.reuseIdentifier)
    }
    
    func dequeueReusableSupplementaryViewOfKind<T: UICollectionReusableView>(elementKind: String, indexPath: NSIndexPath) -> T where T: Reusable {
        return self.dequeueReusableSupplementaryView(ofKind: elementKind, withReuseIdentifier: T.reuseIdentifier, for: indexPath as IndexPath) as! T
    }
}

public extension UITableView {
    func dequeueReusableCell<T: Reusable>() -> T? {
        return self.dequeueReusableCell(withIdentifier: T.reuseIdentifier) as! T?
    }
}

