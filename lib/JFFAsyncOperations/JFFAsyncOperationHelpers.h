#ifndef __JASYNC_OPERATION_CONSTRUCTOR_FUNCTIONS_H__
#define __JASYNC_OPERATION_CONSTRUCTOR_FUNCTIONS_H__

#import <JFFAsyncOperations/JFFAsyncOperationsBlockDefinitions.h>
#import <JFFUtils/Blocks/JFFUtilsBlockDefinitions.h>

#include <objc/objc.h>
#include <objc/objc-api.h>


@class NSArray;
@class NSError;


///////////////////////// ADD OBSERVERS OF ASYNC OP. RESULT ////////////////////////

OBJC_EXTERN    JFFAsyncOperation asyncOperationWithResult(id result);
OBJC_EXTERN    JFFAsyncOperation asyncOperationWithError(NSError *error);
OBJC_EXTERN    JFFAsyncOperation asyncOperationWithCancelFlag(BOOL canceled);
OBJC_EXTERN    JFFAsyncOperation neverFinishAsyncOperation(void);
    
OBJC_EXTERN    JFFAsyncOperation asyncOperationWithSyncOperationInCurrentQueue(JFFSyncOperation block);
    
    //finish_callback_block_ called before loader_'s JFFDidFinishAsyncOperationHandler
OBJC_EXTERN    JFFAsyncOperation asyncOperationWithFinishCallbackBlock(JFFAsyncOperation loader,
                                                            JFFDidFinishAsyncOperationHandler finishCallbackBlock);
    
    //finish_callback_hook_ called instead loader_'s JFFDidFinishAsyncOperationHandler
OBJC_EXTERN    JFFAsyncOperation asyncOperationWithFinishHookBlock(JFFAsyncOperation loader,
                                                        JFFDidFinishAsyncOperationHook finishCallbackHook);
    
OBJC_EXTERN    JFFAsyncOperation asyncOperationWithStartAndFinishBlocks(JFFAsyncOperation loader,
                                                             JFFSimpleBlock startBlock,
                                                             JFFDidFinishAsyncOperationHandler finishCallback);
    
OBJC_EXTERN    JFFAsyncOperation asyncOperationWithOptionalStartAndFinishBlocks(JFFAsyncOperation loader,
                                                                     JFFSimpleBlock startBlock,
                                                                     JFFDidFinishAsyncOperationHandler finishCallback);
    
OBJC_EXTERN    JFFAsyncOperation asyncOperationWithStartAndDoneBlocks(JFFAsyncOperation loader,
                                                           JFFSimpleBlock startBlock,
                                                           JFFSimpleBlock doneBlock);
    
OBJC_EXTERN    JFFAsyncOperation asyncOperationWithAnalyzer(id data, JFFAnalyzer analyzer);
    
OBJC_EXTERN    JFFAsyncOperationBinder asyncOperationBinderWithAnalyzer(JFFAnalyzer analyzer);
    
typedef id (^JFFChangedResultBuilder)(id result);
OBJC_EXTERN    JFFAsyncOperation asyncOperationWithChangedResult(JFFAsyncOperation loader,
                                                      JFFChangedResultBuilder resultBuilder);
OBJC_EXTERN    JFFAsyncOperation asyncOperationWithChangedProgress(JFFAsyncOperation loader,
                                                        JFFChangedResultBuilder resultBuilder);
    
OBJC_EXTERN    JFFAsyncOperation asyncOperationResultAsProgress(JFFAsyncOperation loader);
    
typedef NSError *(^JFFChangedErrorBuilder)(NSError *error);
OBJC_EXTERN    JFFAsyncOperation asyncOperationWithChangedError(JFFAsyncOperation loader,
                                                     JFFChangedErrorBuilder errorBuilder);
    
OBJC_EXTERN    JFFAsyncOperation asyncOperationWithResultOrError(JFFAsyncOperation loader,
                                                      id result,
                                                      NSError *error);
    
OBJC_EXTERN    JFFAsyncOperation ignorePregressLoader(JFFAsyncOperation loader);
OBJC_EXTERN    JFFAsyncOperationBinder ignorePregressBinder(JFFAsyncOperationBinder binder);
    
OBJC_EXTERN    JFFAsyncOperation loaderWithAdditionalParalelLoaders(JFFAsyncOperation original, JFFAsyncOperation additionalLoader, ...) NS_REQUIRES_NIL_TERMINATION;
    
    ///////////////////////////////////// SEQUENCE /////////////////////////////////////
    
OBJC_EXTERN    JFFAnalyzer analyzerAsSequenceOfAnalyzers(JFFAnalyzer firstAnalyzer, ...) NS_REQUIRES_NIL_TERMINATION;


#endif //__JASYNC_OPERATION_CONSTRUCTOR_FUNCTIONS_H__

