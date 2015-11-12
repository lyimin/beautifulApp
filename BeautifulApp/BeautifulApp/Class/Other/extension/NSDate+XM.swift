//
//  NSDate+XM.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/11.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import Foundation

extension NSDate {
    // 获取今天日期
    class func today() -> String{
        let dataFormatter : NSDateFormatter = NSDateFormatter()
        dataFormatter.dateFormat = "yyyy-MM-dd"
        let now : NSDate = NSDate()
        return dataFormatter.stringFromDate(now)
    }
    
    // 判断是否是今天
    class func isToday (dateString : String) -> Bool {
//        let date : String = NSDate.formattDay(dateString)
        return dateString == self.today()
    }
    
    // 判断是否是昨天
    class func isLastDay (dateString : String) -> Bool {
        let todayTimestamp = self.getTimestamp(today())
        let lastdayTimestamp = self.getTimestamp(dateString)
        return lastdayTimestamp == todayTimestamp-(24*60*60)
    }
    
    // yyyy-MM-dd格式 转 MM月dd日
    class func formattDay (dataString : String) -> String {
        if dataString.length <= 0 {
            return "errorDate"
        }
        let dateFormatter : NSDateFormatter = NSDateFormatter()
        dateFormatter.dateFormat = "yyyy-MM-dd"
        let date : NSDate = dateFormatter.dateFromString(dataString)!
        
        
        // 转换成xx月xx日格式
        let newDateFormatter : NSDateFormatter = NSDateFormatter()
        newDateFormatter.dateFormat = "MM月dd日"
        return newDateFormatter.stringFromDate(date)
    }
    
    // 根据日期获取时间戳
    class func getTimestamp (dateString : String) -> NSTimeInterval {
        if dateString.length <= 0 {
            return 0
        }
        let newDateStirng = dateString.stringByAppendingString(" 00:00:00")
        
        let formatter : NSDateFormatter = NSDateFormatter()
        formatter.dateStyle = NSDateFormatterStyle.MediumStyle
        formatter.dateStyle = NSDateFormatterStyle.ShortStyle
        formatter.dateFormat = "yyyy-MM-dd HH:mm:ss"
        formatter.timeZone = NSTimeZone(name: "Asia/Beijing")
        
        let dateNow = formatter.dateFromString(newDateStirng)
        
        return (dateNow?.timeIntervalSince1970)!
    }
    
    // 获取星期
    class func weekWithDateString (dateString : String) -> String{
        let timestamp = NSDate.getTimestamp(dateString)
        let day = Int(timestamp/86400)
        let array : Array = ["星期一","星期二","星期三","星期四","星期五","星期六","星期日"];
        return array[(day-3)%7]
//        return "星期\((day-3)%7))"
    }
    
}
