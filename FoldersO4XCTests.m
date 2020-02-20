//
//  FoldersO4XCTests.m
//
//  Created by Robert Russell Millward on 10/16/13.
//  Copyright (c) 2020 Robert Russell Millward. All rights reserved.
//
// os
#import <XCTest/XCTest.h>
#import "FoldersO4TestAid.h"
//#import "TestAidZ0.h" // until the fetch can be eliminated

/**
 * Alphabetical list of tests batches.
 */
@interface FoldersO4AboutTests : XCTestCase
@end

@interface FoldersO4ExistsSet1Tests : XCTestCase
@end

@interface FoldersO4GetInfoSet2Tests : XCTestCase
@end

@interface FoldersO4ChangeSet3Tests : XCTestCase
@end

@interface FoldersO4ZooTests : XCTestCase
@end





@implementation FoldersO4ExistsSet1Tests

- (void)setUp
{
    FoldersO4QCapi.setupExistsSet1(__LINE__);
}

- (void)tearDown
{
    FoldersO4QCapi.teardownExistsSet1(__LINE__);
}

-(void) test2019GetExistsYes
{
    if(FoldersO4QCapi.isScheduled(__FUNCTION__, __LINE__)){
        bool ewc = FoldersO4QCapi.doExistsSet1(__LINE__);
        if(ewc){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:FoldersO4QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}

@end

@implementation FoldersO4GetInfoSet2Tests

- (void)setUp
{
    FoldersO4QCapi.setupGetInfoSet2(__LINE__);
}

- (void)tearDown
{
    FoldersO4QCapi.teardownGetInfoSet2(__LINE__);
}
-(void) test2019GetInfoThatExists
{
    if(FoldersO4QCapi.isScheduled(__FUNCTION__, __LINE__)){
        bool ewc = FoldersO4QCapi.doGetInfoSet2(__LINE__);;
        if(ewc){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:FoldersO4QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}
@end

@implementation FoldersO4ChangeSet3Tests

- (void)setUp
{
    FoldersO4QCapi.setupChangeSet3(__LINE__);
}

- (void)tearDown
{
    FoldersO4QCapi.teardownChangeSet3(__LINE__);
}
-(void) test2019DoChangeSet3
{
    if(FoldersO4QCapi.isScheduled(__FUNCTION__, __LINE__)){
        bool ewc = FoldersO4QCapi.doChangeSet3(__LINE__);;
        if(ewc){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:FoldersO4QCapi.getAssertText(__FUNCTION__, __LINE__)]);
        }
    }
}
@end



@implementation FoldersO4AboutTests

- (void)setUp
{
    FoldersO4QCapi.setupSuite(__LINE__);
}

- (void)tearDown
{
    // No teardown for suite
}
@end


@implementation FoldersO4ZooTests
- (void)setUp
{
    // No initialization for Zoo (suite)
}

- (void)tearDown
{
    FoldersO4QCapi.teardownSuite(__LINE__);
    //TestAidC.processSuiteStats();
}

@end // FoldersO4XCTests.m
/**
 *
 */
