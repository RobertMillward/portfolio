//
//  PeopleGroupO4.h
//
//  Created by Robert R on 11/3/14.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef PeopleGroupO4_h
#define PeopleGroupO4_h
// os
// helper api's
// data plans
#include "ArchitectureZ0Plan.h"
#include "PeopleGroupZ0Plan.h"
// application api's

//#define GRP_DEFAULT 0

typedef struct PeopleGroupO4ApplicationInstanceApiStructure
{
    
}PeopleGroupO4AIapiT, *PeopleGroupO4AIapiPT;

typedef struct PeopleGroupO4ApplicationInstanceNewStructure
{
    PeopleGroupO4AIapiPT apiP;
    PeopleGroupZ0AIdataT data;
    
}PeopleGroupO4AInewT, *PeopleGroupO4AInewPT;

#endif /* PeopleGroupO4_h */
/**
* This is very incomplete.
* Group has special rules :
* - normally there is only the default group
* - groups can share data if allowed at init
* A people group is the collection of users that support a particular community process.
*/
