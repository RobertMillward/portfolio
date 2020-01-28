//
//  UHBtreeO0.h
//  gitrealportfolio
//
//  Created by Robert R on 1/24/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//

#ifndef UHBtreeO0_h
#define UHBtreeO0_h
// os
// data plan
#include "UHBtreeZ0Plan.h"
// api

typedef const struct UHBtreeO0HelperInstanceApiStruct
{
    // These functions are in this file
    
    /**
     * Get a pristine btree element.
     * See if an element is pristine.
     */
    btxElT              (*newPristine)  (btxPassPT);
    btxElPT             (*isPristine)   (btxPassPT, btxElPT);
    /**
     * Get the btree index for the left or right side of the node.
     */
    btxControlSetT      (*getLeftNode)  (btxControlSetT);
    btxControlSetT      (*getRightNode) (btxControlSetT);
    /**
     * Verify that this btree index and step size are valid.
     */
    btxIndexValidT       (*isValidIx)    (btxPassPT, btreeIxT, btreeStepSizeT, btxStepMinValT);
    /**
     * Evaluate the left right balance of a node based on depth.
     * Return combination of the two nodes including the current node count and depth.
     * If one of the parameters is bad then the toDo will contain the return from isValidIx().
     */
    btxNodeCtT          (*evalNodes)    (btxNodeCtT left, btxNodeCtT right);
    
    
    // These functions are in BtreeFragZ0.h from here down
    
    /**
     * Set all the btree elements to pristine.
     */
    void                (*clearBtx)     (btxPassPT);
    /**
     * Count the btree elements at this node.
     */
    btxNodeCtT          (*count)        (btxPassPT, btreeIxT, btreeStepSizeOrZeroT);
    btxNodeCtT          (*countCS)      (btxPassPT, btxControlSetT);
    
    /**
     * Insert one heap item btree node into the btree.
     */
    void                (*insert)       (btxPassPT);
    /**
     * Set up the current (fractional) heap range for the upcoming import.
     * Must be called at least once starting with next = 0.
     */
    void                (*currNext)     (btxPassPT);
    /**
     * Import the existing heap into the btree.
     */
    void                (*importHeap)   (btxPassPT);
    /**
     * Export the filled btree to the new heap.
     */
    void                (*exportToHeap) (btxPassPT);
    /**
     * Initialize only the insert sttats portion of the pass structure
     */
    void                (*initInsertStats)(btxPassPT);
    /**
     * Initialize the pass structure.
     */
    void                (*initStructure)(btxPassPT passP);
}UHBtreeO0HIapiT, *UHBtreeO0HIapiPT;

extern UHBtreeO0HIapiT UHBtreeO0HIapi;


#endif /* UHBtreeO0_h */
/**
 */
