#import "JAsyncOperationHooks.h"

#import "JFFAsyncOperationHelpers.h"


@implementation JAsyncOperationHooks


+(JFFAsyncOperation)asyncOperation:(JFFAsyncOperation)loader
                 withChangedResult:(JFFChangedResultBuilder)resultBuilder
{
    NSParameterAssert( nil != loader );
    NSParameterAssert( nil != resultBuilder );
    
    return asyncOperationWithChangedResult( loader, resultBuilder );
}


+(JFFAsyncOperation)asyncOperation:(JFFAsyncOperation)loader
               withChangedProgress:(JFFChangedResultBuilder)resultBuilder

{
    NSParameterAssert( nil != loader );
    NSParameterAssert( nil != resultBuilder );
    
    return asyncOperationWithChangedProgress( loader, resultBuilder );
}


+(JFFAsyncOperation)asyncOperationResultAsProgress:(JFFAsyncOperation)loader
{
    NSParameterAssert( nil != loader );
    
    return asyncOperationResultAsProgress( loader );
}

+(JFFAsyncOperation)asyncOperation:(JFFAsyncOperation)loader
                  withChangedError:(JFFChangedErrorBuilder)errorBuilder
{
    NSParameterAssert( nil != loader );
    NSParameterAssert( nil != errorBuilder );

    
    return asyncOperationWithChangedError( loader, errorBuilder );
}

+(JFFAsyncOperation)asyncOperation:(JFFAsyncOperation)loader
                              withResult:(id)result
                                 orError:(NSError*)error
{
    return asyncOperationWithResultOrError(loader, result, error);
}

@end
