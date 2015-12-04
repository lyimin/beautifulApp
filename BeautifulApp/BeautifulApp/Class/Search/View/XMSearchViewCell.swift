//
//  XMSearchViewCell.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/30.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

class XMSearchViewCell: UITableViewCell {
    static let XMSearchViewCellID : String = "XMSearchViewCellID"
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }
    class func cellWithTableView(tableView : UITableView) -> XMSearchViewCell {
        var cell : XMSearchViewCell? = tableView.dequeueReusableCellWithIdentifier(XMSearchViewCellID) as? XMSearchViewCell
        
        if cell == nil {
            cell = NSBundle.mainBundle().loadNibNamed("XMSearchViewCell", owner: nil, options: nil).first as? XMSearchViewCell
        }
        
        return cell!
    }

}
