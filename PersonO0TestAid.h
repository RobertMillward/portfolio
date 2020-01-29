//
//  PersonO0TestAid.h
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

#ifndef PersonO0TestAid_h
#define PersonO0TestAid_h
#include "TestAidO0.h"
#include "PersonO0.h"

/*
 */
#pragma mark - instance data
/*
 */
typedef struct PsnAidO0toExpectDataStructure
{
    PersonAIdataT theInstanceData;
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
    
    gpTxPplGrpBatchTwoWayO0T    qtxSzFlags;  // Not checked if null
    gpVersionLevelO0T           qvsnLvl;     // Not checked if null
    /*
     * Compares to the expected warnings and errors.
     */
    ErrorWarnCountT qpersonCounts;
    ErrorWarnCountT qaggregateCounts;
    Ullg qrandomGen;
    char* qtheOffender;
} PsnAidO0QIdataT, *PsnAidO0QIdataPT;
#define PsnAidQIdataPT PsnAidO0QIdataPT
#define PsnAidQIdataT PsnAidO0QIdataT

/*
 */
#pragma mark - instance methods
/*
 */

typedef struct PsnAidO0goInstanceQualityStructure
{
    void (* generateSignatureCodeForTest)( int codeLine, PersonAIdataPT dataP);
    /**
     * Copy in and copy out the basic data.
     */
    void (* setGetEmailForTest)(emailT emailOrNullP, int codeLine, PsnAidQIdataPT, emailCellPT, gdbIsRevisedT);
    void (* setGetFamilyNameForTest)(nameT familyNameOrNullP, int codeLine,  PsnAidQIdataPT, familyNameCellPT, gdbIsRevisedT);
    void (* setGetFirstNameForTest)(nameT firstNameOrNullP, int codeLine,  PersonAIdataPT dataP);
    void (* setGetMiddleNameForTest)(nameT middleNameP, int codeLine,  PersonAIdataPT dataP);
    void (* setGetPassPhraseForTest)(passPhraseT passPhraseOrNullP, int codeLine,  PersonAIdataPT dataP);
    void (* setGetPostalCodeForTest)(postalT postalCodeOrNullP, int codeLine,  PersonAIdataPT dataP);
    void (* setGetReturnedCodeForTest)(char* returnedCodeOrNullP, int codeLine,  PersonAIdataPT dataP);
    void (* setGetTitleForTest)(char* titleOrNullP, int codeLine,  PersonAIdataPT dataP);
    
}PsnAidO0QIapiT, *PsnAidO0QIapiPT;

#define PsnAidQIapiT PsnAidO0QIapiT
#define PsnAidQIapi PsnAidO0QIapi
extern PsnAidQIapiT PsnAidQIapi;


/*
 */
#pragma mark - Class Methods
/*
 */
typedef struct PsnsAidO0goClassQualityStructure
{

}PsnsAidO0QCgoT, *PsnsAidO0QCgoPT;

#define PsnsAidQCgoT PsnsAidO0QCgoT
#define PsnsAidQCgo PsnsAidO0QCgo
extern PsnsAidQCgoT PsnsAidQCgo;

/*
 */
#pragma mark - New instance
/*
 */
extern char* newExpectAndPersonO0In(int codeLine, PsnAidQIdataPT here);

#endif // PersonO0TestAid.h
