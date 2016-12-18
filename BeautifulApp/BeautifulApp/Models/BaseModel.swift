//
//  BaseModel.swift
//  beautifulApp-Swift3
//
//  Created by 梁亦明 on 16/11/21.
//  Copyright © 2016年 xiaoming.com. All rights reserved.
//

import Foundation

public protocol Initable {
    init(dict: NSDictionary)
}
struct BaseModel {
    
}

struct UpUserModel {
    /// 用户名
    var userName: String!
    /// career
    var career: String!
    /// 性别
    var gender: String!
    /// 背景色
    var bg_color: String!
    /// 作者头像
    var avatar_url: String!
    var identity: Int!
    var flowers: Int!
    var id: Int!
    var enname: String!
   
    init(dict: NSDictionary) {
        self.userName = dict["userName"] as? String ?? ""
        self.career = dict["career"] as? String ?? ""
        self.gender = dict["gender"] as? String ?? ""
        self.bg_color = dict["bg_color"] as? String ?? ""
        self.avatar_url = dict["avatar_url"] as? String ?? ""
        self.identity = dict["identity"] as? Int ?? 0
        self.flowers = dict["flowers"] as? Int ?? 0
        self.id = dict["id"] as? Int ?? 0
        self.enname = dict["enname"] as? String ?? ""
    }
}

struct CommentModel {
    var is_on_cover: Bool!
    // 背景色
    var author_bgcolor: String!
    // 创建时间
    var created_at: String!
    // 更新时间
    var updated_at: String!
    // 性别
    var author_gender: String!
    // 内容
    var content: String!
    // 作者名
    var author_name: String!
    var author_career: String!
    var article: Int!
    // 作者id
    var author_id: Int!
    // 作者图片
    var author_avatar_url: String!
    // 评论id
    var id: Int!
    // appid
    var app_id: Int!
    
    init(dict: NSDictionary) {
        self.is_on_cover = dict["is_on_cover"] as? Bool ?? false
        self.author_bgcolor = dict["author_bgcolor"] as? String ?? ""
        self.created_at = dict["created_at"] as? String ?? ""
        self.updated_at = dict["updated_at"] as? String ?? ""
        self.author_gender = dict["author_gender"] as? String ?? ""
        self.content = dict["content"] as? String ?? ""
        self.author_name = dict["author_name"] as? String ?? ""
        self.author_career = dict["author_career"] as? String ?? ""
        self.article = dict["article"] as? Int ?? 0
        self.author_id = dict["author_id"] as? Int ?? 0
        self.author_avatar_url = dict["author_avatar_url"] as? String ?? ""
        self.id = dict["id"] as? Int ?? 0
        self.app_id = dict["app_id"] as? Int ?? 0
    }
}


struct InfoModel {
    // 下载的用户
    var up_users = [String]()
    // 喜欢的用户
    var fav_users = [String]()
    // 喜欢的数量
    var fav : String!
    // 下载数
    var up : String!
    var down : String!
    var av : String!
    var down_users = [String]()
    
    init(dict: NSDictionary) {
        let upUserArray = dict["up_users"] as! NSArray
        self.up_users = upUserArray.map { (user) -> String in
            "\(user)"
        }
        
        let favUserArray = dict["fav_users"] as? NSArray
        if let array = favUserArray {
            self.fav_users = array.map({ (user) -> String in
                "\(user)"
            })
        }
        
        let downUserArray = dict["down_users"] as! NSArray
        self.down_users = downUserArray.map({ (user) -> String in
            "\(user)"
        })
        
        self.fav = "\(dict["fav"])"
        self.up = "\(dict["up"]!)"
        self.down = "\(dict["down"])"
        self.av = "\(dict["av"])"
    }
}
