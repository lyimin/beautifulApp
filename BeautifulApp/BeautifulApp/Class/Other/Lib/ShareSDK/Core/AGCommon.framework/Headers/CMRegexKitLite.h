//
//  RegexKitLite.h
//  http://regexkit.sourceforge.net/
//  Licensed under the terms of the BSD License, as specified below.
//

#ifdef    __OBJC__
#import <Foundation/NSArray.h>
#import <Foundation/NSError.h>
#import <Foundation/NSObjCRuntime.h>
#import <Foundation/NSRange.h>
#import <Foundation/NSString.h>
#endif // __OBJC__

#include <limits.h>
#include <stdint.h>
#include <sys/types.h>
#include <TargetConditionals.h>
#include <AvailabilityMacros.h>

#ifdef __cplusplus
extern "C" {
#endif
  
#ifndef   AG_REGEXKITLITE_VERSION_DEFINED
#define   AG_REGEXKITLITE_VERSION_DEFINED

#define _AG_RKL__STRINGIFY(b)       #b
#define _AG_RKL_STRINGIFY(a)        _AG_RKL__STRINGIFY(a)
#define _AG_RKL_JOIN_VERSION(a,b)   _AG_RKL_STRINGIFY(a##.##b)
#define _AG_RKL_VERSION_STRING(a,b) _AG_RKL_JOIN_VERSION(a,b)

#define AG_REGEXKITLITE_VERSION_MAJOR 4
#define AG_REGEXKITLITE_VERSION_MINOR 0

#define AG_REGEXKITLITE_VERSION_CSTRING   _AG_RKL_VERSION_STRING(AG_REGEXKITLITE_VERSION_MAJOR, AG_REGEXKITLITE_VERSION_MINOR)
#define AG_REGEXKITLITE_VERSION_NSSTRING  @AG_REGEXKITLITE_VERSION_CSTRING

#endif // AG_REGEXKITLITE_VERSION_DEFINED

#if !defined(AG_RKL_BLOCKS) && defined(NS_BLOCKS_AVAILABLE) && (NS_BLOCKS_AVAILABLE == 1)
#define AG_RKL_BLOCKS 1
#endif
  
#if       defined(AG_RKL_BLOCKS) && (AG_RKL_BLOCKS == 1)
#define _AG_RKL_BLOCKS_ENABLED 1
#endif // defined(AG_RKL_BLOCKS) && (AG_RKL_BLOCKS == 1)

#if       defined(_AG_RKL_BLOCKS_ENABLED) && !defined(__BLOCKS__)
#warning RegexKitLite support for Blocks is enabled, but __BLOCKS__ is not defined.  This compiler may not support Blocks, in which case the behavior is undefined.  This will probably cause numerous compiler errors.
#endif // defined(_AG_RKL_BLOCKS_ENABLED) && !defined(__BLOCKS__)

// For Mac OS X < 10.5.
#ifndef   NSINTEGER_DEFINED
#define   NSINTEGER_DEFINED
#if       defined(__LP64__) || defined(NS_BUILD_32_LIKE_64)
typedef long           NSInteger;
typedef unsigned long  NSUInteger;
#define NSIntegerMin   LONG_MIN
#define NSIntegerMax   LONG_MAX
#define NSUIntegerMax  ULONG_MAX
#else  // defined(__LP64__) || defined(NS_BUILD_32_LIKE_64)
typedef int            NSInteger;
typedef unsigned int   NSUInteger;
#define NSIntegerMin   INT_MIN
#define NSIntegerMax   INT_MAX
#define NSUIntegerMax  UINT_MAX
#endif // defined(__LP64__) || defined(NS_BUILD_32_LIKE_64)
#endif // NSINTEGER_DEFINED

#ifndef   AG_RKLREGEXOPTIONS_DEFINED
#define   AG_RKLREGEXOPTIONS_DEFINED

// These must be identical to their ICU regex counterparts. See http://www.icu-project.org/userguide/regexp.html
enum {
  CMRKLNoOptions             = 0,
  CMRKLCaseless              = 2,
  CMRKLComments              = 4,
  CMRKLDotAll                = 32,
  CMRKLMultiline             = 8,
  CMRKLUnicodeWordBoundaries = 256
};
typedef uint32_t AG_RKLRegexOptions; // This must be identical to the ICU 'flags' argument type.

#endif // AG_RKLREGEXOPTIONS_DEFINED

#ifndef   AG_RKLREGEXENUMERATIONOPTIONS_DEFINED
#define   AG_RKLREGEXENUMERATIONOPTIONS_DEFINED

enum {
  CMRKLRegexEnumerationNoOptions                               = 0UL,
  CMRKLRegexEnumerationCapturedStringsNotRequired              = 1UL << 9,
  CMRKLRegexEnumerationReleaseStringReturnedByReplacementBlock = 1UL << 10,
  CMRKLRegexEnumerationFastCapturedStringsXXX                  = 1UL << 11,
};
typedef NSUInteger AG_RKLRegexEnumerationOptions;
  
#endif // AG_RKLREGEXENUMERATIONOPTIONS_DEFINED

#ifndef _AG_REGEXKITLITE_H_
#define _AG_REGEXKITLITE_H_

#if defined(__GNUC__) && (__GNUC__ >= 4) && defined(__APPLE_CC__) && (__APPLE_CC__ >= 5465)
#define AG_RKL_DEPRECATED_ATTRIBUTE __attribute__((deprecated))
#else
#define AG_RKL_DEPRECATED_ATTRIBUTE
#endif

#if       defined(NS_REQUIRES_NIL_TERMINATION)
#define AG_RKL_REQUIRES_NIL_TERMINATION NS_REQUIRES_NIL_TERMINATION
#else  // defined(NS_REQUIRES_NIL_TERMINATION)
#define AG_RKL_REQUIRES_NIL_TERMINATION
#endif // defined(NS_REQUIRES_NIL_TERMINATION)
  
// This requires a few levels of rewriting to get the desired results.
#define _AG_RKL_CONCAT_2(c,d) c ## d
#define _AG_RKL_CONCAT(a,b) _AG_RKL_CONCAT_2(a,b)
  
#ifdef    AG_RKL_PREPEND_TO_METHODS
#define AG_RKL_METHOD_PREPEND(x) _AG_RKL_CONCAT(AG_RKL_PREPEND_TO_METHODS, x)
#else  // AG_RKL_PREPEND_TO_METHODS
#define AG_RKL_METHOD_PREPEND(x) x
#endif // AG_RKL_PREPEND_TO_METHODS
  
// If it looks like low memory notifications might be available, add code to register and respond to them.
// This is (should be) harmless if it turns out that this isn't the case, since the notification that we register for,
// UIApplicationDidReceiveMemoryWarningNotification, is dynamically looked up via dlsym().
#if ((defined(TARGET_OS_EMBEDDED) && (TARGET_OS_EMBEDDED != 0)) || (defined(TARGET_OS_IPHONE) && (TARGET_OS_IPHONE != 0))) && (!defined(AG_RKL_REGISTER_FOR_IPHONE_LOWMEM_NOTIFICATIONS) || (AG_RKL_REGISTER_FOR_IPHONE_LOWMEM_NOTIFICATIONS != 0))
#define AG_RKL_REGISTER_FOR_IPHONE_LOWMEM_NOTIFICATIONS 1
#endif

#ifdef __OBJC__

// NSException exception name.
extern NSString * const CMRKLICURegexException;

// NSError error domains and user info keys.
extern NSString * const CMRKLICURegexErrorDomain;

extern NSString * const CMRKLICURegexEnumerationOptionsErrorKey;
extern NSString * const CMRKLICURegexErrorCodeErrorKey;
extern NSString * const CMRKLICURegexErrorNameErrorKey;
extern NSString * const CMRKLICURegexLineErrorKey;
extern NSString * const CMRKLICURegexOffsetErrorKey;
extern NSString * const CMRKLICURegexPreContextErrorKey;
extern NSString * const CMRKLICURegexPostContextErrorKey;
extern NSString * const CMRKLICURegexRegexErrorKey;
extern NSString * const CMRKLICURegexRegexOptionsErrorKey;
extern NSString * const CMRKLICURegexReplacedCountErrorKey;
extern NSString * const CMRKLICURegexReplacedStringErrorKey;
extern NSString * const CMRKLICURegexReplacementStringErrorKey;
extern NSString * const CMRKLICURegexSubjectRangeErrorKey;
extern NSString * const CMRKLICURegexSubjectStringErrorKey;
  
@interface NSString (RegexKitLiteAdditions)

+ (void)AG_RKL_METHOD_PREPEND(clearStringCache);

// Although these are marked as deprecated, a bug in GCC prevents a warning from being issues for + class methods.  Filed bug with Apple, #6736857.
+ (NSInteger)AG_RKL_METHOD_PREPEND(captureCountForRegex):(NSString *)regex AG_RKL_DEPRECATED_ATTRIBUTE;
+ (NSInteger)AG_RKL_METHOD_PREPEND(captureCountForRegex):(NSString *)regex options:(AG_RKLRegexOptions)options error:(NSError **)error AG_RKL_DEPRECATED_ATTRIBUTE;

- (NSArray *)AG_RKL_METHOD_PREPEND(componentsSeparatedByRegex):(NSString *)regex;
- (NSArray *)AG_RKL_METHOD_PREPEND(componentsSeparatedByRegex):(NSString *)regex range:(NSRange)range;
- (NSArray *)AG_RKL_METHOD_PREPEND(componentsSeparatedByRegex):(NSString *)regex options:(AG_RKLRegexOptions)options range:(NSRange)range error:(NSError **)error;

- (BOOL)AG_RKL_METHOD_PREPEND(isMatchedByRegex):(NSString *)regex;
- (BOOL)AG_RKL_METHOD_PREPEND(isMatchedByRegex):(NSString *)regex inRange:(NSRange)range;
- (BOOL)AG_RKL_METHOD_PREPEND(isMatchedByRegex):(NSString *)regex options:(AG_RKLRegexOptions)options inRange:(NSRange)range error:(NSError **)error;

- (NSRange)AG_RKL_METHOD_PREPEND(rangeOfRegex):(NSString *)regex;
- (NSRange)AG_RKL_METHOD_PREPEND(rangeOfRegex):(NSString *)regex capture:(NSInteger)capture;
- (NSRange)AG_RKL_METHOD_PREPEND(rangeOfRegex):(NSString *)regex inRange:(NSRange)range;
- (NSRange)AG_RKL_METHOD_PREPEND(rangeOfRegex):(NSString *)regex options:(AG_RKLRegexOptions)options inRange:(NSRange)range capture:(NSInteger)capture error:(NSError **)error;

- (NSString *)AG_RKL_METHOD_PREPEND(stringByMatching):(NSString *)regex;
- (NSString *)AG_RKL_METHOD_PREPEND(stringByMatching):(NSString *)regex capture:(NSInteger)capture;
- (NSString *)AG_RKL_METHOD_PREPEND(stringByMatching):(NSString *)regex inRange:(NSRange)range;
- (NSString *)AG_RKL_METHOD_PREPEND(stringByMatching):(NSString *)regex options:(AG_RKLRegexOptions)options inRange:(NSRange)range capture:(NSInteger)capture error:(NSError **)error;

- (NSString *)AG_RKL_METHOD_PREPEND(stringByReplacingOccurrencesOfRegex):(NSString *)regex withString:(NSString *)replacement;
- (NSString *)AG_RKL_METHOD_PREPEND(stringByReplacingOccurrencesOfRegex):(NSString *)regex withString:(NSString *)replacement range:(NSRange)searchRange;
- (NSString *)AG_RKL_METHOD_PREPEND(stringByReplacingOccurrencesOfRegex):(NSString *)regex withString:(NSString *)replacement options:(AG_RKLRegexOptions)options range:(NSRange)searchRange error:(NSError **)error;

  //// >= 3.0

- (NSInteger)AG_RKL_METHOD_PREPEND(captureCount);
- (NSInteger)AG_RKL_METHOD_PREPEND(captureCountWithOptions):(AG_RKLRegexOptions)options error:(NSError **)error;

- (BOOL)AG_RKL_METHOD_PREPEND(isRegexValid);
- (BOOL)AG_RKL_METHOD_PREPEND(isRegexValidWithOptions):(AG_RKLRegexOptions)options error:(NSError **)error;

- (void)AG_RKL_METHOD_PREPEND(flushCachedRegexData);

- (NSArray *)AG_RKL_METHOD_PREPEND(componentsMatchedByRegex):(NSString *)regex;
- (NSArray *)AG_RKL_METHOD_PREPEND(componentsMatchedByRegex):(NSString *)regex capture:(NSInteger)capture;
- (NSArray *)AG_RKL_METHOD_PREPEND(componentsMatchedByRegex):(NSString *)regex range:(NSRange)range;
- (NSArray *)AG_RKL_METHOD_PREPEND(componentsMatchedByRegex):(NSString *)regex options:(AG_RKLRegexOptions)options range:(NSRange)range capture:(NSInteger)capture error:(NSError **)error;


- (NSArray *)AG_RKL_METHOD_PREPEND(captureComponentsMatchedByRegex):(NSString *)regex;
- (NSArray *)AG_RKL_METHOD_PREPEND(captureComponentsMatchedByRegex):(NSString *)regex range:(NSRange)range;
- (NSArray *)AG_RKL_METHOD_PREPEND(captureComponentsMatchedByRegex):(NSString *)regex options:(AG_RKLRegexOptions)options range:(NSRange)range error:(NSError **)error;

- (NSArray *)AG_RKL_METHOD_PREPEND(arrayOfCaptureComponentsMatchedByRegex):(NSString *)regex;
- (NSArray *)AG_RKL_METHOD_PREPEND(arrayOfCaptureComponentsMatchedByRegex):(NSString *)regex range:(NSRange)range;
- (NSArray *)AG_RKL_METHOD_PREPEND(arrayOfCaptureComponentsMatchedByRegex):(NSString *)regex options:(AG_RKLRegexOptions)options range:(NSRange)range error:(NSError **)error;

  //// >= 4.0

- (NSArray *)AG_RKL_METHOD_PREPEND(arrayOfDictionariesByMatchingRegex):(NSString *)regex withKeysAndCaptures:(id)firstKey, ... AG_RKL_REQUIRES_NIL_TERMINATION;
- (NSArray *)AG_RKL_METHOD_PREPEND(arrayOfDictionariesByMatchingRegex):(NSString *)regex range:(NSRange)range withKeysAndCaptures:(id)firstKey, ... AG_RKL_REQUIRES_NIL_TERMINATION;
- (NSArray *)AG_RKL_METHOD_PREPEND(arrayOfDictionariesByMatchingRegex):(NSString *)regex options:(AG_RKLRegexOptions)options range:(NSRange)range error:(NSError **)error withKeysAndCaptures:(id)firstKey, ... AG_RKL_REQUIRES_NIL_TERMINATION;
- (NSArray *)AG_RKL_METHOD_PREPEND(arrayOfDictionariesByMatchingRegex):(NSString *)regex options:(AG_RKLRegexOptions)options range:(NSRange)range error:(NSError **)error withFirstKey:(id)firstKey arguments:(va_list)varArgsList;

- (NSArray *)AG_RKL_METHOD_PREPEND(arrayOfDictionariesByMatchingRegex):(NSString *)regex options:(AG_RKLRegexOptions)options range:(NSRange)range error:(NSError **)error withKeys:(id *)keys forCaptures:(int *)captures count:(NSUInteger)count;

- (NSDictionary *)AG_RKL_METHOD_PREPEND(dictionaryByMatchingRegex):(NSString *)regex withKeysAndCaptures:(id)firstKey, ... AG_RKL_REQUIRES_NIL_TERMINATION;
- (NSDictionary *)AG_RKL_METHOD_PREPEND(dictionaryByMatchingRegex):(NSString *)regex range:(NSRange)range withKeysAndCaptures:(id)firstKey, ... AG_RKL_REQUIRES_NIL_TERMINATION;
- (NSDictionary *)AG_RKL_METHOD_PREPEND(dictionaryByMatchingRegex):(NSString *)regex options:(AG_RKLRegexOptions)options range:(NSRange)range error:(NSError **)error withKeysAndCaptures:(id)firstKey, ... AG_RKL_REQUIRES_NIL_TERMINATION;
- (NSDictionary *)AG_RKL_METHOD_PREPEND(dictionaryByMatchingRegex):(NSString *)regex options:(AG_RKLRegexOptions)options range:(NSRange)range error:(NSError **)error withFirstKey:(id)firstKey arguments:(va_list)varArgsList;

- (NSDictionary *)AG_RKL_METHOD_PREPEND(dictionaryByMatchingRegex):(NSString *)regex options:(AG_RKLRegexOptions)options range:(NSRange)range error:(NSError **)error withKeys:(id *)keys forCaptures:(int *)captures count:(NSUInteger)count;

#ifdef    _AG_RKL_BLOCKS_ENABLED

- (BOOL)AG_RKL_METHOD_PREPEND(enumerateStringsMatchedByRegex):(NSString *)regex usingBlock:(void (^)(NSInteger captureCount, NSString * const capturedStrings[captureCount], const NSRange capturedRanges[captureCount], volatile BOOL * const stop))block;
- (BOOL)AG_RKL_METHOD_PREPEND(enumerateStringsMatchedByRegex):(NSString *)regex options:(AG_RKLRegexOptions)options inRange:(NSRange)range error:(NSError **)error enumerationOptions:(AG_RKLRegexEnumerationOptions)enumerationOptions usingBlock:(void (^)(NSInteger captureCount, NSString * const capturedStrings[captureCount], const NSRange capturedRanges[captureCount], volatile BOOL * const stop))block;

- (BOOL)AG_RKL_METHOD_PREPEND(enumerateStringsSeparatedByRegex):(NSString *)regex usingBlock:(void (^)(NSInteger captureCount, NSString * const capturedStrings[captureCount], const NSRange capturedRanges[captureCount], volatile BOOL * const stop))block;
- (BOOL)AG_RKL_METHOD_PREPEND(enumerateStringsSeparatedByRegex):(NSString *)regex options:(AG_RKLRegexOptions)options inRange:(NSRange)range error:(NSError **)error enumerationOptions:(AG_RKLRegexEnumerationOptions)enumerationOptions usingBlock:(void (^)(NSInteger captureCount, NSString * const capturedStrings[captureCount], const NSRange capturedRanges[captureCount], volatile BOOL * const stop))block;

- (NSString *)AG_RKL_METHOD_PREPEND(stringByReplacingOccurrencesOfRegex):(NSString *)regex usingBlock:(NSString *(^)(NSInteger captureCount, NSString * const capturedStrings[captureCount], const NSRange capturedRanges[captureCount], volatile BOOL * const stop))block;
- (NSString *)AG_RKL_METHOD_PREPEND(stringByReplacingOccurrencesOfRegex):(NSString *)regex options:(AG_RKLRegexOptions)options inRange:(NSRange)range error:(NSError **)error enumerationOptions:(AG_RKLRegexEnumerationOptions)enumerationOptions usingBlock:(NSString *(^)(NSInteger captureCount, NSString * const capturedStrings[captureCount], const NSRange capturedRanges[captureCount], volatile BOOL * const stop))block;

#endif // _AG_RKL_BLOCKS_ENABLED

@end

@interface NSMutableString (RegexKitLiteAdditions)

- (NSInteger)AG_RKL_METHOD_PREPEND(replaceOccurrencesOfRegex):(NSString *)regex withString:(NSString *)replacement;
- (NSInteger)AG_RKL_METHOD_PREPEND(replaceOccurrencesOfRegex):(NSString *)regex withString:(NSString *)replacement range:(NSRange)searchRange;
- (NSInteger)AG_RKL_METHOD_PREPEND(replaceOccurrencesOfRegex):(NSString *)regex withString:(NSString *)replacement options:(AG_RKLRegexOptions)options range:(NSRange)searchRange error:(NSError **)error;

  //// >= 4.0

#ifdef    _AG_RKL_BLOCKS_ENABLED

- (NSInteger)AG_RKL_METHOD_PREPEND(replaceOccurrencesOfRegex):(NSString *)regex usingBlock:(NSString *(^)(NSInteger captureCount, NSString * const capturedStrings[captureCount], const NSRange capturedRanges[captureCount], volatile BOOL * const stop))block;
- (NSInteger)AG_RKL_METHOD_PREPEND(replaceOccurrencesOfRegex):(NSString *)regex options:(AG_RKLRegexOptions)options inRange:(NSRange)range error:(NSError **)error enumerationOptions:(AG_RKLRegexEnumerationOptions)enumerationOptions usingBlock:(NSString *(^)(NSInteger captureCount, NSString * const capturedStrings[captureCount], const NSRange capturedRanges[captureCount], volatile BOOL * const stop))block;

#endif // _AG_RKL_BLOCKS_ENABLED

@end

#endif // __OBJC__

#endif // _AG_REGEXKITLITE_H_

#ifdef __cplusplus
}  // extern "C"
#endif
