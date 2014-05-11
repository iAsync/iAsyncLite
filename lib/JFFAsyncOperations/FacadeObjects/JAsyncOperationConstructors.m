#import "JAsyncOperationConstructors.h"
#import "JFFAsyncOperationUtils.h"

@implementation JAsyncOperationConstructors

+(JFFAsyncOperation)asyncOperationWithSyncOperation:(JFFSyncOperation)loadDataBlock
{
    NSParameterAssert( nil != loadDataBlock );
    
    return asyncOperationWithSyncOperation( loadDataBlock );
}


+(JFFAsyncOperation)asyncOperationWithSyncOperation:(JFFSyncOperation)loadDataBlock
                                           andQueue:(NSString*)queueName
{
    NSParameterAssert( nil != loadDataBlock );
    NSParameterAssert( nil != queueName     );
    
    return asyncOperationWithSyncOperationAndQueue
    (
       loadDataBlock,
       [ queueName cStringUsingEncoding: NSUTF8StringEncoding ]
    );
}


+(JFFAsyncOperation)asyncOperationWithSyncOperationAndConfigurableQueue:(JFFSyncOperation)loadDataBlock
                                                                  queue:(NSString*)queueName
                                                          isSerialQueue:(BOOL)isSerialQueue
{
    NSParameterAssert( nil != loadDataBlock );
    NSParameterAssert( nil != queueName     );
    
    return asyncOperationWithSyncOperationAndConfigurableQueue
    (
       loadDataBlock,
       [ queueName cStringUsingEncoding: NSUTF8StringEncoding ],
       isSerialQueue
    );
}


+(JFFAsyncOperation)barrierAsyncOperationWithSyncOperation:(JFFSyncOperation)loadDataBlock
                                                  andQueue:(NSString*)queueName
{
    NSParameterAssert( nil != loadDataBlock );
    NSParameterAssert( nil != queueName     );

    return barrierAsyncOperationWithSyncOperationAndQueue
    (
       loadDataBlock,
       [ queueName cStringUsingEncoding: NSUTF8StringEncoding ]
    );
}


+(JFFAsyncOperation)asyncOperationWithSyncOperationWithProgressBlock:(JFFSyncOperationWithProgress)progressLoadDataBlock
{
    NSParameterAssert( nil != progressLoadDataBlock );
    
    return asyncOperationWithSyncOperationWithProgressBlock( progressLoadDataBlock );
}

@end
