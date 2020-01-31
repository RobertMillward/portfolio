//
//  DGStateT0.h - Specifics of T0 state api
//
//  Created by Robert R on 01/08/20.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef DGStateT0_h
#define DGStateT0_h
// os
// data plan
#include "DGStateY0Plan.h"

typedef struct StateT0HelperClassApiStruct
{
    void (*codeOf)  (DataAidLocY0HClocPT, gpSllgChar64PT);
    void (*zipOf)   (DataAidLocY0HClocPT, gpSllgChar64PT);
    void (*popOf)   (DataAidLocY0HClocPT, gpSllgChar64PT);
    
}StateT0HCapiT, *StateT0HCapiPT;

extern StateT0HCapiT StateT0HCapi;


#endif /* DGStateT0_h */
/**

 */
