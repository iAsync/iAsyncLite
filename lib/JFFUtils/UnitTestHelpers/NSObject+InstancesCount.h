#import <Foundation/Foundation.h>

/**
This category exposes instances counting for objects of a given class.
It should be used for unit testing only.
*/
@interface NSObject (InstancesCount)

/**
Adds the required runtime hooks.
*/
+ (void)enableInstancesCounting;

/**
Gets the number of objects for the given class.

@return Amount of objects of this class.
*/
+ (NSUInteger)instancesCount;

@end
