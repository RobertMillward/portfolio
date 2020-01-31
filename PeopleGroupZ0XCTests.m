//
//  PeopleGroupZ0XCTests.m
//
//  Created by Robert Russell Millward on 10/8/13.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
// os
#import <XCTest/XCTest.h>
// data plans
#import "ArchitectureZ0Plan.h"
// helper api's
//#import "InitDestroyHelperO0.h"
// app api's
#import "PeopleGroupO4.h"
#import "PeopleGroupO0.h"
// quality
#import "TestAidZ0.h"

static ErrorWarnCountT fakeTest()
{
    ErrorWarnCountT ewc = {0, 0, 0, 0};
    
    TestAidQCapi.putTestChars("fake", "test", __LINE__);
    ewc.classErrors++;
    
    return ewc;
}

@interface PeopleGroupO4TestsPartOne : XCTestCase

@end

@implementation PeopleGroupO4TestsPartOne

- (void)setUp
{
    TestAidC.nextTx();
}

- (void)tearDown
{
    TestAidC.getCounts();
}

#pragma mark - Tests, part one

- (void)test2019ZfakeTest {
    if(TestAidQCapi.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        
        ErrorWarnCountT ewc = fakeTest();

        if(ewc.classErrors != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}


@end






@interface PeopleGroupO4TestsPartTwo : XCTestCase

@end

@implementation PeopleGroupO4TestsPartTwo

- (void)setUp
{
    TestAidC.nextTx();
}

- (void)tearDown
{
    TestAidC.getCounts();
}


#pragma mark - Tests, part two

- (void)test2019ZfakeTest {
    if(TestAidQCapi.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        
        ErrorWarnCountT ewc = fakeTest();

        if(ewc.classErrors != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}

@end // END PeopleGroupZ0XCTests.m
/**
 * 2020/01/30 converted to fakeTest pending Z0TestAid.[ch]
 */
