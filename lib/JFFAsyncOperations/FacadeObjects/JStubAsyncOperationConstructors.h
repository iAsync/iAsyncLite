#import <JFFAsyncOperations/JFFAsyncOperationsBlockDefinitions.h>
#import <JFFUtils/Blocks/JFFUtilsBlockDefinitions.h>
#import <Foundation/Foundation.h>


/**
 A builder for asynchronous operations with an already known result.
 */
@interface JStubAsyncOperationConstructors : NSObject

/**
 Creates an asynchronouys operation that returns the specified object.
 
 @param result An object to return
 
 @return An asynchronous operation.
 */
+(JFFAsyncOperation)asyncOperationWithResult:(id)result;


/**
 Creates an asynchronouys operation that always fails with the given error.
 
 @param error An error object to fail with
 
 @return An asynchronous operation.
 */
+(JFFAsyncOperation)asyncOperationWithError:(NSError *)error;


/**
 Creates an asynchronouys operation that gets cancelled with the specified flag.
 The operation will be cancelled instead of being executed.
 
 @param canceled YES to cancel both the result operation and related ones.
 NO to unsubscribe the operation.
 
 @return An asynchronous operation.
 
 Note : such operations should be used in unit tests only.
 */
+(JFFAsyncOperation)asyncOperationWithCancelFlag:(BOOL)canceled;


/**
 Creates an operation with an infinite loop within.
 
 @return An asynchronous operation.
 
 Note : such operations should be used in unit tests only.
 */
+(JFFAsyncOperation)neverFinishAsyncOperation;

@end
