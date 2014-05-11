#import <JFFAsyncOperations/JFFAsyncOperationsBlockDefinitions.h>
#import <Foundation/Foundation.h>

@class JFFPropertyPath;
@class JFFPropertyExtractor;


/**
 A block that constructs an object of the JFFPropertyExtractor class.
 It implements the **"Factory"** design pattern.
 */
typedef JFFPropertyExtractor *(^JFFPropertyExtractorFactoryBlock)(void);


/**
 A category to simplify asynchronous loading of object's properties.
 */
@interface NSObject (AsyncPropertyReader)

/**
 Binds the asynchronous operation with a given property.
 The operation's result will be written to the property on successful execution.
 
 @param propertyName A property to store the operation result.
 Note : its name must match with the NSStringFromSelector() value.
 
 @param asyncOperation An operation that does the data loading job.
 
 
 @return A new operation that loads the data and stores the result into the corresponding property.
 */
- (JFFAsyncOperation)asyncOperationForPropertyWithName:(NSString *)propertyName
                                        asyncOperation:(JFFAsyncOperation)asyncOperation;


- (JFFAsyncOperation)asyncOperationForPropertyWithName:(NSString *)propertyName
                                        asyncOperation:(JFFAsyncOperation)asyncOperation
                                didFinishLoadDataBlock:(JFFDidFinishAsyncOperationHandler)didFinishOperation;

- (JFFAsyncOperation)asyncOperationForPropertyWithPath:(JFFPropertyPath *)propertyPath
                                        asyncOperation:(JFFAsyncOperation)asyncOperation;

- (JFFAsyncOperation)asyncOperationForPropertyWithPath:(JFFPropertyPath *)propertyPath
                                        asyncOperation:(JFFAsyncOperation)asyncOperation
                                didFinishLoadDataBlock:(JFFDidFinishAsyncOperationHandler)didFinishOperation;

- (JFFAsyncOperation)asyncOperationForPropertyWithPath:(JFFPropertyPath *)propertyPath
                         propertyExtractorFactoryBlock:(JFFPropertyExtractorFactoryBlock)factory
                                        asyncOperation:(JFFAsyncOperation)asyncOperation;

- (JFFAsyncOperation)asyncOperationForPropertyWithPath:(JFFPropertyPath *)propertyPath
                         propertyExtractorFactoryBlock:(JFFPropertyExtractorFactoryBlock)factory
                                        asyncOperation:(JFFAsyncOperation)asyncOperation
                                didFinishLoadDataBlock:(JFFDidFinishAsyncOperationHandler)didFinishOperation;

/**
 */
- (JFFAsyncOperation)asyncOperationMergeLoaders:(JFFAsyncOperation)asyncOperation
                                   withArgument:(id< NSCopying, NSObject >)argument;

- (BOOL)isLoadingPropertyForPropertyName:(NSString *)name;

/**
 */
+ (JFFAsyncOperation)asyncOperationMergeLoaders:(JFFAsyncOperation)asyncOperation
                                   withArgument:(id< NSCopying, NSObject >)argument;

@end
