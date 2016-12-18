//
//  FindAppModel.swift
//  beautifulApp-Swift3
//
//  Created by 梁亦明 on 2016/12/17.
//  Copyright © 2016年 xiaoming.com. All rights reserved.
//

import Foundation

struct FindAppModel: Initable {
    // app 名
    var title: String!
    // 作者id
    var author_id: Int!
    // 作者性别
    var author_gender: String!
    // 作者描述
    var author_career: String!
    // 观看数 int
    var show_times: Int!
    // 喜欢数 int
    var author_flowers: Int!
    // 评论数 int
    var comment_times: Int!
    // id int
    var id: Int!
    // Appicon
    var icon_image: String!
    // 描述 description
    var appDescription: String!
    // 创建时间
    var created_at: String!
    // 更新时间
    var updated_at: String!
    // 作者名
    var author_name: String!
    // 作者头像
    var author_avatar_url: String!
    // 作者背景色
    var author_bgcolor: String!
    // 中间图片
    var cover_image: String!
    var pos: Int!
    var up_times: String!
    
    // 图片
    var all_images: Array<String> = Array()
    
    // 下载
    var download_urls: Array<FindAppDownloadModel> = Array()
    
    // 评论
    var comments: Array<CommentModel> = Array()
    
    // up_users 模型
    var up_users: Array<UpUserDataModel> = Array()
    
    init(dict: NSDictionary) {
        self.title = dict["title"] as? String ?? ""
        self.author_id = dict["author_id"] as? Int ?? 0
        self.author_gender = dict["author_gender"] as? String ?? ""
        self.author_career = dict["author_career"] as? String ?? ""
        self.show_times = dict["show_times"] as? Int ?? 0
        self.author_flowers = dict["author_flowers"] as? Int ?? 0
        self.comment_times = dict["comment_times"] as? Int ?? 0
        self.id = dict["id"] as? Int ?? 0
        self.icon_image = dict["icon_image"] as? String ?? ""
        self.appDescription = dict["description"] as? String ?? ""
        self.created_at = dict["created_at"] as? String ?? ""
        self.updated_at = dict["updated_at"] as? String ?? ""
        self.author_name = dict["author_name"] as? String ?? ""
        self.author_avatar_url = dict["author_avatar_url"] as? String ?? ""
        self.author_bgcolor = dict["author_bgcolor"] as? String ?? ""
        self.cover_image = dict["cover_image"] as? String ?? ""
        self.pos = dict["pos"] as? Int ?? 0
        self.up_times = dict["up_times"] as? String ?? ""
        
        // 图片
        self.all_images = dict["all_images"] as! Array<String>
        
        // 下载
        let downArray = dict["download_urls"] as! NSArray
        self.download_urls = downArray.map({ (dict) -> FindAppDownloadModel in
            FindAppDownloadModel(dict: dict as! NSDictionary)
        })
        
        // 评论
        let commArray = dict["comments"] as! NSArray
        self.comments = commArray.map({ (dict) -> CommentModel in
            return CommentModel(dict: dict as! NSDictionary)
        })
        
        let up_usersArray = dict["up_users"] as! NSArray
        self.up_users = up_usersArray.map({ (dict) -> UpUserDataModel in
            return UpUserDataModel(dict: dict as! NSDictionary)
        })
        
    }
}

// 下载
struct FindAppDownloadModel {
    // 地址
    var url: String!
    // 平台
    var name: String!
    var channel: String!
    
    init(dict: NSDictionary) {
        self.url = dict["url"] as? String ?? ""
        self.name = dict["name"] as? String ?? ""
        self.channel = dict["channel"] as? String ?? ""
    }
}

// 评论
//struct FindAppCommentModel {
//    // 评论数 int
//    var count: Int!
//    // 背景色
//    var author_bgcolor: String!
//    // 创建时间
//    var created_at: String!
//    // 描述
//    var author_career: String!
//    // 性别
//    var author_gender: String!
//    // 更新时间
//    var updated_at: String!
//    // 内容
//    var content: String!
//    var isoncover: Bool!
//    // appTitle
//    var app_title: String!
//    // appid
//    var app_id: Int!
//    // 作者id
//    var author_id: Int!
//    // 作者图片
//    var author_avatar_url: String!
//    // 评论id
//    var id: Int!
//    // 作者名字
//    var author_name: String!
//    
//    init(dict: NSDictionary)  {
//        self.count = dict["count"] as? Int ?? 0
//        self.author_bgcolor = dict["author_bgcolor"] as? String ?? ""
//        self.created_at = dict["created_at"] as? String ?? ""
//        self.author_career = dict["author_career"] as? String ?? ""
//        self.author_gender = dict["author_bgcolor"] as? String ?? ""
//        self.updated_at = dict["updated_at"] as? String ?? ""
//        self.content = dict["content"] as? String ?? ""
//        self.isoncover = dict["isoncover"] as? Bool ?? false
//        self.app_title = dict["app_title"] as? String ?? ""
//        self.app_id = dict["app_id"] as? Int ?? 0
//        self.author_id = dict["author_id"] as! Int 
//        self.author_avatar_url = dict["author_avatar_url"] as? String ?? ""
//        self.id = dict["id"] as? Int ?? 0
//        self.author_name = dict["author_name"] as? String ?? ""
//    }
//}

struct UpUserDataModel {
    var id: Int!
    // 用户名
    var userName: String!
    // 职业
    var career: String!
    // 性别
    var gender: String!
    // 背景
    var bg_color: String!
    // 头像
    var avatar_url: String!
    var identity: Int!
    // 花
    var flowers: Int!
    var enname: String!
    
    init(dict: NSDictionary) {
        
        self.id = dict["id"] as? Int ?? 0
        self.userName = dict["userName"] as? String ?? ""
        self.career = dict["career"] as? String ?? ""
        self.gender = dict["gender"] as? String ?? ""
        self.bg_color = dict["bg_color"] as? String ?? ""
        self.avatar_url = dict["avatar_url"] as? String ?? ""
        self.identity = dict["identity"] as? Int ?? 0
        self.flowers = dict["flowers"] as? Int ?? 0
        self.enname = dict["enname"] as? String ?? ""
    }
}
