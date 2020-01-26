//
//  TestAidZ0.h
//
//  Created by Robert Russell Millward on 11/29/13.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
/**
 * Do include this ".c" in the app compile otherwise the .h files are not available.
 * See ArchitectureZ0.h for an explanation of the naming of Object typedef parts.
 */
#ifndef TestAidZ0_h
#define TestAidZ0_h
// api
// data
#include "ArchitectureZ0Plan.h"
/*
 */
#pragma mark - class data.
/*
 */
/**
 * Some reliable options to creating your own for testing.
 */
typedef struct TestAidZ0QualityClassDataStructure
{
    gpTxPplGrpBatchTwoWayZ0T twoWay;
    bool showFunctionName;
}TestAidZ0QCdataT, *TestAidZ0QCdataPT;
extern TestAidZ0QCdataT TestAidZ0QCdata;


#define GOOD_LOGIN_PPLGRP "BOEINGZ"

#define GOOD_PERSON_PPLG "RRMZZZZ"


///*
// */
//#pragma mark - The instance
///*
// */
//typedef struct TestAidZ0QualityInstanceDataStruct // TODO delete
//{
//    /**
//     * General information.
//     */
//    
//    /**
//     * Generated information.
//     */
//    
//    /**
//     * Overhead variables.
//     */
//    gpTxPplGrpBatchTwoWayZ0PT flagsForTxSizeBatchP;
//    gpVersionLevelZ0PT flagsForCodeVersionAndLevelP;
//    
//}TestAidZ0QIdataIT, *TestAidZ0QIdataIPT;
//
//
///**
// * Instance methods.
// * Other methods may refer to these through the extern immediately below.
// */
//typedef struct TestAidZ0QualityInstanceApiStruct
//{
//    /**
//     * Generate signature code from data so far.
//     */
//    void (* generateSignatureCode)(TestAidZ0QIdataIPT dataP);
//    
//}TestAidZ0QIapiT, *TestAidZ0QIapiPT;
//
//extern TestAidZ0QIapiT TestAidZ0QIapi; // For easy non instance reference
//
//
//
//typedef struct TestAidZ0QIapinstanceStruct // (both data and methods from new)
//{
//    TestAidZ0QIapiPT api;
//    TestAidZ0QIdataIT data;
//    
//} TestAidZ0QInewT, *TestAidZ0QInewPT;
//#define TestAidQIT TestAidZ0QInewT
//#define TestAidQIPT TestAidZ0QInewPT

/*
 */
#pragma mark - Class Methods
/*
 */
/**
 * A assert result has the format: // assert=w91=x-[HashBasicsZ0Tests test2015Asample]=a2=eNE=f0=g
 * where:
 * w[hat]   = assert
 * [inde]x  = the line number
 * a[bout]  = -[file func]
 * e[xpect] = the expected value
 * g[ot]    = what actually occured
 * f[or]    = EQ or NE test
 */


/**
 * How many years to run a test before it expires.
 */
#define TA_FOR_YRS 400 // 4 years, 0 months

typedef char    *expectCharPT;
typedef char    *actualCharPT;
typedef int     expectIntT;
typedef int     actualIntT;
typedef const char *funcNamePT;
#define TA_NULL "(NULL)"

/**
 * TestAid description
 */
typedef struct TestAidZ0ClassMethodStructure
{
    void (*basicInit)(void);
    void (*nextTx)(void);
    bool (*isScheduled)(funcNamePT funcName,
                        bool showFunc);
#define TRM_SHOWFUNC true
#define TRM_HIDEFUNC false
    
    Sint (*putTestInts)(
            expectIntT expect,
            actualIntT got,
            lineNbrT lineNbr);
    Sint (*putTestChars)(
            expectCharPT expect,
            actualCharPT got,
            lineNbrT lineNbr);
    void (*getCounts)(void);
    //void (*processSuiteStats)(void);
    char *(*getAssertText)(funcNamePT testName);
    //char *(*getTraceText)(void);
    //void (*dumpTrace)(void);
    //void (*clearTrace)(void);
    
}TestAidZ0QCapiT, *TestAidZ0QCapiPT;

#define TestAidQCapiT TestAidZ0QCapiT
#define TestAidQCapi TestAidZ0QCapi
extern TestAidQCapiT TestAidQCapi;

#define TestAidC TestAidZ0QCapi // temporary

// If a shorter call name will clarify code.
#define TA0C TestAidZ0QCapi
#define intV putTestInts
#define chrV putTestChars


#endif
