//
//  CompareZ0XCTests.m (should be O0)
//
//  Created by Robert R on 2/21/15.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
// os
#import <XCTest/XCTest.h>
// data plan
// api's
// aids
#import "CompareZ0TestAid.h"
#import "TestAidZ0.h"

@interface CompareZ0Tests : XCTestCase

@end

@implementation CompareZ0Tests


- (void)setUp {
}

- (void)tearDown {
    TestAidC.getCounts();
}



- (void)test2019AsortStrAandB {
    if(TA0C.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        char *retStr = NULL;
        sortNullsArcT sn = NULLS_HI_ARC;
        /*fieldTypeT*/ char tp = CPR_FTYPE_STRL; // TODO
        
        char *a = "a val";
        char *b = "b val";
        
        retStr = CompareO0HCapi.sortTwoFields(a, b, tp, sn);
        if(TestAidZ0QCapi.putTestChars(IS_LOW_ARC, retStr, __LINE__) != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
        
        retStr = CompareO0HCapi.sortTwoFields(a, a, tp, sn);
        if(TestAidZ0QCapi.putTestChars(IS_EQL_ARC, retStr, __LINE__) != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
        
        retStr = CompareO0HCapi.sortTwoFields(b, a, tp, sn);
        if(TestAidZ0QCapi.putTestChars(IS_HIGH_ARC, retStr, __LINE__) != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}


- (void)test2019AsortNull {
    if(TA0C.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        char *retStr = NULL;
        sortNullsArcT sn = NULLS_HI_ARC;
        /*fieldTypeCprT*/ char tp = CPR_FTYPE_STRL; // TODO
        
        char *a = "a val";
        
        retStr = CompareO0HCapi.sortTwoFields(a, 0, tp, sn);
        if(TestAidC.putTestChars(NULL_LO_ARC, retStr, __LINE__) != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
        
        retStr = CompareO0HCapi.sortTwoFields(0, a, tp, sn);
        if(TestAidC.putTestChars(NULL_HI_ARC, retStr, __LINE__) != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
        
        retStr = CompareO0HCapi.sortTwoFields(0, 0, tp, sn);
        if(TestAidC.putTestChars(UNDEFINED_ARC, retStr, __LINE__) != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
        
        sn = NULLS_LO_ARC;
        
        retStr = CompareO0HCapi.sortTwoFields(a, 0, tp, sn);
        if(TestAidC.putTestChars(NULL_HI_ARC, retStr, __LINE__) != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
        
        retStr = CompareO0HCapi.sortTwoFields(0, a, tp, sn);
        if(TestAidC.putTestChars(NULL_LO_ARC, retStr, __LINE__) != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
        
        retStr = CompareO0HCapi.sortTwoFields(0, 0, tp, sn);
        if(TestAidC.putTestChars(UNDEFINED_ARC, retStr, __LINE__) != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}



- (void)test2019AsortTimeAandB {
    if(TA0C.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        char *retStr = NULL;
        sortNullsArcT sn = NULLS_HI_ARC;
        /*fieldTypeCprT*/ char tp = CPR_FTYPE_DTTM; // TODO
        
        char *a = "a val";
        char *b = "b val";
        
        retStr = CompareO0HCapi.sortTwoFields(a, b, tp, sn);
        if(TestAidC.putTestChars(IS_LOW_ARC, retStr, __LINE__) != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
        
        retStr = CompareO0HCapi.sortTwoFields(a, a, tp, sn);
        if(TestAidC.putTestChars(IS_EQL_ARC, retStr, __LINE__) != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
        
        retStr = CompareO0HCapi.sortTwoFields(b, a, tp, sn);
        if(TestAidC.putTestChars(IS_HIGH_ARC, retStr, __LINE__) != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}




- (void)test2019AlikeSeveralB {
    if(TA0C.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        
        itemCountT failedTestCount = CompareZ0QCapi.aLikeTest(__LINE__);
        
        if(failedTestCount > 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}




- (void)test2019EdwardSimilar {
    if(TA0C.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        
        itemCountT failedTestCount = CompareZ0QCapi.edwardSimilarTest(__LINE__);
        
        if(failedTestCount > 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}




@end

//END CompareZ0XCTests.m
