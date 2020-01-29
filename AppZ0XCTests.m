//
//  AppO0XCTests.m
//
//  Created by Robert R on 3/27/15.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
// os
#import <XCTest/XCTest.h>
// data plans
#import "ArchitectureZ0Plan.h"
// api's
#import "AppO0.h"
#import "PeopleGroupO0.h"
//#import "InitDestroyHelperO0.h"
//#import "SignatureFactoryO0.h"
//#import "CommaSepO3.h"
//#import "UnixStreamO0.h"
//#import "RowO0.h"
//#import "HashBasicsO0.h"
// quality
#import "TestAidZ0.h"

@interface AppO0Tests : XCTestCase

@end

@implementation AppO0Tests

//static bool showFunctionName = false;


- (void)setUp {
    //initSignatureFactoryO0(&TestAidO0QCre.infoTwoWay);
}

- (void)tearDown {
    //TestAidC.getCounts();
    //InitDestroyerHelperC.destroyAll(&TestAidO0QCre.infoTwoWay);
}





//void doReport(nkBufferPT yourFirstElementP, int stepNumber)
//{
//    stepNumber = 0;
//}

//void setUpReport(nkBufferPT yourFirstElementP, int stepNumber)
//{
//    stepNumber++;
//    switch(stepNumber)
//    {
//        case 0: BufferBuildersC.get500k(yourFirstElementP,  stepNumber); break;
//        case 1: BufferBuildersC.get4k(yourFirstElementP,    stepNumber); break;
//        case 2: BufferBuildersC.get100k(yourFirstElementP,  stepNumber); break;
//        case 3: BufferBuildersC.get20k(yourFirstElementP,   stepNumber); break;
//    }
//}

//- (void)test2019ZdoBuffer {
//    if(TA0C.isScheduled(__FUNCTION__, showFunctionName)){
//        // Create a buffer builder[] .
//        nkBufferT myBuffers[4];
//        for(int Ix = 0; Ix < 4; Ix++)
//        {
//            myBuffers[Ix].thenCall = setUpReport;
//            myBuffers[Ix].where = 0;
//        }
//        myBuffers[3].thenCall = doReport;
//        setUpReport(&myBuffers[0], -1);
//
//        if(TA0C.putTestInts(0, (int)myBuffers[0].where, __LINE__) != 0          ||
//           TA0C.putTestInts(0, (int)myBuffers[0].where, __LINE__) != 0          ||
//           TA0C.putTestInts(0, (int)myBuffers[0].where, __LINE__) != 0          ||
//           TA0C.putTestInts(0, (int)myBuffers[0].where, __LINE__) != 0          ||
//           TA0C.putTestInts(500*1024, (int)myBuffers[0].size, __LINE__) != 0    ||
//           TA0C.putTestInts(  4*1024, (int)myBuffers[1].size, __LINE__) != 0    ||
//           TA0C.putTestInts(100*1024, (int)myBuffers[2].size, __LINE__) != 0    ||
//           TA0C.putTestInts( 20*1024, (int)myBuffers[3].size, __LINE__) != 0    ||
//              1 == 2)
//        {
//            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
//        }
//    }
//}


/*
 typedef struct UnixStreamO0Y
 {
 FILE* (*open)(char *fullPath, char* X_UXSTRM);
 Ulng (*write)(char* data, size_t itemSize, size_t itemCount, FILE* stream);
 Sint (*flush)(FILE* stream);
 Sint (*getc)(FILE* stream);
 Sint (*ungetc)(int gotc, FILE* stream);
 Sint (*isEOF)(FILE* stream);
 Slng (*tell)(FILE* stream);
 Ulng (*read)(char* data, size_t itemSize, size_t itemCount, FILE* stream);
 char* (*getLine)(char* data, int size, FILE* stream);
 Sint (*close)(FILE* stream);
 Slng (*isError)(FILE* stream);
 void (*clearError)(FILE* stream);
 }UnixStreamO0XT, *UnixStreamO0XPT;
 */

//- (void)test2019ZdoUnix {
//    if(TA0C.isScheduled(__FUNCTION__, showFunctionName))
//    {
//        int rowCount = 0;
//        CommaSepsInitC.initPath(COMMASEP_PATH, &TestAidO0QCre.infoTwoWay);
//        /*initStatusT status = */initCommaSeps(&TestAidO0QCre.infoTwoWay);
//        TestAidO0QCre.infoTwoWay.peopleGroupP = "HEXASFT";
//        CommaSepIT myCommaSep = newCommaSep(&TestAidO0QCre.infoTwoWay);
//        myCommaSep.go->openRead("IP2LOCATION-LITE-DB11", &myCommaSep.to);
//#define NAMESPACE 400
//        nameSigT theSelected[NAMESPACE];
//        char theValues[NAMESPACE][40];
//        int theCounter = 0;
//        int the8100ints[8100];
//
//        for(int theIx = 0; theIx < 8100; theIx++)
//        {
//            the8100ints[theIx] = -1;
//        }
//        for(int theIx = 0; theIx < NAMESPACE; theIx++)
//        {
//            theSelected[theIx].name = theValues[theIx];
//            theSelected[theIx].signature[0] = 0;
//            theSelected[theIx].newCount = 0;
//            theSelected[theIx].otherCount = 0;
//            theSelected[theIx].versionLevel.callerSeesLevel = 'O';
//            theSelected[theIx].versionLevel.callerSeesVersion = '3';
//
//            strcpy(theValues[theIx], "not set");
//        }
//
//
//        char here[2000];
//        //char there[2000];
//#define IPFR_IP2 "a"
//#define IPTO_IP2 "b"
//#define CTCD_IP2 "c"
//#define CTRY_IP2 "d"
//#define STAT_IP2 "e"
//#define CITY_IP2 "f"
//#define LATV_IP2 "g"
//#define LONG_IP2 "h"
//#define ZIPX_IP2 "i"
//#define TMZN_IP2 "j"
//        while(!myCommaSep.go->isAtEof(&myCommaSep.to) )
//        {
//            myCommaSep.go->read(sizeof(here), here, &myCommaSep.to);
//            char seeIt[3000];
//            strcpy(seeIt, here);
//            RowIT aRow = newRow(here, 2);
//            char *myField = aRow.O0->getField(&aRow.dataO0, CTRY_IP2);
//            if(myField)
//            {
//                if(strcmp(myField, "-") == 0 || strcmp(myField, "") == 0)
//                {
//                    continue;
//                }
//                Ssht tryHash8100 = HashBasicsC.get8100HashForItemName(myField);
//                int g1 = the8100ints[tryHash8100];
//                char* g2 = theSelected[g1].name;
//                while(the8100ints[tryHash8100] != -1 && strcmp(theSelected[the8100ints[tryHash8100]].name, myField) != 0)
//                {
//                    tryHash8100++;
//                }
//                if(the8100ints[tryHash8100] == -1)
//                {
//                    the8100ints[tryHash8100] = theCounter;
//                    strcpy(theSelected[theCounter].name, myField);
//                    theCounter++;
//                }
//            }
//            rowCount++;
//            if(rowCount > 20275)
//            {
//                myField = 0; // just to catch the bad ones
//            }
//        }
//        here[1999] = 0;
//    }
//}


//- (void)test2099ZULUAppHelpO0NewDestroy {
//    if(TestAidC.isScheduled(__FUNCTION__, showFunctionName)){
//        char* report = InitDestroyerHelperC.getReport();
//        
//        // Before destroyAll().
//        if(report[0] != 0)
//        {
//            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:InitDestroyerHelperC.getReport()]);
//            report[0] = 0;
//        }
//        
//        // After destroyAll().
//        InitDestroyerHelperC.destroyAll(&TestAidO0QCre.infoTwoWay);
//        if(report[0] != 0)
//        {
//            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:InitDestroyerHelperC.getReport()]);
//        }
//    }
//}

@end
/**
 *
 */
