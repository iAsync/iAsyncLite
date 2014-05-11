#import "JStubAsyncOperationConstructors.h"

#import "JFFAsyncOperationHelpers.h"
#import "JFFAsyncOperationsPredefinedBlocks.h"


@implementation JStubAsyncOperationConstructors

+(JFFAsyncOperation)asyncOperationWithResult:(id)result
{
    return asyncOperationWithResult( result );
}


+(JFFAsyncOperation)asyncOperationWithError:(NSError *)error
{
    return asyncOperationWithError( error );
}


+(JFFAsyncOperation)asyncOperationWithCancelFlag:(BOOL)canceled
{
    return asyncOperationWithCancelFlag( canceled );
}


+(JFFAsyncOperation)neverFinishAsyncOperation
{
    return neverFinishAsyncOperation();
}

+(JFFCancelAsyncOperation)stubCancelAsyncOperationBlock
{
    return JFFStubCancelAsyncOperationBlock;
}

@end
