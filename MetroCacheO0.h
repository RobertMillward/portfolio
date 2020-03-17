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
/**
 * The several types of data in the metro cache
 */
typedef enum MetroCacheContentTypesZ0ServiceClassEnum
{
    METCACHE_CNTTYP_CNTRY = '^',
    METCACHE_CNTTYP_STATE = '=',
    METCACHE_CNTTYP_CNTY = '~',
    METCACHE_CNTTYP_TOWN = 'v',
    METCACHE_CNTTYP_LINK = '>'
    
}MetroCacheCntTypZ0SCEnumT;


/**
 * The metropolotian data cache class api.
 */
typedef struct MetroCacheO0ServiceClassApiStruct
{
    char* (*putText)(char* text);
    void  (*putElement)(uhxElT);
}MetroCacheO0SCapiT;
extern MetroCacheO0SCapiT MetroCacheO0SCapi;

#endif /* MetroCacheO0_h */
/**
 * The metropolitan data cache is a global cache available to all threads for reading.
 */
