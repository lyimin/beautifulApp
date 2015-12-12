//
//  XMLParserUtil.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/12/5.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMLParserUtil: NSObject, NSXMLParserDelegate {
    private var parserManager : NSXMLParser!
    private var currentModel : XMLContentModel?
    private var currentElement : String?
    private var currentValue : String?
    var contentArray : Array<XMLContentModel> = Array()
    // 回调block
    typealias XMLParserBlock = (array : Array<XMLContentModel>) -> Void
    var block : XMLParserBlock?
    
    convenience init(content : String, block : XMLParserBlock?) {
        self.init()
        var contentStr = "<content>" + content + "</content>"
        contentStr = contentStr.stringByReplacingOccurrencesOfString("&mdash;", withString: "-")
        contentStr = contentStr.stringByReplacingOccurrencesOfString("&hellip;", withString: "...")
        contentStr = contentStr.stringByReplacingOccurrencesOfString("&ldquo;", withString: "\"")
        contentStr = contentStr.stringByReplacingOccurrencesOfString("&rdquo;", withString: "\"")
        contentStr = contentStr.stringByReplacingOccurrencesOfString("&nbsp;", withString: " ")
        contentStr = contentStr.stringByReplacingOccurrencesOfString("&lsquo;", withString: "'")
        contentStr = contentStr.stringByReplacingOccurrencesOfString("&rsquo;", withString: "'")
        contentStr = contentStr.stringByReplacingOccurrencesOfString("&middot", withString: ".")
        self.block = block
        
        parserManager = NSXMLParser(data: contentStr.dataUsingEncoding(NSUTF8StringEncoding)!)
        parserManager.delegate = self
        parserManager.parse()
    
    }
    
    // MARK: - NSXMLParserDelegate
    
    func parser(parser: NSXMLParser, didStartElement elementName: String, namespaceURI: String?, qualifiedName qName: String?, attributes attributeDict: [String : String]) {
        
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
    
    func parser(parser: NSXMLParser, foundCharacters string: String) {
        
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
    func parser(parser: NSXMLParser, didEndElement elementName: String, namespaceURI: String?, qualifiedName qName: String?) {
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
    
    func parser(parser: NSXMLParser, parseErrorOccurred parseError: NSError) {
        print ("解析xml错误\(parseError)")
    }
    
    func parserDidEndDocument(parser: NSXMLParser) {
        if let _ = self.block {
            self.block!(array: self.contentArray)
        }
    }
}
