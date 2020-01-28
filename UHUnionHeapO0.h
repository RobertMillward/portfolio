//
//  UHUnionHeapO0.h
//
//  Created by Robert R on 11/02/19.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
#ifndef UHUnionHeapO0_h
#define UHUnionHeapO0_h
// os
#include <stdio.h>
// data plans
#include "UHUnionHeapZ0Plan.h"
// api's

/**
 * Tjhe core of the UnionHeap is an array (heap) of a union of type uhxElT
 * containing data types of a pointer, an integer, a float, or a seven character C-string.
 * It is carried about among the functions via a control structure identified by uhxPassT.
 * There is a default dompare for each of the four data types or the caller may provide one.
 * Functions are listed in the Instance Helper below.
 */
typedef struct UHUnionHeapO0HelperInstanceApiStruct
{
    /**
     * Get a new control structure.
     */
    uhxPassT    (*newUhxPassT)(uhxElPT, uhxHeapCountT, uhxSubTypeT, uhxComparePT);
    /**
     * Fill in the default compare if missing.
     */
    void        (*fillInCompareAsNeeded)(uhxPassPT);
    /**
     * Sequence check the uhxElT array.
     */
    uhxIxNoMoreT (*seqCheckYourItems)(uhxPassPT);
    /**
     * Merge the sorted sub-sections.
     */
    void        (*mergeSubs)(uhxElPT sourcePairs, uhxElPT targetPairs,
                             long inCount, long subsectionSize,
                             uhxComparePT uhxCompare,
                             uhxPassPT mergeInfoP);
    
}UHUnionHeapO0HIapiT, *UHUnionHeapO0HIapiPT;

extern UHUnionHeapO0HIapiT UHUnionHeapO0HIapi;


#endif /* UHUnionHeapO0_h */
