//
//  DictO3.h
//  2020Apr02Dev
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
     * gp64P->threadIx must be set.
     */
    csvColDataPT (*newHdrsToTav)(csvColHeadersPT, gpSllgChar64PT);
    /**
     *
     * gp64P->threadIx must be set.
     */
    csvColDataPT (*newDataToTav)(csvColDataPT, gpSllgChar64PT);
    /**
     *
     * gp64P...threadIx must be set.
     */
    void (*putWXYZtoTav)(whatT, indeXT, whYT, whoZT, gpSllgChar64PT);
    /**
     * Get the pointer to data for a UCI for your thread.
     * gp64P...threadIx must be set.
     */
    ValPtrASizeZ3dataT (*getFieldViaUci)(UniversalColumnIdT, gpSllgChar64PT);
    /**
     * Create row(s) at this target for these universal columns..
     * gp64P->threadIx must be set. 
     */
    void            (*createRows)(targetPT, massOfT, UniversalColumnIdT[]);
    /**
     * Dequeue so another can use it. As always, enqueue for the shortest possible duration.
     */
    void (*dequeTav)(void);
    
}DictTavO3SCapiT, *DictTavO3SCapiPT;
extern DictTavO3SCapiT DictTavO3SCapi;


/**
 * Services over and above stock store-and-forward.
 */
typedef struct DictTavExtras03ServiceClassApiStruct
{
    /**
     * latitude and longitude arguments in decimal strings as "-47.228" or "57.914".
     */
    void    (*ofLatLong)(longLatPT, char* latitude, char* longitude);
    /**
     * the distance between two points given in
     */
    double  (*distance) (longLatPT place, longLatPT dest);
    
}DictTavExtrasO3SCapiT;
extern DictTavExtrasO3SCapiT DictTavExtrasO3SCapi;


#endif /* DictO3_h */
/**
 *
 */
