#ifndef JFF_UTILS_JFF_MEMORY_MGMT_HEADER_INCLUDED
#define JFF_UTILS_JFF_MEMORY_MGMT_HEADER_INCLUDED

#include <objc/objc.h>
#include <objc/objc-api.h>

OBJC_EXTERN id jff_retainAutorelease(id object);
OBJC_EXTERN id jff_retain(id object);

#endif //JFF_UTILS_JFF_MEMORY_MGMT_HEADER_INCLUDED
