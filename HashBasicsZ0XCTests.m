//
//  HashBasicsZ0XCTests.m - Test the O0 interface
//  2020Apr02Dev
//
//  Created by Robert R on 4/1/15.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
// os
#import <XCTest/XCTest.h>
// data plans
// helper and service api's
// quality
#import "HashBasicsZ0TestAid.h"


@interface HashBasicsO0OrdinaryTests : XCTestCase

@end

@implementation HashBasicsO0OrdinaryTests

- (void)setUp {
    HashBasicsZ0QCapi.setupParseSet1(__LINE__);
}

- (void)tearDown {
    HashBasicsZ0QCapi.teardownParseSet1(__LINE__);
}


- (void)test2015SampleNotWorking {
    if(HashBasicsZ0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(HashBasicsZ0QCapi.doSet4(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:HashBasicsZ0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}


- (void)test2019LikeTestAid {
    if(HashBasicsZ0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(HashBasicsZ0QCapi.doParseTestAidSet3(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:HashBasicsZ0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}

- (void)test2019OtherName{
    if(HashBasicsZ0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(HashBasicsZ0QCapi.do8100Set2(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:HashBasicsZ0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}


- (void)test201901Parse{
    if(HashBasicsZ0QCapi.isScheduled(__FUNCTION__, __LINE__))
    {
        if(HashBasicsZ0QCapi.doParseSet1(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:HashBasicsZ0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}

@end

//END HashBasicsZ0XCTests.m
/**
 *
 */
