//
//  PeopleGroupO2.h
//
//  Created by Robert R on 11/3/14.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef PeopleGroupO2_h
#define PeopleGroupO2_h
// os
// helper api's
// data plans
#include "ArchitectureZ0Plan.h"
#include "PeopleGroupZ0Plan.h"
// application api's

//#define GRP_DEFAULT 0

typedef struct PeopleGroupO2ApplicationInstanceApiStructure
{
    
}PeopleGroupO2AIapiT, *PeopleGroupO2AIapiPT;

typedef struct PeopleGroupO2ApplicationInstanceNewStructure
{
    PeopleGroupO2AIapiPT apiP;
    PeopleGroupZ0AIdataT data;
    
}PeopleGroupO2AInewT, *PeopleGroupO2AInewPT;

#endif /* PeopleGroupO2_h */
/**
* This is very incomplete.
* Group has special rules :
* - normally there is only the default group
* - groups can share data if allowed at init
* A people group is the collection of users that support a particular community process.
*/
