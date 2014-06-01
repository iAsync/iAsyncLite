#import "JDoneCallbackAsyncOperationHooks.h"

#import "JFFAsyncOperationContinuity.h"
#import "JFFAsyncOperationHelpers.h"


@implementation JDoneCallbackAsyncOperationHooks

+(JFFAsyncOperation)asyncOperation:(JFFAsyncOperation)loader
               withDoneActionBlock:(JFFSimpleBlock)doneCallbackHook
{
    NSParameterAssert( nil!= loader           );
    NSParameterAssert( nil!= doneCallbackHook );

    return asyncOperationWithDoneBlock(loader, doneCallbackHook);
}


+(JFFAsyncOperation)asyncOperation:(JFFAsyncOperation)loader
             withDoneCallbackBlock:(JFFDidFinishAsyncOperationHandler)doneCallbackHook
{
    NSParameterAssert( nil!= loader           );
    NSParameterAssert( nil!= doneCallbackHook );
    
    return asyncOperationWithFinishCallbackBlock(loader, doneCallbackHook);
}

+(JFFAsyncOperation)asyncOperation:(JFFAsyncOperation)loader
              withDoneCallbackHook:(JFFDidFinishAsyncOperationHook)doneCallbackHook
{
    NSParameterAssert( nil!= loader           );
    NSParameterAssert( nil!= doneCallbackHook );
    
    return asyncOperationWithFinishHookBlock(loader, doneCallbackHook);
}



@end
