#import <JFFAsyncOperations/JFFAsyncOperationsBlockDefinitions.h>
#import <Foundation/Foundation.h>

/**
 A class to change async operation result, error or progress.
 
 * Completion result
 * Completion error
 * Progress

 */
@interface JAsyncOperationHooks : NSObject


/**
 Passes the operation result to resultBuilder block for post-processing.
 
 @param loader An asynchronous operation to hook.
 @param resultBuilder A block that post-processes the operation result object.
 
 @return A hoked asynchronous operation.
 */
+(JFFAsyncOperation)asyncOperation:(JFFAsyncOperation)loader
                 withChangedResult:(JFFChangedResultBuilder)resultBuilder
__attribute__((nonnull));


/**
 Passes the operation progress info to resultBuilder block for post-processing.
 
 @param loader An asynchronous operation to hook.
 @param resultBuilder A block that post-processes the operation progress info object.
 
 @return A hoked asynchronous operation.
 */
+(JFFAsyncOperation)asyncOperation:(JFFAsyncOperation)loader
               withChangedProgress:(JFFChangedResultBuilder)resultBuilder
__attribute__((nonnull));

/**
 */
+(JFFAsyncOperation)asyncOperationResultAsProgress:(JFFAsyncOperation)loader
__attribute__((nonnull));


/**
 Passes the operation completion error to resultBuilder block for post-processing.
 A typical usage is wrapping system or third-party errors to your own ones.
 
 @param loader An asynchronous operation to hook.
 @param resultBuilder A block that post-processes the operation compeltion error object.
 
 @return A hoked asynchronous operation.
 */+(JFFAsyncOperation)asyncOperation:(JFFAsyncOperation)loader
                  withChangedError:(JFFChangedErrorBuilder)errorBuilder
__attribute__((nonnull));


@end
