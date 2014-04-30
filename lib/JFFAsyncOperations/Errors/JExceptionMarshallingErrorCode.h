#ifndef JFFAsyncOperations_JExceptionMarshallingErrorCodes_h
#define JFFAsyncOperations_JExceptionMarshallingErrorCodes_h


#import <Foundation/Foundation.h>


/**
 Error codes that are used for exceptions marshalling.
 They will be used to create appropriate NSError objects.
 */
typedef NS_ENUM( NSInteger, JExceptionMarshallingErrorCode )
{
    /**
     No error has occured.
     */
    JNoExceptionErrorCode         = 0,
    
    /**
     A subclass of NSException has been thrown. 
     See JObjcExceptionWrapperError class reference.
     */
    JObjcExceptionErrorCode          ,
    
    /**
     A subclass of std::exception has been thrown.
     See JCppExceptionWrapperError class reference.
     */
    JStdCppExceptionErrorCode        ,

    
    /**
     An unknown exception has been thrown and suppressed by the ```catch(...)``` statement.
     See JUnknownCppExceptionWrapperError class reference.
     */
    JUnknownCppExceptionErrorCode
};

#endif
