//
//  SSLog.h
//  ShareSDK
//
//  Created by 冯 鸿杰 on 13-11-26.
//  Copyright (c) 2013年 掌淘科技. All rights reserved.
//

#ifndef ShareSDK_SSLogDef_h
#define ShareSDK_SSLogDef_h

#ifdef DEBUG
    #define SS_DEBUG(...)   NSLog(__VA_ARGS__)
    #define SS_INFO(msg)    NSLog(@"#info:%@", msg)
    #define SS_WARNING(msg)    NSLog(@"#warning:%@", msg)
    #define SS_ERROR(msg)   NSLog(@"#error:%@", msg)
#else
    #define SS_DEBUG(...)   {}
    #define SS_INFO(msg)    NSLog(@"#info:%@", msg)
    #define SS_WARNING(msg)    NSLog(@"#warning:%@", msg)
    #define SS_ERROR(msg)   NSLog(@"#error:%@", msg)
#endif

#endif
