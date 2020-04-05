//
//  TwoWayZ0XCTests.m
//  2020Apr21Dev
//
//  Created by Robert R on 3/27/19.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
// os
#import <XCTest/XCTest.h>
// quality
#import "TwoWayZ0TestAid.h"


// For test accounting
@interface AboutTests : XCTestCase
@end
@interface ZuluTests : XCTestCase
@end


// Break out only tests that require special setup
@interface TwoWayZ0OrdinaryTests : XCTestCase
@end
@interface TwoWayZ0SafeSizeTests : XCTestCase
@end
@interface TwoWayZ0BasicTests : XCTestCase
@end
@interface TwoWayZ0ExtraDemoTests : XCTestCase
@end
@interface TwoWayZ0PerformanceTests : XCTestCase
@end

@implementation TwoWayZ0OrdinaryTests

- (void)setUp {
    TwoWayZ0QCapi.setupSet1(__LINE__);
}

- (void)tearDown {
    TwoWayZ0QCapi.teardownSet1(__LINE__);
}



- (void)test2099SafeSize {
    if(TwoWayZ0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(TwoWayZ0QCapi.doSet1SizeSafe(__LINE__)){
           XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TwoWayZ0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}

- (void)test2099Basics {
    if(TwoWayZ0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        
        if(TwoWayZ0QCapi.doSet2Basics(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TwoWayZ0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}


- (void)test2099ExtraDemo {
    if(TwoWayZ0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        
        if(TwoWayZ0QCapi.doSet3ExtraDemo(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TwoWayZ0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}

- (void)test2099Performance {
    if(TwoWayZ0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        
        if(TwoWayZ0QCapi.doSet4Performance(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TwoWayZ0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}

- (void)test9999SuiteStats{
}

@end

//============== Stats only
@implementation AboutTests
- (void)setUp {
    TwoWayZ0QCapi.setupSuite(__LINE__);
}

- (void)tearDown {
}

- (void)test2099StatsBegin {
}
@end

@implementation ZuluTests
- (void)setUp {
}

- (void)tearDown {
    TwoWayZ0QCapi.teardownSuite(__LINE__);
}
- (void)test9999SuiteStats {
}
- (void)test9999ZuluStats {
}
@end

/*
@implementation TwoWayZ0SafeSizeTests

- (void)setUp {
    TwoWayZ0QCapi.setupSet1(__LINE__);
}

- (void)tearDown {
    TwoWayZ0QCapi.teardownSet1(__LINE__);
}



- (void)test2099SafeSize {
    if(TwoWayZ0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(TwoWayZ0QCapi.doSet1SizeSafe(__LINE__)){
           XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TwoWayZ0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}

@end


@implementation TwoWayZ0BasicTests

- (void)setUp {
    TwoWayZ0QCapi.setupSet2(__LINE__);
}

- (void)tearDown {
    TwoWayZ0QCapi.teardownSet2(__LINE__);
}


- (void)test2099Basics {
    if(TwoWayZ0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        
        if(TwoWayZ0QCapi.doSet2Basics(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TwoWayZ0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}

@end


@implementation TwoWayZ0ExtraDemoTests

- (void)setUp {
    TwoWayZ0QCapi.setupSet3(__LINE__);
}

- (void)tearDown {
    TwoWayZ0QCapi.teardownSet3(__LINE__);
}


- (void)test2099ExtraDemo {
    if(TwoWayZ0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        
        if(TwoWayZ0QCapi.doSet3ExtraDemo(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TwoWayZ0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}

@end


@implementation TwoWayZ0PerformanceTests

- (void)setUp {
    TwoWayZ0QCapi.setupSet4(__LINE__);
}

- (void)tearDown {
    TwoWayZ0QCapi.teardownSet4(__LINE__);
}


- (void)test2099Performance {
    if(TwoWayZ0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        
        if(TwoWayZ0QCapi.doSet4Performance(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TwoWayZ0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}

@end
*/
// END TwoWayZ0XCTests.m
/**
 *
 */
