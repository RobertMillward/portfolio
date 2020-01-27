//
//  RoleO0Tests.m
//
//  Created by Robert R on 3/27/19.
//  Copyright (c) 2015 Robert Russell Millward.
//  All rights reserved.
//

#import <XCTest/XCTest.h>
#import "ArchitectureO0.h"
#import "RoleO0.h"
//#import "PeopleGroupO0.h"
#import "TestAidO0.h"
//#import "InitDestroyHelperO0.h"
#import "SignatureFactoryO0.h"
//#import "CommaSepO3.h"
//#import "UnixStreamO0.h"
//#import "RowO0.h"
//#import "HashBasicsO0.h"

@interface RoleO0Tests : XCTestCase

@end

@implementation RoleO0Tests

- (void)setUp {
    initSignatureFactoryO0(&TestAidO0QCdata.twoWay);
}

- (void)tearDown {
    TestAidQCapi.getCounts();
}





/*
- (void)test2099ZULURoleO0NewDestroy {
    if(TestAidC.isScheduled(__FUNCTION__, showFunctionName)){
        char* report = InitDestroyerHelperC.getReport();
        
        // Before destroyAll().
        if(report[0] != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:InitDestroyerHelperC.getReport()]);
            report[0] = 0;
        }
        
        // After destroyAll().
        InitDestroyerHelperC.destroyAll(&TestAidO0QCre.infoTwoWay);
        if(report[0] != 0)
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:InitDestroyerHelperC.getReport()]);
        }
    }
}
 */

@end
