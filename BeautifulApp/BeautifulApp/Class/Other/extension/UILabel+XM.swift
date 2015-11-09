//
//  UILabel+XM.swift
//  BeautifulApp
//
//  Created by 梁亦明 on 15/11/8.
//  Copyright © 2015年 xiaoming. All rights reserved.
//

import UIKit

extension UILabel  {

    func textLeftTopAlign(width : CGFloat, font : UIFont) {
        let style : NSMutableParagraphStyle = NSMutableParagraphStyle()
        style.lineBreakMode = NSLineBreakMode.ByWordWrapping
        
        let attributes = [NSFontAttributeName : font, NSParagraphStyleAttributeName : style.copy()]
        let labelSize = (self.text! as NSString).boundingRectWithSize(CGSize(width: width, height: CGFloat(999)), options: .UsesLineFragmentOrigin, attributes: attributes, context: nil)
        
        let rect = CGRectMake(self.x, self.y, labelSize.width, labelSize.height)
        self.frame = rect
    }

}
//- (void) textLeftTopAlign
//7
//    {
//        8
//        NSMutableParagraphStyle *paragraphStyle = [[NSMutableParagraphStyle alloc]init];
//        9
//        paragraphStyle.lineBreakMode = NSLineBreakByWordWrapping;
//        10
//        
//        11
//        NSDictionary *attributes = @{NSFontAttributeName:[UIFont systemFontOfSize:12.f], NSParagraphStyleAttributeName:paragraphStyle.copy};
//        12
//        
//        13
//        CGSize labelSize = [self.text boundingRectWithSize:CGSizeMake(207, 999) options:NSStringDrawingUsesLineFragmentOrigin attributes:attributes context:nil].size;
//        14
//        
//        15
//        CGRect dateFrame =CGRectMake(2, 140, CGRectGetWidth(self.frame)-5, labelSize.height);
//        16
//        self.frame = dateFrame;
//        17
//}