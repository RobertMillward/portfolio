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
     * Two sequencers.
     * - The index of the first couplet that is out of sequence with the prior couplet or IXNOMORE_HEAPSM
     */
    //uhxIxNoMoreT (*UHUnionHeapZ0_sortYourToBeCoupledItems_fx99)(uhxPassPT );
    //void         (*UHUnionHeapZ0_swapItems_fx99)(uhxPassPT uhxPassP);
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
    /**
     * Compare a triplet then rearrange the triplet as needed.
     */
    uhxTripletDiagramT  (*mapTriplet)(uhxPassPT uhxPassP, long item1Ix, long item2Ix, long item3Ix);
    void                (*xferTriplet)(uhxPassPT uhxPassP, long item1Ix, long item2Ix, long item3Ix, uhxTripletDiagramT);
    /**
     * From a sampling of the heap produce an analysis which can be used to guide any process such as sorting.
     */
    uhxAnalysisT        (*analyze)(uhxPassPT uhxPassP);
    
}UHUnionHeapO0HIapiT, *UHUnionHeapO0HIapiPT;

extern UHUnionHeapO0HIapiT UHUnionHeapO0HIapi;


#endif /* UHUnionHeapO0_h */
