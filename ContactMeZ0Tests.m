//
//  ContactMeZ0Tests.m
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

@interface ContactMeZ0SafetyTests : XCTestCase

@end

@implementation ContactMeZ0SafetyTests

- (void)setUp{
}

- (void)tearDown{
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
@end

@interface ContactMeZ0GeneralTests : XCTestCase

@end

@implementation ContactMeZ0GeneralTests

- (void)setUp{
}

- (void)tearDown{
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
@end

@interface ContactMeLinkZ0GeneralTests : XCTestCase

@end

@implementation ContactMeLinkZ0GeneralTests

- (void)setUp{
}

- (void)tearDown{
}


- (void)
test2019Link
{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        
        ErrorWarnCountT ewc = cnctMeDGZ0QCapi.testLinkQ(__LINE__);
        
        if(ewc.classErrors != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}
@end

@interface ContactMeStatusZ0GeneralTests : XCTestCase

@end

@implementation ContactMeStatusZ0GeneralTests

- (void)setUp{
}

- (void)tearDown{
}


- (void)
test2019Status
{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        
        ErrorWarnCountT ewc = cnctMeDGZ0QCapi.testStatusQ(__LINE__);
        
        if(ewc.classErrors != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}

@end // END ContactMeZ0Tests.m
/**
 */
