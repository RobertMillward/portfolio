//
//  CursorZ0Tests.m
//
//  Created by Robert Russell Millward on 10/8/13.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
// os
#import <XCTest/XCTest.h>
// helper api's
//#import "InitDestroyHelperZ0.h"
//#import "PeopleGroupO2.h"
//#import "CursorZ0.h"
//#import "TransactionZ0.h"
// data plans
//#import "ArchitectureZ0Olan.h"
#include "ErrorHelperZ0Plan.h"
// quality
#import "TestAidZ0.h"
#import "CursorZ0TestAid.h"

 

@interface CursorZ0SafetySet2Tests : XCTestCase

@end

@interface CursorZ0OtherSet3Tests : XCTestCase

@end

@interface CursorZ0SizeSet1Tests : XCTestCase

@end





@implementation CursorZ0SafetySet2Tests

- (void)setUp
{
    CursorO0QCapi.setupSet2(__LINE__);
}

- (void)tearDown
{
    CursorO0QCapi.teardownSet2(__LINE__);
}


- (void)test2019SafetySet2{
    if(CursorO0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(CursorO0QCapi.doSet2(__LINE__)){
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
    if(CursorO0QCapi.doSizesSet1(__LINE__)){
        XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:CursorO0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
    }
}


@end




@implementation CursorZ0OtherSet3Tests

- (void)setUp
{
    CursorO0QCapi.setupSet3(__LINE__);
}

- (void)tearDown
{
    CursorO0QCapi.teardownSet3(__LINE__);
}

- (void)test2019SortLowEqlHighZ0{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        char *rowAsrc = "item" FSS_ARC "w13" FSS_ARC "x1" FSS_ARC "ysome data" FSS_ARC "a";
        char *rowBsrc = "item" FSS_ARC "w13" FSS_ARC "x2" FSS_ARC "ymore data" FSS_ARC "a";
        char rowAchars[1001];
        char rowBchars[1001];
        char* sortInfoP = "HaS";
        
        strcpy(rowAchars, rowAsrc);
        CursorO0HIthisT rowA = CursorO0HCapi.newCursor(rowAchars, &TestAidZ0QCdata.gp64);
        if(TestAidC.putTestChars(IS_EQL_ARC,
                                  rowA.apiP->sort(&rowA.data, &rowA.data, sortInfoP),
                                  __LINE__) != 0 ||
           TestAidC.putTestChars("some data",
                                  rowA.apiP->getField(&rowA.data, &sortInfoP[1]),
                                  __LINE__) != 0 ||
           1 == 2){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
        
        
        strcpy(rowBchars, rowBsrc);
        CursorO0HIthisT rowB = CursorO0HCapi.newCursor(rowBchars, &TestAidZ0QCdata.gp64);
        
        if(TestAidC.putTestChars(IS_HIGH_ARC,
                                  rowA.apiP->sort(&rowA.data, &rowB.data, sortInfoP),
                                  __LINE__) != 0 ||
           TestAidC.putTestChars("some data",
                                  rowA.apiP->getField(&rowA.data, &sortInfoP[1]),
                                  __LINE__) != 0 ||
           1 == 2){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
        
        
        if(TestAidC.putTestChars(IS_LOW_ARC,
                                  rowA.apiP->sort(&rowB.data, &rowA.data, sortInfoP),
                                  __LINE__) != 0 ||
           TestAidC.putTestChars("more data",
                                  rowB.apiP->getField(&rowB.data, &sortInfoP[1]),
                                  __LINE__) != 0 ||
           1 == 2){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}


- (void) test2019UpdateMatchingCursorZ0{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        char *origCursorStr = "item" FSS_ARC "w13" FSS_ARC "x1" FSS_ARC "ysome data" FSS_ARC "a";
        char *updtCursorStr = "item" FSS_ARC "w13" FSS_ARC "x2" FSS_ARC "ymore data" FSS_ARC "b";
        char wkoCursorStr[1001];
        char wkuCursorStr[1001];
        char *myGotChars;
        char *myExpectChars;
        
        strcpy(wkoCursorStr, origCursorStr);
        CursorO0HIthisT tRo = CursorO0HCapi.newCursor(wkoCursorStr, &TestAidZ0QCdata.gp64);
        
        strcpy(wkuCursorStr, updtCursorStr);
        CursorO0HIthisT tRu = CursorO0HCapi.newCursor(wkuCursorStr, &TestAidZ0QCdata.gp64);
        
        tRo.apiP->updateMatchingCursor(&tRo.data, &tRu.data);
        
        for(char fIX = 'a' ; fIX <= 'z' ; fIX++){
            
            myGotChars = tRo.apiP->getField(&tRo.data, &fIX);
            
            switch (fIX) {
                case ITEM_NAME_ROW: myExpectChars = "item";         break;
                case ID_ROW:        myExpectChars = "13";           break;
                case STATUS_ROW:    myExpectChars = "2";            break;
                case SOURCE_ROW:    myExpectChars = "";             break;
                case 'a':           myExpectChars = "some data";    break;
                case 'b':           myExpectChars = "more data";    break;
                default:            myExpectChars = NULL;           break;
            }
            
            if(TestAidC.putTestChars(myExpectChars, myGotChars, __LINE__) != 0){
                XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
            }
        }
    }
}


/** EOW
- (void)test2019newCursor0EOWZ0{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        char *doCursorStr = "item\034wrowID\034x1\034ysome data\034a" EOW;
        char wkCursorStr[1001];
        char ckCursorStr[1001];
        strcpy(wkCursorStr, doCursorStr);
        CursorZ0AInewT tR = newCursor(wkCursorStr, &TestAidZ0QCdata.twoWay);
        tR.api->toRow(&tR.data, ckCursorStr);
        
        strcat(ckCursorStr, EOW);
        if(TestAidC.putTestChars(doCursorStr, ckCursorStr, __LINE__) != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}
 */

- (void)test2019CsvSet3{
    if(CursorO0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(CursorO0QCapi.doSet3(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:CursorO0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}
@end

//END CursorZ0Tests.m
/**
 *
 */
