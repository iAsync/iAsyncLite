#import <Foundation/Foundation.h>


/**
A category to check whether the string is empty or not.
This approach is more human friendly rather than comparing [NSString length] to zero.
*/
@interface NSString (IsEmpty)

/**
Checks whether the string is empty.

@return YES - in case the string contains at least one symbol. 
NO - for nil and empty ( @"" ) strings.
*/
- (BOOL)hasSymbols;


/** 
Checks whether the string contains characters from the [NSCharacterSet whitespaceAndNewlineCharacterSet]

@return YES - in case the string contains whitespaces. 
NO - in case no whitespaces have been found.
NO - for nil and empty ( @"" ) strings.
*/
- (BOOL)hasNonWhitespaceSymbols;

@end
