//
//  RowZ0Tests.m
//
//  Created by Robert Russell Millward on 10/8/19.
//  Copyright (c) 2019 Robert Russell Millward.  All rights reserved.
//
#import <XCTest/XCTest.h>
#import "RowZ0TestAid.h"
#import "TestAidZ0.h"
#import "AuthAndAuthO8.h"

@interface RowO0Tests : XCTestCase

@end

@implementation RowO0Tests
- (void)setUp{
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

@end
/**
 */
