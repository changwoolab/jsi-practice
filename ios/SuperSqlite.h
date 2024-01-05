#ifdef __cplusplus
#import "react-native-super-sqlite.h"
#endif

#ifdef RCT_NEW_ARCH_ENABLED
#import "RNSuperSqliteSpec.h"

@interface SuperSqlite : NSObject <NativeSuperSqliteSpec>
#else
#import <React/RCTBridgeModule.h>

@interface SuperSqlite : NSObject <RCTBridgeModule>
#endif

// I'm not sure if this should be here or not, but it's here for now.
@property (nonatomic, assign) BOOL setBridgeOnMainQueue;

@end
