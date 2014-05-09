#import <Foundation/Foundation.h>


/**
This category automates safe error object assignment to the out parameter pointer.
You can write it in a single statement and get rid of "if" statements.
*/
@interface NSError (SetToPointer)

/**
Sets the "self" error object to the out pointer.

@param outError An out parameter to assign the error to.

@return YES - in case of successful assignment. NO - in case "outError" is NULL.
*/
- (BOOL)setToPointer:(out NSError *__autoreleasing *)outError;

@end
