//
//  UserGroupO2.h
//
//  Created by Robert R on 11/3/14.
//  Copyright (c) 2014 Robert Russell Millward.
//  All rights reserved.
//
/**
* Special parameters notes for this package:
* - uses no memory so does not need group size and Id information
* - DOES transaction trace logging so does use the transaction Id (probably TRAN_IX) and isBatch information
* - may have versions using inheritance so has version and level information
*/
/**
 * This is very incomplete.
 * Group has special rules :
 * - normally there is only the default group
 * - groups can share data if allowed at init
 * A user group is the collection of users that support a particular community process.
 */

#ifndef __UserGroupO2__
#define __UserGroupO2__
#include "ArchitectureZ0.h"
#include "PeopleGroupO0.h"

#define GRP_DEFAULT 0


/**
 * This will eventually fill out to a new-able structure.
 */
/*
extern peopleGroupT newPeopleGroupO2(
        char *groupID,
        char *schemaDate,
        bool canShare); // ...with other designated groups.
 
    gpTransactionSizeO0PT flagsForTxSizeBatchP;
    gpVersionLevelO0PT flagsForCodeVersionAndLevelP;
#define newPeopleGroup newPeopleGroupO2

extern char *initPeopleGroupO2(void);
#define initPeopleGroup initPeopleGroupO2
 */
#endif /* defined(__PeopleGroupO2__) */
