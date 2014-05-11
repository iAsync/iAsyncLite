#import <Foundation/Foundation.h>
#include <stdexcept>


/**
 An error object to wrap std::exception thrown in the code of a worker operation.
 */
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
                     userInfo:(NSDictionary *)dict __attribute__((noreturn, unavailable("unsupported initializer")));

/**
 Unsupported initializer.
  @return Throws an exception
 */
-(instancetype)init __attribute__((noreturn, unavailable("unsupported initializer")));

/**
 Unsupported initializer.
 @return Throws an exception
 */
+(instancetype)new __attribute__((noreturn, unavailable("unsupported initializer")));

/**
 Creates an error from an exception.
 
 @param cppExceptionPtr A constant pointer to a C++ exception.
 
 @return A properly initialized error.
 */
-(instancetype)initWithStdException:( const std::exception* )cppExceptionPtr;

/**
 @return A const pointer to the C++ exception object passed in the constructor.
 */
-(const std::exception*)cppExceptionPtr;

@end
