#import <Foundation/Foundation.h>

@class JFFTimer;


/**
A category to perform methods with delay.
*/
@interface NSObject (Timer)


/**
Invokes a method of the receiver on the current thread using the default mode after a delay.
The "receiver" object is not retained by this method.
The invocation will be canceled when "receiver" object is removed from memory

@param selector A selector to execute. It should have either zero or one parameter.
@param timeInterval Time interval for delaying the block. The same value is used for repeating the calls in case **repeats** flag is set to YES.
@param leeway Any fire of the timer may be delayed by the system in order to improve power consumption and system
     performance. The upper limit to the allowable delay may be configured with the leeway argument, the
     lower limit is under the control of the system.
@param userInfo This object will be passed to 
@param repeats If this flag is set to "NO", the block will be delayed. Otherwise the block will be repeated forever with the given delay.
*/
- (void)performSelector:(SEL)selector
           timeInterval:(NSTimeInterval)timeInterval
                 leeway:(NSTimeInterval)leeway
               userInfo:(id)userInfo
                repeats:(BOOL)repeats;


/**
Invokes a method of the receiver on the current thread using the default mode after a delay.
The "receiver" object is not retained by this method.
The invocation will be canceled when "receiver" object is removed from memory

@param selector A selector to execute. It should have either zero or one parameter.
@param timeInterval Time interval for delaying the block. The same value is used for repeating the calls in case **repeats** flag is set to YES.
@param leeway Any fire of the timer may be delayed by the system in order to improve power consumption and system
     performance. The upper limit to the allowable delay may be configured with the leeway argument, the
     lower limit is under the control of the system.
@param userInfo This object will be passed to 
@param repeats If this flag is set to "NO", the block will be delayed. Otherwise the block will be repeated forever with the given delay.
@param timer A JFFTimer object that will be used for blocks scheduling.
*/
- (void)performSelector:(SEL)selector
           timeInterval:(NSTimeInterval)timeInterval
                 leeway:(NSTimeInterval)leeway
               userInfo:(id)userInfo
                repeats:(BOOL)repeats
                  timer:(JFFTimer *)timer;

@end
