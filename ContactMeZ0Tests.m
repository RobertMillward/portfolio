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
test2019Safety
{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        
        ErrorWarnCountT ewc = cnctMeDGZ0QCapi.testSupply(__LINE__);
        
        if(ewc.classErrors != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}
@end

//@interface ContactMeZ0GeneralTests : XCTestCase
//
//@end
//
//@implementation ContactMeZ0GeneralTests
//
//- (void)setUp{
//}
//
//- (void)tearDown{
//    //TestAidC.getCounts();
//}
//
//- (void)
//test2019General
//{
//    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
//         ErrorWarnCountT ewc = {0,0,0,0};
//        if(ewc.classErrors != 0)
//        {
//            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
//        }
//    }
//}
//@end
//
//@interface ContactMeZ0MisuseTests : XCTestCase
//
//@end
//
//@implementation ContactMeZ0MisuseTests
//
//- (void)setUp{
//}
//
//- (void)tearDown{
//    //TestAidC.getCounts();
//}
//
//- (void)
//test2019Misuse
//{
//    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
//        ErrorWarnCountT ewc = {0,0,0,0};
//        if(ewc.classErrors != 0)
//        {
//            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
//        }
//    }
//}
//@end
//
//@interface StressContactMeZ0QTests : XCTestCase
//
//@end
//
//@implementation StressContactMeZ0QTests
//
//- (void)setUp{
//}
//
//- (void)tearDown{
//    //TestAidC.getCounts();
//}
//
//- (void)
//test2019StressContactMe
//{
//    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
//        ErrorWarnCountT ewc = {0,0,0,0};
//        if(ewc.classErrors != 0)
//        {
//            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
//        }
//    }
//}
//
//@end
//
//@interface StressThreadingZ0QTests : XCTestCase
//
//@end
//
//@implementation StressThreadingZ0QTests
//
//- (void)setUp{
//}
//
//- (void)tearDown{
//    //TestAidC.getCounts();
//}
//
//- (void)
//test2019StressThreading
//{
//    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
//        ErrorWarnCountT ewc = {0,0,0,0};
//        if(ewc.classErrors != 0)
//        {
//            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
//        }
//    }
//}
//@end // END ContactMeZ0Tests.m
/**
 */
