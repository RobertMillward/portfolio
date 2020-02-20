//
//  DictZ0XCTests.m -
//  2020Mar10Dev
//
//  Created by Robert Russell Millward on 12/3/19.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
// os
#import <XCTest/XCTest.h>
// helper api's
// data plans
#import "DictZ0TestAid.h"
// quality
#import "TestAidZ0.h"

@interface DictO0CheckTests : XCTestCase
@end
@interface DictO0FormatTests : XCTestCase
@end
@interface DictO0GetTests : XCTestCase
@end


@implementation DictO0GetTests
- (void)setUp{
    TestAidZ0QCapi.basicInit();
}

- (void)tearDown{
}


- (void)test2019GetItO0{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        ErrorWarnCountT ewc = DictO0QCapi.getDictTests(CPR_FTYPE_STRL, __LINE__);
        if(ewc.classErrors != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
        
        ewc = DictO0QCapi.getDictTests(CPR_FTYPE_DUBL, __LINE__);
        if(ewc.classErrors != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
        
        ewc = DictO0QCapi.getDictTests(CPR_FTYPE_DTTM, __LINE__);
        if(ewc.classErrors != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
        
        ewc = DictO0QCapi.getDictTests(CPR_FTYPE_TEXT, __LINE__);
        if(ewc.classErrors != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}
@end



/**
 * Check
 */


@implementation DictO0CheckTests
- (void)setUp{
    TestAidZ0QCapi.basicInit();
}

- (void)tearDown{
}



- (void)test2019CheckDUBLTestsO0{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        ErrorWarnCountT ewc = DictO0QCapi.formatDictDUBLTests(__LINE__);
        if(ewc.classErrors != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}


- (void)test2019CheckDTXXTestsO0{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        ErrorWarnCountT ewc = DictO0QCapi.checkDictDTXXTests(__LINE__);
        if(ewc.classErrors != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}


- (void)test2019CheckTEXTTestsO0{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        ErrorWarnCountT ewc = DictO0QCapi.formatDictTEXTTests(__LINE__);
        if(ewc.classErrors != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}


- (void)test2019CheckSTRXTestsO0{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        ErrorWarnCountT ewc = DictO0QCapi.formatDictSTRXTests(__LINE__);
        if(ewc.classErrors != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}


- (void)test2019CheckINTGTestsO0{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        ErrorWarnCountT ewc = DictO0QCapi.formatDictINTGTests(__LINE__);
        if(ewc.classErrors != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}

@end

/**
 * Format
 */


@implementation DictO0FormatTests
- (void)setUp{
    TestAidZ0QCapi.basicInit();
}

- (void)tearDown{
}



- (void)test2019FormatDUBLTestsO0{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        ErrorWarnCountT ewc = DictO0QCapi.formatDictDUBLTests(__LINE__);
        if(ewc.classErrors != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}


- (void)test2019FormatDTXXTestsO0{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        ErrorWarnCountT ewc = DictO0QCapi.formatDictDTXXTests(__LINE__);
        if(ewc.classErrors != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}


- (void)test2019FormatTEXTTestsO0{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        ErrorWarnCountT ewc = DictO0QCapi.formatDictTEXTTests(__LINE__);
        if(ewc.classErrors != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}


- (void)test2019FormatSTRXTestsO0{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        ErrorWarnCountT ewc = DictO0QCapi.formatDictSTRXTests(__LINE__);
        if(ewc.classErrors != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}


- (void)test2019FormatINTGTestsO0{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        ErrorWarnCountT ewc = DictO0QCapi.formatDictINTGTests(__LINE__);
        if(ewc.classErrors != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}

@end // DictZ0XCTests.m

/**
 */
