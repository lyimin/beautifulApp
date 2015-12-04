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
        // 
        self.setupNavView()
        tableView.delegate = self
        tableView.dataSource = self
        self.view.addSubview(tableView)
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
                self.navigationController?.pushViewController(AboutViewController(), animated: true)
            case 1:
                print("分享")
            case 2:
                UIApplication.sharedApplication().openURL(NSURL(string: APIConfig.API_APPStoreComment)!)
            case 3: break
                // 意见反馈
            case 4:
                // 清除缓存
            
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
        headerView.y = 0
        self.headerView = headerView
        self.view.addSubview(headerView)
        headerView.backBtnDidClickWithBlock { [unowned self]() -> Void in
            self.dismissViewControllerAnimated(true, completion: nil)
        }
    }
    
    //MARK:- setting or getter 
    private var tableView : UITableView = {
        let tableView : UITableView = UITableView(frame: CGRectMake(0, 64, SCREEN_WIDTH, SCREEN_HEIGHT-64))
        tableView.separatorStyle = .None
        tableView.tableFooterView = UIView()
        tableView.rowHeight = 50
        return tableView
    }()
    
    private var dataSource : NSArray = {
        let path : NSString = NSBundle.mainBundle().pathForResource("settingDataSource", ofType: "plist")!
        let dataSource : NSArray = NSArray(contentsOfFile: path as String)!
        return dataSource
    }()

}
