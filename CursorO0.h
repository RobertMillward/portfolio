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
#include "CursorZ0Plan.h"
#include "RowZ0Plan.h"

typedef struct CursorO0HelperInstanceDataStruct
{
    /**
     * Create a ready to journal string.
     */
    void (*toASCII)(CursorZ0HIdataPT data,
                    char * here);
    /**
     * Get a pointer to the designated field.
     */
    char* (*getField)(CursorZ0HIdataPT data,
                      fieldLetterRowPT field);
    /**
     * Update to/from without deleting missing from
     * fields.
     *
     * The field identifiers must be related.
     */
    // For sure ROW_ITEM_NAME must match.
    // Probably ROW_ID should match.
    void (*updateMatchingRow)(CursorZ0HIdataPT data,
                              CursorZ0HIdataPT that);
    /**
     * Clear or drop the value for the designated field.
     */
    void (*dropField)(CursorZ0HIdataPT data,
                      fieldLetterRowPT field);
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
    char *(*sort)(CursorZ0HIdataPT data,
                  CursorZ0HIdataPT that,
                  sortCtlRowPT sortOnP);
}CursorO0HIapiT, *CursorO0HIapiPT;



typedef struct CursorO0IS
{
    CursorZ0HIdataT data;
    
    // Instance functions:
    CursorO0HIapiPT apiP;  // The externalized methods to keep the instance as small as possible.

} CursorO0HInewT, *CursorO0HInewPT;
#define CursorHInewT CursorO0HInewT
#define CursorHInew CursorO0HInew
/**
 * A newRow reformats the input data (journal or commaSep)
 * so copy or strlen the input row first as necessary.
 */
extern CursorHInewT CursorHInew(char *jnlOrCsvLine, gpTxPplGrpBatchTwoWayZ0PT infoP);


#endif /* CursorO0_h */
/**
 *
 */
