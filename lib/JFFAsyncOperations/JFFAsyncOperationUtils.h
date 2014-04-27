#ifndef __JASYNC_OPERATION_WITH_QUEUE_CONSTRUCTOR_FUNCTIONS_H__
#define __JASYNC_OPERATION_WITH_QUEUE_CONSTRUCTOR_FUNCTIONS_H__

#import <JFFAsyncOperations/JFFAsyncOperationsBlockDefinitions.h>
#include <objc/objc-api.h>


OBJC_EXTERN    JFFAsyncOperation asyncOperationWithSyncOperation(JFFSyncOperation loadDataBlock);
    
OBJC_EXTERN    JFFAsyncOperation asyncOperationWithSyncOperationAndQueue(JFFSyncOperation loadDataBlock,
                                                              const char *queueName);
    
OBJC_EXTERN    JFFAsyncOperation asyncOperationWithSyncOperationAndConfigurableQueue(JFFSyncOperation loadDataBlock, const char *queueName, BOOL isSerialQueue);
    
OBJC_EXTERN    JFFAsyncOperation barrierAsyncOperationWithSyncOperationAndQueue(JFFSyncOperation loadDataBlock,
                                                                     const char *queueName);
    
OBJC_EXTERN    JFFAsyncOperation asyncOperationWithSyncOperationWithProgressBlock(JFFSyncOperationWithProgress progressLoadDataBlock);


#endif //__JASYNC_OPERATION_WITH_QUEUE_CONSTRUCTOR_FUNCTIONS_H__

