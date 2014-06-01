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
@interface JDoneCallbackAsyncOperationHooks : NSObject

/**
 Subscribes the given block to operation completion.
 The original callback will be executed.
 
 @param loader An asynchronous operation to hook.
 @param doneCallbackHook An action block to subscribe for completion.
 
 @return A hooked asynchronous operation.
 */
+(JFFAsyncOperation)asyncOperation:(JFFAsyncOperation)loader
               withDoneActionBlock:(JFFSimpleBlock)doneCallbackHook
__attribute__((nonnull, pure,const));



/**
 Subscribes the given block to operation completion.
 The original callback will be executed.
 
 @param loader An asynchronous operation to hook.
 @param doneCallbackHook A block callback to subscribe for completion.
 
 @return A hooked asynchronous operation.
 */
+(JFFAsyncOperation)asyncOperation:(JFFAsyncOperation)loader
             withDoneCallbackBlock:(JFFDidFinishAsyncOperationHandler)doneCallbackHook
__attribute__((nonnull, pure,const));



/**
 Subscribes the given block to operation completion.
 
 @param loader An asynchronous operation to hook.
 @param doneCallbackHook A hook for completion. Depending on its implementation, the original callback will either be invoked or not.
 
 @return A hooked asynchronous operation.
 */
+(JFFAsyncOperation)asyncOperation:(JFFAsyncOperation)loader
              withDoneCallbackHook:(JFFDidFinishAsyncOperationHook)doneCallbackHook
__attribute__((nonnull, pure,const));



/**
 Subscribes an action block to operation start and a callback block to operation completion.
 A typical usage is injecting logging messages.
 
 @param loader An asynchronous operation to hook.
 @param startBlock An action block to subscribe for operation start.
 @param finishCallback A block callback to subscribe for completion. The original callback will be executed.
 
 @return A hooked asynchronous operation.
 */
+(JFFAsyncOperation)asyncOperation:(JFFAsyncOperation)loader
              withStartActionBlock:(JFFSimpleBlock)startBlock
               finishCallbackBlock:(JFFDidFinishAsyncOperationHandler)finishCallback
__attribute__((nonnull, pure,const));



/**
 Subscribes an action block to operation start and a callback block to operation completion.
 Same as +[JDoneCallbackAsyncOperationHooks asyncOperation:withStartActionBlock:finishCallbackBlock:] but hook blocks may be nil
 A typical usage is injecting logging messages.
 
 @param loader An asynchronous operation to hook.
 @param startBlock An action block to subscribe for operation start.
 @param finishCallback A block callback to subscribe for completion. The original callback will be executed.
 
 @return A hooked asynchronous operation.
 */
+(JFFAsyncOperation)asyncOperation:(JFFAsyncOperation)loader
      withOptionalStartActionBlock:(JFFSimpleBlock)startBlock
       optionalFinishCallbackBlock:(JFFDidFinishAsyncOperationHandler)finishCallback
__attribute__((nonnull(1), pure,const));


/**
 Subscribes an action block to operation start and a callback block to operation completion.
 Same as +[JDoneCallbackAsyncOperationHooks asyncOperation:withStartActionBlock:finishCallbackBlock:] but hook blocks may be nil
 
 A typical usage is injecting logging messages.
 
 @param loader An asynchronous operation to hook.
 @param startBlock An action block to subscribe for operation start.
 @param doneBlock A block callback to subscribe for completion. The original callback will be executed.
 
 @return A hooked asynchronous operation.
 */
+(JFFAsyncOperation)asyncOperation:(JFFAsyncOperation)loader
      withOptionalStartActionBlock:(JFFSimpleBlock)startBlock
         optionalFinishActionBlock:(JFFSimpleBlock)doneBlock
__attribute__((nonnull(1), pure,const));

@end
