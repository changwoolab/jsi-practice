#import "SuperSqlite.h"

#import <React/RCTBridge+Private.h>
#import <jsi/jsi.h>

#import <React/RCTUtils.h>
#import <ReactCommon/CallInvoker.h>

#import <memory>

@implementation SuperSqlite
RCT_EXPORT_MODULE()

+ (BOOL)requiresMainQueueSetup {
    return YES;
}

- (void)setBridge:(RCTBridge *)bridge {
    _bridge = bridge;
    _setBridgeOnMainQueue = RCTIsMainQueue();

    RCTCxxBridge *cxxBridge = (RCTCxxBridge *)self.bridge;

    if (!cxxBridge.runtime) {
        return;
    }

    installSequel(*(facebook::jsi::Runtime *)cxxBridge.runtime);
}

- (void)invalidate {
    cleanUpSequel();
}

// Don't compile this code when we build for the old architecture.
#ifdef RCT_NEW_ARCH_ENABLED
- (NSNumber *)multiply:(double)a b:(double)b {
    NSNumber *result = @(supersqlite::multiply(a, b));

    return result;
}

- (std::shared_ptr<facebook::react::TurboModule>)getTurboModule:
    (const facebook::react::ObjCTurboModule::InitParams &)params
{
    return std::make_shared<facebook::react::NativeSuperSqliteSpecJSI>(params);
}
#endif

@end
