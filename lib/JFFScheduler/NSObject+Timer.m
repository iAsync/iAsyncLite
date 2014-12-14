#import "NSObject+Timer.h"

#import "JFFTimer.h"

#import <JFFUtils/NSString/NSString+Search.h>




@implementation NSObject (Timer)

- (void)performSelector:(SEL)selector
           timeInterval:(NSTimeInterval)timeInterval
                 leeway:(NSTimeInterval)leeway
               userInfo:(id)userInfo
                repeats:(BOOL)repeats
                  timer:(JFFTimer *)timer
{
    NSParameterAssert(timer);
    
    //use signature's number params
    NSString *selectorString = NSStringFromSelector(selector);
    NSUInteger numOfArgs = [selectorString numberOfCharacterFromString:@":"];
    NSAssert1(numOfArgs == 0 || numOfArgs == 1,
              @"selector \"%@\" should has 0 or 1 parameters",
              selectorString);
    
    __unsafe_unretained id unretainedSelf = self;
    
    JFFScheduledBlock block = ^void(JFFCancelScheduledBlock cancel) {
        if (!repeats) {
            [unretainedSelf removeOnDeallocBlock:cancel];
            cancel();
        }
        
        if (numOfArgs == 1)
        {
            typedef void(*MethodWithUserInfo)( id, SEL, id);
            MethodWithUserInfo selInvoker = (MethodWithUserInfo)objc_msgSend;
            
            selInvoker(unretainedSelf, selector, userInfo);
        }
        else
        {
            typedef void(*MethodWithoutUserInfo)( id, SEL);
            MethodWithoutUserInfo selInvoker = (MethodWithoutUserInfo)objc_msgSend;
            
            selInvoker(unretainedSelf, selector);
        }
    };
    
    JFFCancelScheduledBlock cancel = [timer addBlock:block
                                            duration:timeInterval
                                              leeway:leeway];
    [self addOnDeallocBlock:cancel];
}

- (void)performSelector:(SEL)selector
           timeInterval:(NSTimeInterval)timeInterval
                 leeway:(NSTimeInterval)leeway
               userInfo:(id)userInfo
                repeats:(BOOL)repeats
{
    [self performSelector:selector
             timeInterval:timeInterval
                   leeway:leeway
                 userInfo:userInfo
                  repeats:repeats
                    timer:[JFFTimer sharedByThreadTimer]];
}

@end
