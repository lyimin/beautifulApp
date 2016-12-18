//
//  SettingViewCell.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/27.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class SettingViewCell: UITableViewCell,Reusable {
    
    @IBOutlet weak var iconView: UIImageView!
    
    @IBOutlet weak var itemLabel: UILabel!
    static let SettingViewCellID = "SettingViewCellID"
    
    var data : NSDictionary! {
        willSet {
            self.data = newValue
        }
        
        didSet {
            self.iconView.image = UIImage(named: data.object(forKey: "icon") as! String)
            self.itemLabel.text = data.object(forKey: "text") as? String
        }
    }
    
    class func cellWithTableView(tableView : UITableView) -> SettingViewCell {
        var cell : SettingViewCell? = tableView.dequeueReusableCell()
        if cell == nil {
            cell = Bundle.main.loadNibNamed("SettingViewCell", owner: nil, options: nil)?.first as! SettingViewCell?
        }

        return cell!
    }

    override func awakeFromNib() {
        super.awakeFromNib()
        
    }

}
