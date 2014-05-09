#import <Foundation/Foundation.h>


/**
A category for adding and removing the hook for the [NSObject dealloc] method.
*/
@interface NSObject (OnDeallocBlock)

/**
Adds a hook to the dealloc method.
The block is invoked on the same thread as the [NSObject dealloc] method.
*/
- (void)addOnDeallocBlock:(void(^)(void))block;


/**
Removes a hook from the dealloc method.
It must be the very same object that you've passed to the [NSObject addOnDeallocBlock:]
*/
- (void)removeOnDeallocBlock:(void(^)(void))block;

@end
