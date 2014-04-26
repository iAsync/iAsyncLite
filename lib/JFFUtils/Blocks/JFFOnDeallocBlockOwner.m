#import "JFFOnDeallocBlockOwner.h"

@implementation JFFOnDeallocBlockOwner

- (instancetype)initWithBlock:(JFFSimpleBlock)block
{
    self = [super init];
    
    if (nil != self)
    {
        NSParameterAssert( nil != block );
        _block = [block copy];
    }
    
    return self;
}

- (void)dealloc
{
    if ( nil != self->_block)
    {
        self->_block();
    }
}

@end
