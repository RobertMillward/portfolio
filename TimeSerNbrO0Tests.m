//
//  TimeSerNbrO0Tests.m
//
//  Created by Robert Russell Millward on 12/24/18.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
// os
#import <XCTest/XCTest.h>
// data plans
// api's
#import "TimeSerNbrO0.h"
// quality
#import "TestAidZ0.h"


@interface TimeSerNbrZ0UseTests : XCTestCase

@end

@implementation TimeSerNbrZ0UseTests


- (void)setUp {
    TestAidC.basicInit(); // does signature factory
}

- (void)tearDown {
    TestAidC.getCounts();
    //    InitDestroyerHelperC.destroyAll(&TestAidZ0QCdata.twoWay);
}


-(void)test2019SerNbrSequentialEachTran // Run stand alone
{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        bool assertForDebug = false;
        
        // Verify that serial number is serial in same transaction
        theStampAIdataT
            hotOne = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, CURRENT_BASE_YEAR},
            hotTwo = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, CURRENT_BASE_YEAR};
        // Make sure the serial numbers restart
        hotOne.currentSeconds = 0;
        hotTwo.currentSeconds = 0;
        
        TimeSerNbrHCapi.newTimeAndSerNbrNow(&hotOne);
        TestAidC.nextTx();
        TimeSerNbrHCapi.newTimeAndSerNbrNow(&hotTwo);
        // Occasionally this test will fail due to crossing the second.
        if(TestAidC.putTestInts(1, (int)hotOne.currentSerNbr, __LINE__) != 0 || // Why 2? TODO there is residual data
           TestAidC.putTestInts(1, (int)hotTwo.currentSerNbr, __LINE__) != 0 ||
           assertForDebug){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}

-(void)test2019SerNbrSequentialSameTran
{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        bool assertForDebug = false;
        
        // Verify that serial number is serial in same transaction
        TestAidC.nextTx();
        theStampAIdataT
            hotOne = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, CURRENT_BASE_YEAR},
            hotTwo = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, CURRENT_BASE_YEAR};
        
        TimeSerNbrHCapi.newTimeAndSerNbrNow(&hotOne);
        hotTwo.currentSeconds = hotOne.currentSeconds;
        // Occasionally this test will fail due to crossing the second.
        TimeSerNbrHCapi.newTimeAndSerNbrNow(&hotTwo);
        if(TestAidC.putTestInts(1, (int)hotOne.currentSerNbr, __LINE__) != 0 ||
           TestAidC.putTestInts(2, (int)hotTwo.currentSerNbr, __LINE__) != 0 ||
           assertForDebug){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}


-(void)test2019SerNbr8000PerTx
{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        bool assertForDebug = false;

        // Verify that serial number is not capped over two transactions
        theStampAIdataT hotOne = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, CURRENT_BASE_YEAR},
        hotTwo = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, CURRENT_BASE_YEAR};

        TestAidC.nextTx();
        for(int serIx = 0; serIx < 8000; serIx++)
        {
            TimeSerNbrHCapi.newTimeAndSerNbrNow(&hotOne);
        }

        TestAidC.nextTx();
        for(int serIx = 0; serIx < 8000; serIx++)
        {
            TimeSerNbrHCapi.newTimeAndSerNbrNow(&hotTwo);
        }

        if(TestAidC.putTestInts(8000, (int)hotOne.currentSerNbr, __LINE__) != 0 ||
           TestAidC.putTestInts(8000, (int)hotTwo.currentSerNbr, __LINE__) != 0 ||
           assertForDebug){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}

-(void)test2019SerNbrSerialPerTx
{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        bool assertForDebug = false;

        // Verify that serial number is independent in two transactions

        theStampAIdataT
            hotOne = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, CURRENT_BASE_YEAR},
            hotTwo = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, CURRENT_BASE_YEAR};

        TestAidC.nextTx();
        TimeSerNbrHCapi.newTimeAndSerNbrNow(&hotOne);

        TestAidC.nextTx();
        TimeSerNbrHCapi.newTimeAndSerNbrNow(&hotTwo);

        if(TestAidC.putTestInts(1, (int)hotOne.currentSerNbr, __LINE__) != 0 ||
           TestAidC.putTestInts(1, (int)hotTwo.currentSerNbr, __LINE__) != 0 ||
           assertForDebug){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}

@end


@interface TimeSerNbrZ0SizeTests : XCTestCase

@end

@implementation TimeSerNbrZ0SizeTests


- (void)setUp {
    TestAidC.basicInit();
}

- (void)tearDown {
    //  TestAidC.getCounts();
    //  InitDestroyerHelperC.destroyAll(&TestAidZ0QCdata.twoWay);
}


- (void)test2999SizeofTmSerNbrZ0
{
    // Added functionality and bigger x-field in early 2015.
    // Added bigger field in 2019
    if(TestAidQCapi.putTestInts(72, sizeof(theStampZ0AIdataT), __LINE__) != 0){
        XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
    }
}

@end


/**
 * .
 */
@interface TimeSerNbrZ0StringTests : XCTestCase

@end

@implementation TimeSerNbrZ0StringTests


- (void)setUp {
    TestAidC.basicInit();
}

- (void)tearDown {
    //  TestAidC.getCounts();
    //  InitDestroyerHelperC.destroyAll(&TestAidZ0QCdata.twoWay);
}


-(void) test2019RowOfSerNbr
{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        bool assertForDebug = false;
        
        gpSllgChar32T myStruct = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, CURRENT_BASE_YEAR};
        Zint theSize = TimeSerNbrHCapi.getRowOfSerNbr(&myStruct);
        char *badOrGood = "badLength";
        if(theSize == 24){
            badOrGood = myStruct.theCharValue;
        }
        
        if(TestAidC.putTestChars(badOrGood, myStruct.theCharValue, __LINE__) != 0 ||
           assertForDebug){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}

-(void) test2019StringOfTime
{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        bool assertForDebug = false;
        
        gpSllgChar32T myStruct = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, 9999 * FRACTION_SECS};
        
        TimeSerNbrHCapi.getStrOfTime(&myStruct);
        
        if(TestAidC.putTestChars("9999.000", myStruct.theCharValue, __LINE__) != 0 ||
           assertForDebug){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}


@end

/**
 * .
 */
@interface TimeSerNbrZ0MiscTests : XCTestCase

@end

@implementation TimeSerNbrZ0MiscTests


- (void)setUp {
    TestAidC.basicInit();
}

- (void)tearDown {
    //  TestAidC.getCounts();
    //  InitDestroyerHelperC.destroyAll(&TestAidZ0QCdata.twoWay);
}

#define JAN20_2019_095001PM 1548049493
-(void) test2019AgeInWeeksAndDays
{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        bool assertForDebug = false;
        
        gpSllgChar32T myStruct = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, JAN20_2019_095001PM};
        
        TimeSerNbrHCapi.getAgeInWeeksAndDays(&myStruct);
        // This string has to be set for each day of testing because the unit position is days.
        if(TestAidC.putTestChars("526W", myStruct.theCharValue, __LINE__) != 0 || // i.e, 46W is 4 weeks and 6 days so 50W is next.
           assertForDebug){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}

@end

/**
 * .
 */
@interface TimeSerNbrZ0ThoroughTests : XCTestCase

@end

@implementation TimeSerNbrZ0ThoroughTests


- (void)setUp {
    TestAidC.basicInit();
}

- (void)tearDown {
    //  TestAidC.getCounts();
    //  InitDestroyerHelperC.destroyAll(&TestAidZ0QCdata.twoWay);
}
/**
 * A thorough check that only version and level come from the caller.
 */
-(void)test2019SerNbrVerifyCodes
{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        bool assertForDebug = false;
        
        Zchr callerSeesVersion = 'O';
        Zsht callerSeesLevel = '0';
        Sllg currentSeconds = 30*366*SECS_PER_DAY;
        Ullg currentQSeconds = 0;
        Usht currentYear = 9999;
        Usht baseYear = CURRENT_BASE_YEAR;
        Usht currentQuarter = 4 ;
        Usht currentSerNbr = 0;
        Usht isLeapYear = 0;
        Zchr yearCode[YEAR_CODE_Z_TIME+1] = " ";
        Zchr quarterCode[QTR_CODE_Z_TIME+1] = " ";
        Zchr secondsIntoQuarterCode[SECS_CODE_Z_TIME+1] = "    ";
        Zchr serNbrCode[SERNBR_CODE_Z_TIME+1] = "  ";
        
        theStampAIdataT hotOne = {
            NO_ARG_PTR_ARC,
            &TestAidZ0QCdata.twoWay,
            baseYear,
            currentSeconds,
            currentQSeconds,
            currentYear,
            currentQuarter,
            currentSerNbr,
            isLeapYear
        };
        strcpy(hotOne.yearCode, yearCode);
        strcpy(hotOne.quarterCode, quarterCode);
        strcpy(hotOne.secondsIntoQuarterCode, secondsIntoQuarterCode);
        strcpy(hotOne.serNbrCode, serNbrCode);
        
        TimeSerNbrHCapi.newTimeAndSerNbrNow(&hotOne);
        
        if(TestAidC.putTestInts(hotOne.versionLevelP->callerSeesVersion,  callerSeesVersion,  __LINE__) != 0 ||
           TestAidC.putTestInts(hotOne.versionLevelP->callerSeesLevel,    callerSeesLevel,    __LINE__) != 0 ||
           TestAidC.putTestInts(hotOne.currentYear,        currentYear,        __LINE__) == 0 ||
           TestAidC.putTestInts(hotOne.currentQuarter,     currentQuarter,     __LINE__) == 0 ||
           TestAidC.putTestChars(hotOne.yearCode,          yearCode,           __LINE__) == 0 ||
           TestAidC.putTestChars(hotOne.quarterCode,       quarterCode,        __LINE__) == 0 ||
           TestAidC.putTestChars(hotOne.secondsIntoQuarterCode, secondsIntoQuarterCode, __LINE__) == 0 ||
           TestAidC.putTestChars(hotOne.serNbrCode,      serNbrCode,       __LINE__) == 0 ||
           assertForDebug){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}


/**
 * This test needs to be upgraded to the new high value. 10,000 is gt 8100 but not the new number TODO
 */
-(void)test2016SerNbrAA92X92
{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        bool assertForDebug = false;
        
        // Verify that transaction never exceeds 92^2
        long maxTranNbrSeen = 0;
        theStampAIdataT hotOne = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, CURRENT_BASE_YEAR};
        for(int cx = 0; cx < 10000; cx++){ // Test must take 1.x seconds
            TimeSerNbrHCapi.newTimeAndSerNbrNow(&hotOne);
            if(hotOne.currentSerNbr > maxTranNbrSeen){
                maxTranNbrSeen = hotOne.currentSerNbr;
            }
        }
        
        if(TestAidC.putTestInts((int)maxTranNbrSeen, 92*92, __LINE__) != 0 ||
           assertForDebug){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}

@end
