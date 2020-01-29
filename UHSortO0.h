//
//  UHSortO0.h
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

typedef struct UHSortO0HelperInstanceDataStruct
{
    long    passCount;
    
    uhxPassPT uhxPassP;
}srtPassT, *srtPassPT;

typedef struct UHSortO0HelperInstanceApiStruct
{
    /**
     * Functions
     */
    long            (*ourSort)(srtPassPT);
    /**
     * These simple sort examples being here avoid two more code sets.
     */
    int             (*clangSort)(srtPassPT);
    void            (*bruteSort)(srtPassPT);
    /**
     * Tools
     * - caller should increment srtPassP->passCount for these two
     */
    uhxIxNoMoreT    (*sortYourToBeCoupledItems)(srtPassPT);
    void            (*swapItems)               (srtPassPT);
    
}UHSortO0HIapiT, *UHSortO0HIapiPT;

extern UHSortO0HIapiT UHSortO0HIapi;


#endif /* UHSortO0_h */
