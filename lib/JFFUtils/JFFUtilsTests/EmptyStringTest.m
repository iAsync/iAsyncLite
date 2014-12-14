#import <XCTest/XCTest.h>
#import <JFFUtils/JFFUtils.h>


@interface EmptyStringTest : XCTestCase

@end



@implementation EmptyStringTest

- (void)testNilStringIsEmpty
{
    NSString *str;
    XCTAssertFalse([str hasSymbols], @"Nil String[%@] should have no symbols", str);
}

- (void)testEmptyStringIsEmpty
{
    {
        NSString *str = @"";
        XCTAssertFalse([str hasSymbols], @"Nil String[%@] should have no symbols", str);
    }
    
    {
        NSMutableString* empty = [NSMutableString stringWithString:@""];
        NSString* str = [empty copy];
        XCTAssertFalse([str hasSymbols], @"Nil String[%@] should have no symbols", str);
    }
    
    {
        NSMutableString* empty = [NSMutableString stringWithString:@""];
        NSString *str = [empty copy];
        XCTAssertFalse( [str hasSymbols], @"Nil String[%@] should have no symbols", str);
    }
}

- (void)testStringWithCharactersIsNotEmpty
{
    NSString *str = @"abrakadabre";
    XCTAssertTrue([str hasSymbols], @"The String[%@] should have some symbols", str);
}

@end
