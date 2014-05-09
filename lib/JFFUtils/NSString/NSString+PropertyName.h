#import <Foundation/Foundation.h>


/**
A category for parsing data from the **class_copyPropertyList()** method.
*/
@interface NSString (PropertyName)

/**
Returns the name of the getter property that can be used with NSSelectorFromString()

@return A name of the getter property that can be used with NSSelectorFromString()
*/
- (instancetype)propertyGetNameFromPropertyName;


/**
Returns the name of the setter property that can be used with NSSelectorFromString()

@return A name of the setter property that can be used with NSSelectorFromString()
*/
- (instancetype)propertySetNameForPropertyName;

@end
