//
//  PersonZ0TestAid.h
//
//  Created by Robert Russell Millward on 9/26/13.
//  Copyright (c) 2013 Robert Russell Millward.
//  All rights reserved.
//
/**
 * The Q class is for Quality checking.
 * Persons (plural) is for the class and Person (singular) is for the instance.
 * InitDestroyHelper.destroyAll() is the class cleanup
 */

#ifndef PersonZ0TestAid_h
#define PersonZ0TestAid_h
#include "TestAidZ0.h"
#include "PersonZ0Plan.h"

/*
 */
#pragma mark - instance data
/*
 */
typedef struct PsnAidZ0toExpectDataStructure
{
    PersonZ0AIdataT theInstanceData;
    /*
     * Compares to the expected data.
     */
    char qfamilyName[44];
    char qfirstName[44];
    char qtitle[6];
    char qmiddleName[44];
    char qemail[44];
    char qpostalCode[10];
    char qauthentCodeBefore[8];
    char qauthentCodeNow[8];
    char qpassPhrase[24];

    char qpersonSigCode[10];
    
    gpTxPplGrpBatchTwoWayZ0T    qtxSzFlags;  // Not checked if null
    gpVersionLevelZ0T           qvsnLvl;     // Not checked if null
    /*
     * Compares to the expected warnings and errors.
     */
    ErrorWarnCountT qpersonCounts;
    ErrorWarnCountT qaggregateCounts;
    Ullg qrandomGen;
    char* qtheOffender;
} PsnAidZ0QIdataT, *PsnAidZ0QIdataPT;
#define PsnAidQIdataPT PsnAidZ0QIdataPT
#define PsnAidQIdataT PsnAidZ0QIdataT

/*
 */
#pragma mark - instance methods
/*
 */

typedef struct PsnAidZ0ApplicationInstanceApiQualityStructure
{
    void (* generateSignatureCodeForTest)( int codeLine, PersonZ0AIdataPT dataP);
    /**
     * Copy in and copy out the basic data.
     */
//    void (* setGetEmailForTest)(emailT emailOrNullP, int codeLine, PsnAidQIdataPT, emailPT, gdbIsRevisedT);
//    void (* setGetFamilyNameForTest)(nameT familyNameOrNullP, int codeLine,  PsnAidQIdataPT, familyNamePT, gdbIsRevisedT);
//    void (* setGetFirstNameForTest)(nameT firstNameOrNullP, int codeLine,  PersonAIdataPT dataP);
//    void (* setGetMiddleNameForTest)(nameT middleNameP, int codeLine,  PersonAIdataPT dataP);
//    void (* setGetPassPhraseForTest)(passPhraseT passPhraseOrNullP, int codeLine,  PersonAIdataPT dataP);
//    void (* setGetPostalCodeForTest)(postalT postalCodeOrNullP, int codeLine,  PersonAIdataPT dataP);
//    void (* setGetReturnedCodeForTest)(char* returnedCodeOrNullP, int codeLine,  PersonAIdataPT dataP);
//    void (* setGetTitleForTest)(char* titleOrNullP, int codeLine,  PersonAIdataPT dataP);
    
}PsnAidZ0QIapiT, *PsnAidZ0QIapiPT;

#define PsnAidQIapiT PsnAidZ0QIapiT
#define PsnAidQIapi PsnAidZ0QIapi
extern PsnAidQIapiT PsnAidQIapi;


/*
 */
#pragma mark - Class Methods
/*
 */
typedef struct PsnsAidZ0goClassQualityStructure
{

}PsnsAidZ0QCgoT, *PsnsAidZ0QCgoPT;

#define PsnsAidQCgoT PsnsAidZ0QCgoT
#define PsnsAidQCgo PsnsAidZ0QCgo
extern PsnsAidQCgoT PsnsAidQCgo;

/*
 */
#pragma mark - New instance
/*
 */
extern char* newExpectAndPersonZ0In(int codeLine, PsnAidQIdataPT here);

#endif // PersonZ0TestAid.h
