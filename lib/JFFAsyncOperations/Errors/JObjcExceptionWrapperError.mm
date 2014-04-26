#import "JObjcExceptionWrapperError.h"

@implementation JObjcExceptionWrapperError

-(instancetype)initWithDomain:(NSString *)domain
                         code:(NSInteger)code
                     userInfo:(NSDictionary *)dict __attribute__((noreturn))
{
    throw std::runtime_error( "[JUserTaskError] : Unsupported initializer" );
}


-(instancetype)initWithObjcException:( NSException* )objcException
{
    self = [ super initWithDomain: @"org.iasync-lite.scheduler"
                             code: JObjcExceptionErrorCode
                         userInfo: nil ];
    
    if ( nil == self )
    {
        return nil;
    }
    
    self->_objcException = objcException;

    return self;
}


@end
