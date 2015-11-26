//
//  XMFindAppDownloadModel.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/25.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMFindAppDownloadModel: NSObject {
    // 地址
    var url : String?
    // 平台
    var name : String?
    var channel : String?
    
    convenience init(dict : NSDictionary) {
        self.init()
        self.url = dict["url"] as? String
        self.name = dict["name"] as? String
        self.channel = dict["channel"] as? String
    }
}
