//
//  XMInfoDataModel.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/9.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMInfoDataModel: NSObject {
    // 下载的用户
    var up_users : Array<String>?
    // 喜欢的用户
    var fav_users : Array<String>?
    // 喜欢的数量
    var fav : String?
    // 下载数
    var up : String?
    var down : String?
    var av : String?
    var down_users : Array<String>?
    
    convenience init(dict : NSDictionary) {
        self.init()
        
        self.up_users = dict["up_users"] as? Array
        self.fav_users = dict["fav_users"] as? Array
        self.fav = dict["fav"] as? String
        self.up = dict["up"] as? String
        self.down = dict["down"] as? String
        self.av = dict["av"] as? String
        self.down_users = dict["down_users"] as? Array
    }
}
