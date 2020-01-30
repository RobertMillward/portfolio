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
#include "PersonZ0Plan.h"
// application api's

/*
 */
#pragma mark - instance methods
/*
 */

typedef struct PersonO4ApplicationInstanceApiStructure
{
    /**
     * Copy in and copy out the basic data.
     */
    //void (* setGetPassPhrase)   (passPhraseT,   PersonZ0AIdataPT, passPhrasePT,   gdbIsRevisedT);
    //void (* setGetReturnedCode) (returnedCodeT, PersonZ0AIdataPT, returnedCodePT, gdbIsRevisedT);
    //void (* setGetAuthentCode)  (authentT,      PersonZ0AIdataPT, authentNowPT,   gdbIsRevisedT);
    //void (* generateSignatureCode)(PersonZ0AIdataPT dataP);
    
}PersonO4AIapiT, *PersonO4AIapiPT;

#define PersonAIapiT PersonO4AIapiT
#define PersonAIapi  PersonO4AIapi
extern PersonAIapiT PersonAIapi;


/*
 */
#pragma mark - Class Methods
/*
 */
typedef struct PersonO4ApplicationClassApiStructure
{

}PersonO4ACapiT, *PersonO4ACapiPT;

#define PersonACapiT PersonO4ACapiT
#define PersonACapi  PersonO4ACapi
extern PersonACapiT PersonACapi;

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

#endif // END PersonO4_h
/**
 *
 */
