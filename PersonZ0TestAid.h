//
//  PersonZ0TestAid.h
//
//  Created by Robert Russell Millward on 9/26/13.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef PersonZ0TestAid_h
#define PersonZ0TestAid_h
// os
// helper api's
// data plans
#include "PersonZ0Plan.h"
// application api's
// quality
#include "TestAidZ0.h"

/*
 */
#pragma mark - instance data
/*
 */
//typedef struct PsnAidZ0toExpectDataStructure
//{
//    PersonZ0AIdataT theInstanceData;
//    /*
//     * Compares to the expected data.
//     */
//    char qfamilyName[44];
//    char qfirstName[44];
//    char qtitle[6];
//    char qmiddleName[44];
//    char qemail[44];
//    char qpostalCode[10];
//    char qauthentCodeBefore[8];
//    char qauthentCodeNow[8];
//    char qpassPhrase[24];
//
//    char qpersonSigCode[10];
//
//    gpTxPplGrpBatchTwoWayZ0T    qtxSzFlags;  // Not checked if null
//    gpVersionLevelZ0T           qvsnLvl;     // Not checked if null
//    /*
//     * Compares to the expected warnings and errors.
//     */
//    ErrorWarnCountT qpersonCounts;
//    ErrorWarnCountT qaggregateCounts;
//    Ullg qrandomGen;
//    char* qtheOffender;
//} PsnAidZ0QIdataT, *PsnAidZ0QIdataPT;


/*
 */
#pragma mark - instance methods
/*
 */

//typedef struct PsnAidZ0ApplicationInstanceApiQualityStructure
//{
//    void (* generateSignatureCodeForTest)( int codeLine, PersonZ0AIdataPT dataP);
//    /**
//     * Copy in and copy out the basic data.
//     */
//
//}PsnAidZ0QIapiT, *PsnAidZ0QIapiPT;
//
//extern PsnAidZ0QIapiT PsnAidZ0QIapi;


/*
 */
#pragma mark - Class Methods
/*
 */
//typedef struct PsnsAidZ0goClassQualityStructure
//{
//
//}PsnAidZ0QCapiT, *PsnAidZ0QCapiPT;
//
//
//extern PsnAidZ0QCapiT PsnsAidZ0QCapi;


typedef struct PersonZ0QualityClassApiStruct
{
    ErrorWarnCountT (*newQ)(lineNbrT);
    /**
     *
     */
    ErrorWarnCountT (*fakeTestQ)(lineNbrT);
    
    
}PersonZ0QCapiT, *PersonZ0QCapiPT;

extern PersonZ0QCapiT PersonZ0QCapi;

#endif // END PersonZ0TestAid_h
/**
 *
 */
