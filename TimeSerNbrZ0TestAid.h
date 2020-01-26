//
//  TimeSerNbrZ0TestAid.h - interface file for all level 0 quality assurance code silo parts common to all versions
//
//  Created by Robert R on 11/2/19.
//  Copyright © 2019 Robert Russell Millward. All rights reserved.
//


#ifndef TimeSerNbrZ0TestAid_h
#define TimeSerNbrZ0TestAid_h
#include <stdio.h>
#include "TimeSerNbrZ0Plan.h"


/**
 * The TimeSerNbrZ0QC silo of quality assurance class api
 */
typedef struct TimeSerNbrZ0QualityClassApiStruct
{
    /**
     * Please see TimeSerNbrO0.h for documentation
     */
    void (*newTimeAndSerNbrNow)(theStampAIdataPT, lineNbrT);
    Sint (*getStrOfTime)(gpSllgCharArrayPT, lineNbrT);
    Sint (*getRowOfSerNbr)(gpSllgCharArrayPT, lineNbrT);
    void (*getAgeInWeeksAndDays)(gpSllgCharArrayPT, lineNbrT);
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

#endif /* TimeSerNbrZ0TestAid_h */
