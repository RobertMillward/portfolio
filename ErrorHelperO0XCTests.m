//
//  ErrorHelperO0XCTests.m
//
//  Created by Robert R on 10/22/14.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//


#import <XCTest/XCTest.h>
// api
#import "ErrorHelperO0.h"
// data plans
#import "ErrorHelperZ0Plan.h"
// api's
// quality
#import "TestAidZ0.h"

@interface ErrorHelperO0Tests : XCTestCase

@end

@implementation ErrorHelperO0Tests

- (void)setUp {
}

- (void)tearDown
{
}

/**
 * This little bit of testing is not worth the crafting of a ErrorHelperZ0Aid.c/h set.
 */
- (void)test2099EHO0setGet
{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName))
    {
        int goodBase = ERRERRBASE;
        char* badTxt = "99.Bad text, good base";
        int badBase = 9999;
        char* goodTxt = " 1.Good text, bad base";
        int badNbr = -1;
        int goodNbr = 28;
        
        if(TestAidQCapi.putTestChars(CEINVAL, ErrorHelperACapi.set(badTxt, goodBase), __LINE__) != 0 ||
           TestAidC.putTestChars(CEINVAL, ErrorHelperACapi.set(goodTxt, badBase), __LINE__) != 0 ||
           TestAidC.putTestChars(CEINVAL, ErrorHelperACapi.get(badNbr), __LINE__) != 0 ||
           TestAidC.putTestChars(CENOSPC, ErrorHelperACapi.get(goodNbr), __LINE__) != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}


@end // ErrorHelperO0XCTests.m
/**
 */
