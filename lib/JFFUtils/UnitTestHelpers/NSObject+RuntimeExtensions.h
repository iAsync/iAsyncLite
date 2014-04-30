#import <Foundation/Foundation.h>



/**
 Categories for method swizzling.
 They can be extremely useful in unit tests for mocking.
 */
@interface NSObject (RuntimeExtensions)


/**
 Adds an instance method to the **targetClass** if it does not have one.
 
```
 
    [ ClassA addInstanceMethodIfNeedWithSelector: @selector( doWork )
                                         toClass: [ ClassB class ] ];
 
    ClassB* b = [ ClassB new ];
 
    [ b doWork ]; // Will call -[ ClassA doWork ]

 ```
 
 @param selector A selector of the current class to be executed with the **targetClass**
 @param targetClass A class that gets a new instance method
 
 @return YES - In case a new method has been added to the **targetClass**
 NO - In case a method already existed.
 NO - In case of any objc-runtime errors.
 */
+ (BOOL)addInstanceMethodIfNeedWithSelector:(SEL)selector
                                    toClass:(Class)targetClass;



/**
 Adds an instance method to the **targetClass** if it does not have one.
 
 ```
 
    [ ClassA addInstanceMethodIfNeedWithSelector: @selector( doWork )
                                         toClass: [ ClassB class ]
                               newMethodSelector: @selector( doWorkFooBar ) ];
 
    ClassB* b = [ ClassB new ];
 
    [ b doWork       ]; // Throws "Does not recognize selector" exception
 
    [ b doWorkFooBar ]; // Will call -[ ClassA doWork ]
 
 ```
 
 @param selector A selector of the current class to be executed with the **targetClass**
 @param targetClass A class that gets a new instance method
 @param newSelector A method on the **targetClass** to be invoked by the end user.
 
 @return YES - In case a new method has been added to the **targetClass**
 NO - In case a **newSelector** method already existed.
 NO - In case of any objc-runtime errors.
 */
+ (BOOL)addInstanceMethodIfNeedWithSelector:(SEL)selector
                                    toClass:(Class)targetClass
                          newMethodSelector:(SEL)newSelector;



/**
 Adds a static method to the **targetClass** if it does not have one.
 
 ```
 
    [ ClassA addClassMethodIfNeedWithSelector: @selector( doWork )
                                      toClass: [ ClassB class ] ];

    [ ClassB doWork ]; // Will call +[ ClassA doWork ]
 
 ```
 
 @param selector A selector of the current class to be executed with the **targetClass**
 @param targetClass A class that gets a new static method.
 
 @return YES - In case a new method has been added to the **targetClass**
 NO - In case a method already existed.
 NO - In case of any objc-runtime errors.
 */
+ (BOOL)addClassMethodIfNeedWithSelector:(SEL)selector
                                 toClass:(Class)targetClass;


/**
 Adds a static method to the **targetClass** if it does not have one.
 
 ```
 
    [ ClassA addClassMethodIfNeedWithSelector: @selector( doWork )
                                      toClass: [ ClassB class ]
                            newMethodSelector: @selector( doWorkFooBar ) ];
 
    [ ClassB doWork       ]; // Throws "Does not recognize selector" exception
 
    [ ClassB doWorkFooBar ]; // Will call +[ ClassA doWork ]
 
 ```
 
 @param selector A selector of the current class to be executed with the **targetClass**
 @param targetClass A class that gets a new static method
 @param newSelector A method on the **targetClass** to be invoked by the end user.
 
 @return YES - In case a new method has been added to the **targetClass**
 NO - In case a **newSelector** method already existed.
 NO - In case of any objc-runtime errors.
 */
+ (BOOL)addClassMethodIfNeedWithSelector:(SEL)selector
                                 toClass:(Class)targetClass
                       newMethodSelector:(SEL)newSelector;






/**
 Creates a hook for the existing instance method of a given class. Depending on your impementation, the original method may either be executed or not. By default the original method is replaced.
 
 @param targetClass - a class for which the hook is being set up. Both targetSelector andhookSelector must be implemented for it.
 
 @param targetSelector - an instance method of the targetClass to be replaced
 
 @param prototypeSelector - an instance method of "self" to be executed instead of "targetSelector"
 
 @param hookSelector - an instance method of "self" where old implementation will be placed. It may be invoked from "prototypeSelector"
 */
+ (void)hookInstanceMethodForClass:(Class)targetClass
                      withSelector:(SEL)targetSelector
           prototypeMethodSelector:(SEL)prototypeSelector
                hookMethodSelector:(SEL)hookSelector;

//+ (void)unHookInstanceMethodForClass:(Class)targetClass
//                        withSelector:(SEL)targetSelector
//             prototypeMethodSelector:(SEL)prototypeSelector
//                  hookMethodSelector:(SEL)hookSelector;


/**
  Creates a hook for the existing static method of a given class. Depending on your impementation, the original method may either be executed or not. By default the original method is replaced.
 
 @param targetClass - a class for which the hook is being set up. Both targetSelector andhookSelector must be implemented for it.
 
 @param targetSelector - a static method of the targetClass to be replaced
 
 @param prototypeSelector - a static method of "self" to be executed instead of "targetSelector"
 
 @param hookSelector - a static method of "self" where old implementation will be placed. It may be invoked from "prototypeSelector"
 */
+ (void)hookClassMethodForClass:(Class)targetClass
                   withSelector:(SEL)targetSelector
        prototypeMethodSelector:(SEL)prototypeSelector
             hookMethodSelector:(SEL)hookSelector;

//+ (void)unHookClassMethodForClass:(Class)targetClass
//                     withSelector:(SEL)targetSelector
//          prototypeMethodSelector:(SEL)prototypeSelector
//               hookMethodSelector:(SEL)hookSelector;


/**
 Checks whether [self class] object has an instance method with the given selector
 
 @param methodSelector A method to check.
 
 @return YES in case the method exists. NO - otherwise
 */
+ (BOOL)hasInstanceMethodWithSelector:(SEL)methodSelector;


/**
 Checks whether [self class] object has a static method with the given selector
 
 @param methodSelector A method to check.
 
 @return YES in case the method exists. NO - otherwise
 */
+ (BOOL)hasClassMethodWithSelector:(SEL)methodSelector;

@end
