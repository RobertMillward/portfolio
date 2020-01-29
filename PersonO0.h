//
//  PersonO0.h
//
//  Created by Robert Russell Millward on 9/26/13.
//  Copyright (c) 2013 Robert Russell Millward.  All rights reserved.
//
#ifndef PersonO0_h
#define PersonO0_h
#include "PersonZ0Plan.h"
/*
 */
#pragma mark - instance methods
/*
 */

typedef struct PersonO0ApplicationInstanceApiStructure
{
    /**
     * Copy in and copy out the basic data.
     */
    //void (* setGetEmail)        (emailT,        PersonZ0AIdataPT, emailPT,        gdbIsRevisedT);
    void (* setGetFamilyName)   (nameT,         PersonZ0AIdataPT, familyNamePT,   gdbIsRevisedT);
    void (* setGetFirstName)    (nameT,         PersonZ0AIdataPT, firstNamePT,    gdbIsRevisedT);
    void (* setGetMiddleName)   (nameT,         PersonZ0AIdataPT, middleNamePT,   gdbIsRevisedT);
    //void (* setGetPassPhrase)   (passPhraseT,   PersonZ0AIdataPT, passPhrasePT,   gdbIsRevisedT);
    //void (* setGetPostalCode)   (postalT,       PersonZ0AIdataPT, postalCodePT,   gdbIsRevisedT);
    void (* setGetTitle)        (titleT,        PersonZ0AIdataPT, titlePT,        gdbIsRevisedT);
    //void (* setGetReturnedCode) (returnedCodeT, PersonZ0AIdataPT, returnedCodePT, gdbIsRevisedT);
    //void (* setGetAuthentCode)  (authentT,      PersonZ0AIdataPT, authentNowPT,   gdbIsRevisedT);
    //void (* generateSignatureCode)(PersonZ0AIdataPT dataP);
    
}PersonO0AIapiT, *PersonO0AIapiPT;

#define PersonAIapiT PersonO0AIapiT
#define PersonAIapi  PersonO0AIapi
extern PersonO0AIapiT PersonAIapi;


/*
 */
#pragma mark - Class Methods
/*
 */
typedef struct PersonO0ApplicationClassApiStructure
{

}PersonO0ACapiT, *PersonO0ACapiPT;

#define PersonACapiT PersonO0ACapiT
#define PersonACapi  PersonO0ACapi
extern PersonACapiT PersonACapi;

/*
 */
#pragma mark - New instance
/*
 */
typedef struct PersonO0ApplicationInstanceNewStructure
{
    PersonO0AIapiPT api;
    PersonZ0AIdataT data;
    
}PersonO0AInewT, *PersonO0AInewPT;

#endif
/**
 */
//END PersonO0.h
