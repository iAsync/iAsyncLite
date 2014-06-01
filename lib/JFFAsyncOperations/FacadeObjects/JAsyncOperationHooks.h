#import <JFFAsyncOperations/JFFAsyncOperationsBlockDefinitions.h>
#import <JFFUtils/JFFUtils.h>
#import <Foundation/Foundation.h>


/**
 A class to hook the callbacks of asynchronous operation. All kinds of callbacks can be hooked : 
 
 * Completion result
 * Completion error
 * Progress
 * Cancellation
 
 */
@interface JAsyncOperationHooks : NSObject

/**
 */
+(JFFAsyncOperation)asyncOperation:(JFFAsyncOperation)loader
                     withDoneBlock:(JFFSimpleBlock)doneCallbackHook
__attribute__((nonnull, pure,const));



@end
