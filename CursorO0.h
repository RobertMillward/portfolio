//
//  RowO0.h
//
//  Created by Robert Russell Millward on 10/4/13.
//  Copyright (c) 2013 Robert Russell Millward.
//
/**
 * Special parameters notes for this package:
 * - uses no memory so does not need group size and Id information
 * - DOES transaction trace logging so does use the transaction Id (probably TRAN_IX) and isBatch information
 * - may have versions using inheritance so has version and level information
 */
#ifndef RowO0_h
#define RowO0_h

#import "ArchitectureO0.h"
#import "TimeSerNbrO0.h"

// A log, journal, csv, or message row looks like:
// NNNN - the actual length of data and eow (journal only)
// fieldContent=a (through v)
// itemName=w
// rowID=x
// rowStatus=y
// serNbrOffset=z (see TimeSerNbr)

// eow=w - the end of write
// Notes:
// - none of these two blocks must ever change
// - null pointers are missing fields
// - The fields are not required to be ordered
// - The data is ASCII8
// - The "=" is actually an ASCII FS

#define FIRST_VALUE_ROW 'a'
#define LAST_VALUE_ROW  'v'
#define FIELDS_FROM_FIRST_TO_LAST (LAST_VALUE_ROW - FIRST_VALUE_ROW + 1)
#define ITEM_NAME_ROW   'w'
#define ID_ROW          'x'
#define STATUS_ROW      'y'
#define SOURCE_ROW      'z'
#define ITEM_NAME_ROW_STR   "w"
#define EOW "eow" FSS_ARC ITEM_NAME_ROW_STR

#define EMPTY_ROWST  '0'
#define ACTIVE_ROWST '1'
#define DEBUG_ROWST  '2'
#define HIDDEN_ROWST '8'
#define PURGE_ROWST  '9'
#define STATUS_Z_ROWST 1


typedef char* sortCtlRowPT;
typedef char* fieldLetterRowPT;

// The data pointed to by fields[FIELDS_FROM_FIRST_TO_LAST] is generally
// stored in journalData, messageData, CsvData, etc
// in the main block.
// Someday, small, non-conflicting
// rows will be stored in dOrF.data.
// When that happens:
// - the ending characters will be offsets
// - an offset of -1 will be null
// - highField will play a bigger role
typedef struct RowO0IdoS
{
    int txIX;
    //gpTransactionSizeO0PT flagsForTxSizeBatchP;
    //gpVersionLevelO0PT flagsForCodeVersionAndLevelP;
    char itemName[20];                  //w[hat] it is
    char rowID[TIME_INFO_Z_TIME+1];     //[inde]x (possibly from TimeSerNbr)
    char rowStatus[STATUS_Z_ROWST+1];   //[wh]y the row is here [act, bug, del]
    char sourceId[10+1];                //z[ignatures]-> PersonSig[3], PeopleGrpSig[3], AppSig[2], RoleSig[2]
    
    char highField;         //high field number
    union dOrFU
    {
        // Fields go left to right (z to e).
        // Empty pointer is no field.
        // A row is not required to address all fields.
        char *fieldsR2L[FIELDS_FROM_FIRST_TO_LAST];// last - first + 1
                                                   // Data left to right and pointers right to left.
                                                   // This is not yet implemented.
        char dataL2R[FIELDS_FROM_FIRST_TO_LAST * sizeof((char *)0)];
    }dOrF;
    
    // Statistics:
    int getFieldCt;
    
}RowO0doIT, *RowO0doIPT;

typedef struct RowO0IgoS
{
    /**
     * Create a ready to journal string.
     */
    void (*toASCII)(RowO0doIPT data,
                    char * here);
    /**
     * Get a pointer to the designated field.
     */
    char* (*getField)(RowO0doIPT data,
                      fieldLetterRowPT field);
    /**
     * Update to/from without deleting missing from
     * fields.
     *
     * The field identifiers must be related.
     */
    // For sure ROW_ITEM_NAME must match.
    // Probably ROW_ID should match.
    void (*updateMatchingRow)(RowO0doIPT data,
                              RowO0doIPT that);
    /**
     * Clear or drop the value for the designated field.
     */
    void (*dropField)(RowO0doIPT data,
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
    char *(*sort)(RowO0doIPT data,
                  RowO0doIPT that,
                  sortCtlRowPT sortOnP);
}RowO0goIT, *RowO0goIPT;



typedef struct RowO0IS
{
    RowO0doIT dataO0;
    
    // Instance functions:
    RowO0goIPT O0;  // The externalized methods to keep the instance as small as possible.

} RowO0IT, *RowO0IPT;


#define RowIT RowO0IT
#define RowIPT RowO0IPT
/**
 * A newRow reformats the input data (journal or commaSep)
 * so copy or strlen the input row first as necessary.
 */
#define newRow newRowO0
extern RowIT newRow(char *jnlOrCsvLine, gpTxPplGrpBatchTwoWayO0PT infoP);

#define ROW_FTYPE_DTTM 't'
#define ROW_FTYPE_NBR  'n'
#define ROW_FTYPE_STRL 'l'
#define ROW_FTYPE_STRR 'r'
#define ROW_FTYPE_SPCL 'L'
#define ROW_FTYPE_SPCR 'R'

#endif /* RowO0_h */
