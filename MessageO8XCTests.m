//
//  TestsGroupMessage8.m
//  TestsGroupMessage8
//
//  Created by Robert R on 10/30/14.
//  Copyright (c) 2014 Robert Russell Millward. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>

#import "Message8.h"
#import "Row.h"
#import "TransactionLow.h"

@interface TestsGroupMessage8 : XCTestCase

@end

@implementation TestsGroupMessage8

- (void)setUp
{
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown
{
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}



static char *testMessage01 =
  "1111111,2222222,3333333,4444444,5555555,6666666,7777777,dev=veow=w";

- (void)test201711basics
{
    char wk[1001];
    strcpy(wk, testMessage01);
    Row msgRow = newRow(wk, TXL_TRANIX_FOR_THREADER);
    Message8 msg8 = newMessage8(msgRow.getField(&msgRow, MSG_INFO_LTTR));
    char *appID = msg8.getAppID(&msg8);
    char *feaID = msg8.getFeatureID(&msg8);
    char *stpID = msg8.getStepID(&msg8);
    char *grpID = msg8.getGroupID(&msg8);
    char *rolID = msg8.getRoleID(&msg8);
    char *usrID = msg8.getUserID(&msg8);
    char *envID = msg8.getEnvrID(&msg8);
    // This is an example of a functional test case.
    XCTAssert(YES, @"Pass");
}

//- (void)testPerformanceExample {
//    // This is an example of a performance test case.
//    [self measureBlock:^{
//        // Put the code you want to measure the time of here.
//    }];
//}

@end
