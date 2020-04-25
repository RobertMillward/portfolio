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
static srtPassT srtPass = {0, 0, DEFAULT_COMPARE, 0};


@interface UHUnionHeapZ0OrdinaryTests : XCTestCase
@end

@interface UHUnionHeapZ0PerfIntRandTests : XCTestCase
@end
@interface UHUnionHeapO0UseMiscTests : XCTestCase
@end

@interface UHUnionHeapO0SafeSizeTests : XCTestCase
@end
@interface UHUnionHeapO0OtherTests : XCTestCase
@end



#pragma mark - SAFETY


@implementation UHUnionHeapO0SafeSizeTests

- (void)setUp {
}

- (void)tearDown {
}
/**
* This includes about 20 tests for safety.
*/
- (void)test2099SafeSize {
    
    ErrorWarnCountT ewc = UHUnionHeapO0QCapi.safeSizeChecks012n(__LINE__);
    
    if(ewc.classErrors > 0)
    {
        XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidQCapi.getAssertText(__FUNCTION__)]);
    }
}

@end




#pragma mark - PERF (no sequence check)

@implementation UHUnionHeapZ0PerfIntRandTests
- (void)setUp {
    masterMillionUnionsInfo = UHUnionHeapO0QCapi.newUhxPassT(myNMillionUnions,
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


@end // performance (no sequence check)



@implementation UHUnionHeapZ0OrdinaryTests

- (void)setUp {

    masterMillionUnionsInfo = UHUnionHeapO0QCapi.newUhxPassT(myNMillionUnions,
                                                             sizeof(myNMillionUnions),
                                                             INT_DATATYPESM,
                                                             FILL_RANDOM,
                                                             __LINE__);
}

- (void)tearDown {
}

#pragma mark - CLANGSORT

- (void)test2099SeqChkClangIntegers {
    
    UHUnionHeapO0QCapi.seqChk(&masterMillionUnionsInfo, __LINE__);
    srtPass.uhxPassP = &masterMillionUnionsInfo;
    srtPass.passCount = srtPass.parentSwapCount = 0;
    UHUnionHeapO0QCapi.clangSort(&srtPass, __LINE__);
    
    UHUnionHeapO0QCapi.seqChk(&masterMillionUnionsInfo, __LINE__);
}

#pragma mark - OURSORT

- (void)test2099SeqChkOurSortIntegers {

    srtPass.uhxPassP = &masterMillionUnionsInfo;
    srtPass.passCount = srtPass.parentSwapCount = 0;
    UHUnionHeapO0QCapi.seqChk(&masterMillionUnionsInfo, __LINE__);
    
    UHUnionHeapO0QCapi.ourSort(&srtPass, __LINE__);
    
    UHUnionHeapO0QCapi.seqChk(&masterMillionUnionsInfo, __LINE__);
}

#pragma mark - LOGSORT

- (void)test2099SeqChkLogSortIntegers {

    masterMillionUnionsInfo.oneTooManyP = masterMillionUnionsInfo.uhxHeapP + masterMillionUnionsInfo.heapCount;
    srtPass.uhxPassP = &masterMillionUnionsInfo;
    srtPass.passCount = srtPass.parentSwapCount = 0;
    srtPass.yourValuer = 0;
    
    UHUnionHeapO0QCapi.logSort(&srtPass, __LINE__);
    
    UHUnionHeapO0QCapi.seqChk(&masterMillionUnionsInfo, __LINE__);
}

@end


@implementation UHUnionHeapO0UseMiscTests

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


#pragma mark - BTREE

- (void)test2099BtreeA {
    UHUnionHeapO0QCapi.btree(&masterMillionUnionsInfo, __LINE__);
    UHUnionHeapO0QCapi.seqChk(&masterMillionUnionsInfo, __LINE__);
}

#pragma mark - BRUTE

//- (void)test2099BruteA {
//    srtPass.uhxPassP = &masterMillionUnionsInfo;
//    srtPass.passCount = srtPass.parentSwapCount = 0;
//    UHUnionHeapO0QCapi.bruteSort(&srtPass, __LINE__);
//    UHUnionHeapO0QCapi.seqChk(&masterMillionUnionsInfo, __LINE__);
//}

#pragma mark - SLOSH


- (void)test2099SloshA {
    UHUnionHeapO0QCapi.slosh(&masterMillionUnionsInfo, __LINE__);
    UHUnionHeapO0QCapi.seqChk(&masterMillionUnionsInfo, __LINE__);
}

@end

@implementation UHUnionHeapO0OtherTests
- (void)setUp {
}
- (void)tearDown {
}
- (void)test2004KeyHashTest {
    int year = 2014;
    if(year > 2015)
    {
        char lotsaText[] = "Now is the time for all good men to come to the aid of their country."
        " Give them hell. It's now or never. Bring every able bodied man. Love is in the air tonight."
        " Damn the torpedoes, full speed ahead. I Nephi, having been born of goodly parents, therefor"
        " I take it to myself to write about some of the things I learned in kindergarten."
        " Did you ever iver over see a deer dire dore with a dimple dimple domple on its ear ire ore?"
        " When in the course of human events it becomes necessary for one party to sever its relationship."
        " Do you like bacon wrapped avacado sandwiches?";
        
        Ssht KeyHashTest_researchYv[MAX_SORTX];
        // programming note: the file containing this code was lost during checkin. We may rebuild it later
//        extern void UHLLogSortZ0_gatherData_xf99(sourcePT source, int* keyByte, actionT action);
//        UHLLogSortZ0_gatherData_xf99(lotsaText, 0, INIT_BASE);
        for(int xx = 0; xx < MAX_SORTX; xx++){
            int keyByte = xx;
            //UHLLogSortZ0_gatherData_xf99(0, &keyByte, INIT_SRCH);
            KeyHashTest_researchYv[xx] = keyByte;
        }
        
        /**
         * Hash the text..
         */
        Slng fullLen = strlen(lotsaText);
        printf("    0 2 4 6 8 A C E");
        for(int ltsaIx = 0; ltsaIx < fullLen; ltsaIx++)
        {
            int xx = ltsaIx % MAX_SORTX;
            if(xx == 0){
                printf("\n%3d ", ltsaIx / MAX_SORTX );
            }
            
            char yv = lotsaText[ltsaIx] ^ KeyHashTest_researchYv[xx];
            if(yv < ' '){
                yv = '?';
            }
            printf("%c", yv);
            
        }
        printf("\n");
    }
}

@end

// END UHUnionHeapO0XCTests.m
/**
 *
 */
