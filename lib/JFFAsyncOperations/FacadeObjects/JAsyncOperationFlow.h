#import <JFFAsyncOperations/JFFAsyncOperationsBlockDefinitions.h>
#import <Foundation/Foundation.h>

@interface JAsyncOperationFlow : NSObject

#pragma mark - 
#pragma mark Sequence
/**
 Combines operations from array so that they run one after another.
 Result of the last operation is returned to the caller.
 
 @param loaders An NSArray of JFFAsyncOperation objects. It cannot be nil or empty.
 @return A composite operation that launches loaders in the same order as they are stored in the array
 
 If any operation fails, then
 1. The next operations do not start executing
 2. The **entire sequence** is considered as **failed**
 
 If all operations succeed the completion callback gets the result of the last operation in the **loaders** array.
 */
+(JFFAsyncOperation)sequenceOfAsyncOperationsArray:(NSArray*)loaders __attribute__((nonnull, pure, const));



/**
 Combines operations from array so that they run one after another.
 Results of all operations are returned to the caller.
 
 @param loaders An NSArray of JFFAsyncOperation objects. It cannot be nil or empty.
 @return A composite operation that launches loaders in the same order as they are stored in the array
 
 If any operation fails, then
 1. The next operations do not start executing
 2. The **entire sequence** is considered as **failed**
 
 If all operations succeed the completion callback gets the array with results from all operations in the execution order.
 */
+(JFFAsyncOperation)sequenceOfAsyncOperationsWithAllResults:(NSArray*)loaders __attribute__((nonnull, pure, const));


/**
 Combines operations from array so that they run one after another.
 Results of all operations are returned to the caller.
 
 @param loaders An NSArray of JFFAsyncOperation objects. It cannot be nil or empty.
 @return A composite operation that launches loaders in the same order as they are stored in the array.
 
 If any operation fails, then the next operations try executing. The sequence is marked as **failed** if **all operations** are failed.
 
 The completion callback gets the array with results from all succeeded operations in the execution order. Results of failed operations are ignored.
 */
+(JFFAsyncOperation)sequenceOfAsyncOperationsWithSuccessfullResults:(NSArray*)loaders __attribute__((nonnull, pure, const));


#pragma mark -
#pragma mark Try Sequence
/**
 Executes operations in the order specified by the array until any of them succeeds. This may be useful when we are uncertain which approach is going to work. For example, 
 
 * Try various authentication approaches
 * Checking back end version based on available API and endpoints
 * URL scheme autocomplete
 
 @param loaders An NSArray of JFFAsyncOperation objects. It cannot be nil or empty.
 @return A composite async operation.
 
 On success : the completion callback gets the result of the succeeded operation.
 On error   : the completion callback gets an error from the last operation.
 */
+(JFFAsyncOperation)sequenceUntilFirstSuccessOfAsyncOperationsArray:(NSArray*)loaders __attribute__((nonnull, pure, const));


#pragma mark -
#pragma mark Group
/**
 Combines operations from array so that they run one after another.
 An array with results of all operations is returned to the caller.
 The results of failed operations are stubbed with NSNull objects.
 
 @param loaders An NSArray of JFFAsyncOperation objects. It cannot be nil or empty.
 @return A composite async operation.
 */
+(JFFAsyncOperation)parallelGroupOfAsyncOperations:(NSArray*)loaders __attribute__((nonnull, pure, const));


/**
 Combines operations from array so that they run one after another.
 An array with results of all operations is returned to the caller.
 If any operation fails then other operations stop executing and an entire operation is marked as failed.
 
 @param loaders An NSArray of JFFAsyncOperation objects. It cannot be nil or empty.
 @return A composite async operation.
 */
+(JFFAsyncOperation)failOnFirstErrorParallelGroupOfAsyncOperations:(NSArray*)loaders __attribute__((nonnull, pure, const));


#pragma mark -
#pragma mark Waterfall
/**
 Chains the operations so that each next operation receives the result of a previous one.
 
 @param firstLoader The first loader in the chain
 @param arrayOfBinders Array of JFFAsyncOperationBinder blocks that implement a **monad** concept. It cannot be nil or empty.
 
 @return A chain of operations. Each next operation receives the result of a previous one.
 
 If all operations succeed the completion callback gets the result of the last operation.
 */
+(JFFAsyncOperation)waterfallFlowForAsyncOperation:(JFFAsyncOperation)firstLoader
                                 cascadeOperations:(NSArray*)arrayOfBinders __attribute__((nonnull, pure, const));


/**
 Chains the operations so that each next operation receives the error of a previous one.
 The execution stops on first successful operation or cascade element.
 
 @param firstLoader The first loader in the chain
 @param arrayOfBinders Array of JFFAsyncOperationBinder blocks that implement a **monad** concept. It cannot be nil or empty.
 
 @return A chain of operations. Each next operation receives the result of a previous one.
 
 If all operations succeed the completion callback gets the result of the last operation.
 */
+(JFFAsyncOperation)waterfallFlowUntilFirstSuccessForAsyncOperation:(JFFAsyncOperation)firstLoader
                                                  cascadeOperations:(NSArray*)arrayOfBinders __attribute__((nonnull, pure, const));

/**
 Same as +[JAsyncOperationFlow sequenceOfAsyncOperationsArray:] but operates on JFFAsyncOperationBinder blocks that implement a **monad** concept.
 
 @param cascadeElements Cascade elements to combine. It cannot be nil or empty.
 @return A composite element. It accepts the argument of the first element and returns the result of the last one.
 */
+(JFFAsyncOperationBinder)sequenceOfCascadeElements:(NSArray*)cascadeElements __attribute__((nonnull, pure, const));

@end
