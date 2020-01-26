//
//  RowZ0TestAid.h
//
//  Created by Robert Russell Millward on 10/4/19.
//  Copyright (c) 2019 Robert Russell Millward. All rights reserved.
//
#ifndef RowZ0TestAid_h
#define RowZ0TestAid_h
#include "RowO0.h"

/**
 * A thread safe library to support the stages of Row creation.
 */
typedef const struct RowO0QCapiS
{
    // These have line number unlike O0.h
    Sint
    (*clearTgt)(targetPT, Zint, lineNbrT);
    
    // These have line number unlike O0.h
    Sint
    (*addMore)(fieldLetterRowT, sourcePT, targetPT, lineNbrT);
    
    // These have line number unlike O0.h
    Zint
    (*finish)(targetPT, lineNbrT);
    
    /**
     * Tests to certify that the library won't crash for:
     *
     * a missing target or source argument
     * a source containing FLDSEP_ROW or ROWSEP_ROW
     * a field Letter of NUL_ARC, EQ_ARC, FLDSEP_ROW or ROWSEP_ROW
     */
    ErrorWarnCountT (*targetTests)(lineNbrT);
    ErrorWarnCountT (*letterTests)(lineNbrT);
    ErrorWarnCountT (*sourceTests)(lineNbrT);
    
}RowO0QCapiT, *RowO0QCapiPT;

extern RowO0QCapiT RowO0QCapi;

/**
 * Additional Versons api will go here.
 */

#endif /* defined(RowZ0TestAid_h) */
/**
 */
