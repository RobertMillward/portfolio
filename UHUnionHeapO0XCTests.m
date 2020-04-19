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

#define MULT_FACTOR 5
static uhxElT myNMillionUnions[MYARRAYCT*MULT_FACTOR];
static uhxPassT masterMillionUnionsInfo;
static srtPassT srtPass;


@interface UHUnionHeapZ0PerfIntRandTests : XCTestCase
@end
@interface UHUnionHeapO0UseBruteTests : XCTestCase
@end
@interface UHUnionHeapO0UseBtreeTests : XCTestCase
@end
@interface UHUnionHeapZ0UseClangIntRandTests : XCTestCase
@end
@interface UHUnionHeapZ0UseLogSortTests : XCTestCase
@end
@interface UHUnionHeapZ0UseOurSortTests : XCTestCase
@end
@interface UHUnionHeapO0UseSloshTests : XCTestCase
@end
@interface UHUnionHeapO0SafetyTests : XCTestCase
@end
@interface UHUnionHeapO0SizeTests : XCTestCase
@end


#pragma mark - SAFETY

/**
 * S A F E
 */


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

@implementation UHUnionHeapZ0UseOurSortTests

- (void)setUp {
    masterMillionUnionsInfo =
        UHUnionHeapO0QCapi.newUhxPassT(myNMillionUnions, sizeof(myNMillionUnions), INT_DATATYPESM, FILL_RANDOM, __LINE__);
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


@implementation UHUnionHeapZ0UseLogSortTests

- (void)setUp {
    masterMillionUnionsInfo =
        UHUnionHeapO0QCapi.newUhxPassT(myNMillionUnions, sizeof(myNMillionUnions), INT_DATATYPESM, FILL_RANDOM, __LINE__);
}

- (void)tearDown {
}

- (void)test2099LogSortIntegers {
    
    masterMillionUnionsInfo.heapCount = MYBIGODD_HEAPCT;
    srtPass.uhxPassP = &masterMillionUnionsInfo;
    srtPass.passCount = srtPass.parentSwapCount = 0;
    
    UHUnionHeapO0QCapi.logSort(&srtPass, __LINE__);
    
    UHUnionHeapO0QCapi.seqChk(&masterMillionUnionsInfo, __LINE__);
}


@end // use


#pragma mark - PERF
/**
 * Performance is a subset of use.
 */


@implementation UHUnionHeapZ0PerfIntRandTests
- (void)setUp {
    masterMillionUnionsInfo = UHUnionHeapO0QCapi.newUhxPassT(myNMillionUnions,
                                                             sizeof(myNMillionUnions),
                                                             INT_DATATYPESM,
                                                             FILL_RANDOM,
                                                             __LINE__);
    
    //masterMillionUnionsInfo.heapCount = MYBIGODD_HEAPCT*MULT_FACTOR;
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

- (void)test2099CompareLogSortIntegers {
    srtPass.uhxPassP = &masterMillionUnionsInfo;
    srtPass.passCount = srtPass.parentSwapCount = 0;
    UHUnionHeapO0QCapi.logSort(&srtPass, __LINE__);
}


@end // performance

#pragma mark - CLANG



@implementation UHUnionHeapZ0UseClangIntRandTests

- (void)setUp {

    masterMillionUnionsInfo = UHUnionHeapO0QCapi.newUhxPassT(myNMillionUnions,
                                                             sizeof(myNMillionUnions),
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

@implementation UHUnionHeapO0UseBtreeTests


- (void)setUp {
    masterMillionUnionsInfo =
        UHUnionHeapO0QCapi.newUhxPassT(myNMillionUnions,
                                 sizeof(myNMillionUnions),
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

@implementation UHUnionHeapO0UseBruteTests


- (void)setUp {
    masterMillionUnionsInfo =
        UHUnionHeapO0QCapi.newUhxPassT(myNMillionUnions,
                                 sizeof(myNMillionUnions),
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


@implementation UHUnionHeapO0UseSloshTests


- (void)setUp {
    masterMillionUnionsInfo =
        UHUnionHeapO0QCapi.newUhxPassT(myNMillionUnions,
                                 sizeof(myNMillionUnions),
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
