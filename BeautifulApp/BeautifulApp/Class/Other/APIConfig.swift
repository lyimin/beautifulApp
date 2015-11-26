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
    static let API_resolution : String = "&resolution={750%2C%201334}"
    // 系统版本 
    static let API_systemVersion : String = "&systemVersion=9.1"
    
    // 1.每日最美  参数 page
    static let API_Today : String = API_Server+"/apps/app/daily/?"+API_appVersion+API_openUDID+API_resolution+API_systemVersion+"&page_size=20&platform=1"
    
    // 2.限免推荐  参数 page
    static let API_Recommend : String = API_Server+"/category/100/all/?type=zuimei.daily"+API_appVersion+API_systemVersion+API_openUDID+"&page_size=20&platform=1&resolution={750%2C%201334}"
    
    // 3.文章专栏 
    static let API_Article : String = API_Server+"/media/list/?&platform=1&resolution={750%2C%201334}&type=zhuanlan"+API_appVersion+API_openUDID+API_systemVersion
//    http://zuimeia.com/api/media/list/?&appVersion=2.2.4&openUDID=1bf9ccab8d121135bed763089b514aff901ffc28&platform=1&resolution={750%2C%201334}&systemVersion=9.1&type=zhuanlan
}
