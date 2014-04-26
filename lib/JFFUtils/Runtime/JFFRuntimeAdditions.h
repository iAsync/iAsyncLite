#ifndef JFFUtils_JFFBlockRuntimeAddiotions_h
#define JFFUtils_JFFBlockRuntimeAddiotions_h

#include <stdarg.h>
#include <objc/objc.h>
#include <objc/objc-api.h>

@class NSArray;
@class NSString;

    
OBJC_EXTERN    void enumerateAllClassesWithBlock(void(^)(Class));
    
OBJC_EXTERN    const char *block_getTypeEncoding(id block);
    
OBJC_EXTERN    void invokeMethosBlockWithArgsAndReturnValue(id targetObjectOrBlock,
                                                 const char *signature,
                                                 SEL selectorOrNullForBlock,
                                                 va_list args,
                                                 id *selfArgumentPtr,
                                                 void *returnValuePtr);
    
OBJC_EXTERN    void jClass_implementProperty(Class cls, NSString *propertyName);
    

#endif //JFFUtils_JFFBlockRuntimeAddiotions_h
