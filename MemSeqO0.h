//
//  MemSeqO0.h
//  portfolio
//
//  Created by Robert R on 1/24/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//

#ifndef MemSeqO0_h
#define MemSeqO0_h
// os
// data plan
#include "MemSeqZ0Plan.h"
// other api


typedef const struct MemSeqZ0HelperInstanceApiStruct
{
    /**
     * Recursivly retrieve and clear the leftmost item at the given node.
     * - in core will be a ordered list of all the items in this node.
     * Store those ordered items into the btree.
     */
    void                (*retrieveSequential)(msxPassPT, btxControlSetT);
    void                (*insertBalanced)    (msxPassPT, btxControlSetT);
    
    /**
     * Rebalance the btree, usually triggered by rebalanceNodeReqd.
     */
    msxPassT            (*rebalance0)   (btxPassPT);
    msxPassT            (*rebalance10)  (btxPassPT);

}MemSeqO0HIapiT, *MemSeqO0HIapiPT;

extern MemSeqO0HIapiT MemSeqO0HIapi;


#endif /* MemSeqO0_h */
/**
 */
