//
//  UHSortO0.h - Precious
//  2020May10Dev
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




typedef struct UHSortO0ServiceClassApiStruct
{
    /**
     * Functions
     */
    Slng (*ourSort)(srtPassPT);
    /**
     * These simple sort examples being here avoid two more code sets.
     */
    Sint (*clangSort)(srtPassPT);
    /**
     * Log Sort
     */
    Slng (*logSort)(srtPassPT);
    //void            (*bruteSortIntegers)(srtPassPT);
    /**
     * Tools
     * - caller should increment srtPassP->passCount for these two
     */
    uhxIxNoMoreT    (*sortYourToBeCoupledItems)(srtPassPT);
    void            (*swapItems)               (srtPassPT);
    
}UHSortO0SCapiT, *UHSortO0SCapiPT;

extern UHSortO0SCapiT UHSortO0SCapi;


#endif /* UHSortO0_h */
/**
 *
 */
