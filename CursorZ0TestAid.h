//
//  CursorZ0TestAid.h
//
//  Created by Robert Russell Millward on 10/4/13.
//  Copyright (c) 2020 Robert Russell Millward. All rights reserved
//
#ifndef CursorZ0TestAid_h
#define CursorZ0TestAid_h
// os
// helper api's
#include "CompareO0.h"
#include "CursorO0.h"
// data plans
#include "CursorZ0Plan.h"
#include "RowZ0Plan.h"


typedef struct CursorO0QualityInstanceApiStruct
{
    /**
     * Create a ready to journal string.
     */
    void (*toRow)(CursorZ0HIdataPT data, char * here, massOfT, lineNbrT);
    /**
     * Get a pointer to the designated field.
     */
    char* (*getField)(CursorZ0HIdataPT data, fieldLetterRowPT field, lineNbrT);
    /**
     * Update to/from without deleting missing from
     * fields.
     *
     * The field identifiers must be related.
     */
    // For sure ROW_ITEM_NAME must match.
    // Probably ROW_ID should match.
    void (*updateMatchingCursor)(CursorZ0HIdataPT data, CursorZ0HIdataPT that, lineNbrT);
    /**
     * Clear or drop the value for the designated field.
     */
    void (*dropField)(CursorZ0HIdataPT data, fieldLetterRowPT field, lineNbrT);
    /**
     * Compare per the sortOn list
     * (see CPR_FTYPE_*).
     * Example for
     * - Nulls High,
     * - field a, left justified string,
     * - field b, number,
     * - field c, date-time
     * sortOn literally looks like "Halbnct"
     */
    char *(*sort)(CursorZ0HIdataPT data, CursorZ0HIdataPT that, sortCtlCprPT sortOnP, lineNbrT);
    
}CursorO0QIapiT, *CursorO0QIapiPT;
extern CursorO0QIapiT CursorO0QIapi;

typedef struct CursorO0QualityClassApiStruct
{
    void (*setupSuite)(lineNbrT);
    bool (*isScheduled)(cfuncNameT, lineNbrT);
    char* (*getAssertText)(cfuncNameT, lineNbrT);
    
    void (*setupSizesSet1)(lineNbrT);
    bool (*doSizesSet1)(lineNbrT);
    void (*teardownSizesSet1)(lineNbrT);
    
    void (*setupSafetySet2)(lineNbrT);
    bool (*doSafetySet2)(lineNbrT);
    void (*teardownSafetySet2)(lineNbrT);
    
    void (*setupCsvSet3)(lineNbrT);
    bool (*doCsvSet3)(lineNbrT);
    void (*teardownCsvSet3)(lineNbrT);
    
    void (*setupSortSet4)(lineNbrT);
    bool (*doSortSet4)(lineNbrT);
    void (*teardownSortSet4)(lineNbrT);
    
    void (*setupUpdateSet5)(lineNbrT);
    bool (*doSetUpdateSet5)(lineNbrT);
    void (*teardownUpdateSet5)(lineNbrT);
    
    void (*teardownSuite)(lineNbrT);
    
}CursorO0QCapiT, *CursorO0QCapiPT;

extern CursorO0QCapiT CursorO0QCapi;



typedef struct CursorZ0QualiyInstanceThisStruct
{
    CursorZ0HIdataT data;
    
    // Instance functions:
    CursorO0QIapiPT apiP;  // The externalized methods to keep the instance as small as possible.
    
} CursorO0QIthisT, *CursorO0QIthisPT;



/**
 * A newCursor reformats the input data (journal or commaSep)
 * so preserve the input row first as necessary.
 */
//extern CursorO0QIthisT newCursorZ0Test(char *jnlOrCsvLine, gpSllgChar64PT, lineNbrT);
//typedef struct CursorO0QualityClassApiStruct
//{
//    /**
//     * Create a ready to journal string.
//     */
//    void (*newThisQ)(CursorZ0HIdataPT data, char * here, massOfT, lineNbrT);
//
//}CursorO0QCapiT, *CursorO0QCapiPT;
//extern CursorO0QCapiT CursorO0QCapi;



#endif /* CursorZ0TestAid_h */
