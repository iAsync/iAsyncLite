#import <JFFUtils/Blocks/JUContainersHelperBlocks.h>
#import <Foundation/Foundation.h>


/**
A category for memory management of the "NSObject+OnDeallocBlock" category.
*/
@interface NSObject (Ownerships)


/**
Adds an object to be retained by **self**.
All ownersips are released in the [NSObject dealloc] method.

@param object An object that will be retained by **self**.
*/
- (void)addOwnedObject:(id)object;


/**
Removes an object retained by **self**. 
The [NSArray removeObject:] is used under the hood.

@param object An object that was previously added to **self**.
*/
- (void)removeOwnedObject:(id)object;


/**
Searches through the attached objects.

@param predicate A predicate to search through attached objects.

@return The object retained by **self** matching the given predicate.
*/
- (id)firstOwnedObjectMatch:(JFFPredicateBlock)predicate;

@end
