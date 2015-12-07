//
//  XMHomeDataModel.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/9.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMHomeDataModel: NSObject {
    
    var id : String?
    // 背景色
    var recommanded_background_color : String?
    // 标题
    var title : String?
    // 子标题
    var sub_title : String?
    // 中间图片
    var cover_image : String?
    // 详情
    var digest : String?
    // 底部图片
    var icon_image : String?
    // 更新时间
    var update_time : String?
    // 公开时间
    var publish_date : String?
    // 作者
    var author_username : String?
    // 作者id
    var author_id : String?
    // 作者背景
    var author_bgcolor : String?
    // 内容
    var content : String?
    // 分类
    var tags : String?
    // 二维码
    var qrcode_image : String?
    // 下载地址
    var download_url : String?
    
    // up_users 模型
    var up_users : Array<XMUpUserDataModel> = Array()
    
    // comments 模型
    var comments : Array<XMCommentsDataModel> = Array()
    
    // info 模型
    var info : XMInfoDataModel?
    
    
    convenience init(dict : NSDictionary) {
        self.init()
        
        self.id = "\(dict["id"]!)";
        self.recommanded_background_color = dict["recommanded_background_color"] as? String
        self.title = dict["title"] as? String
        self.sub_title = dict["sub_title"] as? String
        self.cover_image = dict["cover_image"] as? String
        self.digest = dict["digest"] as? String
        self.icon_image = dict["icon_image"] as? String
        self.update_time = dict["update_time"] as? String
        self.publish_date = dict["publish_date"] as? String
        self.author_username = dict["author_username"] as? String
        self.author_id = dict["author_id"] as? String
        self.author_bgcolor = dict["author_bgcolor"] as? String
        self.content = dict["content"] as? String
        self.tags = dict["tags"] as? String
        self.qrcode_image = dict["qrcode_image"] as? String
        self.download_url = dict["download_url"] as? String
        // up_users 模型
        let upuserArray : NSArray = dict["up_users"] as! NSArray
        
        for upuserDic in upuserArray {
            let userDataModel : XMUpUserDataModel = XMUpUserDataModel(dict: upuserDic as! NSDictionary)
            self.up_users.append(userDataModel)
        }
        
        // comments 模型
        let commentsArray : NSDictionary = dict["comments"] as! NSDictionary
        
        for commentDic in commentsArray["data"] as! NSArray {
            let commentModel : XMCommentsDataModel = XMCommentsDataModel(dict: commentDic as! NSDictionary)
            self.comments.append(commentModel)
        }
        
        // info 模型
        let infoDic : NSDictionary = dict["info"] as! NSDictionary
        self.info = XMInfoDataModel(dict: infoDic)
       
        
    }
}
