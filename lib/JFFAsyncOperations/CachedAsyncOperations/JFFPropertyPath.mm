#import "JFFPropertyPath.h"

@implementation JFFPropertyPath

- (instancetype)init __attribute__((noreturn))
{
    throw std::runtime_error("Unsupported initializer");
}

- (instancetype)initWithName:(NSString *)name
                         key:(id<NSCopying, NSObject>)key
__attribute__((nonnull (1)))
{
    NSParameterAssert( nil != name );
    self = [ super init ];
    
    
    if ( nil == self) {
        return nil;
    }

    self->_name = name;
    self->_key  = key;

    
    return self;
}

- (NSString *)description
{
    return [[NSString alloc] initWithFormat:@"<JFFPropertyPath name: %@ key: %@>",
            self.name,
            self.key];
}

@end
