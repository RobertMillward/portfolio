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
    long (*ourSort)(uhxPassPT);
    /**
     * These simple sort examples are here to avoid two more code sets.
     */
    int (*clangSort)(uhxPassPT);
    void (*bruteSort)(uhxPassPT);
    /**
     * Tools
     */
    uhxIxNoMoreT (*sortYourToBeCoupledItems)(uhxPassPT);
    void (*swapItems)(uhxPassPT);
}UHSortO0HIapiT, *UHSortO0HIapiPT;

extern UHSortO0HIapiT UHSortO0HIapi;

//UHUnionHeapZ0Q_ourSort_fx99,
//UHUnionHeapZ0Q_clang_fx99,
//UHUnionHeapZ0Q_brute_fx99,
//
//UHUnionHeapZ0Q_newMasterSortInfo_fx99,
//
//UHUnionHeapZ0Q_fillRandom_fx99,
//UHUnionHeapZ0Q_fillAscending_fx99,
//UHUnionHeapZ0Q_fillDescending_fx99,
//UHUnionHeapZ0Q_seqChk_fx99,
//UHUnionHeapZ0Q_sortCouplets_fx99,
//
//UHUnionHeapZ0Q_slosh_fx99,
//UHUnionHeapZ0Q_btree_fx99

#endif /* UHSortO0_h */
