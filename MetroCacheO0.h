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

// the following will be moved to the data plan file
// if exposed at completion else the C-file.
/**
 * The several types of data in the metro cache
 * Used interchangebly:
 * - country, nation. and region
 * - state and province
 * - town and city
 * programming note: the codes were chozen to be contiguous
 */
typedef enum MetroCacheKnowTypesZ0ServiceClassEnum
{
    METCACHE_CNTTYP_CNTRY = '[',
    METCACHE_CNTTYP_STATE = '\\',
    METCACHE_CNTTYP_CNTY = ']',
    METCACHE_CNTTYP_TOWN = 'v', // really A-Z
    METCACHE_CNTTYP_LINK = '>'  // currently unused
    
}MetroCacheKnowTypesZ0SCEnumT;


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
     * Store the text into the cache and return the address.
     * Return 0 if the pool is full.
     * The putting of the text may happen during importing the data.
     * The text is a unique town, county, state, or country name,
     */
    //char*   (*putText)(char* text);
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
