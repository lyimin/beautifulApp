//
//  XMShareModel.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/12/12.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import Foundation

class XMShareModel: NSObject {
    // 内容
    var appContent : String!
    // 图片url
    var imgUrl : String!
    // app标题
    var appTitle : String!
    // app描述
    var appDescription : String!
    // appURL
    var appURL : String!
    
    convenience init(appContent:String, imgUrl : String, appTitle:String, appDescription:String,appURL:String) {
        self.init()
        
        self.appContent = appContent
        self.imgUrl = imgUrl
        self.appTitle = appTitle
        self.appDescription = appDescription
        self.appURL = appURL
    }
}
