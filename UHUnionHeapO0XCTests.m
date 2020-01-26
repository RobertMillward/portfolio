//
//  UnionHeapO0XCTests.m - tests for version o level 0
//  gitrealportfolio
//
//  Created by Robert R on 11/02/19.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
// os
#import <XCTest/XCTest.h>
// data plan
#import "UHUnionHeapZ0Plan.h"
// api's
#import "UHUnionHeapO0.h"
// test aids
#import "SortMergeZ0TestAid.h"


#define MYARRAYCT       1000000
#define MYBIGODD_HEAPCT 999997 // To test the left edge of the third row
#define MYSMALL_HEAPCT  900 // To keep the test small
#define MYTINY_HEAPCT   16
static uhxElT myMillionUnions[MYARRAYCT];

static uhxPassT masterMillionUnionsInfo;




/**
 * S I Z E
 */
@interface UHUnionHeapZ0SizeTests : XCTestCase

@end

@implementation UHUnionHeapZ0SizeTests

- (void)setUp {
}

- (void)tearDown {
}

- (void)test2099SizeUHUnionHeap {
    // Use XCTAssert and related functions to verify your tests produce the correct results.
    printf("*******%lu, %lu, %lu, %lu\n", sizeof(void*), sizeof(uhxPtrSzMfloatT), sizeof(uhxPtrSzMintegerT), sizeof(uhxPtrSzCstringT));
}


@end


/**
 *
 */
@interface UHUnionHeapZ0UseTests : XCTestCase

@end




@implementation UHUnionHeapZ0UseTests

- (void)setUp {
    //masterMillionUnionsInfo = UHUnionHeapZ0QClineApi.newInfo(myMillionUnions, sizeof(myMillionUnions), INT_DATATYPESM, FILL_RANDOM, __LINE__);
}

- (void)tearDown {
    
}

- (void)test2099DoSomething {
    
    masterMillionUnionsInfo.heapCount = MYBIGODD_HEAPCT;

}


@end



// END UnionHeapZ0XCTests.m
/**
 */
