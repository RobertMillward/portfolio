//
//  RowZ0XCTests.m
//
//  Created by Robert Russell Millward on 10/8/19.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
// os
#import <XCTest/XCTest.h>
// helper api's
//#import "AuthAndAuthO8.h"
// quality
#import "RowZ0TestAid.h"
#import "TestAidZ0.h"

@interface RowO0Tests : XCTestCase

@end

@implementation RowO0Tests
- (void)setUp{
    TestAidZ0QCapi.basicInit();
}

- (void)tearDown{
}


- (void)test2019TargetO0{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        ErrorWarnCountT ewc = RowO0QCapi.targetTests(__LINE__);
        if(ewc.classErrors != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}


- (void)test2019LetterO0{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        ErrorWarnCountT ewc = RowO0QCapi.letterTests(__LINE__);
        if(ewc.classErrors != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}


- (void)test2019SourceO0{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        ErrorWarnCountT ewc = RowO0QCapi.sourceTests(__LINE__);
        if(ewc.classErrors != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}
/**
 * From non-XC
 */

- (void)test2019StoreO0{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        ErrorWarnCountT ewc = RowO0QCapi.storeTests(__LINE__);
        if(ewc.classErrors != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}

@end
/**
 */
