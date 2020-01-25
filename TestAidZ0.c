//
//  TestAidZ0.c
//
//  Created by Robert Russell Millward on 11/29/13.
//  Copyright (c) 2020 Robert Russell Millward. All rights reserved.
//
// os
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
// data
// api
#include "TimeSerNbrO0.h"
#include "RowO0.h"
// quality
#include "TestAidZ0.h"

/*
 */
#pragma mark - class data.
/*
 */

#define TRANSACTION_ID 1
#define IS_BATCH false

TestAidZ0QCdataT TestAidZ0QCdata =
{
    {
        KNOW_MAYBE_ARC,         // twoWayStatusPT twoWayStatusP;
        IS_BATCH,               // x isBatch;
        TRANSACTION_ID,         // x transactionIx;
        TINY_PPLG,              // x peopleGroupSize;
        CURRENT_BASE_YEAR
    }/*,
    {
        GOOD_LOGIN_PPLGRP,      // peopleGroupIdT   peopleGroupId;
        "XX",                   // appSigT          appSig;
        "0",                    // appWeeksOldT     appWeeksOldOverRide;
        "XX",                   // roleSigT         roleSig;
        "0",                    // roleLevelT       rollLevel;
        "ABCDEABCDE",           // personSigT       personSig;
        "0",                    // roleExpertiseT   roleExpertise;
        &TestAidZ0QCdata.twoWay
        // gpVersionLevelZ0PT flagsForCodeVersionAndLevelP;
        // {Zchr callerSeesVersion;, Zchr callerSeesLevel;}
        // If new then comes from creator's signature information.
        
    } */
};




int  testAidZ0TxIX = TRANIX_FOR_THREADER_TXL; // obsolete, is incremented in many cases
//static char testAidZ0Ctext[2000+1];
static char testAidZ0Ttext[20000+1];
static char testAidZ0ExpectChars[1000+1];
static char testAidZ0GotChars[1000+1];
static int  testAidZ0ExpectInt;
static int  testAidZ0GotInt;
static int  testAidZ0LineNbr = 0;


    
    
static struct TALPrivate
{
    int  assertCount;
    int  suiteAssertCount;
    int  runAssertCount;
    int  failureCount;
    int  suiteFailureCount;
    int  runFailureCount;
}talF =
{
    0,
    0,
    0,
    0,
    0,
    0
};
/*
 */
#pragma mark - Init and destroy
/*
 */
static void
basicInitZ0()
{
    TestAidZ0QCdata.showFunctionName = TRM_HIDEFUNC;
    TestAidZ0QCdata.twoWay.groupBaseYear = CURRENT_BASE_YEAR;
}

#pragma mark - Test scheduling

static bool
isScheduledZ0(const char *fileFuncName, bool showFunc)
{
    theStampAIdataT myStamp = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, CURRENT_BASE_YEAR};
    TimeSerNbrO0ACapi.newTimeAndSerNbrNow(&myStamp);
    
    char *funcP = strstr(fileFuncName, "test");
    Ulng dt = strtol(funcP + 4, NO_ARG_PTR_ARC, RADIX_10_ARC);
    if(dt == 0){
        // Tests with no date are always run.
        dt = 9999;
    }
    if(dt <= 9999){
        // Tests with only years are treated as December.
        dt *= 100;
        dt += 12;
    }
    
    return ((myStamp.currentYear * 100) + 12) < dt + TA_FOR_YRS; // TODO
}



#pragma mark - transaction management

static void
nextTxIxZ0()
{
    TestAidZ0QCdata.twoWay.transactionIx++;
    if(TestAidZ0QCdata.twoWay.transactionIx > LOG_BUF_Z0CT_TXL){
        TestAidZ0QCdata.twoWay.transactionIx = 1;
    }
}







#pragma mark - assert management


#define ASSERTROW_TEST_NAME   'a'
#define ASSERTROW_EXPECT      'e'
#define ASSERTROW_CONDITION   'f'
#define ASSERTROW_GOT         'g'



static void
testAidToRowZ0(const char *testName)
{
    talF.failureCount++;
    
    targetPT hereP = testAidZ0Ttext;
    RowO0ACapi.clearTgt(testAidZ0Ttext, sizeof(testAidZ0Ttext));
    
    if(hereP != 0)
    {
        RowO0ACapi.addMore(ITEM_NAME_ROW,   "assert", testAidZ0Ttext);
        char wk[20];
        sprintf(wk, "%d", testAidZ0LineNbr);
        RowO0ACapi.addMore(ID_ROW,          wk, testAidZ0Ttext);
        sprintf(wk, "%c", DEBUG_ROWST);
        RowO0ACapi.addMore(STATUS_ROW,      wk, testAidZ0Ttext);
        RowO0ACapi.addMore(SOURCE_ROW,      (char*)testName, testAidZ0Ttext);
        
        
        RowO0ACapi.addMore(ASSERTROW_EXPECT, testAidZ0ExpectChars, testAidZ0Ttext);
        char *fFactor = "NE";
        if(strcmp(testAidZ0ExpectChars, testAidZ0GotChars) == 0){
            fFactor = "EQ";
        }
        RowO0ACapi.addMore(ASSERTROW_CONDITION, fFactor, testAidZ0Ttext);
        RowO0ACapi.addMore(ASSERTROW_GOT, testAidZ0GotChars, testAidZ0Ttext);
        
        RowO0ACapi.finish(hereP);
    }
}

enum TRMReportLevelE
{
    TRM_TEST,
    TRM_SUITE,
    TRM_RUN
}TRMReportLevelE;


static void
getCountsZ0()
{
    int ct = talF.assertCount;
    int fl = talF.failureCount;
    char *lvl = "  test";
    
    if(talF.assertCount == 0){
        lvl = "*suite";
        ct = talF.suiteAssertCount;
        fl = talF.suiteFailureCount;
        if(talF.suiteAssertCount == 0){
            lvl = "** run";
            ct = talF.runAssertCount;
            talF.runAssertCount = 0;
            fl = talF.runFailureCount;
            talF.runFailureCount = 0;
        }else{
            talF.runAssertCount += talF.suiteAssertCount;
            talF.suiteAssertCount = 0;
            talF.runFailureCount += talF.suiteFailureCount;
            talF.suiteFailureCount = 0;
        }
    }else{
        talF.suiteAssertCount += talF.assertCount;
        talF.assertCount = 0;
        talF.suiteFailureCount += talF.failureCount;
        talF.failureCount = 0;
    }
    if(ct != 0){
        sprintf(testAidZ0Ttext, // testAidZ0Ctext
               "*\n%s level note: %d asserts were processed with %d failures\n*\n",
               lvl, ct, fl);
    }
}


static int
putIntsZ0(expectIntT expect,
          actualIntT got,
          lineNbrT lineNbr)
{
    talF.assertCount++;
    
    sprintf(testAidZ0ExpectChars, "%d", expect);
    sprintf(testAidZ0GotChars, "%d", got);
    testAidZ0ExpectInt = expect;
    testAidZ0GotInt = got;
    testAidZ0LineNbr = lineNbr;
    
    return (expect - got);
}

static int
putCharsZ0(
        expectCharPT expect,
        actualCharPT got,
        lineNbrT lineNbr)
{
    talF.assertCount++;
    
    if(expect == NULL){
        expect = TA_NULL;
    }
    if(got == NULL){
        got = TA_NULL;
    }
    
    strcpy(testAidZ0ExpectChars, expect);
    strcpy(testAidZ0GotChars, got);
    testAidZ0LineNbr = lineNbr;
    
    return strcmp(testAidZ0ExpectChars, testAidZ0GotChars);
}


#pragma mark - statistics

bool isNoErrorsZ0(){
    return talF.failureCount == 0;
}



static char *
getAssertTextZ0(cfileNameT testName)
{
    testAidToRowZ0(testName);
    return testAidZ0Ttext;
}




TestAidQCapiT TestAidQCapi =
{
    basicInitZ0,
    nextTxIxZ0,
    isScheduledZ0,
    putIntsZ0,
    putCharsZ0,
    getCountsZ0,
    getAssertTextZ0
};

//END TestAidZ0.c
