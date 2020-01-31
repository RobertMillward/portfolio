//
//  AppZ0XCTests.m
//
//  Created by Robert R on 3/27/15.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
// os
#import <XCTest/XCTest.h>
// helper api's
#import "ErrorHelperO0.h"
//#import "InitDestroyHelperO0.h"
//#import "SignatureFactoryO0.h"
//#import "CommaSepO3.h"
//#import "UnixStreamO0.h"
//#import "RowO0.h"
//#import "HashBasicsO0.h"
// data plans
#import "ArchitectureZ0Plan.h"
// application api's
#import "AppO4.h"
#import "PeopleGroupO0.h"
// quality
#import "TestAidZ0.h"

static ErrorWarnCountT fakeTest()
{
    ErrorWarnCountT ewc = {0, 0, 0, 0};
    
    TestAidQCapi.putTestChars("fake", "test", __LINE__);
    ewc.classErrors++;
    
    return ewc;
}

@interface AppO4Tests : XCTestCase

@end

@implementation AppO4Tests



- (void)setUp {
    //initSignatureFactoryO0(&TestAidO0QCre.infoTwoWay);
}

- (void)tearDown {
    //TestAidC.getCounts();
    //InitDestroyerHelperC.destroyAll(&TestAidO0QCre.infoTwoWay);
}

- (void)test2019ZfakeTest {
    if(TestAidQCapi.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        
        ErrorWarnCountT ewc = fakeTest();

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
