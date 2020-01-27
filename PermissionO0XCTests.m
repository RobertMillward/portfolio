//
//  PermissionO0Tests.m
//
//  Created by Robert R on 3/27/19.
//  Copyright (c) 2015 Robert Russell Millward.
//  All rights reserved.
//

#import <XCTest/XCTest.h>
#import "ArchitectureO0.h"
#import "PermissionO0.h"
#import "PeopleGroupO0.h"
#import "TestAidO0.h"
#import "InitDestroyHelperO0.h"
#import "SignatureFactoryO0.h"
//#import "CommaSepO3.h"
//#import "UnixStreamO0.h"
#import "RowO0.h"
#import "HashBasicsO0.h"


@interface PermissionO0SetATests : XCTestCase

@end

@implementation PermissionO0SetATests

- (void)setUp {
    initSignatureFactoryO0(&TestAidO0QCdata.twoWay);
}

- (void)tearDown {
    TestAidC.getCounts();
}






- (void)test2099ZULUPermissionO0SetADestroy {
    if(TestAidC.isScheduled(__FUNCTION__, TestAidO0QCdata.showFunctionName)){
        char* report = InitDestroyerHelperO0ACapi.getReport();
        
        // Before destroyAll().
        if(report[0] != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:InitDestroyerHelperO0ACapi.getReport()]);
            report[0] = 0;
        }
        
        // After destroyAll().
        InitDestroyerHelperO0ACapi.destroyAll(&TestAidO0QCdata.twoWay);
        if(report[0] != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:InitDestroyerHelperO0ACapi.getReport()]);
        }
    }
}

@end

@interface PermissionO0SetBTests : XCTestCase

@end

@implementation PermissionO0SetBTests

- (void)setUp {
    initSignatureFactoryO0(&TestAidO0QCdata.twoWay);
}

- (void)tearDown {
    TestAidC.getCounts();
    InitDestroyerHelperO0ACapi.destroyAll(&TestAidO0QCdata.twoWay);
}


- (void)test2099ZULUPermissionO0SetBDestroy {
    if(TestAidC.isScheduled(__FUNCTION__, TestAidO0QCdata.showFunctionName)){
        char* report = InitDestroyerHelperO0ACapi.getReport();
        
        // Before destroyAll().
        if(report[0] != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:InitDestroyerHelperO0ACapi.getReport()]);
            report[0] = 0;
        }
        
        // After destroyAll().
        InitDestroyerHelperO0ACapi.destroyAll(&TestAidO0QCdata.twoWay);
        if(report[0] != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:InitDestroyerHelperO0ACapi.getReport()]);
        }
    }
}

@end
