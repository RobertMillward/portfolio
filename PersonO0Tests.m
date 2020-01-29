//
//  PersonO0Tests.m
//
//  Created by Robert R on 3/5/19.
//  Copyright (c) 2015 Robert Russell Millward.
//  All rights reserved.
//

#import <XCTest/XCTest.h>
#import "ArchitectureO0.h"
#import "PeopleGroupO0.h"
#import "TestAidO0.h"
#import "InitDestroyHelperO0.h"
#import "PersonO0.h"
#import "PersonO0TestAid.h"
#import "GeneralRowsO0.h"
#import "GeneralRowHdrsO0.h"
//#import "QueingO0.h"
//#import "SignatureFactoryO0.h"
//#import "AppHelperO0.h"
//#import "CommaSepO3.h"
//#import "UnixStreamO0.h"
//#import "RowO0.h"
//#import "HashBasicsO0.h"

#undef  PSNHDR_TESTSPACE
#define PSNHDR_TESTSPACE 2400
#undef  PSNROW_TESTSPACE
#define PSNROW_TESTSPACE 16800
#undef  PSNCEL_TESTSPACE
#define PSNCEL_TESTSPACE 82000

@interface PersonO0NewTests : XCTestCase

@end

@implementation PersonO0NewTests


- (void)setUp {
    TestAidQCapi.basicInit(); // this gets signature
    
    GeneralRowHdrsO0ACapi.preInitClassZoneCounts(100);
    GeneralRowsO0ACapi.preInitClassZoneCounts(200, 100, 100, 100);
    GeneralCellsO0ACapi.preInitClassZoneCounts(1000, 500, 250, 125);
    /*
    Ulng hdrSpaceReq = GeneralRowHdrsO0ACapi.getClassZoneSpaceRequirement();
    Ulng rowSpaceReq = GeneralRowsO0ACapi.getClassZoneSpaceRequirement();
    Ulng celSpaceReq = GeneralCellsO0ACapi.getClassZoneSpaceRequirement();
     */
}

- (void)tearDown {
}


- (void)test2099PersonO0NewRandom
{
    char psnHdrTestSpace[PSNHDR_TESTSPACE];
    char psnRowTestSpace[PSNROW_TESTSPACE];
    char psnCellTestSpace[PSNCEL_TESTSPACE];
    
    GeneralRowHdrsO0ACapi.buildClassZoneDatabase((gh1PT)psnHdrTestSpace);
    GeneralRowsO0ACapi.buildClassZoneDatabase((gr0PT)psnRowTestSpace);
    GeneralCellsO0ACapi.buildClassZoneDatabase((gc00PT)psnCellTestSpace);
    initGeneralRowHdrsO0(&TestAidO0QCdata.twoWay);
    
    char* report = "";
    
    PsnAidQIdataT theQdata;
    char* result = newExpectAndPersonO0In(__LINE__, &theQdata);
    
    InitDestroyerHelperC.destroyAll(&TestAidO0QCdata.twoWay);
    
    if((report = InitDestroyerHelperC.getReport()) && report[0] != 0)
    {
        XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:InitDestroyerHelperC.getReport()]);
    }
    
}
@end



@interface PersonO0ReviseTests : XCTestCase

@end

@implementation PersonO0ReviseTests

- (void)setUp {
    TestAidQCapi.basicInit();
    
    GeneralRowHdrsO0ACapi.preInitClassZoneCounts(100);
    GeneralRowsO0ACapi.preInitClassZoneCounts(200, 100, 100, 100);
    GeneralCellsO0ACapi.preInitClassZoneCounts(1000, 500, 250, 125);
}

- (void)tearDown {
}


- (void)test2099PersonO0RevisionOk
{
    char psnHdrTestSpace[PSNHDR_TESTSPACE];
    char psnRowTestSpace[PSNROW_TESTSPACE];
    char psnCellTestSpace[PSNCEL_TESTSPACE];
    
    GeneralRowHdrsO0ACapi.buildClassZoneDatabase((gh1PT)psnHdrTestSpace);
    GeneralRowsO0ACapi.buildClassZoneDatabase((gr0PT)psnRowTestSpace);
    GeneralCellsO0ACapi.buildClassZoneDatabase((gc00PT)psnCellTestSpace);
    initGeneralRowHdrsO0(&TestAidO0QCdata.twoWay);
    
    char* report = "";
    gdbIsRevisedT gdbIsRevised = true;
    PsnAidQIdataT theQdata;
    
    gc48T famNameCell;
    familyNameCellPT famNameCellP = &famNameCell;
    
    char* result = newExpectAndPersonO0In(__LINE__, &theQdata);
    
    char* badRevision = "This string is far to long to be accepted as a revision";
    //TestAidO0QCdata.twoWay.twoWayStatusP = DONT_KNOW_ARC;
    PsnAidQIapi.setGetEmailForTest(badRevision, __LINE__, &theQdata, famNameCellP, gdbIsRevised);
    char* goodRevision = "Johnsen";
    strcpy(theQdata.qfamilyName, goodRevision);
    PsnAidQIapi.setGetFamilyNameForTest(goodRevision, __LINE__, &theQdata, famNameCellP, gdbIsRevised);
    
    InitDestroyerHelperC.destroyAll(&TestAidO0QCdata.twoWay);
    
    if((report = InitDestroyerHelperC.getReport()) && report[0] != 0)
    {
        XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:InitDestroyerHelperC.getReport()]);
    }
}
@end



@interface PersonO0ReviseBadTests : XCTestCase

@end

@implementation PersonO0ReviseBadTests


- (void)setUp {
    TestAidQCapi.basicInit();
    
    GeneralRowHdrsO0ACapi.preInitClassZoneCounts(100);
    GeneralRowsO0ACapi.preInitClassZoneCounts(200, 100, 100, 100);
    GeneralCellsO0ACapi.preInitClassZoneCounts(1000, 500, 250, 125);
}

- (void)tearDown {
}

- (void)test2099PersonO0RevisionOk
{
    char psnHdrTestSpace[PSNHDR_TESTSPACE];
    char psnRowTestSpace[PSNROW_TESTSPACE];
    char psnCellTestSpace[PSNCEL_TESTSPACE];
    
    GeneralRowHdrsO0ACapi.buildClassZoneDatabase((gh1PT)psnHdrTestSpace);
    GeneralRowsO0ACapi.buildClassZoneDatabase((gr0PT)psnRowTestSpace);
    GeneralCellsO0ACapi.buildClassZoneDatabase((gc00PT)psnCellTestSpace);
    initGeneralRowHdrsO0(&TestAidO0QCdata.twoWay);
    
    char* report = "";
    char* testStatus = "";
    
    PsnAidQIdataT theQdata;
    bool isMoreCanDo = true;
    int doCount = 0;
    while(isMoreCanDo)
    {
        doCount++;
        switch(doCount)
        {
            default:
                isMoreCanDo = false;
                break;
            case 1:
                testStatus = newExpectAndPersonO0In(__LINE__, &theQdata);
                break;
        }
    }
    
    
    

    
    InitDestroyerHelperC.destroyAll(&TestAidO0QCdata.twoWay);
    
    if((report = InitDestroyerHelperC.getReport()) && report[0] != 0)
    {
        XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:InitDestroyerHelperC.getReport()]);
    }
}

@end
