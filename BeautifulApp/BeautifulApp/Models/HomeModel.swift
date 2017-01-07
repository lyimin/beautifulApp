//
//  HomeModel.swift
//  beautifulApp-Swift3
//
//  Created by 梁亦明 on 16/11/21.
//  Copyright © 2016年 xiaoming.com. All rights reserved.
//

import Foundation


struct HomeModel: Initable {
    var id: Int!
    // 背景色
    var recommanded_background_color: String!
    // 标题
    var title: String!
    // 子标题
    var sub_title: String!
    // 中间图片
    var cover_image: String!
    // 详情
    var digest: String!
    // 底部图片
    var icon_image: String!
    // 更新时间
    var update_time: String!
    // 公开时间
    var publish_date: String!
    // 作者
    var author_username: String!
    // 作者id
    var author_id: String!
    // 作者背景
    var author_bgcolor: String!
    // 内容
    var content: String!
    // 分类
    var tags: String!
    // 二维码
    var qrcode_image: String!
    // 下载地址
    var download_url: String!
    // 分享url
    var video_share_url: String!
    // up_users 模型
    var up_users = [UpUserModel]()
    
    // comments 模型
    var comments = [CommentModel]()
    
    // info 模型
    var info: InfoModel!
    
    init(dict: NSDictionary) {
        self.id = dict["id"] as? Int ?? 0
        self.recommanded_background_color = dict["recommanded_background_color"] as? String ?? ""
        self.title = dict["title"] as? String ?? ""
        self.sub_title = dict["sub_title"] as? String ?? ""
        self.cover_image = dict["cover_image"] as? String ?? ""
        self.digest = dict["digest"] as? String ?? ""
        self.icon_image = dict["icon_image"] as? String ?? ""
        self.update_time = dict["update_time"] as? String ?? ""
        self.publish_date = dict["publish_date"] as? String ?? ""
        self.author_username = dict["author_username"] as? String ?? ""
        self.author_id = dict["author_id"] as? String ?? ""
        self.author_bgcolor = dict["author_bgcolor"] as? String ?? ""
        self.content = dict["content"] as? String ?? ""
        self.tags = dict["tags"] as? String ?? ""
        self.qrcode_image = dict["qrcode_image"] as? String ?? ""
        self.download_url = dict["download_url"] as? String ?? ""
        self.video_share_url = dict["video_share_url"] as? String ?? ""
        // up_users 模型
        let upuserArray : Array<NSDictionary> = dict["up_users"] as! Array<NSDictionary>
        
        self.up_users = upuserArray.map{ (dict) -> UpUserModel in
            UpUserModel(dict: dict)
        }
        
        // comments 模型
        let commentsDic: NSDictionary = dict["comments"] as! NSDictionary
        let commentArray: Array<NSDictionary> = commentsDic["data"] as! Array<NSDictionary>
        
        self.comments = commentArray.map({ (dict) -> CommentModel in
            CommentModel(dict: dict)
        })
        
        // Info 模型
        let infoData = dict["info"] as! NSDictionary
        self.info = InfoModel(dict: infoData)
    }
}
