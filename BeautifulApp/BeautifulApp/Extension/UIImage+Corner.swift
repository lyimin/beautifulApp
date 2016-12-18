//
//  UIImage+Nice.swift
//  beautifulApp-Swift3
//
//  Created by 梁亦明 on 16/11/29.
//  Copyright © 2016年 xiaoming.com. All rights reserved.
//

import Foundation


private func roundbyunit(num: Double, _ unit: inout Double) -> Double {
    let remain = modf(num, &unit)
    if (remain > unit / 2.0) {
        return ceilbyunit(num: num, &unit)
    } else {
        return floorbyunit(num: num, &unit)
    }
}

private func ceilbyunit(num: Double, _ unit: inout Double) -> Double {
    return num - modf(num, &unit) + unit
}

private func floorbyunit(num: Double, _ unit: inout Double) -> Double {
    return num - modf(num, &unit)
}

private func pixel(num: Double) -> Double {
    var unit: Double
    switch Int(UIScreen.main.scale) {
    case 1: unit = 1.0 / 1.0
    case 2: unit = 1.0 / 2.0
    case 3: unit = 1.0 / 3.0
    default: unit = 0.0
    }
    return roundbyunit(num: num, &unit)
}

extension UIView {
    func addCorner(radius: CGFloat) {
        self.addCorner(radius: radius, borderWidth: 0, backgroundColor: UIColor.clear, borderColor: UIColor.clear)
    }
    
    func addCorner(radius: CGFloat,
                      borderWidth: CGFloat,
                      backgroundColor: UIColor,
                      borderColor: UIColor) {
        let imageView = UIImageView(image: drawRectWithRoundedCorner(radius: radius,
                                                                        borderWidth: borderWidth,
                                                                        backgroundColor: backgroundColor,
                                                                        borderColor: borderColor))
        self.insertSubview(imageView, at: 0)
    }
    
    func drawRectWithRoundedCorner(radius: CGFloat,
                                      borderWidth: CGFloat,
                                      backgroundColor: UIColor,
                                      borderColor: UIColor) -> UIImage {
        let sizeToFit = CGSize(width: pixel(num: Double(self.bounds.size.width)), height: Double(self.bounds.size.height))
        let halfBorderWidth = CGFloat(borderWidth / 2.0)
        
        UIGraphicsBeginImageContextWithOptions(sizeToFit, false, UIScreen.main.scale)
        let context = UIGraphicsGetCurrentContext()
        
        context?.setLineWidth(borderWidth)
        context?.setStrokeColor(borderColor.cgColor)
        context?.setFillColor(backgroundColor.cgColor)
        
        let width = sizeToFit.width, height = sizeToFit.height
        context?.move(to: CGPoint(x: width - halfBorderWidth, y: radius + halfBorderWidth)) // 开始坐标右边开始
        context?.addArc(tangent1End: CGPoint(x: width - halfBorderWidth, y: height - halfBorderWidth), tangent2End: CGPoint(x: width - radius - halfBorderWidth, y: height - halfBorderWidth), radius: radius) // 右下角角度
        
        context?.addArc(tangent1End: CGPoint(x: halfBorderWidth, y: height - halfBorderWidth), tangent2End: CGPoint(x: halfBorderWidth, y: height - radius - halfBorderWidth), radius: radius) // 左下角角度
        
        context?.addArc(tangent1End: CGPoint(x: halfBorderWidth, y: halfBorderWidth), tangent2End: CGPoint(x: width - halfBorderWidth, y: halfBorderWidth), radius: radius) // 左上角
        
        context?.addArc(tangent1End: CGPoint(x: width - halfBorderWidth, y: halfBorderWidth), tangent2End: CGPoint(x: width - halfBorderWidth, y: radius + halfBorderWidth), radius: radius)
//        UIGraphicsGetCurrentContext()?.clip()
        UIGraphicsGetCurrentContext()?.drawPath(using: .fillStroke)
        let output = UIGraphicsGetImageFromCurrentImageContext()
        UIGraphicsEndImageContext()
        return output!
    }
}

extension UIImageView {
    override func addCorner(radius: CGFloat) {
        self.image = self.image?.drawRectWithRoundedCorner(radius: radius, self.bounds.size)
    }
}

extension UIImage {
    func drawRectWithRoundedCorner(radius: CGFloat, _ sizetoFit: CGSize) -> UIImage {
        let rect = CGRect(origin: CGPoint(x: 0, y: 0), size: sizetoFit)
        
        UIGraphicsBeginImageContextWithOptions(rect.size, false, UIScreen.main.scale)
        UIGraphicsGetCurrentContext()!.addPath(UIBezierPath(roundedRect: rect, byRoundingCorners: UIRectCorner.allCorners,
                                      cornerRadii: CGSize(width: radius, height: radius)).cgPath)
        UIGraphicsGetCurrentContext()?.clip()
        
        self.draw(in: rect)
//        UIGraphicsGetCurrentContext()!.drawPath(using: .fillStroke)
        let output = UIGraphicsGetImageFromCurrentImageContext()
        UIGraphicsEndImageContext()
        
        return output!
    }
}

