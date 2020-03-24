//
//  MetroCacheO0.h
//  2020Apr02Dev
//
//  Created by Robert Russell Millward on 3/17/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
#ifndef MetroCacheO0_h
#define MetroCacheO0_h
// os
// helper and service api's
#include "ArchitectureZ0Plan.h"
// data plans
// other api's




/**
 * The metropolotian data cache class api.
 * Data can be loaded from any source so loading services are not included.
 */
typedef struct MetroCacheO0ServiceClassApiStruct
{
    /**
     * Process the row most recently put into the thesarus.
     */
    void (*doThisRow)(gpSllgChar64PT);
    /**
     * Get the pointer to the longLat for a toen
     */
    char*   (*getLongLat)(char* town, char* stateOrCountry, gpSllgChar64PT);
    /**
     * Store the element which points to the text in the cache.
     * The putting of the element may happen after the import and
     * after resequencing.
     */
    //void    (*putElement)(uhxElT);
    /**
     * Sort elements according to text.
     */
    void    (*sort)(void);
    /**
     * Save the contents to disk for rapid retrieval.
     * Not implemented.
     */
    void  (*save)(void);
}MetroCacheO0SCapiT;
extern MetroCacheO0SCapiT MetroCacheO0SCapi;

#endif /* MetroCacheO0_h */
/**
 * The metropolitan data cache is a global read-only cache available to all threads.
 */
