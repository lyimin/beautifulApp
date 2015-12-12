//
//  MOBFRegex.h
//  MOBFoundation
//
//  Created by vimfung on 15-1-20.
//  Copyright (c) 2015年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  替换处理
 *
 *  @param captureCount    捕获数量
 *  @param capturedStrings 捕获字符串集合
 *  @param capturedRanges  捕获字符串范围集合
 *  @param stop            是否停止捕获标识
 *
 *  @return 替换后的字符串
 */
typedef NSString *(^MOBFReplacingOccurrencesHandler) (NSInteger captureCount, NSString *const capturedStrings[captureCount], const NSRange capturedRanges[captureCount], volatile BOOL * const stop);

/**
 *  正则表达式选项
 */
typedef NS_ENUM(NSUInteger, MOBFRegexOptions){
    /**
     *  无设置
     */
    MOBFRegexOptionsNoOptions             = 0,
    /**
     *  不区分大小写
     */
    MOBFRegexOptionsCaseless              = 2,
    /**
     *  注释
     */
    MOBFRegexOptionsComments              = 4,
    /**
     *  匹配点
     */
    MOBFRegexOptionsDotAll                = 32,
    /**
     *  多行模式
     */
    MOBFRegexOptionsMultiline             = 8,
    /**
     *  Unicode字符
     */
    MOBFRegexOptionsUnicodeWordBoundaries = 256
};

/**
 *  正则表达式工具类
 */
@interface MOBFRegex : NSObject

/**
 *  替换字符串
 *
 *  @param regex    正则表达式
 *  @param string   原始字符串
 *  @param block    块回调处理替换规则
 *
 *  @return 字符串
 */
+ (NSString *)stringByReplacingOccurrencesOfRegex:(NSString *)regex
                                       withString:(NSString *)string
                                       usingBlock:(MOBFReplacingOccurrencesHandler)block;

/**
 *  匹配字符串
 *
 *  @param regex    正则表达式
 *  @param options  表达式选项
 *  @param range    匹配范围
 *  @param string   原始字符串
 *
 *  @return YES 匹配，NO 不匹配
 */
+ (BOOL)isMatchedByRegex:(NSString *)regex
                 options:(MOBFRegexOptions)options
                 inRange:(NSRange)range
              withString:(NSString *)string;

/**
 *  匹配字符串
 *
 *  @param regex 正则表达式
 *  @param string   原始字符串
 *
 *  @return 匹配的字符串集合
 */
+ (NSArray *)captureComponentsMatchedByRegex:(NSString *)regex
                                  withString:(NSString *)string;

@end
