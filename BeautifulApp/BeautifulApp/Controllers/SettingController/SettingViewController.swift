//
//  SettingViewController.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/27.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class SettingViewController: UIViewController {
    private weak var headerView : SettingHeaderView!
    var shareView: ShareView?
    var shadowView: UIView? 
    override func viewDidLoad() {
        super.viewDidLoad()
        // 设置导航栏
        self.setupNavView()
        // 添加tableView
        self.view.addSubview(tableView)
        // 适配屏幕
        self.setupLayout()
        
        headerView.backBtnDidClickWithBlock { [unowned self] in
            self.dismiss(animated: true, completion: nil)
        }
    }
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        UIApplication.shared.statusBarStyle = .default
    }
    
  

    // MARK: - private
    private func setupNavView() {
        let headerView : SettingHeaderView = SettingHeaderView.headerView()
        self.headerView = headerView
        self.view.addSubview(headerView)
        headerView.backBtnDidClickWithBlock { [unowned self]() -> Void in
            self.dismiss(animated: true, completion: nil)
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
    
    fileprivate var dataSource : NSArray = {
        let path = Bundle.main.path(forResource: "settingDataSource", ofType: "plist")!
        let dataSource : NSArray = NSArray(contentsOfFile: path as String)!
        return dataSource
    }()
    
    private func setupLayout() {
        self.headerView.snp.makeConstraints { (make) -> Void in
            make.top.left.right.equalTo(self.view)
            make.height.equalTo(headerView.height)
        }
        
        self.tableView.snp.makeConstraints { (make) -> Void in
            make.left.right.bottom.equalTo(self.view)
            make.top.equalTo(headerView.snp.bottom)
        }
    }
}

extension SettingViewController: UITableViewDataSource, UITableViewDelegate {
    //MARK: -tableview delgate
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.dataSource.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell : SettingViewCell = SettingViewCell.cellWithTableView(tableView: tableView)
        cell.data = self.dataSource[indexPath.row] as! NSDictionary
        return cell
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        
        switch indexPath.row {
        case 0:
            // 关于我们
            self.navigationController?.pushViewController(AboutViewController(), animated: true)
        case 1:
            // 分享给朋友
            //            ShareSDKUtil.shareToFriend()
            showShareView()
            break
        case 2:
            // 评分
            if #available(iOS 10.0, *) {
                UIApplication.shared.open(APIConstant.appStoreComment.baseURL, options: [:], completionHandler: nil)
            } else {
                // Fallback on earlier versions
                UIApplication.shared.openURL(APIConstant.appStoreComment.baseURL)
            }
        case 3: break
        // 意见反馈
        case 4:
            // 清除缓存
            break
//                        let diskCache : YYDiskCache = YYWebImageManager.sharedCache().cache;
//                        diskCache.removeAllObjects()
//                        PKHUD.sharedHUD.contentView = PKHUDSuccessView()
//                        PKHUD.sharedHUD.show()
//                        PKHUD.sharedHUD.hide(afterDelay: 1.0)
            
        default:
            break
        }
        
    }
}

extension SettingViewController: shareResuable {
    // 微信朋友
    func weixinShareButtonDidClick() {
        shareToFriend(shareContent: "_Eamon开发的最美应用", shareImage: UIImage(named: "ic_launcher")!, shareUrl: "https://github.com/lyimin", shareTitle: "_Eamon开发的最美应用")
    }
    // 朋友圈
    func friendsCircleShareButtonDidClick() {
        shareToFriendsCircle(shareContent: "_Eamon开发的最美应用", shareTitle: "_Eamon开发的最美应用", shareUrl: "https://github.com/lyimin", shareImage: UIImage(named: "ic_launcher")!)
    }
    // 更多
    func shareMoreButtonDidClick() {
        hiddenShareView()
    }
}
