//
//  BufferShareZ0XCTests.m
//
//  Created by Robert R on 3/27/15.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
// os
#import <XCTest/XCTest.h>
// helper api's (contains HCapi and HIapi)
//#import "BufferShareO0.h"
//#import "PeopleGroupO0.h"
// data plans (contains HCdata and HIdata)
//#import "BufferShareZ0Plan.h" // included by BufferShareO0.h
//#import "ArchitectureZ0Plan.h" // included by BufferShareZ0Plan.h
// quality
#import "TestAidZ0.h"
#import "BufferShareZ0TestAid.h"

@interface BufferShareCreateDestroyO0Tests : XCTestCase
@end

@interface BufferShareZ0XCTests : XCTestCase
@end
@implementation BufferShareZ0XCTests


- (void)setUp {
    BufferShareO0QCapi.setupCreateDestroy(__LINE__);
}

- (void)tearDown {
}


/**
 * Example of use when processing a CSV:
 * - Caller creates a control using newBufferShare()
 * - loadHere is 10% down in the buffer to account for overlap
 *   and to indicate that a loaded file is being processed
 * - caller passes control to the loader method
 * - loader loads file (i.e, csv) into loadHere
 * - loader then
 * --- while(isMore())
 * --- calls readCurrent()
 * --- formats row data
 * --- calls writeCurrent()
 * -- calls nextPhase()
 * -- returns
 * - caller then can
 * -- while(isMore())
 * -- readCurrent()
 */
//static void
//loadAndProcessCSVsim(BufferShareZ0HIdataPT ctlP)
//{
//    Ulng maxLoadLen = ctlP->getSizeForLoad(ctlP);
//    char *simCSV = "a,b,c,d,e,f\n\rg,h,i,j,k,l\n\r";
//    if(strlen(simCSV) < maxLoadLen)
//    {
//        // This would probably be an open, read, close.
//        strcpy(ctlP->loadHere, simCSV);
//        // Process each cr/lf terminated CSV line into a Row-ready line.
//        while(ctlP->isMore(ctlP))
//        {
//            ctlP->readCurrent(ctlP);
//            // A real process would reformat this to Row ready
//            // but here we only recopy the value.
//            //printf("lap=%s\n", ctlP->currentRead);
//            ctlP->writeCurrent(ctlP, ctlP->currentRead);
//        }
//        ctlP->nextPhase(ctlP);
//    }
//    else
//    {
//        ctlP->sourceOnFailure = (char *)__FUNCTION__;
//        ctlP->lineOnFailure = __LINE__;
//    }
//}

- (void)test2015ExampleProcessCSV {
    if(BufferShareO0QCapi.isScheduled(__FUNCTION__, __LINE__)){
//        // Create a sharable buffer and a control to share it.
//        char sharedBuf[BS0_BFSZ];
//        BufferShareZ0HIdataT shareCtl =
//        BufferShareO0HCapi.new(sharedBuf,
//                        sharedBuf + sizeof(sharedBuf) - 1,
//                        &myTxSizeInteractiveInfo);
//        // Load the buffer with (simulated) CSV data
//        // then process it.
//        loadAndProcessCSVsim(&shareCtl);
//
//        while(shareCtl.isMore(&shareCtl))
//        {
//            shareCtl.readCurrent(&shareCtl);
//            //printf("%s\n", shareCtl.currentRead);
//        }
//
//        char descShare[BS0_DESC_SZ];
//        shareCtl.description(&shareCtl, descShare);
//
//        if(TA0C.putTestInts(0, shareCtl.lineOnFailure, __LINE__)                != 0 ||
//           TA0C.putTestChars("BufShr: lr=2, lw=2, pr=2", descShare, __LINE__)   != 0 ||
//           1 == 2)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:BufferShareO0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}


- (void)test2019ExampleProcessRow {
    if(BufferShareO0QCapi.isScheduled(__FUNCTION__, __LINE__)){
//        // Create a sharable buffer and a control to share it.
//        char sharedBuf[BS0_BFSZ];
//        BufferShare shareCtl =
//        newBufferShare(sharedBuf,
//                        sharedBuf + sizeof(sharedBuf) - 1,
//                        &myTxSizeInteractiveInfo);
//
//        shareCtl.nextPhase(&shareCtl);
//        char rowsBuf[] = "row1\0row2\0row3";
//        strcpy(shareCtl.bufBeg, rowsBuf);
//        shareCtl.currentWrite = shareCtl.bufBeg + sizeof(rowsBuf);
//
//        while(shareCtl.isMore(&shareCtl))
//        {
//            shareCtl.readCurrent(&shareCtl);
//            //printf("%s\n", shareCtl.currentRead);
//        }
//
//        if(TA0C.putTestChars(TA_NULL, shareCtl.sourceOnFailure, __LINE__) != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:BufferShareO0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}



- (void)test2019ANew {
    if(BufferShareO0QCapi.isScheduled(__FUNCTION__, __LINE__)){
//        // Create a sharable buffer and a control to share it.
//        char sharedBuf[BS0_BFSZ];
//        BufferShare shareCtl =
//        newBufferShare(sharedBuf,
//                        sharedBuf + sizeof(sharedBuf) - 1,
//                        &myTxSizeInteractiveInfo);
//
//        if(TA0C.putTestChars(TA_NULL, shareCtl.sourceOnFailure, __LINE__) != 0              ||
//           TA0C.putTestInts(0, shareCtl.lineOnFailure, __LINE__) != 0                       ||
//           TA0C.putTestInts(1800, (int)shareCtl.getSizeForLoad(&shareCtl),__LINE__) != 0    ||
//           1 == 2)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:BufferShareO0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}


- (void)test2019ASizes {
    if(BufferShareO0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        // Create a sharable buffer and a control to share it.
//        char sharedBuf[BS0_BFSZ];
//        BufferShare shareCtl =
//        newBufferShare(sharedBuf,
//                        sharedBuf + sizeof(sharedBuf) - 1,
//                        &myTxSizeInteractiveInfo);
//
//        char biggerBuf[1001];
//        shareCtl.description(&shareCtl, biggerBuf);
//        int szBuf = (int)strlen(biggerBuf);
//        int bufToDef = ((szBuf - BS0_DESC_SZ) < 50);
//        int defToBuf = ((BS0_DESC_SZ - szBuf) < 50);
//
//        if(TA0C.putTestInts(152, sizeof(BufferShare), __LINE__) != 0         ||
//           TA0C.putTestInts(1, bufToDef, __LINE__) != 0                       ||
//           TA0C.putTestInts(1, defToBuf, __LINE__) != 0                       ||
//           1 == 2)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:BufferShareO0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}



- (void)test2019AInBetween {
    if(BufferShareO0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        // Create a sharable buffer and a control to share it.
//        char sharedBuf[BS0_BFSZ];
//        BufferShare shareCtl =
//        newBufferShare(sharedBuf,
//                        sharedBuf + sizeof(sharedBuf) - 1,
//                        &myTxSizeInteractiveInfo);
//
//        if(TA0C.putTestInts(0, shareCtl.isMore(&shareCtl), __LINE__) != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:BufferShareO0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}

@end


@implementation BufferShareCreateDestroyO0Tests

- (void)setUp {
    BufferShareO0QCapi.setupCreateDestroy(__LINE__);
}

- (void)tearDown {
}
- (void)test2019Zdestroy {
    if(BufferShareO0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(BufferShareO0QCapi.doCreateDestroy(__LINE__))
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:BufferShareO0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}

@end
/**
 *
 */
