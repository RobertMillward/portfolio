//
//  CityT0.h - Specifics of T0 city api
//
//  Created by Robert R on 01/08/20.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef CityT0_h
#define CityT0_h
// os
// data plan
#include "DataAidY0Plan.h"

typedef struct CityT0HelperClassApiStruct
{
    void (*name)(DataAidLocY0HClocPT, gpSllgChar64PT);
}CityT0HCapiT, *CityT0HCapiPT;

extern CityT0HCapiT CityT0HCapi;


#endif /* defined(CityT0_h) */
/**

 */
