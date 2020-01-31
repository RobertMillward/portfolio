//
//  StreetT0.h - Specifics of T0 street api
//
//  Created by Robert R on 01/08/20.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef StreetT0_h
#define StreetT0_h
// os
// data plan
#include "DataAidY0Plan.h"
#include "StreetY0Plan.h"
// api's


typedef struct StreetT0HelperClassApiStruct
{
    void (*getNumber)(DataAidLocY0HClocPT, gpSllgChar64PT);
    void (*getName)(DataAidLocY0HClocPT, gpSllgChar64PT);
    void (*getFloor)(DataAidLocY0HClocPT, gpSllgChar64PT);
}StreetT0HCapiT, *StreetT0HCapiPT;

extern StreetT0HCapiT StreetT0HCapi;

#endif /* defined(StreetT0_h) */
/**

 */
