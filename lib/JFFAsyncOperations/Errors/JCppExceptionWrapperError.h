#import <Foundation/Foundation.h>

#include <stdexcept>

@interface JCppExceptionWrapperError : NSError

/**
 Unsupported initializer.
 
 @param domain The error domain—this can be one of the predefined NSError domains, or an arbitrary string describing a custom domain. domain must not be nil. See “Error Domains” for a list of predefined domains.
 
 @param code The error code for the error.
 
 @param dict The userInfo dictionary for the error. userInfo may be nil.
 
 @return Throws an exception
 */
-(instancetype)initWithDomain:(NSString *)domain
                         code:(NSInteger)code
                     userInfo:(NSDictionary *)dict __attribute__((noreturn));


/**
 Creates an error from an exception.
 
 @param cppException A constant pointer to a C++ exception.
 
 @return A properly initialized error.
 */
-(instancetype)initWithStdException:( const std::exception* )cppExceptionPtr;

/**
 A const pointer to the C++ exception object passed in the constructor.
 */
-(const std::exception*)cppExceptionPtr;

@end
