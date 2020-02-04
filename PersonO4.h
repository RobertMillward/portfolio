//
//  PersonO4.h
//
//  Created by Robert Russell Millward on 9/26/13.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef PersonO4_h
#define PersonO4_h
// os
// helper api's
// data plans
#include "ArchitectureZ0Plan.h"
#include "PersonZ0Plan.h"
// application api's


/**
 * Copy in and copy out the basic data.
 */
//void (* setGetPassPhrase)   (passPhraseT,   PersonZ0AIdataPT, passPhrasePT,   gdbIsRevisedT);
//void (* setGetAuthentCode)  (authentT,      PersonZ0AIdataPT, authentNowPT,   gdbIsRevisedT);

/*
 */
#pragma mark - Instance api
/*
 */

typedef struct PersonO4ApplicationInstanceApiStructure
{
    void    (*hideRow)  (PersonZ0AIdataPT);
    void    (*unhideRow)(PersonZ0AIdataPT);
    void    (*saveRow)  (PersonZ0AIdataPT);
    /**
     * Run either ... or ... on gp64.vsnLvlP
     */
    void    (*rowOf)    (PersonZ0AIdataPT,
                         targetPT, massOfT,
                         indeXPT, whoZPT,
                         gpSllgChar64PT);
    
}PersonO4AIapiT, *PersonO4AIapiPT;

// extern PersonO4AIapiT PersonO4AIapi; available only through the instance

typedef struct PersonPassPhraseO4ApplicationInstanceApiStructure
{
    void    (*saveRow)(void);
    void    (*trashRow)(void);
    void    (*rowOf)        (PersonPassPhraseZ0AIdataPT);
}PersonPassPhraseO4AIapiT, *PersonPassPhraseO4AIapiPT;



/*
 */
#pragma mark - New instance
/*
 */
typedef struct PersonO4ApplicationInstanceNewStructure
{
    PersonO4AIapiPT apiP;
    PersonZ0AIdataT data;
    
}PersonO4AInewT, *PersonO4AInewPT;


typedef struct PersonPassPhraseO4ApplicationInstanceNewStructure
{
    PersonPassPhraseO4AIapiPT apiP;
    PersonPassPhraseZ0AIdataT data;
    
}PersonPassPhraseO4AInewT, *PersonPassPhraseO4AInewPT;


/*
 */
#pragma mark - Class Api
/*
 */
typedef struct PersonO4ApplicationClassApiStructure
{
    PersonO4AInewT (*forInsert)(abstractRowT);
    //PersonO4AInewT (*toView)(abstractRowT);
    PersonO4AInewT (*fromFields)(personIdT, gpSllgChar64PT);
}PersonO4ACapiT, *PersonO4ACapiPT;
#define PersonACapiT PersonO4ACapiT
#define PersonACapi  PersonO4ACapi
extern PersonACapiT PersonACapi;

typedef struct PersonPassPhraseO4ApplicationClassApiStructure
{
    PersonPassPhraseO4AInewT (*forInsert)(abstractRowT);
    PersonPassPhraseO4AInewT (*toView)(abstractRowT);
    PersonPassPhraseO4AInewT (*fromFields)(abstractRowT);
}PersonPassPhraseO4ACapiT, *PersonPassPhraseO4ACapiPT;
#define PersonPassPhraseACapiT PersonPassPhraseO4ACapiT
#define PersonPassPhraseACapi  PersonPassPhraseO4ACapi
extern PersonPassPhraseACapiT PersonPassPhraseACapi;

#endif // END PersonO4_h
/**
 *
 */
