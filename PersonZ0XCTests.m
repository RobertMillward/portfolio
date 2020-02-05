//
//  PersonZ0Tests.m -
//
//  Created by Robert R on 3/5/19.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
// os
#import <XCTest/XCTest.h>
// helper api's
//#import "QueingZ0.h"
//#import "SignatureFactoryZ0.h"
//#import "AppHelperZ0.h"
//#import "CommaSepO3.h"
//#import "UnixStreamZ0.h"
//#import "RowZ0.h"
//#import "HashBasicsZ0.h"
//#import "InitDestroyHelperZ0.h"
// data plans
#import "ArchitectureZ0Plan.h"
// application api's
#import "PersonO4.h"
// quality
#import "TestAidZ0.h"
#import "PersonZ0TestAid.h"




@interface PersonZ0NewTests : XCTestCase

@end

@implementation PersonZ0NewTests


- (void)setUp {
    TestAidQCapi.basicInit();
}

- (void)tearDown {
}


- (void)test2099PersonZ0New
{
    if(TestAidQCapi.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        
        ErrorWarnCountT ewc = PersonZ0QCapi.newQ(__LINE__);

        if(ewc.classErrors != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}
@end

// END PersonZ0Tests.m
/**
 *
 */
