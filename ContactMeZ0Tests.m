//
//  ContactMeZ0Tests.m
//
//  Created by Robert R on 01/09/20.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
// os
#import <XCTest/XCTest.h>
// data
// api
#import "ContactMeO0.h"
// quality
#import "TestAidZ0.h"
#import "PersonT0.h"
#import "StreetT0.h"
#import "CityT0.h"
#import "StateT0.h"



@interface ContactMeZ0SafetyTests : XCTestCase

@end

@implementation ContactMeZ0SafetyTests

- (void)setUp{
}

- (void)tearDown{
    //TestAidC.getCounts();
}


DataAidLocY0HClocT DataAidLocY0HCloc; // All zeros up here, thank you, linker.
static void
ContactMeZ0TestSupply(void)
{
    // Choose direction, initialize person and progress
    DataAidLocY0HCloc.x.direction = EAST_DIRECTION;
    DataAidLocY0HCloc.x.firstTimeIn = 1;
    DataAidLocY0HCloc.x.moreToDo = 1;
    
    char infoPerson[50];
    char infoAddrOne[50];
    char infoAddrTwo[50];
    char infoCtyStZip[50];
    
    int countEm = 0;
    
    while(DataAidLocY0HCloc.x.moreToDo){
        strcpy(infoPerson, "");
        strcpy(infoAddrOne, "");
        strcpy(infoAddrTwo, "");
        strcpy(infoCtyStZip, "");
        
        gpSllgChar64T gpSllgChar64;
        PersonT0HCapi.nextPerson(&DataAidLocY0HCloc);
        countEm++;
        
        CityT0HCapi.name(&DataAidLocY0HCloc, &gpSllgChar64);
        strcat(infoCtyStZip, gpSllgChar64.theCharValue); // i.e Seattle
        
        StateT0HCapi.codeOf(&DataAidLocY0HCloc, &gpSllgChar64);
        strcat(infoCtyStZip,  " ");
        strcat(infoCtyStZip,  gpSllgChar64.theCharValue); // i.e WA
        StateT0HCapi.zipOf(&DataAidLocY0HCloc, &gpSllgChar64);
        strcat(infoCtyStZip,  " ");
        strcat(infoCtyStZip,  gpSllgChar64.theCharValue); // i.e 99352
        //StateT0HCapi.popOf(&DataAidLocY0HCloc, &gpSllgChar64);
        
        StreetT0HCapi.getNumber(&DataAidLocY0HCloc, &gpSllgChar64);
        strcat(infoAddrOne, gpSllgChar64.theCharValue); // 3400
        StreetT0HCapi.getName(&DataAidLocY0HCloc, &gpSllgChar64);
        strcat(infoAddrOne, gpSllgChar64.theCharValue); // Aberdeen Ave
        StreetT0HCapi.getFloor(&DataAidLocY0HCloc, &gpSllgChar64);
        strcat(infoAddrTwo, gpSllgChar64.theCharValue); // 1st Floor
        
        PersonT0HCapi.famName(&DataAidLocY0HCloc, &gpSllgChar64);
        strcat(infoPerson, gpSllgChar64.theCharValue); // Millward
        PersonT0HCapi.givenName(&DataAidLocY0HCloc, &gpSllgChar64);
        strcat(infoPerson, ", ");
        strcat(infoPerson, gpSllgChar64.theCharValue); // , Robert
        PersonT0HCapi.age(&DataAidLocY0HCloc, &gpSllgChar64);
    }

    DataAidLocY0HCloc.x.moreToDo = 0; // a debugger landing point
}

- (void)
test2019Safety
{
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        ErrorWarnCountT ewc = {0,0,0,0};
        
        ContactMeZ0TestSupply();
        
        if(ewc.classErrors != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}
@end

//@interface ContactMeZ0GeneralTests : XCTestCase
//
//@end
//
//@implementation ContactMeZ0GeneralTests
//
//- (void)setUp{
//}
//
//- (void)tearDown{
//    //TestAidC.getCounts();
//}
//
//- (void)
//test2019General
//{
//    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
//         ErrorWarnCountT ewc = {0,0,0,0};
//        if(ewc.classErrors != 0)
//        {
//            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
//        }
//    }
//}
//@end
//
//@interface ContactMeZ0MisuseTests : XCTestCase
//
//@end
//
//@implementation ContactMeZ0MisuseTests
//
//- (void)setUp{
//}
//
//- (void)tearDown{
//    //TestAidC.getCounts();
//}
//
//- (void)
//test2019Misuse
//{
//    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
//        ErrorWarnCountT ewc = {0,0,0,0};
//        if(ewc.classErrors != 0)
//        {
//            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
//        }
//    }
//}
//@end
//
//@interface StressContactMeZ0QTests : XCTestCase
//
//@end
//
//@implementation StressContactMeZ0QTests
//
//- (void)setUp{
//}
//
//- (void)tearDown{
//    //TestAidC.getCounts();
//}
//
//- (void)
//test2019StressContactMe
//{
//    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
//        ErrorWarnCountT ewc = {0,0,0,0};
//        if(ewc.classErrors != 0)
//        {
//            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
//        }
//    }
//}
//
//@end
//
//@interface StressThreadingZ0QTests : XCTestCase
//
//@end
//
//@implementation StressThreadingZ0QTests
//
//- (void)setUp{
//}
//
//- (void)tearDown{
//    //TestAidC.getCounts();
//}
//
//- (void)
//test2019StressThreading
//{
//    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
//        ErrorWarnCountT ewc = {0,0,0,0};
//        if(ewc.classErrors != 0)
//        {
//            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
//        }
//    }
//}
//@end

/**
 */
