//
//  TwoWayO0.h
//
//  Created by Robert R on 3/27/2019.
//  Copyright (c) 2015 Robert Russell Millward.
//  All rights reserved.
//
/**
 *
 */
#ifndef __TwoWayO0__
#define __TwoWayO0__
//#include <stdio.h>
//#include <libc.h>
//#include <string.h>
//#include <strings.h>
//#include "ArchitectureO0.h"
//#include "TransactionO0.h"
//#include "PermissionO0.h"
/*
 */
#pragma mark - class data.
/*
 */
extern ErrorWarnCountT twoWayO0Counts;

/*
 */
#pragma mark - init and destroy.
/*
 */

// none

/*
 */
#pragma mark - instance data
/*
 */

// none


/**
 * Instance methods.
 * Other methods may refer to these through the extern immediately below.
 */

// none

/*
 */
#pragma mark - Class Methods
/*
 */

/**
 * This two way status is designed to allow methods to see if a failure is a loggable error
 * and to return a symbolic result thus making C debugging more visual.
 * For example, for opening a file which must be present "Don't know" would be passed in
 * where for opening a file which might be present "Maybe" would be passed in.
 * In either case "No" or "Yes" would be returned, but with "Maybe" no error would be logged.
 * Every function that uses this must set an initial value (1.Don't know/2.Maybe) or "0.Don't care".
 */
typedef char* twoWayStatusPT;

#define DONT_CARE_ARC   "0.Don't care"  // skip return processing
#define DONT_KNOW_ARC   "1.Don't know"  // don't know but I want it to succeed so note errors
#define KNOW_MAYBE_ARC  "2.Maybe"       // don't note any errors but do send result
#define KNOW_NULL_ARC   "3.Null"        // one of these three is returned for Don't know or Maybe
#define KNOW_NO_ARC     "4.No/Bad"      //
#define KNOW_YES_ARC    "5.Yes/Good"

typedef struct TwoWayO0AppClassApiStruct
{
    /**
     * Starting at 0.Don't care will end up at 0.Don't care
     * and no tracking will be done.
     */
    void (* setDoNotCare)(twoWayStatusPT*);
    /**
     * Starting at must work will cause error logging on failures
     * and notification of 4.No/Bad, otherwise 5.Yes/Good.
     */
    void (* setMustWork)(twoWayStatusPT*);
    /**
     * Starting at 2.May work will avoid error logging on failures
     * and allow a notification of 5.Yes/Good regardless of any failures.
     */
    void (* setMayWork)(twoWayStatusPT*);
    /**
     * Change the status to 3.Null if it didn't start at 0.Don't care
     * and status can not be determined.
     */
    void (* setNull)(twoWayStatusPT*);
    /**
     * Change the status to 4.No/Bad if it didn't start at 0.Don't care
     * and never got to 3.Null along the way.
     */
    void (* setFailure)(twoWayStatusPT*);
    /**
     * Change the status to 5.Yes/Good if it isn't 0.Dont care or
     * 3.Null or 4.No/Bad.
     */
    void (* setSuccess)(twoWayStatusPT*);
    
}TwoWayO0ACapiT, *TwoWayO0ACapiPT;

#define TwoWayACapiT TwoWayO0ACapiT
#define TwoWayACapi TwoWayO0ACapi
extern TwoWayACapiT TwoWayACapi;

typedef struct gpTxPplGrpBatchTwoWayO0Struct
{
    twoWayStatusPT twoWayStatusP;
    bool isBatch;
    Usht transactionIx;
    Usht peopleGroupSize;
} gpTxPplGrpBatchTwoWayO0T, *gpTxPplGrpBatchTwoWayO0PT;

//extern void setRationalTwoWayStatusO0(char **twoWay); // currently in PersonO0.c

#pragma mark -- General purpose argument and return structures.

typedef struct gpSllgCharArrayStructureT
{
    gpVersionLevelO0PT versionLevelP;  // Initialize with NO_ARG_PTR_ARC
    gpTxPplGrpBatchTwoWayO0PT twoWayP; // Initialize from caller's argument.
    Sllg theLongValue;
    char theCharValue[16 * 2];
} gpSllgCharArrayT, *gpSllgCharArrayPT;

typedef struct gpUllgCharArrayStructureT
{
    gpVersionLevelO0PT versionLevelP;  // Initialize with NO_ARG_PTR_ARC
    gpTxPplGrpBatchTwoWayO0PT twoWayP; // Initialize from caller's transaction.
    Ullg theLongValue;
    char theCharValue[16 * 2];
} gpUllgCharArrayT, *gpUllgCharArrayPT;

typedef struct gpCharArray32StructureT
{
    gpVersionLevelO0PT versionLevelP;  // Initialize with NO_ARG_PTR_ARC
    gpTxPplGrpBatchTwoWayO0PT twoWayP; // Initialize from caller's transaction.
    char theCharValue[16 * 2];
} gpCharArray32T, *gpCharArray32PT;

/*
 */
#pragma mark - New instance
/*
 */

// none

#endif /* defined(__TwoWayO0__) */
