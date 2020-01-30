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

//- (void)test2019Template
//{
//    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
//        if(TestAidC.putTestChars("not", "tested", __LINE__) == 0)
//        {
//            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
//        }
//    }
//}

//- (void)test2099ZULURowO0Destroy {
//    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
//        char* report = InitDestroyerHelperC.getReport();
//
//        // Before destroyAll().
//        if(report[0] != 0)
//        {
//            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:InitDestroyerHelperC.getReport()]);
//            report[0] = 0;
//        }
//
//        // After destroyAll().
//        InitDestroyerHelperC.destroyAll(&TestAidO0QCre.infoTwoWay);
//        if(report[0] != 0)
//        {
//            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:InitDestroyerHelperC.getReport()]);
//        }
//    }
//}

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


#pragma mark - Tests, part one

//- (void)test2019TemplateO4B
//{
//    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
//        if(TestAidC.putTestChars("not", "tested", __LINE__) == 0)
//        {
//            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
//        }
//    }
//}

//- (void)test2099ZULUPGO4BDestroy {
//    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
//        char* report = InitDestroyerHelperC.getReport();
//
//        // Before destroyAll().
//        if(report[0] != 0)
//        {
//            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:InitDestroyerHelperC.getReport()]);
//            report[0] = 0;
//        }
//
//        // After destroyAll().
//        InitDestroyerHelperC.destroyAll(&TestAidO0QCre.infoTwoWay);
//        if(report[0] != 0)
//        {
//            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:InitDestroyerHelperC.getReport()]);
//        }
//    }
//}

@end // END PeopleGroupZ0XCTests.m
