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

typedef struct UHSortO0HelperInstanceApiStruct
{
    /**
     * Functions
     */
    long            (*ourSort)(uhxPassPT);
    /**
     * These simple sort examples being here avoid two more code sets.
     */
    int             (*clangSort)(uhxPassPT);
    void            (*bruteSort)(uhxPassPT);
    /**
     * Tools
     */
    uhxIxNoMoreT    (*sortYourToBeCoupledItems)(uhxPassPT);
    void            (*swapItems)                (uhxPassPT);
}UHSortO0HIapiT, *UHSortO0HIapiPT;

extern UHSortO0HIapiT UHSortO0HIapi;


#endif /* UHSortO0_h */
