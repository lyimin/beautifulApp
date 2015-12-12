//
//  OpenUDID.h
//  openudid
//
//  initiated by Yann Lechelle (cofounder @Appsfire) on 8/28/11.
//  Copyright 2011 OpenUDID.org
//
//  Main branches
//      iOS code: https://github.com/ylechelle/OpenUDID
//


#import <Foundation/Foundation.h>

#define kAGSKOpenUDIDErrorNone          0
#define kAGSKOpenUDIDErrorOptedOut      1
#define kAGSKOpenUDIDErrorCompromised   2

@interface CMOpenUDID : NSObject {
}
+ (NSString*) value;
+ (NSString*) valueWithError:(NSError**)error;
+ (void) setOptOut:(BOOL)optOutValue;

@end
