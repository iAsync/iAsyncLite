#import <JFFAsyncOperations/JFFAsyncOperationsBlockDefinitions.h>

#import <Foundation/Foundation.h>

@class JFFPropertyPath;


/**
 A class to hold the information about a property that is being asynchronously loaded.
 */
@interface JFFPropertyExtractor : NSObject

/**
 Property path. The notation is the same as the one used for KVC.

 WARNING : Do not pass properties with primitive types (int/BOOL/...)
 */
@property ( nonatomic ) JFFPropertyPath* propertyPath;

/**
 ???
 */
@property ( nonatomic ) NSObject* object;



//object related data
@property (nonatomic) NSMutableArray *delegates;

/**
 A block to cancel object loading.
 */
@property (nonatomic, copy) JFFCancelAsyncOperation cancelBlock;

/**
 A block to start loading the object.
 */
@property (nonatomic, copy) JFFAsyncOperation asyncLoader;

/**
 A block to notify the user about operation success or failure.
 */
@property (nonatomic, copy) JFFDidFinishAsyncOperationHandler didFinishBlock;

/**
 */
@property (nonatomic) id property;

/**
 */
- (void)clearData;

@end
