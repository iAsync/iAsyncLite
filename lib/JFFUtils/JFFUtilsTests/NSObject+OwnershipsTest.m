#import <XCTest/XCTest.h>

#import <JFFUtils/JFFUtils.h>
#import "NSObject+Ownerships.h"

@interface NSObjectOwnershipsExtensionTest :XCTestCase

@end

@implementation NSObjectOwnershipsExtensionTest

- (void)testObjectOwnershipsExtension
{
    __weak NSObject *ownedDeallocated;
    {
        NSObject *owner = [NSObject new];

        {
            NSObject *owned = [NSObject new];
            
            ownedDeallocated = owned;
            
            [owner addOwnedObject:owned];
        }
        
        XCTAssertNotNil(ownedDeallocated, @"Owned should not be dealloced");
    }
    XCTAssertNil(ownedDeallocated, @"Owned should be dealloced");
}

@end
