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
    /**
     * Canned Tests
     */
    ErrorWarnCountT     (*sizeCheck)(lineNbrT);
    /**
     * Functions
     */
    long                (*ourSort)     (uhxPassPT, lineNbrT);
    int                 (*clangSort)   (uhxPassPT, lineNbrT);
    void                (*bruteSort)   (uhxPassPT, lineNbrT);
    
    uhxIxNoMoreT        (*sortCouplets)(uhxPassPT, lineNbrT);
    uhxIxNoMoreT        (*seqChk)      (uhxPassPT, lineNbrT);
    /**
     * New
     */
    uhxPassT (*newUhxPassT)(uhxElPT, massOfT, uhxSubTypeT, unionHeapFillOrderQ0T, lineNbrT);
    /**
     * Test tools
     */
    void                (*fillRandom)       (uhxElPT, massOfT, uhxSubTypeT, lineNbrT);
    void                (*fillAscending)    (uhxElPT, massOfT, uhxSubTypeT, lineNbrT);
    void                (*fillDescending)   (uhxElPT, massOfT, uhxSubTypeT, lineNbrT);

    /**
     * Expirments
     */
    void (*slosh)(uhxPassPT, int lineNbr);
    void (*btree)(uhxPassPT, int lineNbr);
    
}UHUnionHeapO0QIapiT, * UHUnionHeapO0QIapiPT;

extern UHUnionHeapO0QIapiT UHUnionHeapO0QIapi;

#endif /* UHUnionHeapZ0TestAid_h */
/**
 */
