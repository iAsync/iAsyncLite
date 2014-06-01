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

+(JFFAsyncOperation)asyncOperation:(JFFAsyncOperation)loader
              withStartActionBlock:(JFFSimpleBlock)startBlock
               finishCallbackBlock:(JFFDidFinishAsyncOperationHandler)finishCallback
{
    NSParameterAssert( nil!= loader         );
    NSParameterAssert( nil!= startBlock     );
    NSParameterAssert( nil!= finishCallback );
    
    return asyncOperationWithStartAndFinishBlocks(loader, startBlock, finishCallback);
}

+(JFFAsyncOperation)asyncOperation:(JFFAsyncOperation)loader
      withOptionalStartActionBlock:(JFFSimpleBlock)startBlock
       optionalFinishCallbackBlock:(JFFDidFinishAsyncOperationHandler)finishCallback
{
    NSParameterAssert( nil!= loader );
    
    return asyncOperationWithOptionalStartAndFinishBlocks( loader, startBlock, finishCallback );
}

+(JFFAsyncOperation)asyncOperation:(JFFAsyncOperation)loader
      withOptionalStartActionBlock:(JFFSimpleBlock)startBlock
         optionalFinishActionBlock:(JFFSimpleBlock)doneBlock
{
    NSParameterAssert( nil!= loader );
    
    return asyncOperationWithStartAndDoneBlocks( loader, startBlock, doneBlock );
}

@end
