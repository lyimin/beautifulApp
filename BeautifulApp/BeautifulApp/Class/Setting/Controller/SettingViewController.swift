//
//  SettingViewController.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/27.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class SettingViewController: UIViewController, UITableViewDataSource, UITableViewDelegate {
    private weak var headerView : SettingHeaderView!
    override func viewDidLoad() {
        super.viewDidLoad()
        // 设置导航栏
        self.setupNavView()
        // 添加tableView
        self.view.addSubview(tableView)
        // 适配屏幕
        self.setupLayout()
    }
    override func viewWillAppear(animated: Bool) {
        super.viewWillAppear(animated)
        UIApplication.sharedApplication().statusBarStyle = .Default
    }
    
    //MARK: -tableview delgate 
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.dataSource.count
    }
    
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        let cell : SettingViewCell = SettingViewCell.cellWithTableView(tableView)
        cell.data = self.dataSource[indexPath.row] as! NSDictionary
        return cell
    }
    
    func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
        tableView.deselectRowAtIndexPath(indexPath, animated: true)

        switch indexPath.row {
            case 0:
                // 关于我们
                self.navigationController?.pushViewController(AboutViewController(), animated: true)
            case 1:
                // 分享给朋友
                ShareSDKUtil.shareToFriend()
            case 2:
                // 评分
                UIApplication.sharedApplication().openURL(NSURL(string: APIConfig.API_APPStoreComment)!)
            case 3: break
                // 意见反馈
            case 4:
                // 清除缓存
                let diskCache : YYDiskCache = YYImageCache.sharedCache().diskCache
                diskCache.removeAllObjects()
            PKHUD.sharedHUD.contentView = PKHUDSuccessView()
            PKHUD.sharedHUD.show()
            PKHUD.sharedHUD.hide(afterDelay: 1.0)
           
        default:
            break
        }
    }
    // MARK: - private
    private func setupNavView() {
        let headerView : SettingHeaderView = SettingHeaderView.headerView()
        self.headerView = headerView
        self.view.addSubview(headerView)
        headerView.backBtnDidClickWithBlock { [unowned self]() -> Void in
            self.dismissViewControllerAnimated(true, completion: nil)
        }
    }
    
    //MARK:- setting or getter 
    private lazy var tableView : UITableView = {
        let tableView : UITableView = UITableView()
        tableView.delegate = self
        tableView.dataSource = self
        tableView.tableFooterView = UIView()
        tableView.rowHeight = 60
        return tableView
    }()
    
    private var dataSource : NSArray = {
        let path : NSString = NSBundle.mainBundle().pathForResource("settingDataSource", ofType: "plist")!
        let dataSource : NSArray = NSArray(contentsOfFile: path as String)!
        return dataSource
    }()
    
    private func setupLayout() {
        self.headerView.snp_makeConstraints { (make) -> Void in
            make.top.left.right.equalTo(self.view)
            make.height.equalTo(headerView.height)
        }
        
        self.tableView.snp_makeConstraints { (make) -> Void in
            make.left.right.bottom.equalTo(self.view)
            make.top.equalTo(headerView.snp_bottom)
        }
    }

}
