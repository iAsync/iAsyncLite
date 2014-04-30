#import <JFFAsyncOperations/JFFAsyncOperationsBlockDefinitions.h>
#import <Foundation/Foundation.h>

@class JFFPropertyPath;


/**
 A class to hold the information about a property that is being asynchronously loaded.
 
 Note : As an end user of iAsync, you should not instantiate objects of this class directly.
 */
@interface JFFPropertyExtractor : NSObject

/**
 Property path. The notation is the same as the one used for KVC.

 WARNING : Do not pass properties with primitive types (int/BOOL/...)
 */
@property ( nonatomic ) JFFPropertyPath* propertyPath;

/**
 An object the property has been declared on
 */
@property ( nonatomic ) NSObject* object;



/**
 An array of JFFCallbacksBlocksHolder objects.
 In case multiple operations have been called and merged into a single one, their callback blocks are stored in this array. Once the operation is cancelled or completed, the corresponding blocks are invoked for all delegate objects.
 */
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
 Asynchronous operation result is stored in this object.
 */
@property (nonatomic) id property;

/**
 Make the JFFPropertyExtractor object forget about the corresponding property and the object that owns the property.
 
 Note : this method is used to cancel asynchronous operations.
 */
- (void)clearData;

@end
