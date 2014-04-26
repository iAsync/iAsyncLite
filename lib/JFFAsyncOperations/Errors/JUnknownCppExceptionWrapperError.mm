#import "JUnknownCppExceptionWrapperError.h"

@implementation JUnknownCppExceptionWrapperError

-(instancetype)initWithDomain:(NSString *)domain
                         code:(NSInteger)code
                     userInfo:(NSDictionary *)dict __attribute__((noreturn))
{
    throw std::runtime_error( "[JUserTaskError] : Unsupported initializer" );
}

-(instancetype)init
{
    self = [ super initWithDomain: @"org.iasync-lite.scheduler"
                             code: JUnknownCppExceptionErrorCode
                         userInfo: nil ];
    
    return nil;
}

@end
