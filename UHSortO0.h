//
//  UHSortO0.h
//  2020Apr02Dev
//
//  Created by Robert R on 11/02/19.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//

#ifndef UHSortO0_h
#define UHSortO0_h
// os
#include <stdio.h>
// data plans
#include "UHUnionHeapZ0Plan.h"
// api's

typedef struct UHSortO0ServiceInstanceDataStruct
{
    long    passCount;
    long    parentSwapCount;
    
    uhxPassPT uhxPassP;
}srtPassT, *srtPassPT;


typedef struct UHSortO0ServiceInstanceApiStruct
{
    /**
     * Functions
     */
    long            (*ourSort)(srtPassPT);
    /**
     * These simple sort examples being here avoid two more code sets.
     */
    int             (*clangSort)(srtPassPT);
    void            (*bruteSortIntegers)(srtPassPT);
    /**
     * Tools
     * - caller should increment srtPassP->passCount for these two
     */
    uhxIxNoMoreT    (*sortYourToBeCoupledItems)(srtPassPT);
    void            (*swapItems)               (srtPassPT);
    
}UHSortO0SIapiT, *UHSortO0SIapiPT;

extern UHSortO0SIapiT UHSortO0SIapi;


#endif /* UHSortO0_h */
