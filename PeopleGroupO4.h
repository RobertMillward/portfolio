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
#include "PeopleGroupZ0Plan.h"
#include "ArchitectureZ0Plan.h"
#include "RowZ0Plan.h"
// application api's


/*
 */
#pragma mark - instance api
/*
 */
typedef struct PeopleGroupO4ApplicationInstanceApiStructure
{
    //void    (*getSignature) (PeopleGroupZ0AIdataPT);
    //void    (*getNode)      (PeopleGroupZ0AIdataPT);
    //void    (*getGroupSize) (PeopleGroupZ0AIdataPT);
    
    void    (*hide)  (PeopleGroupZ0AIdataPT);
    void    (*unhide)(PeopleGroupZ0AIdataPT);
    void    (*save)  (PeopleGroupZ0AIdataPT);
    void    (*rowOf) (PeopleGroupZ0AIdataPT,
                      targetPT targetP, massOfT massOf,
                      indeXPT indeXP, whoZPT whoZP,
                      gpSllgChar64PT gp64P);
    
}PeopleGroupO4AIapiT, *PeopleGroupO4AIapiPT;

// extern PeopleGroupO4AIapiT PeopleGroupO4AIapi; // available through the instance.apiP

/*
 */
#pragma mark - New instance
/*
 */
typedef struct PeopleGroupO4ApplicationInstanceNewStructure
{
    PeopleGroupO4AIapiPT apiP;
    PeopleGroupZ0AIdataT data;
    
}PeopleGroupO4AInewT, *PeopleGroupO4AInewPT;


/*
 */
#pragma mark - Class Api
/*
 */
typedef struct PeopleGroupO4ApplicationClassApiStructure
{
    /**
     *
     */
    PeopleGroupO4AInewT (*fromRow)(abstractRowT);
    /**
     *
     */
    PeopleGroupO4AInewT (*fromFields)(personIdT, gpSllgChar64PT);
    
}PeopleGroupO4ACapiT, *PeopleGroupO4ACapiPT;
#define PeopleGroupACapiT PeopleGroupO4ACapiT
#define PeopleGroupACapi PeopleGroupO4ACapi
extern PeopleGroupACapiT PeopleGroupACapi;

#endif /* PeopleGroupO4_h */
/**
* This is very incomplete.
* Group has special rules :
* - normally there is only the default group
* - groups can share data if allowed at init
* A people group is the collection of users and applications that support a particular community process.
*/
