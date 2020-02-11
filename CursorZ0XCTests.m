//
//  CursorZ0Tests.m
//
//  Created by Robert Russell Millward on 10/8/13.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
// os
#import <XCTest/XCTest.h>
// quality
#import "CursorZ0TestAid.h"

 
@interface CursorZ0SafetySet2Tests : XCTestCase

@end

@interface CursorZ0CsvSet3Tests : XCTestCase

@end

@interface CursorZ0SizeSet1Tests : XCTestCase

@end

@interface CursorZ0SortSet4Tests : XCTestCase

@end

@interface CursorZ0UpdateSet5Tests : XCTestCase

@end





@implementation CursorZ0SafetySet2Tests

- (void)setUp
{
    CursorO0QCapi.setupSafetySet2(__LINE__);
}

- (void)tearDown
{
    CursorO0QCapi.teardownSafetySet2(__LINE__);
}


- (void)test2019SafetySet2{
    if(CursorO0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(CursorO0QCapi.doSafetySet2(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:CursorO0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}
@end



@implementation CursorZ0SizeSet1Tests

- (void)setUp
{
    CursorO0QCapi.setupSizesSet1(__LINE__);
}

- (void)tearDown
{
    CursorO0QCapi.teardownSizesSet1(__LINE__);
}

- (void)test2999SizeofCursorSet1{
    if(CursorO0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(CursorO0QCapi.doSizesSet1(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:CursorO0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}
@end




@implementation CursorZ0SortSet4Tests

- (void)setUp
{
    CursorO0QCapi.setupSortSet4(__LINE__);
}

- (void)tearDown
{
    CursorO0QCapi.teardownSortSet4(__LINE__);
}

- (void)test2019SortLowEqlHighSet5{
    if(CursorO0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(CursorO0QCapi.doSortSet4(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:CursorO0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}
@end




@implementation CursorZ0UpdateSet5Tests

- (void)setUp
{
    CursorO0QCapi.setupUpdateSet5(__LINE__);
}

- (void)tearDown
{
    CursorO0QCapi.teardownUpdateSet5(__LINE__);
}

- (void) test2019UpdateMatchingCursorZ0{
    if(CursorO0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(CursorO0QCapi.doSetUpdateSet5(__LINE__)){
        }
    }
}
@end




 @implementation CursorZ0CsvSet3Tests

 - (void)setUp
 {
     CursorO0QCapi.setupCsvSet3(__LINE__);
 }

 - (void)tearDown
 {
     CursorO0QCapi.teardownCsvSet3(__LINE__);
 }

- (void)test2019CsvSet3{
    if(CursorO0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(CursorO0QCapi.doCsvSet3(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:CursorO0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}
@end

//END CursorZ0Tests.m
/**
 *
 */
