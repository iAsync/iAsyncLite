#import "JCppExceptionWrapperError.h"

using namespace ::std;

@implementation JCppExceptionWrapperError
{
    const std::exception* _cppException;
}

-(instancetype)initWithDomain:(NSString *)domain
                         code:(NSInteger)code
                     userInfo:(NSDictionary *)dict __attribute__((noreturn))
{
    throw std::runtime_error( "[JUserTaskError] : Unsupported initializer" );
}


-(instancetype)initWithStdException:( const std::exception* )cppException;
{
    self = [ super initWithDomain: @"org.iasync-lite.scheduler"
                             code: JStdCppExceptionErrorCode
                         userInfo: nil ];
    
    if ( nil == self )
    {
        return nil;
    }
    
    self->_cppException = cppException;
    
    return self;
}

-(const std::exception*)cppExceptionPtr
{
    return self->_cppException;
}

@end
