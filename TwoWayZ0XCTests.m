//
//  TwoWayZ0XCTests.m
//
//  Created by Robert R on 3/27/19.
//  Copyright (c) 2020 Robert Russell Millward.
//  All rights reserved.
//

#import <XCTest/XCTest.h>
#import "ArchitectureZ0Plan.h"
#import "TestAidZ0.h"




@interface TwoWayZ0SetATests : XCTestCase

@end

@implementation TwoWayZ0SetATests

- (void)setUp {
    TestAidZ0QCapi.basicInit();
}

- (void)tearDown {
    TestAidC.getCounts();
}






- (void)test2099ZULUTwoWayZ0SetADestroy {
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        char* report = ""/*InitDestroyerHelperC.getReport()*/;
        
        // Before destroyAll().
        if(report[0] != 0)
        {
            //XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:InitDestroyerHelperC.getReport()]);
            report[0] = 0;
        }
        
        // After destroyAll().
        //InitDestroyerHelperC.destroyAll(&TestAidZ0QCdata.twoWay);
        if(report[0] != 0)
        {
            //XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:InitDestroyerHelperC.getReport()]);
        }
    }
}

@end

@interface TwoWayZ0SetBTests : XCTestCase

@end

@implementation TwoWayZ0SetBTests

- (void)setUp {
    TestAidZ0QCapi.basicInit();
}

- (void)tearDown {
    TestAidC.getCounts();
}


- (void)test2099ZULUTwoWayZ0SetBDestroy {
    if(TestAidC.isScheduled(__FUNCTION__, TestAidZ0QCdata.showFunctionName)){
        char* report = "" /*InitDestroyerHelperC.getReport()*/;
        
        // Before destroyAll().
        if(report[0] != 0)
        {
            //XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:InitDestroyerHelperC.getReport()]);
            report[0] = 0;
        }
        
        // After destroyAll().
        //InitDestroyerHelperC.destroyAll(&TestAidZ0QCdata.twoWay);
        if(report[0] != 0)
        {
            // XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:InitDestroyerHelperC.getReport()]);
        }
    }
}

@end // TwoWayZ0XCTests.m
