//
//  HexasoftO3Tests.m
//  2020Apr02Dev
//
//  Created by Robert R on 3/27/15.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
// os
#include <XCTest/XCTest.h>
// helper and service api's
// data plans
// other api's
// quality
#import "HexasoftZ3TestAid.h"

@interface HexasoftO3OrdinaryTests : XCTestCase

@end

@implementation HexasoftO3OrdinaryTests


- (void)setUp {
    HexasoftZ3QCapi.setupSet1(__LINE__);
}

- (void)tearDown {
    HexasoftZ3QCapi.teardownSet1(__LINE__);
}

- (void)test2020SizeSafe
{
    if(HexasoftZ3QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(HexasoftZ3QCapi.doSet1SizeSafe(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:HexasoftZ3QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}// END SizeSafe


- (void)test2020Basics
{
    if(HexasoftZ3QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(HexasoftZ3QCapi.doSet2Basics(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:HexasoftZ3QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}// END Basics


- (void)test2020ExtraDemo
{
    if(HexasoftZ3QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(HexasoftZ3QCapi.doSet3ExtraDemo(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:HexasoftZ3QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}// END ExtraDemo


- (void)test2020Performance
{
    if(HexasoftZ3QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(HexasoftZ3QCapi.doSet4Performance(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:HexasoftZ3QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}// END Performance



@end
/**
 *
 */
