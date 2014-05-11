#ifndef __JASYNC_OPERATION_WITH_QUEUE_CONSTRUCTOR_FUNCTIONS_H__
#define __JASYNC_OPERATION_WITH_QUEUE_CONSTRUCTOR_FUNCTIONS_H__

#import <JFFAsyncOperations/JFFAsyncOperationsBlockDefinitions.h>
#include <objc/objc-api.h>


/**
Creates an asynchronous operation with a synchronous one.

@param loadDataBlock The worker block that returns data object or error (as an out parameter).
Warning : if you pass nil an exception will be thrown.

@return An asynchronous operation.
*/
OBJC_EXTERN    JFFAsyncOperation asyncOperationWithSyncOperation(JFFSyncOperation loadDataBlock);
  


/**
Creates an asynchronous operation with a synchronous one and shedules it on an operation queue.

@param loadDataBlock The worker block that returns data object or error (as an out parameter).
Warning : if you pass nil an exception will be thrown.

@param queueName The name of an operation queue. It will be taken from the pool or spawned by the dispatch_queue_create() call.

@return An asynchronous operation.
*/  
OBJC_EXTERN    JFFAsyncOperation asyncOperationWithSyncOperationAndQueue(JFFSyncOperation loadDataBlock,
                                                              const char *queueName);


/**
Creates an asynchronous operation with a synchronous one and shedules it on an operation queue.

@param loadDataBlock The worker block that returns data object or error (as an out parameter).
Warning : if you pass nil an exception will be thrown.

@param queueName The name of an operation queue. It will be taken from the pool or spawned by the dispatch_queue_create() call.

@param isSerialQueue YES for continuous execution. NO for parallel execution.

@return An asynchronous operation.
*/
OBJC_EXTERN    JFFAsyncOperation asyncOperationWithSyncOperationAndConfigurableQueue(JFFSyncOperation loadDataBlock, const char *queueName, BOOL isSerialQueue);
    


/**
Creates an asynchronous operation with a synchronous one.
It won't start executing as long as there are other operations in the queue.

@param loadDataBlock The worker block that returns data object or error (as an out parameter).
Warning : if you pass nil an exception will be thrown.
 
@param queueName The name of an operation queue. It will be taken from the pool or spawned by the dispatch_queue_create() call.

@return An asynchronous operation.
*/
OBJC_EXTERN    JFFAsyncOperation barrierAsyncOperationWithSyncOperationAndQueue(JFFSyncOperation loadDataBlock,
                                                                     const char *queueName);


/**
Creates an asynchronous operation with a synchronous one.
A synchronous operation block accepts the progress callback.

@param progressLoadDataBlock The worker block that returns data object or error (as an out parameter).
Warning : if you pass nil an exception will be thrown.

@return An asynchronous operation.
*/    
OBJC_EXTERN    JFFAsyncOperation asyncOperationWithSyncOperationWithProgressBlock(JFFSyncOperationWithProgress progressLoadDataBlock);


#endif //__JASYNC_OPERATION_WITH_QUEUE_CONSTRUCTOR_FUNCTIONS_H__

