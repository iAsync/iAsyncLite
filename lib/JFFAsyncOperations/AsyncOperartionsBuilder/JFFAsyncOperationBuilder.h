#import <JFFAsyncOperations/JFFAsyncOperationsBlockDefinitions.h>

#import <Foundation/Foundation.h>
#include <objc/objc-api.h>


@protocol JFFAsyncOperationInterface;
typedef id<JFFAsyncOperationInterface> (^JFFAsyncOperationInstanceBuilder)(void);


OBJC_EXTERN    JFFAsyncOperation buildAsyncOperationWithAdapterFactory(JFFAsyncOperationInstanceBuilder factory);
    
OBJC_EXTERN    JFFAsyncOperation buildAsyncOperationWithAdapterFactoryWithDispatchQueue(JFFAsyncOperationInstanceBuilder factory, dispatch_queue_t callbacksQueue);
    
