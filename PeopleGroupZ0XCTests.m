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
// app api's
#import "PeopleGroupO4.h"
// quality
#import "TestAidZ0.h"
#import "PeopleGroupZ0TestAid.h"

@interface PeopleGroupZ0NewTests : XCTestCase

@end

@implementation PeopleGroupZ0NewTests


- (void)setUp {
    TestAidQCapi.basicInit();
}

- (void)tearDown {
}


- (void)test2099PersonZ0New
{
    if(TestAidQCapi.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        
        ErrorWarnCountT ewc = PeopleGroupZ0QCapi.newQ(__LINE__);

        if(ewc.classErrors != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}
@end
/**
 * 2020/01/30 converted to fakeTest pending Z0TestAid.[ch]
 */
