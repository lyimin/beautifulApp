//
//  MenuController.swift
//  beautifulApp-Swift3
//
//  Created by 梁亦明 on 16/10/17.
//  Copyright © 2016年 xiaoming.com. All rights reserved.
//

import UIKit
import SafariServices

enum MenuItemType {
    // 每日最美
    case dayily
    // 限免推荐
    case recommend
    // 发现应用
    case findApp
    // 文章专栏
    case article
    // 美我一下
    case appStoreComment
    // 我的收藏
    case collect
    
    func typeTarget() -> APIConstant {
        switch self {
        case .dayily:
            return .daily(1)
        case .recommend:
            return .recommend(1)
        case .findApp:
            return .popular(1)
        case .article:
            return .article
        default:
            return .daily(1)
        }
    }
}

protocol MenuControllerDelegate {
    func menuDidClick(withType: MenuItemType)
}

class MenuController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = UIConstant.COLOR_APPNORMAL

        view.addSubview(mainTableView)
        view.addSubview(footerView)
        
        setupLayout()
    }
    override var preferredStatusBarStyle: UIStatusBarStyle {
        return .lightContent
    }
    //MARK: --------------------------- Getter and Setter --------------------------
    /// tableview
    fileprivate lazy var mainTableView : UITableView = {
        var mainTabView : UITableView = UITableView()
        mainTabView.backgroundColor = UIColor.clear
        let headerView = MenuHeaderView(frame: CGRect(x: 0, y: 0, width: UIConstant.SCREEN_WIDTH, height: 120))
        mainTabView.tableHeaderView = headerView
        mainTabView.separatorStyle = .none
        mainTabView.rowHeight   = 50
        mainTabView.sectionHeaderHeight = 120
        mainTabView.dataSource  = self
        mainTabView.delegate    = self
        return mainTabView
    }()
    
    fileprivate lazy var footerView: MenuFooterView = {
        var footerView = MenuFooterView()
        footerView.delegate = self
        return footerView
    }()
    
    var delegate: MenuControllerDelegate?
    fileprivate var type: MenuItemType! = .dayily
    /// 当前选中的item
    fileprivate var selectIndex: Int! = 0
    /// 上一个选中的cell
    fileprivate var lastSelectDotView: UIView!
}


//MARK: --------------------------- TableViewDelegate TableViewDataSource --------------------------
extension MenuController: UITableViewDelegate, UITableViewDataSource {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return MenuTabItems.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = MenuTableViewCell.cell(withTableView: tableView)
        cell.model = MenuTabItems[indexPath.row]
        
        if indexPath.row == 0 {
            cell.dotView.isHidden = false
            lastSelectDotView = cell.dotView;
        }
        return cell
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        guard selectIndex != indexPath.row else {
            return
        }
        switch indexPath.row {
        case 0:
            // 每日最美
            type = MenuItemType.dayily
        case 1:
            // 限免推荐
            type = MenuItemType.recommend
        case 2:
            // 发现应用
            type = MenuItemType.findApp
        case 3:
            // 文章专栏
            type = MenuItemType.article
        case 4:
            // 美我一下
            type = MenuItemType.appStoreComment
            if #available(iOS 10.0, *) {
                UIApplication.shared.open(APIConstant.appStoreComment.baseURL, options: [:], completionHandler: nil)
            } else {
                // Fallback on earlier versions
                UIApplication.shared.openURL(APIConstant.appStoreComment.baseURL)
            }
        case 5:
            // 我的收藏
            type = MenuItemType.collect
        default:
            break
        }
        
        if type == MenuItemType.appStoreComment || type == MenuItemType.collect {
            return
        }
        // 回调给Main 刷新页面
        delegate?.menuDidClick(withType: type)
        // 更新圆点位置
        selectIndex = indexPath.row
        lastSelectDotView.isHidden = true
        let cell = tableView.cellForRow(at: indexPath) as! MenuTableViewCell
        cell.dotView.isHidden = false
        lastSelectDotView = cell.dotView
    }
}


extension MenuController: MenuFooterViewDelegate {
    func searchBtnDidClick() {
        
    }
    
    func inviteBtnDidClick() {
        let safaController = SFSafariViewController(url: APIConstant.invite.baseURL)
        present(safaController, animated: true, completion: nil)
    }
    
    func settingBtnDidClick() {
        present(IFBaseNavController(rootViewController:SettingViewController()), animated: true, completion: nil)
    }
}

extension MenuController {
    fileprivate func setupLayout() {
        mainTableView.snp.makeConstraints { (make) in
            make.left.right.top.equalTo(self.view)
            make.height.equalTo(UIConstant.SCREEN_HEIGHT-40)
        }
        
        footerView.snp.makeConstraints { (make) in
            make.left.right.bottom.equalTo(self.view)
            make.height.equalTo(40)
        }
    }
}
