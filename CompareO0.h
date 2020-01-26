//
//  CompareO0.h
//
//  Created by Robert R on 2/21/15.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef CompareO0_h
#define CompareO0_h
#include "CompareZ0Plan.h"
/**
 *
 */
typedef struct CompareO0AppClassApiStructure
{
    /**
     * Compare two fields.
     */
    compareResultArcT(*sortTwoFields)(
            char *thisVal,
            char *thatVal,
            dataTypeArcT onType,
            sortNullsArcT hiLo);
    /**
     * Rank the similarity of two fields.
     */
    rankCprT (*isSimilar)(
            char *val1,
            char *similarTo,
            dataTypeArcT onType);
    /**
     * See if this field or value is like that value.
     */
    compareResultArcT (*isLike)(
            char *thisVal,
            char *thatVal,
            dataTypeArcT onType);
    
}CompareO0ACapiT, *CompareO0ACapiPT;


#define CompareACapiT CompareO0ACapiT
#define CompareACapi CompareO0ACapi
extern const CompareACapiT CompareACapi;

#endif /* defined(CompareO0_h) */
