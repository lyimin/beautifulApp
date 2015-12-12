//
//  JSONKit.h
//  http://github.com/johnezang/JSONKit
//  Dual licensed under either the terms of the BSD License, or alternatively
//  under the terms of the Apache License, Version 2.0, as specified below.
//

#include <stddef.h>
#include <stdint.h>
#include <limits.h>
#include <TargetConditionals.h>
#include <AvailabilityMacros.h>

#ifdef    __OBJC__
#import <Foundation/NSArray.h>
#import <Foundation/NSData.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSError.h>
#import <Foundation/NSObjCRuntime.h>
#import <Foundation/NSString.h>
#endif
 
#ifdef __cplusplus
extern "C" {
#endif
  
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


#ifndef _AG_SKJSON_H_
#define _AG_SKJSON_H_

#if defined(__GNUC__) && (__GNUC__ >= 4) && defined(__APPLE_CC__) && (__APPLE_CC__ >= 5465)
#define AG_SK_DEPRECATED_ATTRIBUTE __attribute__((deprecated))
#else
#define AG_SK_DEPRECATED_ATTRIBUTE
#endif
  
#define AG_SKJSON_VERSION_MAJOR 1
#define AG_SKJSON_VERSION_MINOR 4

typedef NSUInteger AG_SKFlags;

enum {
  AG_SKParseOptionNone                     = 0,
  AG_SKParseOptionStrict                   = 0,
  AG_SKParseOptionComments                 = (1 << 0),
  AG_SKParseOptionUnicodeNewlines          = (1 << 1),
  AG_SKParseOptionLooseUnicode             = (1 << 2),
  AG_SKParseOptionPermitTextAfterValidJSON = (1 << 3),
  AG_SKParseOptionValidFlags               = (AG_SKParseOptionComments | AG_SKParseOptionUnicodeNewlines | AG_SKParseOptionLooseUnicode | AG_SKParseOptionPermitTextAfterValidJSON),
};
typedef AG_SKFlags AG_SKParseOptionFlags;

enum {
  AG_SKSerializeOptionNone                 = 0,
  AG_SKSerializeOptionPretty               = (1 << 0),
  AG_SKSerializeOptionEscapeUnicode        = (1 << 1),
  AG_SKSerializeOptionEscapeForwardSlashes = (1 << 4),
  AG_SKSerializeOptionValidFlags           = (AG_SKSerializeOptionPretty | AG_SKSerializeOptionEscapeUnicode | AG_SKSerializeOptionEscapeForwardSlashes),
};
typedef AG_SKFlags AG_SKSerializeOptionFlags;

#ifdef    __OBJC__

typedef struct AG_SKParseState AG_SKParseState; // Opaque internal, private type.

@interface AG_SKJSONDecoder : NSObject {
  AG_SKParseState *parseState;
}
+ (id)decoder;
+ (id)decoderWithParseOptions:(AG_SKParseOptionFlags)parseOptionFlags;
- (id)initWithParseOptions:(AG_SKParseOptionFlags)parseOptionFlags;
- (void)clearCache;

// The parse... methods were deprecated in v1.4 in favor of the v1.4 objectWith... methods.
- (id)parseUTF8String:(const unsigned char *)string length:(size_t)length                         AG_SK_DEPRECATED_ATTRIBUTE; // Deprecated in JSONKit v1.4.  Use objectWithUTF8String:length:        instead.
- (id)parseUTF8String:(const unsigned char *)string length:(size_t)length error:(NSError **)error AG_SK_DEPRECATED_ATTRIBUTE; // Deprecated in JSONKit v1.4.  Use objectWithUTF8String:length:error:  instead.
// The NSData MUST be UTF8 encoded JSON.
- (id)parseJSONData:(NSData *)jsonData                                                            AG_SK_DEPRECATED_ATTRIBUTE; // Deprecated in JSONKit v1.4.  Use objectWithData:                     instead.
- (id)parseJSONData:(NSData *)jsonData error:(NSError **)error                                    AG_SK_DEPRECATED_ATTRIBUTE; // Deprecated in JSONKit v1.4.  Use objectWithData:error:               instead.

// Methods that return immutable collection objects.
- (id)objectWithUTF8String:(const unsigned char *)string length:(NSUInteger)length;
- (id)objectWithUTF8String:(const unsigned char *)string length:(NSUInteger)length error:(NSError **)error;
// The NSData MUST be UTF8 encoded JSON.
- (id)objectWithData:(NSData *)jsonData;
- (id)objectWithData:(NSData *)jsonData error:(NSError **)error;

// Methods that return mutable collection objects.
- (id)mutableObjectWithUTF8String:(const unsigned char *)string length:(NSUInteger)length;
- (id)mutableObjectWithUTF8String:(const unsigned char *)string length:(NSUInteger)length error:(NSError **)error;
- (id)mutableObjectWithData:(NSData *)jsonData;
- (id)mutableObjectWithData:(NSData *)jsonData error:(NSError **)error;

@end

#pragma mark Deserializing methods

@interface NSString (AG_SKJSONDeserializing)
- (id)AG_SKObjectFromJSONString;
- (id)AG_SKObjectFromJSONStringWithParseOptions:(AG_SKParseOptionFlags)parseOptionFlags;
- (id)AG_SKObjectFromJSONStringWithParseOptions:(AG_SKParseOptionFlags)parseOptionFlags error:(NSError **)error;
- (id)AG_SKMutableObjectFromJSONString;
- (id)AG_SKMutableObjectFromJSONStringWithParseOptions:(AG_SKParseOptionFlags)parseOptionFlags;
- (id)AG_SKMutableObjectFromJSONStringWithParseOptions:(AG_SKParseOptionFlags)parseOptionFlags error:(NSError **)error;
@end

@interface NSData (AG_SKJSONDeserializing)
- (id)AG_SKObjectFromJSONData;
- (id)AG_SKObjectFromJSONDataWithParseOptions:(AG_SKParseOptionFlags)parseOptionFlags;
- (id)AG_SKObjectFromJSONDataWithParseOptions:(AG_SKParseOptionFlags)parseOptionFlags error:(NSError **)error;
- (id)AG_SKMutableObjectFromJSONData;
- (id)AG_SKMutableObjectFromJSONDataWithParseOptions:(AG_SKParseOptionFlags)parseOptionFlags;
- (id)AG_SKMutableObjectFromJSONDataWithParseOptions:(AG_SKParseOptionFlags)parseOptionFlags error:(NSError **)error;
@end

#pragma mark Serializing methods
  
@interface NSString (AG_SKJSONSerializing)
// Convenience methods for those that need to serialize the receiving NSString (i.e., instead of having to serialize a NSArray with a single NSString, you can "serialize to JSON" just the NSString).
// Normally, a string that is serialized to JSON has quotation marks surrounding it, which you may or may not want when serializing a single string, and can be controlled with includeQuotes:
// includeQuotes:YES `a "test"...` -> `"a \"test\"..."`
// includeQuotes:NO  `a "test"...` -> `a \"test\"...`
- (NSData *)AG_SKJSONData;     // Invokes JSONDataWithOptions:JKSerializeOptionNone   includeQuotes:YES
- (NSData *)AG_SKJSONDataWithOptions:(AG_SKSerializeOptionFlags)serializeOptions includeQuotes:(BOOL)includeQuotes error:(NSError **)error;
- (NSString *)AG_SKJSONString; // Invokes JSONStringWithOptions:JKSerializeOptionNone includeQuotes:YES
- (NSString *)AG_SKJSONStringWithOptions:(AG_SKSerializeOptionFlags)serializeOptions includeQuotes:(BOOL)includeQuotes error:(NSError **)error;
@end

@interface NSArray (AG_SKJSONSerializing)
- (NSData *)AG_SKJSONData;
- (NSData *)AG_SKJSONDataWithOptions:(AG_SKSerializeOptionFlags)serializeOptions error:(NSError **)error;
- (NSData *)AG_SKJSONDataWithOptions:(AG_SKSerializeOptionFlags)serializeOptions serializeUnsupportedClassesUsingDelegate:(id)delegate selector:(SEL)selector error:(NSError **)error;
- (NSString *)AG_SKJSONString;
- (NSString *)AG_SKJSONStringWithOptions:(AG_SKSerializeOptionFlags)serializeOptions error:(NSError **)error;
- (NSString *)AG_SKJSONStringWithOptions:(AG_SKSerializeOptionFlags)serializeOptions serializeUnsupportedClassesUsingDelegate:(id)delegate selector:(SEL)selector error:(NSError **)error;
@end

@interface NSDictionary (AG_SKJSONSerializing)
- (NSData *)AG_SKJSONData;
- (NSData *)AG_SKJSONDataWithOptions:(AG_SKSerializeOptionFlags)serializeOptions error:(NSError **)error;
- (NSData *)AG_SKJSONDataWithOptions:(AG_SKSerializeOptionFlags)serializeOptions serializeUnsupportedClassesUsingDelegate:(id)delegate selector:(SEL)selector error:(NSError **)error;
- (NSString *)AG_SKJSONString;
- (NSString *)AG_SKJSONStringWithOptions:(AG_SKSerializeOptionFlags)serializeOptions error:(NSError **)error;
- (NSString *)AG_SKJSONStringWithOptions:(AG_SKSerializeOptionFlags)serializeOptions serializeUnsupportedClassesUsingDelegate:(id)delegate selector:(SEL)selector error:(NSError **)error;
@end

#ifdef __BLOCKS__

@interface NSArray (AG_SKJSONSerializingBlockAdditions)
- (NSData *)AG_SKJSONDataWithOptions:(AG_SKSerializeOptionFlags)serializeOptions serializeUnsupportedClassesUsingBlock:(id(^)(id object))block error:(NSError **)error;
- (NSString *)AG_SKJSONStringWithOptions:(AG_SKSerializeOptionFlags)serializeOptions serializeUnsupportedClassesUsingBlock:(id(^)(id object))block error:(NSError **)error;
@end

@interface NSDictionary (AG_SKJSONSerializingBlockAdditions)
- (NSData *)AG_SKJSONDataWithOptions:(AG_SKSerializeOptionFlags)serializeOptions serializeUnsupportedClassesUsingBlock:(id(^)(id object))block error:(NSError **)error;
- (NSString *)AG_SKJSONStringWithOptions:(AG_SKSerializeOptionFlags)serializeOptions serializeUnsupportedClassesUsingBlock:(id(^)(id object))block error:(NSError **)error;

- (NSData *)AG_SKJSONDataWithUnsupportedClassesUsingBlock:(id(^)(id object))block error:(NSError **)error;
@end
  
#endif


#endif // __OBJC__

#endif // _JSONKIT_H_

#ifdef __cplusplus
}  // extern "C"
#endif
