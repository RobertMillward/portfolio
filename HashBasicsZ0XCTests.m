//
//  HashBasicsZ0XCTests.m - Test the O0 interfac3
//
//  Created by Robert R on 4/1/15.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
// os
#import <XCTest/XCTest.h>
// data plans
// api's
#import "HashBasicsO0.h"
// quality
#import "TestAidZ0.h"


@interface HashBasicsO0Tests : XCTestCase

@end

@implementation HashBasicsO0Tests

- (void)setUp {
}

- (void)tearDown {
}

/**
 * This test is not working TODO
 */
- (void)test2015SampleNotWorking {
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        
        char *tP = ",,\n,,\n";
        int rowNbr = 0;
        
        HashBasicsCtlT hc =
        {
            6,      // doAtLeast
            6,      // maxShift
            HB_NO_CONDENSE,
            HB_COL_NBR_BASE,
            HB_BIG_HASH_RSVD,
            ",",   // field separators
            "\n",   // row separators
            tP      // the data
        };
        
        while(*hc.tokenNxtP)
        {
            int hash = (int)HashBasicsHCapi.getBasicHash(&hc);
            
            char wkS[1001];
            strncpy(wkS, hc.tokenBegP, hc.tokenEndP - hc.tokenBegP);
            wkS[hc.tokenEndP - hc.tokenBegP] = 0;
            
            if(TestAidC.putTestChars("", wkS, __LINE__) != 0)
            {
                XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
            }
            
            hc.byCol++;
            
            if(*hc.tokenEndP == '\n')
            {
                if(TestAidC.putTestInts(3, hc.byCol, __LINE__) != 0)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                    
                }
                hc.byCol = HB_COL_NBR_BASE;
                rowNbr++;
            }
        }
        
        if(TestAidC.putTestInts(2, rowNbr, __LINE__) != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
            
        }
    }
}


- (void)test2019LikeTestAid {
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName))
    {
        char *tP = "someFunc inSomeFile.c\n exit\n";
        
        HashBasicsCtlT hc =
        {
            6,      // doAtLeast
            6,      // maxShift
            HB_NO_CONDENSE,
            HB_NO_COLUMNS,
            HB_BIG_HASH_RSVD,
            " .",   // field separators
            "\n",   // row separators
            tP      // the data
        };
        
        int h1 = -99999, h2 = h1;
        
        //strcpy(latestFunc, "");
        
        while(*hc.tokenNxtP)
        {
            int hash = (int)HashBasicsHCapi.getBasicHash(&hc);
            char wkS[1001];
            strncpy(wkS, hc.tokenBegP, hc.tokenEndP - hc.tokenBegP);
            wkS[hc.tokenEndP - hc.tokenBegP] = 0;
            if(strcmp(wkS, "c") == 0){
                h2 += h1;
                
                if(TestAidC.putTestInts(5284881, h2, __LINE__) != 0)
                {
                    XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
                }
            }
            
            h2 = h1;
            h1 = hash;
        }
    }
}

- (void)test2019therName
{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName))
    {
        if(TestAidC.putTestInts(   0, (int)HashBasicsHCapi.get8100HashForOtherName("00200"),         __LINE__) != 0 ||
           TestAidC.putTestInts(  15, (int)HashBasicsHCapi.get8100HashForOtherName("02000"),         __LINE__) != 0 ||
           TestAidC.putTestInts(4168, (int)HashBasicsHCapi.get8100HashForOtherName("getHappyDays"),  __LINE__) != 0 ||
           TestAidC.putTestInts(4168, (int)HashBasicsHCapi.get8100HashForOtherName("setHappyDays"),  __LINE__) != 0 ||
           TestAidC.putTestInts(4168, (int)HashBasicsHCapi.get8100HashForOtherName("HappyDays"),     __LINE__) != 0 ||
           TestAidC.putTestInts(4546, (int)HashBasicsHCapi.get8100HashForOtherName("islandTime"),    __LINE__) != 0 ||
           TestAidC.putTestInts(7399, (int)HashBasicsHCapi.get8100HashForOtherName("isZooAnimal"),   __LINE__) != 0 ||
           TestAidC.putTestInts(7447, (int)HashBasicsHCapi.get8100HashForOtherName("ZZZsleep"),      __LINE__) != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}


- (void)test201901CompileLike
{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName))
    {
        char *tP = "HappyHollow PatientVisit HashBasics TimeoutBox.clean";
        
        HashBasicsCtlT hbc =
        {
            6,      // doAtLeast
            6,      // maxShift
            HB_NO_CONDENSE,
            HB_NO_COLUMNS,
            HB_BIG_HASH_RSVD,
            " .",   // field separators
            "\n",   // row separators
            tP      // the data
        };
        
        struct gotFromTextS
        {
            Slng bigHash;
            Zsht littleHash;
            char *whereInBufferP;
            Zsht mass;
        }gotFromText[10];
        int gftIx = 0;
        
        while(*hbc.tokenNxtP)
        {
            gotFromText[gftIx].bigHash = HashBasicsHCapi.getBasicHash(&hbc);
            gotFromText[gftIx].whereInBufferP = hbc.tokenBegP;
            gotFromText[gftIx].mass = hbc.tokenEndP - hbc.tokenBegP;
            /*
            char wkS[1001];
            strncpy(wkS, gotFromText[gftIx].whereInBufferP, gotFromText[gftIx].mass);
            wkS[gotFromText[gftIx].mass] = 0;
            gotFromText[gftIx++].littleHash = HashBasicsC.get8100HashForOtherName(wkS);
             */
            gotFromText[gftIx].littleHash = HashBasicsHCapi.get8100HashForOtherName(gotFromText[gftIx].whereInBufferP);
            gftIx++;
        }
            
        if(TestAidC.putTestInts(   5, gftIx,         __LINE__) != 0 ||
           1 == 2)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}

@end

//END HashBasicsZ0XCTests.m
/**
 *
 */
