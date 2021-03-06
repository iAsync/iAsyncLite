#import "JFFSimpleBlockHolder.h"

@implementation JFFSimpleBlockHolder

-(void)performBlockOnce
{
    if (!_simpleBlock)
    {
        return;
    }
    
    JFFSimpleBlock block = self.simpleBlock;
    self->_simpleBlock = nil;
    
    block();
}

-(JFFSimpleBlock)onceSimpleBlock
{
    return ^void( void )
    {
        [ self performBlockOnce ];
    };
}

@end
