//
//  RowO0.h - A thread safe library to robustly support Row manipulation.
//
//  Created by Robert Russell Millward on 10/4/19.
//  Copyright (c) 2019 Robert Russell Millward. All rights reserved
//
#ifndef RowO0_h
#define RowO0_h
#include "RowZ0Plan.h"

typedef const struct RowO0ACapiS
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
    
    RowZ0AIwxyzT
    (*getWXYZ)(char* rowP);
    
}RowO0ACapiT, *RowO0ACapiPT;

extern RowO0ACapiT RowO0ACapi;

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
