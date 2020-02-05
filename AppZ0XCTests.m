//
//  AppZ0XCTests.m
//
//  Created by Robert R on 3/27/15.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
// os
#import <XCTest/XCTest.h>
// helper api's
// data plans
#import "ArchitectureZ0Plan.h"
// application api's
#import "AppO4.h"
// quality
#import "TestAidZ0.h"
#import "AppZ0TestAid.h"

@interface AppZ0NewTests : XCTestCase

@end

@implementation AppZ0NewTests


- (void)setUp {
    TestAidQCapi.basicInit();
}

- (void)tearDown {
}


- (void)test2099PersonZ0New
{
    if(TestAidQCapi.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        
        ErrorWarnCountT ewc = AppZ0QCapi.newQ(__LINE__);

        if(ewc.classErrors != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}


@end // AppZ0XCTests.m
/**
* 2020/01/30 converted to fakeTest pending Z0TestAid.[ch]
*/
