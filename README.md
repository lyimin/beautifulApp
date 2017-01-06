<p align="center">
<a href="#截图">截图</a> -
<a href="#第三方库">第三方库</a> -
<a href="#UI">UI</a> -
<a href="#Networking">Networking</a> -
<a href="#更新日志">更新日志</a>
</p>

<p align="center">
<a href="https://developer.apple.com/swift"><img src="https://img.shields.io/badge/language-Swift3-orange.svg"></a>
<a href="https://developer.apple.com/ios"><img src="https://img.shields.io/badge/platform-iOS9-blue.svg?style=flat"></a>
<a href="https://https://github.com/lyimin/beautifulApp/blob/develop/LICENSE"><img src="http://img.shields.io/badge/license-MIT-lightgrey.svg?style=flat"></a>
</p>

# 最美应用 - Swift3
  
## 截图

<img src="https://github.com/lyimin/beautifulApp/blob/master/BeautifulApp/BeautifulApp/Resources/1.gif" width="30%" height="30%" />

![](https://github.com/lyimin/beautifulApp/blob/master/BeautifulApp/BeautifulApp/Resources/2.gif)

![](https://github.com/lyimin/beautifulApp/blob/master/BeautifulApp/BeautifulApp/Resources/3.gif)

## 第三方库

- ![Alamofire](https://github.com/Alamofire/Alamofire)      网络请求
- ![Moya](https://github.com/Moya/Moya)                     与Alamofire结合完成网络请求，爽0.0
- ![SnapKit](https://github.com/SnapKit/SnapKit)            屏幕适配
- ![YYWebImage](https://github.com/ibireme/YYWebImage)      图片加载

## UI

UI采用纯代码编写+![SnapKit](https://github.com/SnapKit/SnapKit)屏幕适配

- 目录结构分析
  - Controllers    : 控制器文件
  - Views          : View文件
  - Models         : 模型文件
  - Extensions     : 一些分类扩展
  - Constant       : 常量
  - Other          : 工具类和第三方库
  - Resources      : 资源文件
  - Services       : API服务
  
## Networking

网络请求是采用![Alamofire](https://github.com/Alamofire/Alamofire)+![Moya](https://github.com/Moya/Moya),只需要创建一个`enum`去实现`Moya`的`TargetType`协议，然后配置`URL`和`parameters`等即可完成网络请求。详情可以看![APIConstant.swift](https://github.com/lyimin/beautifulApp/blob/master/BeautifulApp/BeautifulApp/Constant/APIConstant.swift)


## 更新日志
- 加入分享第三方库Monkeyking                       ----- 2017-01-06
- 解决点击设置返回崩溃问题                          ----- 2017-01-03
- 完成Swift3大致功能的迁移，优化和重构目录结构              ----- 2016-12-18
- 配置好网络请求库（moya+alamofire）     ----- 2016-11-15
- 初步完成首页view的结构       ----- 2016-11-13
- 准备用Swift3重写一般，更Swifty   ----- 2016-10-26
- 提高一些圆角造成的性能问题，swift2.x后的一些警告，添加详情页手势返回   ----- 2016-07-07
- 1.修复每日最美详情页的XML解析错误问题,2.优化代码 ----- 2015-12-22
