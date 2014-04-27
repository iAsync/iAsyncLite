#import "MockErrorBuilder.h"

@implementation MockErrorBuilder


+(NSError*)getMockError
{
    return [ NSError errorWithDomain:@"1" code: 1 userInfo: nil ];
}


@end
