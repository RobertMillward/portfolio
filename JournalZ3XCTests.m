//
//  JournalZ3Tests.m - test with permission level code 
//
//  Created by Robert Russell Millward on 9/26/13.
//  Copyright (c) 2020 Robert Russell Millward. All rights reserved.
//

#import <XCTest/XCTest.h>
// api
#import "JournalO0.h"
#import "TransactionO3.h"

//#include "PeopleGroupO0.h"
// data
#import "ArchitectureZ0Plan.h"
#import "InitDestroyHelperZ3Plan.h"
#import "RowZ0Plan.h"
#import "TransactionZ3Plan.h"
#import "UnixStreamZ0Plan.h"
// quality
#import "TestAidZ0.h"
#import "JournalZ3TestAid.h"

/**
 * Memory is virgin for each XCode test.
 * Get the expected values for a new instance,
 * add the pointer to the info block.
 */
static JnlAidQ3ExpectT expectData;
void getMyExpectedData()
{
    expectData = JnlAidQ.getInitialExpect();
}

@interface JournalO3PathTests : XCTestCase

@end

@implementation JournalO3PathTests


- (void)setUp
{
    TestAidC.basicInit();
    /*
     * The testAid provides expected results that can be modified as a test progresses.
     */
    getMyExpectedData();
    
    /*
     * Initialize the system.
     */
    TestAidZ0QCdata.twoWay.isBatch = false;
    /*initStatusT status = */initJournalsPathO3(HOMEPATH_JNL, &TestAidZ0QCdata.twoWay);
    /*initStatusT status = */initJournalsPathO3("xx", &TestAidZ0QCdata.twoWay);  // Remove from Class
    
}

- (void)tearDown
{
    //TestAidC.getCounts();
    InitDestroyerZ3HCapi.destroyAll(&TestAidZ0QCdata.twoWay);
}

- (void)test201901SetBadJournalPath
{
    bool isMoreElse = true;
    int elseIndex = 0;
    while(isMoreElse)
    {
        elseIndex++;
        switch(elseIndex)
        {
            default: // automatic shutoff
                isMoreElse = false;
                
                char* report = InitDestroyerHCapi.getReport();
                if(report[0] != 0)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:InitDestroyerHCapi.getReport()]);
                    report[0] = 0;
                }
                break;
            case 1:
                isMoreElse = TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName);
                break;
            case 2:
                /*initStatusT status =*/ initJournalsPathO3("bad/path", &TestAidZ0QCdata.twoWay); // needs to count an instance warning
                expectData.testAid.classWarnings = 0;
                if(TestAidC.putTestInts(expectData.testAid.classWarnings,
                                        TransactionLogPrepHCapi.getWarnCt(&TestAidZ0QCdata.twoWay),
                                        __LINE__) != 0)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
        }
    }
}

@end






@interface JournalO3Tests : XCTestCase

@end

@implementation JournalO3Tests


- (void)setUp
{
    TestAidC.basicInit();
    /*
     * The testAid provides expected results that can be modified as a test progresses.
     */
    getMyExpectedData();

    /*initStatusT status = */initJournalsPathO3(HOMEPATH_JNL, &TestAidZ0QCdata.twoWay);
    /*initStatusT status = */initJournalsPathO3("xx", &TestAidZ0QCdata.twoWay);
    
}

- (void)tearDown
{
    //TestAidC.getCounts();
    InitDestroyerHCapi.destroyAll(&TestAidZ0QCdata.twoWay);
}

#pragma mark - Tests

- (void)test201901AtEOFOpenWrite // Alphabetically first but not the correct name
{
    JournalZ3AIdataT tJ;
    bool isMoreElse = true;
    int elseIndex = 0;
    char* status;
    while(isMoreElse)
    {
        elseIndex++;
        switch(elseIndex)
        {
            default:
                isMoreElse = false; // guarantee termination
                break;
            case 1:
                isMoreElse = TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName);
                break;
            case 2:
                if((status = JnlAidQ.getNewJournalForTest(&tJ, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
            case 3:
                expectData.isConsistant = KNOW_YES_ARC;
                if((status = JnlAidQ.openWriteForTest(&tJ, JRNLFILE_QL, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
            case 4:
                expectData.isConsistant = KNOW_NO_ARC;
                if((status = JnlAidQ.closeForTest(&tJ, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
        }
    }
}



- (void)test201901CloseBadPath
{
    bool isMoreElse = true;
    int elseIndex = 0;
    char* status;
    
    JournalZ3AIdataT tJ;
    
    while(isMoreElse)
    {
        elseIndex++;
        switch(elseIndex)
        {
            default: // automatic shutoff
                isMoreElse = false;
                break;
            case 1:
                isMoreElse = TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName);
                break;
            case 2:
                if((status = JnlAidQ.getNewJournalForTest(&tJ, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
            case 3:
                /*initStatusT status = */initJournalsPathO3("bad/path", &TestAidZ0QCdata.twoWay);
                expectData.testAid.classWarnings = 1; // Journal is not open
                if((status = JnlAidQ.closeForTest(&tJ, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
        }
    }
}


- (void)test201901CloseNoPath
{
    bool isMoreElse = true;
    int elseIndex = 0;
    char* status;
    
    JournalZ3AIdataT tJ;
    
    while(isMoreElse)
    {
        elseIndex++;
        switch(elseIndex)
        {
            default: // automatic shutoff
                isMoreElse = false;
                break;
            case 1:
                isMoreElse = TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName);
                break;
            case 2:
                if((status = JnlAidQ.getNewJournalForTest(&tJ, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
            case 3:;
                expectData.testAid.classWarnings = 1; // Journal is not open
                if((status = JnlAidQ.closeForTest(&tJ, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
        }
    }
}

- (void)test201901NewIsInconsistent
{
    bool isMoreElse = true;
    int elseIndex = 0;
    char* status;
    
    JournalZ3AIdataT tJ;
    
    while(isMoreElse)
    {
        elseIndex++;
        switch(elseIndex)
        {
            default: // automatic shutoff
                isMoreElse = false;
                break;
            case 1:
                isMoreElse = TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName);
                break;
            case 2:
                if((status = JnlAidQ.getNewJournalForTest(&tJ, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
        }
    }
}



- (void)test201901OpenReadBadPath
{
    bool isMoreElse = true;
    int elseIndex = 0;
    char *file = JRNLFILE_QL;
    char* status;
    
    JournalZ3AIdataT tJ;
    
    while(isMoreElse)
    {
        elseIndex++;
        switch(elseIndex)
        {
            default: // automatic shutoff
                isMoreElse = false;
                break;
            case 1:
                isMoreElse = TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName);
                break;
            case 2:
                if((status = JnlAidQ.getNewJournalForTest(&tJ, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
            case 3:
                /*initStatusT status = */initJournalsPathO3("bad/path", &TestAidZ0QCdata.twoWay);
                strcpy(tJ.permissionP->peopleGroupId, "badGrup");
                expectData.openMode[0] = RO_MODE_UXSTRM[0];
                if((status = JnlAidQ.openReadForTest(&tJ, file, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
            case 4:
                expectData.testAid.classWarnings = 1; // Journal could not open
                if((status = JnlAidQ.closeForTest(&tJ, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
        }
    }
    
}


- (void)test201901OpenReadNoPath
{
    bool isMoreElse = true;
    int elseIndex = 0;
    char *file = JRNLFILE_QL;
    char* status;
    
    JournalZ3AIdataT tJ;
    
    while(isMoreElse)
    {
        elseIndex++;
        switch(elseIndex)
        {
            default: // automatic shutoff
                isMoreElse = false;
                break;
            case 1:
                isMoreElse = TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName);
                break;
            case 2:
                if((status = JnlAidQ.getNewJournalForTest(&tJ, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
            case 3:
                strcpy(tJ.permissionP->peopleGroupId, "badGrup");
                expectData.openMode[0] = RO_MODE_UXSTRM[0];
                if((status = JnlAidQ.openReadForTest(&tJ, file, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
            case 4:
                expectData.testAid.classWarnings = 1; // Journal could not open
                if((status = JnlAidQ.closeForTest(&tJ, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
        }
    }
}


- (void)test201901OpenReadWarnings
{
    bool isMoreElse = true;
    int elseIndex = 0;
    char *file = JRNLFILE_QL;
    char* status;
    
    JournalZ3AIdataT tJ;
    
    while(isMoreElse)
    {
        elseIndex++;
        switch(elseIndex)
        {
            default: // automatic shutoff
                isMoreElse = false;
                
                char* report = InitDestroyerHCapi.getReport();
                if(report[0] != 0)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:InitDestroyerHCapi.getReport()]);
                    report[0] = 0;
                }
                break;
            case 1:
                isMoreElse = TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName);
                break;
            case 2:
                if((status = JnlAidQ.getNewJournalForTest(&tJ, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
            case 3:
                strcpy(tJ.permissionP->peopleGroupId, "badGrup");
                expectData.openMode[0] = RO_MODE_UXSTRM[0];
                if((status = JnlAidQ.openReadForTest(&tJ, file, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
        }
    }
}





- (void)test201901OpenWriteBadPath
{
    bool isMoreElse = true;
    int elseIndex = 0;
    char* status;
    
    JournalZ3AIdataT tJ;
    
    while(isMoreElse)
    {
        elseIndex++;
        switch(elseIndex)
        {
            default: // automatic shutoff
                isMoreElse = false;
                
                char* report = InitDestroyerHCapi.getReport();
                if(report[0] != 0)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:InitDestroyerHCapi.getReport()]);
                    report[0] = 0;
                }
                break;
            case 1:
                isMoreElse = TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName);
                break;
            case 2:
                if((status = JnlAidQ.getNewJournalForTest(&tJ, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
            case 3:
                /*initStatusT status = */initJournalsPathO3("bad/path", &TestAidZ0QCdata.twoWay);
                strcpy(tJ.permissionP->peopleGroupId, "badGrup");
                
                if((status = JnlAidQ.openWriteForTest(&tJ, "17.leaf", __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
            case 4:
                expectData.testAid.classWarnings = 1; // Journal could not open
                if((status = JnlAidQ.closeForTest(&tJ, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
        }
    }
}





- (void)test201901OpenWriteNoPath
{
    bool isMoreElse = true;
    int elseIndex = 0;
    char* status;
    
    JournalZ3AIdataT tJ;
    
    while(isMoreElse)
    {
        elseIndex++;
        switch(elseIndex)
        {
            default: // automatic shutoff
                isMoreElse = false;
                break;
            case 1:
                isMoreElse = TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName);
                break;
            case 2:
                if((status = JnlAidQ.getNewJournalForTest(&tJ, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                
                strcpy(tJ.permissionP->peopleGroupId, "badGrup");
                if((status = JnlAidQ.openWriteForTest(&tJ, "17.leaf", __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
            case 3:
                expectData.testAid.classWarnings = 1; // Journal could not open
                if((status = JnlAidQ.closeForTest(&tJ, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
        }
    }
}






- (void)test201901OpenWriteReadClose
{
    bool isMoreElse = true;
    int elseIndex = 0;
    char* status;

    char wkBuf[1024];
    char *testStr[] = {
        "0=ztestData=w1=xNow is the time for all good men=a",
        "0=ztestRow=w0=xHeavenly shades of night are falling.=a",
        "0=zNeverSee=w0=xNever see this row=a"};
    char wk[1001];
    char *file = JRNLFILE_QL;
    JournalZ3AIdataT tJ;
    
    while(isMoreElse)
    {
        elseIndex++;
        switch(elseIndex)
        {
            default: // automatic shutoff
                isMoreElse = false;
                
                char* report = InitDestroyerHCapi.getReport();
                if(report[0] != 0)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:InitDestroyerHCapi.getReport()]);
                    report[0] = 0;
                }
                break;
            case 1:
                isMoreElse = TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName);
                break;
            case 2: // Create journal object and open the journal for truncate
                strcpy(expectData.permissionP->peopleGroupId, GOOD_LOGIN_PPLGRP);
                if((status = JnlAidQ.getNewJournalForTest(&tJ, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
            case 3:
                expectData.openMode[0] = TRUNCATE_MODE_UXSTRM[0];
                if((status = JnlAidQ.setTruncateForTest(&tJ, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
            case 4:
                expectData.isConsistant = KNOW_YES_ARC;
                if((status = JnlAidQ.openWriteForTest(&tJ, file, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
            case 5: // Write record 1 then close
                strcpy(wk, testStr[0]);
                expectData.operations = 1;
                if((status = JnlAidQ.writeForTest(&tJ, wk, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
            case 6:
                expectData.isConsistant = KNOW_NO_ARC;
                if((status = JnlAidQ.closeForTest(&tJ, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
             case 7: // Open to write record 2
                getMyExpectedData();
                if((status = JnlAidQ.getNewJournalForTest(&tJ, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
            case 8:
                expectData.isConsistant = KNOW_YES_ARC;
                if((status = JnlAidQ.openWriteForTest(&tJ, file, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
            case 9: // Write record 2 then close
                strcpy(wk, testStr[1]);
                expectData.operations = 1;
                if((status = JnlAidQ.writeForTest(&tJ, wk, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
            case 10:
                expectData.isConsistant = KNOW_NO_ARC;
                if((status = JnlAidQ.closeForTest(&tJ, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
            case 11: // Verify record 1 and record 2
                getMyExpectedData();
                if((status = JnlAidQ.getNewJournalForTest(&tJ, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
            case 12:
                expectData.isConsistant = KNOW_YES_ARC;
                expectData.openMode[0] = RO_MODE_UXSTRM[0];
                if((status = JnlAidQ.openReadForTest(&tJ, file, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
            case 13:
                for(int rowIx = 0; rowIx <= 1; rowIx++){
                    char wk[2000];
                    expectData.operations++;
                    if(rowIx == 1)
                    {
                        expectData.isAtEOF = true;
                    }
                    if((status = JnlAidQ.readForTest(&tJ, wk, __LINE__, &expectData)) != KNOW_YES_ARC)
                    {
                        XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                        isMoreElse = false;
                    }
                    strcpy(wkBuf, testStr[rowIx]);
                    strcat(wkBuf, EOW);
                    //printf("data='%s'\n", inBuf);
                    //printf("ctrl='%s'\n", wkBuf);
                    if(TestAidC.putTestChars(wkBuf, wk, __LINE__))
                    {
                        XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                        isMoreElse = false;
                        break;
                    }
                    
                }
                break;
            case 14: // Close (from reading)
                expectData.isConsistant = KNOW_NO_ARC;
                if((status = JnlAidQ.closeForTest(&tJ, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
        }
    }
}


- (void)test201901OpenWriteWarnings
{
    bool isMoreElse = true;
    int elseIndex = 0;
    char* status;
    
    JournalZ3AIdataT tJ;
    
    while(isMoreElse)
    {
        elseIndex++;
        switch(elseIndex)
        {
            default: // automatic shutoff
                isMoreElse = false;
                
                char* report = InitDestroyerHCapi.getReport();
                if(report[0] != 0)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:InitDestroyerHCapi.getReport()]);
                    report[0] = 0;
                }
                break;
            case 1:
                isMoreElse = TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName);
                break;
            case 2:
                if((status = JnlAidQ.getNewJournalForTest(&tJ, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
            case 3:
                strcpy(tJ.permissionP->peopleGroupId, "badGrup");
                if((status = JnlAidQ.openWriteForTest(&tJ, "17.leaf", __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
            case 4:
                expectData.testAid.classWarnings = 1; // Journal could not open
                if((status = JnlAidQ.closeForTest(&tJ, __LINE__, &expectData)) != KNOW_YES_ARC)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    isMoreElse = false;
                }
                break;
        }
    }
}


@end
//RND JournalZ3Tests.m
