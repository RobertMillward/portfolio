//
//  AppZ0TestAid.h
//
//  Created by Robert R on 3/5/15.
//  Copyright (c) 2020 Robert Russell Millward.  All rights reserved.
//
#ifndef AppZ0TestAid_h
#define AppZ0TestAid_h
// os
// helper api's
// data plans
#include "ArchitectureZ0Plan.h"
// application api's


typedef struct AppZ0QualityClassApiStruct
{
    ErrorWarnCountT (*newQ)(lineNbrT);
    /**
     *
     */
    ErrorWarnCountT (*fakeTestQ)(lineNbrT);
    
    
}AppZ0QCapiT, *AppZ0QCapiPT;

extern AppZ0QCapiT AppZ0QCapi;

#endif /* AppZ0TestAid_h */
/**
 *
 */
