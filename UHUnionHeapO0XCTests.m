//
//  UHUnionHeapO0Tests.m - tests for version Z level 0
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



static uhxElT myMillionUnions[MYARRAYCT];
static uhxPassT masterMillionUnionsInfo;
static srtPassT srtPass;

#pragma mark - USE
/**
 *
 */
@interface UHUnionHeapO0SloshUseTests : XCTestCase

@end

@implementation UHUnionHeapO0SloshUseTests


- (void)setUp {
    masterMillionUnionsInfo =
        UHUnionHeapO0QIapi.newUhxPassT(myMillionUnions,
                                 sizeof(myMillionUnions),
                                 INT_DATATYPESM,
                                 FILL_RANDOM,
                                 __LINE__);
}

- (void)tearDown {
}

- (void)test2099SloshA {
    UHUnionHeapO0QIapi.slosh(&masterMillionUnionsInfo, __LINE__);
    UHUnionHeapO0QIapi.seqChk(&masterMillionUnionsInfo, __LINE__);
}

- (void)test2099BtreeA {
    UHUnionHeapO0QIapi.btree(&masterMillionUnionsInfo, __LINE__);
}

@end

/**
 *
 */
@interface UHUnionHeapO0BruteUseTests : XCTestCase

@end

@implementation UHUnionHeapO0BruteUseTests


- (void)setUp {
    masterMillionUnionsInfo =
        UHUnionHeapO0QIapi.newUhxPassT(myMillionUnions,
                                 sizeof(myMillionUnions),
                                 INT_DATATYPESM,
                                 FILL_RANDOM,
                                 __LINE__);
}

- (void)tearDown {
}

- (void)test2099BruteA {
    srtPass.uhxPassP = &masterMillionUnionsInfo;
    srtPass.passCount = 0;
    UHUnionHeapO0QIapi.bruteSort(&srtPass, __LINE__);
    UHUnionHeapO0QIapi.seqChk(&masterMillionUnionsInfo, __LINE__);
}

@end

#pragma SIZE

/**
 * S I Z E
 */
@interface UHUnionHeapO0SizeTests : XCTestCase

@end

@implementation UHUnionHeapO0SizeTests

- (void)setUp {
}

- (void)tearDown {
}

- (void)test2099SizeUnionHeap {
    
    ErrorWarnCountT ewc = UHUnionHeapO0QIapi.sizeChecks(__LINE__);
    
    if(ewc.classErrors > 0)
    {
        XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidQCapi.getAssertText(__FUNCTION__)]);
    }
}


@end

#pragma SAFE

/**
 * S A F E
 */
@interface UHUnionHeapO0SafetyTests : XCTestCase

@end

@implementation UHUnionHeapO0SafetyTests

- (void)setUp {
}

- (void)tearDown {
}

- (void)test2099Safe {
    
    ErrorWarnCountT ewc = UHUnionHeapO0QIapi.safetyChecks012n(__LINE__);
    
    if(ewc.classErrors > 0)
    {
        XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidQCapi.getAssertText(__FUNCTION__)]);
    }
}

@end


/**
 *
 */
@interface UHUnionHeapO0UseTests : XCTestCase

@end

@implementation UHUnionHeapO0UseTests

- (void)setUp {
    masterMillionUnionsInfo =
        UHUnionHeapO0QIapi.newUhxPassT(myMillionUnions, sizeof(myMillionUnions), INT_DATATYPESM, FILL_RANDOM, __LINE__);
}

- (void)tearDown {
}

- (void)test2099SortSeqChkIntegers {
    
    masterMillionUnionsInfo.heapCount = MYBIGODD_HEAPCT;
    srtPass.uhxPassP = &masterMillionUnionsInfo;
    srtPass.passCount = 0;
    UHUnionHeapO0QIapi.seqChk(&masterMillionUnionsInfo, __LINE__);
    
    UHUnionHeapO0QIapi.ourSort(&srtPass, __LINE__);
    
    UHUnionHeapO0QIapi.seqChk(&masterMillionUnionsInfo, __LINE__);
}


@end

#pragma PERF
/**
 *
 */
@interface SortZ0PerfIntRandTests : XCTestCase

@end


@implementation SortZ0PerfIntRandTests

- (void)setUp {

    masterMillionUnionsInfo = UHUnionHeapO0QIapi.newUhxPassT(myMillionUnions,
                                                             sizeof(myMillionUnions),
                                                             INT_DATATYPESM,
                                                             FILL_RANDOM,
                                                             __LINE__);
    
    masterMillionUnionsInfo.heapCount = MYBIGODD_HEAPCT;
}

- (void)tearDown {
    
}


- (void)test2099CompareSortIntegers {
    srtPass.uhxPassP = &masterMillionUnionsInfo;
    srtPass.passCount = 0;
    UHUnionHeapO0QIapi.ourSort(&srtPass, __LINE__);
}


- (void)test2099CompareClangIntegers {
    srtPass.uhxPassP = &masterMillionUnionsInfo;
    srtPass.passCount = 0;
    UHUnionHeapO0QIapi.clangSort(&srtPass, __LINE__);
}

/**
 * A big sort with sequence checks before and after
 */
- (void)test2099SeqChkSortIntegers {
    
    UHUnionHeapO0QIapi.seqChk(&masterMillionUnionsInfo, __LINE__);
    srtPass.uhxPassP = &masterMillionUnionsInfo;
    srtPass.passCount = 0;
    UHUnionHeapO0QIapi.ourSort(&srtPass, __LINE__);
    
    UHUnionHeapO0QIapi.seqChk(&masterMillionUnionsInfo, __LINE__);
}


- (void)test2099SeqChkClangIntegers {
    
    UHUnionHeapO0QIapi.seqChk(&masterMillionUnionsInfo, __LINE__);
    srtPass.uhxPassP = &masterMillionUnionsInfo;
    srtPass.passCount = 0;
    UHUnionHeapO0QIapi.clangSort(&srtPass, __LINE__);
    
    UHUnionHeapO0QIapi.seqChk(&masterMillionUnionsInfo, __LINE__);
}

@end

// END UHUnionHeapO0Tests.m
