//
//  HexasoftO3Tests.m
//  20200310Dev
//
//  Created by Robert R on 3/27/15.
//  Copyright (c) 2015 Robert Russell Millward.  All rights reserved.
//
// os
#include <XCTest/XCTest.h>
// helper and service api's
//#import "PeopleGroupO0.h"
//#import "InitDestroyHelperO1.h"
//#import "SignatureFactoryO0.h"
//#import "CSVO0.h"
// data plans
#include "ArchitectureZ0Plan.h"
// other api's
#include "HexasoftO3.h"
// quality
#import "TestAidZ0.h"

#import "UnixStreamO0.h"

@interface HexasoftO3Tests : XCTestCase

@end

@implementation HexasoftO3Tests

static bool showFunctionName = false;

- (void)setUp {
    //initSignatureFactoryO0(&TestAidO0QCre.infoTwoWay);
}

- (void)tearDown {
    TestAidC.getCounts();
    //InitDestroyerHelperC.destroyAll(&TestAidO0QCre.infoTwoWay);
}



- (void)test2019ZdoHexasoft {
    if(TA0C.isScheduled(__FUNCTION__, showFunctionName))
    {
//        int rowCount = 0;
//        /*initStatusT status = */initHexasofts(&TestAidO0QCdata.infoTwoWay);
//        HexasoftIT myHexasoft = newHexasoft(&TestAidO0QCdata.infoTwoWay);
//        myHexasoft.open("IP2LOCATION-LITE-DB11", &myHexasoft);
//        
//        char here[2000];
//        while(!myHexasoft.isAtEof(&myHexasoft) )
//        {
//            myHexasoft.read(here, &myHexasoft);
//            rowCount++;
//        }
//        myHexasoft.close(&myHexasoft);
//        here[1999] = 0;
    }
}

@end
/**
 *
 */
