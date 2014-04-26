#ifndef JFFAsyncOperations_JExceptionMarshallingErrorCodes_h
#define JFFAsyncOperations_JExceptionMarshallingErrorCodes_h


#import <Foundation/Foundation.h>


typedef NS_ENUM( NSInteger, JExceptionMarshallingErrorCode )
{
    JNoExceptionErrorCode         = 0,
    JObjcExceptionErrorCode          ,
    JStdCppExceptionErrorCode        ,
    JUnknownCppExceptionErrorCode
};

#endif
