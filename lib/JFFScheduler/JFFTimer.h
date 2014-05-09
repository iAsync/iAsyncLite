#import <Foundation/Foundation.h>

typedef void (^JFFCancelScheduledBlock) (void);
typedef void (^JFFScheduledBlock) (JFFCancelScheduledBlock cancel);


/**
This class allows scheduling blocks on the background queue.
*/
@interface JFFTimer : NSObject


/**
A preferred singleton initializer. 

@return A properly initialized shared instance.
*/
+ (instancetype)sharedByThreadTimer;


/**
Add new block to timer which will be invoked on the current thread using the default mode after a delay.
The invocation will be canceled at removing "timer" object from memory.

@param block A block to execute later.
@param duration Time interval for delaying the block.

@return The block to cancel a scheduled operation.
*/
- (JFFCancelScheduledBlock)addBlock:(JFFScheduledBlock)block
                           duration:(NSTimeInterval)duration;


/**
Add new block to timer which will be invoked on the current thread using the default mode after a delay.
The invocation will be canceled at removing "timer" object from memory.

@param block A block to execute later.
@param duration Time interval for delaying the block.
@param leeway  Any fire of the timer may be delayed by the system in order to improve power consumption and system
     performance. The upper limit to the allowable delay may be configured with the leeway argument, the
     lower limit is under the control of the system.

@return The block to cancel a scheduled operation.
*/
- (JFFCancelScheduledBlock)addBlock:(JFFScheduledBlock)block
                           duration:(NSTimeInterval)duration
                             leeway:(NSTimeInterval)leeway;



/**
Add new block to timer which will be invoked on the current thread using the default mode after a delay.
The invocation will be canceled at removing "timer" object from memory.

@param block A block to execute later.
@param duration Time interval for delaying the block.
@param dispatchQueue The dispatch queue to which the event handler block is submitted.

@return The block to cancel a scheduled operation.
*/
- (JFFCancelScheduledBlock)addBlock:(JFFScheduledBlock)block
                           duration:(NSTimeInterval)duration
                      dispatchQueue:(dispatch_queue_t)dispatchQueue;


/**
Add new block to timer which will be invoked on the current thread using the default mode after a delay.
The invocation will be canceled at removing "timer" object from memory.

@param block A block to execute later.
@param duration Time interval for delaying the block.
@param leeway  Any fire of the timer may be delayed by the system in order to improve power consumption and system
     performance. The upper limit to the allowable delay may be configured with the leeway argument, the
     lower limit is under the control of the system.
@param dispatchQueue The dispatch queue to which the event handler block is submitted.

@return The block to cancel a scheduled operation.
*/
- (JFFCancelScheduledBlock)addBlock:(JFFScheduledBlock)block
                           duration:(NSTimeInterval)duration
                             leeway:(NSTimeInterval)leeway
                      dispatchQueue:(dispatch_queue_t)dispatchQueue;

/**
Cancel all delayed invocations for self.
*/
- (void)cancelAllScheduledOperations;

@end
