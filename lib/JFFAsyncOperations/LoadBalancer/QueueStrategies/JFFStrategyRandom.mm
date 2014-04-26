#import "JFFStrategyRandom.h"

#import "JFFQueueState.h"

@implementation JFFStrategyRandom

- (JFFBaseLoaderOwner *)firstPendingLoader
{
    NSUInteger pendingLoadersCount = [self->_queueState->_pendingLoaders count];
    int castedLoadersCount = static_cast<int>( pendingLoadersCount );
    
    int index = rand() % castedLoadersCount;
    NSUInteger castedIndex = static_cast<NSUInteger>(index);
    
    JFFBaseLoaderOwner *result = _queueState->_pendingLoaders[castedIndex];
    return result;
}

@end
