//
//  NiceSerices.swift
//  beautifulApp-Swift3
//
//  Created by 梁亦明 on 16/11/15.
//  Copyright © 2016年 xiaoming.com. All rights reserved.
//

import UIKit
import Moya
import RxSwift
class NiceServices {
    /// 单例
    static let shareInstance = NiceServices()
    
    private init() {}
}
//
extension NiceServices {
    /// 获取首页的数据
    public func getHomeData(target: APIConstant, successHandle: ((Array<HomeModel>) -> Void)?) {
        niceProvider.request(target) { result in
            switch result {
            case let .success(response):
                do {
                    let json = try response.mapJSON() as! NSDictionary
                    
                    guard let content = json["data"] as? NSDictionary else {
                        return
                    }
                    guard let contentArray = content["apps"] as? Array<NSDictionary>  else {
                        return
                    }
                    // 如果有数据再往下执行
                    DispatchQueue.global().async {
                        let data = contentArray.map({ (dict) -> HomeModel in
                            HomeModel(dict: dict)
                        })
                        // 获取数据成功回调
                        DispatchQueue.main.async {
                            if let success = successHandle {
                                success(data)
                            }
                        }
                    }
                    
                } catch {
                    print("数据异常")
                }
                
            default:
                break
            }
        }
    }
    
    
    public func getFindAppData(target: APIConstant, successHandle: ((Array<FindAppModel>) -> Void)?) {
        niceProvider.request(target) { result in
            switch result {
            case let .success(response):
                do {
                    let json = try response.mapJSON() as! NSDictionary
                    
                    guard let content = json["data"] as? NSDictionary else {
                        return
                    }
                    guard let contentArray = content["apps"] as? Array<NSDictionary>  else {
                        return
                    }
                    // 如果有数据再往下执行
                    DispatchQueue.global().async {
                        let data = contentArray.map({ (dict) -> FindAppModel in
                            FindAppModel(dict: dict)
                        })
                        // 获取数据成功回调
                        DispatchQueue.main.async {
                            if let success = successHandle {
                                success(data)
                            }
                        }
                    }
                    
                } catch {
                    print("数据异常")
                }
                
            default:
                break
            }
        }
    }
    
}
