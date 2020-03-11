//
//  TimeSerNbrZ0TestAid.h - interface file for all level 0 quality assurance code silo parts common to all versions
//
//  Created by Robert R on 11/2/19.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
#ifndef TimeSerNbrZ0TestAid_h
#define TimeSerNbrZ0TestAid_h
// os
#include <stdio.h>
// data plans
#include "TimeSerNbrZ0Plan.h"
// api's
// quality


/**
 * The TimeSerNbrZ0QC silo of quality assurance class api
 */
typedef struct TimeSerNbrZ0QualityClassApiStruct
{
    /**
     * Please see TimeSerNbrO0.h for documentation
     */
    //void (*newTimeAndSerNbrNow)(theStampAIdataPT, lineNbrT);
    //Sint (*getStrOfTime)(gpSllgChar32PT, lineNbrT);
    //Sint (*getRowOfSerNbr)(gpSllgChar32PT, lineNbrT);
    //void (*getAgeInWeeksAndDays)(gpSllgChar32PT, lineNbrT);
    /**
     * Tools
     */
    /**
     * Tests
     */
    ErrorWarnCountT (* isSerNbrTwoTx)(itemCountT, lineNbrT);
    ErrorWarnCountT (* isSerNbrSameTx)(lineNbrT);
    ErrorWarnCountT (* isSizeOfCompliant)(lineNbrT);
    ErrorWarnCountT (* isRowOfSerNbrCompliant)(lineNbrT);
    ErrorWarnCountT (* isStringOfTimeCompliant)(lineNbrT);
    ErrorWarnCountT (* isAgingCompliant)(lineNbrT);
    ErrorWarnCountT (* isCodesCompliant)(lineNbrT);
    ErrorWarnCountT (* is92x92Compliant)(lineNbrT);
}TimeSerNbrZ0QCapiT, * TimeSerNbrZ0QCapiPT;

extern TimeSerNbrZ0QCapiT TimeSerNbrZ0QCapi;
//====================================
typedef struct TimeSerNbrO0QualityClassApiStructure
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
}TimeSerNbrO0QCapiT, *TimeSerNbrO0QCapiPT;

extern TimeSerNbrO0QCapiT TimeSerNbrO0QCapi;

#endif /* TimeSerNbrZ0TestAid_h */
