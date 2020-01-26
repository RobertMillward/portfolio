//
//  CompareO0.h
//
//  Created by Robert R on 2/21/15.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef CompareO0_h
#define CompareO0_h
// os
// data plan
#include "CompareZ0Plan.h"
// api's
/**
 * Compare for EQ, LOW, HIGH, Starts with, Ends with, Contains, is numerically similar to.
 */
typedef struct CompareO0HelperClassApiStructure
{
    /**
     * Compare two fields.
     */
    compareResultArcT(*sortTwoFields)(
            char *thisVal,
            char *thatVal,
            dataTypeT onType,
            sortNullsArcT hiLo);
    /**
     * Rank the similarity of two fields.
     */
    rankCprT (*isSimilar)(
            char *val1,
            char *similarTo,
            dataTypeT onType);
    /**
     * See if this field or value is like that value.
     */
    compareResultArcT (*isLike)(
            char *thisVal,
            char *thatVal,
            dataTypeT onType);
    
}CompareO0HCapiT, *CompareO0HCapiPT;


#define CompareHCapiT CompareO0HCapiT
#define CompareHCapi CompareO0HCapi
extern const CompareHCapiT CompareHCapi;

#endif /* defined(CompareO0_h) */
/**
 *
 */
