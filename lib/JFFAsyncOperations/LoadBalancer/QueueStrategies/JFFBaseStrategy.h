#import <Foundation/Foundation.h>

@class JFFQueueState;
@class JFFBaseLoaderOwner;


/**
A base class for execution order strategy.
*/
@interface JFFBaseStrategy : NSObject
{
@protected
    JFFQueueState *_queueState;
}

/**
A task launcher method.

@param pendingLoader A worker block to execute.
*/
- (void)executePendingLoader:(JFFBaseLoaderOwner *)pendingLoader;


/**
A designated initializer.
Note : other initializers are forbidden.

@param queueState A storage for worker objects.

@return A properly initialized strategy object.
*/
- (instancetype)initWithQueueState:(JFFQueueState *)queueState;

@end
