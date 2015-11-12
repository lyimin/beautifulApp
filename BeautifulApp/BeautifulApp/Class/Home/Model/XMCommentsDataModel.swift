//
//  XMCommentsDataModel.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/9.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMCommentsDataModel: NSObject {
    var is_on_cover : Bool?
    // 背景色
    var author_bgcolor : String?
    // 创建时间
    var created_at : String?
    // 更新时间
    var updated_at : String?
    // 性别
    var author_gender : String?
    // 内容
    var content : String?
    // 作者名
    var author_name : String?
    var author_career : String?
    var article : String?
    // 作者id
    var author_id : String?
    // 作者图片
    var author_avatar_url : String?
    // 评论id
    var id : String?
    
    convenience init(dict : NSDictionary) {
        self.init()
        
        self.is_on_cover = dict["is_on_cover"] as? Bool
        self.author_bgcolor = dict["author_bgcolor"] as? String
        self.created_at = dict["created_at"] as? String
        self.updated_at = dict["updated_at"] as? String
        self.author_gender = dict["author_gender"] as? String
        self.content = dict["content"] as? String
        self.author_name = dict["author_name"] as? String
        self.author_career = dict["author_career"] as? String
        self.article = dict["article"] as? String
        self.author_id = dict["author_id"] as? String
        self.author_avatar_url = dict["author_avatar_url"] as? String
        self.id = dict["id"] as? String
    }
}