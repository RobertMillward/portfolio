//
//  ArchitectureTwoWayZ0.h - all of the two-way (inout) variables
//
//  Created by Robert R on 3/27/2019.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef ArchitectureTwoWayZ0_h
#define ArchitectureTwoWayZ0_h

/**
 * A way to communicate version information between owner and creator of an instance.
 * This is handled bidirectionally or two way. The first creator on the way in fills it in
 * and the final creator on the way out fills it in.
 *
 * Behavior modifier that allows inheriting code to be supported as needed by older code versions.
 * Every creator in the call stack will load its value on the way out. Only the first creator in the
 * call stack will load this information on the way in. The owner will zero the pointer then the
 * first creator will know to fill it in on the way in.
 */
typedef struct gpVersionLevelZ0S
{
    Zchr callerSeesVersion;
    Zchr callerSeesLevel;
} gpVersionLevelZ0T, *gpVersionLevelZ0PT, **gpVersionLevelZ0PPT;

typedef struct VersionLevelZ0HelperClassApiStruct
{
    /**
     * Application initializes the structure
     */
    void (*clearByApp)(gpVersionLevelZ0PPT);
    /**
     * First downward function sets the structure
     */
    void (*firstDownWins)(gpVersionLevelZ0PPT, cfuncNameT);
    /**
     * Final downward function defaults the structure
     */
    void (*finalDownDefaults)(gpVersionLevelZ0PPT, cfuncNameT);
    /**
     * Each upward call set the structure
     */
    void (*eachUpwardSet)(gpVersionLevelZ0PPT, cfuncNameT);
    
}VersionLevelZ0HCapiT, *VersionLeveZ0lHCapiPT;

#define VersionLevelHCapiT VersionLevelZ0HCapiT
#define VersionLevelHCapi VersionLevelZ0HCapi
extern VersionLevelHCapiT VersionLevelHCapi;


/**
 * This two way status is designed to allow functions to see if a failure is a loggable error
 * and to return a symbolic result thus making C debugging more visual.
 * For example, for opening a file which must be present "Don't know" would be passed in
 * whereas for opening a file which might be present "Maybe" would be passed in.
 * In either case "No" or "Yes" would be returned, but with "Maybe" no error would be logged.
 * Every function that uses this must set an initial value (1.Don't know/2.Maybe) or "0.Don't care"
 * using MustWork(), MustFail(), or MayWork().
 */
typedef char* twoWayStatusPT;

#define DONT_CARE_ARC   "0.Don't care"  // skip return processing
#define DONT_KNOW_ARC   "1.Don't know"  // don't know but I want it to succeed so note errors
#define DONT_WANT_ARC   "2.Don't want"  // don't know but I want it to fail so don't note errors
#define KNOW_MAYBE_ARC  "3.Maybe"       // don't note any errors but do send result
#define KNOW_NULL_ARC   "4.Null"        // one of these three is returned for Don't know or Maybe
#define KNOW_NO_ARC     "5.No/Bad"      //
#define KNOW_YES_ARC    "6.Yes/Good"

typedef struct TwoWayZ0HelperClassApiStruct
{
    /**
     * Starting at 0.Don't care will end up at 0.Don't care
     * and no tracking will be done.
     */
    void (* setDoNotCare)(twoWayStatusPT*);
    
    /**
     * Starting at MustWork to be successful will cause error logging on
     * failures and notification of No/Bad, otherwise Yes/Good.
     */
    void (* setMustWork)(twoWayStatusPT*);
    
    /**
     * Starting at MustFail to be successful will cause no error logging on
     * failures and notification of No/Bad, otherwise Yes/Good.
     */
    void (* setMustFail)(twoWayStatusPT*);
    
    /**
     * Starting at MayWork will avoid error logging on failures
     * and allow a notification of Yes/Good regardless of any failures.
     */
    void (* setMayWork)(twoWayStatusPT*);
    
    /**
     * Change the status to Null if it didn't start at Don't care
     * and status can not be determined.
     */
    void (* setNull)(twoWayStatusPT*);
    
    /**
     * Change the status to Yes/Good if it was preceeded by setMustFail()
     * or to No/Bad if it was preceed by setMustWork().
     */
    void (* noteFailure)(twoWayStatusPT*);
    
    /**
     * Change the status to Yes/Good if it was preceeded by setMustWork()
     * or to No/Bad if it was preceed by setMustFail().
     */
    void (* noteSuccess)(twoWayStatusPT*);
    
}TwoWayZ0HCapiT, *TwoWayZ0HCapiPT;

#define TwoWayHCapiT TwoWayZ0HCapiT
#define TwoWayHCapi TwoWayZ0HCapi
extern TwoWayHCapiT TwoWayHCapi;


typedef bool isBatchT;

typedef struct gpTxPplGrpBatchTwoWayZ0Struct
{
    twoWayStatusPT twoWayStatusP;
    isBatchT isBatch;
    tranIxT transactionIx; 
    pplGrpSizeT peopleGroupSize;
    Zint groupBaseYear;
} gpTxPplGrpBatchTwoWayZ0T, *gpTxPplGrpBatchTwoWayZ0PT;


/**
 * Some general purpose structures to pass bits of data around.
 * Initialize versionLevelP with VersionLevelACapi.clearByApp()
 */
#pragma mark -- General purpose argument and return structures.

typedef struct gpSllgChar32StructureT
{
    gpVersionLevelZ0PT versionLevelP;
    gpTxPplGrpBatchTwoWayZ0PT twoWayP;
    Sllg theLongValue;
    char theCharValue[16 * 2];
} gpSllgChar32T, *gpSllgChar32PT;

typedef struct gpUllgChar32StructureT
{
    gpVersionLevelZ0PT versionLevelP;
    gpTxPplGrpBatchTwoWayZ0PT twoWayP;
    Ullg theLongValue;
    char theCharValue[16 * 2];
} gpUllgChar32T, *gpUllgChar32PT;


typedef struct gpSllgChar64StructureT
{
    gpVersionLevelZ0PT versionLevelP;
    gpTxPplGrpBatchTwoWayZ0PT twoWayP;
    Sllg theLongValue;
    char theCharValue[16 * 4];
} gpSllgChar64T, *gpSllgChar64PT;

typedef struct gpUllgChar64StructureT
{
    gpVersionLevelZ0PT versionLevelP;
    gpTxPplGrpBatchTwoWayZ0PT twoWayP;
    Ullg theLongValue;
    char theCharValue[16 * 4];
} gpUllgChar64T, *gpUllgChar64PT;


#endif /* defined(ArchitectureTwoWayZ0.h */
/**
 * This file is so small that including it completely here is easier than splitting
 * it into essence and non-essence.
 */




