//
//  TimeSerNbrZ0Tests.m
//
//  Created by Robert Russell Millward on 12/24/18.
//  Copyright © 2018 Robert Russell Millward. All rights reserved.
//


#import <XCTest/XCTest.h>
#import "TestAidZ0.h"
#import "TimeSerNbrO0.h"


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
            hotOne = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, TEST_BASE_YEAR},
            hotTwo = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, TEST_BASE_YEAR};
        // Make sure the serial numbers restart
        hotOne.currentSeconds = 0;
        hotTwo.currentSeconds = 0;
        
        TimeSerNbrACapi.newTimeAndSerNbrNow(&hotOne);
        TestAidC.nextTx();
        TimeSerNbrACapi.newTimeAndSerNbrNow(&hotTwo);
        // Occasionally this test will fail due to crossing the second.
        if(TestAidC.putTestInts(1, hotOne.currentSerNbr, __LINE__) != 0 || // Why 2? TODO there is residual data
           TestAidC.putTestInts(1, hotTwo.currentSerNbr, __LINE__) != 0 ||
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
            hotOne = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, TEST_BASE_YEAR},
            hotTwo = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, TEST_BASE_YEAR};
        
        TimeSerNbrACapi.newTimeAndSerNbrNow(&hotOne);
        hotTwo.currentSeconds = hotOne.currentSeconds;
        // Occasionally this test will fail due to crossing the second.
        TimeSerNbrACapi.newTimeAndSerNbrNow(&hotTwo);
        if(TestAidC.putTestInts(1, hotOne.currentSerNbr, __LINE__) != 0 ||
           TestAidC.putTestInts(2, hotTwo.currentSerNbr, __LINE__) != 0 ||
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
        theStampAIdataT hotOne = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, TEST_BASE_YEAR},
        hotTwo = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, TEST_BASE_YEAR};

        TestAidC.nextTx();
        for(int serIx = 0; serIx < 8000; serIx++)
        {
            TimeSerNbrACapi.newTimeAndSerNbrNow(&hotOne);
        }

        TestAidC.nextTx();
        for(int serIx = 0; serIx < 8000; serIx++)
        {
            TimeSerNbrACapi.newTimeAndSerNbrNow(&hotTwo);
        }

        if(TestAidC.putTestInts(8000, hotOne.currentSerNbr, __LINE__) != 0 ||
           TestAidC.putTestInts(8000, hotTwo.currentSerNbr, __LINE__) != 0 ||
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
            hotOne = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, TEST_BASE_YEAR},
            hotTwo = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, TEST_BASE_YEAR};

        TestAidC.nextTx();
        TimeSerNbrACapi.newTimeAndSerNbrNow(&hotOne);

        TestAidC.nextTx();
        TimeSerNbrACapi.newTimeAndSerNbrNow(&hotTwo);

        if(TestAidC.putTestInts(1, hotOne.currentSerNbr, __LINE__) != 0 ||
           TestAidC.putTestInts(1, hotTwo.currentSerNbr, __LINE__) != 0 ||
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
    if(TestAidQCapi.putTestInts(64, sizeof(theStampZ0AIdataT), __LINE__) != 0){
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
        
        gpSllgCharArrayT myStruct = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, TEST_BASE_YEAR};
        Zint theSize = TimeSerNbrACapi.getRowOfSerNbr(&myStruct);
        char *badOrGood = "badLength";
        if(theSize == 22){ // 2019/11/20 "TimeSerNbr" increased length by 2
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
        
        gpSllgCharArrayT myStruct = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, 9999 * FRACTION_SECS};
        
        TimeSerNbrACapi.getStrOfTime(&myStruct);
        
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
        
        gpSllgCharArrayT myStruct = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, JAN20_2019_095001PM};
        
        TimeSerNbrACapi.getAgeInWeeksAndDays(&myStruct);
        // This string has to be set for each day of testing because the unit position is days.
        if(TestAidC.putTestChars("433W", myStruct.theCharValue, __LINE__) != 0 || // i.e, 46W is 4 weeks and 6 days so 50W is next.
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
        
        Zchr callerSeesVersion = 'Z';
        Zsht callerSeesLevel = '0';
        Sllg currentSeconds = 30*366*SECS_PER_DAY;
        Ullg currentQSeconds = 0;
        Usht currentYear = 9999;
        Usht baseYear = TEST_BASE_YEAR;
        Usht currentQuarter = 4 ;
        Usht currentSerNbr = 0;
        Usht isLeapYear = 0;
        Zchr yearCode[YEAR_CODE_Z_TIME+1] = " ";
        Zchr quarterCode[QTR_CODE_Z_TIME+1] = " ";
        Zchr secondsIntoQuarterCode[SECS_CODE_Z_TIME+1] = "    ";
        Zchr serNbrCode[TX_NBR_CODE_Z_TIME+1] = "  ";
        
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
        
        TimeSerNbrACapi.newTimeAndSerNbrNow(&hotOne);
        
        if( TestAidC.putTestInts(hotOne.versionLevelP->callerSeesVersion,  callerSeesVersion,  __LINE__) != 0 ||
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



-(void)test2019SerNbrAA92X92
{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        bool assertForDebug = false;
        
        // Verify that transaction never exceeds 92^2
        int maxTranNbrSeen = 0;
        theStampAIdataT hotOne = {NO_ARG_PTR_ARC, &TestAidZ0QCdata.twoWay, TEST_BASE_YEAR};
        for(int cx = 0; cx < 10000; cx++){ // Test must take 1.x seconds
            TimeSerNbrACapi.newTimeAndSerNbrNow(&hotOne);
            if(hotOne.currentSerNbr > maxTranNbrSeen){
                maxTranNbrSeen = hotOne.currentSerNbr;
            }
        }
        
        if(TestAidC.putTestInts(maxTranNbrSeen, 92*92, __LINE__) != 0 ||
           assertForDebug){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}

@end
