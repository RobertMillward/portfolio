//
//  CommaSepO3.h
//
//  Created by Robert Russell Millward  on 9/26/13.
//  Copyright (c) 2013 Robert Russell Millward.  All rights reserved.
//
#ifndef CommaSepO3_h
#define CommaSepO3_h
// os
#include <stdio.h>
// helper and service api's
#include "TransactionO3.h"
//#include "InitDestroyHelperO0.h"
// data plans
#include "ArchitectureZ0Plan.h"

#define COMMASEP_PATH "Downloads/Sources/Databases"




#pragma mark - The commaSep as an instance
/**
 * Instance data.
 */
typedef struct CommaSepO3SInstanceDataStruct
{
    /**
     * Not yet open or open for writing else open for reading.
     */
    char* isOpenForWrite;
    // If KNOW_NO_ARC or KNOW_YES_ARC (i.e, isConsistent())
    // then the following instance variables
    // should be consistent.
    Schr openMode[4]; // "r" only, not "w", or "a" and can include "+" and or "x"
    
    
    Sint operations;
    Zint warnings;
    Zint errors;
    Ulng fileSizeAtOpen;
    /**
     * Overhead variables.
     */
    //PermissionO0IPT permissionP;
    gpVersionLevelZ0PT flagsForCodeVersionAndLevelP;
    FILE *cstream;
    
}CommaSepO3SIdataT, *CommaSepO3SIdataPT;


/**
 * Instance methods.
 * Other methods may refer to these through the extern immediately below.
 */
typedef struct CommaSepO3ServiceInstanceApiStruct
{
    /**
     *
     */
    void (* close)(CommaSepO3SIdataPT dataP);
    /**
     *
     */
    void (* openRead)(fileNmPT file, CommaSepO3SIdataPT dataP);
    /**
     *
     */
    void (* read)(int length, char *buffer, CommaSepO3SIdataPT dataP);
    /**
     *
     */
    Sint (* isAtEof)(CommaSepO3SIdataPT dataP);
    
}CommaSepO3SIapiT, *CommaSepO3SIapiPT;

extern CommaSepO3SIapiT CommaSepO3SIapi;



typedef struct CommaSepO3InstanceStruct // (both data and methods)
{
    CommaSepO3SIapiPT apiP;
    CommaSepO3SIdataT data;
    
} CommaSepO3SIthisT, *CommaSepO3SIthisPT;
#define CommaSepIT CommaSepO3IT
#define CommaSepIPT CommaSepO3IPT



#pragma mark - init and destroy.


typedef struct CommaSepsInitO3Y
{
    /**
     * Copy the base path into the commaSep system.
     * If path is null or ""
     * then "." is used for the path;
     * The path is not checked for existing because
     * existing now does not guarantee existing later.\
     * Runs successfully only before calling init().
     */
    void (* initPath)(pathPT path, gpTxPplGrpBatchTwoWayZ0PT info);

    
}CommaSepsInitO3X, *CommaSepsInitO3XP;

#define CommaSepsInitXP CommaSepsInitO3XP
#define CommaSepsInitX CommaSepsInitO3X
#define CommaSepsInitC CommaSepsInitO3C
extern CommaSepsInitX CommaSepsInitO3C;

/**
 *
 * Note: destroy is done with InitDestroyHelper.destroyAll().
 */
#define initCommaSeps initCommaSepsO3
extern initStatusT initCommaSeps(gpTxPplGrpBatchTwoWayZ0PT info);

#pragma mark - New CommaSep instance.

#define newCommaSep newCommaSepO3
extern CommaSepO3SIthisT newCommaSep(void/*PermissionO0IPT permissionP*/);

#endif  // CommaSepO3_h
/**
 *
 */
