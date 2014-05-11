#import <JFFAsyncOperations/JFFAsyncOperationsBlockDefinitions.h>
#import <Foundation/Foundation.h>


/**
 A class to create asynchronous operations from synchronous operations and associating them with a given operation queue.
 */
@interface JAsyncOperationConstructors : NSObject

/**
 Creates an asynchronous operation with a synchronous one.
 
 @param loadDataBlock The worker block that returns data object or error (as an out parameter).
 Warning : if you pass nil an exception will be thrown.
 
 @return An asynchronous operation.
 */
+(JFFAsyncOperation)asyncOperationWithSyncOperation:(JFFSyncOperation)loadDataBlock
__attribute__((nonnull));



/**
 Creates an asynchronous operation with a synchronous one and shedules it on an operation queue.
 
 @param loadDataBlock The worker block that returns data object or error (as an out parameter).
 Warning : if you pass nil an exception will be thrown.
 
 @param queueName The name of an operation queue. It will be taken from the pool or spawned by the dispatch_queue_create() call.
 
 @return An asynchronous operation.
 */
+(JFFAsyncOperation)asyncOperationWithSyncOperation:(JFFSyncOperation)loadDataBlock
                                           andQueue:(NSString*)queueName
__attribute__((nonnull));


/**
 Creates an asynchronous operation with a synchronous one and shedules it on an operation queue.
 
 @param loadDataBlock The worker block that returns data object or error (as an out parameter).
 Warning : if you pass nil an exception will be thrown.
 
 @param queueName The name of an operation queue. It will be taken from the pool or spawned by the dispatch_queue_create() call.
 
 @param isSerialQueue YES for continuous execution. NO for parallel execution.
 
 @return An asynchronous operation.
 */
+(JFFAsyncOperation)asyncOperationWithSyncOperationAndConfigurableQueue:(JFFSyncOperation)loadDataBlock
                                                                  queue:(NSString*)queueName
                                                          isSerialQueue:(BOOL)isSerialQueue
__attribute__((nonnull));



/**
 Creates an asynchronous operation with a synchronous one.
 It won't start executing as long as there are other operations in the queue.
 
 @param loadDataBlock The worker block that returns data object or error (as an out parameter).
 Warning : if you pass nil an exception will be thrown.
 
 @param queueName The name of an operation queue. It will be taken from the pool or spawned by the dispatch_queue_create() call.
 
 @return An asynchronous operation.
 */
+(JFFAsyncOperation)barrierAsyncOperationWithSyncOperation:(JFFSyncOperation)loadDataBlock
                                                  andQueue:(NSString*)queueName
__attribute__((nonnull));



/**
 Creates an asynchronous operation with a synchronous one.
 A synchronous operation block accepts the progress callback.
 
 @param progressLoadDataBlock The worker block that returns data object or error (as an out parameter).
 Warning : if you pass nil an exception will be thrown.
 
 @return An asynchronous operation.
 */
+(JFFAsyncOperation)asyncOperationWithSyncOperationWithProgressBlock:(JFFSyncOperationWithProgress)progressLoadDataBlock
__attribute__((nonnull));

@end
