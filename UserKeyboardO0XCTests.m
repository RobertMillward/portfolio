//
//  UserKeyboard0Tests.m
//
//  Created by Robert R on 4/1/15.
//  Copyright (c) 2015 Robert Russell Millward. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import "TestAid0.h"
#import "UserKeyboard0.h"

@interface UserKeyboard0Tests : XCTestCase

@end

@implementation UserKeyboard0Tests

- (void)setUp {
    [super setUp];
    // Put setup code here.
    // This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here.
    // This method is called after the invocation of each test method in the class.
    [super tearDown];
}



- (void)test2015StrToVals {
    if(TA0C.isScheduled(__FUNCTION__)){
        
        if(TA0C.putTestInts(127, (int)UserKeyboardC.bufToLong("127"), __LINE__) != 0 ||
           //TA0C.putTestInts(127,  UserKeyboard.bufToFloat)("127")) != 0 ||
           //TA0C.putTestInts(127,  UserKeyboard.bufToDouble)("127")) != 0 ||
           1 == 2){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getPreparedCtext(__FUNCTION__)]);
        }
        else
        {
            XCTAssert(YES, @"Pass");
        }
    }
    else
    {
        XCTAssert(YES, @"Not scheduled");
    }
}

@end
