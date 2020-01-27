//
//  JournalO3.h
//
//  Created by Robert Russell Millward on 9/26/13.
//  Copyright (c) 2019 Robert Russell Millward.  All rights reserved.
//

#ifndef JournalO3_h
#define JournalO3_h
#include <stdio.h>
// api
//#include "PermissionO0.h"
//#include "InitDestroyHelperO0.h"
// data
//#include "ArchitectureZ0.h"
#include "TransactionZ0Plan.h"
#include "JournalZ3Plan.h"
/*
 */
#pragma mark - class data.
/*
 */

/*
 */
#pragma mark - init and destroy.
/*
 */
/**
 * Copy the base path into the journal system.
 * If path is null or ""
 * then "." is used for the path;
 * The path is not checked for existing because
 * existing now does not guarantee existing later.
 * Runs successfully only before calling init().
 */
extern void initJournalsPathO3(pathPT path, gpTxPplGrpBatchTwoWayZ0PT info);

/**
 *
 * Note: destroy is done with InitDestroyHelper.destroyAll().
 */
//extern initStatusT initJournalsO3(gpTxPplGrpBatchTwoWayZ0PT info);

/*
 */
#pragma mark - The instance
/*
 */
//typedef struct JournalO3ApplicationInstanceDataStruct
//{
//    gpTxPplGrpBatchTwoWayO0PT flagsForTxSizeBatchP;
//    gpVersionLevelO0PT flagsForCodeVersionAndLevelP;
//    /**
//     * Not yet open or open for writing else open for reading.
//     */
//    char* isOpenForWrite;
//    // If KNOW_NO_ARC or KNOW_YES_ARC (i.e, isConsistent())
//    // then the following instance variables
//    // should be consistent.
//    Schr openMode[4]; // "r", "w", or "a" and can include "+" and or "x"
//    
//    
//    Sint operations;
//    Zint warnings;
//    Zint errors;
//    Ulng fileSizeAtOpen;
//    Ulng fileSizeAtClose;
//    /**
//     * Overhead variables.
//     */
//    PermissionO0dataIPT permissionP;
//    gpVersionLevelO0PT flagsForCodeVersionAndLevelP;
//    FILE *jstream;
//    Sint gotc;
//    Schr flags; // not actually used at this point.
//    
//}JournalZ3AIdataT, *JournalZ3AIdataPT;
/**
 * Instance methods.
 */
typedef struct JournalO3ApplicationInstanceApiStruct
{
    /**
     *
     */
    void (* close)(JournalZ3AIdataPT);
    /**
     *
     * Note: otherwise it will append.
     */
    void (* setTruncateOnOpenWrite)(JournalZ3AIdataPT);
    /**
     *
     */
    void (* openWrite)(JournalZ3AIdataPT, fileNmPT file);
    /**
     *
     */
    void (* openRead)(JournalZ3AIdataPT, fileNmPT file);
    
    /**
     *
     */
    void (* read)(JournalZ3AIdataPT, targetPT);
    /**
     * Write journal row.
     */
    void (* write)(JournalZ3AIdataPT, sourcePT);
    /**
     * 
     */
    char* (* isConsistent)(JournalZ3AIdataPT);
    /**
     *
     */
    Sint (* isAtEOF)(JournalZ3AIdataPT);
    
} JournalO3AIapiT, *JournalO3AIapiPT;

#define JournalAIapiT  JournalO3AIapiT
#define JournalAIapiPT JournalO3AIapiPT
extern JournalO3AIapiT JournalO3AIapi;

typedef struct JournalO3ApplicationInstanceNewStruct // (both data and methods)
{
    JournalO3AIapiPT apiP;
    JournalZ3AIdataT data;
    
} JournalO3AInewT, *JournalO3AInewPT;
#define JournalAInewT JournalO3AInewT
#define JournalAInewPT JournalO3AInewPT


/*
 */
#pragma mark - New instance
/*
 */

#define newJournal newJournalO3
extern JournalO3AInewT newJournal(PermissionZ0AIdataPT permissionP);

#endif
/**
 */
