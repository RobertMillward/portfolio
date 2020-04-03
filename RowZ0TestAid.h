//
//  RowZ0TestAid.h
//  2020Mar10Dev
//
//  Created by Robert Russell Millward on 10/4/19.
//  Copyright (c) 2020 Robert Russell Millward. All rights reserved.
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
    (*addMore)(fieldLetterT, sourcePT, targetPT, lineNbrT);
    
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
    ErrorWarnCountT (*storeTests)(lineNbrT);
    
}RowO0QCapiT, *RowO0QCapiPT;

extern RowO0QCapiT RowO0QCapi;

typedef struct RowZ3QualityClassApiStructure
{
    void (*setupSuite)(lineNbrT);
    bool (*isScheduled)(cfileNameT, lineNbrT);
    char* (*getAssertText)(cfuncNameT, lineNbrT);
    
    void (*setupSet1)(lineNbrT);
    bool (*doSet1SizeSafe)(lineNbrT);
    void (*teardownSet1)(lineNbrT);
    
    
    void (*setupSet2)(lineNbrT);
    bool (*doSet2Basics)(lineNbrT);
    void (*teardownSet2)(lineNbrT);
    
    void (*setupSet3)(lineNbrT);
    bool (*doSet3ExtraDemo)(lineNbrT);
    void (*teardownSet3)(lineNbrT);
    
    void (*setupSet4)(lineNbrT);
    bool (*doSet4Performance)(lineNbrT);
    void (*teardownSet4)(lineNbrT);
    
    void (*teardownSuite)(lineNbrT);
}RowZ3QCapiT, *RowZ3QCapiPT;

extern RowZ3QCapiT RowZ3QCapi;

/**
 * Additional Versons api will go here.
 */

#endif /* defined(RowZ0TestAid_h) */
/**
 */
