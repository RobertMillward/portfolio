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


#define MYARRAYCT       1000000
#define MYBIGODD_HEAPCT  999997 // To test the left edge of the third row
#define MYSMALL_HEAPCT      900 // To keep the test small
#define MYTINY_HEAPCT        16
static uhxElT myMillionUnions[MYARRAYCT];

static uhxPassT masterMillionUnionsInfo;

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
    UHUnionHeapO0QIapi.bruteSort(&masterMillionUnionsInfo, __LINE__);
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
    //[super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    //[super tearDown];
}

- (void)test2099SizeUnionHeap {
    
    ErrorWarnCountT ewc = UHUnionHeapO0QIapi.sizeCheck(__LINE__);
    
    if(ewc.classErrors > 0)
    {
        XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidQCapi.getAssertText(__FUNCTION__)]);
    }
}


@end

#pragma SAFE

/**
 * S A F E
 * F L T
 */
@interface UHUnionHeapO0SafetyRandomFloatTests : XCTestCase

@end

@implementation UHUnionHeapO0SafetyRandomFloatTests

- (void)setUp {
    //[super setUp];
    masterMillionUnionsInfo = UHUnionHeapO0QIapi.newUhxPassT(myMillionUnions, (MYTINY_HEAPCT*sizeof(myMillionUnions[0])), FLT_DATATYPESM, FILL_RANDOM, __LINE__);
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    //[super tearDown];
}

- (void)test2099SafeFloats {
    UHUnionHeapO0QIapi.seqChk(&masterMillionUnionsInfo, __LINE__);
    
    UHUnionHeapO0QIapi.ourSort(&masterMillionUnionsInfo, __LINE__);
    
    UHUnionHeapO0QIapi.seqChk(&masterMillionUnionsInfo, __LINE__);
}

- (void)test2099SafeFloatsZOTX { // ZOTX = zero, one, two, too many
    
    masterMillionUnionsInfo.heapCount = 0;
    UHUnionHeapO0QIapi.ourSort(&masterMillionUnionsInfo, __LINE__);
    
    masterMillionUnionsInfo.heapCount = 1;
    UHUnionHeapO0QIapi.ourSort(&masterMillionUnionsInfo, __LINE__);
    
    masterMillionUnionsInfo.heapCount = 2;
    UHUnionHeapO0QIapi.ourSort(&masterMillionUnionsInfo, __LINE__);
    
    masterMillionUnionsInfo.heapCount = MAX_SORTHEAP+1;
    UHUnionHeapO0QIapi.ourSort(&masterMillionUnionsInfo, __LINE__);
}


@end

/**
 * S A F E
 * I N T
 */
@interface UHUnionHeapO0SafetyIntegerTests : XCTestCase

@end

@implementation UHUnionHeapO0SafetyIntegerTests



- (void)setUp {

    masterMillionUnionsInfo = UHUnionHeapO0QIapi.newUhxPassT(myMillionUnions, (MYTINY_HEAPCT*sizeof(myMillionUnions[0])), INT_DATATYPESM, FILL_DESCENDING, __LINE__);
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.

}

- (void)test2099SafeIntegers {
    UHUnionHeapO0QIapi.seqChk(&masterMillionUnionsInfo, __LINE__);
    
    UHUnionHeapO0QIapi.ourSort(&masterMillionUnionsInfo, __LINE__);
    
    UHUnionHeapO0QIapi.seqChk(&masterMillionUnionsInfo, __LINE__);
}

- (void)test2099SafeIntegersZOTX {
    
    masterMillionUnionsInfo.heapCount = 0;
    UHUnionHeapO0QIapi.ourSort(&masterMillionUnionsInfo, __LINE__);
    
    masterMillionUnionsInfo.heapCount = 1;
    UHUnionHeapO0QIapi.ourSort(&masterMillionUnionsInfo, __LINE__);
    
    masterMillionUnionsInfo.heapCount = 2;
    UHUnionHeapO0QIapi.ourSort(&masterMillionUnionsInfo, __LINE__);
    
    masterMillionUnionsInfo.heapCount = MAX_SORTHEAP+1;
    UHUnionHeapO0QIapi.ourSort(&masterMillionUnionsInfo, __LINE__);
}


@end




/**
 *
 */
@interface UHUnionHeapO0UseTests : XCTestCase

@end

@implementation UHUnionHeapO0UseTests

- (void)setUp {
    //[super setUp];
    masterMillionUnionsInfo = UHUnionHeapO0QIapi.newUhxPassT(myMillionUnions, sizeof(myMillionUnions), INT_DATATYPESM, FILL_RANDOM, __LINE__);
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    //[super tearDown];
}

- (void)test2099SortSeqChkIntegers {
    
    masterMillionUnionsInfo.heapCount = MYBIGODD_HEAPCT;
    UHUnionHeapO0QIapi.seqChk(&masterMillionUnionsInfo, __LINE__);
    
    UHUnionHeapO0QIapi.ourSort(&masterMillionUnionsInfo, __LINE__);
    
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
    
    UHUnionHeapO0QIapi.ourSort(&masterMillionUnionsInfo, __LINE__);
}


- (void)test2099CompareClangIntegers {
    
    UHUnionHeapO0QIapi.clangSort(&masterMillionUnionsInfo, __LINE__);
}

/**
 * A big sort with sequence checks before and after
 */
- (void)test2099SeqChkSortIntegers {
    
    UHUnionHeapO0QIapi.seqChk(&masterMillionUnionsInfo, __LINE__);
    
    UHUnionHeapO0QIapi.ourSort(&masterMillionUnionsInfo, __LINE__);
    
    UHUnionHeapO0QIapi.seqChk(&masterMillionUnionsInfo, __LINE__);
}


- (void)test2099SeqChkClangIntegers {
    
    UHUnionHeapO0QIapi.seqChk(&masterMillionUnionsInfo, __LINE__);
    
    UHUnionHeapO0QIapi.clangSort(&masterMillionUnionsInfo, __LINE__);
    
    UHUnionHeapO0QIapi.seqChk(&masterMillionUnionsInfo, __LINE__);
}

@end

// END UHUnionHeapO0Tests.m
