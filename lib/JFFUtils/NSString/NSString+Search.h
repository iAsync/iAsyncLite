#import <Foundation/Foundation.h>


/**
Adds convenience wrappers for [NSString rangeOfString:options:range:] and 
[NSString rangeOfCharacterFromSet:options:range:] methods.
*/
@interface NSString (Search)

/**
Calculates the aggregated amount within **self** of each symbol from the given string.

@param string An NSString object that contains symbols to search for.

@return An amount of the symbols found within the string.
*/
- (NSUInteger)numberOfCharacterFromString:(NSString *)string;


/**
Calculates the number of occurences of the given string within **self**.

@param string A string to search for within the **self** string.

@return Number of full occurences of the given string within **self**.
*/
- (NSUInteger)numberOfStringsFromString:(NSString *)string;


/**
Detects whether **self** contains the given string. 
The strings are compared **case sensitively**.

@param string A string to search for within **self**.

@return YES - in case the given string is found within **self**.
*/
- (BOOL)containsString:(NSString *)string;


/**
Detects whether **self** contains the given string. 
The strings are compared **case insensitively**.

@param string A string to search for within **self**.

@return YES - in case the given string is found within **self**.
*/
- (BOOL)caseInsensitiveContainsString:(NSString *)string;

@end
