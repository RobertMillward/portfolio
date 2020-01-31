//
//  StateT0.h - Specifics of T0 state api
//
//  Created by Robert R on 01/08/20.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef StateT0_h
#define StateT0_h
// os
// data plan
#include "StateY0Plan.h"

typedef struct StateT0HelperClassApiStruct
{
    void (*codeOf)  (DataAidLocY0HClocPT, gpSllgChar64PT);
    void (*zipOf)   (DataAidLocY0HClocPT, gpSllgChar64PT);
    void (*popOf)   (DataAidLocY0HClocPT, gpSllgChar64PT);
    
}StateT0HCapiT, *StateT0HCapiPT;

extern StateT0HCapiT StateT0HCapi;


#endif /* defined(StateT0_h) */
/**

 */
