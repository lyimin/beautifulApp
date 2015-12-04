//
//  XMSearchController.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/29.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMSearchController: UIViewController, UIScrollViewDelegate {

    private weak var headerView : XMSearchHeaderView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.view.backgroundColor = UIColor.whiteColor()
        // 添加顶部
        let headerView : XMSearchHeaderView = XMSearchHeaderView.headerView()
        self.headerView = headerView
        self.view.addSubview(headerView)

        // 点击取消按钮
        headerView.cancleBtnDidClickWithBlock { [unowned self]() -> Void in
            self.dismissViewControllerAnimated(true, completion: nil)
        }
//        // textfield改变时调用
//        headerView.textfieldDidChangeWithBlock { (text) -> Void in
//            // 调用接口
//            
//        }
        
        self.view.addSubview(imgView)
        
        // 添加tableview
//        tableView.delegate = self
//        tableView.dataSource = self
//        self.view.addSubview(tableView)
    }
    
    //MARK:-  tableView Delegate
//    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
//        return 10
//    }
//    
//    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
//        let cell : XMSearchViewCell = XMSearchViewCell.cellWithTableView(tableView)
//        return cell
//    }
//    
//    func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
//        
//    }
//    
//    //MARK:- scrollviewDelegate 
//    func scrollViewDidScroll(scrollView: UIScrollView) {
//        self.view.endEditing(true)
//    }
    
    //MARK:- getter or setter
    private var imgView : UIImageView = {
        let imgView : UIImageView = UIImageView(frame: CGRectMake(0, 100, 300, 100))
        imgView.image = UIImage(named: "searchImg")
        return imgView
    }()
    
//    private var tableView : UITableView = {
//        let tableView : UITableView = UITableView(frame: CGRectMake(0, 60, SCREEN_WIDTH, 508))
//        tableView.separatorStyle = .None
//        tableView.rowHeight = 50
//        return tableView
//    }()

}
