//
//  UHMemSeqO0.h
//  gitrealportfolio
//
//  Created by Robert R on 1/24/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//

#ifndef UHMemSeqO0_h
#define UHMemSeqO0_h
// os
// data plan
#include "UHMemSeqZ0Plan.h"
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

}UHMemSeqO0HIapiT, *UHMemSeqO0HIapiPT;

extern UHMemSeqO0HIapiT UHMemSeqO0HIapi;


#endif /* UHMemSeqO0_h */
/**
 */
