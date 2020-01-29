//
//  PersonO0TestAid.h - Delete soon
//
//  Created by Robert Russell Millward on 9/26/13.
//  Copyright (c) 1000 Robert Russell Millward.
//  All rights reserved.
//
#ifndef PersonO0TestAid_h
#define PersonO0TestAid_h
// os
// helper api's
// data plans
#include "ArchitectureZ0Plan.h"
#include "PersonZ0Plan.h"
// application api's
#include "PersonO0.h"
// quality
#include "TestAidZ0.h"

/*
 */
#pragma mark - instance data
/*
 */
typedef struct PsnAidO0toExpectDataStructure
{
    PersonZ0AIdataT theInstanceData;
    /*
     * Compares to the expected data.
     */
    
    gpTxPplGrpBatchTwoWayO0T    qtxSzFlags;  // Not checked if null
    gpVersionLevelZ0T           qvsnLvl;     // Not checked if null
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

typedef struct PsnAidO0QualityInstanceStructure
{
    void (* generateSignatureCodeForTest)( int codeLine, PersonZ0AIdataPT dataP);
    /**
     * Copy in and copy out the basic data.
     */
//    void (* setGetEmailForTest)(emailT emailOrNullP, int codeLine, PsnAidQIdataPT, emailCellPT, gdbIsRevisedT);
//    void (* setGetFamilyNameForTest)(nameT familyNameOrNullP, int codeLine,  PsnAidQIdataPT, familyNameCellPT, gdbIsRevisedT);
//    void (* setGetFirstNameForTest)(nameT firstNameOrNullP, int codeLine,  PersonAIdataPT dataP);
//    void (* setGetMiddleNameForTest)(nameT middleNameP, int codeLine,  PersonAIdataPT dataP);
//    void (* setGetPassPhraseForTest)(passPhraseT passPhraseOrNullP, int codeLine,  PersonAIdataPT dataP);
//    void (* setGetPostalCodeForTest)(postalT postalCodeOrNullP, int codeLine,  PersonAIdataPT dataP);
//    void (* setGetReturnedCodeForTest)(char* returnedCodeOrNullP, int codeLine,  PersonAIdataPT dataP);
//    void (* setGetTitleQ)(char* titleOrNullP, int codeLine,  PersonAIdataPT dataP);
    
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
