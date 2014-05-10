#import <JFFAsyncOperations/JFFAsyncOperationsBlockDefinitions.h>
#import <Foundation/Foundation.h>


/**
A category to cancel operations associated to an object.
Once the object is destroyed the operation gets cancelled.
*/
@interface NSObject (WeakAsyncOperation)


/**
Wraps an operation so that it gets cancelled once **self** object is deallocated.

@param asyncOp An operation that performs some job asynchronously.

@return An operation that will be cancelled once **self** gets deallocated.
*/
- (JFFAsyncOperation)autoUnsubsribeOnDeallocAsyncOperation:(JFFAsyncOperation)asyncOp;


/**
Wraps an operation so that its users stop receiving events from it once **self** object is deallocated.

@param asyncOp An operation that performs some job asynchronously.

@return Once **self** gets deallocated, the users will stop receiving events from the operation.
*/
- (JFFAsyncOperation)autoCancelOnDeallocAsyncOperation:(JFFAsyncOperation)asyncOp;

@end
