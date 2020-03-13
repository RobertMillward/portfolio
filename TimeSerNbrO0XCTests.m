//
//  TimeSerNbrZ0Tests.m
//  2020Apr02Dev
//
//  Created by Robert Russell Millward on 12/24/18.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
// os
#import <XCTest/XCTest.h>
// helper api's
#import "TimeSerNbrO0.h"
// data plans
// quality
#import "TestAidZ0.h"
#import "TimeSerNbrZ0TestAid.h"

// Break out only tests that require special aetup
@interface TimeSerNbrZ0OrdinaryTests : XCTestCase
@end
@interface TimeSerNbrZ0SafeSizeTests : XCTestCase
@end
@interface TimeSerNbrZ0BasicTests : XCTestCase
@end
@interface TimeSerNbrZ0ExtraDemoTests : XCTestCase
@end
@interface TimeSerNbrZ0PerformanceTests : XCTestCase
@end




@implementation TimeSerNbrZ0OrdinaryTests
- (void)setUp {
    TimeSerNbrO0QCapi.setupSet1(__LINE__);
}

- (void)tearDown {
    TimeSerNbrO0QCapi.teardownSet1(__LINE__);
}

#define JAN20_2019_095001PM 1548049493
-(void) test2019AgeInWeeksAndDays
{
    if(TestAidQCapi.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        bool assertForDebug = false;
        
        gpSllgChar32T myStruct = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, JAN20_2019_095001PM};
        
        TimeSerNbrO0HCapi.getAgeInWeeksAndDays(&myStruct);
        // This string has to be set for each day of testing because the unit position is days.
        if(TestAidQCapi.putTestChars("594W", myStruct.theCharValue, __LINE__) != 0 || // i.e, 46W is 4 weeks and 6 days so 50W is next.
           assertForDebug){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidQCapi.getAssertText(__FUNCTION__)]);
        }
    }
}

- (void)test2998SizeofTmSerNbrZ0
{
    // Added functionality and bigger x-field in early 2015.
    if(TestAidQCapi.putTestInts(72, sizeof(theStampZ0AIdataT), __LINE__) != 0){
        XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidQCapi.getAssertText(__FUNCTION__)]);
    }
}

/**
 * A thorough check that only version and level come from the caller.
 */
-(void)test2019SerNbrVerifyCodes
{
    if(TestAidQCapi.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
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
        
        TimeSerNbrO0HCapi.newTimeAndSerNbrNow(&hotOne);
        
        if(TestAidQCapi.putTestChar1(hotOne.versionLevelP->callerSeesVersion,  callerSeesVersion,  __LINE__) != 0 ||
           TestAidQCapi.putTestChar1(hotOne.versionLevelP->callerSeesLevel,    callerSeesLevel,    __LINE__) != 0 ||
           TestAidQCapi.putTestInts(hotOne.currentYear,        currentYear,        __LINE__) == 0 ||
           TestAidQCapi.putTestInts(hotOne.currentQuarter,     currentQuarter,     __LINE__) == 0 ||
           TestAidQCapi.putTestChars(hotOne.yearCode,          yearCode,           __LINE__) == 0 ||
           TestAidQCapi.putTestChars(hotOne.quarterCode,       quarterCode,        __LINE__) == 0 ||
           TestAidQCapi.putTestChars(hotOne.secondsIntoQuarterCode, secondsIntoQuarterCode, __LINE__) == 0 ||
           TestAidQCapi.putTestChars(hotOne.serNbrCode,      serNbrCode,       __LINE__) == 0 ||
           assertForDebug){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidQCapi.getAssertText(__FUNCTION__)]);
        }
    }
}



-(void)test2019SerNbrAA92X92X92
{
    if(TestAidQCapi.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        bool assertForDebug = false;
        
        // Verify that transaction never exceeds 92^2
        int maxTranNbrSeen = 0;
        theStampAIdataT hotOne = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, CURRENT_BASE_YEAR};
        for(int cx = 0; cx < 2000000; cx++){ // Test must take 1.x seconds
            TimeSerNbrO0HCapi.newTimeAndSerNbrNow(&hotOne);
            if(hotOne.currentSerNbr > maxTranNbrSeen){
                maxTranNbrSeen = (int)hotOne.currentSerNbr;
            }
        }
        
        if(TestAidQCapi.putTestInts(maxTranNbrSeen, 92*92*92, __LINE__) != 0 ||
           assertForDebug){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidQCapi.getAssertText(__FUNCTION__)]);
        }
    }
}

-(void)test2019SerNbrSequentialEachTran // Run stand alone
{
    if(TestAidQCapi.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        bool assertForDebug = false;
        sleep(1);
        
        // Verify that serial number is serial in same transaction
        theStampAIdataT
            hotOne = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay},
            hotTwo = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay};
            hotOne.currentBaseYear = hotTwo.currentBaseYear = CURRENT_BASE_YEAR;
        do
        {
            TimeSerNbrO0HCapi.newTimeAndSerNbrNow(&hotOne);
        }while(hotOne.currentSerNbr != 1);
        
        TimeSerNbrO0HCapi.newTimeAndSerNbrNow(&hotOne);
        TestAidQCapi.nextTx();
        TimeSerNbrO0HCapi.newTimeAndSerNbrNow(&hotTwo);
        // Occasionally this test will fail due to crossing the second.
        if(TestAidZ0QCapi.putTestInts(2, (int)hotOne.currentSerNbr, __LINE__) != 0 || // Why 2? TODO there is residual data
           TestAidQCapi.putTestInts(3, (int)hotTwo.currentSerNbr, __LINE__) != 0 ||
           assertForDebug){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidQCapi.getAssertText(__FUNCTION__)]);
        }
    }
}

-(void)test2019SerNbrSequentialSameTran
{
    if(TestAidQCapi.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        bool assertForDebug = false;
        sleep(1);
        
        // Verify that serial number is serial in same transaction
        TestAidQCapi.nextTx();
        theStampAIdataT
            hotOne = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay},
            hotTwo = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay};
            hotOne.currentBaseYear = hotTwo.currentBaseYear = CURRENT_BASE_YEAR;
        do
        {
            TimeSerNbrO0HCapi.newTimeAndSerNbrNow(&hotOne);
        }while(hotOne.currentSerNbr != 1);
        
        TimeSerNbrO0HCapi.newTimeAndSerNbrNow(&hotOne);
        hotTwo.currentSeconds = hotOne.currentSeconds;
        // Occasionally this test will fail due to crossing the second.
        TimeSerNbrO0HCapi.newTimeAndSerNbrNow(&hotTwo);
        if(TestAidQCapi.putTestInts(2, (int)hotOne.currentSerNbr, __LINE__) != 0 ||
           TestAidQCapi.putTestInts(3, (int)hotTwo.currentSerNbr, __LINE__) != 0 ||
           assertForDebug){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidQCapi.getAssertText(__FUNCTION__)]);
        }
    }
}


-(void)test2019SerNbr200000PerTx
{
    if(TestAidQCapi.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        bool assertForDebug = false;
        sleep(1);

        // Verify that serial number is not capped over two transactions
        theStampAIdataT
        hotOne = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay},
        hotTwo = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay};
        hotOne.currentBaseYear = hotTwo.currentBaseYear = CURRENT_BASE_YEAR;
        do
        {
            TimeSerNbrO0HCapi.newTimeAndSerNbrNow(&hotOne);
        }while(hotOne.currentSerNbr != 1);
        
        TestAidQCapi.nextTx();
        for(int serIx = 0; serIx < 200000; serIx++)
        {
            TimeSerNbrO0HCapi.newTimeAndSerNbrNow(&hotOne);
        }

        TestAidQCapi.nextTx();
        for(int serIx = 0; serIx < 200000; serIx++)
        {
            TimeSerNbrO0HCapi.newTimeAndSerNbrNow(&hotTwo);
        }

        if(TestAidQCapi.putTestInts(200001, (int)hotOne.currentSerNbr, __LINE__) != 0 ||
           TestAidQCapi.putTestInts(400001, (int)hotTwo.currentSerNbr, __LINE__) != 0 ||
           assertForDebug){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidQCapi.getAssertText(__FUNCTION__)]);
        }
    }
}

-(void)test2019SerNbrSerialPerTx
{
    if(TestAidQCapi.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        bool assertForDebug = false;

        // Verify that serial number is independent in two transactions

        theStampAIdataT
            hotOne = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay},
            hotTwo = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay};
            hotOne.currentBaseYear = hotTwo.currentBaseYear = CURRENT_BASE_YEAR;
        do
        {
            TimeSerNbrO0HCapi.newTimeAndSerNbrNow(&hotOne);
        }while(hotOne.currentSerNbr != 1);

        TestAidQCapi.nextTx();
        TimeSerNbrO0HCapi.newTimeAndSerNbrNow(&hotOne);

        TestAidQCapi.nextTx();
        TimeSerNbrO0HCapi.newTimeAndSerNbrNow(&hotTwo);

        if(TestAidQCapi.putTestInts(2, (int)hotOne.currentSerNbr, __LINE__) != 0 ||
           TestAidQCapi.putTestInts(3, (int)hotTwo.currentSerNbr, __LINE__) != 0 ||
           assertForDebug){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidQCapi.getAssertText(__FUNCTION__)]);
        }
    }
}

-(void) test2019RowOfSerNbr
{
    if(TestAidQCapi.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        bool assertForDebug = false;
        
        gpSllgChar32T myStruct = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, CURRENT_BASE_YEAR};
        Zint theSize = TimeSerNbrO0HCapi.getRowOfSerNbr(&myStruct);
        // set to 24 11Feb2020
        // set back to 22 10Mar2020 TODO: so, it's 24 when run alone and 22 when batched, NOPE
        if(TestAidQCapi.putTestInts(24, theSize, __LINE__) != 0 ||
           assertForDebug){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidQCapi.getAssertText(__FUNCTION__)]);
        }
    }
}

-(void) test2019StringOfTime
{
    if(TestAidQCapi.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        bool assertForDebug = false;
        
        gpSllgChar32T myStruct = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, 9999 * FRACTION_SECS};
        
        TimeSerNbrO0HCapi.getStrOfTime(&myStruct);
        
        if(TestAidQCapi.putTestChars("9999.000", myStruct.theCharValue, __LINE__) != 0 ||
           assertForDebug){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidQCapi.getAssertText(__FUNCTION__)]);
        }
    }
}

-(void) test2999SuiteStats
{
    // teardown prints then rolls the counter on this test
}

@end
// END TimeSerNbrO0XCTests.m
/**
 *
 */
