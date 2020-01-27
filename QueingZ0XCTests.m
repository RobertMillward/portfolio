//
//  QueingZ0Tests.m
//
//  Created by Robert R on 11/14/14.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
// os
#import <XCTest/XCTest.h>
// data
// api
//#import "ErrorHelperO0.h"
#import "QueingO0.h"
// quality
#import "TestAidZ0.h"
#import "QueingZ0TestAid.h"

/**
 * These tests are against only a not yet running queing environment.
 */
//@end
@interface QueingZ0SafetyTests : XCTestCase

@end

@implementation QueingZ0SafetyTests

- (void)setUp{
}

- (void)tearDown{
    //TestAidC.getCounts();
}


- (void)
test2019Safety
{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        ErrorWarnCountT ewc = QueingZ0QCapi.safetyQ(__LINE__);
        if(ewc.classErrors != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}
@end

@interface QueingZ0GeneralTests : XCTestCase

@end

@implementation QueingZ0GeneralTests

- (void)setUp{
}

- (void)tearDown{
    //TestAidC.getCounts();
}

- (void)
test2019General
{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        ErrorWarnCountT ewc = QueingZ0QCapi.generalQ(__LINE__);
        if(ewc.classErrors != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}
@end

@interface QueingZ0MisuseTests : XCTestCase

@end

@implementation QueingZ0MisuseTests

- (void)setUp{
}

- (void)tearDown{
    //TestAidC.getCounts();
}

- (void)
test2019Misuse
{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        ErrorWarnCountT ewc = QueingZ0QCapi.misuseQ(__LINE__);
        if(ewc.classErrors != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}
@end

@interface StressQueingZ0QTests : XCTestCase

@end

@implementation StressQueingZ0QTests

- (void)setUp{
}

- (void)tearDown{
    //TestAidC.getCounts();
}

- (void)
test2019StressQueing
{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        ErrorWarnCountT ewc = QueingZ0QCapi.stressQueingQ(__LINE__);
        if(ewc.classErrors != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}

@end

@interface StressThreadingZ0QTests : XCTestCase

@end

@implementation StressThreadingZ0QTests

- (void)setUp{
}

- (void)tearDown{
    //TestAidC.getCounts();
}

- (void)
test2019StressThreading
{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        ErrorWarnCountT ewc = QueingZ0QCapi.stressThreadingQ(__LINE__);
        if(ewc.classErrors != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}


@end
/**
 */
