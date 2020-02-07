//
//  FoldersO4XCTests.m
//
//  Created by Robert Russell Millward on 10/16/13.
//  Copyright (c) 2020 Robert Russell Millward. All rights reserved.
//
// os
#import <XCTest/XCTest.h>
// helper api's
#import "BufferShareO0.h"
#import "CursorO0.h"
#import "ErrorHelperO0.h"
#import "FoldersO4.h"
#import "RowO0.h"
//#import "InitDestroyHelper1.h"
// data plans
#import "ArchitectureZ0Plan.h"
#import "CursorZ0Plan.h"
// quality
#import "TestAidZ0.h"

#define TA_HOMPATH "hp"
#define TA_GRPFLDR "gf"

@interface FoldersO4XCTests : XCTestCase

@end


@implementation FoldersO4XCTests


// The execution does this per test.

- (void)setUp
{
    //[super setUp];
    
    // Set-up code below here.

    TestAidC.basicInit();
    
}

- (void)tearDown
{
    TestAidC.getCounts();
    
    // Tear-down code above here.
    
    //[super tearDown];
}



#pragma mark - Tests


-(void) testGetFolderInfoThatExists
{
    gpSllgChar64PT gp64P = &TestAidZ0QCdata.gp64;
    char here[4096];
    BufferShareZ0dataT bufShr = BufferShareO0HCapi.new(here, here + sizeof(here) -1, gp64P);
    likePT like = "some*like";
    
    FolderO4HCapi.getInfo(TA_HOMPATH, TA_GRPFLDR, like, &bufShr, gp64P);
    CursorZ0HIdataT mFI = CursorO0HIapi.newData(bufShr.currentRead, gp64P);
    
    if(TestAidC.putTestInts(ACTIVE_ROWST, *mFI.rowStatus, __LINE__) != 0 ||
       TestAidC.putTestChars("folderInfo", mFI.itemName, __LINE__) != 0  ||
       1 == 2){
        //TestAidC.asserT(__FUNCTION__);
    }
}

-(void) testGetExistsNo
{
    gpSllgChar64PT gp64P = &TestAidZ0QCdata.gp64;
    char *retPtr = IDH_DO_HERE_INIT;
    BufferShareZ0dataT mgr = BufferShareO0HCapi.xxx();
    likePT like = "something";
    
    int tE = FolderO4HCapi.exists(TA_HOMPATH, TA_GRPFLDR, like, &mgr, gp64P);
    if(tE != EMPTY_ROWST){
        retPtr = FolderO4HCapi.remove(TA_GRPFLDR, gp64P);
        
        if(TestAidC.putTestChars(CEAOK, retPtr, __LINE__) != 0){
            //TestAidC.asserT(__FUNCTION__);
        }
    }
    
    
    retPtr = FolderO4HCapi.make(TA_GRPFLDR, gp64P);
    if(TestAidC.putTestChars(CEAOK, retPtr, __LINE__) != 0){
        //TestAidC.asserT(__FUNCTION__);
    }else{
        retPtr = FolderO4HCapi.remove(TA_GRPFLDR, gp64P);
        
        if(TestAidC.putTestChars(CEAOK, retPtr, __LINE__) != 0){
            //TestAidC.asserT(__FUNCTION__);
        }
    }
}

-(void) testGetExistsYes
{
    gpSllgChar64PT gp64P = &TestAidZ0QCdata.gp64;
    BufferShareZ0dataT mgr = BufferShareO0HCapi.xxx();
    likePT like = "something";
    int tE = FolderO4HCapi.exists(TA_HOMPATH, TA_GRPFLDR, like, &mgr, gp64P);
    // branchPT branch, peopleGroupIdT grpId, likePT like, BufferShareZ0dataPT mgr, gpSllgChar64PT gp64P
    if(TestAidC.putTestInts(ACTIVE_ROWST, tE, __LINE__) != 0){
        //TestAidC.asserT(__FUNCTION__);
    }
}


- (void)testZReportSuitStats
{
    //TestAidC.processSuiteStats();
}

@end // FoldersO4XCTests.m
/**
 *
 */
