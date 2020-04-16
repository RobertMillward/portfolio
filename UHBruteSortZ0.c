//
//  UHBruteSortZ0.c
//  2020Apr21Dev
//
//  Created by Robert Russell Millward on 4/15/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
// os
//#include <stdlib.h>
//#include <string.h>
// data plans
//#include "UHUnionHeapZ0Plan.h"
// api's
//#include "UHUnionHeapO0.h"
#include "UHSortO0.h"


void
UHBruteMintegerZ0_sort_fx99(srtPassPT srtPassP)
{
    uhxPassPT uhxPassP = srtPassP->uhxPassP;
    
    for(int leftIx = 0; leftIx < uhxPassP->heapCount - 1; leftIx++)
    {
        //brtPassP->xpassCount++;
        for(int rightIx = leftIx + 1; rightIx < uhxPassP->heapCount - 0; rightIx++)
        {
            uhxPassP->compareCount++;
            
            if(uhxPassP->uhxHeapP[rightIx].minteger < uhxPassP->uhxHeapP[leftIx].minteger)
            {
                uhxElT hold = uhxPassP->uhxHeapP[leftIx];
                uhxPassP->uhxHeapP[leftIx] = uhxPassP->uhxHeapP[rightIx];
                uhxPassP->uhxHeapP[rightIx] = hold;
                
                uhxPassP->siblingSwapCount++;
            }
        }
    }
}
//END UHBruteSortZ0.
/**
 * Find and install the progressively low item
 */
