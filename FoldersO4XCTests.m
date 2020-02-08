//
//  FoldersO4XCTests.m
//
//  Created by Robert Russell Millward on 10/16/13.
//  Copyright (c) 2020 Robert Russell Millward. All rights reserved.
//
// os
#import <XCTest/XCTest.h>
#import "FoldersO4TestAid.h"
#import "TestAidZ0.h" // until the fetch can be eliminated

/**
 * Alphabetical list of tests batches.
 */
@interface FoldersO4AboutTests : XCTestCase
@end

@interface FoldersO4Set1Tests : XCTestCase
@end

@interface FoldersO4Set2Tests : XCTestCase
@end

@interface FoldersO4Set3Tests : XCTestCase
@end

@interface FoldersO4ZooTests : XCTestCase
@end





@implementation FoldersO4Set1Tests

- (void)setUp
{
    FoldersO4QCapi.setupSet1();
}

- (void)tearDown
{
    FoldersO4QCapi.teardownSet1();
}

-(void) test2019GetExistsYes
{
    if(FoldersO4QCapi.isScheduled(__FUNCTION__)){
        bool ewc = FoldersO4QCapi.doSet1(__LINE__);
        if(ewc){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}

@end

@implementation FoldersO4Set2Tests

- (void)setUp
{
    FoldersO4QCapi.setupSet2();
}

- (void)tearDown
{
    FoldersO4QCapi.teardownSet2();
}
-(void) test2019GetFolderInfoThatExists
{
    if(FoldersO4QCapi.isScheduled(__FUNCTION__)){
        bool ewc = FoldersO4QCapi.doSet2(__LINE__);;
        if(ewc){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}
@end

@implementation FoldersO4Set3Tests

- (void)setUp
{
    FoldersO4QCapi.setupSet2();
}

- (void)tearDown
{
    FoldersO4QCapi.teardownSet2();
}
-(void) test2019GetFolderInfoThatExists
{
    if(FoldersO4QCapi.isScheduled(__FUNCTION__)){
        bool ewc = FoldersO4QCapi.doSet3(__LINE__);;
        if(ewc){
            XCTAssert(NO, @"%@", [[NSString alloc] initWithUTF8String:TestAidC.getAssertText(__FUNCTION__)]);
        }
    }
}
@end



@implementation FoldersO4AboutTests

- (void)setUp
{
    FoldersO4QCapi.setupSuite0(__LINE__);
}

- (void)tearDown
{
}
@end


@implementation FoldersO4ZooTests
- (void)setUp
{
}

- (void)tearDown
{
    FoldersO4QCapi.teardownSuite0(__LINE__);
    //TestAidC.processSuiteStats();
}

@end // FoldersO4XCTests.m
/**
 *
 */
