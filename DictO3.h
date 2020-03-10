//
//  DictO3.h
//  2020Mar10Dev
//
//  Created by Robert Russell Millward on 2/20/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
#ifndef DictO3_h
#define DictO3_h
// os
// helper and service api's
// data plans
#include "DictZ3Plan.h"

/**
 * Api to the global universal-column-id (uci) and thesarus-to-values (tav) library.
 */
typedef struct DictionaryTavO3ServiceClassApiStruct
{
    /**
     * Process the column headers to assign csv (as the name defaults to) columns to the global dictionary.
     * Enqueues the global thesarus-and-values (tav) so dequeue when all data is loaded.
     */
    csvColDataPT (*newHdrsToTav)(csvColHeadersPT, gpSllgChar64PT);
    /**
     *
     */
    csvColDataPT (*newDataToTav)(csvColDataPT, gpSllgChar64PT);
    /**
     *
     */
    void (*whatIndexToTav)(sourcePT what, sourcePT index, gpSllgChar64PT);
    /**
     * Create row(s) at this target for these universal columns..
     */
    void            (*createRows)(targetPT, massOfT, UniversalColumnIdT[]);
    /**
     * Dequeue so another can use it. As always, enqueue for the shortest possible duration.
     */
    void (*dequeTav)(void);
    
}DictTavO3SCapiT, *DictTavO3SCapiPT;

extern DictTavO3SCapiT DictTavO3SCapi;


#endif /* DictO3_h */
/**
 *
 */
