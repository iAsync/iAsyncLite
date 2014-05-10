#import <JFFAsyncOperations/JFFAsyncOperationsBlockDefinitions.h>
#import <Foundation/Foundation.h>


/**
A category to perform map/reduce actions asynchronously in the background thread.
*/
@interface NSArray (AsyncMap)

/**
Creates an operation that performs the block with each array element simultaneously.
The resulting array will be returned in the completion callback of the async operation.

Note : if the block returns at least one error, the entire operation will be marked as "failed".
The entire operation will also be cancelled.

@param block A block to construct an asynchronous operation with the given array element.

@return An asycnhronous operation that performs actions on array elements in parallel.
*/
- (JFFAsyncOperation)asyncMap:(JFFAsyncOperationBinder)block;



/**
Creates an operation that performs the block with each array element simultaneously.
The resulting array will be returned in the completion callback of the async operation.

Note : if the block returns at least one error, the entire operation will be marked as "failed".
However, all operations will be attempted to execute.

@param block A block to construct an asynchronous operation with the given array element.

@return An asycnhronous operation that performs actions on array elements in parallel.
*/
- (JFFAsyncOperation)asyncWaitAllMap:(JFFAsyncOperationBinder)block;



/**
Creates an operation that performs the block with each array element simultaneously.
The resulting array will be returned in the completion callback of the async operation.

Note : if the block returns at least one error, the execution keeps going. 
The operation is considered as failed if all operations have failed.

@param block A block to construct an asynchronous operation with the given array element.

@return An asycnhronous operation that performs actions on array elements in parallel.
*/
- (JFFAsyncOperation)tolerantFaultAsyncMap:(JFFAsyncOperationBinder)block;

@end
