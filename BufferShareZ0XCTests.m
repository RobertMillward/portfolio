//
//  BufferShareZ0XCTests.m
//
//  Created by Robert R on 3/27/15.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
// os
#import <XCTest/XCTest.h>
// quality
#import "TestAidZ0.h"
#import "BufferShareZ0TestAid.h"


@interface BufferShareO0AboutTests : XCTestCase
@end

@interface BufferShareO0CreateDestroyTests : XCTestCase
@end

@interface BufferShareO0ExampleTests : XCTestCase
@end

@interface BufferShareO0IsMoreDescriptionSizesTests : XCTestCase
@end

@interface BufferShareO0ZooTests : XCTestCase
@end


@implementation BufferShareO0ExampleTests

- (void)setUp {
    //BufferShareO0QCapi.setupCreateDestroy(__LINE__);
}

- (void)tearDown {
    //BufferShareO0QCapi.teardownCreateDestroy(__LINE__);
}

- (void)test2019ExampleProcessCSV {
    if(BufferShareO0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(BufferShareO0QCapi.doSet3(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:BufferShareO0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}


- (void)test2019ExampleProcessRow {
    if(BufferShareO0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(BufferShareO0QCapi.doSet4(__LINE__)){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:BufferShareO0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}

@end


@implementation BufferShareO0IsMoreDescriptionSizesTests

- (void)setUp {
    BufferShareO0QCapi.setupIsMoreDescriptionSizes(__LINE__);
}

- (void)tearDown {
    BufferShareO0QCapi.teardownIsMoreDescriptionSizes(__LINE__);
}


- (void)test2019IsMoreDescriptionSizes {
    if(BufferShareO0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(BufferShareO0QCapi.doIsMoreDescriptionSizes(__LINE__))
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:BufferShareO0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}

@end


@implementation BufferShareO0CreateDestroyTests

- (void)setUp {
    BufferShareO0QCapi.setupCreateDestroy(__LINE__);
}

- (void)tearDown {
    BufferShareO0QCapi.teardownCreateDestroy(__LINE__);
}

- (void)test2019CreateDestroy {
    if(BufferShareO0QCapi.isScheduled(__FUNCTION__, __LINE__)){
        if(BufferShareO0QCapi.doCreateDestroy(__LINE__))
        {
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:BufferShareO0QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}
@end


@implementation BufferShareO0AboutTests

- (void)setUp {
    BufferShareO0QCapi.setupSuite(__LINE__);
}

- (void)tearDown {
}

@end


@implementation BufferShareO0ZooTests

- (void)setUp {
}

- (void)tearDown {
    BufferShareO0QCapi.teardownSuite(__LINE__);
}

@end
/**
 *
 */
