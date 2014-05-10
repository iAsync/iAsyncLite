#import <JFFAsyncOperations/JFFAsyncOperationsBlockDefinitions.h>
#import <Foundation/Foundation.h>


typedef JFFAsyncOperation (^JFFAsyncDictMappingBlock)(id key, id object);


/**
A category to perform map/reduce actions asynchronously in the background thread.
*/
@interface NSDictionary (AsyncMap)

/**
Creates an operation that performs the block with each dictionary key-value pair simultaneously.
The resulting dictionary will be returned in the completion callback of the async operation.

Note : if the block returns at least one error, the entire operation will be marked as "failed".
The entire operation will also be cancelled.

@param block A block to construct an asynchronous operation with the given key-value pair.

@return An asycnhronous operation that performs actions on dictionary ke-value pair elements in parallel.
*/
- (JFFAsyncOperation)asyncMap:(JFFAsyncDictMappingBlock)block;

@end
