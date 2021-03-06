//
//  DictZ0XCTests.m -
//  2020Apr02Dev
//
//  Created by Robert Russell Millward on 12/3/19.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
// os
#import <XCTest/XCTest.h>
// helper api's
// data plans
// quality
#import "DictZ0TestAid.h"

// Break out only tests that require special aetup
@interface DictO0OrdinaryTests : XCTestCase
@end
@interface DictO0SafeSizeTests : XCTestCase
@end
@interface DictO0BasicTests : XCTestCase
@end
@interface DictO0ExtraDemoTests : XCTestCase
@end
@interface DictO0PerformanceTests : XCTestCase
@end

@interface DictO3OrdinaryTests : XCTestCase
@end
@interface DictO3SafeSizeTests : XCTestCase
@end
@interface DictO3BasicTests : XCTestCase
@end
@interface DictO3ExtraDemoTests : XCTestCase
@end
@interface DictO3PerformanceTests : XCTestCase
@end

@implementation DictO0OrdinaryTests

- (void)setUp {
    DictO0QCapi.setupSet1(__LINE__);
}

- (void)tearDown {
    DictO0QCapi.teardownSet1(__LINE__);
}

- (void)test2020SafeSize{
    if(DictO0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(DictO0QCapi.doSet1SizeSafe(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:DictO0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}

- (void)test2020Basic{
    if(DictO0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(DictO0QCapi.doSet2Basics(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:DictO0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}

- (void)test9999SuiteStats{
}

@end // END O0 NonSpecial


@implementation DictO3OrdinaryTests

- (void)setUp {
    DictO3QCapi.setupSet1(__LINE__);
}

- (void)tearDown {
    DictO3QCapi.teardownSet1(__LINE__);
}

- (void)test2020SafeSize{
    if(DictO3QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(DictO3QCapi.doSet1SizeSafe(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:DictO0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}

- (void)test2020Basic{
    if(DictO3QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(DictO3QCapi.doSet2Basics(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:DictO0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}

- (void)test9999SuiteStats{
}

@end // END O3 NonSpecial

/*
@implementation DictO0SafeSizeTests

- (void)setUp {
    DictO0QCapi.setupSet1(__LINE__);
}

- (void)tearDown {
    DictO0QCapi.teardownSet1(__LINE__);
}

- (void)test2020SafeSize{
    if(DictO0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(DictO0QCapi.doSet1SizeSafe(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:DictO0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}

@end // END SafeSize

@implementation DictO0BasicTests

- (void)setUp {
    DictO0QCapi.setupSet2(__LINE__);
}

- (void)tearDown {
    DictO0QCapi.teardownSet2(__LINE__);
}

- (void)test2020Basic{
    if(DictO0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(DictO0QCapi.doSet2Basics(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:DictO0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}

@end // END Basic
 
 */

//END  DictZ0XCTests.m
/**
 */
