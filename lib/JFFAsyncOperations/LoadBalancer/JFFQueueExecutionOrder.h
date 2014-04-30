#ifndef JFFAsyncOperations_JFFQueueExecutionOrder_h
#define JFFAsyncOperations_JFFQueueExecutionOrder_h

#import <Foundation/Foundation.h>

/**
 This enum describes the strategy of asynchronous operations processing by the JFFLimitedLoadersQueue class.
 */
typedef NS_ENUM(NSInteger, JFFQueueExecutionOrder)
{
    /**
     "First In - First Out" - FIFO.
     The default queue order.
     */
    JQOrderFifo   = 0,
    
    /**
     "Last In - First Out" - LIFO.
     The recently added operations have the highest priority.
     */
    JQOrderStack  = 1,
    
    /**
     The order does not matter. The tasks are executed in a random order.
     A uniform distribution is used.
     */
    JQOrderRandom = 2,
};

#endif
