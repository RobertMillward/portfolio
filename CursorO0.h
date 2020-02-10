//
//  CursorO0.h
//
//  Created by Robert Russell Millward on 10/4/13.
//  Copyright (c) 2020 Robert Russell Millward. All rights reserved.
//
#ifndef CursorO0_h
#define CursorO0_h
// os
// helper api's
#include "TimeSerNbrO0.h"
// data plans
#include "ArchitectureZ0Plan.h"
#include "CompareZ0Plan.h"
#include "CursorZ0Plan.h"
#include "RowZ0Plan.h"



typedef struct CursorO0HelperInstanceApiStruct
{
    /**
     * Create a new data instance
     */
    CursorZ0HIdataT (*newData)(char *jnlOrCsvLine, gpSllgChar64PT);
    /**
     * Create a ready to journal string.
     */
    void (*toRow)(CursorZ0HIdataPT data, char* here, massOfT);
    /**
     * Get a pointer to the designated field.
     */
    char* (*getField)(CursorZ0HIdataPT data, fieldLetterRowPT field);
    /**
     * Update to/from without deleting missing from
     * fields.
     *
     * The field identifiers must be related.
     */
    // For sure ROW_ITEM_NAME must match.
    // Probably ROW_ID should match.
    void (*updateMatchingCursor)(CursorZ0HIdataPT data, CursorZ0HIdataPT that);
    /**
     * Clear or drop the value for the designated field.
     */
    void (*dropField)(CursorZ0HIdataPT data, fieldLetterRowPT field);
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
    char *(*sort)(CursorZ0HIdataPT data, CursorZ0HIdataPT that, sortCtlCprPT sortOnP);
}CursorO0HIapiT, *CursorO0HIapiPT;
extern CursorO0HIapiT CursorO0HIapi;


typedef struct CursorO0HelperInstanceNewStruct
{
    CursorZ0HIdataT data;
    
    // Instance functions:
    CursorO0HIapiPT apiP;  // The externalized methods to keep the instance as small as possible.

} CursorO0HIthisT, *CursorO0HIthisPT;
#define CursorHIthisT CursorO0HIthisT
#define CursorHIthis CursorO0HIthis



//extern CursorO0HInewT newCursorO0HI(char *jnlOrCsvLine, gpTxPplGrpBatchTwoWayZ0PT infoP);

typedef struct CursorO0HelperClassApiStruct
{/**
    * A newCursor reformats the input data (journal or commaSep)
    * so copy or strlen the input row first as necessary.
    */
    CursorO0HIthisT (*newCursor)(char *jnlOrCsvLine, gpSllgChar64PT);
    
}CursorO0HCapiT, *CursorO0HCapiPT;
extern CursorO0HCapiT CursorO0HCapi;

#endif /* CursorO0_h */
/**
 *
 */
