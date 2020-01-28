//
//  UHUnionHeapZ0TestAid.h - interface file for all level 0 quality assurance code silo parts common to all versions
//
//  Created by Robert R on 11/2/19.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
#ifndef UHUnionHeapZ0TestAid_h
#define UHUnionHeapZ0TestAid_h
// os
#include <stdio.h>
// data plans
#import "UHUnionHeapZ0Plan.h"
// api's
#import "UHUnionHeapO0.h"
//#import "UHSortO0.h"
//#import "UHBtreeO0.h"
// quality

typedef enum UHUnionHeapFillOrderQ0enum
{
    FILL_RANDOM,
    FILL_ASCENDING,
    FILL_DESCENDING
}unionHeapFillOrderQ0T;

/**
 * The UHUnionHeap applcation silo quality assurance class api
 */
typedef struct UHUnionHeapO0QualityInstanceApiStruct
{
    long (*ourSort)(uhxPassPT, int lineNbr);
    int  (*clangSort)(uhxPassPT, int lineNbr);
    void (*bruteSort)(uhxPassPT, int lineNbr);
    /**
     * New
     */
    uhxPassT (*newUhxPassT)(uhxElPT, size_t massOf, uhxSubTypeT, unionHeapFillOrderQ0T, int lineNbr);
    /**
     * Tools
     */
    void (*fillRandom)(uhxElPT, size_t, uhxSubTypeT, int lineNbr);
    void (*fillAscending)(uhxElPT, size_t, uhxSubTypeT, int lineNbr);
    void (*fillDescending)(uhxElPT, size_t, uhxSubTypeT, int lineNbr);
    
    uhxIxNoMoreT (*sortCouplets)(uhxPassPT, int lineNbr);
    uhxIxNoMoreT (*seqChk)(uhxPassPT, int lineNbr);
    
    void (*slosh)(uhxPassPT, int lineNbr);
    void (*btree)(uhxPassPT, int lineNbr);
    
}UHUnionHeapO0QIapiT, * UHUnionHeapO0QIapiPT;

extern UHUnionHeapO0QIapiT UHUnionHeapO0QIapi;

#endif /* UHUnionHeapZ0TestAid_h */
/**
 */
