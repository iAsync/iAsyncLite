#import "JAsyncOperationFlow.h"
#import "JFFAsyncOperationContinuity.h"


@implementation JAsyncOperationFlow


#pragma mark - 
#pragma mark Sequence
+(JFFAsyncOperation)sequenceOfAsyncOperationsArray:(NSArray*)loaders
{
    NSParameterAssert( [ loaders hasElements ] );

    return sequenceOfAsyncOperationsArray( loaders );
}

+(JFFAsyncOperation)sequenceOfAsyncOperationsWithAllResults:(NSArray*)loaders
{
    NSParameterAssert( [ loaders hasElements ] );
    
    return sequenceOfAsyncOperationsWithAllResults( loaders );
}

+(JFFAsyncOperation)sequenceOfAsyncOperationsWithSuccessfullResults:(NSArray*)loaders
{
    NSParameterAssert( [ loaders hasElements ] );
    
    return sequenceOfAsyncOperationsWithSuccessfullResults( loaders );
}

+(JFFAsyncOperation)sequenceUntilFirstSuccessOfAsyncOperationsArray:(NSArray*)loaders
{
    NSParameterAssert( [ loaders hasElements ] );
    
    return trySequenceOfAsyncOperationsArray( loaders );
}


#pragma mark -
#pragma mark Group
+(JFFAsyncOperation)parallelGroupOfAsyncOperations:(NSArray*)loaders
{
    NSParameterAssert( [ loaders hasElements ] );
    
    return groupOfAsyncOperationsArray(loaders);
}

+(JFFAsyncOperation)failOnFirstErrorParallelGroupOfAsyncOperations:(NSArray*)loaders
{
    NSParameterAssert( [ loaders hasElements ] );

    return failOnFirstErrorGroupOfAsyncOperationsArray(loaders);
}



#pragma mark -
#pragma mark Waterfall
+(JFFAsyncOperation)waterfallFlowForAsyncOperation:(JFFAsyncOperation)firstLoader
                                 cascadeOperations:(NSArray*)arrayOfBinders
{
    NSParameterAssert( nil != firstLoader );
    NSParameterAssert( [ arrayOfBinders hasElements ] );

    return bindSequenceOfAsyncOperationsArray( firstLoader, arrayOfBinders );
}

+(JFFAsyncOperation)waterfallFlowUntilFirstSuccessForAsyncOperation:(JFFAsyncOperation)firstLoader
                                                  cascadeOperations:(NSArray*)arrayOfBinders
{
    NSParameterAssert( nil != firstLoader );
    NSParameterAssert( [ arrayOfBinders hasElements ] );
    
    return bindTrySequenceOfAsyncOperationsArray( firstLoader, arrayOfBinders );
}


+(JFFAsyncOperationBinder)sequenceOfCascadeElements:(NSArray*)cascadeElements
{
    NSParameterAssert( [ cascadeElements hasElements ] );
    
    return binderAsSequenceOfBindersArray( cascadeElements );
}

@end
