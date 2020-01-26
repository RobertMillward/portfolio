//
//  TwoWayZ0Tests.m
//
//  Created by Robert R on 3/27/19.
//  Copyright (c) 2015 Robert Russell Millward.
//  All rights reserved.
//

#import <XCTest/XCTest.h>
#import "ArchitectureZ0Plan.h"
#import "TestAidZ0.h"




@interface TwoWayZ0SetATests : XCTestCase

@end

@implementation TwoWayZ0SetATests

- (void)setUp {
    //initSignatureFactoryZ0(&TestAidZ0QCdata.twoWay);
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
    //initSignatureFactoryZ0(&TestAidZ0QCdata.twoWay);
}

- (void)tearDown {
    TestAidC.getCounts();
    //InitDestroyerHelperC.destroyAll(&TestAidZ0QCdata.twoWay);
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

@end // TwoWayZ0Tests.m
