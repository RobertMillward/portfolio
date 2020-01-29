//
//  PeopleGroupO2.h
//
//  Created by Robert R on 11/3/14.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef PeopleGroupO2_h
#define PeopleGroupO2_h
// os
// data plans
#include "ArchitectureZ0Plan.h"
// api's

#define GRP_DEFAULT 0


/**
 * This will eventually fill out to a new-able structure.
 */
/*
typedef struct PeopleGroupO2ApplicationInstanceDataStruct
 (
        char *groupID,
        char *schemaDate,
        bool canShare); // ...with other designated groups.
 
    gpTransactionSizeO0PT flagsForTxSizeBatchP;
    gpVersionLevelO0PT flagsForCodeVersionAndLevelP;
#define newPeopleGroup newPeopleGroupO2

extern char *initPeopleGroupO2(void);
#define initPeopleGroup initPeopleGroupO2
extern peopleGroupT PeopleGroupO2
 */
#endif /* defined(PeopleGroupO2_h) */
/**
* This is very incomplete.
* Group has special rules :
* - normally there is only the default group
* - groups can share data if allowed at init
* A user group is the collection of users that support a particular community process.
*/
