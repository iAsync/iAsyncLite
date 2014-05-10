#import <JFFAsyncOperations/JFFAsyncOperationsBlockDefinitions.h>
#import <Foundation/Foundation.h>
#include <objc/objc-api.h>




/**
Restricts operations execution to some limits and schedules on the current context.

Note : no more than 5 concurrent operations per context are allowed.
There is no API to configure this limit without recompiling the library.

@param loader An operation that performs some work.
Warning : do not balance the same loader twice

@return A restricted operation.
*/
OBJC_EXTERN JFFAsyncOperation balancedAsyncOperation(JFFAsyncOperation loader);


/**
Restricts operations execution to some limits and schedules on the given context.

Note : no more than 5 concurrent operations per context are allowed.
There is no API to configure this limit without recompiling the library.

@param loader An operation that performs some work.
Warning : do not balance the same loader twice

@param contextName A name of the context to schedule.

@return A restricted operation.
*/
OBJC_EXTERN JFFAsyncOperation balancedAsyncOperationInContext(JFFAsyncOperation loader, NSString *contextName);





/**
Activates the context with a given name.

@param contextName A name of the context to activate.
*/
OBJC_EXTERN void setBalancerActiveContextName(NSString *contextName);


/**
*/
OBJC_EXTERN NSString *balancerActiveContextName (void);


/**
*/
OBJC_EXTERN NSString *balancerCurrentContextName(void);

