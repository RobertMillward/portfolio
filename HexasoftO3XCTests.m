//
//  HexasoftO3Tests.m
//  20200310Dev
//
//  Created by Robert R on 3/27/15.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
// os
#include <XCTest/XCTest.h>
// helper and service api's
//#import "PeopleGroupO0.h"
//#import "InitDestroyHelperO1.h"
//#import "SignatureFactoryO0.h"
//#import "CSVO0.h"
// data plans
//#include "ArchitectureZ0Plan.h"
// other api's
//#include "HexasoftO3.h"
// quality
//#import "TestAidZ0.h"

//#import "UnixStreamO0.h"

#import "HexasoftZ3TestAid.h"

@interface HexasoftO3Tests : XCTestCase

@end

@implementation HexasoftO3Tests


- (void)setUp {
    HexasoftZ3QCapi.setupSet1(__LINE__);
}

- (void)tearDown {
    HexasoftZ3QCapi.teardownSet1(__LINE__);
}

- (void)test2020Basics
{
    if(HexasoftZ3QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(HexasoftZ3QCapi.doSet1(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:HexasoftZ3QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}// END Basics



@end
/**
 *
 */
