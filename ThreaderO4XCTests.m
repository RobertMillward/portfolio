//
//  ThreaderO4Tests.m
//
//  Created by Robert R on 11/6/14.
//  Copyright (c) 2020 Robert Russell Millward. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import "Threader.h"
#import "TestAidLow.h"
#import "TransactionLow.h"
#import "InitDestroyHelper.h"
#import "ErrorHelper.h"

@interface Threader3Tests : XCTestCase

@end

@implementation Threader3Tests

- (void)setUp {
    [super setUp];
    // Put setup code here.
    
    initThreadManagement();
}

- (void)tearDown {
    // Put teardown code here.
    
    TestAidLowC.getCounts();
    
    [super tearDown];
}


#pragma mark - Threading



int executedInErrorFlag = 0;
void threadT2099ExecutedBeforeInitNot(ThreadMgrDataP thrdmgrRow)
{
    executedInErrorFlag = 1;
    
    //QueingC.exitThread(thrdmgrRow);
}

- (void)testT2099BeforeInitThread
{
    testAidLowTxIX = 0;
    
    ThreadMgrDataP tmdP = ThreaderC.findAvailableThread();
    if(TestAidLowC.chrV(NULL,(char *)tmdP, __LINE__) == 0)
    {
        TestAidLowC.asserT(__FUNCTION__);
    }
    else
    {
        tmdP->app = threadT2099ExecutedBeforeInitNot;
        ThreaderC.execute(tmdP);
        // TECHDEBT this s/b 0 except that init is called in setup.
        if(TestAidLowC.putTestInts(1, executedInErrorFlag, __LINE__) != 0
           )
        {
            TestAidLowC.asserT(__FUNCTION__);
        }
    }
}

// void (*application)(ThreadMgr *thrdmgrData)
void threadT2099ToCountDownPercent(ThreadMgrDataP thrdmgrRowP)
{
    if(thrdmgrRowP->memSize == 0)
    {
        thrdmgrRowP->usecEstimate = 100000 * thrdmgrRowP->bizTranIX;
        return;
    }
    //printf("%i entering %d\n", __LINE__, thrdmgrRowP->bizTranIX);
    
    while(thrdmgrRowP->percentRemaining > TM_MIN_PCT)
    {
        // TECHDEBT when threads quit at exactly the same time
        // then the exit counter can be trashed. It needs to be solved but
        // this is a work around so the test works consistently.
        usleep(1000 * thrdmgrRowP->bizTranIX);
        thrdmgrRowP->percentRemaining--;
    }
    
    //printf("%i leaving %d\n", __LINE__, thrdmgrRowP->bizTranIX);
    ThreaderC.exitThread(thrdmgrRowP);
}


- (void)testT2099ThreadExecuteMoreThanHave
{
    testAidLowTxIX = 1;

    if(TestAidLowC.putTestChars(CEAOK, initThreadManagement(), __LINE__) != 0)
    {
        TestAidLowC.asserT(__FUNCTION__);
    }else
    {
        for(int anyIX = 0; anyIX < (2*ARC_NUM_THREADS) ; anyIX++)
        {
            // This needs work to attach a non-busy transaction to a thread.
            TransactionLogC.getActivityLog((char *)0, testAidLowTxIX);
            ThreadMgrDataP tmdP = ThreaderC.findAvailableThread();
            tmdP->bizTranIX = testAidLowTxIX++;
            //printf("%i btix=%d\n", __LINE__, tmdP->bizTranIX);
            tmdP->app = threadT2099ToCountDownPercent;
            ThreaderC.execute(tmdP);
        }
        testAidLowTxIX--;
        
        int maxTries = 1000;
        int cact = -1;
        while((cact = ThreaderC.isAnyThreadActive()) != 0 && maxTries--)
        {
            printf("%i %d active\n", __LINE__, cact);
        }
        if(TestAidLowC.putTestInts(0, maxTries, __LINE__) == 0)
        {
            TestAidLowC.asserT(__FUNCTION__);
        }
        
        ThreaderC.exitThreader();
    }
}



- (void)testT2099ThreadManagementInitAndFindOne
{
    if(talC.chrV(CEAOK, initThreadManagement(), __LINE__) != 0){
        talC.asserT(__FUNCTION__);
    }else{
        ThreadMgrDataP tmdP = ThreaderC.findAvailableThread();
        if(talC.intV(0, tmdP->threadIX, __LINE__) != 0){
            talC.asserT(__FUNCTION__);
        }
    }
}


- (void) testT2099SizeofThreadMgrData
{
    if(TestAidLowC.intV(80, sizeof(ThreadMgrData), __LINE__) != 0){
        TestAidLowC.asserT(__FUNCTION__);
    }
}


#pragma mark - The suite report

- (void)testZReportSuiteStats
{
    TestAidLowC.processSuiteStats();
}

@end
/**
 */
