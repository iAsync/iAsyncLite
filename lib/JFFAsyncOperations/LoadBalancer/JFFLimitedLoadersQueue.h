#import <JFFAsyncOperations/JFFAsyncOperationsBlockDefinitions.h>
#import <JFFAsyncOperations/LoadBalancer/JFFQueueExecutionOrder.h>
#import <Foundation/Foundation.h>


/**
A dispatch_queue wrapper with some limitations of simultaneous execution.
*/
@interface JFFLimitedLoadersQueue : NSObject


/**
A designated initializer.
Creates a queue with the given order.

@param orderStrategyId An id of the execution strategty.
See the reference of the JFFQueueExecutionOrder enum for details. 

@return A properly initialized object.
*/
- (instancetype)initWithExecutionOrder:(JFFQueueExecutionOrder)orderStrategyId;

/**
The limit of simultaneous parallel operations.

Note : default value is 10
*/
@property (nonatomic) NSUInteger limitCount;


/**
Wraps the loader and associates it with the current queue.

@param loader An asynchronous operation to execute in a queue.

@return A wrapped asynchronous operation.


The queue workflow :
1. Once invoked, the resulting  operation is added to the **pending loaders** list of the corresponding queue.
2. The operation stays pending while the **limitCount** is exceeded.
3. When active loaders count is less than **limitCount** the **loader** operation is moved to the **active loaders** list.
4. The operation is executed by the dispatch_async() invocation.
5. The operation is finished and the user gets proper callback notifications.
*/
- (JFFAsyncOperation)balancedLoaderWithLoader:(JFFAsyncOperation)loader;



/**
Wraps the loader and associates it with the current queue. The loader is not executed as long as there are other active loaders in the queue.

@param loader An asynchronous operation to execute in a queue.

@return A wrapped asynchronous operation.


The queue workflow :
1. Once invoked, the resulting  operation is added to the **pending loaders** list of the corresponding queue.
2. The operation stays pending while the **limitCount** is exceeded.
3. When active loaders count is less than **limitCount** the **loader** operation is moved to the **active loaders** list.
4. The operation is executed by the dispatch_barrier_async() invocation.
5. The operation is finished and the user gets proper callback notifications.
*/
- (JFFAsyncOperation)barrierBalancedLoaderWithLoader:(JFFAsyncOperation)loader;

@end
