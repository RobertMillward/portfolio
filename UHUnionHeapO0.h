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
// api's

typedef struct UnionHeapO0HelperInstanceApiStruct
{
    uhxPassT    (*newUhxPassT)(uhxElPT, uhxHeapCountT, uhxSubTypeT, uhxComparePT);
    void        (*fillInCompareAsNeeded)(uhxPassPT);
    uhxIxNoMoreT (*seqCheckYourItems)(uhxPassPT);
    void        (*mergeSubs)(uhxElPT sourcePairs, uhxElPT targetPairs,
                             long inCount, long subsectionSize,
                             uhxComparePT uhxCompare,
                             uhxPassPT mergeInfoP);
    
}UHUnionHeapO0HIapiT, *UHUnionHeapO0HIapiPT;

extern UHUnionHeapO0HIapiT UHUnionHeapO0HIapi;




#endif /* UHUnionHeapO0_h */
