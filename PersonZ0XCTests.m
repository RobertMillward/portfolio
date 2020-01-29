//
//  PersonZ0Tests.m - the General version
//
//  Created by Robert R on 3/5/19.
//  Copyright (c) 2015 Robert Russell Millward.
//  All rights reserved.
//

#import <XCTest/XCTest.h>
#import "ArchitectureZ0.h"
#import "PeopleGroupZ0.h"
#import "TestAidZ0.h"
#import "InitDestroyHelperZ0.h"
#import "PersonZ0.h"
#import "PersonZ0TestAid.h"
#import "GeneralRowsZ0.h"
#import "GeneralRowHdrsZ0.h"
//#import "QueingZ0.h"
//#import "SignatureFactoryZ0.h"
//#import "AppHelperZ0.h"
//#import "CommaSepO3.h"
//#import "UnixStreamZ0.h"
//#import "RowZ0.h"
//#import "HashBasicsZ0.h"

#undef  PSNHDR_TESTSPACE
#define PSNHDR_TESTSPACE 2400
#undef  PSNROW_TESTSPACE
#define PSNROW_TESTSPACE 16800
#undef  PSNCEL_TESTSPACE
#define PSNCEL_TESTSPACE 82000

@interface PersonZ0NewTests : XCTestCase

@end

@implementation PersonZ0NewTests


- (void)setUp {
    TestAidQCapi.basicInit(); // this gets signature
    
    GeneralRowHdrsZ0ACapi.preInitClassZoneCounts(100);
    GeneralRowsZ0ACapi.preInitClassZoneCounts(200, 100, 100, 100);
    GeneralCellsZ0ACapi.preInitClassZoneCounts(1000, 500, 250, 125);
    /*
    Ulng hdrSpaceReq = GeneralRowHdrsZ0ACapi.getClassZoneSpaceRequirement();
    Ulng rowSpaceReq = GeneralRowsZ0ACapi.getClassZoneSpaceRequirement();
    Ulng celSpaceReq = GeneralCellsZ0ACapi.getClassZoneSpaceRequirement();
     */
}

- (void)tearDown {
}


- (void)test2099PersonZ0NewRandom
{
    char psnHdrTestSpace[PSNHDR_TESTSPACE];
    char psnRowTestSpace[PSNROW_TESTSPACE];
    char psnCellTestSpace[PSNCEL_TESTSPACE];
    
    GeneralRowHdrsZ0ACapi.buildClassZoneDatabase((gh1PT)psnHdrTestSpace);
    GeneralRowsZ0ACapi.buildClassZoneDatabase((gr0PT)psnRowTestSpace);
    GeneralCellsZ0ACapi.buildClassZoneDatabase((gc00PT)psnCellTestSpace);
    initGeneralRowHdrsZ0(&TestAidZ0QCdata.twoWay);
    
    char* report = "";
    
    PsnAidQIdataT theQdata;
    char* result = newExpectAndPersonZ0In(__LINE__, &theQdata);
    
    InitDestroyerHelperC.destroyAll(&TestAidZ0QCdata.twoWay);
    
    if((report = InitDestroyerHelperC.getReport()) && report[0] != 0)
    {
        XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:InitDestroyerHelperC.getReport()]);
    }
    
}
@end



@interface PersonZ0ReviseTests : XCTestCase

@end

@implementation PersonZ0ReviseTests

- (void)setUp {
    TestAidQCapi.basicInit();
    
    GeneralRowHdrsZ0ACapi.preInitClassZoneCounts(100);
    GeneralRowsZ0ACapi.preInitClassZoneCounts(200, 100, 100, 100);
    GeneralCellsZ0ACapi.preInitClassZoneCounts(1000, 500, 250, 125);
}

- (void)tearDown {
}


- (void)test2099PersonZ0RevisionOk
{
    char psnHdrTestSpace[PSNHDR_TESTSPACE];
    char psnRowTestSpace[PSNROW_TESTSPACE];
    char psnCellTestSpace[PSNCEL_TESTSPACE];
    
    GeneralRowHdrsZ0ACapi.buildClassZoneDatabase((gh1PT)psnHdrTestSpace);
    GeneralRowsZ0ACapi.buildClassZoneDatabase((gr0PT)psnRowTestSpace);
    GeneralCellsZ0ACapi.buildClassZoneDatabase((gc00PT)psnCellTestSpace);
    initGeneralRowHdrsZ0(&TestAidZ0QCdata.twoWay);
    
    char* report = "";
    gdbIsRevisedT gdbIsRevised = true;
    PsnAidQIdataT theQdata;
    
    gc48T famNameCell;
    familyNameCellPT famNameCellP = &famNameCell;
    
    char* result = newExpectAndPersonZ0In(__LINE__, &theQdata);
    
    char* badRevision = "This string is far to long to be accepted as a revision";
    //TestAidZ0QCdata.twoWay.twoWayStatusP = DONT_KNOW_ARC;
    PsnAidQIapi.setGetEmailForTest(badRevision, __LINE__, &theQdata, famNameCellP, gdbIsRevised);
    char* goodRevision = "Johnsen";
    strcpy(theQdata.qfamilyName, goodRevision);
    PsnAidQIapi.setGetFamilyNameForTest(goodRevision, __LINE__, &theQdata, famNameCellP, gdbIsRevised);
    
    InitDestroyerHelperC.destroyAll(&TestAidZ0QCdata.twoWay);
    
    if((report = InitDestroyerHelperC.getReport()) && report[0] != 0)
    {
        XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:InitDestroyerHelperC.getReport()]);
    }
}
@end



@interface PersonZ0ReviseBadTests : XCTestCase

@end

@implementation PersonZ0ReviseBadTests


- (void)setUp {
    TestAidQCapi.basicInit();
    
    GeneralRowHdrsZ0ACapi.preInitClassZoneCounts(100);
    GeneralRowsZ0ACapi.preInitClassZoneCounts(200, 100, 100, 100);
    GeneralCellsZ0ACapi.preInitClassZoneCounts(1000, 500, 250, 125);
}

- (void)tearDown {
}

- (void)test2099PersonZ0RevisionOk
{
    char psnHdrTestSpace[PSNHDR_TESTSPACE];
    char psnRowTestSpace[PSNROW_TESTSPACE];
    char psnCellTestSpace[PSNCEL_TESTSPACE];
    
    GeneralRowHdrsZ0ACapi.buildClassZoneDatabase((gh1PT)psnHdrTestSpace);
    GeneralRowsZ0ACapi.buildClassZoneDatabase((gr0PT)psnRowTestSpace);
    GeneralCellsZ0ACapi.buildClassZoneDatabase((gc00PT)psnCellTestSpace);
    initGeneralRowHdrsZ0(&TestAidZ0QCdata.twoWay);
    
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
                testStatus = newExpectAndPersonZ0In(__LINE__, &theQdata);
                break;
        }
    }
    
    
    

    
    InitDestroyerHelperC.destroyAll(&TestAidZ0QCdata.twoWay);
    
    if((report = InitDestroyerHelperC.getReport()) && report[0] != 0)
    {
        XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:InitDestroyerHelperC.getReport()]);
    }
}

@end
