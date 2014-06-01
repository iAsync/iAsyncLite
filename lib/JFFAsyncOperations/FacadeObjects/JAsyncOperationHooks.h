#import <JFFAsyncOperations/JFFAsyncOperationsBlockDefinitions.h>
#import <JFFUtils/JFFUtils.h>
#import <Foundation/Foundation.h>

@interface JAsyncOperationHooks : NSObject

/**
 */
+(JFFAsyncOperation)asyncOperation:(JFFAsyncOperation)loader
                     withDoneBlock:(JFFSimpleBlock)doneCallbackHook
__attribute__((nonnull, pure,const));



@end
