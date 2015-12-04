//
//  APIConfig.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/9.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import Foundation

class APIConfig: NSObject {
    // 服务器ip
    static let API_Server : String = "http://zuimeia.com/api"
    // app版本
    static let API_appVersion : String = "&appVersion=2.2.4"
    // udid
    static let API_openUDID : String = "&openUDID=1bf9ccab8d121135bed763089b514aff901ffc28"
    // resolution 
    static let API_resolution : String = "&resolution=%7B750%2C%201334%7D"
    // 系统版本 
    static let API_systemVersion : String = "&systemVersion=9.1"
    // pageSize
    static let API_pageSize : String = "&page_size=10"
    // platform
    static let API_platform : String = "&platform=1"
    
    
    // 1.每日最美 pagesize20 参数 page
    static let API_Today : String = API_Server+"/apps/app/daily/?"+API_appVersion+API_openUDID+API_resolution+API_systemVersion+API_pageSize+API_platform
    
    // 2.限免推荐 pagesize20  参数 page
    static let API_Recommend : String = API_Server+"/category/100/all/?type=zuimei.daily"+API_appVersion+API_systemVersion+API_openUDID+API_pageSize+API_platform+API_resolution
    
    // 3.文章专栏 
    static let API_Article : String = API_Server+"/media/list/?type=zhuanlan"+API_platform+API_resolution+API_appVersion+API_openUDID+API_systemVersion
    // 4.发现应用 - 最热分享 page
    static let API_FindApp_HotShare : String = API_Server+"/community/recommend_apps/?"+API_appVersion+API_openUDID+API_pageSize+API_platform+API_systemVersion+API_resolution
    // 5.发现应用 - 最新分享 参数 pos
    static let API_FindAPP_LastestShare : String = API_Server+"/community/apps/?"+API_appVersion+API_openUDID+API_pageSize+API_platform+API_resolution+API_systemVersion
    
    // 6.美我一下
    static let API_APPStoreComment : String = "https://itunes.apple.com/cn/app/zui-mei-ying-yong/id739652274?mt=8"
    // 7.招聘编辑
    static let API_Invite : String = "http://zuimeia.com/article/100/?utm_medium=community_android&utm_source=niceapp"
    // 8.搜索 参数 keyword:输入的东西
    static let API_Search : String = API_Server+"/search/?"+API_openUDID+API_systemVersion+API_appVersion+API_resolution+API_platform
    // 9.发现应用 - 评论 参数:  app_id,comment_id:上一条评论的id
    static let API_FindApp_comments : String = API_Server+"/community/comments/?"+API_appVersion+API_openUDID+API_pageSize+API_platform+API_resolution+API_systemVersion
}
