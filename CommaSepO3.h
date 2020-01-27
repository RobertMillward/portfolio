//
//  CommaSepO3.h
//
//  Created by Robert Russell Millward
//  on 9/26/13.
//  Copyright (c) 2013 Robert Russell Millward.
//  All rights reserved.
//
/**
 * Special parameters notes for this package:
 * - uses no memory so does not need group size information, does use Id
 * - DOES transaction trace logging so does use the transaction Id (probably TRAN_IX) and isBatch information
 * - may have versions using inheritance so has version and level information
 */
#ifndef CommaSepO3_h
#define CommaSepO3_h
#include <stdio.h>
#include "ArchitectureO0.h"
#include "TransactionO3.h"
#include "InitDestroyHelperO0.h"

#define COMMASEP_PATH "Downloads/Sources/Databases"




#pragma mark - The commaSep as an instance
/**
 * Instance data.
 */
typedef struct CommaSepO3toInstanceDataStruct
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
    PermissionO0IPT permissionP;
    gpVersionLevelO0PT flagsForCodeVersionAndLevelP;
    FILE *cstream;
    
}CommaSepO3toIT, *CommaSepO3toIPT;


/**
 * Instance methods.
 * Other methods may refer to these through the extern immediately below.
 */
typedef struct CommaSepO3goInstanceMethodsStruct
{
    /**
     *
     */
    void (* close)(CommaSepO3toIPT dataP);
    /**
     *
     */
    void (* openRead)(fileNmPT file, CommaSepO3toIPT dataP);
    /**
     *
     */
    void (* read)(int length, char *buffer, CommaSepO3toIPT dataP);
    /**
     *
     */
    Sint (* isAtEof)(CommaSepO3toIPT dataP);
    
}CommaSepO3goIT, *CommaSepO3goIPT;

extern CommaSepO3goIT CommaSepO3go;



typedef struct CommaSepO3InstanceStruct // (both data and methods)
{
    CommaSepO3goIPT go;
    CommaSepO3toIT to;
    
} CommaSepO3IT, *CommaSepO3IPT;
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
    void (* initPath)(pathPT path, gpTxPplGrpBatchTwoWayO0PT info);

    
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
extern initStatusT initCommaSeps(gpTxPplGrpBatchTwoWayO0PT info);

#pragma mark - New CommaSep instance.

#define newCommaSep newCommaSepO3
extern CommaSepIT newCommaSep(PermissionO0IPT permissionP);

#endif  // CommaSepO3.h
