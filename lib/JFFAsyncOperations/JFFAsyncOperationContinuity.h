#ifndef __JASYNC_OPERATIONS_FLOW_H__
#define __JASYNC_OPERATIONS_FLOW_H__

#import <JFFAsyncOperations/JFFAsyncOperationsBlockDefinitions.h>
#import <JFFUtils/Blocks/JFFUtilsBlockDefinitions.h>

#include <objc/objc.h>
#include <objc/objc-api.h>

@class NSArray;
@class NSError;

///////////////////////////////////// SEQUENCE /////////////////////////////////////

//calls loaders while success
OBJC_EXTERN    JFFAsyncOperation sequenceOfAsyncOperations(JFFAsyncOperation firstLoader,
                                                JFFAsyncOperation secondLoader, ...) NS_REQUIRES_NIL_TERMINATION __attribute__((pure,const));
    
OBJC_EXTERN    JFFAsyncOperation sequenceOfAsyncOperationsArray(NSArray *loaders);
    
/////////////////////////////// SEQUENCE ACCUMULATOR ///////////////////////////////
    
    typedef id (^JFFSequenceResultAccumulator)(id waterfallResult,
                                               id loaderResult,
                                               NSError *loaderError);
    
OBJC_EXTERN    JFFAsyncOperation accumulateSequenceResult(NSArray *loaders, JFFSequenceResultAccumulator resultAccumulator);

OBJC_EXTERN    JFFAsyncOperation sequenceOfAsyncOperationsWithAllResults(NSArray *blocks);
    
OBJC_EXTERN    JFFAsyncOperation sequenceOfAsyncOperationsWithSuccessfullResults(NSArray *blocks);
    
/////////////////////////////// SEQUENCE WITH BINDING ///////////////////////////////

//calls binders while success
OBJC_EXTERN    JFFAsyncOperationBinder binderAsSequenceOfBinders(JFFAsyncOperationBinder firstBinder, ...) NS_REQUIRES_NIL_TERMINATION __attribute__((pure,const));
    
OBJC_EXTERN    JFFAsyncOperationBinder binderAsSequenceOfBindersArray(NSArray *binders);
    
//calls binders while success
OBJC_EXTERN    JFFAsyncOperation bindSequenceOfAsyncOperations(JFFAsyncOperation firstLoader,
                                                    JFFAsyncOperationBinder secondLoaderBinder, ...) NS_REQUIRES_NIL_TERMINATION __attribute__((pure,const));
    
OBJC_EXTERN    JFFAsyncOperation bindSequenceOfAsyncOperationsArray(JFFAsyncOperation firstLoader,
                                                         NSArray *loadersBinders) __attribute__((pure,const));
    
/////////////////////////////////// TRY SEQUENCE ///////////////////////////////////

//calls loaders untill success
OBJC_EXTERN    JFFAsyncOperation trySequenceOfAsyncOperations(JFFAsyncOperation firstLoader,
                                                   JFFAsyncOperation secondLoader, ...) NS_REQUIRES_NIL_TERMINATION __attribute__((pure,const));
    
OBJC_EXTERN    JFFAsyncOperation trySequenceOfAsyncOperationsArray(NSArray *loaders) __attribute__((pure,const));
    
/////////////////////////////// TRY SEQUENCE WITH BINDING ///////////////////////////////
    
//calls loaders while success
//@@ next binder will receive an error if previous operation fails
OBJC_EXTERN    JFFAsyncOperation bindTrySequenceOfAsyncOperations(JFFAsyncOperation firstLoader,
                                                       JFFAsyncOperationBinder secondLoaderBinder,
                                                       ...) NS_REQUIRES_NIL_TERMINATION __attribute__((pure,const));
    
//@@ next binder will receive an error if previous operation fails
OBJC_EXTERN    JFFAsyncOperation bindTrySequenceOfAsyncOperationsArray(JFFAsyncOperation firstLoader,
                                                            NSArray *loadersBinders) __attribute__((pure,const));
    
/////////////////////////////////////// GROUP //////////////////////////////////////
    
//calls finish callback when all loaders finished
OBJC_EXTERN    JFFAsyncOperation groupOfAsyncOperations(JFFAsyncOperation firstLoader, ...) NS_REQUIRES_NIL_TERMINATION __attribute__((pure,const));
    
OBJC_EXTERN    JFFAsyncOperation groupOfAsyncOperationsArray(NSArray *loaders) __attribute__((pure,const));
    
///////////////////////////// FAIL ON FIRST ERROR GROUP ////////////////////////////

//calls finish callback when all loaders success finished or when any of them is failed
OBJC_EXTERN    JFFAsyncOperation failOnFirstErrorGroupOfAsyncOperations(JFFAsyncOperation firstLoader, ...) NS_REQUIRES_NIL_TERMINATION __attribute__((pure,const));

OBJC_EXTERN    JFFAsyncOperation failOnFirstErrorGroupOfAsyncOperationsArray(NSArray *loaders) __attribute__((pure,const));

///////////////////////// ADD OBSERVERS OF ASYNC OP. RESULT ////////////////////////

    //doneCallbackHook called an cancel or finish loader_'s callbacks
OBJC_EXTERN    JFFAsyncOperation asyncOperationWithDoneBlock(JFFAsyncOperation loader,
                                                  JFFSimpleBlock doneCallbackHook) __attribute__((pure,const));

#endif // __JASYNC_OPERATIONS_FLOW_H__

