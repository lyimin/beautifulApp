//
//  MBProgressHUD+XM.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/28.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit
extension MBProgressHUD {
    class func showMessage(message : String) -> MBProgressHUD {
        let view = UIApplication.sharedApplication().keyWindow
        let hud = MBProgressHUD.showHUDAddedTo(view, animated: true)
        hud.labelText = message
        hud.dimBackground = true
        hud.removeFromSuperViewOnHide = true
        return hud
    }
    
    class func show (text : String, icon : String, var view : UIView?) {
        if view == nil {
            view = UIApplication.sharedApplication().keyWindow
        }
        
        let hud = MBProgressHUD.showHUDAddedTo(view, animated: true)
        hud.labelText = text
        hud.customView = UIImageView(image: UIImage(named: "MBProgressHUD.bundle/\(icon)"))
        hud.mode = MBProgressHUDMode.CustomView
        hud.removeFromSuperViewOnHide = true
        hud.hide(true, afterDelay: 1)
    }
    
    class func showSuccessMessage (message : String) {
        self.show(message, icon: "success.png", view: nil)
    }
}