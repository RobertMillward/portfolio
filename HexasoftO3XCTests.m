//
//  HexasoftO3Tests.m
//
//  Created by Robert R on 3/27/15.
//  Copyright (c) 2015 Robert Russell Millward.
//  All rights reserved.
//

#import <XCTest/XCTest.h>
#import "ArchitectureO0.h"
#import "HexasoftO3.h"
#import "PeopleGroupO0.h"
#import "TestAidO0.h"
#import "InitDestroyHelperO1.h"
#import "SignatureFactoryO0.h"
#import "CSVO0.h"

#import "UnixStreamO0.h"

@interface HexasoftO03Tests : XCTestCase

@end

@implementation HexasoftO3Tests

static bool showFunctionName = false;

- (void)setUp {
    initSignatureFactoryO0(&TestAidO0QCre.infoTwoWay);
}

- (void)tearDown {
    TestAidC.getCounts();
    InitDestroyerHelperC.destroyAll(&TestAidO0QCre.infoTwoWay);
}



- (void)test2019ZdoHexasoft {
    if(TA0C.isScheduled(__FUNCTION__, showFunctionName))
    {
        int rowCount = 0;
        /*initStatusT status = */initHexasofts(&TestAidO0QCre.infoTwoWay);
        HexasoftIT myHexasoft = newHexasoft(&TestAidO0QCre.infoTwoWay);
        myHexasoft.open("IP2LOCATION-LITE-DB11", &myHexasoft);
        
        char here[2000];
        while(!myHexasoft.isAtEof(&myHexasoft) )
        {
            myHexasoft.read(here, &myHexasoft);
            rowCount++;
        }
        myHexasoft.close(&myHexasoft);
        here[1999] = 0;
    }
}

@end
