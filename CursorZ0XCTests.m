//
//  CursorZ0Tests.m
//
//  Created by Robert Russell Millward on 10/8/13.
//  Copyright (c) 2013 Robert Russell Millward.
//  All rights reserved.
//

#import <XCTest/XCTest.h>
//#import "CursorZ0.h"
//#import "TransactionZ0.h"
#import "TestAidZ0.h"
//#import "ArchitectureZ0.h"
//#import "InitDestroyHelperZ0.h"
//#import "PeopleGroupO2.h"
#import "CursorZ0TestAid.h"

 

@interface CursorZ0NewTests : XCTestCase

@end

@implementation CursorZ0NewTests


- (void)setUp
{
    TestAidC.nextTx();
}

- (void)tearDown
{
    TestAidC.getCounts();
}


#pragma mark - Tests


- (void)test2019NewEmptyZ0{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){

        ErrorWarnCountT errWrn = CursorO0QIapi.toRowSafety(__LINE__, __FUNCTION__);
        
        if(errWrn.instanceErrors != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
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


- (void)test2019newCursor0NoEOWZ0{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        char *doCursorStr = "item\034wrowID\034x1\034ysome data\034a";
        char wkCursorStr[1001];
        char ckCursorStr[1001];
        strcpy(wkCursorStr, doCursorStr);
        CursorO0HInewT tR = CursorO0HCapi.newCursor(wkCursorStr, &TestAidZ0QCdata.gp64);
        //tR.apiP->toRow(&tR.data, ckCursorStr); TODO
        
        if(TestAidC.putTestChars(doCursorStr, ckCursorStr, __LINE__) != 0){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}

- (void)test2019newCursorZ0Csv{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        char *doCursorStr = "zaz,\"zbz\",zcz,,zez,zfz,,,";
        char *ckCursorStr = "zaz" FSS_ARC "a" "zbz" FSS_ARC "b" "zcz" FSS_ARC "c" "zez" FSS_ARC "e" "zfz" FSS_ARC "f";
        char wkcsvCursorStr[1001];
        strcpy(wkcsvCursorStr, doCursorStr);
        CursorO0HInewT tR = CursorO0HCapi.newCursor(wkcsvCursorStr, &TestAidZ0QCdata.gp64);
        char wkjnlCursorStr[1001];
        //tR.apiP->toRow(&tR.data, wkjnlCursorStr); TODO
        
        if(TestAidC.putTestChars(ckCursorStr, wkjnlCursorStr, __LINE__) != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}
@end


@interface CursorZ0SizeTests : XCTestCase

@end

@implementation CursorZ0SizeTests


- (void)setUp
{
    TestAidC.nextTx();
}

- (void)tearDown
{
    TestAidC.getCounts();
}

- (void)test2999SizeofCursorZ0{
    // Added functionality and bigger x-field in early 2015.
    if(TestAidC.putTestInts(240, sizeof(CursorO0HInewT), __LINE__) != 0){
        XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
    }
}


@end



@interface CursorZ0OtherTests : XCTestCase

@end

@implementation CursorZ0OtherTests

- (void)test2019SortLowEqlHighZ0{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        char *rowAsrc = "item" FSS_ARC "w13" FSS_ARC "x1" FSS_ARC "ysome data" FSS_ARC "a";
        char *rowBsrc = "item" FSS_ARC "w13" FSS_ARC "x2" FSS_ARC "ymore data" FSS_ARC "a";
        char rowAchars[1001];
        char rowBchars[1001];
        char* sortInfoP = "HaS";
        
        strcpy(rowAchars, rowAsrc);
        CursorO0HInewT rowA = CursorO0HCapi.newCursor(rowAchars, &TestAidZ0QCdata.gp64);
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
        CursorO0HInewT rowB = CursorO0HCapi.newCursor(rowBchars, &TestAidZ0QCdata.gp64);
        
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
        CursorO0HInewT tRo = CursorO0HCapi.newCursor(wkoCursorStr, &TestAidZ0QCdata.gp64);
        
        strcpy(wkuCursorStr, updtCursorStr);
        CursorO0HInewT tRu = CursorO0HCapi.newCursor(wkuCursorStr, &TestAidZ0QCdata.gp64);
        
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

@end

//END CursorZ0Tests.m
