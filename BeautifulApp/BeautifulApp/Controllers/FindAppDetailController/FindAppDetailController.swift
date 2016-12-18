//
//  FindAppDetailController.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/12/1.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class FindAppDetailController: UIViewController {
    
    //MARK: --------------------------- Life Cycle --------------------------
    override func viewDidLoad() {
        super.viewDidLoad()
        self.view.backgroundColor = UIColor.white
        self.automaticallyAdjustsScrollViewInsets = false
        
        centerView.dataModel = model
        self.view.addSubview(centerView)
        
        // 中间工具条
        self.view.addSubview(toolBarView)
        
        // 底部工具条
        self.view.addSubview(bottomView)
        
        // 返回按钮
        self.view.addSubview(returnBtn)
        // 屏幕适配
        self.setLayout()
        
        self.centerView.footerViewPullToRefresh(direction: .XMRefreshDirectionVertical) { [unowned self]() -> Void in
            self.getCommentData()
        }
    }
    
    convenience init(model: FindAppModel) {
        self.init()
        self.model = model
    }
    
    // MARK: - Event Aciton
    func returnBtnDidClick() {
        self.navigationController?.popViewController(animated: true)
    }

    
    //MARK: --------------------------- Getter and Setter --------------------------
    // 模型
    fileprivate var model: FindAppModel!
    fileprivate lazy var centerView : FindAppDetailCenterView = {
        let centerView = FindAppDetailCenterView(frame: self.view.bounds)
        centerView.delegate = self
        return centerView
    }()
    
    fileprivate lazy var bottomView: XMHomeDetailBottomView = {
        let bottomView = XMHomeDetailBottomView()
        return bottomView
    }()
    
    fileprivate lazy var toolBarView: FindAppDetailToolView = {
        let toolBarView = FindAppDetailToolView.toolView()
        toolBarView.frame = CGRect(x: 0, y: 155, width: UIConstant.SCREEN_WIDTH, height: toolBarView.height)
        toolBarView.delegate = self
        return toolBarView
    }()
    
    // 返回按钮
    fileprivate lazy var returnBtn : UIButton = {
        let returnBtn : UIButton = UIButton()
        returnBtn.frame = CGRect(x: UIConstant.MARGIN_20, y: 30, width: 30, height: 30)
        returnBtn.addTarget(self, action: #selector(FindAppDetailController.returnBtnDidClick), for: .touchUpInside)
        returnBtn.setImage(UIImage(named: "detail_icon_back_normal"), for: .normal)
        returnBtn.setImage(UIImage(named: "detail_icon_back_pressed"), for: .highlighted)
        return returnBtn
    }()
    
    

}

extension FindAppDetailController: UIScrollViewDelegate {
    func scrollViewDidScroll(_ scrollView: UIScrollView) {
        if scrollView.contentOffset.y >= 125 {
            self.toolBarView.y = 30
            // 显示在标题栏动画
            XMFindAppDetailAnimationUtil.toolBarToNavAnimation(toolView: toolBarView)
            
        } else {
            self.toolBarView.y = 155 - scrollView.contentOffset.y
            XMFindAppDetailAnimationUtil.toolBarToScrollAnimation(toolView: toolBarView)
        }
    }
}

extension FindAppDetailController: FindAppDetailToolViewDelegate {
    internal func downloadBtnClick() {
        let downModel = model.download_urls.first!
        if #available(iOS 10.0, *) {
            UIApplication.shared.open(URL(string: downModel.url)!, options: [:], completionHandler: nil)
        } else {
            // Fallback on earlier versions
            UIApplication.shared.openURL(URL(string: downModel.url)!)
        }
    }

    internal func shareBtnClick() {
        
    }
}
//MARK: --------------------------- Private Methods --------------------------
extension FindAppDetailController {
    fileprivate func setLayout () {
        bottomView.snp.makeConstraints { (make) -> Void in
            make.left.right.bottom.equalTo(self.view)
            make.height.equalTo(40)
        }
    }
    
    /**
     * 获取评论数据
     */
    fileprivate func getCommentData() {
        // 获取上一条
        guard model.comments.count != 0 else {
            self.centerView.footerEndRefreshing()
            return
        }
        let lastCommentModel = model.comments.last!
        
        niceProvider.request(APIConstant.findAppComment(lastCommentModel.app_id, lastCommentModel.id), completion: { result in
            switch result {
            case let .success(response):
                do {
                    let json = try response.mapJSON() as! NSDictionary
                    
                    guard let content = json["data"] as? NSDictionary else {
                        return
                    }
                    guard let contentArray = content["comments"] as? Array<NSDictionary>  else {
                        return
                    }
                    
                    if contentArray.count != 0 {
                        // 添加评论到模型
                        var commentArray : Array<CommentModel> = Array()
                        for dict in contentArray {
                            let model = CommentModel(dict: dict )
                            self.model.comments.append(model)
                            commentArray.append(model)
                        }
                        self.centerView.setCommentData(comments: commentArray)
                    }
                    self.centerView.footerEndRefreshing()
                } catch {
                    print("数据异常")
                    self.centerView.footerEndRefreshing()
                }
                
            default:
                break
            }
        })
    }
}
