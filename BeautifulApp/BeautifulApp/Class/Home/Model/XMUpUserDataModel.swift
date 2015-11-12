//
//  XMUpUserDataModel.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/9.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMUpUserDataModel: NSObject {
    var id : String?
    // 用户名
    var userName : String?
    // 职业
    var career : String?
    // 性别
    var gender : String?
    // 背景
    var bg_color : String?
    // 头像
    var avatar_url : String?
    var identity : String?
    // 花
    var flowers : String?
    var enname : String?
    
    convenience init(dict : NSDictionary) {
        self.init()
        
        self.id = "\(dict["id"])"
        self.userName = dict["userName"] as? String
        self.career = dict["career"] as? String
        self.gender = dict["gender"] as? String
        self.bg_color = dict["bg_color"] as? String
        self.avatar_url = dict["avatar_url"] as? String
        self.identity = dict["identity"] as? String
        self.flowers = dict["flowers"] as? String
        self.enname = dict["enname"] as? String
    }
}
