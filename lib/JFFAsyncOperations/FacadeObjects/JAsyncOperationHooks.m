#import "JAsyncOperationHooks.h"

#import "JFFAsyncOperationContinuity.h"

@implementation JAsyncOperationHooks

+(JFFAsyncOperation)asyncOperation:(JFFAsyncOperation)loader
                     withDoneBlock:(JFFSimpleBlock)doneCallbackHook
{
    NSParameterAssert( nil!= loader           );
    NSParameterAssert( nil!= doneCallbackHook );

    return asyncOperationWithDoneBlock(loader, doneCallbackHook);
}


@end
