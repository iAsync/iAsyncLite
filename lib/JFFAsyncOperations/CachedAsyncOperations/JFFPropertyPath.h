#import <Foundation/Foundation.h>


/**
 A class to hold information about asynchronously loaded properties.
 */
@interface JFFPropertyPath : NSObject

/**
 A name used in the "@property" declaration
 */
@property (nonatomic, readonly) NSString *name;

/**
 An object for asynchronous operations uniquing. It comes from the user either in -[NSObject asyncOperationMergeLoaders:withArgument:] or in +[NSObject asyncOperationMergeLoaders:withArgument:]
 
 Note : operations with the same key
 */
@property (nonatomic, readonly) id<NSCopying, NSObject> key;


/**
 @param name A name used in the "@property" declaration.
 Note : do not pass nil
 
 @param key An object for asynchronous operations uniquing. It comes from the user in [NSObject asyncOperationMergeLoaders:withArgument:]
 Note : nil can be passed if loaders of the corresponding property should never be merged.
 
 @return A properly initialized object.
 */
- (instancetype)initWithName:(NSString *)name
                         key:(id< NSCopying, NSObject >)key
__attribute__((nonnull (1)));


/**
 Unsupported initializer.
 
 @return Throws std::runtime_error exception.
 */
- (instancetype)init __attribute__((noreturn));

@end
