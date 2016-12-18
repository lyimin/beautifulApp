//
//  XMLParserUtil.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/12/5.
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

class XMLParserUtil: NSObject, XMLParserDelegate {
    fileprivate var parserManager: XMLParser!
    fileprivate var currentModel: XMLContentModel?
    fileprivate var currentElement: String?
    fileprivate var currentValue: String?
    var contentArray: Array<XMLContentModel> = Array()
    // 回调block
    typealias XMLParserBlock = (_ array: Array<XMLContentModel>) -> Void
    var block : XMLParserBlock?
    
    convenience init(content : String, block : XMLParserBlock?) {
        self.init()
        var contentStr = "<content>" + content + "</content>"
        contentStr = contentStr.replacingOccurrences(of: "&mdash;", with: "-")
        contentStr = contentStr.replacingOccurrences(of: "&hellip;", with: "...")
        contentStr = contentStr.replacingOccurrences(of: "&ldquo;", with: "\"")
        contentStr = contentStr.replacingOccurrences(of: "&rdquo;", with: "\"")
        contentStr = contentStr.replacingOccurrences(of: "&nbsp;", with: " ")
        contentStr = contentStr.replacingOccurrences(of: "&lsquo;", with: "'")
        contentStr = contentStr.replacingOccurrences(of: "&rsquo;", with: "'")
        contentStr = contentStr.replacingOccurrences(of: "&middot;", with: ".")
        contentStr = contentStr.replacingOccurrences(of: "&yen;", with: "¥")
        contentStr = contentStr.replacingOccurrences(of: "&rarr;", with: "->")
        contentStr = contentStr.replacingOccurrences(of: "&ang;", with: "∠")
        contentStr = contentStr.replacingOccurrences(of: "&omega;", with: "ω")
        self.block = block
        
        parserManager = XMLParser(data: contentStr.data(using: String.Encoding.utf8)!)
        parserManager.delegate = self
        parserManager.parse()
    
    }
    
}


//MARK: --------------------------- NSXMLParserDelegate --------------------------
extension XMLParserUtil {
    func parser(_ parser: XMLParser, didStartElement elementName: String, namespaceURI: String?, qualifiedName qName: String?, attributes attributeDict: [String : String] = [:]) {
        
        currentElement = elementName
        if elementName == "img" {
            // 如果有图片
            currentModel = XMLContentModel()
            currentElement = "img"
            currentValue = attributeDict["src"]!
            currentModel!.contentType = .XMLContentTypeImg
            currentModel!.content = attributeDict["src"]!
        } else if elementName == "a" {
            currentModel = XMLContentModel()
            currentElement = "a"
            currentValue = attributeDict["href"]!
            currentModel!.contentType = .XMLContentTypeA
            currentModel!.content = attributeDict["href"]!
        }
        
        
    }
    
    func parser(_ parser: XMLParser, foundCharacters string: String) {
        
        if currentElement != "" {
            // 发现标题
            switch currentElement! {
            case "h2":
                
                currentModel = XMLContentModel()
                currentModel?.contentType = .XMLContentTypeH2
                currentValue = string
                currentModel?.content = currentValue
            case "p" :
                currentModel = XMLContentModel()
                currentModel?.contentType = .XMLContentTypeP
                currentValue = string
                currentModel?.content = currentValue
            default:
                break
                
            }
        }
        
        
    }
    
    // 结束
    func parser(_ parser: XMLParser, didEndElement elementName: String, namespaceURI: String?, qualifiedName qName: String?) {
        guard let _ = self.currentModel else {
            return
        }
        
        guard currentElement != "" && currentValue != "" else {
            return
        }
        
        self.contentArray.append(currentModel!)
        currentValue = ""
        currentElement = ""
        currentModel = nil
    }
    
    func parser(_ parser: XMLParser, parseErrorOccurred parseError: Error) {
        print ("解析xml错误\(parseError)")
    }
    
    func parserDidEndDocument(_ parser: XMLParser) {
        if let _ = self.block {
            self.block!(self.contentArray)
        }
    }
}
