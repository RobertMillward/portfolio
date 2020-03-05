//
//  TestAidZ0.h
//
//  Created by Robert Russell Millward on 11/29/13.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef TestAidZ0_h
#define TestAidZ0_h
// os
// helper api's
// data plans
#include "ArchitectureZ0Plan.h"
// application api's

/*
 */
#pragma mark - class data.
/*
 */
/**
 *
 * Initialize the basic testing environment.
 * Caller should spin on serial number if needed.
 */
typedef struct TestAidZ0QualityClassDataStructure
{
    bool                        showFunctionName;
    gpVersionLevelZ0T           vsnLvl;
    gpTxPplGrpBatchTwoWayZ0T    twoWay;
    gpSllgChar32T               gp32;
    gpSllgChar64T               gp64;
}TestAidZ0QCdataT, *TestAidZ0QCdataPT;
extern TestAidZ0QCdataT TestAidZ0QCdata;

/**
* Some test constants.
*/
#define TA_GOOD_LOGIN   "BOEING"
#define GOOD_PERSON_PPLG    "RRMZZZZ"
#define WIKIDB_REAL_APP     "WIKIDBA"
#define WIKIDB_SHARED_APP   "WIKIDBG"

#define TA_HOMPATH "." // See ArchitectureInit for overall home
//#define TA_GRPFLDR "foldersTest"
#define FOLDERS_TEST_PATH "foldersTest"
#define FOLDERS_TEST_DIR  "youFoundMe"

/*
 */
#pragma mark - Class Methods
/*
 */

/**
 * How many years to run a test before it expires.
 */
#define TA_FOR_YRS 400 // 4 years, 00 months


typedef char*   expectCharPT;
typedef char*   actualCharPT;
typedef char    expectCharT;
typedef char    actualCharT;
typedef int     expectIntT;
typedef int     actualIntT;
typedef const char *funcNamePT;
#define TA_NULL "(NULL)"

/**
 * TestAid description
 */
typedef struct TestAidZ0QualityClassApiStructure
{
    void (*basicInit)(void);
    void (*nextTx)(void);
    #define TRM_SHOWFUNC true
    #define TRM_HIDEFUNC false
    bool (*isScheduled)(funcNamePT, bool);
    /**
     * TestInts returns subtraction thus LT, GT, and EQ can be detected.
     */
    Sint (*putTestInts)(expectIntT,     actualIntT,     lineNbrT);
    Sint (*putTestChars)(expectCharPT,  actualCharPT,   lineNbrT);
    Sint (*putTestChar1)(expectCharT,   actualCharT,    lineNbrT);
    /**
     * Returns a pointer to the report of the count of tests and failures.
     */
    char*  (*getCounts)(void);
    /**
     * Returns a Row of the test results including EQ or NE as the violated condition.
      * A assert result has the format:  =wassert=x91=c3=a-[HashBasicsZ0Tests test2015Asample]=e2=fNE=g0
      * where:
      * w[hat]   = assert
      * [inde]x  = the line number
      * c[ount] = the number of failures so far
      * a[bout]  = -[file func]
      * e[xpect] = the expected value
      * g[ot]    = what actually occured
      * f[or]    = EQ or NE test
     */
    char* (*getAssertText)(funcNamePT testName);
    
}TestAidZ0QCapiT, *TestAidZ0QCapiPT;

#define TestAidQCapiT TestAidZ0QCapiT
#define TestAidQCapi TestAidZ0QCapi
extern TestAidQCapiT TestAidQCapi;

#define TestAidC TestAidZ0QCapi // temporary, diminishing as of 03Feb2020

// If a shorter call name will clarify code.
#define TA0C TestAidZ0QCapi
#define intV putTestInts
#define chrV putTestChars
#define ch1V putTestChar1


#endif // TestAidZ0_h
/**
* Do include this ".c" in the app compile otherwise the .h files are not available.
* See ArchitectureZ0.h for an explanation of the naming of Object typedef parts.
*/
