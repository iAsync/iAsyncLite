#import <JFFAsyncOperations/JFFAsyncOperationsBlockDefinitions.h>
#import <Foundation/Foundation.h>

#include <objc/objc-api.h>

@interface JFFAsyncTimerResult : NSObject
@end

OBJC_EXTERN    JFFAsyncOperation asyncOperationWithDelay(NSTimeInterval delay, NSTimeInterval leeway);
    
OBJC_EXTERN    JFFAsyncOperation asyncOperationAfterDelay(NSTimeInterval delay,
                                               NSTimeInterval leeway,
                                               JFFAsyncOperation loader);
    
    ///////////////////////// AUTO REPEAT CIRCLE ////////////////////////
    
OBJC_EXTERN    JFFAsyncOperation repeatAsyncOperation(JFFAsyncOperation loader,
                                           JFFContinueLoaderWithResult continueLoaderBuilder,
                                           NSTimeInterval delay,
                                           NSTimeInterval leeway,
                                           NSInteger maxRepeatCount);

