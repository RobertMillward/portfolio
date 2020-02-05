//
//  RowO0.h - A thread safe library to robustly support Row manipulation.
//
//  Created by Robert Russell Millward on 10/4/19.
//  Copyright (c) 2020 Robert Russell Millward. All rights reserved
//
#ifndef RowO0_h
#define RowO0_h
// os
// data plans
#include "RowZ0Plan.h"
// api's

typedef const struct RowO0HCapiS
{
    /**
     * Initialize this Row to the empty char[]. The length can be MIN_FIELD_Z_ROW or greater.
     */
    Sint // -1 if error else 0
    (*clearTgt)(targetPT, massOfT);
    
    /**
     * Append this field to this Row. It will be
     * made up of the field separator followed by the field letter followed by the content.
     * The field letter cannot be a field or row separator or the '=' or the '\0' character.
     * The field can not exceed MAX_FIELD_Z_ROW in length.
     * The field cannot contain a field or row separator.
     */
    Sint // -1 if error else 0
    (*addMore)(fieldLetterRowT, sourcePT, targetPT);
    
    Sint // -1 if error else 0
    (*addChar)(fieldLetterRowT, sourceT, targetPT);
    
    /**
     * Add the metadata.
     */
    Sint // from addMore
    (*addWXYZ)(whatPT, indeXPT, whYeT, whoZPT, targetPT);
    
    /**
     * Append an end-of-row marker to this Row.
     */
    Zint // final length
    (*finish)(targetPT);
    
    RowWxyzZ0AIdataT
    (*getWXYZ)(char* rowP);
    
}RowO0HCapiT, *RowO0HCapiPT;

extern RowO0HCapiT RowO0HCapi;

typedef struct RowStoreZ0HelperInstanceApiStruct
{
    /**
     * Set needsSaved = false then return the original needsSaved true/false
     * Make it true
     */
    bool (*needsSaved)(RowStoreZ0HIdataPT);
    void (*setNeedsSaved)(RowStoreZ0HIdataPT);
    /**
     * Set the unix file name (repository which contails this What ) and get a free indeX.
     * It will be used in groupId/[prod|test|train|dev]/fileName
     */
    void (*setFileNameIndeX)(RowStoreZ0HIdataPT, cfuncNameT, gpSllgChar64PT);
    /**
     * Set the various whY values and needsSaved:
     * Show this record as active for regular processing.
     */
    void (*setActive)(RowStoreZ0HIdataPT);
    /**
     * Used with things like clone and clear.
     * Should not be saved.
     */
    void (*setEmpty) (RowStoreZ0HIdataPT);
    /**
     * A logical delete, All deletes can be undone.
     */
    void (*setHidden)(RowStoreZ0HIdataPT);
    /**
     * Identify a node that an otherwise restricted external analyst can see.
     */
    void (*setDebug) (RowStoreZ0HIdataPT);
    /**
     * In the next roll of a detail file purge thiis along with scheduled deletes.
     */
    void (*setPurge) (RowStoreZ0HIdataPT);
    /**
     *
     */
    void (*header)(RowStoreZ0HIdataPT, indeXT nodeIdP, cfuncNameT, gpSllgChar64PT);
    
    void (*footer)(RowStoreZ0HIdataPT, cfuncNameT, gpSllgChar64PT);
    
}RowStoreZ0HIapiT, *RowStoreZ0HIapiPT;
extern RowStoreZ0HIapiT RowStoreZ0HIapi;

/**
 * See SampleHeader
 * Must be named gp64P.
 */
#define FIELDS_BEGIN \
int stepIx = 99; \
for(; stepIx > 0; stepIx--) \
{ \
    gp64P->versionLevelP = newObj.data.storeData.vsnLvlP; \
    strcpy(gp64P->theCharValue, ""); \
    \
    switch(stepIx) \
    { \
        default: stepIx = 0; break;

#define FIELDS_UNTIL \
    } \
       \
    if(stepIx > 0 && gp64P->twoWayP->twoWayStatusP == KNOW_NO_ARC) \
    { \
        stepIx = -1; \
    } \
}

#endif /* defined(RowO0_h) */
/**
 A Row is an essential building block in the library.
 Initializing (clearing), uodating (adding more), and finishing are the three steps required to
 maintain a Row. A Row can exist as a log, journal, or message.
 
 A Row looks like:
 // NNNN - the actual length of data and RS (journal only)
 The "=" in the fllowing is actually an ASCII FS
 =afieldContent (through field v) for Cursor to process. Anything but ROWSEP_ROW, FLDSEP_ROW, "=", and NULL in any case.
 =witemName ([W]hat)
 =xrowID    (inde[X])
 =yrowStatus (wh[Y])
 =zsource signatures (who[Z]) or other source identification
 
 The fields are not required to be ordered.
 The data is ASCII8.
 None of these two blocks must ever change if persistant data exists.
 
 // Notes:
 // - null pointers are missing fields in CursorZ0.c)
 
 FEATURED 11/28/19
 */
