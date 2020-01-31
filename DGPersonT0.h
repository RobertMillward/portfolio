//
//  PersonT0.h - Specifics of T0 person api
//
//  Created by Robert R on 01/08/20.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef PersonT0_h
#define PersonT0_h
#include "PersonY0Plan.h"

typedef struct PersonT0HelperClassApiT
{
    void (*famName) (DataAidLocY0HClocPT, gpSllgChar64PT);
    void (*givenName)(DataAidLocY0HClocPT, gpSllgChar64PT);
    void (*age)     (DataAidLocY0HClocPT, gpSllgChar64PT);
    void (*nextPerson)(DataAidLocY0HClocPT);
}PersonT0HCapiT, *PersonT0HCapiPT;

extern PersonT0HCapiT PersonT0HCapi;

#endif /* defined(PersonT0_h) */
/**

 */
