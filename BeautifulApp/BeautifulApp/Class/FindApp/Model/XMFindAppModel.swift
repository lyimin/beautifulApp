//
//  XMFindAppModel.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/25.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMFindAppModel: NSObject {
    // app 名
    var title : String?
    // 作者id
    var author_id : String?
    // 作者性别
    var author_gender : String?
    // 作者描述
    var author_career : String?
    // 观看数 int
    var show_times : String?
    // 喜欢数 int
    var author_flowers : String?
    // 评论数 int
    var comment_times : String?
    // id int
    var id : String?
    // Appicon
    var icon_image : String?
    // 描述 description
    var appDescription : String?
    // 创建时间
    var created_at : String?
    // 更新时间
    var updated_at : String?
    // 作者名
    var author_name : String?
    // 作者头像
    var author_avatar_url : String?
    // 作者背景色
    var author_bgcolor : String?
    // 中间图片
    var cover_image : String?
    var pos : String?
    
    // 图片
    var all_images : Array<String> = Array()
    
    // 下载
    var download_urls : Array<XMFindAppDownloadModel> = Array()
    
    // 评论
    var comments : Array<XMFindAppCommentModel> = Array()
    
    // up_users 模型
    var up_users : Array<XMUpUserDataModel> = Array()
    
    convenience init(dict : NSDictionary) {
        self.init()
        self.title = dict["title"] as? String
        self.author_id = dict["author_id"] as? String
        self.author_gender = dict["author_gender"] as? String
        self.author_career = dict["author_career"] as? String
        self.show_times = "\(dict["show_times"]!)"
        self.author_flowers = "\(dict["author_flowers"]!)"
        self.comment_times = "\(dict["comment_times"]!)"
        self.id = "\(dict["id"])"
        self.icon_image = dict["icon_image"] as? String
        self.appDescription = dict["description"] as? String
        self.created_at = dict["created_at"] as? String
        self.updated_at = dict["updated_at"] as? String
        self.author_name = dict["author_name"] as? String
        self.author_bgcolor = dict["author_bgcolor"] as? String
        self.author_avatar_url = dict["author_avatar_url"] as? String
        self.cover_image = dict["cover_image"] as? String
        self.pos = "\(dict["pos"]!)"
        // 图片 
        let photoArray : NSArray = dict["all_images"] as! NSArray
        for photo in photoArray {
            self.all_images.append(photo as! String)
        }
        
        // 下载
        let downArray : NSArray = dict["download_urls"] as! NSArray
        for dict in downArray {
            self.download_urls.append(XMFindAppDownloadModel(dict: dict as! NSDictionary))
        }
        
        // 评论
        let commArray : NSArray = dict["comments"] as! NSArray
        for dict in commArray {
            self.comments.append(XMFindAppCommentModel(dict: dict as! NSDictionary))
        }
        
        // up_user
        let up_usersArray : NSArray = dict["up_users"] as! NSArray
        for user in up_usersArray {
            self.up_users.append(XMUpUserDataModel(dict: user as! NSDictionary))
        }
    }
}
