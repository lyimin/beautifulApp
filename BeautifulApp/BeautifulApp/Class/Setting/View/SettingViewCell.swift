//
//  SettingViewCell.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/27.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class SettingViewCell: UITableViewCell {
    
    @IBOutlet weak var iconView: UIImageView!
    
    @IBOutlet weak var itemLabel: UILabel!
    static let SettingViewCellID = "SettingViewCellID"
    
    var data : NSDictionary! {
        willSet {
            self.data = newValue
        }
        
        didSet {
            self.iconView.image = UIImage(named: data.objectForKey("icon") as! String)
            self.itemLabel.text = data.objectForKey("text") as? String
        }
    }
    
    class func cellWithTableView(tableView : UITableView) -> SettingViewCell {
        var cell : SettingViewCell? = tableView.dequeueReusableCellWithIdentifier(SettingViewCellID) as? SettingViewCell
        if cell == nil {
            cell = NSBundle.mainBundle().loadNibNamed("SettingViewCell", owner: nil, options: nil).first as? SettingViewCell
        }
//        cell!.accessoryType = UITableViewCellAccessoryType.DisclosureIndicator
        return cell!
    }

    override func awakeFromNib() {
        super.awakeFromNib()
        
    }

}
