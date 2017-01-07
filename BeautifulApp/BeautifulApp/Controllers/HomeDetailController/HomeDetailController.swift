//
//  HomeDetailController.swift
//  beautifulApp-Swift3
//
//  Created by 梁亦明 on 2016/12/5.
//  Copyright © 2016年 xiaoming.com. All rights reserved.
//

import Foundation
import Moya
import RxSwift

class HomeDetailController: UIViewController {
    
    //MARK: --------------------------- Life Cycle --------------------------
    override func viewDidLoad() {
        super.viewDidLoad()
        self.view.backgroundColor = UIColor.white
        self.view.addSubview(centerView)
        self.topImageView = centerView.headerImgView
        // 工具条
        self.view.addSubview(toolBar)
        // 返回按钮
        self.view.addSubview(backBtn)
        // 底部评论view
        self.view.addSubview(bottomView)
        
        self.view.bringSubview(toFront: bottomView)
        // 下拉刷新
        self.centerView.footerViewPullToRefresh(direction: XMRefreashDirection.XMRefreshDirectionVertical) { [unowned self]() -> Void in
            self.getCommentData()
        }
        
        // 屏幕适配
        self.setupLayout()
    }
    
    convenience init(model: HomeModel) {
        self.init()
        self.model = model
        centerView.model = model
        
    }
    
    //MARK: --------------------------- Getter and Setter --------------------------
    var shadowView: UIView?
    var shareView: ShareView?
    // 模型
    fileprivate var model: HomeModel!
    // 评论page
    fileprivate var page: Int = 1
    // 顶部图片
    weak var topImageView : UIImageView!
    
    // scrollview
    fileprivate lazy var centerView: HomeDetailCenterView = {
        let centerView = HomeDetailCenterView()
        centerView.frame = CGRect(x: 0, y: 0, width: UIConstant.SCREEN_WIDTH, height: UIConstant.SCREEN_HEIGHT)
        centerView.delegate = self
        centerView.centerDelegate = self
        return centerView
    }()
    // 返回按钮
    fileprivate lazy var backBtn : UIButton = {
        let backBtn : UIButton = UIButton()
        backBtn.addTarget(self, action: #selector(HomeDetailController.backBtnDidClick), for: .touchUpInside)
        backBtn.setImage(UIImage(named: "detail_icon_back_normal"), for: .normal)
        backBtn.setImage(UIImage(named: "detail_icon_back_pressed"), for: .highlighted)
        return backBtn
    }()
    
    // 工具条
    fileprivate lazy var toolBar: XMHomeDetailToolView = {
        let toolBar : XMHomeDetailToolView = XMHomeDetailToolView.toolView()
        toolBar.frame = CGRect(x: 0, y: 245, width: UIConstant.SCREEN_WIDTH, height: 30)
        toolBar.delegate = self
        return toolBar
    }()
    
    // 评论栏
    fileprivate lazy var bottomView : XMHomeDetailBottomView = {
        let bottomView : XMHomeDetailBottomView = XMHomeDetailBottomView()
        return bottomView
    }()

}
//MARK: --------------------------- UIScrollViewDelegate --------------------------
extension HomeDetailController: UIScrollViewDelegate {
    func scrollViewDidScroll(_ scrollView: UIScrollView) {
        self.centerView.updateHeaderView()
        if scrollView.contentOffset.y >= 215 {
            self.toolBar.y = self.backBtn.y
            // 显示在标题栏动画
            XMHomeDetailAnimationUtil.homeDetailToolBarToNavAnimation(toolView: self.toolBar)
            
            
        } else {
            self.toolBar.y = 245 - scrollView.contentOffset.y
            XMHomeDetailAnimationUtil.homeDetailToolBarToScrollAnimation(toolView: self.toolBar)
        }
    }
}

//MARK: --------------------------- HomeDetailCenterViewDelegate --------------------------

extension HomeDetailController: HomeDetailCenterViewDelegate {
    func shareBtnDidClick() {
        showShareView()
    }
    
    func backBtnDidClick() {
        self.navigationController?.popViewController(animated: true)
    }
}

extension HomeDetailController: XMHomeDetailToolViewDelegate {
    // 点击收藏
    func homeDetailToolViewCollectBtnClick() {
        
    }
    
    // 点击下载
    func homeDetailToolViewDownloadBtnClick() {
        UIApplication.shared.openURL(URL(string: model.download_url!)!)
    }
    
    // 点击分享
    func homeDetailToolViewShareBtnClick() {
        showShareView()
    }
}

extension HomeDetailController: shareResuable {
    // 微信朋友
    func weixinShareButtonDidClick() {
        do {
            let image = try UIImage(data: Data(contentsOf: URL(string: model.icon_image)!))
            guard image != nil else {
                return
            }
            shareToFriend(shareContent: model.digest, shareImage: image!, shareUrl: model.video_share_url, shareTitle: model.title)
        } catch {
            print("图片发生异常")
        }
        
    }
    // 朋友圈
    func friendsCircleShareButtonDidClick() {
        do {
            let image = try UIImage(data: Data(contentsOf: URL(string: model.icon_image)!))
            guard image != nil else {
                return
            }
            shareToFriendsCircle(shareContent: model.digest, shareTitle: model.title, shareUrl: model.video_share_url, shareImage: image!)
        } catch {
            print("图片发生异常")
        }
    }
    // 更多
    func shareMoreButtonDidClick() {
        hiddenShareView()
    }
}

//MARK: --------------------------- Private Methods --------------------------
extension HomeDetailController {
    // MARK: - Private Methods
    fileprivate func getCommentData() {
        print("\(self.model.id!)")
        niceProvider.request(APIConstant.comment(self.model.id!, self.page), completion: { result in
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
                        self.page = self.page + 1;
                        self.centerView.setCommentData(comments: commentArray)
                    }
                    
                } catch {
                    print("数据异常")
                }

                default:
                break
            }
        })
    }
    
    // 适配屏幕
    fileprivate func setupLayout() {
        
        backBtn.snp.makeConstraints { (make) in
            make.left.equalTo(self.view.snp.left).offset(10)
            make.top.equalTo(self.view.snp.top).offset(40)
            make.width.equalTo(30)
            make.height.equalTo(30)
        }
        

        bottomView.snp.makeConstraints { (make) in
            make.left.right.bottom.equalTo(self.view)
            make.height.equalTo(40)
        }
    }
}
