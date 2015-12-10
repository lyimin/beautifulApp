//
//  XMLContentModel.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/12/6.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit
enum XMLContentType {
    case XMLContentTypeP
    case XMLContentTypeH2
    case XMLContentTypeA
    case XMLContentTypeImg
    case XMLContentTypeUnknow
}

class XMLContentModel: NSObject {
    var contentType : XMLContentType!
    var content : String!
}
