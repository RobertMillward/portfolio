//
//  UHUnionHeapO0XCTests.m - Precious tests for version O level 0
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

static uhxElT myMillionUnions[MYARRAYCT];
static uhxPassT masterMillionUnionsInfo;
static srtPassT srtPass;



#pragma mark - SAFETY

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
/**
* This includes about 20 tests for safety.
*/
- (void)test2099Safe {
    
    ErrorWarnCountT ewc = UHUnionHeapO0QCapi.safetyChecks012n(__LINE__);
    
    if(ewc.classErrors > 0)
    {
        XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidQCapi.getAssertText(__FUNCTION__)]);
    }
}

@end



#pragma mark - SIZE

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
    
    ErrorWarnCountT ewc = UHUnionHeapO0QCapi.sizeChecks(__LINE__);
    
    if(ewc.classErrors > 0)
    {
        XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidQCapi.getAssertText(__FUNCTION__)]);
    }
}


@end


#pragma mark - OURSORT

/**
 *
 */
@interface UHUnionHeapZ0UseOurSortTests : XCTestCase

@end

@implementation UHUnionHeapZ0UseOurSortTests

- (void)setUp {
    masterMillionUnionsInfo =
        UHUnionHeapO0QCapi.newUhxPassT(myMillionUnions, sizeof(myMillionUnions), INT_DATATYPESM, FILL_RANDOM, __LINE__);
}

- (void)tearDown {
}

- (void)test2099SortSeqChkOurSortIntegers {
    
    masterMillionUnionsInfo.heapCount = MYBIGODD_HEAPCT;
    srtPass.uhxPassP = &masterMillionUnionsInfo;
    srtPass.passCount = srtPass.parentSwapCount = 0;
    UHUnionHeapO0QCapi.seqChk(&masterMillionUnionsInfo, __LINE__);
    
    UHUnionHeapO0QCapi.ourSort(&srtPass, __LINE__);
    
    UHUnionHeapO0QCapi.seqChk(&masterMillionUnionsInfo, __LINE__);
}


@end // use


#pragma mark - HASHSORT

/**
 *
 */
@interface UHUnionHeapZ0UseHashSortTests : XCTestCase

@end

@implementation UHUnionHeapZ0UseHashSortTests

- (void)setUp {
    masterMillionUnionsInfo =
        UHUnionHeapO0QCapi.newUhxPassT(myMillionUnions, sizeof(myMillionUnions), INT_DATATYPESM, FILL_RANDOM, __LINE__);
}

- (void)tearDown {
}

- (void)test2099HashSortIntegers {
    
    masterMillionUnionsInfo.heapCount = MYBIGODD_HEAPCT;
    srtPass.uhxPassP = &masterMillionUnionsInfo;
    srtPass.passCount = srtPass.parentSwapCount = 0;
    
    UHUnionHeapO0QCapi.hashSort(&srtPass, __LINE__);
    
    //UHUnionHeapO0QCapi.seqChk(&masterMillionUnionsInfo, __LINE__);
}


@end // use


#pragma mark - PERF
/**
 * Performance is a subset of use.
 */
@interface UHUnionHeapZ0PerfIntRandTests : XCTestCase

@end


@implementation UHUnionHeapZ0PerfIntRandTests

- (void)setUp {

    masterMillionUnionsInfo = UHUnionHeapO0QCapi.newUhxPassT(myMillionUnions,
                                                             sizeof(myMillionUnions),
                                                             INT_DATATYPESM,
                                                             FILL_RANDOM,
                                                             __LINE__);
    
    masterMillionUnionsInfo.heapCount = MYBIGODD_HEAPCT;
}

- (void)tearDown {
    
}


- (void)test2099CompareOurSortIntegers {
    srtPass.uhxPassP = &masterMillionUnionsInfo;
    srtPass.passCount = srtPass.parentSwapCount = 0;
    UHUnionHeapO0QCapi.ourSort(&srtPass, __LINE__);
}


- (void)test2099CompareClangSortIntegers {
    srtPass.uhxPassP = &masterMillionUnionsInfo;
    srtPass.passCount = srtPass.parentSwapCount = 0;
    UHUnionHeapO0QCapi.clangSort(&srtPass, __LINE__);
}


@end // performance

#pragma mark - CLANG

@interface UHUnionHeapZ0UseClangIntRandTests : XCTestCase

@end


@implementation UHUnionHeapZ0UseClangIntRandTests

- (void)setUp {

    masterMillionUnionsInfo = UHUnionHeapO0QCapi.newUhxPassT(myMillionUnions,
                                                             sizeof(myMillionUnions),
                                                             INT_DATATYPESM,
                                                             FILL_RANDOM,
                                                             __LINE__);
    
    masterMillionUnionsInfo.heapCount = MYBIGODD_HEAPCT;
}

- (void)tearDown {
    
}


- (void)test2099SeqChkClangIntegers {
    
    UHUnionHeapO0QCapi.seqChk(&masterMillionUnionsInfo, __LINE__);
    srtPass.uhxPassP = &masterMillionUnionsInfo;
    srtPass.passCount = srtPass.parentSwapCount = 0;
    UHUnionHeapO0QCapi.clangSort(&srtPass, __LINE__);
    
    UHUnionHeapO0QCapi.seqChk(&masterMillionUnionsInfo, __LINE__);
}

@end

#pragma mark - BTREE
/**
 *
 */
@interface UHUnionHeapO0UseBtreeTests : XCTestCase

@end

@implementation UHUnionHeapO0UseBtreeTests


- (void)setUp {
    masterMillionUnionsInfo =
        UHUnionHeapO0QCapi.newUhxPassT(myMillionUnions,
                                 sizeof(myMillionUnions),
                                 INT_DATATYPESM,
                                 FILL_RANDOM,
                                 __LINE__);
}

- (void)tearDown {
}


- (void)test2099BtreeA {
    UHUnionHeapO0QCapi.btree(&masterMillionUnionsInfo, __LINE__);
    UHUnionHeapO0QCapi.seqChk(&masterMillionUnionsInfo, __LINE__);
}

@end

#pragma mark - BRUTE
/**
 *
 */
@interface UHUnionHeapO0UseBruteTests : XCTestCase

@end

@implementation UHUnionHeapO0UseBruteTests


- (void)setUp {
    masterMillionUnionsInfo =
        UHUnionHeapO0QCapi.newUhxPassT(myMillionUnions,
                                 sizeof(myMillionUnions),
                                 INT_DATATYPESM,
                                 FILL_RANDOM,
                                 __LINE__);
}

- (void)tearDown {
}

- (void)test2099BruteA {
    srtPass.uhxPassP = &masterMillionUnionsInfo;
    srtPass.passCount = srtPass.parentSwapCount = 0;
    UHUnionHeapO0QCapi.bruteSort(&srtPass, __LINE__);
    UHUnionHeapO0QCapi.seqChk(&masterMillionUnionsInfo, __LINE__);
}

@end

#pragma mark - SLOSH
/**
 *
 */
@interface UHUnionHeapO0UseSloshTests : XCTestCase

@end

@implementation UHUnionHeapO0UseSloshTests


- (void)setUp {
    masterMillionUnionsInfo =
        UHUnionHeapO0QCapi.newUhxPassT(myMillionUnions,
                                 sizeof(myMillionUnions),
                                 INT_DATATYPESM,
                                 FILL_RANDOM,
                                 __LINE__);
}

- (void)tearDown {
}

- (void)test2099SloshA {
    UHUnionHeapO0QCapi.slosh(&masterMillionUnionsInfo, __LINE__);
    UHUnionHeapO0QCapi.seqChk(&masterMillionUnionsInfo, __LINE__);
}

@end

// END UHUnionHeapO0XCTests.m
/**
 *
 */
