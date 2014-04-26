#ifndef __JFF_GCD_ADDITIONS_INCLUDED__
#define __JFF_GCD_ADDITIONS_INCLUDED__

#include <dispatch/queue.h>
#import <objc/objc-api.h>

OBJC_EXTERN dispatch_queue_t dispatch_queue_get_or_create(const char *label, dispatch_queue_attr_t attr);
    
OBJC_EXTERN    void dispatch_queue_release_by_label(const char *label);


// @adk : for XCTest where dispatch_creqte_queue() returns main queue
OBJC_EXTERN    void dispatch_sync_check_queue(dispatch_queue_t queue, dispatch_queue_t currentQueue, dispatch_block_t block);
OBJC_EXTERN    void dispatch_barrier_sync_check_queue(dispatch_queue_t queue, dispatch_queue_t currentQueue,dispatch_block_t block);


// @adk : legacy since iOS 6
OBJC_EXTERN    void safe_dispatch_sync(dispatch_queue_t queue, dispatch_block_t block);
    
OBJC_EXTERN    void safe_dispatch_barrier_sync(dispatch_queue_t queue, dispatch_block_t block);


#endif //__JFF_GCD_ADDITIONS_INCLUDED__
