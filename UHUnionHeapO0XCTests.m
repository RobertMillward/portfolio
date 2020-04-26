//
//  UHUnionHeapO0XCTests.m - Precious tests for version O level 0
//  2020May10Dev
//  2020Apr02Dev
//
//  Created by Robert R on 11/1/19.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
// os
#import <XCTest/XCTest.h>
// data plans
#import "ArchitectureZ0Plan.h"
// api's
// quality
#import "UHUnionHeapZ0TestAid.h"
#import "TestAidZ0.h"

#define MULT_FACTOR 5
static uhxElT myNMillionUnions[MYARRAYCT*MULT_FACTOR];
static uhxPassT masterMillionUnionsInfo;
static srtPassT srtPass = {0, 0, DEFAULT_COMPARE, 0};


@interface UHUnionHeapZ0OrdinaryTests : XCTestCase
@end


@interface UHUnionHeapZ0PerfIntRandTests : XCTestCase
@end
@interface UHUnionHeapO0UseMiscTests : XCTestCase
@end


@implementation UHUnionHeapZ0OrdinaryTests

- (void)setUp {
    UHUnionHeapZ0QCapi.setupSet1(__LINE__);
    // until moved in
    masterMillionUnionsInfo = UHUnionHeapO0QCapi.newUhxPassQ(myNMillionUnions,
                                                             sizeof(myNMillionUnions) / 1,
                                                             INT_DATATYPESM,
                                                             FILL_RANDOM,
                                                             __LINE__);
}

- (void)tearDown {
    UHUnionHeapZ0QCapi.teardownSet1(__LINE__);
}

#pragma mark - SAFETY

- (void)test2020SafeSize{
    if(UHUnionHeapZ0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(UHUnionHeapZ0QCapi.doSet1SizeSafe(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:UHUnionHeapZ0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}

- (void)test2020Basic{
    if(UHUnionHeapZ0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(UHUnionHeapZ0QCapi.doSet2Basics(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:UHUnionHeapZ0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}

- (void)test2020ExtraDemo{
    if(UHUnionHeapZ0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(UHUnionHeapZ0QCapi.doSet3ExtraDemo(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:UHUnionHeapZ0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}

- (void)test2020Performance{
    if(UHUnionHeapZ0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(UHUnionHeapZ0QCapi.doSet4Performance(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:UHUnionHeapZ0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}

#pragma mark - CLANGSORT

- (void)test2099SeqChkClangIntegers {
    
    if(UHUnionHeapZ0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        srtPass.uhxPassP = &masterMillionUnionsInfo;
        srtPass.passCount = srtPass.parentSwapCount = 0;
        srtPass.yourValuer = 0;
        
        UHUnionHeapO0QCapi.clangSort(&srtPass, __LINE__);
        
        if(srtPass.uhxPassP->heapCount >= SEQCHK_UNDER){
            UHUnionHeapO0QCapi.seqChk(&masterMillionUnionsInfo, __LINE__);
        }
    }
}

#pragma mark - OURSORT

- (void)test2099SeqChkOurSortIntegers {
    
    if(UHUnionHeapZ0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        srtPass.uhxPassP = &masterMillionUnionsInfo;
        srtPass.passCount = srtPass.parentSwapCount = 0;
        srtPass.yourValuer = 0;
        
        UHUnionHeapO0QCapi.ourSort(&srtPass, __LINE__);
        
        if(srtPass.uhxPassP->heapCount >= SEQCHK_UNDER){
            UHUnionHeapO0QCapi.seqChk(&masterMillionUnionsInfo, __LINE__);
        }
    }
}

#pragma mark - LOGSORT

- (void)test2099SeqChkLogSortIntegers {
    
    if(UHUnionHeapZ0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        srtPass.uhxPassP = &masterMillionUnionsInfo;
        srtPass.passCount = srtPass.parentSwapCount = 0;
        srtPass.yourValuer = 0;
        
        UHUnionHeapO0QCapi.logSort(&srtPass, __LINE__);
        if(srtPass.uhxPassP->heapCount >= SEQCHK_UNDER){
            UHUnionHeapO0QCapi.seqChk(&masterMillionUnionsInfo, __LINE__);
        }
    }
}

- (void)test9999SuiteStats{
}

@end // END O0 NonSpecial







#pragma mark - PERF (bigger and no sequence check)

@implementation UHUnionHeapZ0PerfIntRandTests
- (void)setUp {
    masterMillionUnionsInfo = UHUnionHeapO0QCapi.newUhxPassQ(myNMillionUnions,
                                                             sizeof(myNMillionUnions),
                                                             INT_DATATYPESM,
                                                             FILL_RANDOM,
                                                             __LINE__);
}

- (void)tearDown {
}


- (void)test2099CompareOurSortIntegers {
    srtPass.uhxPassP = &masterMillionUnionsInfo;
    srtPass.passCount = srtPass.parentSwapCount = 0;
    UHSortO0SCapi.ourSort(&srtPass);
}


- (void)test2099CompareClangSortIntegers {
    srtPass.uhxPassP = &masterMillionUnionsInfo;
    srtPass.passCount = srtPass.parentSwapCount = 0;
    UHSortO0SCapi.clangSort(&srtPass);
}

- (void)test2099CompareLogSortIntegers {
    srtPass.uhxPassP = &masterMillionUnionsInfo;
    srtPass.passCount = srtPass.parentSwapCount = 0;
    UHSortO0SCapi.logSort(&srtPass);
}


@end // performance (no sequence check)



@implementation UHUnionHeapO0UseMiscTests

- (void)setUp {
    masterMillionUnionsInfo =
        UHUnionHeapO0QCapi.newUhxPassQ(myNMillionUnions,
                                 sizeof(myNMillionUnions),
                                 INT_DATATYPESM,
                                 FILL_RANDOM,
                                 __LINE__);
}

- (void)tearDown {
}


#pragma mark - BTREE

- (void)test2001BtreeA
{
    if(UHUnionHeapZ0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        UHUnionHeapO0QCapi.btree(&masterMillionUnionsInfo, __LINE__);
        UHUnionHeapO0QCapi.seqChk(&masterMillionUnionsInfo, __LINE__);
    }
}

#pragma mark - BRUTE

//- (void)test2099BruteA {
//    srtPass.uhxPassP = &masterMillionUnionsInfo;
//    srtPass.passCount = srtPass.parentSwapCount = 0;
//    UHUnionHeapO0QCapi.bruteSort(&srtPass, __LINE__);
//    UHUnionHeapO0QCapi.seqChk(&masterMillionUnionsInfo, __LINE__);
//}

#pragma mark - SLOSH


- (void)test2001SloshA
{
    if(UHUnionHeapZ0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        UHUnionHeapO0QCapi.slosh(&masterMillionUnionsInfo, __LINE__);
        UHUnionHeapO0QCapi.seqChk(&masterMillionUnionsInfo, __LINE__);
    }
}

@end



// END UHUnionHeapO0XCTests.m
/**
 *
 */
