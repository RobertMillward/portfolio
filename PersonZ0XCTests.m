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
#import "PeopleGroupO4.h"
#import "PersonO4.h"
// quality
#import "TestAidZ0.h"
#import "PersonZ0TestAid.h"


static ErrorWarnCountT fakeTest()
{
    ErrorWarnCountT ewc = {0, 0, 0, 0};
    
    TestAidQCapi.putTestChars("fake", "test", __LINE__);
    ewc.classErrors++;
    
    return ewc;
}


@interface PersonZ0NewTests : XCTestCase

@end

@implementation PersonZ0NewTests


- (void)setUp {
    TestAidQCapi.basicInit(); // this gets signature

}

- (void)tearDown {
}


- (void)test2099PersonZ0NewRandom
{
    if(TestAidQCapi.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        
        ErrorWarnCountT ewc = fakeTest();

        if(ewc.classErrors != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}
@end



@interface PersonZ0ReviseTests : XCTestCase

@end

@implementation PersonZ0ReviseTests

- (void)setUp {
    TestAidQCapi.basicInit();
}

- (void)tearDown {
}


- (void)test2099PersonZ0RevisionOk
{
    if(TestAidQCapi.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        
        ErrorWarnCountT ewc = fakeTest();

        if(ewc.classErrors != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}
@end



@interface PersonZ0ReviseBadTests : XCTestCase

@end

@implementation PersonZ0ReviseBadTests


- (void)setUp {
    TestAidQCapi.basicInit();
}

- (void)tearDown {
}

- (void)test2099PersonZ0RevisionOk
{
    if(TestAidQCapi.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        
        ErrorWarnCountT ewc = fakeTest();

        if(ewc.classErrors != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}

@end
