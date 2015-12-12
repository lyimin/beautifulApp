
#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>
#import <netinet/in.h>

#define USE_DDG_EXTENSIONS 1

enum {
	kCMNotReachable = 0, // Apple's code depends upon 'NotReachable' being the same value as 'NO'.
	kCMReachableViaWWAN, // Switched order from Apple's enum. WWAN is active before WiFi.
	kCMReachableViaWiFi
	
};
typedef	uint32_t NetworkStatus;

enum {
	CMNotReachable     = kCMNotReachable,
	CMReachableViaWiFi = kCMReachableViaWiFi,
	CMReachableViaWWAN = kCMReachableViaWWAN
	
};


extern NSString *const kCMInternetConnection;
extern NSString *const kCMLocalWiFiConnection;
extern NSString *const kCMReachabilityChangedNotification;

@interface CMReachability: NSObject {
	
@private
	NSString                *key_;
	SCNetworkReachabilityRef reachabilityRef;

}

@property (copy) NSString *key; // Atomic because network operations are asynchronous.

// Designated Initializer.
- (CMReachability *) initWithReachabilityRef: (SCNetworkReachabilityRef) ref;

// Use to check the reachability of a particular host name. 
+ (CMReachability *) reachabilityWithHostName: (NSString*) hostName;

// Use to check the reachability of a particular IP address. 
+ (CMReachability *) reachabilityWithAddress: (const struct sockaddr_in*) hostAddress;

// Use to check whether the default route is available.  
// Should be used to, at minimum, establish network connectivity.
+ (CMReachability *) reachabilityForInternetConnection;

// Use to check whether a local wifi connection is available.
+ (CMReachability *) reachabilityForLocalWiFi;

//Start listening for reachability notifications on the current run loop.
- (BOOL) startNotifier;
- (void)  stopNotifier;

// Comparison routines to enable choosing actions in a notification.
- (BOOL) isEqual: (CMReachability *) r;

// These are the status tests.
- (NetworkStatus) currentReachabilityStatus;

// The main direct test of reachability.
- (BOOL) isReachable;

// WWAN may be available, but not active until a connection has been established.
// WiFi may require a connection for VPN on Demand.
- (BOOL) isConnectionRequired; // Identical DDG variant.
- (BOOL)   connectionRequired; // Apple's routine.

// Dynamic, on demand connection?
- (BOOL) isConnectionOnDemand;

// Is user intervention required?
- (BOOL) isInterventionRequired;

// Routines for specific connection testing by your app.
- (BOOL) isReachableViaWWAN;
- (BOOL) isReachableViaWiFi;

- (SCNetworkReachabilityFlags) reachabilityFlags;

@end
