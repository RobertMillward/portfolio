//
//  AuthAndAuthZ8XCTests.m
//
//  Created by Robert Russell Millward on 10/8/19.
//  Copyright (c) 2019 Robert Russell Millward.  All rights reserved.
//
#import <XCTest/XCTest.h>
#import "AuthAndAuthZ8TestAid.h"
#import "TestAidZ0.h"
#import "AuthAndAuthO8.h"

@interface AuthAndAuthO8Tests : XCTestCase

@end

@implementation AuthAndAuthO8Tests
- (void)setUp{
}

- (void)tearDown{
}

- (void)testAuthAndAuthO0{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        ErrorWarnCountT ewc = AuthAndAuthO8QCapi.checkSizes(__LINE__);
        if(ewc.classErrors != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}


@end
/**
 */
