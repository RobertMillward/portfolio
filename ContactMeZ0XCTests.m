//
//  ContactMeZ0XCTests.m
//  2020Apr02Dev
//
//  Created by Robert R on 01/09/20.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
// os
#import <XCTest/XCTest.h>
// helper api's
//#include "ErrorHelperO0.h"
// data plans
//#import "ArchitectureZ0Plan.h"
// api
//#import "ContactMeO4.h"
// quality
#import "ContactMeZ0TestAid.h"
#import "TestAidZ0.h"


@interface ContactMeZ0OrdinaryTests : XCTestCase
@end
//@interface ContactMeZ0SafetyTests : XCTestCase
//@end
//@interface ContactMeZ0GeneralTests : XCTestCase
//@end
//@interface ContactMeLinkZ0GeneralTests : XCTestCase
//@end





@implementation ContactMeZ0OrdinaryTests

- (void)setUp{
}

- (void)tearDown{
    TestAidC.getCounts();
}

- (void)
test2019Supply
{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        
        ErrorWarnCountT ewc = cnctMeDGZ0QCapi.testSupplyQ(__LINE__);
        
        if(ewc.classErrors != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}


- (void)
test2019ContactMe
{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        
        ErrorWarnCountT ewc = cnctMeDGZ0QCapi.testContactMeQ(__LINE__);
        
        if(ewc.classErrors != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}


- (void)test2019Link
{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        
        ErrorWarnCountT ewc = cnctMeDGZ0QCapi.testLinkQ(__LINE__);
        
        if(ewc.classErrors != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}

- (void)test9999SuiteStats{
    
}
@end // ContactMeZ0OrdinaryTests


// END ContactMeZ0XCTests.m
/**
 */
