//
//  UHUnionHeapO0.h
//
//  Created by Robert R on 11/02/19.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//

#ifndef UnionHeapO0_h
#define UnionHeapO0_h
// os
#include <stdio.h>
// data plans
// api's

typedef struct UnionHeapO0HelperClassApiStruct
{
    void (*fillInCompareAsNeeded)(uhxPassPT);
}UHUnionHeapO0QHCapiT, *UHUnionHeapO0QHCapiPT;

extern UHUnionHeapO0HCapiT UHUnionHeapO0HCapi;

#endif /* UHUnionHeapO0_h */
