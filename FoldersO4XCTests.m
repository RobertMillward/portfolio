//
//  Folders4Tests.m
//
//  Created by Robert Russell Millward on 10/16/13.
//  Copyright (c) 2013 Robert Russell Millward. All rights reserved.
//
#import <XCTest/XCTest.h>
#import "BufferShare0.h"
#import "Folders4.h"
#import "Row2.h"
#import "TestAid0.h"
#import "ErrorHelper0.h"
#import "InitDestroyHelper1.h"

@interface Folders4Tests : XCTestCase

@end


@implementation Folders4Tests


// The execution does this per test.

- (void)setUp
{
    [super setUp];
    
    // Set-up code below here.

    TestAidC.nextTx();

    initStatusT status = initFolders();
    
}

- (void)tearDown
{
    TestAidC.getCounts();
    
    // Tear-down code above here.
    
    [super tearDown];
}



#pragma mark - Tests


-(void) testGetFolderInfoThatExists
{
    char here[4096];
    BufferShare bufShr = newBufferShare(here, here + sizeof(here) -1, testAid0TxIX);
    likePT like = "some*like";
    
    FolderC.getFolderInfo(TA_HOMPATH, TA_GRPFLDR, like, &bufShr, testAid0TxIX);
    Row mFI = newRow(bufShr.currentRead, testAid0TxIX);
    
    if(TestAidC.putTestInts(ACTIVE_ROWST, *mFI.rowStatus, __LINE__) != 0 ||
       TestAidC.putTestChars("folderInfo", mFI.itemName, __LINE__) != 0  ||
       1 == 2){
        TestAidC.asserT(__FUNCTION__);
    }
}

-(void) testGetExistsNo
{
    char *retPtr = IDH_DO_HERE_INIT;
    
    int tE = FolderC.exists(TA_HOMPATH, TA_GRPFLDR, testAid0TxIX);
    if(tE != EMPTY_ROWST){
        retPtr = FolderC.remove(TA_GRPFLDR, testAid0TxIX);
        
        if(TestAidC.putTestChars(CEAOK, retPtr, __LINE__) != 0){
            TestAidC.asserT(__FUNCTION__);
        }
    }
    
    
    retPtr = FolderC.makeFolder(TA_GRPFLDR, testAid0TxIX);
    if(TestAidC.putTestChars(CEAOK, retPtr, __LINE__) != 0){
        TestAidC.asserT(__FUNCTION__);
    }else{
        retPtr = FolderC.remove(TA_GRPFLDR, testAid0TxIX);
        
        if(TestAidC.putTestChars(CEAOK, retPtr, __LINE__) != 0){
            TestAidC.asserT(__FUNCTION__);
        }
    }
}

-(void) testGetExistsYes
{
    int tE = FolderC.exists(TA_HOMPATH, TA_GRPFLDR, testAid0TxIX);
    if(TestAidC.putTestInts(ACTIVE_ROWST, tE, __LINE__) != 0){
        TestAidC.asserT(__FUNCTION__);
    }
}


- (void)testZReportSuitStats
{
    TestAidC.processSuiteStats();
}

@end
