#import "JFFBaseLoaderOwner.h"

#import "JFFLimitedLoadersQueue.h"

@interface JFFLimitedLoadersQueue (JFFBaseLoaderOwner)

- (void)performPendingLoaders;
- (void)didFinishActiveLoader:(JFFBaseLoaderOwner *)activeLoader;

@end

@implementation JFFBaseLoaderOwner

+ (instancetype)newLoaderOwnerWithLoader:(JFFAsyncOperation)loader
                                   queue:(JFFLimitedLoadersQueue *)queue
{
    JFFBaseLoaderOwner *result = [self new];
    
    if (result) {
        result->_loader = [loader copy];
        result->_queue  = queue;
    }
    
    return result;
}

- (void)clear
{
    _loader           = nil;
    _queue            = nil;
    _cancelLoader     = nil;
    _progressCallback = nil;
    _cancelCallback   = nil;
    _doneCallback     = nil;
}

- (void)performLoader
{
    NSParameterAssert(_cancelLoader == nil);
    
    JFFAsyncOperationProgressHandler progressCallback = ^(id progress) {
        
        if (self->_progressCallback)
        {
            self->_progressCallback(progress);
        }
    };
    
    JFFCancelAsyncOperationHandler cancelCallback = ^(BOOL canceled) {
        
        if (canceled) {
            [self->_queue didFinishActiveLoader:self];
        }
        
        if (self->_cancelCallback) {
            JFFCancelAsyncOperationHandler cancelCallback = self->_cancelCallback;
            self->_cancelCallback = nil;
            
            if ( cancelCallback )
            {
                cancelCallback(canceled);
            }
        }
        
        [self clear];
    };
    
    JFFDidFinishAsyncOperationHandler doneCallback = ^(id result, NSError *error) {
        
        [self->_queue didFinishActiveLoader:self];
        
        if (self->_doneCallback)
        {
            self->_doneCallback(result, error);
        }
        
        [self clear];
    };
    
    _cancelLoader = _loader(progressCallback, cancelCallback, doneCallback);
}

@end
