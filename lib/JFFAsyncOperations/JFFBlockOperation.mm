#import "JFFBlockOperation.h"

#import "JGCDAdditions.h"
#import "JObjcExceptionWrapperError.h"
#import "JCppExceptionWrapperError.h"
#import "JUnknownCppExceptionWrapperError.h"


@interface JFFBlockOperation ()

@property (nonatomic, copy) JFFSyncOperationWithProgress      loadDataBlock;
@property (nonatomic, copy) JFFDidFinishAsyncOperationHandler didLoadDataBlock;
@property (nonatomic, copy) JFFAsyncOperationProgressHandler  progressBlock;
@property (atomic) BOOL finishedOrCanceled;

@end


@implementation JFFBlockOperation
{
    dispatch_queue_t _currentQueue;
    BOOL _barrier;
}

- (void)dealloc
{
    NSParameterAssert( nil == self->_didLoadDataBlock );
    NSParameterAssert( nil == self->_progressBlock    );
    NSParameterAssert( nil == self->_loadDataBlock    );
}

- (instancetype)initWithLoadDataBlock:(JFFSyncOperationWithProgress)loadDataBlock
                     didLoadDataBlock:(JFFDidFinishAsyncOperationHandler)didLoadDataBlock
                        progressBlock:(JFFAsyncOperationProgressHandler)progressBlock
                         currentQueue:(dispatch_queue_t)currentQueue
                              barrier:(BOOL)barrier
                   serialOrConcurrent:(dispatch_queue_attr_t)serialOrConcurrent
{
    self = [super init];
    
    if (self) {
        _loadDataBlock    = [loadDataBlock    copy];
        _didLoadDataBlock = [didLoadDataBlock copy];
        _progressBlock    = [progressBlock    copy];
        
        _currentQueue = currentQueue;
        _barrier      = barrier;
    }
    
    return self;
}

- (void)finalizeOperations
{
    _finishedOrCanceled = YES;

    _loadDataBlock    = nil;
    _didLoadDataBlock = nil;
    _progressBlock    = nil;
}

- (void)didFinishOperationWithResult:(id)result
                               error:(NSError *)error
{
    if (self.finishedOrCanceled)
    {
        return;
    }
    
    self->_didLoadDataBlock(result, error);
    
    [self finalizeOperations];
}

- (void)progressWithInfo:(id)info
{
    if ( nil != self->_progressBlock )
    {
        self->_progressBlock(info);
    }
}

- (void)cancel
{
    if (self.finishedOrCanceled)
    {
        return;
    }
    
    [self finalizeOperations];
}

typedef void (*DispatchFunction)(dispatch_queue_t, dispatch_block_t);


-(DispatchFunction)dispatchFunctionForCurrentConfiguration
{
    DispatchFunction dispatchAsyncMethod = NULL;
    
    BOOL isBarrierUsed = self->_barrier;
    if ( isBarrierUsed )
    {
        dispatchAsyncMethod = dispatch_barrier_async;
    }
    else
    {
        dispatchAsyncMethod = dispatch_async;
    }

    return dispatchAsyncMethod;
}

- (void)performBackgroundOperationInQueue:(dispatch_queue_t)queue
                            loadDataBlock:(JFFSyncOperationWithProgress)loadDataBlock
{
    DispatchFunction dispatchAsyncMethod = [ self dispatchFunctionForCurrentConfiguration ];

    
    dispatchAsyncMethod(queue, ^void(){
        if (self.finishedOrCanceled)
        {
            return;
        }
        
        NSError *error = nil;
        id opResult = nil;
        
        
        try
        {
            @try
            {
                JFFAsyncOperationProgressHandler progressCallback = ^(id info)
                {
                    //TODO to garante that finish will called after progress
                    dispatch_async(self->_currentQueue, ^void()
                    {
                        [self progressWithInfo:info];
                    });
                };
                @autoreleasepool
                {
                    opResult = loadDataBlock(&error, progressCallback);
                    NSAssert(((opResult != nil) ^ (error != nil)), @"result xor error should be loaded");
                }
            }
            @catch (NSException *ex)
            {
                NSLog(@"critical error: %@", ex);
                opResult = nil;
                
                JObjcExceptionWrapperError* marshalledException = [ [ JObjcExceptionWrapperError alloc ] initWithObjcException: ex ];
                
                error = marshalledException;
            }
        }
        catch ( const std::exception& cppEx )
        {
            JCppExceptionWrapperError* marshalledException = [ [ JCppExceptionWrapperError alloc ] initWithStdException: &cppEx ];
            error = marshalledException;
            
            // suppressing all exceptions
        }
        catch (...)
        {
            error = [ JUnknownCppExceptionWrapperError new ];
            // suppressing all exceptions
        }

        
        dispatch_async(self->_currentQueue, ^void()
        {
            [self didFinishOperationWithResult:opResult error:error];
        });
    });
}

+ (instancetype)performOperationWithQueueName:(const char*)queueName
                                loadDataBlock:(JFFSyncOperationWithProgress)loadDataBlock
                             didLoadDataBlock:(JFFDidFinishAsyncOperationHandler)didLoadDataBlock
                                progressBlock:(JFFAsyncOperationProgressHandler)progressBlock
                                      barrier:(BOOL)barrier
                                 currentQueue:(dispatch_queue_t)currentQueue
                           serialOrConcurrent:(dispatch_queue_attr_t)serialOrConcurrent
{
    NSParameterAssert(loadDataBlock   );
    NSParameterAssert(didLoadDataBlock);
    NSParameterAssert(currentQueue    );
    
    dispatch_queue_t queue = NULL;
    if (queueName != NULL && strlen(queueName) != 0) {
        queue = dispatch_queue_get_or_create(queueName, serialOrConcurrent);
    } else {
        queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    }
    
    NSAssert(currentQueue != queue, @"Invalid run queue");
    
    JFFBlockOperation *result = [[self alloc] initWithLoadDataBlock:loadDataBlock
                                                   didLoadDataBlock:didLoadDataBlock
                                                      progressBlock:progressBlock
                                                       currentQueue:currentQueue
                                                            barrier:barrier
                                                 serialOrConcurrent:serialOrConcurrent];
    
    [result performBackgroundOperationInQueue:queue
                                loadDataBlock:loadDataBlock];
    
    return result;
}

+ (instancetype)performOperationWithQueueName:(const char *)queueName
                                loadDataBlock:(JFFSyncOperationWithProgress)loadDataBlock
                             didLoadDataBlock:(JFFDidFinishAsyncOperationHandler)didLoadDataBlock
{
    NSParameterAssert([NSThread isMainThread]);
    return [self performOperationWithQueueName:queueName
                                 loadDataBlock:loadDataBlock
                              didLoadDataBlock:didLoadDataBlock
                                 progressBlock:nil
                                       barrier:NO
                                  currentQueue:dispatch_get_main_queue()
                            serialOrConcurrent:DISPATCH_QUEUE_CONCURRENT];
}

@end
