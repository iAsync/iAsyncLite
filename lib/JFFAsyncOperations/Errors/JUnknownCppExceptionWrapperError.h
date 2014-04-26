#import <Foundation/Foundation.h>

@interface JUnknownCppExceptionWrapperError : NSError

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

@end
