//
//  DGPersonT0.h - Specifics of T0 person api
//
//  Created by Robert R on 01/08/20.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef DGPersonT0_h
#define DGPersonT0_h
#include "DGPersonY0Plan.h"

typedef struct PersonT0HelperClassApiT
{
    void (*famName) (DataAidLocY0HClocPT, gpSllgChar64PT);
    void (*givenName)(DataAidLocY0HClocPT, gpSllgChar64PT);
    void (*age)     (DataAidLocY0HClocPT, gpSllgChar64PT);
    void (*nextPerson)(DataAidLocY0HClocPT);
}PersonT0HCapiT, *PersonT0HCapiPT;

extern PersonT0HCapiT PersonT0HCapi;

#endif /* DGPersonT0_h */
/**

 */
